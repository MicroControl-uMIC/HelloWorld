//============================================================================//
// File:          umic_relay.h                                                //
// Description:   Relay API function for µMIC Automation Controller           //
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


#ifndef UMIC_RELAY_H_
#define UMIC_RELAY_H_


//----------------------------------------------------------------------------//
// take precautions if compiled with C++ compiler                             //
#ifdef __cplusplus                                                            //
extern "C" {                                                                  //
#endif                                                                        //


//-----------------------------------------------------------------------------
/*!
** \file     umic_relay.h
** \defgroup UMIC_RELAY  Relay
**
** The Relay API provides access to the on-board relays. The total number of
** on-board relays can be evaluated by the \c umic-info command.
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
** Defines                                                                    **
**                                                                            **
\*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*\
** function declarations                                                      **
**                                                                            **
\*----------------------------------------------------------------------------*/

/*!
** @brief Switch selected relay off
** @param ubRelayV - Number of relay
**
** @return 0 on success, or -1 on error
**
** This function switches the relay to the off (NC) position. The
** first relay starts at index 0.
*/
int32_t umic_relay_off(uint8_t ubRelayV);


/*!
** @brief Switch selected relay on
** @param ubRelayV - Number of relay
**
** @return 0 on success, or -1 on error
**
** This function switches the relay to the on (NO) position. The
** first relay starts at index 0.
*/
int32_t umic_relay_on(uint8_t ubRelayV);

/** @} */ // end of group UMIC_RELAY

//----------------------------------------------------------------------------//
#ifdef __cplusplus                                                            //
}                                                                             //
#endif                                                                        //
// end of C++ compiler wrapper                                                //
//----------------------------------------------------------------------------//

#endif /* UMIC_RELAY_H_ */
