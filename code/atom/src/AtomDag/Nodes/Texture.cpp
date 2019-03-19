#include "Texture.hpp"
#include <maya/MFnDependencyNode.h>
#include "../../MTLog.hpp"

using namespace atom::dag;

Texture::Texture( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path ) : Node(adag, object, path), dataDirty_(true) {
	type_ = DagType::Texture;
}

Texture::~Texture() {
}

std::string Texture::getTextureName() const {
	return MFnDependencyNode(mayaObject_).findPlug("fileTextureName").asString().asChar();
}

std::string Texture::getTextureExt() const {
	const std::string file = getTextureName();
	const auto lastDot = file.find_last_of('.');
	if( lastDot == std::string::npos || file.length() == (lastDot+1) ) {
		return "";
	}
	return file.substr(lastDot+1, file.length() - lastDot+1);
}

unsigned char* const Texture::getTextureData() {
	// dispose existing data if dirty
	if( dataDirty_ && data_ != nullptr ) {
		data_ = nullptr;
	}

	if( nullptr == data_ || dataDirty_ ) {
		std::ifstream in(getTextureName(), ios::binary | ios::ate);
		if( in.is_open() ) {
			dataLength_ = in.tellg();
			data_ = std::make_unique<unsigned char[]>(dataLength_);
			in.seekg(0, ios::beg);
			in.read(reinterpret_cast<char*>(data_.get()), dataLength_);
			dataDirty_= false;
		} else {
			MTLog::instance()->log("Tried to read Texture but failed: " + getTextureName() + "\n");
		}
	}

	return data_.get();
}

std::streampos Texture::getTextureDataLength() const {
	return dataLength_;
}

float Texture::getTranslateFrameU() const {
	return MFnDependencyNode(mayaObject_).findPlug("translateFrameU").asFloat();
}

float Texture::getTranslateFrameV() const {
	return MFnDependencyNode(mayaObject_).findPlug("translateFrameV").asFloat();
}

float Texture::getRotateFrame() const {
	return MFnDependencyNode(mayaObject_).findPlug("rotateFrame").asFloat() * 57.29578f; // CONVERT TO DEGREES
}

bool Texture::getMirrorU() const {
	return MFnDependencyNode(mayaObject_).findPlug("mirrorU").asBool();
}

bool Texture::getMirrorV() const {
	return MFnDependencyNode(mayaObject_).findPlug("mirrorV").asBool();
}

bool Texture::getWrapU() const {
	return MFnDependencyNode(mayaObject_).findPlug("wrapU").asBool();
}

bool Texture::getWrapV() const {
	return MFnDependencyNode(mayaObject_).findPlug("wrapV").asBool();
}

float Texture::getRepeatU() const {
	return MFnDependencyNode(mayaObject_).findPlug("repeatU").asFloat();
}

float Texture::getRepeatV() const {
	return MFnDependencyNode(mayaObject_).findPlug("repeatV").asFloat();
}

float Texture::getOffsetU() const {
	return MFnDependencyNode(mayaObject_).findPlug("offsetU").asFloat();
}

float Texture::getOffsetV() const {
	return MFnDependencyNode(mayaObject_).findPlug("offsetV").asFloat();
}

float Texture::getRotateUV() const {
	return MFnDependencyNode(mayaObject_).findPlug("rotateUV").asFloat() * 57.29578f; // CONVERT TO DEGREES
}

float Texture::getNoiseU() const {
	return MFnDependencyNode(mayaObject_).findPlug("noiseU").asFloat();
}

float Texture::getNoiseV() const {
	return MFnDependencyNode(mayaObject_).findPlug("noiseV").asFloat();
}

std::string Texture::getNameInternal() const {
	return MFnDependencyNode(mayaObject_).name().asChar();
}

void Texture::OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) {
	if( !((msg & MNodeMessage::kAttributeSet) && (msg & MNodeMessage::kIncomingDirection)) ) {
		return;
	}
}

void Texture::OnPlugDirtied( MObject& node, MPlug& plug ) {
	const char* name = plug.partialName().asChar();

	DagCallback DagCallback;
	bool changed = false;

	if( strcmp(name, "ftn")==0 ) { // fileTextureName(ftn)
		dataDirty_ = true;
		DagCallback = DagCallback::kTextureChangedFile;
		changed = true;
	} else if( strcmp(name, "tf")==0 ) { // translateFrame(tf)
		DagCallback = DagCallback::kTextureChangedTranslateFrame;
		changed = true;
	} else if( strcmp(name, "rf")==0 ) { // rotateFrame(rf)
		DagCallback = DagCallback::kTextureChangedRotateFrame;
		changed = true;
	} else if( strcmp(name, "mu")==0 ) { // mirrorU(mu)
		DagCallback = DagCallback::kTextureChangedMirrorU;
		changed = true;
	} else if( strcmp(name, "mv")==0 ) { // mirrorV(mv)
		DagCallback = DagCallback::kTextureChangedMirrorV;
		changed = true;
	} else if( strcmp(name, "wu")==0 ) { // wrapU(wu)
		DagCallback = DagCallback::kTextureChangedWrapU;
		changed = true;
	} else if( strcmp(name, "wv")==0 ) { // wrapV(wv)
		DagCallback = DagCallback::kTextureChangedWrapV;
		changed = true;
	} else if( strcmp(name, "re")==0 ) { // repeatUV(re)
		DagCallback = DagCallback::kTextureChangedRepeat;
		changed = true;
	} else if( strcmp(name, "of")==0 ) { // offset(of)
		DagCallback = DagCallback::kTextureChangedOffset;
		changed = true;
	} else if( strcmp(name, "ro")==0 ) { // rotateUV(ro)
		DagCallback = DagCallback::kTextureChangedRotateUV;
		changed = true;
	} else if( strcmp(name, "n")==0 ) { // noiseUV(n)
		DagCallback = DagCallback::kTextureChangedNoise;
		changed = true;
	}

	if( changed ) {
		addChange(DagCallback, nullptr);
	}
}