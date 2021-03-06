// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape_HeaderFile
#define _BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape_HeaderFile
#include <Handle_BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape.hxx>
#endif

#ifndef _Handle_MAT_BasicElt_HeaderFile
#include <Handle_MAT_BasicElt.hxx>
#endif
#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class MAT_BasicElt;
class TopoDS_Shape;
class TColStd_MapTransientHasher;
class BRepMAT2d_DataMapOfBasicEltShape;
class BRepMAT2d_DataMapIteratorOfDataMapOfBasicEltShape;



class BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape : public TCollection_MapNode {

public:

  
      BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape(const Handle(MAT_BasicElt)& K,const TopoDS_Shape& I,const TCollection_MapNodePtr& n);
  
        Handle_MAT_BasicElt& Key() const;
  
        TopoDS_Shape& Value() const;




  DEFINE_STANDARD_RTTI(BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape)

protected:




private: 


Handle_MAT_BasicElt myKey;
TopoDS_Shape myValue;


};

#define TheKey Handle_MAT_BasicElt
#define TheKey_hxx <MAT_BasicElt.hxx>
#define TheItem TopoDS_Shape
#define TheItem_hxx <TopoDS_Shape.hxx>
#define Hasher TColStd_MapTransientHasher
#define Hasher_hxx <TColStd_MapTransientHasher.hxx>
#define TCollection_DataMapNode BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape
#define TCollection_DataMapNode_hxx <BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape.hxx>
#define TCollection_DataMapIterator BRepMAT2d_DataMapIteratorOfDataMapOfBasicEltShape
#define TCollection_DataMapIterator_hxx <BRepMAT2d_DataMapIteratorOfDataMapOfBasicEltShape.hxx>
#define Handle_TCollection_DataMapNode Handle_BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape
#define TCollection_DataMapNode_Type_() BRepMAT2d_DataMapNodeOfDataMapOfBasicEltShape_Type_()
#define TCollection_DataMap BRepMAT2d_DataMapOfBasicEltShape
#define TCollection_DataMap_hxx <BRepMAT2d_DataMapOfBasicEltShape.hxx>

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
