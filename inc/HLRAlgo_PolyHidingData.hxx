// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _HLRAlgo_PolyHidingData_HeaderFile
#define _HLRAlgo_PolyHidingData_HeaderFile

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
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif



class HLRAlgo_PolyHidingData  {
public:

  DEFINE_STANDARD_ALLOC

  
      HLRAlgo_PolyHidingData();
  
        void Set(const Standard_Integer Index,const Standard_Integer Minim,const Standard_Integer Maxim,const Standard_Real A,const Standard_Real B,const Standard_Real C,const Standard_Real D) ;
  
        Standard_Address IndexAndMinMax() const;
  
        Standard_Address Plan() const;





protected:





private:



Standard_Integer myMinMax[3];
Standard_Real myPlan[4];


};


#include <HLRAlgo_PolyHidingData.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
