//=============================================================================
// Project: fw
//-----------------------------------------------------------------------------
//! @file
//! @brief Short description of this include file: Common error codes
//!
//! @version
//! $Revision: 29 $
//! $Date: 2015-04-15 15:11:48 +0200 (Mi, 15 Apr 2015) $
//!
//! Detailed description of the interface of the content of this include file
//! ...
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
//! @see @ref error.h for interface description
//! @see @ref ERROR.c for implementation details.
//-----------------------------------------------------------------------------

#ifndef ERROR__H__
#define ERROR__H__



#ifndef _RESULT_DEFINED
#error RESULT is not defined, fw_typedef.h is probably not included
#endif

// Includes *******************************************************************

// Defines ********************************************************************

#ifdef SUCCEEDED
#undef SUCCEEDED
#endif
//#define SUCCEEDED(s) ((RESULT)(s) <= 1)
#define SUCCEEDED(s)  (s == S_OK) ? (TRUE) : (FALSE) 

#ifdef FAILED
#undef FAILED
#endif
#define FAILED(s) ((RESULT)(s) > 1)

#ifdef IS_ERROR
#undef IS_ERROR
#endif
#define IS_ERROR(s) ((RESULT)(s) > 1)

#undef S_OK
#define S_OK ((RESULT)0)

#undef S_FALSE
#define S_FALSE ((RESULT)1)

#undef E_FAIL
#define E_FAIL ((RESULT)-1)

#undef E_INVALIDARG
#define E_INVALIDARG ((RESULT)-2)

#undef E_ABORT
#define E_ABORT ((RESULT)-3)

#undef E_ACCESSDENIED
#define E_ACCESSDENIED ((RESULT)-4)

#undef E_OUTOFMEMORY
#define E_OUTOFMEMORY ((RESULT)-5)

#undef E_POINTER
#define E_POINTER ((RESULT)-6)

#undef E_HANDLE
#define E_HANDLE ((RESULT)-7)

#undef E_NOTIMPL
#define E_NOTIMPL ((RESULT)-8)

#undef E_UNEXPECTED
#define E_UNEXPECTED ((RESULT)-9)

#undef STG_E_MEDIUMFULL
#define STG_E_MEDIUMFULL ((RESULT)-10)

#undef STG_E_READFAULT
#define STG_E_READFAULT ((RESULT)-11)

#undef E_PENDING
#define E_PENDING ((RESULT)-12)

//! Error codes for underrange, overrange and defect coding of measurement values
#define ERROR_VALUE_DEFECT ((RESULT)0x06E9U)
#define ERROR_VALUE_OVERRANGE ((RESULT)0x06EBU)
#define ERROR_VALUE_UNDERRANGE ((RESULT)0x06EAU)

// Macros *********************************************************************

// See Defines section

// Type definitions ***********************************************************

// Prototypes *****************************************************************
// No Doxygen comment necessary here,  description will be placed before function
// definition.

// Constants ******************************************************************

// Variables ******************************************************************



#endif // of ERROR__H__

