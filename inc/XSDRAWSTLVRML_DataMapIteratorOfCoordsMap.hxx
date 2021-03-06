// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _XSDRAWSTLVRML_DataMapIteratorOfCoordsMap_HeaderFile
#define _XSDRAWSTLVRML_DataMapIteratorOfCoordsMap_HeaderFile

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
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_XSDRAWSTLVRML_DataMapNodeOfCoordsMap_HeaderFile
#include <Handle_XSDRAWSTLVRML_DataMapNodeOfCoordsMap.hxx>
#endif
class Standard_NoSuchObject;
class TColStd_DataMapOfIntegerReal;
class TColStd_MapIntegerHasher;
class XSDRAWSTLVRML_CoordsMap;
class XSDRAWSTLVRML_DataMapNodeOfCoordsMap;



class XSDRAWSTLVRML_DataMapIteratorOfCoordsMap  : public TCollection_BasicMapIterator {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   XSDRAWSTLVRML_DataMapIteratorOfCoordsMap();
  
  Standard_EXPORT   XSDRAWSTLVRML_DataMapIteratorOfCoordsMap(const XSDRAWSTLVRML_CoordsMap& aMap);
  
  Standard_EXPORT     void Initialize(const XSDRAWSTLVRML_CoordsMap& aMap) ;
  
  Standard_EXPORT    const Standard_Integer& Key() const;
  
  Standard_EXPORT    const TColStd_DataMapOfIntegerReal& Value() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
