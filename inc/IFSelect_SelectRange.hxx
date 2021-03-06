// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IFSelect_SelectRange_HeaderFile
#define _IFSelect_SelectRange_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IFSelect_SelectRange_HeaderFile
#include <Handle_IFSelect_SelectRange.hxx>
#endif

#ifndef _Handle_IFSelect_IntParam_HeaderFile
#include <Handle_IFSelect_IntParam.hxx>
#endif
#ifndef _IFSelect_SelectExtract_HeaderFile
#include <IFSelect_SelectExtract.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Handle_Interface_InterfaceModel_HeaderFile
#include <Handle_Interface_InterfaceModel.hxx>
#endif
class IFSelect_IntParam;
class Standard_DomainError;
class Standard_Transient;
class Interface_InterfaceModel;
class TCollection_AsciiString;


//! A SelectRange keeps or rejects a sub-set of the input set, <br>
//!           that is the Entities of which rank in the iteration list <br>
//!           is in a given range (for instance form 2nd to 6th, etc...) <br>
class IFSelect_SelectRange : public IFSelect_SelectExtract {

public:

  //! Creates a SelectRange. Default is Take all the input list <br>
  Standard_EXPORT   IFSelect_SelectRange();
  //! Sets a Range for numbers, with a lower and a upper limits <br>
//!           Error if rankto is lower then rankfrom <br>
  Standard_EXPORT     void SetRange(const Handle(IFSelect_IntParam)& rankfrom,const Handle(IFSelect_IntParam)& rankto) ;
  //! Sets a unique number (only one Entity will be sorted as True) <br>
  Standard_EXPORT     void SetOne(const Handle(IFSelect_IntParam)& rank) ;
  //! Sets a Lower limit but no upper limit <br>
  Standard_EXPORT     void SetFrom(const Handle(IFSelect_IntParam)& rankfrom) ;
  //! Sets an Upper limit but no lower limit (equivalent to lower 1) <br>
  Standard_EXPORT     void SetUntil(const Handle(IFSelect_IntParam)& rankto) ;
  //! Returns True if a Lower limit is defined <br>
  Standard_EXPORT     Standard_Boolean HasLower() const;
  //! Returns Lower limit (if there is; else, value is senseless) <br>
  Standard_EXPORT     Handle_IFSelect_IntParam Lower() const;
  //! Returns Value of Lower Limit (0 if none is defined) <br>
  Standard_EXPORT     Standard_Integer LowerValue() const;
  //! Returns True if a Lower limit is defined <br>
  Standard_EXPORT     Standard_Boolean HasUpper() const;
  //! Returns Upper limit (if there is; else, value is senseless) <br>
  Standard_EXPORT     Handle_IFSelect_IntParam Upper() const;
  //! Returns Value of Upper Limit (0 if none is defined) <br>
  Standard_EXPORT     Standard_Integer UpperValue() const;
  //! Returns True for an Entity of which occurence number in the <br>
//!           iteration is inside the selected Range (considers <rank>) <br>
  Standard_EXPORT     Standard_Boolean Sort(const Standard_Integer rank,const Handle(Standard_Transient)& ent,const Handle(Interface_InterfaceModel)& model) const;
  //! Returns a text defining the criterium : following cases, <br>
//!           " From .. Until .." or "From .." or "Until .." or "Rank no .." <br>
  Standard_EXPORT     TCollection_AsciiString ExtractLabel() const;




  DEFINE_STANDARD_RTTI(IFSelect_SelectRange)

protected:




private: 


Handle_IFSelect_IntParam thelower;
Handle_IFSelect_IntParam theupper;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
