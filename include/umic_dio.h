//============================================================================//
// File:          umic_dio.h                                                  //
// Description:   Control of digital I/Os on uMIC controller hardware         //
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



#ifndef  UMIC_DIO_H_
#define  UMIC_DIO_H_


//----------------------------------------------------------------------------//
// take precautions if compiled with C++ compiler                             //
#ifdef __cplusplus                                                            //
extern "C" {                                                                  //
#endif                                                                        //
//----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------
/*!
** \file     umic_dio.h
** \defgroup UMIC_DIO  Digital I/O
**
** The digital I/O API provides access to the on-board digital I/O terminals.
** Digital I/O terminals are accessed in groups of 8-bit, the first group
** starts at index 0.
** <p>
** In order to access digital I/O terminals the hardware has to be initialized
** by calling to umic_dio_init() first. The terminals are configured as
** digital inputs by default. The port direction of each terminals can be changed
** by calling either umic_dio_set_direction() or umic_dio_set_direction_pin().
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

#include <stdint.h>           // use C99 data types
#include <stdbool.h>          // boolean definitions


/*----------------------------------------------------------------------------*\
** Definitions                                                                **
**                                                                            **
\*----------------------------------------------------------------------------*/


//-------------------------------------------------------------------
/*!
** \enum    UMIC_DIO_ERR_e
**
** Error codes for access to digital I/Os
*/
enum UMIC_DIO_ERR_e {
   // deprecated value
   eUMIC_DIO_ERR_OK    =  0,

   /*! No Error                                 */
   eUMIC_DIO_ERR_NONE  =  0,

   /*! Error while digital I/O initialisation   */
   eUMIC_DIO_ERR_INIT  = -1,

   /*  deprecated value, SPI_IOC_MESSAGE Error  */
   eUMIC_DIO_ERR_SPI   = -2,

   /*! Digital I/O communication error          */
   eUMIC_DIO_ERR_COM   = -2,

   /*! Invalid group value                      */
   eUMIC_DIO_ERR_GROUP = -3,

   /*! Invalid pin value                        */
   eUMIC_DIO_ERR_PIN   = -4
};

//-------------------------------------------------------------------
/*!
** \enum    UMIC_DIO_PIN_e
**
** Pin number for digital I/Os
*/
enum UMIC_DIO_PIN_e {

   /*! I/O Pin 1                                */
   eUMIC_DIO_PIN_1 =  0,

   /*! I/O Pin 2                                */
   eUMIC_DIO_PIN_2,

   /*! I/O Pin 3                                */
   eUMIC_DIO_PIN_3,

   /*! I/O Pin 4                                */
   eUMIC_DIO_PIN_4,

   /*! I/O Pin 5                                */
   eUMIC_DIO_PIN_5,

   /*! I/O Pin 6                                */
   eUMIC_DIO_PIN_6,

   /*! I/O Pin 7                                */
   eUMIC_DIO_PIN_7,

   /*! I/O Pin 8                                */
   eUMIC_DIO_PIN_8
};

//-------------------------------------------------------------------
/*!
** \param[in]  ubGroupV - Input group
**
** \return digital input value, or negative value on error
**
** The function reads the state of the digital inputs for the
** group \a ubGroupV. The first group starts at index 0.
**
*/
int32_t umic_dio_get_input(uint8_t ubGroupV);

//-------------------------------------------------------------------
/*!
** \param[in]     uwPinNumberV - Input pin
** \param[in,out] pslSuccessV  - Pointer to function status
**
** \see umic_dio_get_input()
**
** \return digital input value
**
** The function reads the state of the digital input pin
** \a uwPinNumberV. The first pin starts with the value 0, the
** enumeration #UMIC_DIO_PIN_e provides pre-defined values.
** The pointer \a pslSuccessV is an optional parameter, it can be set
** to 0L if it is not required. The memory location of the pointer
** \a pslSuccessV has the value #eUMIC_DIO_ERR_NONE after successful
** operation, or any other value defined by #UMIC_DIO_ERR_e in case
** of an error.
** <p>
** The function returns \c true if the input is switched on,
** otherwise it returns \c false.
**
*/
bool umic_dio_get_input_pin(uint16_t uwPinNumberV, int32_t * pslSuccessV);

//-------------------------------------------------------------------
/*!
** \see  umic_dio_release()
**
** \return #eUMIC_DIO_ERR_NONE on success, or negative value on error
**
** This function must be called prior to any other function in order
** to initialise the digital I/O driver.
*/
int32_t umic_dio_init(void);


//-------------------------------------------------------------------
/*!
** \see  umic_dio_init()
**
** The function releases the digital I/O support.
*/
void    umic_dio_release(void);


//-------------------------------------------------------------------
/*!
** \param[in] ubGroupV - I/O group
** \param[in] ubMaskV  - I/O mask value
**
** \return #eUMIC_DIO_ERR_NONE on success, or negative value on error
**
** The function sets the I/O direction to the group \a ubGroupV.
** The first group starts at index 0. A mask value of 0 sets
** all pins of the group as inputs, a mask value of FFh sets
** all pins of the group as outputs.
**
*/
int32_t umic_dio_set_direction(uint8_t ubGroupV, uint8_t ubMaskV);


//-------------------------------------------------------------------
/*!
** \param[in]     uwPinNumberV - Input pin
** \param[in]     btIsOutputV  - 1 if pin is an output, otherwise 0
**
** \return #eUMIC_DIO_ERR_NONE on success, or negative value on error
**
** The function sets the I/O direction of the terminal defined by
** \a uwPinNumberV.
** The first pin starts with the value 0, the enumeration
** #UMIC_DIO_PIN_e provides pre-defined values. If the parameter
** \a btIsOutputV is set to \c true, the terminal is an output.
** If the parameter \a btIsOutputV is set to \c false, the terminal
** is an input.
**
*/
int32_t umic_dio_set_direction_pin(uint16_t uwPinNumberV, bool btIsOutputV);


//-------------------------------------------------------------------
/*!
** \param[in] ubGroupV - Output group
** \param[in] ubValueV - Output group
**
** \return #eUMIC_DIO_ERR_NONE on success, or negative value on error
**
** The function write the output value \a ubValueV to the
** group \a ubGroupV. The first group starts at index 0
**
*/
int32_t umic_dio_set_output(uint8_t ubGroupV, uint8_t ubValueV);


//-------------------------------------------------------------------
/*!
** \param[in]     uwPinNumberV - Input pin
** \param[in]     btValueV  - Output value
**
** \return #eUMIC_DIO_ERR_NONE on success, or negative value on error
**
** The function writes the output value \a btValueV to the pin
** \a uwPinNumberV. The first pin starts with the value 0, the
** enumeration #UMIC_DIO_PIN_e provides pre-defined values.
**
*/
int32_t umic_dio_set_output_pin(uint16_t uwPinNumberV, bool btValueV);

/** @} */ // end of group UMIC_DIO

//----------------------------------------------------------------------------//
#ifdef __cplusplus                                                            //
}                                                                             //
#endif                                                                        //
// end of C++ compiler wrapper                                                //
//----------------------------------------------------------------------------//

#endif      // UMIC_DIO_H_
