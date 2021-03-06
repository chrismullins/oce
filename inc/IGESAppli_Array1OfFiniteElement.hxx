// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESAppli_Array1OfFiniteElement_HeaderFile
#define _IGESAppli_Array1OfFiniteElement_HeaderFile

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
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_IGESAppli_FiniteElement_HeaderFile
#include <Handle_IGESAppli_FiniteElement.hxx>
#endif
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class IGESAppli_FiniteElement;



class IGESAppli_Array1OfFiniteElement  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   IGESAppli_Array1OfFiniteElement(const Standard_Integer Low,const Standard_Integer Up);
  
  Standard_EXPORT   IGESAppli_Array1OfFiniteElement(const Handle(IGESAppli_FiniteElement)& Item,const Standard_Integer Low,const Standard_Integer Up);
  
  Standard_EXPORT     void Init(const Handle(IGESAppli_FiniteElement)& V) ;
  
  Standard_EXPORT     void Destroy() ;
~IGESAppli_Array1OfFiniteElement()
{
  Destroy();
}
  
        Standard_Boolean IsAllocated() const;
  
  Standard_EXPORT    const IGESAppli_Array1OfFiniteElement& Assign(const IGESAppli_Array1OfFiniteElement& Other) ;
   const IGESAppli_Array1OfFiniteElement& operator =(const IGESAppli_Array1OfFiniteElement& Other) 
{
  return Assign(Other);
}
  
        Standard_Integer Length() const;
  
        Standard_Integer Lower() const;
  
        Standard_Integer Upper() const;
  
        void SetValue(const Standard_Integer Index,const Handle(IGESAppli_FiniteElement)& Value) ;
  
       const Handle_IGESAppli_FiniteElement& Value(const Standard_Integer Index) const;
     const Handle_IGESAppli_FiniteElement& operator ()(const Standard_Integer Index) const
{
  return Value(Index);
}
  
        Handle_IGESAppli_FiniteElement& ChangeValue(const Standard_Integer Index) ;
      Handle_IGESAppli_FiniteElement& operator ()(const Standard_Integer Index) 
{
  return ChangeValue(Index);
}





protected:





private:

  
  Standard_EXPORT   IGESAppli_Array1OfFiniteElement(const IGESAppli_Array1OfFiniteElement& AnArray);


Standard_Integer myLowerBound;
Standard_Integer myUpperBound;
Standard_Address myStart;
Standard_Boolean isAllocated;


};

#define Array1Item Handle_IGESAppli_FiniteElement
#define Array1Item_hxx <IGESAppli_FiniteElement.hxx>
#define TCollection_Array1 IGESAppli_Array1OfFiniteElement
#define TCollection_Array1_hxx <IGESAppli_Array1OfFiniteElement.hxx>

#include <TCollection_Array1.lxx>

#undef Array1Item
#undef Array1Item_hxx
#undef TCollection_Array1
#undef TCollection_Array1_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
