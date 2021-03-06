// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _SelectMgr_DataMapIteratorOfDataMapOfSelectionActivation_HeaderFile
#define _SelectMgr_DataMapIteratorOfDataMapOfSelectionActivation_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BasicMapIterator_HeaderFile
#include <TCollection_BasicMapIterator.hxx>
#endif
#ifndef _Handle_SelectMgr_Selection_HeaderFile
#include <Handle_SelectMgr_Selection.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_SelectMgr_DataMapNodeOfDataMapOfSelectionActivation_HeaderFile
#include <Handle_SelectMgr_DataMapNodeOfDataMapOfSelectionActivation.hxx>
#endif
class Standard_NoSuchObject;
class SelectMgr_Selection;
class TColStd_MapTransientHasher;
class SelectMgr_DataMapOfSelectionActivation;
class SelectMgr_DataMapNodeOfDataMapOfSelectionActivation;



class SelectMgr_DataMapIteratorOfDataMapOfSelectionActivation  : public TCollection_BasicMapIterator {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   SelectMgr_DataMapIteratorOfDataMapOfSelectionActivation();
  
  Standard_EXPORT   SelectMgr_DataMapIteratorOfDataMapOfSelectionActivation(const SelectMgr_DataMapOfSelectionActivation& aMap);
  
  Standard_EXPORT     void Initialize(const SelectMgr_DataMapOfSelectionActivation& aMap) ;
  
  Standard_EXPORT    const Handle_SelectMgr_Selection& Key() const;
  
  Standard_EXPORT    const Standard_Integer& Value() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
