// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _CPnts_AbscissaPoint_HeaderFile
#define _CPnts_AbscissaPoint_HeaderFile

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
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _CPnts_MyRootFunction_HeaderFile
#include <CPnts_MyRootFunction.hxx>
#endif
class StdFail_NotDone;
class Standard_ConstructionError;
class Adaptor3d_Curve;
class Adaptor2d_Curve2d;


//! the algorithm computes a point on a curve at a given <br>
//!          distance from another point on the curve <br>
//! <br>
//!          We can instantiates with <br>
//!            Curve from Adaptor3d, Pnt from gp, Vec from gp <br>
//! <br>
//!          or <br>
//!            Curve2d from Adaptor2d, Pnt2d from gp, Vec2d from gp <br>
class CPnts_AbscissaPoint  {
public:

  DEFINE_STANDARD_ALLOC

  //! Computes the length of the Curve <C>. <br>
  Standard_EXPORT   static  Standard_Real Length(const Adaptor3d_Curve& C) ;
  //! Computes the length of the Curve <C>. <br>
  Standard_EXPORT   static  Standard_Real Length(const Adaptor2d_Curve2d& C) ;
  //! Computes the length of the Curve <C> with the given tolerance. <br>
  Standard_EXPORT   static  Standard_Real Length(const Adaptor3d_Curve& C,const Standard_Real Tol) ;
  //! Computes the length of the Curve <C> with the given tolerance. <br>
  Standard_EXPORT   static  Standard_Real Length(const Adaptor2d_Curve2d& C,const Standard_Real Tol) ;
  //! Computes the length of the Curve <C> between <U1> and <U2>. <br>
  Standard_EXPORT   static  Standard_Real Length(const Adaptor3d_Curve& C,const Standard_Real U1,const Standard_Real U2) ;
  //! Computes the length of the Curve <C> between <U1> and <U2>. <br>
  Standard_EXPORT   static  Standard_Real Length(const Adaptor2d_Curve2d& C,const Standard_Real U1,const Standard_Real U2) ;
  //! Computes the length of the Curve <C> between <U1> and <U2> with the given tolerance. <br>
  Standard_EXPORT   static  Standard_Real Length(const Adaptor3d_Curve& C,const Standard_Real U1,const Standard_Real U2,const Standard_Real Tol) ;
  //! Computes the length of the Curve <C> between <U1> and <U2> with the given tolerance. <br>//! creation of a indefinite AbscissaPoint. <br>
  Standard_EXPORT   static  Standard_Real Length(const Adaptor2d_Curve2d& C,const Standard_Real U1,const Standard_Real U2,const Standard_Real Tol) ;
  
  Standard_EXPORT   CPnts_AbscissaPoint();
  //! the algorithm computes a point on a curve <Curve> at the <br>
//!          distance <Abscissa> from the point of parameter <U0>. <br>
//!          <Resolution> is the error allowed in the computation. <br>
//!          The computed point can be outside of the curve 's bounds. <br>
  Standard_EXPORT   CPnts_AbscissaPoint(const Adaptor3d_Curve& C,const Standard_Real Abscissa,const Standard_Real U0,const Standard_Real Resolution);
  //! the algorithm computes a point on a curve <Curve> at the <br>
//!          distance <Abscissa> from the point of parameter <U0>. <br>
//!          <Resolution> is the error allowed in the computation. <br>
//!          The computed point can be outside of the curve 's bounds. <br>
  Standard_EXPORT   CPnts_AbscissaPoint(const Adaptor2d_Curve2d& C,const Standard_Real Abscissa,const Standard_Real U0,const Standard_Real Resolution);
  //! the algorithm computes a point on a curve <Curve> at the <br>
//!          distance <Abscissa> from the point of parameter <U0>. <br>
//!          <Ui> is the starting value used in the iterative process <br>
//!          which find the solution, it must be closed to the final <br>
//!          solution <br>
//!          <Resolution> is the error allowed in the computation. <br>
//!          The computed point can be outside of the curve 's bounds. <br>
  Standard_EXPORT   CPnts_AbscissaPoint(const Adaptor3d_Curve& C,const Standard_Real Abscissa,const Standard_Real U0,const Standard_Real Ui,const Standard_Real Resolution);
  //! the algorithm computes a point on a curve <Curve> at the <br>
//!          distance <Abscissa> from the point of parameter <U0>. <br>
//!          <Ui> is the starting value used in the iterative process <br>
//!          which find the solution, it must be closed to the final <br>
//!          solution <br>
//!          <Resolution> is the error allowed in the computation. <br>
//!          The computed point can be outside of the curve 's bounds. <br>
  Standard_EXPORT   CPnts_AbscissaPoint(const Adaptor2d_Curve2d& C,const Standard_Real Abscissa,const Standard_Real U0,const Standard_Real Ui,const Standard_Real Resolution);
  //! Initializes the resolution function with <C>. <br>
  Standard_EXPORT     void Init(const Adaptor3d_Curve& C) ;
  //! Initializes the resolution function with <C>. <br>
  Standard_EXPORT     void Init(const Adaptor2d_Curve2d& C) ;
  //! Initializes the resolution function with <C>. <br>
  Standard_EXPORT     void Init(const Adaptor3d_Curve& C,const Standard_Real Tol) ;
  //! Initializes the resolution function with <C>. <br>
  Standard_EXPORT     void Init(const Adaptor2d_Curve2d& C,const Standard_Real Tol) ;
  //! Initializes the resolution function with <C> <br>
//!          between U1 and U2. <br>
  Standard_EXPORT     void Init(const Adaptor3d_Curve& C,const Standard_Real U1,const Standard_Real U2) ;
  //! Initializes the resolution function with <C> <br>
//!          between U1 and U2. <br>
  Standard_EXPORT     void Init(const Adaptor2d_Curve2d& C,const Standard_Real U1,const Standard_Real U2) ;
  //! Initializes the resolution function with <C> <br>
//!          between U1 and U2. <br>
  Standard_EXPORT     void Init(const Adaptor3d_Curve& C,const Standard_Real U1,const Standard_Real U2,const Standard_Real Tol) ;
  //! Initializes the resolution function with <C> <br>
//!          between U1 and U2. <br>
  Standard_EXPORT     void Init(const Adaptor2d_Curve2d& C,const Standard_Real U1,const Standard_Real U2,const Standard_Real Tol) ;
  //! Computes the point at the distance <Abscissa> of <br>
//!          the curve. <br>
  Standard_EXPORT     void Perform(const Standard_Real Abscissa,const Standard_Real U0,const Standard_Real Resolution) ;
  //! Computes the point at the distance <Abscissa> of <br>
//!          the curve. <br>
  Standard_EXPORT     void Perform(const Standard_Real Abscissa,const Standard_Real U0,const Standard_Real Ui,const Standard_Real Resolution) ;
  //! Computes the point at the distance <Abscissa> of <br>
//!          the curve; performs more appropriate tolerance managment; <br>
//!          to use this method in right way it is necessary to call <br>
//!          empty consructor. then call method Init with <br>
//!	        Tolerance = Resolution, then call AdvPermorm. <br>
  Standard_EXPORT     void AdvPerform(const Standard_Real Abscissa,const Standard_Real U0,const Standard_Real Ui,const Standard_Real Resolution) ;
  //! True if the computation was successful, False otherwise. <br>
        Standard_Boolean IsDone() const;
  //! Returns the parameter of the solution. <br>
//! <br>
        Standard_Real Parameter() const;
  //! Enforce the solution, used by GCPnts. <br>
//! <br>
        void SetParameter(const Standard_Real P) ;





protected:





private:



Standard_Boolean myDone;
Standard_Real myL;
Standard_Real myParam;
Standard_Real myUMin;
Standard_Real myUMax;
CPnts_MyRootFunction myF;


};


#include <CPnts_AbscissaPoint.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
