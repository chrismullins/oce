// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Image_Image_HeaderFile
#define _Image_Image_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Image_Image_HeaderFile
#include <Handle_Image_Image.hxx>
#endif

#ifndef _Handle_Standard_Type_HeaderFile
#include <Handle_Standard_Type.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Quantity_HArray1OfColor_HeaderFile
#include <Handle_Quantity_HArray1OfColor.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Image_TypeOfImage_HeaderFile
#include <Image_TypeOfImage.hxx>
#endif
#ifndef _Image_PixelAddress_HeaderFile
#include <Image_PixelAddress.hxx>
#endif
#ifndef _Image_FlipType_HeaderFile
#include <Image_FlipType.hxx>
#endif
class Standard_Type;
class Quantity_Color;
class Quantity_HArray1OfColor;
class Quantity_Array1OfColor;
class Aspect_Pixel;


//! This class defined the general behavior of an Image from <br>
//!		Package Image . <br>
class Image_Image : public MMgt_TShared {

public:

  //! Image destructor. <br>
  Standard_EXPORT   virtual  void Destroy() ;
~Image_Image()
{
  Destroy();
}
  //! Returns True if me->Pixel(X,Y) is equal to <br>
//!	    anotherImage->Pixel(anotherX,anotherY) <br>
  Standard_EXPORT   virtual  Standard_Boolean isSamePixel(const Standard_Integer X,const Standard_Integer Y,const Handle(Image_Image)& anotherImage,const Standard_Integer anotherX,const Standard_Integer anotherY) const = 0;
  //! Returns the Color of an Image Pixel. <br>
  Standard_EXPORT   virtual const Quantity_Color& PixelColor(const Standard_Integer X,const Standard_Integer Y) const = 0;
  //! Returns the Color of an Image Pixel Row. <br>
  Standard_EXPORT   virtual  Handle_Quantity_HArray1OfColor RowColor(const Standard_Integer Y) const;
  //! Stores the Color of an Image Pixel Row in aArray1. <br>
  Standard_EXPORT   virtual  void RowColor(const Standard_Integer Y,Quantity_Array1OfColor& aArray1) const;
  //! Returns the Image Pixel Type. <br>
  Standard_EXPORT     Handle_Standard_Type PixelType() const;
  //! Returns the Image size in Pixel unit ( width*height) . <br>
  Standard_EXPORT     Standard_Integer Size() const;
  //! Duplicates an Image. <br>
  Standard_EXPORT   virtual  void InternalDup(const Handle(Image_Image)& anImage)  = 0;
  //! Sets Image origin, for Rotation, copy between image ... <br>
//!		Image origin is on the TOP LEFT . Y axis goes TOP to <br>
//!		DOWN , X axis goes LEFT to RIGHT. <br>
  Standard_EXPORT   virtual  void SetOrigin(const Standard_Integer x,const Standard_Integer y)  = 0;
  //! Returns the lower X Image coordinate ( X Origin ). <br>
  Standard_EXPORT   virtual  Standard_Integer LowerX() const = 0;
  //! Returns the upper X Image coordinate <br>
//!		( X Origin + Image width - 1 ). <br>
  Standard_EXPORT   virtual  Standard_Integer UpperX() const = 0;
  //! Returns the Image width. <br>
  Standard_EXPORT   virtual  Standard_Integer Width() const = 0;
  //! Returns the lower Y Image coordinate ( Y Origin ). <br>
  Standard_EXPORT   virtual  Standard_Integer LowerY() const = 0;
  //! Returns the upper Y Image coordinate <br>
//!		( Y Origin + Image height - 1 ). <br>
  Standard_EXPORT   virtual  Standard_Integer UpperY() const = 0;
  //! Returns the Image height. <br>
  Standard_EXPORT   virtual  Standard_Integer Height() const = 0;
  //! Resize an Image. Image Pixel are left unchanged at there <br>
//!	      absolute positon. Resulting Image can be clipped. <br>
//!	newLowerX = LowerX()*XScale + XOffset <br>
//!	newLowerY = LowerY()*YScale + YOffset <br>
//!	newUpperX = UpperX()*XScale + XOffset <br>
//!	newUpperY = UpperY()*YScale + YOffset <br>
//!	newWidth  = Width() *XScale <br>
//!	newHeight = Height()*YScale <br>
  Standard_EXPORT   virtual  void Resize(const Standard_Real XOffset,const Standard_Real XScale,const Standard_Real YOffset,const Standard_Real YScale)  = 0;
  //! Returns the ImageType TOI_ColorImage or TOI_PseudoColorImage <br>
  Standard_EXPORT   virtual  Image_TypeOfImage Type() const = 0;
  //! Get the Image Pixel Value at X,Y coordinate in aPixel. <br>
//! Warning: aPixel must have the same type than Image Pixel. <br>
  Standard_EXPORT   virtual  void Pixel(const Standard_Integer X,const Standard_Integer Y,Aspect_Pixel& aPixel) const = 0;
  //! Store aPixel in the Image  at X,Y coordinate . <br>
//! Warning: aPixel must have the same type than Image Pixel. <br>
  Standard_EXPORT   virtual  void SetPixel(const Standard_Integer X,const Standard_Integer Y,const Aspect_Pixel& aPixel)  = 0;
  //! Get the Image Pixel Value at X,Y coordinate in aPixel. <br>
//! Warning: aPixel must have the same type than Image Pixel. <br>
  Standard_EXPORT   virtual  void Pixel(const Standard_Integer X,const Standard_Integer Y,Image_PixelAddress& aPixel) const = 0;
  //! Store aPixel in the Image  at X,Y coordinate . <br>
//! Warning: aPixel must have the same type than Image Pixel. <br>
  Standard_EXPORT   virtual  void SetPixel(const Standard_Integer X,const Standard_Integer Y,const Image_PixelAddress& aPixel)  = 0;
  //! Transpose an Image( flipping across horizontal axis or <br>
//!		vertical axis, or across diagonal... ) <br>
//!	    This geometric transformation preserves all Image Pixels. <br>
//!	    We don't need to interpolate pixels . <br>
//!	    Warning : Image size change during Transpose. <br>
  Standard_EXPORT   virtual  void Transpose(const Image_FlipType aType)  = 0;
  //! Extract a SubImage starting at coordinate X,Y <br>
//!		to (X+Width-1),(Y+Height-1). <br>
//!	    Warning : the Image size and origin change, new origin <br>
//!	    is X,Y ; new size is Width,Height. <br>
  Standard_EXPORT   virtual  void Clip(const Standard_Integer X,const Standard_Integer Y,const Standard_Integer Width,const Standard_Integer Height)  = 0;
  //! Translate an Image XShift pixel Right, YShift Down . <br>
//!	    Shift parameter are Integer value. <br>
  Standard_EXPORT   virtual  void Shift(const Standard_Integer XShift,const Standard_Integer YShift)  = 0;
  //! Fill me with SrcImage. SrcImage pixel are copied starting <br>
//!	     at SrcImage->LowerX(),SrcImage->LowerY() in MyPixelField. <br>
//!	     SrcImage Pixel are clipped outside <me>. <br>
  Standard_EXPORT   virtual  void Fill(const Handle(Image_Image)& SrcImage)  = 0;
  //! Fill me with a SubImage of SrcImage starting from <br>
//!	    SrcX, SrcY to (SrcX+SrcWidth-1),(SrcY+SrcHeight-1) in <br>
//!	    Src Image coordinate. SrcImage SubImage pixels are copied <br>
//!	    starting at X,Y in MyPixelField. <br>
//!	    SrcImage Pixel are clipped outside <me>. <br>
  Standard_EXPORT   virtual  void Fill(const Handle(Image_Image)& SrcImage,const Standard_Integer SrcX,const Standard_Integer SrcY,const Standard_Integer SrcWidth,const Standard_Integer SrcHeight,const Standard_Integer X,const Standard_Integer Y)  = 0;
  //! Fill the entire Image with the BackgroundPixel. <br>
  Standard_EXPORT   virtual  void Clear()  = 0;
  //! Duplicate an Image. <br>
  Standard_EXPORT   virtual  Handle_Image_Image Dup() const = 0;
  //! Debug <br>
  Standard_EXPORT   virtual  void Dump() const = 0;



  DEFINE_STANDARD_RTTI(Image_Image)

protected:

  //! Image constructor ,initialise the Image PixelType. <br>
  Standard_EXPORT   Image_Image(const Handle(Standard_Type)& aPixelType);



private: 


Handle_Standard_Type myPixelType;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
