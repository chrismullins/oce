// Created on: 2002-12-12
// Created by: data exchange team
// Copyright (c) 2002-2012 OPEN CASCADE SAS
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

// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.2

#include <StepElement_SurfaceSection.ixx>

//=======================================================================
//function : StepElement_SurfaceSection
//purpose  : 
//=======================================================================

StepElement_SurfaceSection::StepElement_SurfaceSection ()
{
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void StepElement_SurfaceSection::Init (const StepElement_MeasureOrUnspecifiedValue &aOffset,
                                       const StepElement_MeasureOrUnspecifiedValue &aNonStructuralMass,
                                       const StepElement_MeasureOrUnspecifiedValue &aNonStructuralMassOffset)
{

  theOffset = aOffset;

  theNonStructuralMass = aNonStructuralMass;

  theNonStructuralMassOffset = aNonStructuralMassOffset;
}

//=======================================================================
//function : Offset
//purpose  : 
//=======================================================================

StepElement_MeasureOrUnspecifiedValue StepElement_SurfaceSection::Offset () const
{
  return theOffset;
}

//=======================================================================
//function : SetOffset
//purpose  : 
//=======================================================================

void StepElement_SurfaceSection::SetOffset (const StepElement_MeasureOrUnspecifiedValue &aOffset)
{
  theOffset = aOffset;
}

//=======================================================================
//function : NonStructuralMass
//purpose  : 
//=======================================================================

StepElement_MeasureOrUnspecifiedValue StepElement_SurfaceSection::NonStructuralMass () const
{
  return theNonStructuralMass;
}

//=======================================================================
//function : SetNonStructuralMass
//purpose  : 
//=======================================================================

void StepElement_SurfaceSection::SetNonStructuralMass (const StepElement_MeasureOrUnspecifiedValue &aNonStructuralMass)
{
  theNonStructuralMass = aNonStructuralMass;
}

//=======================================================================
//function : NonStructuralMassOffset
//purpose  : 
//=======================================================================

StepElement_MeasureOrUnspecifiedValue StepElement_SurfaceSection::NonStructuralMassOffset () const
{
  return theNonStructuralMassOffset;
}

//=======================================================================
//function : SetNonStructuralMassOffset
//purpose  : 
//=======================================================================

void StepElement_SurfaceSection::SetNonStructuralMassOffset (const StepElement_MeasureOrUnspecifiedValue &aNonStructuralMassOffset)
{
  theNonStructuralMassOffset = aNonStructuralMassOffset;
}
