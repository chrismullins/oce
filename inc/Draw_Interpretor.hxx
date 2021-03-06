// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Draw_Interpretor_HeaderFile
#define _Draw_Interpretor_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Draw_PInterp_HeaderFile
#include <Draw_PInterp.hxx>
#endif
#ifndef _Standard_SStream_HeaderFile
#include <Standard_SStream.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Draw_CommandFunction_HeaderFile
#include <Draw_CommandFunction.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class TCollection_AsciiString;
class TCollection_ExtendedString;


//! Provides  an  encapsulation of the TCL interpretor <br>
//!          to define Draw commands. <br>
class Draw_Interpretor  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   Draw_Interpretor();
  
  Standard_EXPORT     void Init() ;
  //! Creates a  new command  with name <Command>,  help <br>
//!          string <Help> in group <Group>. <br>
//!          <Function> implement the function. <br>
  Standard_EXPORT     void Add(const Standard_CString Command,const Standard_CString Help,const Draw_CommandFunction Function,const Standard_CString Group = "User Commands") ;
  //! Creates a  new command  with name  <Command>, help <br>
//!          string   <Help>   in   group  <Group>.  <Function> <br>
//!          implement the function. <br>
//!           <FileName> is the name of the file that contains <br>
//!           the implementation of the command <br>
  Standard_EXPORT     void Add(const Standard_CString Command,const Standard_CString Help,const Standard_CString FileName,const Draw_CommandFunction Function,const Standard_CString Group = "User Commands") ;
  //! Removes   <Command>, returns true  if success (the <br>
//!          command existed). <br>
  Standard_EXPORT     Standard_Boolean Remove(const Standard_CString Command) ;
  
  Standard_EXPORT     Standard_CString Result() const;
  //! Resets the result to empty string <br>
  Standard_EXPORT     void Reset() ;
  //! Appends to the result <br>
  Standard_EXPORT     Draw_Interpretor& Append(const Standard_CString Result) ;
    Draw_Interpretor& operator<<(const Standard_CString Result) 
{
  return Append(Result);
}
  //! Appends to the result <br>
  Standard_EXPORT     Draw_Interpretor& Append(const TCollection_AsciiString& Result) ;
    Draw_Interpretor& operator<<(const TCollection_AsciiString& Result) 
{
  return Append(Result);
}
  //! Appends to the result <br>
  Standard_EXPORT     Draw_Interpretor& Append(const TCollection_ExtendedString& Result) ;
    Draw_Interpretor& operator<<(const TCollection_ExtendedString& Result) 
{
  return Append(Result);
}
  //! Appends  to the result <br>
  Standard_EXPORT     Draw_Interpretor& Append(const Standard_Integer Result) ;
    Draw_Interpretor& operator<<(const Standard_Integer Result) 
{
  return Append(Result);
}
  //! Appends  to the result <br>
  Standard_EXPORT     Draw_Interpretor& Append(const Standard_Real Result) ;
    Draw_Interpretor& operator<<(const Standard_Real Result) 
{
  return Append(Result);
}
  //! Appends  to the result <br>
  Standard_EXPORT     Draw_Interpretor& Append(const Standard_SStream& Result) ;
    Draw_Interpretor& operator<<(const Standard_SStream& Result) 
{
  return Append(Result);
}
  //! Appends to the result the string as a list element <br>
  Standard_EXPORT     void AppendElement(const Standard_CString Result) ;
  //! Eval the script and returns OK = 0, ERROR = 1 <br>
  Standard_EXPORT     Standard_Integer Eval(const Standard_CString Script) ;
  //! Eval the script and returns OK = 0, ERROR = 1 <br>
//!          Store the script in the history record. <br>
  Standard_EXPORT     Standard_Integer RecordAndEval(const Standard_CString Script,const Standard_Integer Flags = 0) ;
  //! Eval the content on the file and returns status <br>
  Standard_EXPORT     Standard_Integer EvalFile(const Standard_CString FileName) ;
  //! Returns True if the script is complete, no pending <br>
//!          closing braces. (}) <br>
  Standard_EXPORT   static  Standard_Boolean Complete(const Standard_CString Script) ;
  
  Standard_EXPORT     void Destroy() ;
~Draw_Interpretor()
{
  Destroy();
}
  
  Standard_EXPORT   Draw_Interpretor(const Draw_PInterp& anInterp);
  
  Standard_EXPORT     void Set(const Draw_PInterp& anInterp) ;
  
  Standard_EXPORT     Draw_PInterp Interp() const;
  //! Enables or disables logging of all commands and their <br>
//! results <br>
  Standard_EXPORT     void SetDoLog(const Standard_Boolean doLog) ;
  //! Enables or disables eachoing of all commands and their <br>
//! results to cout <br>
  Standard_EXPORT     void SetDoEcho(const Standard_Boolean doEcho) ;
  //! Returns true if logging of commands is enabled <br>
  Standard_EXPORT     Standard_Boolean GetDoLog() const;
  //! Returns true if echoing of commands is enabled <br>
  Standard_EXPORT     Standard_Boolean GetDoEcho() const;
  //! Returns log stream <br>
  Standard_EXPORT     Standard_SStream& Log() ;





protected:





private:



Standard_Boolean isAllocated;
Draw_PInterp myInterp;
Standard_Boolean myDoLog;
Standard_Boolean myDoEcho;
Standard_SStream myLog;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
