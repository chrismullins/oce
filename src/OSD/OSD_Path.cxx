// Copyright (c) 1998-1999 Matra Datavision
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

#ifdef HAVE_CONFIG_H
# include <oce-config.h>
#endif

#ifndef WNT

#include <Standard_NumericError.hxx>
#include <Standard_NullObject.hxx>
#include <Standard_ProgramError.hxx>
#include <Standard_ConstructionError.hxx>
#include <OSD_Path.ixx>
#include <OSD_WhoAmI.hxx>

static OSD_SysType whereAmI(){
#if defined(__digital__) || defined(__FreeBSD__) || defined(SUNOS) || defined(__APPLE__) || defined(__FreeBSD_kernel__)
  return OSD_UnixBSD;
}
#elif defined(sgi)  || defined(IRIX) || defined(__sun)  || defined(SOLARIS) ||  defined(__sco__) || defined(__hpux) || defined(HPUX)
  return OSD_UnixSystemV;
}
#elif defined(__osf__) || defined(DECOSF1)
  return OSD_OSF;
}
#elif defined(OS2)
  return OSD_WindowsNT;
}
#elif defined(WIN32)
  return OSD_WindowsNT;
}
#elif defined(__CYGWIN32_) || defined(__MINGW32__)
  return OSD_WindowsNT;
}
#elif defined(vax) || defined(__vms)
  return OSD_VMS;
}
#elif defined(__linux__) || defined(LIN)
  return OSD_LinuxREDHAT;
}
#elif defined(_AIX) || defined(AIX)
  return OSD_Aix;
}
#else
  return OSD_Default;
}
#endif



OSD_Path::OSD_Path(){
 SysDep = whereAmI();
}

static void VmsExtract(const TCollection_AsciiString& what,
                TCollection_AsciiString& node,
                TCollection_AsciiString& username,
                TCollection_AsciiString& password,
                TCollection_AsciiString& disk,
                TCollection_AsciiString& trek,
                TCollection_AsciiString& name,
                TCollection_AsciiString& ext){

 TCollection_AsciiString buffer;
 Standard_Integer pos;

 buffer = what;

 if (buffer.Search("\"") != -1){  // a username to extract

   if (buffer.Value(1) != '"') { // Begins with Node
    node = buffer.Token("\"");
    buffer.Remove(1,node.Length());
   }
   else node = "";

   username = buffer.Token("\" ");
   buffer.Remove(1,username.Length()+2); // Removes <<"username ' ' or '"' >>

   if (buffer.Search("\"") != -1){ // a password to extract
    password = buffer.Token("\"");
    buffer.Remove(1,password.Length()+1);  // removes <<password">>
   }

   // If we found a node then we must find "::"
   if (buffer.Search("::") != -1)
    buffer.Remove(1,2);            // Removes <<::>>
 }
 else  // No name or password
 if (buffer.Search("::") != -1){ // a node to extract
  node = buffer.Token(":");
  buffer.Remove(1,node.Length()+2); // Removes <<node::>
 }

 if (buffer.Search(":") != -1){ // a disk to extract
   disk = buffer.Token(":");
   buffer.Remove(1,disk.Length()+1);  // Removes <<disk:>>
 }
 else disk = "";

 // Analyse trek

 if (buffer.Search("[") != -1){  // There is atrek to extract
  trek = buffer.Token("[]");

  if (trek.Value(1) == '.') trek.Remove(1,1);  // Removes first '.'
    else trek.Insert(1,'|');                   // Add root

  trek.ChangeAll('.','|');   // Translates to portable syntax
  trek.ChangeAll('-','^');  

  pos = trek.Search("000000");
  if (pos != -1) {
   trek.Remove(pos,6); // on VMS [000000] is the root
   if (trek.Search("||") != -1) trek.Remove(1,1); // When [000000.xxx] -> ||xxx
  }

  name = buffer.Token("]",2);
 }
 else name = buffer;

 if (name.Search(".") != -1){
  ext = name.Token(".",2);
  ext.Insert(1,'.');
  name.Remove(name.Search("."),ext.Length());
 }
 else ext = "";
  
}


//=======================================================================
//function : UnixExtract
//purpose  : 
//=======================================================================
static void UnixExtract(const TCollection_AsciiString& what,
			TCollection_AsciiString& node,
			TCollection_AsciiString& username,
			TCollection_AsciiString& password,
			TCollection_AsciiString& trek,
			TCollection_AsciiString& name,
			TCollection_AsciiString& ext){

 Standard_Integer pos;
 TCollection_AsciiString buffer;   // To manipulate 'what' without modifying it

 Standard_PCharacter p;
 buffer = what;

#ifdef TOTO  // Username, password and node are no longer given in the string (LD)

 if (buffer.Search("@") != -1){  // There is a name to extract
  username = buffer.Token("\"@");
  buffer.Remove(1,username.Length()+1);   // Removes << user@ >>

  if (buffer.Search("\"") != -1){       // There is a password to extract
   password = buffer.Token("\"");
   buffer.Remove(1,password.Length()+2);  // Removes << "password" >>
  }

 }
 else {
  username = "";
  password = "";
 }

#endif  // node must be given (for DBT, DM) (ADN 29/8/96)

 if (buffer.Search(":/") != -1){      // There is a node to extract
  node = buffer.Token(":/");
  buffer.Remove(1,node.Length()+1);  // Removes << node: >>
 }
 else node = ""; 

  username = "";
  password = "";
//  node = ""; 
 
 trek = buffer;

 trek.ChangeAll('/','|');  // Translates to portable syntax

 pos = trek.SearchFromEnd("|");  // Extract name
 if (pos != -1) {
  p = (Standard_PCharacter)trek.ToCString();
  name = &p[pos];
  if(name.Length()) trek.Remove(pos+1,name.Length());
 }
 else {   // No '|' means no trek but a name
  name = buffer;
  trek = "";
 }

 pos = trek.Search("..");
 while (pos != -1){        // Changes every ".." by '^'
  trek.SetValue(pos,'^');
  trek.Remove(pos+1,1);
  pos = trek.Search("..");
 }

  pos = name.SearchFromEnd(".") ;   // LD : debug
  if (pos != -1)      // There is an extension to extract
    ext = name.Split(pos - 1) ;  


// if (name.Search(".") != -1){ // There is an extension to extract
//   if ( name.Value(1) == '.' ) {
//     ext = name;
//     name.Clear();
//   }
//   else {
//     ext = name.Token(".",2); 
//     ext.Insert(1,'.');            // Prepends 'dot'
//     pos = name.Search(".");     // Removes extension from buffer
//     if (pos != -1)
//       name.Remove(pos,ext.Length());
//   }
// }

}


//=======================================================================
//function : DosExtract
//purpose  : 
//=======================================================================
static void DosExtract(const TCollection_AsciiString& what,
                TCollection_AsciiString& disk,
                TCollection_AsciiString& trek,
                TCollection_AsciiString& name,
                TCollection_AsciiString& ext){

 TCollection_AsciiString buffer;
 Standard_Integer pos;
 Standard_PCharacter p;

 buffer = what;

 if (buffer.Search(":") != -1){ // There is a disk to extract
  disk = buffer.Token(":");
  disk += ":";
  buffer.Remove(1,disk.Length());  // Removes <<disk:>>
 }

 if (buffer.Search(".") != -1){ // There is an extension to extract
  ext = buffer.Token(".",2); 
  ext.Insert(1,'.');            // Prepends 'dot'
  pos = buffer.Search(".");     // Removes extension from buffer
  if (pos != -1)
   buffer.Remove(pos,ext.Length());
 }

 trek = buffer;

 trek.ChangeAll('\\','|');  

 pos = trek.Search("..");
 while (pos != -1){        // Changes every ".." by '^'
  trek.SetValue(pos,'^');
  trek.Remove(pos+1,1);
  pos = trek.Search("..");
 }

 pos = trek.SearchFromEnd("|");  // Extract name
 if (pos != -1) {
  p = (Standard_PCharacter)trek.ToCString();
  name = &p[pos];
  trek.Remove(trek.Search(name),name.Length());
 }
 else {   // No '|' means no trek but a name
  name = buffer;
  trek = "";
 }
}


//=======================================================================
//function : MacExtract
//purpose  : 
//=======================================================================
static void MacExtract(const TCollection_AsciiString& what,
                TCollection_AsciiString& ,
                TCollection_AsciiString& trek,
                TCollection_AsciiString& name,
                TCollection_AsciiString& ){

  Standard_Integer pos;
  Standard_PCharacter p;
  
  // I don't know how to distingish a disk from a trek !
  
  trek = what;
  
  pos = trek.Search("::");
  while (pos != -1){        // Changes every "::" by '^'
    trek.SetValue(pos,'^');
    trek.Remove(pos+1,1);
    pos = trek.Search("::");
  }

  trek.ChangeAll(':','|');  // Translates to portable syntax

  pos = trek.SearchFromEnd("|");  // Extract name
  if (pos != -1) {
    p = (Standard_PCharacter)trek.ToCString();
    name = &p[pos+1];
    trek.Remove(trek.Search(name),name.Length());
  }
  else {   // No '|' means no trek but a name
    name = what;
    trek = "";
  }
}


OSD_Path::OSD_Path(const TCollection_AsciiString& aDependentName,
		   const OSD_SysType aSysType){

 SysDep = whereAmI();

 if (!IsValid(aDependentName,aSysType))
  Standard_ProgramError::Raise("OSD_Path::OSD_Path : Invalid dependent name");

 OSD_SysType todo;
//  Standard_Integer i,l;

  if (aSysType == OSD_Default) {
    todo = SysDep;
  } else {
    todo = aSysType;
  }

 switch (todo){
  case OSD_VMS:
     VmsExtract(aDependentName,myNode,myUserName,myPassword,myDisk,myTrek,myName,myExtension);
     break;
  case OSD_LinuxREDHAT:
  case OSD_UnixBSD:
  case OSD_UnixSystemV:
  case OSD_Aix:
  case OSD_OSF:
     UnixExtract(aDependentName,myNode,myUserName,myPassword,myTrek,myName,myExtension);
     break;
  case OSD_OS2:
  case OSD_WindowsNT:
     DosExtract(aDependentName,myDisk,myTrek,myName,myExtension);
     break;
  case OSD_MacOs:
     MacExtract(aDependentName,myDisk,myTrek,myName,myExtension);
     break;
  default:
#ifndef DEB
       cout << " WARNING WARNING : OSD Path for an Unknown SYSTEM : " << (Standard_Integer)todo << endl;
#endif 
     break ;
 } 
}



OSD_Path::OSD_Path(const TCollection_AsciiString& Nod,
                   const TCollection_AsciiString& UsrNm,
                   const TCollection_AsciiString& Passwd,
                   const TCollection_AsciiString& Dsk,
                   const TCollection_AsciiString& Trk,
                   const TCollection_AsciiString& Nam,
		   const TCollection_AsciiString& ext){

 SysDep = whereAmI();

 SetValues ( Nod, UsrNm, Passwd, Dsk, Trk, Nam, ext);


}


void OSD_Path::Values(TCollection_AsciiString& Nod, 
                      TCollection_AsciiString& UsrNm, 
                      TCollection_AsciiString& Passwd, 
                      TCollection_AsciiString& Dsk, 
                      TCollection_AsciiString& Trk,
                      TCollection_AsciiString& Nam,
		      TCollection_AsciiString& ext)const{

 Nod = myNode;
 UsrNm = myUserName;
 Passwd = myPassword;
 Dsk = myDisk;
 Trk = myTrek;
 Nam = myName;
 ext = myExtension;
}


void OSD_Path::SetValues(const TCollection_AsciiString& Nod, 
                         const TCollection_AsciiString& UsrNm, 
                         const TCollection_AsciiString& Passwd,
                         const TCollection_AsciiString& Dsk,
                         const TCollection_AsciiString& Trk,
                         const TCollection_AsciiString& Nam,
                         const TCollection_AsciiString& ext){

 if (!Nod.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetValues argument : Node");
 if (!UsrNm.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetValues argument : User Name");
 if (!Dsk.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetValues argument : Disk");
 if (!Trk.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetValues argument : Trek");
 if (!Nam.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetValues argument : Name");
 if (!ext.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetValues argument : Extension");

 myNode = Nod;
 myUserName = UsrNm;
 myPassword = Passwd;
 myDisk = Dsk;
 myTrek = Trk;
 myName = Nam;
 myExtension = ext;
}


static Standard_Boolean Analyse_VMS(const TCollection_AsciiString& name){
 if (name.Search("/") != -1)
  return(Standard_False);
 if (name.Search("@") != -1)
  return(Standard_False);
 if (name.Search("\\") != -1)
  return(Standard_False);


 return Standard_True;
}

static Standard_Boolean Analyse_DOS(const TCollection_AsciiString& name){

// if (name.Search("$") != -1)
//  return(Standard_False);
// if (name.Search(" ") != -1)
//  return(Standard_False);

 if (name.Search("/") != -1)
  return(Standard_False);
 if (name.Search(":") != -1)
  return(Standard_False);
  if (name.Search("*") != -1)
  return(Standard_False);
 if (name.Search("?") != -1)
  return(Standard_False);
 if (name.Search(".") != name.SearchFromEnd("."))
  return(Standard_False);
 if (name.Search("\"") != -1)
  return(Standard_False);
 if (name.Search("<") != -1)
  return(Standard_False);
 if (name.Search(">") != -1)
  return(Standard_False);
 if (name.Search("|") != -1)
  return(Standard_False);
   
 return Standard_True;
 // Rajouter les tests sur les noms de 8 caracteres au maximum et
 // l'extension de 3 caracteres.
}

static Standard_Boolean Analyse_MACOS(const TCollection_AsciiString& name){
 Standard_Integer i = name.Search(":");
 Standard_Integer l = name.Length();

 if (i == -1)
  if (l > 31)
    return(Standard_False);
  else 
    return(Standard_True);
 else
   return(Standard_True);
}

static Standard_Boolean Analyse_UNIX(const TCollection_AsciiString& /*name*/)
{
// if (name.Search("$") != -1)  Unix filename can have a "$" (LD)
//  return(Standard_False);

// all characters are allowed in UNIX file name, except null '\0' and slash '/'

// if (name.Search("[") != -1)
//  return(Standard_False);
// if (name.Search("]") != -1)
//  return(Standard_False);
// if (name.Search("\\") != -1)
//  return(Standard_False);
// if (name.Search(" ") != -1) 
//  return(Standard_False);

  return(Standard_True);

}





Standard_Boolean OSD_Path::IsValid(const TCollection_AsciiString& aDependentName,
                                   const OSD_SysType aSysType)const{
 if (aDependentName.Length()==0) return(Standard_True);
 if (!aDependentName.IsAscii()) return(Standard_False);

 OSD_SysType provSys;
 if (aSysType == OSD_Default) provSys = SysDep;
                      else provSys = aSysType; 

 switch (provSys){
  case OSD_VMS:
            return(Analyse_VMS(aDependentName));
  case OSD_OS2:
  case OSD_WindowsNT:
            return(Analyse_DOS(aDependentName));
  case OSD_MacOs:
            return(Analyse_MACOS(aDependentName));
  default:
            return(Analyse_UNIX(aDependentName));

 }
}


void OSD_Path::UpTrek(){
 Standard_Integer length=TrekLength();

 if (length == 0) return;

 Standard_Integer awhere,aHowmany;
 TCollection_AsciiString tok;

 tok = myTrek.Token("|",length);
 awhere = myTrek.SearchFromEnd(tok);
 aHowmany = tok.Length();
 myTrek.Remove(awhere,aHowmany);

 awhere = myTrek.Search("||");   // Searches leaving "||"
 if (awhere != -1)
  myTrek.Remove(awhere);
}


void OSD_Path::DownTrek(const TCollection_AsciiString& aName){
 myTrek += aName;
// Pb signale par GG : pour ne pas avoir "||" ;
 if ( aName.ToCString()[ aName.Length() - 1 ] != '|' )
   myTrek += "|";
}


Standard_Integer OSD_Path::TrekLength()const{
 Standard_Integer cpt=0;

 while (myTrek.Token("|",cpt+1) != "")  // Counts token separated by '|'
  cpt++;

 return(cpt);
}


void OSD_Path::RemoveATrek(const Standard_Integer thewhere){
 Standard_Integer length=TrekLength();

 if (length <= 0 || thewhere > length)
  Standard_NumericError::Raise("OSD_Path::RemoveATrek : where has an invalid value");

 Standard_Integer posit,aHowmany;
 TCollection_AsciiString tok;

 tok = myTrek.Token("|",thewhere);
 posit = myTrek.Search(tok);
 aHowmany = tok.Length();
 myTrek.Remove(posit,aHowmany);

 posit = myTrek.Search("||");   // Searches leaving "||"
 if (posit != -1)
  myTrek.Remove(posit);
}


void OSD_Path::RemoveATrek(const TCollection_AsciiString& aName){
 Standard_Integer length=TrekLength();

 if (length == 0) return;

 Standard_Integer awhere;

 awhere = myTrek.Search(aName);
 if (awhere != -1){
  myTrek.Remove(awhere,aName.Length());

  awhere = myTrek.Search("||");   // Searches leaving "||"
  if (awhere != -1)
   myTrek.Remove(awhere); 
 } 
}


TCollection_AsciiString OSD_Path::TrekValue(const Standard_Integer thewhere)const{
 TCollection_AsciiString result=myTrek.Token("|",thewhere);

 if (result == "")
  Standard_NumericError::Raise("OSD_Path::TrekValue : where is invalid");

 return(result);
}

void OSD_Path::InsertATrek(const TCollection_AsciiString& aName,
                           const Standard_Integer thewhere){
 Standard_Integer length=TrekLength();

 if (thewhere <= 0 || thewhere > length)
  Standard_NumericError::Raise("OSD_Path::InsertATrek : where has an invalid value");

 TCollection_AsciiString tok=myTrek.Token("|",thewhere);
 Standard_Integer wwhere = myTrek.Search(tok);
 TCollection_AsciiString what = aName;
 what += "|";

 myTrek.Insert(wwhere,what);
}


// The 4 following methods will be PUBLIC in the future

// Converts a VMS disk to other system syntax

static void VMSDisk2Other(TCollection_AsciiString & Disk){
 Disk.RemoveAll('$');
}


// Convert a Trek to VMS syntax

static void P2VMS (TCollection_AsciiString & Way){
 Standard_Integer length = Way.Length();

 if (length == 0) return;

 if (Way.Value(1) == '|')             // If begin with '|' remove '|'
  if (Way.Value(1) != '\0')
   Way.Remove(1,1);
  else Way = "000000";             // Si uniquement la racine -> [000000]
 else
  if (Way.Length()!=0)
   Way.Insert(1,'|');          // Else insert '|' at beginning if not empty;

 Way.ChangeAll('|','.');
 Way.ChangeAll('^','-');

}

// Convert a Trek to MAC syntax

static void P2MAC (TCollection_AsciiString & Way){
 int i,l;
 Way.ChangeAll('|',':');

 l = (int)Way.Length();
 for (i=1; i <= l; i++)             // Replace '^' by "::"
  if (Way.Value(i) == '^'){
   Way.SetValue(i,':');
   Way.Insert(i,':');
   i++; l++;
  } 
}


// Convert a Trek to UNIX syntax

static void P2UNIX (TCollection_AsciiString & Way){
 int i,l;
 Standard_Integer length = Way.Length();

 if (length == 0) return;

 // if (Way.Value(length) == '|') // If Finishes with "|" removes it
 // Way.Trunc(length-1);

 Way.ChangeAll('|','/');
 
 l = (int)Way.Length();
 for (i=1; i <= l; i++)             // Replace '^' by "../"
  if (Way.Value(i) == '^'){
   Way.SetValue(i,'.');
   Way.Insert(i+1,'.');
   //Way.Insert(i+2,'/');
   i +=1; l +=1;
  } 
}


// Convert a Trek to DOS like syntax

static void P2DOS (TCollection_AsciiString & Way){
 int i,l;
 Standard_Integer len = Way.Length();

 if (len == 0) return;

 if (Way.Value(len) == '|')   // If Finishes with "|" removes it
  Way.Trunc(len-1);

 Way.ChangeAll('|','\\');
 
 l = (int)Way.Length();
 for (i=1; i <= l; i++)             // Replace '^' by ".."
  if (Way.Value(i) == '^'){
   Way.SetValue(i,'.');
   Way.Insert(i,'.');
   i++; l++;
  } 

}




// Convert a path to system dependant syntax

void OSD_Path::SystemName (TCollection_AsciiString& FullName,
			   const OSD_SysType aType)const{
TCollection_AsciiString Way;
TCollection_AsciiString pNode;
TCollection_AsciiString pDisk;
OSD_SysType pType;

 if (aType == OSD_Default) {
   pType = SysDep;
 } else {
   pType = aType;
 }

 Way = myTrek;
 FullName.Clear();

 switch (pType){
  case OSD_VMS :
   pNode = myNode;

   P2VMS (Way);    // Convert path

   if (myNode.Length()!=0) FullName += myNode;      // Append Node

   if (myUserName.Length()!=0){   // Append User name

    if (pNode.Length()==0) {    // If a user name but no node, catenate "0"
     pNode = "0";
     FullName += pNode;
    }


    FullName += "\"";
    FullName += myUserName;

    if (myPassword.Length()!=0){  // Append password
     FullName += " ";
     FullName += myPassword;
    }

    FullName += "\"";
   }

   if (pNode.Length()!=0) FullName += "::";

   if (myDisk.Length()!=0){       // Append Disk
    FullName += myDisk;
    FullName += ":";
   }
    

   if (Way.Length()!=0)         // Append VMS path
    FullName = FullName + "[" + Way + "]" + myName + myExtension;

//   FullName.UpperCase();
   break;


   case OSD_OS2 :
   case OSD_WindowsNT :            // MSDOS-like syntax
    {
    int length = (int)myDisk.Length();

    P2DOS (Way);
    if (length != 1)

    if (myDisk.Length()!=0){

     if (
         (length == 1 && IsAlphabetic(myDisk.Value(1))) ||     // 'A/a' to 'Z/z'
         (length == 2 &&
          IsAlphabetic(myDisk.Value(1)) &&
          myDisk.Value(2) == ':')                         // 'A:' to 'Z:'
        )    // This is a MSDOS disk syntax
     {
      FullName += myDisk;
      if (myDisk.Value(length) != ':') FullName += ":";
     }
     else   // This is an assigned Disk
     {
      FullName += "\\";
      pDisk = myDisk;
      VMSDisk2Other(pDisk);
      FullName += pDisk;
      if (Way.Value(1) != '\\') FullName += "\\";
     }
    }

    if (Way.Length()!=0)
     FullName = FullName + Way + "\\";
    
    FullName += myName; 
    FullName += myExtension;
//    FullName.UpperCase();
    break;
   }

   case OSD_MacOs :                // Mackintosh-like syntax
    if (myDisk.Length()!=0){
     FullName += myDisk ;
     FullName += ":";
    }
    P2MAC(Way); 
    FullName += myName;
    FullName += myExtension;
   break;



   default :                      // UNIX-like syntax

 // Syntax :
 //             user"password"@host:/disk/xxx/xxx/filename
    P2UNIX (Way);

    if (myUserName.Length()!=0 && myNode.Length()!=0){  // If USER name
     FullName += myUserName;                        // appends user name 

     if (myPassword.Length()!=0)
      FullName = FullName + "\"" + myPassword + "\""; // a password if not empty

     FullName += "@";                            // and character '@'
    }

    if (myNode.Length()!=0){                     // Appends HOST name
     FullName += myNode;
     FullName += ":";
    }

    if (myDisk.Length()!=0) {                    // Appends Disk name as path
     FullName += "/";
     pDisk = myDisk;
     VMSDisk2Other(pDisk);
     FullName += pDisk;
    }

//    if (FullName.Length()) {                     // Adds a "/" if necessary
//      FullName += "/";
//    }

    if (Way.Length()!=0) {                       // Appends a path if not empty
      FullName += Way ; 
    }

    if (FullName.Length()){
	if (FullName.Value(FullName.Length()) != '/') {
           FullName += "/";                      // Adds a / if necessary
       }
    }

    if (myName.Length()){                        // Adds the file name
      FullName += myName;
    }

    if (myExtension.Length()) {                  // Adds the extension
      FullName += myExtension;
    }
    break;
 }
}

#ifdef TOTO  // A reactiver...

void OSD_Path::SetSystemName(const TCollection_AsciiString& aDependentName,
		   const OSD_SysType aSysType){
  UnixExtract(aDependentName,myNode,myUserName,myPassword,myTrek,myName,myExtension);
}
#endif

TCollection_AsciiString OSD_Path::Node()const{
 return(myNode);
}


TCollection_AsciiString OSD_Path::UserName()const{
 return(myUserName);
}


TCollection_AsciiString OSD_Path::Password()const{
 return(myPassword);
}


TCollection_AsciiString OSD_Path::Disk()const{
 return(myDisk);
}


TCollection_AsciiString OSD_Path::Trek()const{
 return(myTrek);
}


// Return extension (suffix) of file/directory name

TCollection_AsciiString OSD_Path::Extension()const{
 return(myExtension);
}


TCollection_AsciiString OSD_Path::Name()const{
 return(myName);
}


void OSD_Path::SetNode(const TCollection_AsciiString& aName){
 if (!aName.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetNode bad name");
 myNode = aName;
}




void OSD_Path::SetUserName(const TCollection_AsciiString& aName){
 if (!aName.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetUserName bad name");
 myUserName = aName;
}




void OSD_Path::SetPassword(const TCollection_AsciiString& aName){
 if (!aName.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetPassword bad name");
  myPassword = aName;
}




void OSD_Path::SetDisk(const TCollection_AsciiString& aName){
 if (!aName.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetDisk bad name");
  myDisk = aName;
}




void OSD_Path::SetTrek(const TCollection_AsciiString& aName){
 if (!aName.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetTrek bad name");
  myTrek = aName;
}




void OSD_Path::SetName(const TCollection_AsciiString& aName){
 if (!aName.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetName bad name");
  myName = aName;
}




void OSD_Path::SetExtension(const TCollection_AsciiString& aName){
 if (!aName.IsAscii())
  Standard_ConstructionError::Raise("OSD_Path::SetExtension bad name");
  myExtension = aName;
}

#else

//------------------------------------------------------------------------
//-------------------  Windows NT sources for OSD_Path -------------------
//------------------------------------------------------------------------

#include <OSD_Path.hxx>
#include <Standard_ProgramError.hxx>

#include <windows.h>
#include <stdlib.h>
#include <tchar.h>

#define TEST_RAISE( type, arg ) _test_raise (  ( type ), ( arg )  )

static void __fastcall _test_raise ( OSD_SysType, Standard_CString );
static void __fastcall _remove_dup ( TCollection_AsciiString& );

OSD_Path :: OSD_Path () {

}  // end constructor ( 1 )

OSD_Path ::  OSD_Path (
              const TCollection_AsciiString& aDependentName,
              const OSD_SysType aSysType
             ) {

 Standard_Integer        i, j, len;
 static char __drive [ _MAX_DRIVE ];
 static char __dir [ _MAX_DIR ];
 static char __trek [ _MAX_DIR ];
 static char __fname [ _MAX_FNAME ];
 static char __ext [ _MAX_EXT ];

 memset(__drive, 0,_MAX_DRIVE);
 memset(__dir, 0,_MAX_DIR);
 memset(__trek, 0,_MAX_DIR);
 memset(__fname, 0,_MAX_FNAME);
 memset(__ext, 0,_MAX_EXT);
 Standard_Character      chr;

 TEST_RAISE(  aSysType, TEXT( "OSD_Path" )  );

 _splitpath (  aDependentName.ToCString (), __drive, __dir, __fname, __ext );
 
 

 myDisk      = __drive;
 myName      = __fname;
 myExtension = __ext;

 {
   TCollection_AsciiString dir   = __dir;
   len = dir.UsefullLength ();
 }

 for ( i = j = 0; i < len; ++i, ++j ) {

  chr = __dir[i];
 
  if (  chr == TEXT( '\\' ) || chr == TEXT( '/' )  )

   __trek[j] = TEXT( '|' );

  else if (  chr == TEXT( '.' )&& (i+1) < len && __dir[i+1] == TEXT( '.' )  ) {
  
   __trek[j] = TEXT( '^' );
   ++i;
  
  } else

   __trek[j] = chr;
 
 }  // end for
 __trek[j] = '\0';
 TCollection_AsciiString trek  = __trek;
 _remove_dup ( trek );
 myTrek = trek;

}  // end constructor ( 2 )

OSD_Path :: OSD_Path (
             const TCollection_AsciiString& aNode,
             const TCollection_AsciiString& aUsername,
             const TCollection_AsciiString& aPassword,
             const TCollection_AsciiString& aDisk,
             const TCollection_AsciiString& aTrek,
             const TCollection_AsciiString& aName,
             const TCollection_AsciiString& anExtension
            ) {

 SetValues ( aNode, aUsername, aPassword, aDisk, aTrek, aName, anExtension );

}  // end constructor ( 3 )

void OSD_Path :: Values (
                  TCollection_AsciiString& aNode,
                  TCollection_AsciiString& aUsername,
                  TCollection_AsciiString& aPassword,
                  TCollection_AsciiString& aDisk,
                  TCollection_AsciiString& aTrek,
                  TCollection_AsciiString& aName,
                  TCollection_AsciiString& anExtension
                 ) const {

 aNode       = myNode;
 aUsername   = myUserName;
 aPassword   = myPassword;
 aDisk       = myDisk;
 aTrek       = myTrek;
 if (!aTrek.IsEmpty() && aTrek.Value(aTrek.Length()) != '|')
   aTrek += "|" ; // (LD)
 aName       = myName;
 anExtension = myExtension;

}  // end OSD_Path :: Values

void OSD_Path :: SetValues (
                  const TCollection_AsciiString& aNode,
                  const TCollection_AsciiString& aUsername,
                  const TCollection_AsciiString& aPassword,
                  const TCollection_AsciiString& aDisk,
                  const TCollection_AsciiString& aTrek,
                  const TCollection_AsciiString& aName,
                  const TCollection_AsciiString& anExtension
                 ) {

 myNode      = aNode;
 myUserName  = aUsername;
 myPassword  = aPassword;
 myDisk      = aDisk;
 myTrek      = aTrek;
 myName      = aName;
 myExtension = anExtension;

 if (  myExtension.UsefullLength () && myExtension.Value ( 1 ) != TEXT( '.' )  )

  myExtension.Insert (  1, TEXT( '.' )  );

 _remove_dup ( myTrek );

}  // end OSD_Path :: SetValues

void OSD_Path :: SystemName (
                  TCollection_AsciiString& FullName,
                  const OSD_SysType aType
                 ) const {

 Standard_Integer        i, j;
 TCollection_AsciiString fullPath;
 static Standard_Character trek [ _MAX_PATH ];
 Standard_Character      chr;

 memset(trek,0,_MAX_PATH);

 TEST_RAISE(  aType, TEXT( "SystemName" )  );

 for ( i = j = 1; i <= myTrek.UsefullLength () && j <= _MAX_PATH; ++i, ++j ) {

  chr = myTrek.Value ( i );   

  if (  chr == TEXT( '|' )  ) {
  
   trek[j-1] = TEXT( '/' );
  
  } else if (  chr == TEXT( '^' ) && j <= _MAX_PATH - 1  ) {
   
   strcpy(&(trek[(j++) - 1]),TEXT( ".." ));

  } else

   trek[j-1] = chr ;
 
 }  //end for

 fullPath = myDisk + TCollection_AsciiString(trek);
 
 if ( trek[0] ) fullPath += TEXT( "/" );
 
 fullPath += ( myName + myExtension );

 if (  fullPath.UsefullLength () > 0  )

  FullName = fullPath;

 else

  FullName.Clear ();

}  // end OSD_Path :: SystemName

Standard_Boolean OSD_Path :: IsValid (
                              const TCollection_AsciiString& aDependentName,
                              const OSD_SysType aSysType
                             ) const {

 TEST_RAISE(  aSysType, TEXT( "IsValid" )  );

 return Standard_True;

}  // end OSD_Path :: IsValid

void OSD_Path :: UpTrek () {

 Standard_Integer pos = myTrek.SearchFromEnd (  TEXT( "|" )  );

 if ( pos == -1 )

  pos = 0;

 else if ( pos > 1 ) {

  while (  myTrek.Value ( pos ) == TEXT( '|' ) && pos != 1  ) --pos;

 }  // end if

 myTrek.Trunc ( pos );

}  // end OSD_Path :: UpTrek

void OSD_Path :: DownTrek ( const TCollection_AsciiString& aName ) {

 Standard_Integer pos = myTrek.UsefullLength ();

 if (  aName.Value ( 1 ) != TEXT( '|' )    &&
       pos                                 &&
       myTrek.Value ( pos ) != TEXT( '|' )
 )

  myTrek += TEXT( "|" );

 myTrek += aName;

 _remove_dup ( myTrek );

}  // end OSD_Path :: DownTrek

Standard_Integer OSD_Path :: TrekLength () const {

 Standard_Integer i      = 1;
 Standard_Integer retVal = 0;

 if (  myTrek.IsEmpty () || myTrek.UsefullLength () == 1 && myTrek.Value ( 1 ) == TEXT( '|' )  )

  return retVal;

 while ( Standard_True ) {
 
  if (  myTrek.Token (  TEXT( "|" ), i++  ).IsEmpty ()  )

   break;

  ++retVal;
 
 }  //end while

 return retVal;

}  // end TrekLength

void OSD_Path :: RemoveATrek ( const Standard_Integer thewhere ) {

 Standard_Integer i, j;
 Standard_Boolean flag = Standard_False;

 if (  TrekLength () < thewhere  )

  return;

 if (  myTrek.Value ( 1 ) != TEXT( '|' )  ) {
 
  flag = Standard_True;
  myTrek.Insert (  1, TEXT( '|' )  );
 
 }  // end if

 i = myTrek.Location (
             thewhere, TEXT( '|' ),
             1, myTrek.UsefullLength ()
            );

 if ( i ) {

  j = myTrek.Location (
              thewhere + 1, TEXT( '|' ),
              1, myTrek.UsefullLength ()
             );

  if ( j == 0 )

   j = myTrek.UsefullLength () + 1;

  myTrek.Remove ( i, j - i );

 }  // end if

 if ( flag )

  myTrek.Remove ( 1 );

}  // end OSD_Path :: RemoveATrek ( 1 )

void OSD_Path :: RemoveATrek ( const TCollection_AsciiString& aName ) {

 Standard_Integer        i;
 Standard_Boolean        flag = Standard_False;
 TCollection_AsciiString tmp;

 if (  myTrek.Value ( 1 ) != TEXT( '|' )  ) {
 
  flag = Standard_True;
  myTrek.Insert (  1, TEXT( '|' )  );
 
 }  // end if

 myTrek += TEXT( '|' );

 tmp = aName;

 if (  tmp.Value ( 1 ) != TEXT( '|' )  )

  tmp.Insert (  1, TEXT( '|' )  );

 if (   tmp.Value (  tmp.UsefullLength ()  ) != TEXT( '|' )   )

  tmp += TEXT( '|' );

 i = myTrek.Search ( tmp );

 if ( i != -1 )
 
  myTrek.Remove (  i + 1, tmp.UsefullLength () - 1  );

 if ( flag )

  myTrek.Remove ( 1 );
 
 if (   myTrek.Value (  myTrek.UsefullLength ()  ) == TEXT( '|' )  )

  myTrek.Trunc (  myTrek.UsefullLength () - 1  );

}  // end OSD_Path :: RemoveATrek ( 2 )

TCollection_AsciiString OSD_Path :: TrekValue (
                                     const Standard_Integer thewhere
                                    ) const {

 TCollection_AsciiString retVal;
 TCollection_AsciiString trek = myTrek;

 if (  trek.Value ( 1 ) != TEXT( '|' )  )
 
  trek.Insert (  1, TEXT( '|' )  );
 
 retVal = trek.Token (  TEXT( "|" ), thewhere  );

 return retVal;

}  // end OSD_Path :: TrekValue

void OSD_Path :: InsertATrek (
                  const TCollection_AsciiString& aName,
                  const Standard_Integer thewhere
                 ) {

 Standard_Integer        pos;
 TCollection_AsciiString tmp = aName;
 Standard_Boolean        flag = Standard_False;

 if (  myTrek.Value ( 1 ) != TEXT( '|' )  ) {
 
  flag = Standard_True;
  myTrek.Insert (  1, TEXT( '|' )  );
 
 }  // end if

 myTrek += TEXT( '|' );

 pos = myTrek.Location (
               thewhere, TEXT( '|' ),
               1, myTrek.UsefullLength ()
              );

 if ( pos ) {

  if (   tmp.Value (  tmp.UsefullLength ()  ) != TEXT( '|' )   )

   tmp += TEXT( '|' );

  myTrek.Insert ( pos + 1, tmp );

 }  // end if

 if ( flag )

  myTrek.Remove ( 1 );

 if (   myTrek.Value (  myTrek.UsefullLength ()  ) == TEXT( '|' )  )

  myTrek.Trunc (  myTrek.UsefullLength () - 1  );

 _remove_dup ( myTrek );

}  // end OSD_Path :: InsertATrek

TCollection_AsciiString OSD_Path :: Node () const {

 return myNode;

}  // end OSD_Path :: Node

TCollection_AsciiString OSD_Path :: UserName () const {

 return myUserName;

}  // end OSD_Path :: UserName

TCollection_AsciiString OSD_Path :: Password () const {

 return myPassword;

}  // end OSD_Path :: Password

TCollection_AsciiString OSD_Path :: Disk () const {

 return myDisk;

}  // end OSD_Path :: Disk

TCollection_AsciiString OSD_Path :: Trek () const {

 TCollection_AsciiString retVal ;
 retVal = myTrek ;
 if (!retVal.IsEmpty() && retVal.Value(retVal.Length()) != '|')
   retVal += "|" ;          // (LD)
 return retVal;

}  // end OSD_Path :: Trek

TCollection_AsciiString OSD_Path :: Name () const {

 return myName;

}  // end OSD_Path :: Name

TCollection_AsciiString OSD_Path :: Extension () const {

 return myExtension;

}  // end OSD_Path :: Extension

void OSD_Path :: SetNode ( const TCollection_AsciiString& aName ) {

 myNode = aName;

}  // end OSD_Path :: SetNode

void OSD_Path :: SetUserName (const TCollection_AsciiString& aName ) {

 myUserName = aName;

}  // end OSD_Path :: SetUserName

void OSD_Path :: SetPassword ( const TCollection_AsciiString& aName ) {

 myPassword = aName;

}  // end OSD_Path :: SetPassword

void OSD_Path :: SetDisk ( const TCollection_AsciiString& aName ) {

 myDisk = aName;

}  // end OSD_Path :: SetDisk

void OSD_Path :: SetTrek (const TCollection_AsciiString& aName ) {

 myTrek = aName;

 _remove_dup ( myTrek );

}  // end OSD_Path :: SetTrek

void OSD_Path :: SetName ( const TCollection_AsciiString& aName ) {

 myName = aName;

}  // end OSD_Path :: SetName

void OSD_Path :: SetExtension ( const TCollection_AsciiString& aName ) {

 myExtension = aName;

}  // end OSD_Path :: SetExtension

static void __fastcall _test_raise ( OSD_SysType type, Standard_CString str ) {

 Standard_Character buff[ 64 ];

 if ( type != OSD_Default && type != OSD_WindowsNT ) {
 
  _tcscpy (  buff, TEXT( "OSD_Path :: " )  );
  _tcscat (  buff, str );
  _tcscat (  buff, TEXT( " (): unknown system type" )  );

  Standard_ProgramError :: Raise ( buff );
 
 }  // end if

}  // end _test_raise

static void __fastcall _remove_dup ( TCollection_AsciiString& str ) {

 Standard_Integer pos = 1, orgLen, len = str.UsefullLength ();

 orgLen = len;

 while ( pos <= len ) {
 
  if (  str.Value ( pos     ) == TEXT( '|' ) && pos != len &&
        str.Value ( pos + 1 ) == TEXT( '|' ) && pos != 1
  ) {
  
   ++pos;

   while (  pos <= len && str.Value ( pos ) == TEXT( '|' )  ) str.Remove ( pos ), --len;
  
  } else

   ++pos;
 
 }  // end while

 if (  orgLen > 1 && len > 0 && str.Value ( len ) == TEXT( '|' )  ) str.Remove ( len );

 pos = 1;
 orgLen = len = str.UsefullLength ();

 while ( pos <= len ) {
 
  if (  str.Value ( pos ) == TEXT( '^' ) && pos != len && str.Value ( pos + 1 ) == TEXT( '^' )  ) {
  
   ++pos;

   while (  pos <= len && str.Value ( pos ) == TEXT( '^' )  ) str.Remove ( pos ), --len;
  
  } else

   ++pos;
 
 }  // end while

// if (  orgLen > 1 && len > 0 && str.Value ( len ) == TEXT( '^' )  ) str.Remove ( len );

}  // end _remove_dup

#endif

// ---------------------------------------------------------------------------

// Elimine les separateurs inutiles


static Standard_Integer RemoveExtraSeparator(TCollection_AsciiString& aString) {

  Standard_Integer i, j, len ;

  len = aString.Length() ;
  for (i = j = 1 ; j <= len ; i++,j++) {
      Standard_Character c = aString.Value(j) ;
      aString.SetValue(i,c) ;
      if (c == '/')
          while(j < len && aString.Value(j+1) == '/') j++ ;
  }
  len = i-1 ;
  if (aString.Value(len) == '/') len-- ;  
  aString.Trunc(len) ;
  return len ;
}

// ---------------------------------------------------------------------------

TCollection_AsciiString OSD_Path::RelativePath(
                            const TCollection_AsciiString& aDirPath,
                            const TCollection_AsciiString& aAbsFilePath)
{
  TCollection_AsciiString EmptyString = "" ;
  TCollection_AsciiString FilePath ;
  Standard_Integer len ;
  Standard_Integer i, n ;
  Standard_Boolean Wnt = 0 ;

  FilePath = aAbsFilePath ;

  if (aDirPath.Search(":") == 2) {    // Cas WNT
      Wnt = 1 ;
      if (FilePath.Search(":") != 2 || 
          UpperCase(aDirPath.Value(1)) != UpperCase(FilePath.Value(1))
      )
          return  EmptyString ;

      FilePath.ChangeAll('\\','/') ;
      if (FilePath.Search("/") != 3 )
          return  EmptyString ;
  }
  else {        // Cas Unix
      if (aDirPath.Value(1) != '/' || FilePath.Value(1) != '/')
          return  EmptyString ;
  }

  // Eliminer les separateurs redondants

  len = RemoveExtraSeparator(FilePath) ;

  if (!Wnt) {
     if (len < 2)
         return  EmptyString ;
     FilePath = FilePath.SubString(2,len) ;
  }
  TCollection_AsciiString DirToken, FileToken ;
  Standard_Boolean Sibling = 0 ;

  for (i = n = 1 ;; n++) {
      DirToken = aDirPath.Token("/\\",n) ;
      if (DirToken.IsEmpty())
          return FilePath ;

      if (!Sibling) {
          len = FilePath.Length() ;
          i = FilePath.Search("/") ;
          if (i > 0) {
              if (i == len)
                  return EmptyString ;

              FileToken = FilePath.SubString(1,i-1) ;
              if (Wnt) {
                  DirToken.UpperCase() ;
                  FileToken.UpperCase() ;
              }
              if (DirToken == FileToken) {
	          FilePath = FilePath.SubString(i+1,len) ;
                  continue ;
              }
          }
          else if (DirToken == FilePath)
              return EmptyString ;
 
          else
              Sibling = 1 ;
      }
      FilePath.Insert(1,"../") ;
  }
}
      
// ---------------------------------------------------------------------------
    
TCollection_AsciiString OSD_Path::AbsolutePath(
                            const TCollection_AsciiString& aDirPath,
                            const TCollection_AsciiString& aRelFilePath)
{
  TCollection_AsciiString EmptyString = "" ;
  if (aRelFilePath.Search("/") == 1 || aRelFilePath.Search(":") == 2)
      return aRelFilePath ;
  TCollection_AsciiString DirPath = aDirPath, RelFilePath = aRelFilePath  ;
  Standard_Integer i,len ;

  if (DirPath.Search("/") != 1 && DirPath.Search(":") != 2)
      return EmptyString ;

  if ( DirPath.Search(":") == 2)
      DirPath.ChangeAll('\\','/') ;
  RelFilePath.ChangeAll('\\','/') ;
  RemoveExtraSeparator(DirPath) ;
  len = RemoveExtraSeparator(RelFilePath) ;
  
  while (RelFilePath.Search("../") == 1) {
      if (len == 3)
	  return EmptyString ;
      RelFilePath = RelFilePath.SubString(4,len) ;
      len -= 3 ;
      if (DirPath.IsEmpty())
	  return EmptyString ;
      i = DirPath.SearchFromEnd("/") ;
      if (i < 0)
          return EmptyString ;
      DirPath.Trunc(i-1) ;
  }
  DirPath += '/' ;
  DirPath += RelFilePath ;
  return DirPath ;
}

//void OSD_Path::ExpandedName(TCollection_AsciiString& aName)
void OSD_Path::ExpandedName(TCollection_AsciiString& )
{
}

//Standard_Boolean LocateExecFile(OSD_Path& aPath)
Standard_Boolean LocateExecFile(OSD_Path& )
{
  return Standard_False ;
}
