// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Prs3d_HeaderFile
#define _Prs3d_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Quantity_Length_HeaderFile
#include <Quantity_Length.hxx>
#endif
class gp_Pnt;
class Prs3d_Presentation;
class Prs3d_BasicAspect;
class Prs3d_PointAspect;
class Prs3d_LineAspect;
class Prs3d_ShadingAspect;
class Prs3d_TextAspect;
class Prs3d_CompositeAspect;
class Prs3d_IsoAspect;
class Prs3d_PlaneAspect;
class Prs3d_ArrowAspect;
class Prs3d_LengthAspect;
class Prs3d_AngleAspect;
class Prs3d_RadiusAspect;
class Prs3d_DatumAspect;
class Prs3d_Drawer;
class Prs3d_Projector;
class Prs3d_PlaneSet;
class Prs3d_Root;
class Prs3d_Point;
class Prs3d_Line;
class Prs3d_WFDeflectionRestrictedFace;
class Prs3d_WFRestrictedFace;
class Prs3d_WFShape;
class Prs3d_HLRShape;
class Prs3d_SectionShapeTool;
class Prs3d_Vector;
class Prs3d_Datum;
class Prs3d_LengthPresentation;
class Prs3d_AnglePresentation;
class Prs3d_Text;
class Prs3d_PointTool;
class Prs3d_LineTool;
class Prs3d_CurvePresentation;
class Prs3d_RestrictionTool;
class Prs3d_ShapeTool;
class Prs3d_HLRShapeTool;
class Prs3d_VectorTool;
class Prs3d_DatumTool;
class Prs3d_Arrow;


//! The Prs3d package provides the following services <br>
//! -   a presentation object (the context for all <br>
//!   modifications to the display, its presentation will be <br>
//!   displayed in every view of an active viewer) <br>
//! -   an attribute manager governing how objects such <br>
//!   as color, width, and type of line are displayed; <br>
//!   these are generic objects, whereas those in <br>
//!   StdPrs are specific geometries and topologies. <br>
//! -   generic   algorithms providing default settings for <br>
//!   objects such as points, curves, surfaces and shapes <br>
//! -   a root object which provides the abstract <br>
//!   framework for the DsgPrs definitions at work in <br>
//!   display of dimensions, relations and trihedra. <br>
class Prs3d  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   static  Standard_Boolean MatchSegment(const Quantity_Length X,const Quantity_Length Y,const Quantity_Length Z,const Quantity_Length aDistance,const gp_Pnt& p1,const gp_Pnt& p2,Quantity_Length& dist) ;





protected:





private:




friend class Prs3d_Presentation;
friend class Prs3d_BasicAspect;
friend class Prs3d_PointAspect;
friend class Prs3d_LineAspect;
friend class Prs3d_ShadingAspect;
friend class Prs3d_TextAspect;
friend class Prs3d_CompositeAspect;
friend class Prs3d_IsoAspect;
friend class Prs3d_PlaneAspect;
friend class Prs3d_ArrowAspect;
friend class Prs3d_LengthAspect;
friend class Prs3d_AngleAspect;
friend class Prs3d_RadiusAspect;
friend class Prs3d_DatumAspect;
friend class Prs3d_Drawer;
friend class Prs3d_Projector;
friend class Prs3d_PlaneSet;
friend class Prs3d_Root;
friend class Prs3d_Point;
friend class Prs3d_Line;
friend class Prs3d_WFDeflectionRestrictedFace;
friend class Prs3d_WFRestrictedFace;
friend class Prs3d_WFShape;
friend class Prs3d_HLRShape;
friend class Prs3d_SectionShapeTool;
friend class Prs3d_Vector;
friend class Prs3d_Datum;
friend class Prs3d_LengthPresentation;
friend class Prs3d_AnglePresentation;
friend class Prs3d_Text;
friend class Prs3d_PointTool;
friend class Prs3d_LineTool;
friend class Prs3d_CurvePresentation;
friend class Prs3d_RestrictionTool;
friend class Prs3d_ShapeTool;
friend class Prs3d_HLRShapeTool;
friend class Prs3d_VectorTool;
friend class Prs3d_DatumTool;
friend class Prs3d_Arrow;

};





// other Inline functions and methods (like "C++: function call" methods)


#endif
