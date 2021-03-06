// Copyright (c) 1999-2012 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.

#include <IGESSelect_AutoCorrect.ixx>
#include <IGESData_Protocol.hxx>
#include <IGESData_BasicEditor.hxx>
#include <Interface_Check.hxx>

#include <Interface_Macros.hxx>




IGESSelect_AutoCorrect::IGESSelect_AutoCorrect ()
    : IGESSelect_ModelModifier (Standard_False)    {  }

    void  IGESSelect_AutoCorrect::Performing
  (IFSelect_ContextModif& ctx,
   const Handle(IGESData_IGESModel)& target,
   Interface_CopyTool& ) const
{
  DeclareAndCast(IGESData_Protocol,protocol,ctx.Protocol());
  if (protocol.IsNull()) {
    ctx.CCheck()->AddFail("IGES Auto Correct, not called with Protocol");
    return;
  }

  IGESData_BasicEditor corrector (target,protocol);
  for (ctx.Start(); ctx.More(); ctx.Next()) {
    DeclareAndCast(IGESData_IGESEntity,ent,ctx.ValueResult());
    Standard_Boolean done = corrector.AutoCorrect (ent);
    if (done) ctx.Trace();
  }
}


    TCollection_AsciiString  IGESSelect_AutoCorrect::Label () const
{
  return TCollection_AsciiString ("Auto-Correction of IGES Entities");
}
