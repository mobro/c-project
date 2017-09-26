//=============================================================================
// Copyright (c) 
// Project: 
//-----------------------------------------------------------------------------
//! @file
//! @brief Short description of this source file: Safe multiplication
//!
//! @version
//! $Revision: 22 $
//! $Date: 2015-02-12 10:54:56 +0100 (Do, 12 Feb 2015) $
//!
//! Detailed description of the the content of this source file
//! ...
//!
//! @see @ref Section_SectionName for descriptive information.
//! @see @ref FW_MULTIPLICATION.h for interface description.
//-----------------------------------------------------------------------------
// Notes
// Initial author: 
// $Author: 
//=============================================================================

// Includes *******************************************************************
#include <assert.h>

#include <fos/fw_typedef.h>
#include <fos/fw_macros.h>
  

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

//-----------------------------------------------------------------------------
//! Safe multiplication of signed long parameters.
//!
//!
//! @param [in] i32FactA: Factor A
//!
//! @param [in] i32FactB: Factor B
//!
//! @param [out] po32Dest: Product of the multiplication
//!
//! @return @todo RETURN_VALUE DESCRIPTION / NONE
//!
//-----------------------------------------------------------------------------
INT32 umult32(INT32 i32FactA, INT32 i32FactB, INT32* pi32Dest)
{
  INT32 i32Check = TRUE;
  UINT64 u64Product = (UINT64)(i32FactA)*(UINT64)(i32FactB);

  assert(NULL!=pi32Dest);

  if(u64Product>0xFFFFFFFF)
  {
    i32Check = FALSE;
  }

  *pi32Dest=(INT32)(u64Product&0xFFFFFFFF);

  return i32Check;
}


