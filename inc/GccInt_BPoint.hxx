// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GccInt_BPoint_HeaderFile
#define _GccInt_BPoint_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_GccInt_BPoint_HeaderFile
#include <Handle_GccInt_BPoint.hxx>
#endif

#ifndef _gp_Pnt2d_HeaderFile
#include <gp_Pnt2d.hxx>
#endif
#ifndef _GccInt_Bisec_HeaderFile
#include <GccInt_Bisec.hxx>
#endif
#ifndef _GccInt_IType_HeaderFile
#include <GccInt_IType.hxx>
#endif
class gp_Pnt2d;


//! Describes a point as a bisecting object between two 2D geometric objects. <br>
class GccInt_BPoint : public GccInt_Bisec {

public:

  //! Constructs a bisecting object whose geometry is the 2D point Point. <br>
  Standard_EXPORT   GccInt_BPoint(const gp_Pnt2d& Point);
  //! Returns a 2D point which is the geometry of this bisecting object. <br>
  Standard_EXPORT   virtual  gp_Pnt2d Point() const;
  //! Returns GccInt_Pnt, which is the type of any GccInt_BPoint bisecting object. <br>
  Standard_EXPORT     GccInt_IType ArcType() const;




  DEFINE_STANDARD_RTTI(GccInt_BPoint)

protected:




private: 


gp_Pnt2d pnt;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
