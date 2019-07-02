//============================================================================//
// File:          umic_fram.h                                                 //
// Description:   Access to FRAM on uMIC controller hardware                  //
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


#ifndef  UMIC_FRAM_H_
#define  UMIC_FRAM_H_

//----------------------------------------------------------------------------//
// take precautions if compiled with C++ compiler                             //
#ifdef __cplusplus                                                            //
extern "C" {                                                                  //
#endif                                                                        //
//----------------------------------------------------------------------------//

//-----------------------------------------------------------------------------
/*!
** \file     umic_fram.h
** \defgroup UMIC_FRAM  FRAM
**
** The FRAM API provides access to the FRAM. The size of the FRAM can be
** evaluated by the \c umic-info command.
** <p>
** In order to access the FRAM memory the hardware has to be initialized
** by calling to umic_fram_init() first. The FRAM is write protected by
** default, write access is granted by calling umic_fram_write_enable().
**
** <p>
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
// \enum Error codes for access to FRAM
*/
enum UMIC_FRAM_ERR_e {

   /* deprecated                             */
   eUMIC_FRAM_ERR_OK    = 0,

   /*! No Error                              */
   eUMIC_FRAM_ERR_NONE  = 0,

   /*! Error while initialising FRAM         */
   eUMIC_FRAM_ERR_INIT  = -1,

   /* deprecated : SPI_IOC_MESSAGE Error     */
   eUMIC_FRAM_ERR_SPI   = -2,

   /*! FRAM communication error              */
   eUMIC_FRAM_ERR_COM   = -2,

   /*! Invalid FRAM Address                  */
   eUMIC_FRAM_ERR_ADR   = -3,

   /*! FRAM is busy                          */
   eUMIC_FRAM_ERR_BUSY  = -4,

   /*! FRAM is write protected               */
   eUMIC_FRAM_ERR_PROT  = -5
};

/*----------------------------------------------------------------------------*\
** function declarations                                                      **
**                                                                            **
\*----------------------------------------------------------------------------*/

//-------------------------------------------------------------------
/*!
** \see  umic_fram_release()
**
** \return #eUMIC_FRAM_ERR_NONE on success, or negative value on error
**
** This function must be called prior to any other function in order
** to initialise the FRAM driver.
*/
int32_t umic_fram_init(void);


//-------------------------------------------------------------------
/*!
** \param ulAddressV - Start address
** \param pubDataV - pointer to data
** \param ulSizeV - Size of data to read
**
** \return  #eUMIC_FRAM_ERR_NONE on success, or negative value on error
** \see     umic_fram_write()
**
** The function reads \a ulSizeV bytes from the given address \a ulAddressV
** and copies the data to the location \a pubDataV.
**
*/
int32_t umic_fram_read( uint32_t ulAddressV, uint8_t *pubDataV,
                        uint32_t ulSizeV);


//-------------------------------------------------------------------
/*!
** \see  umic_fram_init()
**
** The function releases the FRAM support.
**
*/
void umic_fram_release(void);


//-------------------------------------------------------------------
/*!
** \param ulAddressV - Start address
** \param pubDataV - pointer to data
** \param ulSizeV - Size of data to write
**
** \return #eUMIC_FRAM_ERR_NONE on success, or negative value on error
** \see     umic_fram_read()
**
** The function writes \a ulSizeV bytes to the given address \a ulAddressV
** and copies the data from the location \a pubDataV.
*/
int32_t umic_fram_write(uint32_t ulAddressV,
                        uint8_t *pubDataV,
                        uint32_t ulSizeV);

//-------------------------------------------------------------------
/*!
** \return #eUMIC_FRAM_ERR_NONE on success, or negative value on error
**
** The functions disables the write access to the FRAM.
*/
int32_t umic_fram_write_disable(void);

//-------------------------------------------------------------------
/*!
** \return #eUMIC_FRAM_ERR_NONE on success, or negative value on error
**
** The functions enables the write access to the FRAM.
*/
int32_t umic_fram_write_enable(void);

/** @} */ // end of group UMIC_FRAM

//----------------------------------------------------------------------------//
#ifdef __cplusplus                                                            //
}                                                                             //
#endif                                                                        //
// end of C++ compiler wrapper                                                //
//----------------------------------------------------------------------------//

#endif      // UMIC_FRAM_H_
