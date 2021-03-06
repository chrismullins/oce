// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRep_Polygon3D_HeaderFile
#define _BRep_Polygon3D_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BRep_Polygon3D_HeaderFile
#include <Handle_BRep_Polygon3D.hxx>
#endif

#ifndef _Handle_Poly_Polygon3D_HeaderFile
#include <Handle_Poly_Polygon3D.hxx>
#endif
#ifndef _BRep_CurveRepresentation_HeaderFile
#include <BRep_CurveRepresentation.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_BRep_CurveRepresentation_HeaderFile
#include <Handle_BRep_CurveRepresentation.hxx>
#endif
class Poly_Polygon3D;
class Standard_DomainError;
class TopLoc_Location;
class BRep_CurveRepresentation;



class BRep_Polygon3D : public BRep_CurveRepresentation {

public:

  
  Standard_EXPORT   BRep_Polygon3D(const Handle(Poly_Polygon3D)& P,const TopLoc_Location& L);
  //! Returns True. <br>
  Standard_EXPORT   virtual  Standard_Boolean IsPolygon3D() const;
  
  Standard_EXPORT   virtual const Handle_Poly_Polygon3D& Polygon3D() const;
  
  Standard_EXPORT   virtual  void Polygon3D(const Handle(Poly_Polygon3D)& P) ;
  //! Return a copy of this representation. <br>
  Standard_EXPORT     Handle_BRep_CurveRepresentation Copy() const;




  DEFINE_STANDARD_RTTI(BRep_Polygon3D)

protected:




private: 


Handle_Poly_Polygon3D myPolygon3D;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
