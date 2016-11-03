//=============================================================================
// Project: fw
//-----------------------------------------------------------------------------
//! @file
//! @brief Short description of this include file: Macros
//!
//! @version
//! $Revision: 29 $
//! $Date: 2015-04-15 15:11:48 +0200 (Mi, 15 Apr 2015) $
//!
//! Detailed description of the interface of the content of this include file
//! Define of macros often used in projects.
//!
//! @see @ref Section_ModuleName for descriptive informations.
//! @see @ref ModuleName.c for implementation details.
//-----------------------------------------------------------------------------
// Notes
//=============================================================================

//--------------------------------- -------------------------------------------
//! @addtogroup Group_GroupName Group Title
//! @section Section_SectionName Section Title
//! Here is the section text to be placed. Several sections (i.e header files)
//! can be assigned to the same group but different sections. The groups are listed
//! by the modules tab of the HTML ouput
//!
//! @see @ref fw_macros.h for interface description
//! @see @ref FW_MACROS.c for implementation details.
//-----------------------------------------------------------------------------

#ifndef MACROS__H__
#define MACROS__H__

// Includes *******************************************************************

// Defines ********************************************************************


// Macros *********************************************************************

//! BOOLEAN values, true and false.
#ifndef TRUE
  #define TRUE 1
  #define FALSE 0
#endif

//! Define the null pointer constant 
#ifndef NULL
  #define NULL 0L 
#endif

//! Define ON and OFF 
#ifndef ON
  #define ON 1
  #define OFF 0
#endif

//! LONIBBLE macro to determine the low 4 bits of BYTE b.
#ifndef LONIBBLE
  #define LONIBBLE(b) ((BYTE)(b & 0x0FU))
#endif

//! HINIBBLE macro to determine the high 4 bits of BYTE b.
#ifndef HINIBBLE
  #define HINIBBLE(b) ((BYTE) b >> 4U)
#endif

//! MAKEBYTE macro to build a BYTE from low 4 bits and the high 4 bits.
#ifndef MAKEBYTE
  #define MAKEBYTE(low, high) (((BYTE)low & 0x0FU) | ((BYTE)high << 4U)) 
#endif

//! LOBYTE macro to determine the low BYTE of the UINT16 w.
#ifndef LOBYTE
  #define LOBYTE(w) ((BYTE)(w)) 
#endif

//! HIBYTE macro to determine the high BYTE of the UINT16 w.
#ifndef HIBYTE
  #define HIBYTE(w) ((BYTE)(((UINT16)(w) >> 8U) & 0x00FFU))
#endif

//! MAKEUINT16  macro to build a UINT16 from low BYTE and the high BYTE.
#ifndef MAKEUINT16
  #define MAKEUINT16(low, high) ((UINT16)(((BYTE)(low)) | (((UINT16)((BYTE)(high))) << 8U)))
#endif

//! LOUINT16  macro to determine the low UINT16 of the UINT32 dw.
#ifndef LOUINT16
  #define LOUINT16(dw) ((UINT16)(UINT32)(dw))
#endif

//! HIUINT16 macro to determine the high UINT16 of the UINT32 dw.
#ifndef HIUINT16
  #define HIUINT16(dw) ((UINT16)((((UINT32)(dw)) >> 16UL) & 0x0000FFFFUL))
#endif

//! MAKELONG macro to build a UINT32 from low UINT16 and the high UINT16.
#ifndef MAKELONG
  #define MAKELONG(low, high) ((UINT32)(((UINT16)(low)) | (((UINT32)((UINT16)(high))) << 16U)))
#endif

//! SWAPW macro to swap high and low BYTE of a UINT16 variable. 
#ifndef SWAPW
  #define SWAPW(w) ((w << 8U) | (w >> 8U))
#endif

//! SWAPL macro to swap byte order of a UINT32 variable.
//! e.g. 0x12345678UL is transformed to 0x78563412UL.
#ifndef SWAPL
  #define SWAPL(l) ((l << 24U) | ((l & 0xff00UL) << 8U) | ((l & 0xff0000UL) >> 8U) | (l >> 24U))
#endif

//!  max macro to determine the maximum value. 
#ifndef MAX
  #define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

//! min macro to determine the minimun value. 
#ifndef MIN
  #define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

//! DECLARE_DBG_VAR is a macro to define a variable that is only available in debug mode
//! FETCH_DBG_RESULT is a macro to fetch a result and store it in a variable that is only
//! available in debug mode (NDEBUG not defined)
#ifndef NDEBUG
  #define DECLARE_DBG_VAR(d) d
  #define FETCH_DBG_RESULT(v,f) v = f
#else
  #define DECLARE_DBG_VAR(d) ((void)0)
  #define FETCH_DBG_RESULT(v,f) f
#endif

// See Defines section

// Type definitions ***********************************************************

// Prototypes *****************************************************************
// No Doxygen comment necessary here,  description will be placed before function
// definition.

// Constants ******************************************************************

// Variables ******************************************************************



#endif // of MACROS__H__

