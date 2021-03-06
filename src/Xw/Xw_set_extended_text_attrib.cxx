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


#include <Xw_Extension.h>

/* ifdef then trace on */
#ifdef TRACE
#define TRACE_SET_EXTENDED_TEXT_ATTRIB
#endif

/*
   XW_ATTRIB Xw_set_extended_text_attrib (awindow,color,font,mode,attribs):
   XW_EXT_WINDOW *awindow
   int color ;		Color index to used 0 >= x < MAXCOLOR
   int font ;		Font index to used 0 >= x < MAXFONT
   DRAWMODE mode ;	Draw Mode must be one of DRAWMODE enum 
   EXTENDEDTEXT *attrib ;	Text attributes descriptor

	Set Text Color,Font and extended current graphic attrib .

        Returns Selected Text Attribute Index if successful
        Returns 0 if Bad Color,Font Index or extended attributes

*/

#ifdef XW_PROTOTYPE
XW_ATTRIB Xw_set_extended_text_attrib (void *awindow,int color,int font,XW_DRAWMODE mode,XW_EXTENDEDTEXT *attribs)
#else
XW_ATTRIB Xw_set_extended_text_attrib (awindow,color,font,mode,attribs)
void *awindow;
int color,font ;
XW_DRAWMODE mode ;
XW_EXTENDEDTEXT *attribs;
#endif /*XW_PROTOTYPE*/
{
XW_EXT_WINDOW *pwindow = (XW_EXT_WINDOW*)awindow;
XGCValues gc_values ;
XW_ATTRIB code ;
int i,j,k,function,mask= 0,type = 0 ;
unsigned long planemask,hcolor ;

        if( !Xw_isdefine_window(pwindow) ) {
            /*ERROR*Bad EXT_WINDOW Address*/
            Xw_set_error(24,"Xw_set_extended_text_attrib",pwindow) ;
            return (0) ;
        }

	if( _BINDEX > 0 ) return (1) ;

        if ( !Xw_isdefine_color(_COLORMAP,color) ) {
            /*ERROR*Bad Defined Color*/
            Xw_set_error(41,"Xw_set_extended_text_attrib",&color) ;
            return (0) ;
        }

	if ( !Xw_isdefine_font(_FONTMAP,font) ) {
	    /*WARNING*Bad Defined Font*/
	    Xw_set_error(43,"Xw_set_extended_text_attrib",&font) ;
	    font = 0 ;
	}

	if( !_FONTMAP || !_FONTMAP->fonts[font] ) font = 0 ;

	code = QGCODE(color,type,font,mode) ;

        if( code == pwindow->qgtext[pwindow->textindex].code ) {
                                /* The last index computed is already set*/
            pwindow->qgtext[pwindow->textindex].count++ ;
            return (pwindow->textindex+1) ;
        }
 
        for( i=j=0,k=MAXQG ; i<MAXQG ; i++ ) {
            if( code == pwindow->qgtext[i].code ) k = i ;
            if( pwindow->qgtext[i].count < pwindow->qgtext[j].count ) j = i;
        }
 
        if( k < MAXQG ) {
                                        /* A GC index already exist,use it */
            pwindow->textindex = k ;
            pwindow->qgtext[k].count++ ;
            return (k+1) ;
	}
 
	pwindow->textindex = j ;
	pwindow->qgtext[j].count = 1 ;

        Xw_get_color_attrib(pwindow,mode,color,&hcolor,&function,&planemask); 
        if( mode != QGMODE(pwindow->qgtext[j].code) ) {
            mask |= GCFunction | GCPlaneMask | GCForeground ;
            gc_values.function = function ;
            gc_values.plane_mask = planemask ;
	    gc_values.foreground = hcolor ;
        } else if( color != QGCOLOR(pwindow->qgtext[j].code) ) {
	    mask |= GCForeground;
	    gc_values.foreground = hcolor ;
	}

	if( font != QGFONT(pwindow->qgtext[j].code) ) {
	    if( _FONTMAP && _FONTMAP->fonts[font] ) {
 	        mask |= GCFont ;
	        gc_values.font = _FONTMAP->fonts[font]->fid ;
	    }
	}

/*
	the extended text attribs will be treated hear more later
	by using XFLD fonts if any
*/

	k = j+1 ;

	if( mask ) {	
	    XChangeGC(_DISPLAY,pwindow->qgtext[j].gc,mask,&gc_values) ;
            pwindow->qgtext[j].code = code ; 

#ifdef  TRACE_SET_EXTENDED_TEXT_ATTRIB
if( Xw_get_trace() > 1 ) {
    printf(" %d = Xw_set_extended_text_attrib(%lx,%d,%d,%d,%lx)\n",
				k,(long ) pwindow,color,font,mode,(long ) attribs) ;
}
#endif
	}

	return (k) ;	
}
