//=============================================================================
// Project: fw 
//-----------------------------------------------------------------------------
//! @file
//! @brief Short description of this include file: Defines all technical, 
//! mathematical and physical units.
//!
//! @version
//! $Revision: 11 $
//! $Date: 2014-12-26 00:54:35 +0100 (Fr, 26 Dez 2014) $
//!
//! Detailed description of the interface of the content of this include file:
//! Here you find the defines of all technical, mathematical and physical units.
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
//! @see @ref units.h for interface description
//! @see @ref UNITS.c for implementation details.
//-----------------------------------------------------------------------------

#ifndef UNITS__H__
#define UNITS__H__

// Includes *******************************************************************

// Defines ********************************************************************
//! Temperature units
#define DEGREE_CELSIUS 1
#define DEGREE_FAHRENHEIT 2

//! Velocity units
#define COUNTS_PER_SECOND 10
#define COUTNS_PER_MILISECOND 11
#define ROUNDS_PER_SECOND 12
#define ROUNDS_PER_MINUTE 13
#define ROUNDS_PER_HOUR 14

//! Acceleration units, second squared
#define COUNTS_PER_MSS 20
#define COUNTS_PER_SS 21
#define ROUNDS_PER_SS 22
#define RAD_PER_SS 23

// Macros *********************************************************************

// See Defines section

// Type definitions ***********************************************************

// Prototypes *****************************************************************
// No Doxygen comment necessary here,  description will be placed before function
// definition.

// Constants ******************************************************************

// Variables ******************************************************************



#endif // of UNITS__H__

