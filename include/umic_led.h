//============================================================================//
// File:          umic_led.h                                                  //
// Description:   LED functions for uMIC controller hardware                  //
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


#ifndef UMIC_LED_H_
#define UMIC_LED_H_

//----------------------------------------------------------------------------//
// take precautions if compiled with C++ compiler                             //
#ifdef __cplusplus                                                            //
extern "C" {                                                                  //
#endif                                                                        //


//-----------------------------------------------------------------------------
/*!
** \file     umic_led.h
** \defgroup UMIC_LED  LED
**
** The controller&micro;MIC.200 has four application specific bi-color LEDs,
** which can be controller using the umic_led_set() and umic_led_clr()
** functions.
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

/*!
 * \enum UMIC_LED_e
 */
enum UMIC_LED_e {
   eUMIC_LED1_GREEN = 0,//!< eUMIC_LED1_GREEN
   eUMIC_LED2_GREEN,    //!< eUMIC_LED2_GREEN
   eUMIC_LED3_GREEN,    //!< eUMIC_LED3_GREEN
   eUMIC_LED4_GREEN,    //!< eUMIC_LED4_GREEN

   eUMIC_LED1_RED,      //!< eUMIC_LED1_RED
   eUMIC_LED2_RED,      //!< eUMIC_LED2_RED
   eUMIC_LED3_RED,      //!< eUMIC_LED3_RED
   eUMIC_LED4_RED,      //!< eUMIC_LED4_RED

   eUMIC_LED_MAX        //!< eUMIC_LED_MAX
};


enum UMIC_LED_TRIGGER_e {
   eUMIC_LED_TRIGGER_NONE = 0,   //!< eUMIC_LED_TRIGGER_NONE
   eUMIC_LED_TRIGGER_USB_GADGET, //!< eUMIC_LED_TRIGGER_USB_GADGET
   eUMIC_LED_TRIGGER_USB_HOST,   //!< eUMIC_LED_TRIGGER_USB_HOST
   eUMIC_LED_TRIGGER_MMC0,       //!< eUMIC_LED_TRIGGER_MMC0
   eUMIC_LED_TRIGGER_MMC1,       //!< eUMIC_LED_TRIGGER_MMC1
   eUMIC_LED_TRIGGER_TIMER,      //!< eUMIC_LED_TRIGGER_TIMER
   eUMIC_LED_TRIGGER_ONESHOT,    //!< eUMIC_LED_TRIGGER_ONESHOT
   eUMIC_LED_TRIGGER_HEARTBEAT,  //!< eUMIC_LED_TRIGGER_HEARTBEAT
   eUMIC_LED_TRIGGER_BACKLIGHT,  //!< eUMIC_LED_TRIGGER_BACKLIGHT
   eUMIC_LED_TRIGGER_GPIO,       //!< eUMIC_LED_TRIGGER_GPIO
   eUMIC_LED_TRIGGER_DEFAULT_ON, //!< eUMIC_LED_TRIGGER_DEFAULT_ON
   eUMIC_LED_TRIGGER_MAX                 //!< eUMIC_LED_MAX
};
/*----------------------------------------------------------------------------*\
** function declarations                                                      **
**                                                                            **
\*----------------------------------------------------------------------------*/

/*!
** @brief Switch selected LED off
** @param ubLedV - Number of LED from #UMIC_LED_e enumeration
** @return 0 on success, or -1 on error
*/
int32_t umic_led_clr(uint8_t ubLedV);

/*!
** @brief Switch selected LED on
** @param ubLedV - Number of LED from #UMIC_LED_e enumeration
** @return 0 on success, or -1 on error
*/
int32_t umic_led_set(uint8_t ubLedV);

/*!
** @brief Get current Trigger mode of selected LED
** @param ubLedV - Number of LED from #UMIC_LED_e enumeration
** @param pubTriggerTypeV - Pointer to variable to write Trigger mode on
** @return 0 on success, or -1 on error
*/
int32_t umic_led_trigger_get(uint8_t ubLedV, uint8_t *pubTriggerTypeV);

/*!
** @brief Set current Trigger mode of selected LED
** @param ubLedV - Number of LED from #UMIC_LED_e enumeration
** @param ubTriggerTypeV Number of Trigger mode from #UMIC_LED_TRIGGER_e enumeration
** @return 0 on success, or -1 on error
*/
int32_t umic_led_trigger_set(uint8_t ubLedV, uint8_t ubTriggerTypeV);


/** @} */ // end of group UMIC_LED

//----------------------------------------------------------------------------//
#ifdef __cplusplus                                                            //
}                                                                             //
#endif                                                                        //
// end of C++ compiler wrapper                                                //
//----------------------------------------------------------------------------//
#endif /* UMIC_LED_H_ */
