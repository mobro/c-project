//=============================================================================
// Project: fw
//-----------------------------------------------------------------------------
//! @file
//! @brief Short description of this include file: Typedef header
//!
//! @version
//! $Revision: 29 $
//! $Date: 2015-04-15 15:11:48 +0200 (Mi, 15 Apr 2015) $
//!
//! Detailed description of the interface of the content of this include file
//! Type definition of the c types 
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
//! @see @ref fw_typedef.h for interface description
//! @see @ref FW_TYPEDEF.c for implementation details.
//-----------------------------------------------------------------------------

#ifndef TYPEDEF__H__
#define TYPEDEF__H__

// Includes *******************************************************************
//! Attention this header comes from the application
#include <fos/config.h>

// Defines ********************************************************************

#ifndef CONF_EN_8BIT_RESULT
  #error Configuration variable CONF_EN_8BIT_HRESULT missing in config.h
#endif

#ifndef CONF_EN_16BIT_RESULT
  #error Configuration variable CONF_EN_16BIT_HRESULT missing in config.h
#endif

#ifndef CONF_EN_32BIT_RESULT
  #error Configuration variable CONF_EN_32BIT_HRESULT missing in config.h
#endif

//! bool
#ifndef _BOOL_DEFINED
#define _BOOL_DEFINED
  typedef int BOOL;
#endif

//! 8-bit integer datatypes.
#ifndef _BYTE_DEFINED_INC
  #define _BYTE_DEFINED_INC
  typedef signed char CHAR;
  typedef unsigned char BYTE;
  typedef signed char INT8;
  typedef unsigned char UINT8;
#endif

//! 16-bit integer datatypes.
#ifndef _WORD_DEFINED_INC
#define _WORD_DEFINED_INC
  typedef signed short INT16;
  typedef unsigned short UINT16;
#endif

//! 32-bit integer datatypes
#ifndef _DWORD_DEFINED_INC
#define _DWORD_DEFINED_INC
  typedef signed long INT32;
  typedef unsigned long UINT32;
#endif

//! 64-bit integer datatypes
#ifndef _DDWORD_DEFINED_INC
#define _DDWORD_DEFINED_INC
  typedef signed long long INT64;
  typedef unsigned long long UINT64;
#endif

//! 32-bit float datatypes
#ifndef _FLOAT32_DEFINED_INC
#define _FLOAT32_DEFINED_INC
  typedef float FLOAT32;
#endif

//! 64-bit float datatypes
#ifndef _FLOAT64_DEFINED_INC
#define _FLOAT64_DEFINED_INC
  typedef double FLOAT64;
#endif

//! HRESULT definition
#ifndef _RESULT_DEFINED
  #define _RESULT_DEFINED
  #if(CONF_EN_8BIT_RESULT)
  //! 8 bit special definition of RESULT
    typedef INT8 RESULT;
  #elif(CONF_EN_16BIT_RESULT)
  //! 16 bit special definition of RESULT
    typedef INT16 RESULT;
  #elif(CONF_EN_32BIT_RESULT)
  //! 32 bit special definition of RESULT
    typedef INT32 RESULT;
  #endif
#endif

#define PTRPARAM

// Macros *********************************************************************

// See Defines section

// Type definitions ***********************************************************

// Prototypes *****************************************************************
// No Doxygen comment necessary here,  description will be placed before function
// definition.

// Constants ******************************************************************

// Variables ******************************************************************



#endif // of TYPEDEF__H__

