// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESData_TransfEntity_HeaderFile
#define _IGESData_TransfEntity_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IGESData_TransfEntity_HeaderFile
#include <Handle_IGESData_TransfEntity.hxx>
#endif

#ifndef _IGESData_IGESEntity_HeaderFile
#include <IGESData_IGESEntity.hxx>
#endif
class gp_GTrsf;


//! defines required type for Transf in directory part <br>
//!           an effective Transf entity must inherits it <br>
class IGESData_TransfEntity : public IGESData_IGESEntity {

public:

  //! gives value of the transformation, as a GTrsf <br>
//!           To be defined by an effective class of Transformation Entity <br>
//!  Warning : Must take in account Composition : if a TransfEntity has in <br>
//!           its Directory Part, a Transf, this means that it is Compound, <br>
//!           Value must return the global result <br>
  Standard_EXPORT   virtual  gp_GTrsf Value() const = 0;




  DEFINE_STANDARD_RTTI(IGESData_TransfEntity)

protected:




private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
