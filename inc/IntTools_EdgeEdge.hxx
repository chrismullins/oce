// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntTools_EdgeEdge_HeaderFile
#define _IntTools_EdgeEdge_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopoDS_Edge_HeaderFile
#include <TopoDS_Edge.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _BRepAdaptor_Curve_HeaderFile
#include <BRepAdaptor_Curve.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _IntTools_SequenceOfCommonPrts_HeaderFile
#include <IntTools_SequenceOfCommonPrts.hxx>
#endif
#ifndef _IntTools_Range_HeaderFile
#include <IntTools_Range.hxx>
#endif
class TopoDS_Edge;
class IntTools_Range;
class IntTools_SequenceOfCommonPrts;
class IntTools_CommonPrt;
class IntTools_CArray1OfReal;


//! The  class  provides  Edge/Edge  algorithm  to  determine <br>
//!          common  parts  between two edges in  3-d space. <br>
//!          Common  parts can be :  Vertices  or Edges. <br>
//! <br>
class IntTools_EdgeEdge  {
public:

  DEFINE_STANDARD_ALLOC

  
//! Empty constructor <br>
  Standard_EXPORT   IntTools_EdgeEdge();
  
//! Sets the first edge <br>
  Standard_EXPORT     void SetEdge1(const TopoDS_Edge& anEdge) ;
  
//! Sets  the  value of tolerance pipe for the first edge <br>
  Standard_EXPORT     void SetTolerance1(const Standard_Real aTolEdge1) ;
  
//! Sets the second edge <br>
  Standard_EXPORT     void SetEdge2(const TopoDS_Edge& anEdge) ;
  
//! Sets  the  value of tolerance pipe for the first edge <br>
  Standard_EXPORT     void SetTolerance2(const Standard_Real aTolEdge2) ;
  
//! Sets  the  number of division for the shortest <br>
//! edge among the two.  The  deflection is not taken <br>
//! into  account <br>
  Standard_EXPORT     void SetDiscretize(const Standard_Integer aDiscret) ;
  
//! Sets the value of maximum reative deflection between <br>
//! the two nearest points on a curve. <br>
  Standard_EXPORT     void SetDeflection(const Standard_Real aDeflection) ;
  
//! Sets the criteria of equality of two arguments, <br>
//! i.e.  |t2-t1|<anEpsT will mean that t2=t1 <br>
  Standard_EXPORT     void SetEpsilonT(const Standard_Real anEpsT) ;
  
//! Sets the criteria of equality of two functions' values <br>
//! i.e.  |f(t2)-f(t1)|<anEpsNull will mean that f(t2)=f(t1) <br>
  Standard_EXPORT     void SetEpsilonNull(const Standard_Real anEpsNull) ;
  
  Standard_EXPORT     void SetRange1(const IntTools_Range& aRange) ;
  
  Standard_EXPORT     void SetRange2(const IntTools_Range& aRange) ;
  
  Standard_EXPORT     void SetRange1(const Standard_Real aFirst,const Standard_Real aLast) ;
  
  Standard_EXPORT     void SetRange2(const Standard_Real aFirst,const Standard_Real aLast) ;
  
//! The main method of the algorithm to determine <br>
//! common  parts  between two edges in  3-d space <br>
  Standard_EXPORT     void Perform() ;
  
//! True if the common  parts are found <br>
  Standard_EXPORT     Standard_Boolean IsDone() const;
  
//! False if the common parts are coherented  with Edge1, Edge2 <br>
  Standard_EXPORT     Standard_Boolean Order() const;
  //! Returns the number that corresponds to the error. <br>
//! The  list of error-codes is in  ...cxx file <br>
  Standard_EXPORT     Standard_Integer ErrorStatus() const;
  
//! Returns the common parts (Output) <br>
  Standard_EXPORT    const IntTools_SequenceOfCommonPrts& CommonParts() const;
  
  Standard_EXPORT    const IntTools_Range& Range1() const;
  
  Standard_EXPORT    const IntTools_Range& Range2() const;





protected:

  
//! Fool-proof chechking the input data. <br>
//! The  following  data is not  available <br>
//!    *  Degenerated edges is  not  available; <br>
//!    *  Egdes,  that don't contain 3d-curve. <br>
  Standard_EXPORT     void CheckData() ;
  
//! Preparing the main  fields  for  the  algorithm <br>
//!    *  From-Curve  (myCFrom,myTminFrom,myTmaxFrom), <br>
//!    *  To  -Curve  (myCTo  ,myTminTo  ,myTmaxTo  ), <br>
//!    *  myCreiteria=myTol1+myTol2  , <br>
//!    *  myProjectableRanges. <br>
  Standard_EXPORT     void Prepare() ;
  
//! Returns the flag 1 if it is possible to project <br>
//! the point from the From-Curve at the  parameter t <br>
//! to the To-Curve. <br>
//! Othrwise it returns  0. <br>
  Standard_EXPORT     Standard_Integer IsProjectable(const Standard_Real t) const;
  
//! Find the range on the curve Curve-To that  corresponds <br>
//! to  the  given  range on the curve Curve-From. <br>
  Standard_EXPORT     Standard_Integer FindRangeOnCurve2(IntTools_CommonPrt& aCP) ;
  
//! Find the  value  of  the  parameter  on  the curve Curve-To <br>
//! that corresponds  to  the  given  parameter  on the curve <br>
//! Curve-From. <br>
  Standard_EXPORT     Standard_Integer GetParameterOnCurve2(const Standard_Real aT1,Standard_Real& aT2) const;
  
  Standard_EXPORT     Standard_Integer TreatVertexType(const Standard_Real am1,const Standard_Real am2,IntTools_CommonPrt& aCP) ;
  
  Standard_EXPORT     void IsIntersection(const Standard_Real t1,const Standard_Real t2) ;
  
  Standard_EXPORT     void FindDerivativeRoot(const IntTools_CArray1OfReal& t,const IntTools_CArray1OfReal& f) ;
  
//! Find the Root of the function on given interval <br>
//! of the argument [ta,tb] using  bisection  method . <br>
//! IP  - a  flag; <br>
//! =1  -  use DistanceFunction; <br>
//! =2  -  use DerivativeFunction; <br>
//! <br>
  Standard_EXPORT     Standard_Real FindSimpleRoot(const Standard_Integer IP,const Standard_Real ta,const Standard_Real tb,const Standard_Real fA) ;
  
//! Calculates the DistanceFunction D(t). <br>
//! D(t)=D1(t) - myCriteria; <br>
//! where <br>
//! D1(t) -  the lower distance between a point from <br>
//! the  From-Curve at  parameter t  and <br>
//! projection point of  this point on To-Curve; <br>
//! myCriteria=myTol1+myTol2. <br>
  Standard_EXPORT     Standard_Real DistanceFunction(const Standard_Real t) ;
  
//! Calculates the first derivative of <br>
//! the DistanceFunction D(t). <br>
  Standard_EXPORT     Standard_Real DerivativeFunction(const Standard_Real t) ;
  
  Standard_EXPORT     Standard_Boolean CheckTouch(const IntTools_CommonPrt& aCP,Standard_Real& t1,Standard_Real& t2) ;
  
  Standard_EXPORT     Standard_Boolean CheckTouchVertex(const IntTools_CommonPrt& aCP,Standard_Real& t1,Standard_Real& t2) const;
  
  Standard_EXPORT     void ComputeLineLine() ;
  
  Standard_EXPORT     Standard_Boolean IsSameCurves() ;




private:



TopoDS_Edge myEdge1;
TopoDS_Edge myEdge2;
Standard_Real myTol1;
Standard_Real myTol2;
Standard_Integer myDiscret;
Standard_Real myEpsT;
Standard_Real myEpsNull;
Standard_Real myDeflection;
BRepAdaptor_Curve myCFrom;
Standard_Real myTminFrom;
Standard_Real myTmaxFrom;
Standard_Real myTolFrom;
BRepAdaptor_Curve myCTo;
Standard_Real myTminTo;
Standard_Real myTmaxTo;
Standard_Real myTolTo;
Standard_Real myCriteria;
Standard_Boolean myIsDone;
Standard_Integer myErrorStatus;
IntTools_SequenceOfCommonPrts mySeqOfCommonPrts;
Standard_Boolean myOrder;
Standard_Real myPar1;
Standard_Boolean myParallel;
IntTools_Range myRange1;
IntTools_Range myRange2;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
