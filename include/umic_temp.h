//============================================================================//
// File:          umic_temp.h                                                 //
// Description:   Acccess to Temperature on uMIC controller hardware          //
//                                                                            //
// Copyright (C) MicroControl GmbH & Co. KG                                   //
// Junkersring 23                                                             //
// 53844 Troisdorf                                                            //
// Germany                                                                    //
// Tel: +49-2241-25659-0                                                      //
// Fax: +49-2241-25659-11                                                     //
//                                                                            //
// The copyright to the computer program(s) herein is the property of         //
// MicroControl GmbH & Co. KG, Germany. The program(s) may be used            //
// and/or copied only with the written permission of MicroControl GmbH &      //
// Co. KG or in accordance with the terms and conditions stipulated in        //
// the agreement/contract under which the program(s) have been supplied.      //
//----------------------------------------------------------------------------//
//                                                                            //
// Date        History                                                        //
// ----------  -------------------------------------------------------------- //
// 27.01.2016  Initial version                                                //
//                                                                            //
//============================================================================//

#ifndef  UMIC_TEMP_H_
#define  UMIC_TEMP_H_

//----------------------------------------------------------------------------//
// take precautions if compiled with C++ compiler                             //
#ifdef __cplusplus                                                            //
extern "C" {                                                                  //
#endif                                                                        //
//----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------
/*!
** \file     umic_temp.h
** \defgroup UMIC_TEMP  Temperature
**
** The ...
** <p>
**
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


/*----------------------------------------------------------------------------*\
** function declarations                                                      **
**                                                                            **
\*----------------------------------------------------------------------------*/



/*!
** @return Current Temp on success, or negative value on error
** The function reads the ADC-Data of the Tempereature-Voltage provided by the PMIC-MUX
** Calculating the actual Temp and returns it as an signed 32bit integer multiplied with 1000
** Example: At 25°C umic_temp_read() returns 25000.
*/
int32_t umic_temp_read(void);


/** @} */ // end of group UMIC_TEMP

//----------------------------------------------------------------------------//
#ifdef __cplusplus                                                            //
}                                                                             //
#endif                                                                        //
// end of C++ compiler wrapper                                                //
//----------------------------------------------------------------------------//

#endif      // UMIC_FRAM_H_
