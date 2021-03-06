// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPTools_PaveFiller_HeaderFile
#define _BOPTools_PaveFiller_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BOPTools_PInterferencePool_HeaderFile
#include <BOPTools_PInterferencePool.hxx>
#endif
#ifndef _BooleanOperations_PShapesDataStructure_HeaderFile
#include <BooleanOperations_PShapesDataStructure.hxx>
#endif
#ifndef _BOPTools_PavePool_HeaderFile
#include <BOPTools_PavePool.hxx>
#endif
#ifndef _BOPTools_CommonBlockPool_HeaderFile
#include <BOPTools_CommonBlockPool.hxx>
#endif
#ifndef _BOPTools_SplitShapesPool_HeaderFile
#include <BOPTools_SplitShapesPool.hxx>
#endif
#ifndef _BOPTools_SSIntersectionAttribute_HeaderFile
#include <BOPTools_SSIntersectionAttribute.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BOPTools_IteratorOfCoupleOfShape_HeaderFile
#include <BOPTools_IteratorOfCoupleOfShape.hxx>
#endif
#ifndef _Handle_IntTools_Context_HeaderFile
#include <Handle_IntTools_Context.hxx>
#endif
#ifndef _TopAbs_ShapeEnum_HeaderFile
#include <TopAbs_ShapeEnum.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class IntTools_Context;
class BOPTools_InterferencePool;
class BOPTools_SSIntersectionAttribute;
class TColStd_SetOfInteger;
class BOPTools_PavePool;
class BOPTools_CommonBlockPool;
class BOPTools_SplitShapesPool;
class BOPTools_IteratorOfCoupleOfShape;
class BOPTools_Pave;
class IntTools_ShrunkRange;
class BOPTools_PaveBlock;
class TColStd_ListOfInteger;
class BOPTools_ListOfPaveBlock;
class BOPTools_PaveSet;
class BOPTools_Curve;
class BOPTools_SSInterference;
class gp_Pnt;
class TopoDS_Vertex;
class TColStd_IndexedMapOfInteger;


//!  The algorithm that provides <br>
//!  1. creation of the data structure (DS) <br>
//!  2. creation of the interferences' pool <br>
//!  3. invocation of Perform() to fill the DS <br>
//! <br>
class BOPTools_PaveFiller  {
public:

  DEFINE_STANDARD_ALLOC

  
//! Empty Contructor <br>
  Standard_EXPORT   BOPTools_PaveFiller();
  
//! Constructor <br>
  Standard_EXPORT   BOPTools_PaveFiller(const BOPTools_InterferencePool& aIP);
  
//! Constructor <br>
  Standard_EXPORT   BOPTools_PaveFiller(const BOPTools_InterferencePool& theIP,const BOPTools_SSIntersectionAttribute& theSectionAttribute);
  
//! Destructor <br>
  Standard_EXPORT   virtual  void Destroy() ;
Standard_EXPORT virtual ~BOPTools_PaveFiller(){Destroy();}
  
//! Fills the DS <br>
  Standard_EXPORT   virtual  void Perform() ;
  
  Standard_EXPORT   virtual  void PartialPerform(const TColStd_SetOfInteger& anObjSubSet,const TColStd_SetOfInteger& aToolSubSet) ;
  
  Standard_EXPORT   virtual  void ToCompletePerform() ;
  
//! Sets the intersecton context <br>
//! <br>
  Standard_EXPORT     void SetContext(const Handle(IntTools_Context)& aContext) ;
  
//! Selector <br>
//! Selector <br>
  Standard_EXPORT    const Handle_IntTools_Context& Context() const;
  
//! Selector <br>
  Standard_EXPORT     void SetInterferencePool(const BOPTools_InterferencePool& aPool) ;
  
//! Selector <br>
  Standard_EXPORT     Standard_Boolean IsDone() const;
  
//! Selector <br>
  Standard_EXPORT    const BOPTools_PavePool& PavePool() const;
  
//! Selector <br>
  Standard_EXPORT     BOPTools_PavePool& ChangePavePool() ;
  
//! Selector <br>
  Standard_EXPORT    const BOPTools_CommonBlockPool& CommonBlockPool() const;
  
//! Selector <br>
  Standard_EXPORT     BOPTools_CommonBlockPool& ChangeCommonBlockPool() ;
  
//! Selector <br>
  Standard_EXPORT    const BOPTools_SplitShapesPool& SplitShapesPool() const;
  
//! Selector <br>
  Standard_EXPORT     BOPTools_SplitShapesPool& ChangeSplitShapesPool() ;
  
//! Selector <br>
  Standard_EXPORT     BooleanOperations_PShapesDataStructure DS() ;
  
//! Selector <br>
  Standard_EXPORT     BOPTools_PInterferencePool InterfPool() ;
  
//! Selector <br>
  Standard_EXPORT    const BOPTools_IteratorOfCoupleOfShape& IteratorOfCoupleOfShape() const;
  
//! Selector <br>
  Standard_EXPORT    const BOPTools_SSIntersectionAttribute& SectionAttribute() const;
  
//! Selector <br>
  Standard_EXPORT     void SetSectionAttribute(const BOPTools_SSIntersectionAttribute& anAtt) ;
  
//! For the face <nF1> get all splits that are IN-2D <br>
//! to  the face <nF2>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsInFace(const Standard_Integer aBid,const Standard_Integer nF1,const Standard_Integer nF2,TColStd_ListOfInteger& aLs) ;
  
//! For the edge <nE1> get all splits that are IN-2D <br>
//! to  the face <nF1>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsInFace(const Standard_Integer nE1,const Standard_Integer nF2,TColStd_ListOfInteger& aLs) ;
  
//! For the edge <nE1> get all splits that are ON-3D <br>
//! to  the edge <nE2>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsOnEdge(const Standard_Integer nE1,const Standard_Integer nE2,TColStd_ListOfInteger& aLs) ;
  
//! For the edge <nE1> get all splits that are ON-3D <br>
//! to  the face <nF2>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsOnFace(const Standard_Integer nE1,const Standard_Integer nF2,TColStd_ListOfInteger& aLs) ;
  
//! For the face <nF1> get all splits that are ON-3D <br>
//! to  the face <nF2>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsOnFace(const Standard_Integer aBid,const Standard_Integer nF1,const Standard_Integer nF2,TColStd_ListOfInteger& aLs) ;
  
//! For the face <nF1> get all PaveBlocks that are IN-2D <br>
//! to  the face <nF2>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsInFace(const Standard_Integer aBid,const Standard_Integer nF1,const Standard_Integer nF2,BOPTools_ListOfPaveBlock& aLs) ;
  
//! For the edge <nE1> get all PaveBlocks that are IN-2D <br>
//! to  the face <nF1>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsInFace(const Standard_Integer nE1,const Standard_Integer nF2,BOPTools_ListOfPaveBlock& aLs) ;
  
//! For the edge <nE1> get all PaveBlocks that are ON-3D <br>
//! to  the edge <nE2>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsOnEdge(const Standard_Integer nE1,const Standard_Integer nE2,BOPTools_ListOfPaveBlock& aLs) ;
  
//! For the edge <nE1> get all PaveBlocks that are ON-3D <br>
//! to  the face <nF2>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsOnFace(const Standard_Integer nE1,const Standard_Integer nF2,BOPTools_ListOfPaveBlock& aLs) ;
  
//! For the face <nF1> get all PaveBlocks that are ON-3D <br>
//! to  the face <nF2>; The result is in <aLs> <br>
//! Returns 0 if OK; <br>
  Standard_EXPORT     Standard_Integer SplitsOnFace(const Standard_Integer aBid,const Standard_Integer nF1,const Standard_Integer nF2,BOPTools_ListOfPaveBlock& aLs) ;
  
//! Find  for the vertex <nV> SD-vertex (if possible) and return <br>
//! its DS-index.  Otherwise it returns 0. <br>
  Standard_EXPORT     Standard_Integer FindSDVertex(const Standard_Integer nV) const;
  
//! For couple of faces <nF1>, <nF2> prepare set of all paves <br>
//! of all edges <aPaveSet> <br>
  Standard_EXPORT     void PrepareSetForFace(const Standard_Integer nF1,const Standard_Integer nF2,BOPTools_PaveSet& aPaveSet) ;





protected:

  
//! Computes Vertex/Vertex interferences <br>
  Standard_EXPORT   virtual  void PerformVV() ;
  
//! Computes Vertex/Edge interferences <br>
  Standard_EXPORT   virtual  void PerformVE() ;
  
//! Computes Vertex/Face interferences <br>
  Standard_EXPORT   virtual  void PerformVF() ;
  
//! Computes Edge/Edge interferences <br>
  Standard_EXPORT   virtual  void PerformEE() ;
  
//! Computes Edge/Face interferences <br>
  Standard_EXPORT   virtual  void PerformEF() ;
  
//! Computes Face/Face interferences <br>
  Standard_EXPORT   virtual  void PerformFF() ;
  
//! Sorts the types of shapes with DS-indices <br>
//! <anInd1> and  <anInd2> in increasing order of <br>
//! types of the shapes <br>
  Standard_EXPORT     void SortTypes(Standard_Integer& anInd1,Standard_Integer& anInd2) const;
  
  Standard_EXPORT     void PerformNewVertices() ;
  
  Standard_EXPORT     Standard_Boolean IsSuccesstorsComputed(const Standard_Integer iF1,const Standard_Integer iF2) const;
  
//! Prepare end paves for each edge <br>
  Standard_EXPORT   virtual  void PrepareEdges() ;
  
//! Prepare PaveBlocks  for  each  edge  (EE-interferences) <br>
  Standard_EXPORT   virtual  void PreparePaveBlocks(const TopAbs_ShapeEnum aType1,const TopAbs_ShapeEnum aType2) ;
  
//! Prepare PaveBlocks for given edge (EE-interferences) <br>
  Standard_EXPORT   virtual  void PreparePaveBlocks(const Standard_Integer anE) ;
  
//! Refines myPavePool taking into account new Paves obtained from EE algo <br>
  Standard_EXPORT     void RefinePavePool() ;
  
//! Makes split edges from source edges <br>
  Standard_EXPORT     void MakeSplitEdges() ;
  
//! Update Lists of PaveBlocks with info about <br>
//! indices of split edges that are Same Domain <br>
//! with other splits or faces <br>
  Standard_EXPORT     void DoSDEdges() ;
  
//! Update Shrunk  Range <aSR> for Pave <aPave> <br>
  Standard_EXPORT     void CorrectShrunkRanges(const Standard_Integer aSide,const BOPTools_Pave& aPave,IntTools_ShrunkRange& aSR) ;
  
//! Returns  the Index of Split edge for the PaveBlock <aPB> <br>
//! in  DS. <br>
//! If the PaveBlock is not found, returns 0; <br>
  Standard_EXPORT     Standard_Integer SplitIndex(const BOPTools_PaveBlock& aPB) ;
  
//! Returns  TRUE if the two PaveBlocks have vertices <br>
//! that touch each other in terms of Tolerances of <br>
//! the vertices <br>
  Standard_EXPORT     Standard_Boolean IsBlocksCoinside(const BOPTools_PaveBlock& aPB1,const BOPTools_PaveBlock& aPB2) const;
  
//! Make Pave Blocks for intersection curves <br>
  Standard_EXPORT     void MakeBlocks() ;
  
//! Make vertices that are place of intersection <br>
//! between faces <br>
  Standard_EXPORT     void MakeAloneVertices() ;
  
//! Among Paves from <aPaveSet> find ones that belong <br>
//! to intersection curve <aBCurve> with 3D-tolerance <br>
//! value <aTolR3D> <br>
  Standard_EXPORT     void PutPaveOnCurve(const BOPTools_PaveSet& aPaveSet,const Standard_Real aTolR3D,BOPTools_Curve& aBCurve) ;
  
//! Try to put Pave <aPave> on intersection curve <aBCurve> <br>
//! with 3D-tolerance value <aTolR3D> <br>
  Standard_EXPORT     void PutPaveOnCurve(const BOPTools_Pave& aPave,const Standard_Real aTolR3D,BOPTools_Curve& aBCurve) ;
  
  Standard_EXPORT     void PutPavesOnCurves() ;
  
//! For all inrefered faces make section edges from <br>
//! intersection curves and corresp.  Paves on them <br>
  Standard_EXPORT     void MakeSectionEdges() ;
  
//! Try to  put own  bounds of the curve on the curve <aBC> <br>
  Standard_EXPORT     void PutBoundPaveOnCurve(BOPTools_Curve& aBC,BOPTools_SSInterference& aFF) ;
  
//! Try to put 3D-point <aP> (parameter aT)  on the curve <aBC> <br>
  Standard_EXPORT     void PutBoundPaveOnCurve(const gp_Pnt& aP,const Standard_Real aT,BOPTools_Curve& aBC,BOPTools_SSInterference& aFF) ;
  
//! Try to  put own  bounds of the curve on the curve <aBC> <br>
//! <br>
  Standard_EXPORT     void PutBoundPaveOnCurveSpec(BOPTools_Curve& aBC,BOPTools_SSInterference& aFF) ;
  
//! Try to put 3D-point <aP> (parameter aT)  on the curve <aBC> <br>
//! <br>
  Standard_EXPORT     void PutBoundPaveOnCurveSpec(const gp_Pnt& aP,const Standard_Real aT,BOPTools_Curve& aBC,BOPTools_SSInterference& aFF) ;
  
//! Put paves on the curve <aBC> in case when <aBC> <br>
//!  is closed 3D-curve <br>
//! <br>
  Standard_EXPORT     void PutClosingPaveOnCurve(BOPTools_Curve& aBC,BOPTools_SSInterference& aFF) ;
  
//! Returns TRUE if 3D-point <aP> coinsides with some Pave <br>
//! from <aPS> (with 3D-tolerance value <aTpV>); <br>
//! In  TRUE case <aPV> will contain the Pave  . <br>
  Standard_EXPORT     Standard_Boolean FindPave(const gp_Pnt& aP,const Standard_Real aTpV,const BOPTools_PaveSet& aPS,BOPTools_Pave& aPV) ;
  
//! Returns TRUE if PaveBlock <aPB> lays on the faces <br>
//! from FF-interference <aFF> <br>
  Standard_EXPORT     Standard_Boolean CheckCoincidence(const BOPTools_PaveBlock& aPB,const BOPTools_SSInterference& aFF) ;
  
//! Returns 0 if some arbitrary intermediate point from <br>
//! PaveBlock <aPB> lays on the PaveBlock  <aPBR> <br>
//! (with 3D-tolerance value <aTol>) <br>
  Standard_EXPORT     Standard_Integer CheckIntermediatePoint(const BOPTools_PaveBlock& aPB,const BOPTools_PaveBlock& aPBR,const Standard_Real aTol) ;
  
//! Internal  usage <br>
  Standard_EXPORT     Standard_Integer CheckFacePaves(const TopoDS_Vertex& aV,const Standard_Integer nF) ;
  
//! Internal  usage <br>
  Standard_EXPORT     void StickVertices(const Standard_Integer nF1,const Standard_Integer nF2,TColStd_IndexedMapOfInteger& aMV) ;
  
//! Returns the value of expected length of array of interferences <br>
  Standard_EXPORT     Standard_Integer ExpectedPoolLength() const;
  
  Standard_EXPORT     Standard_Boolean ExtendedTolerance(const Standard_Integer nV,Standard_Real& aTolExt) ;


BOPTools_PInterferencePool myIntrPool;
BooleanOperations_PShapesDataStructure myDS;
BOPTools_PavePool myPavePool;
BOPTools_PavePool myPavePoolNew;
BOPTools_CommonBlockPool myCommonBlockPool;
BOPTools_SplitShapesPool mySplitShapesPool;
BOPTools_SSIntersectionAttribute mySectionAttribute;
Standard_Integer myNbSources;
Standard_Integer myNbEdges;
Standard_Boolean myIsDone;
BOPTools_IteratorOfCoupleOfShape myDSIt;
Handle_IntTools_Context myContext;


private:

  
  Standard_EXPORT     void RestrictCurveIn2d(const Standard_Integer nE,const Standard_Integer nF1,const Standard_Integer nF2,const Standard_Real theTolerance,BOPTools_Curve& theBC) ;
  
  Standard_EXPORT     void RecomputeCommonBlocks(const Standard_Integer nE) ;




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
