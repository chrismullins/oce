// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Poly_Polygon2D_HeaderFile
#define _Poly_Polygon2D_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Poly_Polygon2D_HeaderFile
#include <Handle_Poly_Polygon2D.hxx>
#endif

#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TColgp_Array1OfPnt2d_HeaderFile
#include <TColgp_Array1OfPnt2d.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
class Standard_NullObject;
class TColgp_Array1OfPnt2d;


//! Provides a polygon in 2D space (for example, in the <br>
//! parametric space of a surface). It is generally an <br>
//! approximate representation of a curve. <br>
//! A Polygon2D is defined by a table of nodes. Each node is <br>
//! a 2D point. If the polygon is closed, the point of closure is <br>
//! repeated at the end of the table of nodes. <br>
class Poly_Polygon2D : public MMgt_TShared {

public:

  //! Constructs a 2D polygon defined by the table of points, <Nodes>. <br>
  Standard_EXPORT   Poly_Polygon2D(const TColgp_Array1OfPnt2d& Nodes);
  //! Returns the deflection of this polygon. <br>
//!  Deflection is used in cases where the polygon is an <br>
//! approximate representation of a curve. Deflection <br>
//! represents the maximum distance permitted between any <br>
//! point on the curve and the corresponding point on the polygon. <br>
//! By default the deflection value is equal to 0. An algorithm <br>
//! using this 2D polygon with a deflection value equal to 0 <br>
//! considers that it is working with a true polygon and not with <br>
//! an approximate representation of a curve. The Deflection <br>
//! function is used to modify the deflection value of this polygon. <br>
//! The deflection value can be used by any algorithm working  with 2D polygons. <br>
//! For example: <br>
//! -   An algorithm may use a unique deflection value for all <br>
//!   its polygons. In this case it is not necessary to use the <br>
//!   Deflection function. <br>
//! -   Or an algorithm may want to attach a different <br>
//!   deflection to each polygon. In this case, the Deflection <br>
//!   function is used to set a value on each polygon, and <br>
//!   later to fetch the value. <br>
  Standard_EXPORT     Standard_Real Deflection() const;
  //! Sets the deflection of this polygon to D <br>
  Standard_EXPORT     void Deflection(const Standard_Real D) ;
  //! Returns the number of nodes in this polygon. <br>
//! Note: If the polygon is closed, the point of closure is <br>
//! repeated at the end of its table of nodes. Thus, on a closed <br>
//! triangle, the function NbNodes returns 4. <br>
        Standard_Integer NbNodes() const;
  //! Returns the table of nodes for this polygon. <br>
  Standard_EXPORT    const TColgp_Array1OfPnt2d& Nodes() const;




  DEFINE_STANDARD_RTTI(Poly_Polygon2D)

protected:




private: 


Standard_Real myDeflection;
Standard_Integer myNbNodes;
TColgp_Array1OfPnt2d myNodes;


};


#include <Poly_Polygon2D.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
