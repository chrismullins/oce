// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ChFiDS_ListNodeOfRegularities_HeaderFile
#define _ChFiDS_ListNodeOfRegularities_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_ChFiDS_ListNodeOfRegularities_HeaderFile
#include <Handle_ChFiDS_ListNodeOfRegularities.hxx>
#endif

#ifndef _ChFiDS_Regul_HeaderFile
#include <ChFiDS_Regul.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class ChFiDS_Regul;
class ChFiDS_Regularities;
class ChFiDS_ListIteratorOfRegularities;



class ChFiDS_ListNodeOfRegularities : public TCollection_MapNode {

public:

  
      ChFiDS_ListNodeOfRegularities(const ChFiDS_Regul& I,const TCollection_MapNodePtr& n);
  
        ChFiDS_Regul& Value() const;




  DEFINE_STANDARD_RTTI(ChFiDS_ListNodeOfRegularities)

protected:




private: 


ChFiDS_Regul myValue;


};

#define Item ChFiDS_Regul
#define Item_hxx <ChFiDS_Regul.hxx>
#define TCollection_ListNode ChFiDS_ListNodeOfRegularities
#define TCollection_ListNode_hxx <ChFiDS_ListNodeOfRegularities.hxx>
#define TCollection_ListIterator ChFiDS_ListIteratorOfRegularities
#define TCollection_ListIterator_hxx <ChFiDS_ListIteratorOfRegularities.hxx>
#define Handle_TCollection_ListNode Handle_ChFiDS_ListNodeOfRegularities
#define TCollection_ListNode_Type_() ChFiDS_ListNodeOfRegularities_Type_()
#define TCollection_List ChFiDS_Regularities
#define TCollection_List_hxx <ChFiDS_Regularities.hxx>

#include <TCollection_ListNode.lxx>

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
