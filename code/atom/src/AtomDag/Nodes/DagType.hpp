#ifndef __atom_dag_DagType__
#define __atom_dag_DagType__

#include <string>

namespace atom { namespace dag {

enum class DagType {
	Invalid,
	Xform,
	Mesh,
	Camera,
	Light,
	Texture,
	Material,
	Utility,
	Annotation,
	Curve
};

static std::string DagTypeToString( DagType type ) {
	switch( type ) {
		case DagType::Invalid: { return "INVALID"; }
		case DagType::Xform:{ return "XFORM"; }
		case DagType::Mesh:{ return "MESH"; }
		case DagType::Camera: { return "CAMERA"; }
		case DagType::Light: { return "LIGHT"; }
		case DagType::Texture: { return "TEXTURE"; }
		case DagType::Material: { return "MATERIAL"; }
		case DagType::Utility: { return "UTILITY"; }
		case DagType::Annotation: { return "ANNOTATION"; }
		case DagType::Curve: { return "CURVE"; }
	}
	return "ERROR";
}

}
}

#endif