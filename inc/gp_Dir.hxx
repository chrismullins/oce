// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _gp_Dir_HeaderFile
#define _gp_Dir_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _gp_XYZ_HeaderFile
#include <gp_XYZ.hxx>
#endif
#ifndef _Standard_Storable_HeaderFile
#include <Standard_Storable.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_PrimitiveTypes_HeaderFile
#include <Standard_PrimitiveTypes.hxx>
#endif
class Standard_ConstructionError;
class Standard_DomainError;
class Standard_OutOfRange;
class gp_Vec;
class gp_XYZ;
class gp_Ax1;
class gp_Ax2;
class gp_Trsf;


Standard_EXPORT const Handle(Standard_Type)& STANDARD_TYPE(gp_Dir);


//! Describes a unit vector in 3D space. This unit vector is also called "Direction". <br>
//! See Also <br>
//! gce_MakeDir which provides functions for more complex <br>
//! unit vector constructions <br>
//! Geom_Direction which provides additional functions for <br>
//! constructing unit vectors and works, in particular, with the <br>
//! parametric equations of unit vectors. <br>
class gp_Dir  {

public:

  DEFINE_STANDARD_ALLOC

  //! Creates a direction corresponding to X axis. <br>
      gp_Dir();
  //! Normalizes the vector V and creates a direction. Raises ConstructionError if V.Magnitude() <= Resolution. <br>
      gp_Dir(const gp_Vec& V);
  //! Creates a direction from a triplet of coordinates. Raises ConstructionError if Coord.Modulus() <= Resolution from gp. <br>
      gp_Dir(const gp_XYZ& Coord);
  //! Creates a direction with its 3 cartesian coordinates. Raises ConstructionError if Sqrt(Xv*Xv + Yv*Yv + Zv*Zv) <= Resolution <br>//! Modification of the direction's coordinates <br>
//!  If Sqrt (X*X + Y*Y + Z*Z) <= Resolution from gp where <br>
//!  X, Y ,Z are the new coordinates it is not possible to <br>
//!  construct the direction and the method raises the <br>
//!  exception ConstructionError. <br>
      gp_Dir(const Standard_Real Xv,const Standard_Real Yv,const Standard_Real Zv);
  
//! For this unit vector,  assigns the value Xi to: <br>
//!   -   the X coordinate if Index is 1, or <br>
//!   -   the Y coordinate if Index is 2, or <br>
//!   -   the Z coordinate if Index is 3, <br>
//!   and then normalizes it. <br>
//! Warning <br>
//! Remember that all the coordinates of a unit vector are <br>
//! implicitly modified when any single one is changed directly. <br>
//! Exceptions <br>
//! Standard_OutOfRange if Index is not 1, 2, or 3. <br>
//! Standard_ConstructionError if either of the following <br>
//! is less than or equal to gp::Resolution(): <br>
//! -   Sqrt(Xv*Xv + Yv*Yv + Zv*Zv), or <br>
//! -   the modulus of the number triple formed by the new <br>
//!   value Xi and the two other coordinates of this vector <br>
//!   that were not directly modified. <br>
        void SetCoord(const Standard_Integer Index,const Standard_Real Xi) ;
  //! For this unit vector,  assigns the values Xv, Yv and Zv to its three coordinates. <br>
//! Remember that all the coordinates of a unit vector are <br>
//! implicitly modified when any single one is changed directly. <br>
        void SetCoord(const Standard_Real Xv,const Standard_Real Yv,const Standard_Real Zv) ;
  //! Assigns the given value to the X coordinate of this   unit vector. <br>
        void SetX(const Standard_Real X) ;
  //! Assigns the given value to the Y coordinate of this   unit vector. <br>
        void SetY(const Standard_Real Y) ;
  //! Assigns the given value to the Z  coordinate of this   unit vector. <br>
        void SetZ(const Standard_Real Z) ;
  //! Assigns the three coordinates of Coord to this unit vector. <br>
        void SetXYZ(const gp_XYZ& Coord) ;
  
//!  Returns the coordinate of range Index : <br>
//!  Index = 1 => X is returned <br>
//!  Index = 2 => Y is returned <br>
//!  Index = 3 => Z is returned <br>
//! Exceptions <br>
//! Standard_OutOfRange if Index is not 1, 2, or 3. <br>
        Standard_Real Coord(const Standard_Integer Index) const;
  //! Returns for the  unit vector  its three coordinates Xv, Yv, and Zv. <br>
        void Coord(Standard_Real& Xv,Standard_Real& Yv,Standard_Real& Zv) const;
  //! Returns the X coordinate for a  unit vector. <br>
        Standard_Real X() const;
  //! Returns the Y coordinate for a  unit vector. <br>
        Standard_Real Y() const;
  //! Returns the Z coordinate for a  unit vector. <br>
        Standard_Real Z() const;
  //! for this unit vector, returns  its three coordinates as a number triplea. <br>
       const gp_XYZ& XYZ() const;
  
//!  Returns True if the angle between the two directions is <br>
//!  lower or equal to AngularTolerance. <br>
        Standard_Boolean IsEqual(const gp_Dir& Other,const Standard_Real AngularTolerance) const;
  
//!  Returns True if  the angle between this unit vector and the unit vector Other is equal to Pi/2 (normal). <br>
        Standard_Boolean IsNormal(const gp_Dir& Other,const Standard_Real AngularTolerance) const;
  
//!  Returns True if  the angle between this unit vector and the unit vector Other is equal to  Pi (opposite). <br>
        Standard_Boolean IsOpposite(const gp_Dir& Other,const Standard_Real AngularTolerance) const;
  
//! Returns true if the angle between this unit vector and the <br>
//! unit vector Other is equal to 0 or to Pi. <br>
//! Note: the tolerance criterion is given by AngularTolerance. <br>
        Standard_Boolean IsParallel(const gp_Dir& Other,const Standard_Real AngularTolerance) const;
  
//!  Computes the angular value in radians between <me> and <br>
//!  <Other>. This value is always positive in 3D space. <br>
//!  Returns the angle in the range [0, PI] <br>
  Standard_EXPORT     Standard_Real Angle(const gp_Dir& Other) const;
  
//!  Computes the angular value between <me> and <Other>. <br>
//!  <VRef> is the direction of reference normal to <me> and <Other> <br>
//!  and its orientation gives the positive sense of rotation. <br>
//!  If the cross product <me> ^ <Other> has the same orientation <br>
//!  as <VRef> the angular value is positive else negative. <br>
//!  Returns the angular value in the range -PI and PI (in radians). Raises  DomainError if <me> and <Other> are not parallel this exception is raised <br>
//!  when <VRef> is in the same plane as <me> and <Other> <br>
//!  The tolerance criterion is Resolution from package gp. <br>
  Standard_EXPORT     Standard_Real AngleWithRef(const gp_Dir& Other,const gp_Dir& VRef) const;
  //! Computes the cross product between two directions <br>
//!  Raises the exception ConstructionError if the two directions <br>
//!  are parallel because the computed vector cannot be normalized <br>
//!  to create a direction. <br>
        void Cross(const gp_Dir& Right) ;
      void operator ^=(const gp_Dir& Right) 
{
  Cross(Right);
}
  //! Computes the triple vector product. <br>
//!  <me> ^ (V1 ^ V2) <br>
//!  Raises the exception ConstructionError if V1 and V2 are parallel <br>
//!  or <me> and (V1^V2) are parallel because the computed vector <br>
//!  can't be normalized to create a direction. <br>
        gp_Dir Crossed(const gp_Dir& Right) const;
      gp_Dir operator ^(const gp_Dir& Right) const
{
  return Crossed(Right);
}
  
        void CrossCross(const gp_Dir& V1,const gp_Dir& V2) ;
  //!  Computes the double vector product this ^ (V1 ^ V2). <br>
//!  -   CrossCrossed creates a new unit vector. <br>
//! Exceptions <br>
//! Standard_ConstructionError if: <br>
//! -   V1 and V2 are parallel, or <br>
//! -   this unit vector and (V1 ^ V2) are parallel. <br>
//! This is because, in these conditions, the computed vector <br>
//! is null and cannot be normalized. <br>
        gp_Dir CrossCrossed(const gp_Dir& V1,const gp_Dir& V2) const;
  //! Computes the scalar product <br>
        Standard_Real Dot(const gp_Dir& Other) const;
      Standard_Real operator *(const gp_Dir& Other) const
{
  return Dot(Other);
}
  
//!  Computes the triple scalar product <me> * (V1 ^ V2). <br>
//! Warnings : <br>
//!  The computed vector V1' = V1 ^ V2 is not normalized <br>
//!  to create a unitary vector. So this method never <br>
//!  raises an exception even if V1 and V2 are parallel. <br>
        Standard_Real DotCross(const gp_Dir& V1,const gp_Dir& V2) const;
  
        void Reverse() ;
  //! Reverses the orientation of a direction <br>//! geometric transformations <br>
//!  Performs the symmetrical transformation of a direction <br>
//!  with respect to the direction V which is the center of <br>
//!  the  symmetry.] <br>
        gp_Dir Reversed() const;
      gp_Dir operator -() const
{
  return Reversed();
}
  
  Standard_EXPORT     void Mirror(const gp_Dir& V) ;
  
//!  Performs the symmetrical transformation of a direction <br>
//!  with respect to the direction V which is the center of <br>
//!  the  symmetry. <br>
  Standard_EXPORT     gp_Dir Mirrored(const gp_Dir& V) const;
  
  Standard_EXPORT     void Mirror(const gp_Ax1& A1) ;
  
//!  Performs the symmetrical transformation of a direction <br>
//!  with respect to an axis placement which is the axis <br>
//!  of the symmetry. <br>
  Standard_EXPORT     gp_Dir Mirrored(const gp_Ax1& A1) const;
  
  Standard_EXPORT     void Mirror(const gp_Ax2& A2) ;
  
//!  Performs the symmetrical transformation of a direction <br>
//!  with respect to a plane. The axis placement A2 locates <br>
//!  the plane of the symmetry : (Location, XDirection, YDirection). <br>
  Standard_EXPORT     gp_Dir Mirrored(const gp_Ax2& A2) const;
  
        void Rotate(const gp_Ax1& A1,const Standard_Real Ang) ;
  
//!  Rotates a direction. A1 is the axis of the rotation. <br>
//!  Ang is the angular value of the rotation in radians. <br>
        gp_Dir Rotated(const gp_Ax1& A1,const Standard_Real Ang) const;
  
  Standard_EXPORT     void Transform(const gp_Trsf& T) ;
  
//!  Transforms a direction with a "Trsf" from gp. <br>
//! Warnings : <br>
//!  If the scale factor of the "Trsf" T is negative then the <br>
//!  direction <me> is reversed. <br>
        gp_Dir Transformed(const gp_Trsf& T) const;
    const gp_XYZ& _CSFDB_Getgp_Dircoord() const { return coord; }



protected:




private: 


gp_XYZ coord;


};


#include <gp_Dir.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
