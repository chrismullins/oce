// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepOffsetAPI_MakePipe_HeaderFile
#define _BRepOffsetAPI_MakePipe_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BRepFill_Pipe_HeaderFile
#include <BRepFill_Pipe.hxx>
#endif
#ifndef _BRepPrimAPI_MakeSweep_HeaderFile
#include <BRepPrimAPI_MakeSweep.hxx>
#endif
class TopoDS_Wire;
class TopoDS_Shape;
class BRepFill_Pipe;


//! Describes functions to build pipes. <br>
//! A pipe is built a basis shape (called the profile) along <br>
//! a wire (called the spine) by sweeping. <br>
//! The profile must not contain solids. <br>
//! A MakePipe object provides a framework for: <br>
//! - defining the construction of a pipe, <br>
//! - implementing the construction algorithm, and <br>
//! - consulting the result. <br>
//! Warning <br>
//! The MakePipe class implements pipe constructions <br>
//! with G1 continuous spines only. <br>
class BRepOffsetAPI_MakePipe  : public BRepPrimAPI_MakeSweep {
public:

  DEFINE_STANDARD_ALLOC

  //! Constructs a pipe by sweeping the shape Profile along <br>
//! the wire Spine.The angle made by the spine with the profile is <br>
//! maintained along the length of the pipe. <br>
//! Warning <br>
//! Spine must be G1 continuous; that is, on the connection <br>
//! vertex of two edges of the wire, the tangent vectors on <br>
//! the left and on the right must have the same direction, <br>
//! though not necessarily the same magnitude. <br>
//! Exceptions <br>
//! Standard_DomainError if the profile is a solid or a <br>
//! composite solid. <br>
  Standard_EXPORT   BRepOffsetAPI_MakePipe(const TopoDS_Wire& Spine,const TopoDS_Shape& Profile);
  
  Standard_EXPORT    const BRepFill_Pipe& Pipe() const;
  //! Builds the resulting shape (redefined from MakeShape). <br>
  Standard_EXPORT   virtual  void Build() ;
  //! Returns the  TopoDS  Shape of the bottom of the prism. <br>
  Standard_EXPORT     TopoDS_Shape FirstShape() ;
  //! Returns the TopoDS Shape of the top of the prism. <br>
  Standard_EXPORT     TopoDS_Shape LastShape() ;
  
  Standard_EXPORT     TopoDS_Shape Generated(const TopoDS_Shape& SSpine,const TopoDS_Shape& SProfile) ;





protected:





private:



BRepFill_Pipe myPipe;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
