// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _HLRTest_OutLiner_HeaderFile
#define _HLRTest_OutLiner_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_HLRTest_OutLiner_HeaderFile
#include <Handle_HLRTest_OutLiner.hxx>
#endif

#ifndef _Handle_HLRTopoBRep_OutLiner_HeaderFile
#include <Handle_HLRTopoBRep_OutLiner.hxx>
#endif
#ifndef _Draw_Drawable3D_HeaderFile
#include <Draw_Drawable3D.hxx>
#endif
#ifndef _Handle_Draw_Drawable3D_HeaderFile
#include <Handle_Draw_Drawable3D.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
class HLRTopoBRep_OutLiner;
class TopoDS_Shape;
class Draw_Display;
class Draw_Drawable3D;
class Draw_Interpretor;



class HLRTest_OutLiner : public Draw_Drawable3D {

public:

  
  Standard_EXPORT   HLRTest_OutLiner(const TopoDS_Shape& S);
  
        Handle_HLRTopoBRep_OutLiner OutLiner() const;
  //! Does nothhing, <br>
  Standard_EXPORT     void DrawOn(Draw_Display& dis) const;
  //! For variable copy. <br>
  Standard_EXPORT   virtual  Handle_Draw_Drawable3D Copy() const;
  //! For variable dump. <br>
  Standard_EXPORT   virtual  void Dump(Standard_OStream& S) const;
  //! For variable whatis command. Set  as a result  the <br>
//!          type of the variable. <br>
  Standard_EXPORT   virtual  void Whatis(Draw_Interpretor& I) const;




  DEFINE_STANDARD_RTTI(HLRTest_OutLiner)

protected:




private: 


Handle_HLRTopoBRep_OutLiner myOutLiner;


};


#include <HLRTest_OutLiner.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
