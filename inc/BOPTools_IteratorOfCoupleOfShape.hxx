// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPTools_IteratorOfCoupleOfShape_HeaderFile
#define _BOPTools_IteratorOfCoupleOfShape_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BooleanOperations_PShapesDataStructure_HeaderFile
#include <BooleanOperations_PShapesDataStructure.hxx>
#endif
#ifndef _Handle_BOPTools_HArray2OfIntersectionStatus_HeaderFile
#include <Handle_BOPTools_HArray2OfIntersectionStatus.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TopAbs_ShapeEnum_HeaderFile
#include <TopAbs_ShapeEnum.hxx>
#endif
#ifndef _BOPTools_ListOfCoupleOfInteger_HeaderFile
#include <BOPTools_ListOfCoupleOfInteger.hxx>
#endif
#ifndef _BOPTools_ListIteratorOfListOfCoupleOfInteger_HeaderFile
#include <BOPTools_ListIteratorOfListOfCoupleOfInteger.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BOPTools_IntersectionStatus_HeaderFile
#include <BOPTools_IntersectionStatus.hxx>
#endif
class BOPTools_HArray2OfIntersectionStatus;
class Standard_NoSuchObject;
class BOPTools_ListOfCoupleOfInteger;


//! The class IteratorOfCoupleOfShape provides the iteration <br>
//!         on the couples of shapes stored in ShapesDataStructure <br>
//!         according to the given types of shapes and <br>
//!         status of their intersection. <br>
//!         The statuses are stored in 2 dimension array. <br>
class BOPTools_IteratorOfCoupleOfShape  {
public:

  DEFINE_STANDARD_ALLOC

  
//! Empty Constructor <br>
  Standard_EXPORT   BOPTools_IteratorOfCoupleOfShape();
  
//! Initializes iterator by ShapesDataStructure and <br>
//! shape types <br>
  Standard_EXPORT   BOPTools_IteratorOfCoupleOfShape(const BooleanOperations_PShapesDataStructure& PDS,const TopAbs_ShapeEnum Type1,const TopAbs_ShapeEnum Type2);
  
  Standard_EXPORT   virtual  void Destroy() ;
Standard_EXPORT virtual ~BOPTools_IteratorOfCoupleOfShape(){Destroy();}
  
//! Initializes iterator with shape types. <br>
//! The iterator uses PDS assigned in constructor or in SetDataStructure(). <br>
//! Raises the exception if myPDS is null. <br>
  Standard_EXPORT   virtual  void Initialize(const TopAbs_ShapeEnum Type1,const TopAbs_ShapeEnum Type2) ;
  
//! Initialize iterator with ShapeDataStructure. <br>
  Standard_EXPORT     void SetDataStructure(const BooleanOperations_PShapesDataStructure& PDS) ;
  
//! Returns True if there are still not <br>
//! treated couples of shapes <br>
  Standard_EXPORT   virtual  Standard_Boolean More() const;
  
//! Moves to the next couple of iteration <br>
  Standard_EXPORT   virtual  void Next() ;
  
//! Returns current couple of indices and <br>
//! flag WithSubShape which is true <br>
//! if bounding boxes of subshapes <br>
//! are intersected <br>
  Standard_EXPORT   virtual  void Current(Standard_Integer& Index1,Standard_Integer& Index2,Standard_Boolean& WithSubShape) const;
  
//! Returns a list of couples of shape indices <br>
//! according to shape types by which <br>
//! the iterator was initialized <br>
  Standard_EXPORT    const BOPTools_ListOfCoupleOfInteger& ListOfCouple() const;
  
//! Sets status to array according to Index1 and Index2 <br>
  Standard_EXPORT     void SetIntersectionStatus(const Standard_Integer Index1,const Standard_Integer Index2,const BOPTools_IntersectionStatus theStatus) ;
  
//! Returns 2 dimension array of intersection statuses <br>
  Standard_EXPORT    const Handle_BOPTools_HArray2OfIntersectionStatus& GetTableOfIntersectionStatus() const;
  
//! For internal use <br>
  Standard_EXPORT     void DumpTableOfIntersectionStatus() const;





protected:

  
  Standard_EXPORT     Standard_Boolean MoreP() const;
  
  Standard_EXPORT     void NextP() ;
  
  Standard_EXPORT     void CurrentP(Standard_Integer& Index1,Standard_Integer& Index2) const;


BooleanOperations_PShapesDataStructure myPDS;
Handle_BOPTools_HArray2OfIntersectionStatus myTableOfStatus;
Standard_Integer myCurrentIndex1;
Standard_Integer myCurrentIndex2;
TopAbs_ShapeEnum myType1;
TopAbs_ShapeEnum myType2;
Standard_Integer myFirstLowerIndex;
Standard_Integer myFirstUpperIndex;
Standard_Integer mySecondLowerIndex;
Standard_Integer mySecondUpperIndex;
BOPTools_ListOfCoupleOfInteger myListOfCouple;
BOPTools_ListIteratorOfListOfCoupleOfInteger myIterator;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
