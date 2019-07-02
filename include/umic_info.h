//============================================================================//
// File:          umic_info.h                                                 //
// Description:   Get information about uMIC controller hardware              //
//                                                                            //
// Copyright (C) MicroControl GmbH & Co. KG                                   //
// 53844 Troisdorf - Germany                                                  //
// www.microcontrol.net                                                       //
//                                                                            //
//----------------------------------------------------------------------------//
// The copyright to the computer program(s) herein is the property of         //
// MicroControl GmbH & Co. KG, Germany. The program(s) may be used            //
// and/or copied only with the written permission of MicroControl GmbH &      //
// Co. KG or in accordance with the terms and conditions stipulated in        //
// the agreement/contract under which the program(s) have been supplied.      //
//                                                                            //
//============================================================================//



#ifndef  UMIC_INFO_H_
#define  UMIC_INFO_H_


//----------------------------------------------------------------------------//
// take precautions if compiled with C++ compiler                             //
#ifdef __cplusplus                                                            //
extern "C" {                                                                  //
#endif                                                                        //
//----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------
/*!
** \file     umic_info.h
** \defgroup UMIC_INFO  System
**
** The system (or info) API provides information about the controller.
** <p>
**
**
** @{
**
**
*/


/*----------------------------------------------------------------------------*\
** Include files                                                              **
**                                                                            **
\*----------------------------------------------------------------------------*/

#include <stdint.h>        // use C99 data types


/*----------------------------------------------------------------------------*\
** Definitions                                                                **
**                                                                            **
\*----------------------------------------------------------------------------*/


//-------------------------------------------------------------------
/*!
**
** \def UMIC_TEMPERATURE_NOT_VALID
**
** This value defines an invalid temperature.
**
*/
#define  UMIC_TEMPERATURE_NOT_VALID    ((int16_t) -450)


/*----------------------------------------------------------------------------*\
** Functions                                                                  **
**                                                                            **
\*----------------------------------------------------------------------------*/


//-------------------------------------------------------------------
/*!
**
** \return Serial number
**
** The function retrieves the serial number of the CPU board. A
** value of 0 or FFFFFFFF<sub>h</sub> denotes an invalid value.
**
*/
uint32_t umic_info_get_serial_cpu(void);


//-------------------------------------------------------------------
/*!
**
** \return System temperature
**
** The function returns the actual system temperature in degree
** Celsius. A value of #UMIC_TEMPERATURE_NOT_VALID denotes an
** invalid value.
**
*/
int16_t     umic_info_get_system_temperature(void);


//-------------------------------------------------------------------
/*!
**
** \return Library version
**
** The function returns a pointer to a constant string with
** the library version.
**
*/
const char * umic_info_get_library_version(void);


/** @} */ // end of group UMIC_INFO

//----------------------------------------------------------------------------//
#ifdef __cplusplus                                                            //
}                                                                             //
#endif                                                                        //
// end of C++ compiler wrapper                                                //
//----------------------------------------------------------------------------//

#endif      // UMIC_INFO_H_
