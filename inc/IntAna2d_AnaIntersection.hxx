// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntAna2d_AnaIntersection_HeaderFile
#define _IntAna2d_AnaIntersection_HeaderFile

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
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _IntAna2d_IntPoint_HeaderFile
#include <IntAna2d_IntPoint.hxx>
#endif
class StdFail_NotDone;
class Standard_OutOfRange;
class gp_Lin2d;
class gp_Circ2d;
class IntAna2d_Conic;
class gp_Elips2d;
class gp_Parab2d;
class gp_Hypr2d;
class IntAna2d_IntPoint;


//! Implementation of the analytical intersection between: <br>
//!          - two Lin2d, <br>
//!          - two Circ2d, <br>
//!          - a Lin2d and a Circ2d, <br>
//!          - an element of gp (Lin2d, Circ2d, Elips2d, Parab2d, Hypr2d) <br>
//!          and another conic. <br>
//!          No tolerance is given for all the intersections: the tolerance <br>
//!          will be the "precision machine". <br>
class IntAna2d_AnaIntersection  {
public:

  DEFINE_STANDARD_ALLOC

  //! Empty constructor. IsDone returns False. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection();
  //! Intersection between two lines. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection(const gp_Lin2d& L1,const gp_Lin2d& L2);
  //! Intersection between two circles. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection(const gp_Circ2d& C1,const gp_Circ2d& C2);
  //! Intersection between a line and a circle. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection(const gp_Lin2d& L,const gp_Circ2d& C);
  //! Intersection between a line and a conic. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection(const gp_Lin2d& L,const IntAna2d_Conic& C);
  //! Intersection between a circle and another conic. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection(const gp_Circ2d& C,const IntAna2d_Conic& Co);
  //! Intersection between an ellipse and another conic. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection(const gp_Elips2d& E,const IntAna2d_Conic& C);
  //! Intersection between a parabola and another conic. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection(const gp_Parab2d& P,const IntAna2d_Conic& C);
  //! Intersection between an hyperbola and another conic. <br>
  Standard_EXPORT   IntAna2d_AnaIntersection(const gp_Hypr2d& H,const IntAna2d_Conic& C);
  //! Intersection between two lines. <br>
  Standard_EXPORT     void Perform(const gp_Lin2d& L1,const gp_Lin2d& L2) ;
  //! Intersection between two circles. <br>
  Standard_EXPORT     void Perform(const gp_Circ2d& C1,const gp_Circ2d& C2) ;
  //! Intersection between a line and a circle. <br>
  Standard_EXPORT     void Perform(const gp_Lin2d& L,const gp_Circ2d& C) ;
  //! Intersection between a line and a conic. <br>
  Standard_EXPORT     void Perform(const gp_Lin2d& L,const IntAna2d_Conic& C) ;
  //! Intersection between a circle and another conic. <br>
  Standard_EXPORT     void Perform(const gp_Circ2d& C,const IntAna2d_Conic& Co) ;
  //! Intersection between an ellipse and another conic. <br>
  Standard_EXPORT     void Perform(const gp_Elips2d& E,const IntAna2d_Conic& C) ;
  //! Intersection between a parabola and another conic. <br>
  Standard_EXPORT     void Perform(const gp_Parab2d& P,const IntAna2d_Conic& C) ;
  //! Intersection between an hyperbola and another conic. <br>
  Standard_EXPORT     void Perform(const gp_Hypr2d& H,const IntAna2d_Conic& C) ;
  //! Returns TRUE if the computation was succesfull. <br>
        Standard_Boolean IsDone() const;
  //! Returns TRUE when there is no intersection, i-e <br>
//!           - no intersection point <br>
//!           - the elements are not identical. <br>
//!          The element may be parallel in this case. <br>
        Standard_Boolean IsEmpty() const;
  //! For the intersection between an element of gp and a conic <br>
//!          known by an implicit equation, the result will be TRUE <br>
//!          if the element of gp verifies the implicit equation. <br>
//!          For the intersection between two Lin2d or two Circ2d, the <br>
//!          result will be TRUE if the elements are identical. <br>
//!          The function returns FALSE in all the other cases. <br>
        Standard_Boolean IdenticalElements() const;
  //! For the intersection between two Lin2d or two Circ2d, <br>
//!          the function returns TRUE if the elements are parallel. <br>
//!          The function returns FALSE in all the other cases. <br>
        Standard_Boolean ParallelElements() const;
  //! returns the number of IntPoint between the 2 curves. <br>
        Standard_Integer NbPoints() const;
  //! returns the intersection point of range N; <br>
//!          If (N<=0) or (N>NbPoints), an exception is raised. <br>
       const IntAna2d_IntPoint& Point(const Standard_Integer N) const;





protected:





private:



Standard_Boolean done;
Standard_Boolean para;
Standard_Boolean iden;
Standard_Boolean empt;
Standard_Integer nbp;
IntAna2d_IntPoint lpnt[4];


};


#include <IntAna2d_AnaIntersection.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
