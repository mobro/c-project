//=============================================================================
// Copyright (c) 
// Project: fw
//-----------------------------------------------------------------------------
//! @file
//! @brief Short description of this source file: Calculation of checksum
//!
//! @version
//! $Revision: 29 $
//! $Date: 2015-04-15 15:11:48 +0200 (Mi, 15 Apr 2015) $
//!
//! Detailed description of the the content of this source file
//! ...
//!
//! @see @ref Section_SectionName for descriptive information.
//! @see @ref fw_smath.h for interface description.
//-----------------------------------------------------------------------------
// Notes
// Initial author: 
// $Author: 
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

//-----------------------------------------------------------------------------
//! One-line description of the function STDLib_CalcCRC.
//!
//! Calculates CRC checksum from message and returns remainder.
//!
//! @param [in] u8Message[]: Array of bytes in message to be checked.
//!
//! @param [in] u16Length: Number of bytes on message
//!
//! @return Calculated checksum
//!
//-----------------------------------------------------------------------------
UINT16 STDLib_CalcCRC(BYTE *auc8pMessage, UINT16 u16Length)
{
  UINT16 u16Remainder = CRC_INIT;
  UINT8  u8Data;
  UINT16 u16Index;
  UINT16 const u16CrcTable[256] = {
    0x0000, 0xC86C, 0x58B4, 0x90D8, 0xB168, 0x7904, 0xE9DC, 0x21B0,
    0xAABC, 0x62D0, 0xF208, 0x3A64, 0x1BD4, 0xD3B8, 0x4360, 0x8B0C,
    0x9D14, 0x5578, 0xC5A0, 0x0DCC, 0x2C7C, 0xE410, 0x74C8, 0xBCA4,
    0x37A8, 0xFFC4, 0x6F1C, 0xA770, 0x86C0, 0x4EAC, 0xDE74, 0x1618,
    0xF244, 0x3A28, 0xAAF0, 0x629C, 0x432C, 0x8B40, 0x1B98, 0xD3F4, 
    0x58F8, 0x9094, 0x004C, 0xC820, 0xE990, 0x21FC, 0xB124, 0x7948,
    0x6F50, 0xA73C, 0x37E4, 0xFF88, 0xDE38, 0x1654, 0x868C, 0x4EE0,
    0xC5EC, 0x0D80, 0x9D58, 0x5534, 0x7484, 0xBCE8, 0x2C30, 0xE45C,
    0x2CE4, 0xE488, 0x7450, 0xBC3C, 0x9D8C, 0x55E0, 0xC538, 0x0D54,
    0x8658, 0x4E34, 0xDEEC, 0x1680, 0x3730, 0xFF5C, 0x6F84, 0xA7E8,
    0xB1F0, 0x799C, 0xE944, 0x2128, 0x0098, 0xC8F4, 0x582C, 0x9040,
    0x1B4C, 0xD320, 0x43F8, 0x8B94, 0xAA24, 0x6248, 0xF290, 0x3AFC,
    0xDEA0, 0x16CC, 0x8614, 0x4E78, 0x6FC8, 0xA7A4, 0x377C, 0xFF10,
    0x741C, 0xBC70, 0x2CA8, 0xE4C4, 0xC574, 0x0D18, 0x9DC0, 0x55AC,
    0x43B4, 0x8BD8, 0x1B00, 0xD36C, 0xF2DC, 0x3AB0, 0xAA68, 0x6204,
    0xE908, 0x2164, 0xB1BC, 0x79D0, 0x5860, 0x900C, 0x00D4, 0xC8B8,
    0x59C8, 0x91A4, 0x017C, 0xC910, 0xE8A0, 0x20CC, 0xB014, 0x7878,
    0xF374, 0x3B18, 0xABC0, 0x63AC, 0x421C, 0x8A70, 0x1AA8, 0xD2C4,
    0xC4DC, 0x0CB0, 0x9C68, 0x5404, 0x75B4, 0xBDD8, 0x2D00, 0xE56C,
    0x6E60, 0xA60C, 0x36D4, 0xFEB8, 0xDF08, 0x1764, 0x87BC, 0x4FD0,
    0xAB8C, 0x63E0, 0xF338, 0x3B54, 0x1AE4, 0xD288, 0x4250, 0x8A3C,
    0x0130, 0xC95C, 0x5984, 0x91E8, 0xB058, 0x7834, 0xE8EC, 0x2080,
    0x3698, 0xFEF4, 0x6E2C, 0xA640, 0x87F0, 0x4F9C, 0xDF44, 0x1728,
    0x9C24, 0x5448, 0xC490, 0x0CFC, 0x2D4C, 0xE520, 0x75F8, 0xBD94,
    0x752C, 0xBD40, 0x2D98, 0xE5F4, 0xC444, 0x0C28, 0x9CF0, 0x549C,
    0xDF90, 0x17FC, 0x8724, 0x4F48, 0x6EF8, 0xA694, 0x364C, 0xFE20,
    0xE838, 0x2054, 0xB08C, 0x78E0, 0x5950, 0x913C, 0x01E4, 0xC988,
    0x4284, 0x8AE8, 0x1A30, 0xD25C, 0xF3EC, 0x3B80, 0xAB58, 0x6334,
    0x8768, 0x4F04, 0xDFDC, 0x17B0, 0x3600, 0xFE6C, 0x6EB4, 0xA6D8,
    0x2DD4, 0xE5B8, 0x7560, 0xBD0C, 0x9CBC, 0x54D0, 0xC408, 0x0C64,
    0x1A7C, 0xD210, 0x42C8, 0x8AA4, 0xAB14, 0x6378, 0xF3A0, 0x3BCC,
    0xB0C0, 0x78AC, 0xE874, 0x2018, 0x01A8, 0xC9C4, 0x591C, 0x9170};

  // Divide the message by the polynomial, a byte at a time.
  for(u16Index = 0; u16Index < u16Length; ++u16Index)
  {
    u8Data = (UINT8)(auc8pMessage[u16Index] ^ (u16Remainder >> (CRC_WIDTH - 8)));
    u16Remainder = u16CrcTable[u8Data] ^ (u16Remainder << 8);
  }

  // The final remainder is the CRC.
  return (u16Remainder ^ CRC_FINAL);
}


//-----------------------------------------------------------------------------
//! Calculate a checksum for the input buffer
//!
//! @param [in] @todo PARAMETER_NAME DESCRIPTION
//!   @ref DEFINE_NAME,  @ref DEFINE_NAME DEFINE_NAME DESCRIPTION
//!
//! @param [in, out] u8Length: Length of the buffer +1. The reason for the +1
//!                            is that this function is used mainly where the 
//!                            last byte of the buffer should be the checksum
//!                            itself.
//!
//! @param [in] PARAMETER_NAME,  PARAMETER_NAME PARAMETER_NAME DESCRIPTION
//!
//! @return @todo RETURN_VALUE DESCRIPTION / NONE
//!
//-----------------------------------------------------------------------------
UINT8 UTIL_u8CsCalculate(UINT8 u8Length, BYTE* au8pBuffer)
{
  UINT8 u8Counter;
  UINT8 u8Result = 0;

  for (u8Counter = 0; u8Counter < (u8Length - 1); u8Counter++)
  {
    u8Result ^= au8pBuffer[u8Counter];
  }

  return u8Result;
}

