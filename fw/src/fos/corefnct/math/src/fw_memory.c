//=============================================================================
// Copyright (c) 
// Project: 
//-----------------------------------------------------------------------------
//! @file
//! @brief Short description of this source file: 
//!
//! @version
//! $Revision: $
//! $Date: $
//!
//! Detailed description of the the content of this source file
//! ...
//!
//! @see @ref Section_SectionName for descriptive information.
//! @see @ref FW_MEMORY.h for interface description.
//-----------------------------------------------------------------------------
// Notes
// Initial author: 
// $Author:  $(last change)
//=============================================================================

// Includes *******************************************************************
#include <fos/corefnct/smath/fw_smath.h>

// Defines ********************************************************************


// Macros *********************************************************************


// Type definitions ***********************************************************


// Prototypes *****************************************************************
// No Doxygen comment necessary here, description will be placed before function
// definition.


// Constants ******************************************************************
//! One-liner to explain the following constant.


// Variables ******************************************************************
//! Brief description of the variable.


// Functions ******************************************************************

UINT32 util_memcpy_safe(void PTRPARAM * pTargt, const void PTRPARAM * pSource, const UINT32 ui32TargetBufLen, const UINT32 ui32Length)
{
  UINT32 ui32Done = 0;

  if (ui32Length <= ui32TargetBufLen)
  {
    if ((NULL != pTargt) && (NULL != pSource))
    {
      while (ui32Done < ui32Length)
      {
        ((UINT8*)pTargt)[ui32Done] = ((UINT8*)pSource)[ui32Done];
        ui32Done++;
      }
    }
  }

  return ui32Done;
}

UINT32 util_memset_safe(void PTRPARAM * pTargt, const UINT8 ui8Value, const UINT32 ui32TargetBufLen, const UINT32 ui32Length)
{
  UINT32 ui32Done = 0;

  if (ui32Length <= ui32TargetBufLen)
  {
    if (NULL != pTargt)
    {
      while (ui32Done < ui32Length)
      {
        ((UINT8*)pTargt)[ui32Done] = ui8Value;
        ui32Done++;
      }
    }
  }

  return ui32Done;
}

BOOL util_memcmp(const void PTRPARAM * pBuffer1, const void PTRPARAM *  pBuffer2, const UINT32 ui32Length)
{
  BOOL res = TRUE;
  UINT32 ui32Done = 0;

  if ((NULL != pBuffer1) && (NULL != pBuffer2))
  {
    if (ui32Length > 0)
    {
      while ((ui32Done < ui32Length) && (TRUE == res))
      {
        if (((UINT8 PTRPARAM *)pBuffer1)[ui32Done] != ((UINT8 PTRPARAM *)pBuffer2)[ui32Done])
        {
          res = FALSE;
        }
        ui32Done++;
      }
    }
    else
    {
      res = FALSE;
    }
  }

  return res;
}


