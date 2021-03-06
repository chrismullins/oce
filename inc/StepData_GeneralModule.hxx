// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepData_GeneralModule_HeaderFile
#define _StepData_GeneralModule_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepData_GeneralModule_HeaderFile
#include <Handle_StepData_GeneralModule.hxx>
#endif

#ifndef _Interface_GeneralModule_HeaderFile
#include <Interface_GeneralModule.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Handle_Interface_Check_HeaderFile
#include <Handle_Interface_Check.hxx>
#endif
class Standard_Transient;
class Interface_EntityIterator;
class Interface_ShareTool;
class Interface_Check;
class Interface_CopyTool;


//! Specific features for General Services adapted to STEP <br>
class StepData_GeneralModule : public Interface_GeneralModule {

public:

  //! Specific filling of the list of Entities shared by an Entity <br>
//!           <ent>. Can use the internal utility method Share, below <br>
  Standard_EXPORT   virtual  void FillSharedCase(const Standard_Integer casenum,const Handle(Standard_Transient)& ent,Interface_EntityIterator& iter) const = 0;
  //! Specific Checking of an Entity <ent> <br>
  Standard_EXPORT   virtual  void CheckCase(const Standard_Integer casenum,const Handle(Standard_Transient)& ent,const Interface_ShareTool& shares,Handle(Interface_Check)& ach) const = 0;
  //! Specific Copy ("Deep") from <entfrom> to <entto> (same type) <br>
//!           by using a TransferControl which provides its working Map. <br>
//!           Use method Transferred from TransferControl to work <br>//! Specific Copying of Implied References <br>
//!           A Default is provided which does nothing (must current case !) <br>
//!           Already copied references (by CopyFrom) must remain unchanged <br>
//!           Use method Search from TransferControl to work <br>
  Standard_EXPORT   virtual  void CopyCase(const Standard_Integer casenum,const Handle(Standard_Transient)& entfrom,const Handle(Standard_Transient)& entto,Interface_CopyTool& TC) const = 0;




  DEFINE_STANDARD_RTTI(StepData_GeneralModule)

protected:




private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
