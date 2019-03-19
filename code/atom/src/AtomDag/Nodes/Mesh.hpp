#ifndef __atom_dag_Mesh__
#define __atom_dag_Mesh__

#include <set>
#include <mutex>
#include <vector>
#include "Node.hpp"
#include <maya/MStringArray.h>
#include <maya/MFloatVectorArray.h>
#include <maya/MFloatArray.h>
#include <maya/MPoint.h>
#include <maya/MColorArray.h>
#include <maya/MIntArray.h>
#include <maya/MMatrix.h>
#include "../../ManualResetEvent.hpp"

namespace atom { namespace dag {

class Mesh : public Node {
public:
	Mesh( const std::shared_ptr<AtomDag>& adag, MObject& object, MDagPath& path );
	virtual ~Mesh();

	void notifyExternalChange( DagCallback type, std::shared_ptr<Node> instigator );
	std::string getMaterialName() const;
	void lockMeshData();
	void unlockMeshData();
	const MStringArray& getUVSetNames() const;
	const std::vector<int>& getVertexIndices() const; // physical indices from loop order
	const std::vector<int>& getVertexMayaIndices() const; // vertex IDs according to Maya
	const std::vector<MPoint>& getVertexPositions() const;
	const std::vector<MFloatVector>& getVertexNormals() const;
	const std::vector<std::vector<std::pair<float, float>>>& getVertexTexcoords() const;
	const std::vector<std::vector<int>>& getVertexTexcoordIndices() const;
	const std::vector<MFloatVectorArray>& getVertexTangents() const;
	const std::vector<MFloatVectorArray>& getVertexBinormals() const;
	const MStringArray& getColorSetNames() const;
	const std::vector<MColorArray>& getVertexColors() const;
	const MIntArray& getIndices() const;
	std::set<int> getVertexIndicesChanged();

private:
	void rebuildMeshData();

protected:
	virtual std::string getNameInternal() const override;
	virtual void OnAttributeChanged( MNodeMessage::AttributeMessage msg, MPlug& plug, MPlug& otherPlug ) override;
	virtual void OnPlugDirtied( MObject& node, MPlug& plug ) override;
	virtual void justBeforeNotify() override;
	virtual void justAfterNotify() override;
	virtual void onTranslate() override;
	virtual void onRotate() override;
	virtual void onScale() override;


private:
	std::set<int> vertexIndicesChanged_; /**< Accumulated modified vertices applied in justBeforeNotify(). */
	std::mutex vertexIndicesChangedMutex_;
	ManualResetEvent meshDirtyEvent_; /**< Reset event for rebuilding cached mesh data. */
	bool isMeshDirty_;
	MStringArray uvSetNames_;
	std::vector<int> vertexIndex_;
	std::vector<int> vertexMayaIndex_;
	std::vector<MPoint> vertexPosition_;
	std::vector<MFloatVector> vertexNormal_;
	std::vector<std::vector<std::pair<float, float>>> vertexTexcoord_;
	std::vector<std::vector<int>> vertexTexcoordIndices_;
	std::vector<MFloatVectorArray> vertexTangent_;
	std::vector<MFloatVectorArray> vertexBinormal_;
	MStringArray colorSetNames_;
	std::vector<MColorArray> vertexColors_;
	MIntArray indices_;
};

}
}

#endif