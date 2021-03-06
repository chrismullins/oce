// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepFilletAPI_MakeFillet2d_HeaderFile
#define _BRepFilletAPI_MakeFillet2d_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _ChFi2d_Builder_HeaderFile
#include <ChFi2d_Builder.hxx>
#endif
#ifndef _BRepBuilderAPI_MakeShape_HeaderFile
#include <BRepBuilderAPI_MakeShape.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _ChFi2d_ConstructionError_HeaderFile
#include <ChFi2d_ConstructionError.hxx>
#endif
class TopoDS_Face;
class TopoDS_Edge;
class TopoDS_Vertex;
class TopTools_SequenceOfShape;
class TopTools_ListOfShape;
class TopoDS_Shape;


//! Describes functions to build fillets and chamfers on the <br>
//! vertices of a planar face. <br>
//! Fillets and Chamfers on the Vertices of a Planar Face <br>
//! A MakeFillet2d object provides a framework for: <br>
//! - initializing the construction algorithm with a given face, <br>
//! - acquiring the data characterizing the fillets and chamfers, <br>
//! -   building the fillets and chamfers, and constructing the <br>
//!   resulting shape, and <br>
//! -   consulting the result. <br>
//! Warning <br>
//! Only segments of straight lines and arcs of circles are <br>
//! treated. BSplines are not processed. <br>
class BRepFilletAPI_MakeFillet2d  : public BRepBuilderAPI_MakeShape {
public:

  DEFINE_STANDARD_ALLOC

  //! Initializes an empty algorithm for computing fillets and <br>
//!   chamfers. The face on which the fillets and <br>
//!   chamfers are built is defined using the Init function. <br>
//! The vertices on which fillets or chamfers are built are <br>
//! defined using the AddFillet or AddChamfer function. <br>
//! Warning <br>
//! The status of the initialization, as given by the Status <br>
//! function, can be one of the following: <br>
//! -   ChFi2d_Ready if the initialization is correct, <br>
//! -   ChFi2d_NotPlanar if F is not planar, <br>
//! -   ChFi2d_NoFace if F is a null face. <br>
  Standard_EXPORT   BRepFilletAPI_MakeFillet2d();
  //! Initializes an algorithm for computing fillets and chamfers on the face F. <br>
//! The vertices on which fillets or chamfers are built are <br>
//! defined using the AddFillet or AddChamfer function. <br>
//! Warning <br>
//! The status of the initialization, as given by the Status <br>
//! function, can be one of the following: <br>
//! -   ChFi2d_Ready if the initialization is correct, <br>
//! -   ChFi2d_NotPlanar if F is not planar, <br>
//! -   ChFi2d_NoFace if F is a null face. <br>
  Standard_EXPORT   BRepFilletAPI_MakeFillet2d(const TopoDS_Face& F);
  //! Initializes this algorithm for constructing fillets or <br>
//! chamfers with the face F. <br>
//! Warning <br>
//! The status of the initialization, as given by the Status <br>
//! function, can be one of the following: <br>
//! -   ChFi2d_Ready if the initialization is correct, <br>
//! -   ChFi2d_NotPlanar if F is not planar, <br>
//! -   ChFi2d_NoFace if F is a null face. <br>
  Standard_EXPORT     void Init(const TopoDS_Face& F) ;
  //! This initialize  method allow  to init the builder <br>
//!          from a  face <RefFace> and  another face <ModFace> <br>
//!          which derive from  <RefFace>.  This  is usefull to <br>
//!          modify a fillet or   a chamfer already created  on <br>
//!          <ModFace> . <br>
  Standard_EXPORT     void Init(const TopoDS_Face& RefFace,const TopoDS_Face& ModFace) ;
  //! Adds a fillet of radius Radius between the two edges <br>
//! adjacent to the vertex V on the face modified by this <br>
//! algorithm. The two edges do not need to be rectilinear. <br>
//! This function returns the fillet and builds the resulting face. <br>
//! Warning <br>
//! The status of the construction, as given by the Status <br>
//! function, can be one of the following: <br>
//! - ChFi2d_IsDone if the fillet is built, <br>
//! - ChFi2d_ConnexionError if V does not belong to the initial face, <br>
//! -   ChFi2d_ComputationError if Radius is too large <br>
//!   to build a fillet between the two adjacent edges, <br>
//! -   ChFi2d_NotAuthorized <br>
//! -   if one of the two edges connected to V is a fillet or chamfer, or <br>
//! -   if a curve other than a straight line or an arc of a <br>
//!    circle is used as E, E1 or E2. <br>
//! Do not use the returned fillet if the status of the construction is not ChFi2d_IsDone. <br>
//! Exceptions <br>
//! Standard_NegativeValue if Radius is less than or equal to zero. <br>
  Standard_EXPORT     TopoDS_Edge AddFillet(const TopoDS_Vertex& V,const Standard_Real Radius) ;
  //! Assigns the radius Radius to the fillet Fillet already <br>
//! built on the face modified by this algorithm. <br>
//! This function returns the new fillet and modifies the existing face. <br>
//! Warning <br>
//! The status of the construction, as given by the Status <br>
//! function, can be one of the following: <br>
//! -   ChFi2d_IsDone if the new fillet is built, <br>
//! -   ChFi2d_ConnexionError if Fillet does not <br>
//!   belong to the existing face, <br>
//! -   ChFi2d_ComputationError if Radius is too <br>
//!  large to build a fillet between the two adjacent edges. <br>
//!   Do not use the returned fillet if the status of the <br>
//! construction is not ChFi2d_IsDone. <br>
//! Exceptions <br>
//! Standard_NegativeValue if Radius is less than or equal to zero. <br>
  Standard_EXPORT     TopoDS_Edge ModifyFillet(const TopoDS_Edge& Fillet,const Standard_Real Radius) ;
  //! Removes the fillet Fillet already built on the face <br>
//! modified by this algorithm. <br>
//! This function returns the vertex connecting the two <br>
//! adjacent edges of Fillet and modifies the existing face. <br>
//! Warning <br>
//! -   The returned vertex is only valid if the Status <br>
//!   function returns ChFi2d_IsDone. <br>
//! -   A null vertex is returned if the edge Fillet does not <br>
//!   belong to the initial face. <br>
  Standard_EXPORT     TopoDS_Vertex RemoveFillet(const TopoDS_Edge& Fillet) ;
  //! Adds a chamfer on the face modified by this algorithm <br>
//!    between the two adjacent edges E1 and E2, where <br>
//!   the extremities of the chamfer are on E1 and E2 at <br>
//!   distances D1 and D2 respectively <br>
//!    In cases where the edges are not rectilinear, distances <br>
//! are measured using the curvilinear abscissa of the <br>
//! edges and the angle is measured with respect to the <br>
//! tangent at the corresponding point. <br>
//! The angle Ang is given in radians. <br>
//! This function returns the chamfer and builds the resulting face. <br>
  Standard_EXPORT     TopoDS_Edge AddChamfer(const TopoDS_Edge& E1,const TopoDS_Edge& E2,const Standard_Real D1,const Standard_Real D2) ;
  //! Adds a chamfer on the face modified by this algorithm <br>
//!   between the two edges connected by the vertex V, <br>
//!   where E is one of the two edges. The chamfer makes <br>
//!   an angle Ang with E and one of its extremities is on <br>
//!   E at distance D from V. <br>
//!    In cases where the edges are not rectilinear, distances <br>
//! are measured using the curvilinear abscissa of the <br>
//! edges and the angle is measured with respect to the <br>
//! tangent at the corresponding point. <br>
//! The angle Ang is given in radians. <br>
//! This function returns the chamfer and builds the resulting face. <br>
//! Warning <br>
//! The status of the construction, as given by the Status function, can <br>
//! be one of the following: <br>
//! -          ChFi2d_IsDone if the chamfer is built, <br>
//! -  ChFi2d_ParametersError if D1, D2, D or Ang is less than or equal to zero, <br>
//! -          ChFi2d_ConnexionError if: <br>
//! - the edge E, E1 or E2 does not belong to the initial face, or <br>
//! -  the edges E1 and E2 are not adjacent, or <br>
//! -  the vertex V is not one of the limit points of the edge E, <br>
//! -          ChFi2d_ComputationError if the parameters of the chamfer <br>
//!   are too large to build a chamfer between the two adjacent edges, <br>
//! -          ChFi2d_NotAuthorized if: <br>
//! - the edge E1, E2 or one of the two edges connected to V is a fillet or chamfer, or <br>
//! - a curve other than a straight line or an arc of a circle is used as E, E1 or E2. <br>
//! Do not use the returned chamfer if <br>
//! the status of the construction is not ChFi2d_IsDone. <br>
  Standard_EXPORT     TopoDS_Edge AddChamfer(const TopoDS_Edge& E,const TopoDS_Vertex& V,const Standard_Real D,const Standard_Real Ang) ;
  //! Modifies the chamfer Chamfer on the face modified <br>
//! by this algorithm, where: <br>
//!   E1 and E2 are the two adjacent edges on which <br>
//!   Chamfer is already built; the extremities of the new <br>
//!   chamfer are on E1 and E2 at distances D1 and D2 respectively. <br>
  Standard_EXPORT     TopoDS_Edge ModifyChamfer(const TopoDS_Edge& Chamfer,const TopoDS_Edge& E1,const TopoDS_Edge& E2,const Standard_Real D1,const Standard_Real D2) ;
  //! Modifies the chamfer Chamfer on the face modified <br>
//! by this algorithm, where: <br>
//!   E is one of the two adjacent edges on which <br>
//!   Chamfer is already built; the new chamfer makes <br>
//!   an angle Ang with E and one of its extremities is <br>
//! on E at distance D from the vertex on which the chamfer is built. <br>
//!   In cases where the edges are not rectilinear, the <br>
//! distances are measured using the curvilinear abscissa <br>
//! of the edges and the angle is measured with respect <br>
//! to the tangent at the corresponding point. <br>
//! The angle Ang is given in radians. <br>
//! This function returns the new chamfer and modifies the existing face. <br>
//! Warning <br>
//! The status of the construction, as given by the Status <br>
//! function, can be one of the following: <br>
//! -   ChFi2d_IsDone if the chamfer is built, <br>
//! -   ChFi2d_ParametersError if D1, D2, D or Ang is less than or equal to zero, <br>
//! -   ChFi2d_ConnexionError if: <br>
//!   -   the edge E, E1, E2 or Chamfer does not belong <br>
//!    to the existing face, or <br>
//!   -   the edges E1 and E2 are not adjacent, <br>
//! -   ChFi2d_ComputationError if the parameters of <br>
//!   the chamfer are too large to build a chamfer <br>
//!   between the two adjacent edges, <br>
//! -   ChFi2d_NotAuthorized if E1 or E2 is a fillet or chamfer. <br>
//! Do not use the returned chamfer if the status of the <br>
//! construction is not ChFi2d_IsDone. <br>
  Standard_EXPORT     TopoDS_Edge ModifyChamfer(const TopoDS_Edge& Chamfer,const TopoDS_Edge& E,const Standard_Real D,const Standard_Real Ang) ;
  //! Removes the chamfer Chamfer already built on the face <br>
//! modified by this algorithm. <br>
//! This function returns the vertex connecting the two <br>
//! adjacent edges of Chamfer and modifies the existing face. <br>
//! Warning <br>
//! -   The returned vertex is only valid if the Status <br>
//!   function returns ChFi2d_IsDone. <br>
//! -   A null vertex is returned if the edge Chamfer does <br>
//!   not belong to the initial face. <br>
  Standard_EXPORT     TopoDS_Vertex RemoveChamfer(const TopoDS_Edge& Chamfer) ;
  //!    Returns true if the edge E on the face modified by this <br>
//! algorithm is chamfered or filleted. <br>
//! Warning <br>
//! Returns false if E does not belong to the face modified by this algorithm. <br>
        Standard_Boolean IsModified(const TopoDS_Edge& E) const;
  //! Returns the table of fillets on the face modified by this algorithm. <br>
       const TopTools_SequenceOfShape& FilletEdges() const;
  //! Returns the number of fillets on the face modified by this algorithm. <br>
        Standard_Integer NbFillet() const;
  //! Returns the table of chamfers on the face modified by this algorithm. <br>
       const TopTools_SequenceOfShape& ChamferEdges() const;
  //! Returns the number of chamfers on the face modified by this algorithm. <br>
        Standard_Integer NbChamfer() const;
  //! Returns the list  of shapes modified from the shape <br>
//!          <S>. <br>
  Standard_EXPORT   virtual const TopTools_ListOfShape& Modified(const TopoDS_Shape& S) ;
  //! returns the number of new curves <br>
//!          after the shape creation. <br>
  Standard_EXPORT     Standard_Integer NbCurves() const;
  //! Return the Edges created for curve I. <br>
  Standard_EXPORT    const TopTools_ListOfShape& NewEdges(const Standard_Integer I) ;
  
        Standard_Boolean HasDescendant(const TopoDS_Edge& E) const;
  //! Returns the chamfered or filleted edge built from the <br>
//! edge E on the face modified by this algorithm. If E has <br>
//! not been modified, this function returns E. <br>
//! Exceptions <br>
//! Standard_NoSuchObject if the edge E does not <br>
//! belong to the initial face. <br>
       const TopoDS_Edge& DescendantEdge(const TopoDS_Edge& E) const;
  //! Returns the basis edge on the face modified by this <br>
//! algorithm from which the chamfered or filleted edge E is <br>
//! built. If E has not been modified, this function returns E. <br>
//! Warning <br>
//! E is returned if it does not belong to the initial face. <br>
  Standard_EXPORT    const TopoDS_Edge& BasisEdge(const TopoDS_Edge& E) const;
  
        ChFi2d_ConstructionError Status() const;
  //! Update the result and set the Done flag <br>
  Standard_EXPORT   virtual  void Build() ;





protected:





private:



ChFi2d_Builder myMakeChFi2d;


};


#include <BRepFilletAPI_MakeFillet2d.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
