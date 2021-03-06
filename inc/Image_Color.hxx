// Created on: 2012-07-18
// Created by: Kirill GAVRILOV
// Copyright (c) 2012 OPEN CASCADE SAS
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

#ifndef _Image_Color_H__
#define _Image_Color_H__

#include <Standard.hxx>

//! POD structure for packed RGB color value (3 bytes)
struct Image_ColorRGB
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 3;
  }

public: // access methods

  //! Alias to 1st component (red intensity).
  Standard_Byte r() const { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte g() const { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_Byte b() const { return v[2]; }

  //! Alias to 1st component (red intensity).
  Standard_Byte& r() { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte& g() { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_Byte& b() { return v[2]; }

public:

  Standard_Byte v[3];

};

//! POD structure for packed RGB color value (4 bytes with extra byte for alignment)
struct Image_ColorRGB32
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 3;
  }

  //! Alias to 1st component (red intensity).
  Standard_Byte r() const { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte g() const { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_Byte b() const { return v[2]; }

  //! Alias to 4th component (dummy).
  Standard_Byte a_() const { return v[3]; }

  //! Alias to 1st component (red intensity).
  Standard_Byte& r() { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte& g() { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_Byte& b() { return v[2]; }

  //! Alias to 4th component (dummy).
  Standard_Byte& a_() { return v[3]; }

public:

  Standard_Byte v[4];

};

//! POD structure for packed RGBA color value (4 bytes)
struct Image_ColorRGBA
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 4;
  }

  //! Alias to 1st component (red intensity).
  Standard_Byte r() const { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte g() const { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_Byte b() const { return v[2]; }

  //! Alias to 4th component (alpha value).
  Standard_Byte a() const { return v[3]; }

  //! Alias to 1st component (red intensity).
  Standard_Byte& r() { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte& g() { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_Byte& b() { return v[2]; }

  //! Alias to 4th component (alpha value).
  Standard_Byte& a() { return v[3]; }

public:

  Standard_Byte v[4];

};

//! POD structure for packed BGR color value (3 bytes)
struct Image_ColorBGR
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 3;
  }

  //! Alias to 3rd component (red intensity).
  Standard_Byte r() const { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte g() const { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_Byte b() const { return v[0]; }

  //! Alias to 3rd component (red intensity).
  Standard_Byte& r() { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte& g() { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_Byte& b() { return v[0]; }

public:

  Standard_Byte v[3];

};

//! POD structure for packed BGR color value (4 bytes with extra byte for alignment)
struct Image_ColorBGR32
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 3;
  }

  //! Alias to 3rd component (red intensity).
  Standard_Byte r() const { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte g() const { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_Byte b() const { return v[0]; }

  //! Alias to 4th component (dummy).
  Standard_Byte a_() const { return v[3]; }

  //! Alias to 3rd component (red intensity).
  Standard_Byte& r() { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte& g() { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_Byte& b() { return v[0]; }

  //! Alias to 4th component (dummy).
  Standard_Byte& a_() { return v[3]; }

public:

  Standard_Byte v[4];

};

//! POD structure for packed BGRA color value (4 bytes)
struct Image_ColorBGRA
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 4;
  }

  //! Alias to 3rd component (red intensity).
  Standard_Byte r() const { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte g() const { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_Byte b() const { return v[0]; }

  //! Alias to 4th component (alpha value).
  Standard_Byte a() const { return v[3]; }

  //! Alias to 3rd component (red intensity).
  Standard_Byte& r() { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_Byte& g() { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_Byte& b() { return v[0]; }

  //! Alias to 4th component (alpha value).
  Standard_Byte& a() { return v[3]; }

public:

  Standard_Byte v[4];

};

//! POD structure for packed float RGB color value (3 floats)
struct Image_ColorRGBF
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 3;
  }

  //! Alias to 1st component (red intensity).
  Standard_ShortReal r() const { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_ShortReal g() const { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_ShortReal b() const { return v[2]; }

  //! Alias to 1st component (red intensity).
  Standard_ShortReal& r() { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_ShortReal& g() { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_ShortReal& b() { return v[2]; }

public:

  Standard_ShortReal v[3];

};

//! POD structure for packed BGR float color value (3 floats)
struct Image_ColorBGRF
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 3;
  }

  //! Alias to 3rd component (red intensity).
  Standard_ShortReal r() const { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_ShortReal g() const { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_ShortReal b() const { return v[0]; }

  //! Alias to 3rd component (red intensity).
  Standard_ShortReal& r() { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_ShortReal& g() { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_ShortReal& b() { return v[0]; }

public:

  Standard_ShortReal v[3];

};

//! POD structure for packed RGBA color value (4 floats)
struct Image_ColorRGBAF
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 4;
  }

  //! Alias to 1st component (red intensity).
  Standard_ShortReal r() const { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_ShortReal g() const { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_ShortReal b() const { return v[2]; }

  //! Alias to 4th component (alpha value).
  Standard_ShortReal a() const { return v[3]; }

  //! Alias to 1st component (red intensity).
  Standard_ShortReal& r() { return v[0]; }

  //! Alias to 2nd component (green intensity).
  Standard_ShortReal& g() { return v[1]; }

  //! Alias to 3rd component (blue intensity).
  Standard_ShortReal& b() { return v[2]; }

  //! Alias to 4th component (alpha value).
  Standard_ShortReal& a() { return v[3]; }

public:

  Standard_ShortReal v[4];

};

//! POD structure for packed float BGRA color value (4 floats)
struct Image_ColorBGRAF
{

  //! Returns the number of components.
  static Standard_Integer Length()
  {
    return 4;
  }

  //! Alias to 3rd component (red intensity).
  Standard_ShortReal r() const { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_ShortReal g() const { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_ShortReal b() const { return v[0]; }

  //! Alias to 4th component (alpha value).
  Standard_ShortReal a() const { return v[3]; }

  //! Alias to 3rd component (red intensity).
  Standard_ShortReal& r() { return v[2]; }

  //! Alias to 2nd component (green intensity).
  Standard_ShortReal& g() { return v[1]; }

  //! Alias to 1st component (blue intensity).
  Standard_ShortReal& b() { return v[0]; }

  //! Alias to 4th component (alpha value).
  Standard_ShortReal& a() { return v[3]; }

public:

  Standard_ShortReal v[4];

};

//! Addition operator
template<typename ColorType_t>
inline ColorType_t Image_ColorSumm3 (const ColorType_t& theA, const ColorType_t& theB)
{
  ColorType_t aRes = { theA.v[0] + theB.v[0],
                       theA.v[1] + theB.v[1],
                       theA.v[2] + theB.v[2] };
  return aRes;
}

inline Image_ColorRGB operator+ (const Image_ColorRGB& theA, const Image_ColorRGB& theB)
{
  return Image_ColorSumm3 (theA, theB);
}

inline Image_ColorBGR operator+ (const Image_ColorBGR& theA, const Image_ColorBGR& theB)
{
  return Image_ColorSumm3 (theA, theB);
}

inline Image_ColorRGBF operator+ (const Image_ColorRGBF& theA, const Image_ColorRGBF& theB)
{
  return Image_ColorSumm3 (theA, theB);
}

inline Image_ColorBGRF operator+ (const Image_ColorBGRF& theA, const Image_ColorBGRF& theB)
{
  return Image_ColorSumm3 (theA, theB);
}

template<typename ColorType_t>
inline ColorType_t Image_ColorSumm4 (const ColorType_t& theA, const ColorType_t& theB)
{
  ColorType_t aRes = { theA.v[0] + theB.v[0],
                       theA.v[1] + theB.v[1],
                       theA.v[2] + theB.v[2],
                       theA.v[3] + theB.v[3] };
  return aRes;
}

inline Image_ColorRGBA operator+ (const Image_ColorRGBA& theA, const Image_ColorRGBA& theB)
{
  return Image_ColorSumm4 (theA, theB);
}

inline Image_ColorBGRA operator+ (const Image_ColorBGRA& theA, const Image_ColorBGRA& theB)
{
  return Image_ColorSumm4 (theA, theB);
}

inline Image_ColorRGB32 operator+ (const Image_ColorRGB32& theA, const Image_ColorRGB32& theB)
{
  return Image_ColorSumm4 (theA, theB);
}

inline Image_ColorBGR32 operator+ (const Image_ColorBGR32& theA, const Image_ColorBGR32& theB)
{
  return Image_ColorSumm4 (theA, theB);
}

inline Image_ColorRGBAF operator+ (const Image_ColorRGBAF& theA, const Image_ColorRGBAF& theB)
{
  return Image_ColorSumm4 (theA, theB);
}

inline Image_ColorBGRAF operator+ (const Image_ColorBGRAF& theA, const Image_ColorBGRAF& theB)
{
  return Image_ColorSumm4 (theA, theB);
}

//! Subtraction operator
template<typename ColorType_t>
inline ColorType_t Image_ColorSub3 (const ColorType_t& theA, const ColorType_t& theB)
{
  ColorType_t aRes = { theA.v[0] - theB.v[0],
                       theA.v[1] - theB.v[1],
                       theA.v[2] - theB.v[2] };
  return aRes;
}

inline Image_ColorRGB operator- (const Image_ColorRGB& theA, const Image_ColorRGB& theB)
{
  return Image_ColorSub3 (theA, theB);
}

inline Image_ColorBGR operator- (const Image_ColorBGR& theA, const Image_ColorBGR& theB)
{
  return Image_ColorSub3 (theA, theB);
}

inline Image_ColorRGBF operator- (const Image_ColorRGBF& theA, const Image_ColorRGBF& theB)
{
  return Image_ColorSub3 (theA, theB);
}

inline Image_ColorBGRF operator- (const Image_ColorBGRF& theA, const Image_ColorBGRF& theB)
{
  return Image_ColorSub3 (theA, theB);
}

template<typename ColorType_t>
inline ColorType_t Image_ColorSub4 (const ColorType_t& theA, const ColorType_t& theB)
{
  ColorType_t aRes = { theA.v[0] - theB.v[0],
                       theA.v[1] - theB.v[1],
                       theA.v[2] - theB.v[2],
                       theA.v[3] - theB.v[3] };
  return aRes;
}

inline Image_ColorRGBA operator- (const Image_ColorRGBA& theA, const Image_ColorRGBA& theB)
{
  return Image_ColorSub4 (theA, theB);
}

inline Image_ColorBGRA operator- (const Image_ColorBGRA& theA, const Image_ColorBGRA& theB)
{
  return Image_ColorSub4 (theA, theB);
}

inline Image_ColorRGB32 operator- (const Image_ColorRGB32& theA, const Image_ColorRGB32& theB)
{
  return Image_ColorSub4 (theA, theB);
}

inline Image_ColorBGR32 operator- (const Image_ColorBGR32& theA, const Image_ColorBGR32& theB)
{
  return Image_ColorSub4 (theA, theB);
}

inline Image_ColorRGBAF operator- (const Image_ColorRGBAF& theA, const Image_ColorRGBAF& theB)
{
  return Image_ColorSub4 (theA, theB);
}

inline Image_ColorBGRAF operator- (const Image_ColorBGRAF& theA, const Image_ColorBGRAF& theB)
{
  return Image_ColorSub4 (theA, theB);
}

#endif // _Image_Color_H__
