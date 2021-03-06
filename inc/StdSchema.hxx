#ifndef _Storage_Schema_HeaderFile
#include <Storage_Schema.hxx>
#endif
#ifndef _Storage_BaseDriver_HeaderFile
#include <Storage_BaseDriver.hxx>
#endif
#ifndef _Storage_CallBack_HeaderFile
#include <Storage_CallBack.hxx>
#endif
#ifndef _Storage_Macros_HeaderFile
#include <Storage_Macros.hxx>
#endif
class Handle(PDataXtd_Position);
class Handle(PDataXtd_Point);
class Handle(PDataXtd_Axis);
class Handle(PDataXtd_Plane);
class Handle(PDataXtd_Geometry);
class Handle(PDataXtd_Constraint);
class Handle(PDataXtd_Placement);
class Handle(PDataXtd_PatternStd);
class Handle(PDataXtd_Shape);
class Handle(PNaming_Name);
class Handle(PNaming_Name_1);
class Handle(PNaming_NamedShape);
class Handle(PNaming_Naming);
class Handle(PNaming_Naming_1);
class Handle(PNaming_HArray1OfNamedShape);
class PNaming_FieldOfHArray1OfNamedShape;
class Handle(PPrsStd_AISPresentation);
class Handle(PPrsStd_AISPresentation_1);
class Handle(PDF_Attribute);
class Handle(Standard_Persistent);
class Standard_Storable;
class gp_Pnt;
class Handle(PDataStd_Real);
class Handle(PDF_HAttributeArray1);
class Handle(PDataStd_Integer);
class Handle(PCollection_HAsciiString);
class Handle(PTopoDS_HArray1OfShape1);
class Handle(PColStd_HArray1OfInteger);
class Handle(PCollection_HExtendedString);
class gp_Ax1;
class gp_Ax2;
class gp_Trsf;
class gp_Vec;
class gp_XYZ;
class PDF_FieldOfHAttributeArray1;
class DBC_VArrayOfCharacter;
class PTopoDS_Shape1;
class PTopoDS_FieldOfHArray1OfShape1;
class PColStd_FieldOfHArray1OfInteger;
class DBC_VArrayOfExtCharacter;
class gp_Dir;
class gp_Ax3;
class gp_Mat;
class gp_Trsf2d;
class Handle(PTopoDS_TShape1);
class PTopLoc_Location;
class gp_Ax2d;
class gp_Mat2d;
class gp_Pnt2d;
class gp_Vec2d;
class gp_XY;
class Handle(PTopLoc_Datum3D);
class Handle(PTopLoc_ItemLocation);
class gp_Dir2d;
// File generated by Schema (Schema)
//
//                     Copyright (C) 1991 - 2000 by  
//                      Matra Datavision SA.  All rights reserved.
//  
//                     Copyright (C) 2001 - 2004 by
//                     Open CASCADE SA.  All rights reserved.
// 
// This file is part of the Open CASCADE Technology software.
//
// This software may be distributed and/or modified under the terms and
// conditions of the Open CASCADE Public License as defined by Open CASCADE SA
// and appearing in the file LICENSE included in the packaging of this file.
//  
// This software is distributed on an "AS IS" basis, without warranty of any
// kind, and Open CASCADE SA hereby disclaims all such warranties,
// including without limitation, any warranties of merchantability, fitness
// for a particular purpose or non-infringement. Please see the License for
// the specific terms and conditions governing rights and limitations under the
// License.

#ifndef _StdSchema_HeaderFile
#define _StdSchema_HeaderFile

#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif
#ifndef _Storage_Macros_HeaderFile
#include <Storage_Macros.hxx>
#endif
#ifndef _Storage_stCONSTclCOM_HeaderFile
#include <Storage_stCONSTclCOM.hxx>
#endif
#ifndef _Storage_Schema_HeaderFile
#include <Storage_Schema.hxx>
#endif
#ifndef _Storage_CallBack_HeaderFile
#include <Storage_CallBack.hxx>
#endif
#ifndef _Storage_BaseDriver_HeaderFile
#include <Storage_BaseDriver.hxx>
#endif

DEFINE_STANDARD_HANDLE(StdSchema,Storage_Schema)


class StdSchema : public Storage_Schema {
public:

  Storage_DECLARE_SCHEMA_METHODS(StdSchema)

  DEFINE_STANDARD_RTTI(StdSchema)
};

#endif
