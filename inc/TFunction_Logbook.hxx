// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TFunction_Logbook_HeaderFile
#define _TFunction_Logbook_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TDF_LabelMap_HeaderFile
#include <TDF_LabelMap.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
class TDF_Label;
class TDF_LabelMap;


//! This class contains information which is written and <br>
//!          read during the solving process. Information is divided <br>
//!          in three groups. <br>
//! <br>
//!          * Touched Labels  (modified by the end user), <br>
//!          * Impacted Labels (modified during execution of the function), <br>
//!          * Valid Labels    (within the valid label scope). <br>
class TFunction_Logbook  {
public:

  DEFINE_STANDARD_ALLOC

  //! next methods are solving declaration <br>
//!          =================================== <br>
  Standard_EXPORT   TFunction_Logbook();
  //! Clears this logbook to its default, empty state. <br>
  Standard_EXPORT     void Clear() ;
  
  Standard_EXPORT     Standard_Boolean IsEmpty() const;
  //! Sets the label L as a touched label in this logbook. <br>
//! In other words, L is understood to have been modified by the end user. <br>
        void SetTouched(const TDF_Label& L) ;
  //! Sets the label L as an impacted label in this logbook. <br>
//! This method is called by execution of the function driver. <br>
  Standard_EXPORT     void SetImpacted(const TDF_Label& L,const Standard_Boolean WithChildren = Standard_False) ;
  //! Sets the label L as a valid label in this logbook. <br>
  Standard_EXPORT     void SetValid(const TDF_Label& L,const Standard_Boolean WithChildren = Standard_False) ;
  
        TDF_LabelMap& ChangeValid() ;
  //! Returns True if the label L is touched  or impacted. This method <br>
//!          is called by <TFunction_FunctionDriver::MustExecute>. <br>
//!          If <WithChildren> is set to true, the method checks <br>
//!          all the sublabels of <L> too. <br>//! next method to consult solving result <br>
//!          ===================================== <br>
  Standard_EXPORT     Standard_Boolean IsModified(const TDF_Label& L,const Standard_Boolean WithChildren = Standard_False) const;
  
//! Returns the map of touched labels in this logbook. <br>
//! A touched label is the one modified by the end user. <br>
       const TDF_LabelMap& GetTouched() const;
  
//! Returns the map of impacted labels contained in this logbook. <br>
       const TDF_LabelMap& GetImpacted() const;
  //! Returns the map of valid labels in this logbook. <br>
       const TDF_LabelMap& GetValid() const;
  //! Sets if the execution failed <br>
        void Done(const Standard_Boolean status) ;
  
        Standard_Boolean IsDone() const;
  
  Standard_EXPORT     Standard_OStream& Dump(Standard_OStream& stream) const;





protected:





private:



TDF_LabelMap myTouched;
TDF_LabelMap myImpacted;
TDF_LabelMap myValid;
Standard_Boolean isDone;


};


#include <TFunction_Logbook.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
