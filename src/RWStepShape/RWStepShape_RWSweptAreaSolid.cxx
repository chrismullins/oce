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


#include <RWStepShape_RWSweptAreaSolid.ixx>
#include <StepGeom_CurveBoundedSurface.hxx>


#include <Interface_EntityIterator.hxx>


#include <StepShape_SweptAreaSolid.hxx>


RWStepShape_RWSweptAreaSolid::RWStepShape_RWSweptAreaSolid () {}

void RWStepShape_RWSweptAreaSolid::ReadStep
	(const Handle(StepData_StepReaderData)& data,
	 const Standard_Integer num,
	 Handle(Interface_Check)& ach,
	 const Handle(StepShape_SweptAreaSolid)& ent) const
{


	// --- Number of Parameter Control ---

	if (!data->CheckNbParams(num,2,ach,"swept_area_solid")) return;

	// --- inherited field : name ---

	Handle(TCollection_HAsciiString) aName;
	//szv#4:S4163:12Mar99 `Standard_Boolean stat1 =` not needed
	data->ReadString (num,1,"name",ach,aName);

	// --- own field : sweptArea ---

	Handle(StepGeom_CurveBoundedSurface) aSweptArea;
	//szv#4:S4163:12Mar99 `Standard_Boolean stat2 =` not needed
	data->ReadEntity(num, 2,"swept_area", ach, STANDARD_TYPE(StepGeom_CurveBoundedSurface), aSweptArea);

	//--- Initialisation of the read entity ---


	ent->Init(aName, aSweptArea);
}


void RWStepShape_RWSweptAreaSolid::WriteStep
	(StepData_StepWriter& SW,
	 const Handle(StepShape_SweptAreaSolid)& ent) const
{

	// --- inherited field name ---

	SW.Send(ent->Name());

	// --- own field : sweptArea ---

	SW.Send(ent->SweptArea());
}


void RWStepShape_RWSweptAreaSolid::Share(const Handle(StepShape_SweptAreaSolid)& ent, Interface_EntityIterator& iter) const
{

	iter.GetOneItem(ent->SweptArea());
}

