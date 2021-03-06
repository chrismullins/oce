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

#include <RWStepBasic_RWThermodynamicTemperatureUnit.ixx>

//=======================================================================
//function : RWStepBasic_RWThermodynamicTemperatureUnit
//purpose  : 
//=======================================================================

RWStepBasic_RWThermodynamicTemperatureUnit::RWStepBasic_RWThermodynamicTemperatureUnit ()
{
}

//=======================================================================
//function : ReadStep
//purpose  : 
//=======================================================================

void RWStepBasic_RWThermodynamicTemperatureUnit::ReadStep (const Handle(StepData_StepReaderData)& data,
                                                           const Standard_Integer num,
                                                           Handle(Interface_Check)& ach,
                                                           const Handle(StepBasic_ThermodynamicTemperatureUnit) &ent) const
{
  // Check number of parameters
  if ( ! data->CheckNbParams(num,1,ach,"thermodynamic_temperature_unit") ) return;

  // Inherited fields of NamedUnit

  Handle(StepBasic_DimensionalExponents) aNamedUnit_Dimensions;
  data->ReadEntity (num, 1, "named_unit.dimensions", ach, STANDARD_TYPE(StepBasic_DimensionalExponents), aNamedUnit_Dimensions);

  // Initialize entity
  ent->Init(aNamedUnit_Dimensions);
}

//=======================================================================
//function : WriteStep
//purpose  : 
//=======================================================================

void RWStepBasic_RWThermodynamicTemperatureUnit::WriteStep (StepData_StepWriter& SW,
                                                            const Handle(StepBasic_ThermodynamicTemperatureUnit) &ent) const
{

  // Inherited fields of NamedUnit

  SW.Send (ent->StepBasic_NamedUnit::Dimensions());
}

//=======================================================================
//function : Share
//purpose  : 
//=======================================================================

void RWStepBasic_RWThermodynamicTemperatureUnit::Share (const Handle(StepBasic_ThermodynamicTemperatureUnit) &ent,
                                                        Interface_EntityIterator& iter) const
{

  // Inherited fields of NamedUnit

  iter.AddItem (ent->StepBasic_NamedUnit::Dimensions());
}
