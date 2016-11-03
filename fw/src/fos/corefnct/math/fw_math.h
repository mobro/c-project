//=============================================================================
// Copyright (c) SICK AG - DIV07 
// Project: fw
//-----------------------------------------------------------------------------
//! @file
//! @brief Short description of this include file: Mathematical functions
//!
//! @version
//! $Revision: 29 $
//! $Date: 2015-04-15 15:11:48 +0200 (Mi, 15 Apr 2015) $
//!
//! Detailed description of the interface of the content of this include file
//! This interface provides access to various mathematical routines used in 
//! SICK devices.
//!
//! @see @ref Section_ModuleName for descriptive informations.
//! @see @ref ModuleName.c for implementation details.
//-----------------------------------------------------------------------------
// Notes
// Initial author: Benjamin Hug (hugbe), benjaminhug@sick.de
// $Author: hugbe $ (last change)
//=============================================================================

//--------------------------------- -------------------------------------------
//! @addtogroup Group_GroupName Group Title
//! @section Section_SectionName Section Title
//! Here is the section text to be placed. Several sections (i.e header files)
//! can be assigned to the same group but different sections. The groups are listed
//! by the modules tab of the HTML ouput
//!
//! @see @ref fw_smath.h for interface description
//! @see @ref FW_SMATH.c for implementation details.
//-----------------------------------------------------------------------------

#ifndef FW_SMATH__H__
#define FW_SMATH__H__

// Includes *******************************************************************
// Framework
#include <fos/fw_typedef.h>
#include <fos/fw_macros.h>
#include <fos/fw_typedef.h>
#include <fos/fw_error.h>

// Defines ********************************************************************

//! Number pi.
#define SMATH_CONST_PI 3.1415926535897932385

//! 2 * pi
#define SMATH_CONST_2PI 6.2831853071795864769

//! pi / 2
#define SMATH_CONST_PI_2 1.5707963267948966192

//! pi / 4
#define SMATH_CONST_PI_4 0.7853981633974483096

//! 3/4 * pi
#define SMATH_CONST_3PI_4 2.3561944901923448370

//! 1 / pi
#define SMATH_CONST_1_PI 0.3183098861837906715

//! 2 / pi
#define SMATH_CONST_2_PI 0.6366197723675813431

//! 1 / sqrt(pi)
#define SMATH_CONST_2_SQRTPI 1.1283791670955125739

//! sqrt(pi)
#define SMATH_CONST_SQRTPI 1.7724538509055160279

//! sqrt(1/2)
#define SMATH_CONST_SQRT1_2 0.7071067811865475244

//! sqrt(2)
#define SMATH_CONST_SQRT2 1.4142135623730950488

//! sqrt(3)
#define SMATH_CONST_SQRT3 1.7320508075688772935

//! sqrt(5)
#define SMATH_CONST_SQRT5 2.2360679774997896964

//! Eularian number e
#define SMATH_CONST_E 2.7182818284590452354

//! ln(2) natural logarithm
#define SMATH_CONST_LN2 0.6931471805599453094

//! ln(10) natural logarithm
#define SMATH_CONST_LN10 2.3025850929940456840

//! log(2) logarithm with base 10
#define SMATH_CONST_LOG2 0.3010299956639811952

//! log(e) logarithm with base 10
#define SMATH_CONST_LOGE 0.4342944819032518277

//! lb(10) logarithm with base 2
#define SMATH_CONST_LB10 3.3219280948873623480

//! lb(e) logarithm with base 2
#define SMATH_CONST_LBE 1.4426950408889634074


//! Polynom for CRC calculation.
#define CRC_POLY        (UINT16)0x90D9    // 0xC86C << 1 + 1
//! Initial value for CRC.
#define CRC_INIT        (UINT16)0x0000
//! Mask to get CRC from final remainder.
#define CRC_FINAL       (UINT16)0x00FF
//! Width of CRC.
#define CRC_WIDTH       (16 * sizeof(UINT8))


// Macros *********************************************************************

// See Defines section

// Type definitions ***********************************************************

// Prototypes *****************************************************************
INT32 umult32(INT32 i32FactA, INT32 i32FactB, INT32* pi32Dest);
UINT16 STDLib_CalcCRC(BYTE *auc8pMessage, UINT16 u16Length);
UINT8 UTIL_u8CsCalculate(UINT8 u8Length, BYTE* au8pBuffer);

//! Calculate xor checksum
RESULT xorcs_CheckCs(const UINT8 aui8Data[], const UINT32 ui32Size);
UINT8 xorcs_CalcCs(const UINT8 aui8Data[], const UINT32 ui32Size);

//! Memory copy, set and compare functions
UINT32 util_memcpy_safe(void PTRPARAM *pTargt, const void PTRPARAM *pSource, const UINT32 ui32TargetBufLen, const UINT32 ui32Length);
UINT32 util_memset_safe(void PTRPARAM *pTargt, const UINT8 ui8Value, const UINT32 ui32TargetBufLen, const UINT32 ui32Length);
BOOL util_memcmp(const void PTRPARAM *pBuffer1, const void PTRPARAM *pBuffer2, const UINT32 ui32Length);


// Constants ******************************************************************

// Variables ******************************************************************



#endif // of FW_SMATH__H__

