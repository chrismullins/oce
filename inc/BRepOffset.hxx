// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepOffset_HeaderFile
#define _BRepOffset_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_Geom_Surface_HeaderFile
#include <Handle_Geom_Surface.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _BRepOffset_Status_HeaderFile
#include <BRepOffset_Status.hxx>
#endif
class Geom_Surface;
class BRepOffset_MakeOffset;
class BRepOffset_Inter3d;
class BRepOffset_Inter2d;
class BRepOffset_Offset;
class BRepOffset_Analyse;
class BRepOffset_MakeLoops;
class BRepOffset_Tool;
class BRepOffset_Interval;
class BRepOffset_ListOfInterval;
class BRepOffset_DataMapOfShapeListOfInterval;
class BRepOffset_DataMapOfShapeOffset;
class BRepOffset_DataMapOfShapeMapOfShape;
class BRepOffset_ListNodeOfListOfInterval;
class BRepOffset_ListIteratorOfListOfInterval;
class BRepOffset_DataMapNodeOfDataMapOfShapeListOfInterval;
class BRepOffset_DataMapIteratorOfDataMapOfShapeListOfInterval;
class BRepOffset_DataMapNodeOfDataMapOfShapeOffset;
class BRepOffset_DataMapIteratorOfDataMapOfShapeOffset;
class BRepOffset_DataMapNodeOfDataMapOfShapeMapOfShape;
class BRepOffset_DataMapIteratorOfDataMapOfShapeMapOfShape;



class BRepOffset  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   static  Handle_Geom_Surface Surface(const Handle(Geom_Surface)& Surface,const Standard_Real Offset,BRepOffset_Status& Status) ;





protected:





private:




friend class BRepOffset_MakeOffset;
friend class BRepOffset_Inter3d;
friend class BRepOffset_Inter2d;
friend class BRepOffset_Offset;
friend class BRepOffset_Analyse;
friend class BRepOffset_MakeLoops;
friend class BRepOffset_Tool;
friend class BRepOffset_Interval;
friend class BRepOffset_ListOfInterval;
friend class BRepOffset_DataMapOfShapeListOfInterval;
friend class BRepOffset_DataMapOfShapeOffset;
friend class BRepOffset_DataMapOfShapeMapOfShape;
friend class BRepOffset_ListNodeOfListOfInterval;
friend class BRepOffset_ListIteratorOfListOfInterval;
friend class BRepOffset_DataMapNodeOfDataMapOfShapeListOfInterval;
friend class BRepOffset_DataMapIteratorOfDataMapOfShapeListOfInterval;
friend class BRepOffset_DataMapNodeOfDataMapOfShapeOffset;
friend class BRepOffset_DataMapIteratorOfDataMapOfShapeOffset;
friend class BRepOffset_DataMapNodeOfDataMapOfShapeMapOfShape;
friend class BRepOffset_DataMapIteratorOfDataMapOfShapeMapOfShape;

};





// other Inline functions and methods (like "C++: function call" methods)


#endif
