// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepAlgo_DataMapNodeOfDataMapOfShapeInterference_HeaderFile
#define _BRepAlgo_DataMapNodeOfDataMapOfShapeInterference_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BRepAlgo_DataMapNodeOfDataMapOfShapeInterference_HeaderFile
#include <Handle_BRepAlgo_DataMapNodeOfDataMapOfShapeInterference.hxx>
#endif

#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _Handle_TopOpeBRepDS_Interference_HeaderFile
#include <Handle_TopOpeBRepDS_Interference.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class TopOpeBRepDS_Interference;
class TopoDS_Shape;
class TopTools_ShapeMapHasher;
class BRepAlgo_DataMapOfShapeInterference;
class BRepAlgo_DataMapIteratorOfDataMapOfShapeInterference;



class BRepAlgo_DataMapNodeOfDataMapOfShapeInterference : public TCollection_MapNode {

public:

  
      BRepAlgo_DataMapNodeOfDataMapOfShapeInterference(const TopoDS_Shape& K,const Handle(TopOpeBRepDS_Interference)& I,const TCollection_MapNodePtr& n);
  
        TopoDS_Shape& Key() const;
  
        Handle_TopOpeBRepDS_Interference& Value() const;




  DEFINE_STANDARD_RTTI(BRepAlgo_DataMapNodeOfDataMapOfShapeInterference)

protected:




private: 


TopoDS_Shape myKey;
Handle_TopOpeBRepDS_Interference myValue;


};

#define TheKey TopoDS_Shape
#define TheKey_hxx <TopoDS_Shape.hxx>
#define TheItem Handle_TopOpeBRepDS_Interference
#define TheItem_hxx <TopOpeBRepDS_Interference.hxx>
#define Hasher TopTools_ShapeMapHasher
#define Hasher_hxx <TopTools_ShapeMapHasher.hxx>
#define TCollection_DataMapNode BRepAlgo_DataMapNodeOfDataMapOfShapeInterference
#define TCollection_DataMapNode_hxx <BRepAlgo_DataMapNodeOfDataMapOfShapeInterference.hxx>
#define TCollection_DataMapIterator BRepAlgo_DataMapIteratorOfDataMapOfShapeInterference
#define TCollection_DataMapIterator_hxx <BRepAlgo_DataMapIteratorOfDataMapOfShapeInterference.hxx>
#define Handle_TCollection_DataMapNode Handle_BRepAlgo_DataMapNodeOfDataMapOfShapeInterference
#define TCollection_DataMapNode_Type_() BRepAlgo_DataMapNodeOfDataMapOfShapeInterference_Type_()
#define TCollection_DataMap BRepAlgo_DataMapOfShapeInterference
#define TCollection_DataMap_hxx <BRepAlgo_DataMapOfShapeInterference.hxx>

#include <TCollection_DataMapNode.lxx>

#undef TheKey
#undef TheKey_hxx
#undef TheItem
#undef TheItem_hxx
#undef Hasher
#undef Hasher_hxx
#undef TCollection_DataMapNode
#undef TCollection_DataMapNode_hxx
#undef TCollection_DataMapIterator
#undef TCollection_DataMapIterator_hxx
#undef Handle_TCollection_DataMapNode
#undef TCollection_DataMapNode_Type_
#undef TCollection_DataMap
#undef TCollection_DataMap_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
