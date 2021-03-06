// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPTools_ListOfPaveBlock_HeaderFile
#define _BOPTools_ListOfPaveBlock_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Handle_BOPTools_ListNodeOfListOfPaveBlock_HeaderFile
#include <Handle_BOPTools_ListNodeOfListOfPaveBlock.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoSuchObject;
class BOPTools_ListIteratorOfListOfPaveBlock;
class BOPTools_PaveBlock;
class BOPTools_ListNodeOfListOfPaveBlock;



class BOPTools_ListOfPaveBlock  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   BOPTools_ListOfPaveBlock();
  
  Standard_EXPORT     void Assign(const BOPTools_ListOfPaveBlock& Other) ;
    void operator=(const BOPTools_ListOfPaveBlock& Other) 
{
  Assign(Other);
}
  
  Standard_EXPORT     Standard_Integer Extent() const;
  
  Standard_EXPORT     void Clear() ;
~BOPTools_ListOfPaveBlock()
{
  Clear();
}
  
        Standard_Boolean IsEmpty() const;
  
  Standard_EXPORT     void Prepend(const BOPTools_PaveBlock& I) ;
  
  Standard_EXPORT     void Prepend(const BOPTools_PaveBlock& I,BOPTools_ListIteratorOfListOfPaveBlock& theIt) ;
  
  Standard_EXPORT     void Prepend(BOPTools_ListOfPaveBlock& Other) ;
  
  Standard_EXPORT     void Append(const BOPTools_PaveBlock& I) ;
  
  Standard_EXPORT     void Append(const BOPTools_PaveBlock& I,BOPTools_ListIteratorOfListOfPaveBlock& theIt) ;
  
  Standard_EXPORT     void Append(BOPTools_ListOfPaveBlock& Other) ;
  
  Standard_EXPORT     BOPTools_PaveBlock& First() const;
  
  Standard_EXPORT     BOPTools_PaveBlock& Last() const;
  
  Standard_EXPORT     void RemoveFirst() ;
  
  Standard_EXPORT     void Remove(BOPTools_ListIteratorOfListOfPaveBlock& It) ;
  
  Standard_EXPORT     void InsertBefore(const BOPTools_PaveBlock& I,BOPTools_ListIteratorOfListOfPaveBlock& It) ;
  
  Standard_EXPORT     void InsertBefore(BOPTools_ListOfPaveBlock& Other,BOPTools_ListIteratorOfListOfPaveBlock& It) ;
  
  Standard_EXPORT     void InsertAfter(const BOPTools_PaveBlock& I,BOPTools_ListIteratorOfListOfPaveBlock& It) ;
  
  Standard_EXPORT     void InsertAfter(BOPTools_ListOfPaveBlock& Other,BOPTools_ListIteratorOfListOfPaveBlock& It) ;


friend class BOPTools_ListIteratorOfListOfPaveBlock;



protected:





private:

  
  Standard_EXPORT   BOPTools_ListOfPaveBlock(const BOPTools_ListOfPaveBlock& Other);


Standard_Address myFirst;
Standard_Address myLast;


};

#define Item BOPTools_PaveBlock
#define Item_hxx <BOPTools_PaveBlock.hxx>
#define TCollection_ListNode BOPTools_ListNodeOfListOfPaveBlock
#define TCollection_ListNode_hxx <BOPTools_ListNodeOfListOfPaveBlock.hxx>
#define TCollection_ListIterator BOPTools_ListIteratorOfListOfPaveBlock
#define TCollection_ListIterator_hxx <BOPTools_ListIteratorOfListOfPaveBlock.hxx>
#define Handle_TCollection_ListNode Handle_BOPTools_ListNodeOfListOfPaveBlock
#define TCollection_ListNode_Type_() BOPTools_ListNodeOfListOfPaveBlock_Type_()
#define TCollection_List BOPTools_ListOfPaveBlock
#define TCollection_List_hxx <BOPTools_ListOfPaveBlock.hxx>

#include <TCollection_List.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_ListNode
#undef TCollection_ListNode_hxx
#undef TCollection_ListIterator
#undef TCollection_ListIterator_hxx
#undef Handle_TCollection_ListNode
#undef TCollection_ListNode_Type_
#undef TCollection_List
#undef TCollection_List_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
