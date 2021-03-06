// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _VrmlConverter_WFShape_HeaderFile
#define _VrmlConverter_WFShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
#ifndef _Handle_VrmlConverter_Drawer_HeaderFile
#include <Handle_VrmlConverter_Drawer.hxx>
#endif
class TopoDS_Shape;
class VrmlConverter_Drawer;


//! WFShape - computes the wireframe presentation of <br>
//!          compound set  of  faces,  edges  and vertices by <br>
//!          displaying a given  number of U and/or V isoparametric <br>
//!          curves converts this one into VRML objects and writes (adds) <br>
//!          them into anOStream. <br>
//!          All requested properties of the representation are <br>
//!          specify in aDrawer. <br>
//!          This kind of the presentation is converted into <br>
//!          IndexedLineSet and PointSet  ( VRML ). <br>
class VrmlConverter_WFShape  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   static  void Add(Standard_OStream& anOStream,const TopoDS_Shape& aShape,const Handle(VrmlConverter_Drawer)& aDrawer) ;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
