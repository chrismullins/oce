// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Visual3d_PickPath_HeaderFile
#define _Visual3d_PickPath_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Graphic3d_Structure_HeaderFile
#include <Handle_Graphic3d_Structure.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Graphic3d_Structure;
class Visual3d_PickError;


//! PickPath is a vector ( pick_id, struct_id, elem_num ). <br>
//!	    It's one of the constituents of a PickDescriptor. <br>
//!	    There are many PickPaths in a PickDescriptor. <br>
//!	    Each PickPath describes a structure or a sub-structure. <br>
//!	    The pick_id is set by SetPickId method from Group. <br>
class Visual3d_PickPath  {
public:

  DEFINE_STANDARD_ALLOC

  //! Creates an undefined PickPath. <br>
  Standard_EXPORT   Visual3d_PickPath();
  //! Creates a PickPath : <br>
//!	    <AElemNumber> : Element number of the structure picked. <br>
//!	    <APickId>	  : Pick identifier of the structure picked. <br>
//!	    <AStructure>  : The picked structure. <br>
  Standard_EXPORT   Visual3d_PickPath(const Standard_Integer AElemNumber,const Standard_Integer APickId,const Handle(Graphic3d_Structure)& AStructure);
  //! Modifies the PickPath <me>. <br>
//!	    <AElemNumber> : Element number of the structure picked. <br>
  Standard_EXPORT     void SetElementNumber(const Standard_Integer AElemNumber) ;
  //! Modifies the PickPath <me>. <br>
//!	    <APickId>	  : Pick identifier of the structure picked. <br>
  Standard_EXPORT     void SetPickIdentifier(const Standard_Integer APickId) ;
  //! Modifies the PickPath <me>. <br>
//!	    <AStructure>	: Identifier of the structure picked. <br>
  Standard_EXPORT     void SetStructIdentifier(const Handle(Graphic3d_Structure)& AStructure) ;
  //! Returns the element number stocked in the PickPath <me>. <br>
//!  Category: Inquire methods <br>
//!  Warning: Raises PickError if PickPath is empty (no picked structure). <br>
  Standard_EXPORT     Standard_Integer ElementNumber() const;
  //! Returns the pick identifier stocked in the PickPath <me>. <br>
//!  Category: Inquire methods <br>
//!  Warning: Raises PickError if PickPath is empty (no picked structure). <br>
  Standard_EXPORT     Standard_Integer PickIdentifier() const;
  //! Returns the structure stocked in the PickPath <me>. <br>
//!  Category: Inquire methods <br>
//!  Warning: Raises PickError if PickPath is empty (no picked structure). <br>
  Standard_EXPORT     Handle_Graphic3d_Structure StructIdentifier() const;





protected:





private:



Standard_Integer MyElementNumber;
Standard_Integer MyPickId;
Handle_Graphic3d_Structure MyStructure;
Standard_Boolean MyElementNumberIsDef;
Standard_Boolean MyPickIdIsDef;
Standard_Boolean MyStructureIsDef;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
