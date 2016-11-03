//=============================================================================
// Copyright (c) SICK AG - DIV07
// Project: AFx
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
//! @see @ref FW_XORCS.h for interface description.
//-----------------------------------------------------------------------------
// Notes
// Initial author: Benjamin Hug (hugbe), benjaminhug@sick.de
// $Author:  $(last change)
//=============================================================================

// Includes *******************************************************************


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

// Includes
#include <fos/corefnct/smath/fw_smath.h>

// functions local to this file

// variables local to this file

RESULT xorcs_CheckCs(const UINT8 aui8Data[], const UINT32 ui32Size)
{
  RESULT res = E_FAIL;
  UINT8 u8Cs = 0;
  UINT8 u8Cnt = 0;

  for (u8Cnt = 0; u8Cnt < ui32Size; u8Cnt++)
  {
    u8Cs ^= aui8Data[u8Cnt];
  }

  if (0 == u8Cs)
  {
    res = S_OK;
  }

  return res;
}


UINT8 xorcs_CalcCs(const UINT8 aui8Data[], const UINT32 ui32Size)
{
  UINT8 u8Cnt = 0;
  UINT8 u8Checksum = 0;

  for (u8Cnt = 0; u8Cnt < (ui32Size - 1); u8Cnt++)
  {
    u8Checksum ^= aui8Data[u8Cnt];
  }

  return u8Checksum;
}


