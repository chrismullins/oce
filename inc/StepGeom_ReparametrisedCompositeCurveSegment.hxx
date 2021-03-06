// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepGeom_ReparametrisedCompositeCurveSegment_HeaderFile
#define _StepGeom_ReparametrisedCompositeCurveSegment_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepGeom_ReparametrisedCompositeCurveSegment_HeaderFile
#include <Handle_StepGeom_ReparametrisedCompositeCurveSegment.hxx>
#endif

#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _StepGeom_CompositeCurveSegment_HeaderFile
#include <StepGeom_CompositeCurveSegment.hxx>
#endif
#ifndef _StepGeom_TransitionCode_HeaderFile
#include <StepGeom_TransitionCode.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_StepGeom_Curve_HeaderFile
#include <Handle_StepGeom_Curve.hxx>
#endif
class StepGeom_Curve;



class StepGeom_ReparametrisedCompositeCurveSegment : public StepGeom_CompositeCurveSegment {

public:

  //! Returns a ReparametrisedCompositeCurveSegment <br>
  Standard_EXPORT   StepGeom_ReparametrisedCompositeCurveSegment();
  
  Standard_EXPORT   virtual  void Init(const StepGeom_TransitionCode aTransition,const Standard_Boolean aSameSense,const Handle(StepGeom_Curve)& aParentCurve) ;
  
  Standard_EXPORT   virtual  void Init(const StepGeom_TransitionCode aTransition,const Standard_Boolean aSameSense,const Handle(StepGeom_Curve)& aParentCurve,const Standard_Real aParamLength) ;
  
  Standard_EXPORT     void SetParamLength(const Standard_Real aParamLength) ;
  
  Standard_EXPORT     Standard_Real ParamLength() const;




  DEFINE_STANDARD_RTTI(StepGeom_ReparametrisedCompositeCurveSegment)

protected:




private: 


Standard_Real paramLength;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
