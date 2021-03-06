// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFeat_HeaderFile
#define _BRepFeat_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_Geom_Curve_HeaderFile
#include <Handle_Geom_Curve.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _TopAbs_Orientation_HeaderFile
#include <TopAbs_Orientation.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
#ifndef _BRepFeat_StatusError_HeaderFile
#include <BRepFeat_StatusError.hxx>
#endif
class TopoDS_Shape;
class TColgp_SequenceOfPnt;
class gp_Pnt;
class Geom_Curve;
class TopoDS_Face;
class BRepTopAdaptor_FClass2d;
class Geom2dAdaptor_Curve;
class TopoDS_Solid;
class BRepFeat_Builder;
class BRepFeat_LocalOperation;
class BRepFeat_MakeCylindricalHole;
class BRepFeat_SplitShape;
class BRepFeat_Form;
class BRepFeat_RibSlot;
class BRepFeat_MakePrism;
class BRepFeat_MakeRevol;
class BRepFeat_MakePipe;
class BRepFeat_Gluer;
class BRepFeat_MakeDPrism;
class BRepFeat_MakeLinearForm;
class BRepFeat_MakeRevolutionForm;


//! BRepFeat is necessary for the <br>
//! creation and manipulation of both form and mechanical features in a <br>
//! Boundary Representation framework. Form features can be depressions or <br>
//! protrusions and include the following types: <br>
//! -          Cylinder <br>
//! -          Draft Prism <br>
//! -          Prism <br>
//! -          Revolved feature <br>
//! -          Pipe <br>
//! Depending on whether you wish to make a depression or a protrusion, <br>
//! you can choose your operation type between the following: <br>
//! - removing matter (a Boolean cut: Fuse setting 0) <br>
//! - adding matter (Boolean fusion: Fuse setting 1) <br>
//!   The semantics of form feature creation is based on the <br>
//! construction of shapes: <br>
//! -          for a certain length in a certain direction <br>
//! -          up to a limiting face <br>
//! -          from a limiting face at a height <br>
//! -          above and/or below a plane <br>
//! The shape defining the construction of a feature can be either a <br>
//! supporting edge or a concerned area of a face. <br>
//! In case of supporting edge, this contour can be attached to a face <br>
//! of the basis shape by binding. When the contour is bound to this face, <br>
//! the information that the contour will slide on the face becomes <br>
//! available to the relevant class methods. In case of the concerned <br>
//! area of a face, you could, for example, cut it out and move it at <br>
//! a different height, which will define the limiting face of a <br>
//! protrusion or depression. Topological definition with local <br>
//! operations of this sort makes calculations simpler and faster <br>
//! than a global operation. The latter would entail a second phase of <br>
//! removing unwanted matter to get the same result. <br>
//! Mechanical features include ribs - protrusions - and grooves (or <br>
//! slots) - depressions along planar (linear) surfaces or revolution surfaces. <br>
//! The semantics of mechanical features is based on giving <br>
//! thickness to a contour. This thickness can either be unilateral <br>
//! - on one side of the contour - or bilateral - on both sides. As in <br>
//! the semantics of form features, the thickness is defined by <br>
//! construction of shapes in specific contexts. <br>
//! However, in case of mechanical features, development contexts <br>
//! differ. Here they include extrusion: <br>
//! -          to a limiting face of the basis shape <br>
//! -          to or from a limiting plane <br>
//! -          to a height. <br>
class BRepFeat  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   static  void SampleEdges(const TopoDS_Shape& S,TColgp_SequenceOfPnt& Pt) ;
  
  Standard_EXPORT   static  void Barycenter(const TopoDS_Shape& S,gp_Pnt& Pt) ;
  
  Standard_EXPORT   static  Standard_Real ParametricBarycenter(const TopoDS_Shape& S,const Handle(Geom_Curve)& C) ;
  //!  Ori = True taking account the orientation <br>
  Standard_EXPORT   static  void ParametricMinMax(const TopoDS_Shape& S,const Handle(Geom_Curve)& C,Standard_Real& prmin,Standard_Real& prmax,Standard_Real& prbmin,Standard_Real& prbmax,Standard_Boolean& flag,const Standard_Boolean Ori = Standard_False) ;
  
  Standard_EXPORT   static  Standard_Boolean IsInside(const TopoDS_Face& F1,const TopoDS_Face& F2) ;
  
  Standard_EXPORT   static  Standard_Boolean IsInOut(const BRepTopAdaptor_FClass2d& FC,const Geom2dAdaptor_Curve& AC) ;
  
  Standard_EXPORT   static  void FaceUntil(const TopoDS_Shape& S,TopoDS_Face& F) ;
  
  Standard_EXPORT   static  TopoDS_Solid Tool(const TopoDS_Shape& SRef,const TopoDS_Face& Fac,const TopAbs_Orientation Orf) ;
  //! Prints the Error description of the State <St> as a String on <br>
//!          the Stream <S> and returns <S>. <br>
//! <br>
  Standard_EXPORT   static  Standard_OStream& Print(const BRepFeat_StatusError SE,Standard_OStream& S) ;





protected:





private:




friend class BRepFeat_Builder;
friend class BRepFeat_LocalOperation;
friend class BRepFeat_MakeCylindricalHole;
friend class BRepFeat_SplitShape;
friend class BRepFeat_Form;
friend class BRepFeat_RibSlot;
friend class BRepFeat_MakePrism;
friend class BRepFeat_MakeRevol;
friend class BRepFeat_MakePipe;
friend class BRepFeat_Gluer;
friend class BRepFeat_MakeDPrism;
friend class BRepFeat_MakeLinearForm;
friend class BRepFeat_MakeRevolutionForm;

};





// other Inline functions and methods (like "C++: function call" methods)


#endif
