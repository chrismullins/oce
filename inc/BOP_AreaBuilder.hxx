// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOP_AreaBuilder_HeaderFile
#define _BOP_AreaBuilder_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BOP_ListOfListOfLoop_HeaderFile
#include <BOP_ListOfListOfLoop.hxx>
#endif
#ifndef _BOP_ListIteratorOfListOfListOfLoop_HeaderFile
#include <BOP_ListIteratorOfListOfListOfLoop.hxx>
#endif
#ifndef _BOP_ListIteratorOfListOfLoop_HeaderFile
#include <BOP_ListIteratorOfListOfLoop.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _TopAbs_State_HeaderFile
#include <TopAbs_State.hxx>
#endif
#ifndef _Handle_BOP_Loop_HeaderFile
#include <Handle_BOP_Loop.hxx>
#endif
#ifndef _BOP_LoopEnum_HeaderFile
#include <BOP_LoopEnum.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class BOP_LoopSet;
class BOP_LoopClassifier;
class BOP_Loop;
class BOP_ListOfLoop;
class BOP_ListIteratorOfListOfLoop;



class BOP_AreaBuilder  {
public:

  DEFINE_STANDARD_ALLOC

  
//! Empty  Constructor <br>
  Standard_EXPORT   BOP_AreaBuilder();
  
//! Creates the objectr to build the areas on <br>
//! the shapes described by <LS> using the classifier <LC>. <br>
  Standard_EXPORT   BOP_AreaBuilder(BOP_LoopSet& LS,BOP_LoopClassifier& LC,const Standard_Boolean ForceClass = Standard_False);
  
//! Destructor <br>
  Standard_EXPORT   virtual  void Delete() ;
Standard_EXPORT virtual ~BOP_AreaBuilder(){Delete() ; }
  
//! Sets a AreaBuilder to find the areas on <br>
//! the shapes described by <LS> using the classifier <LC>. <br>
  Standard_EXPORT   virtual  void InitAreaBuilder(BOP_LoopSet& LS,BOP_LoopClassifier& LC,const Standard_Boolean ForceClass = Standard_False) ;
  
//! Initialize iteration on areas. <br>
  Standard_EXPORT     Standard_Integer InitArea() ;
  
  Standard_EXPORT     Standard_Boolean MoreArea() const;
  
  Standard_EXPORT     void NextArea() ;
  
//! Initialize iteration on loops of current Area. <br>
  Standard_EXPORT     Standard_Integer InitLoop() ;
  
  Standard_EXPORT     Standard_Boolean MoreLoop() const;
  
  Standard_EXPORT     void NextLoop() ;
  
//! Returns the current Loop in the current area. <br>
  Standard_EXPORT    const Handle_BOP_Loop& Loop() const;
  
//! Internal <br>
  Standard_EXPORT   virtual  void ADD_Loop_TO_LISTOFLoop(const Handle(BOP_Loop)& L,BOP_ListOfLoop& LOL) const;
  
//! Internal <br>
  Standard_EXPORT   virtual  void REM_Loop_FROM_LISTOFLoop(BOP_ListIteratorOfListOfLoop& ITLOL,BOP_ListOfLoop& LOL) const;
  
//! Internal <br>
  Standard_EXPORT   virtual  void ADD_LISTOFLoop_TO_LISTOFLoop(BOP_ListOfLoop& LOL1,BOP_ListOfLoop& LOL2) const;





protected:

  
//! Compare position of the Loop <L> with the Area <LOL> <br>
//! using the Loop Classifier <LC>. <br>
//!       According to <aWhat>, Loops of <LOL> are selected or not <br>
//!       during <LOL> exploration. <br>
  Standard_EXPORT     TopAbs_State CompareLoopWithListOfLoop(BOP_LoopClassifier& LC,const Handle(BOP_Loop)& L,const BOP_ListOfLoop& LOL,const BOP_LoopEnum aWhat) const;
  
//! Internal <br>
  Standard_EXPORT     void Atomize(TopAbs_State& state,const TopAbs_State newstate) const;


BOP_ListOfListOfLoop myArea;
BOP_ListIteratorOfListOfListOfLoop myAreaIterator;
BOP_ListIteratorOfListOfLoop myLoopIterator;
Standard_Boolean myUNKNOWNRaise;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
