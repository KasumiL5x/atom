#ifndef __atom_dag_Texture__
#define __atom_dag_Texture__

#include "Node.hpp"
#include <fstream>

namespace atom { namespace dag {

class Texture : public Node {
public:
	Texture( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path );
	virtual ~Texture();

	std::string getTextureName() const;
	std::string getTextureExt() const;
	unsigned char* const getTextureData();
	std::streampos getTextureDataLength() const;
	float getTranslateFrameU() const;
	float getTranslateFrameV() const;
	float getRotateFrame() const;
	bool getMirrorU() const;
	bool getMirrorV() const;
	bool getWrapU() const;
	bool getWrapV() const;
	float getRepeatU() const;
	float getRepeatV() const;
	float getOffsetU() const;
	float getOffsetV() const;
	float getRotateUV() const;
	float getNoiseU() const;
	float getNoiseV() const;

protected:
	virtual std::string getNameInternal() const override;
	virtual void OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) override;
	virtual void OnPlugDirtied( MObject& node, MPlug& plug ) override;

private:
	bool dataDirty_;
	std::unique_ptr<unsigned char[]> data_;
	std::streampos dataLength_;
};

}
}

#endif