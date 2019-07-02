//============================================================================//
// File:           canopen_master.h                                           //
// Description:    API for CANopen Master library                             //
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



#ifndef CANOPEN_MASTER_H_
#define CANOPEN_MASTER_H_


//----------------------------------------------------------------------------//
// take precautions if compiled with C++ compiler                             //
#ifdef __cplusplus                                                            //
extern "C" {                                                                  //
#endif                                                                        //
//----------------------------------------------------------------------------//



/*----------------------------------------------------------------------------*\
** Include files                                                              **
**                                                                            **
\*----------------------------------------------------------------------------*/
#include <stdint.h>        // use C99 data types


/*----------------------------------------------------------------------------*\
** Data types                                                                 **
**                                                                            **
\*----------------------------------------------------------------------------*/

typedef  int32_t     ComStatus_tv;


/*----------------------------------------------------------------------------*\
** Definitions / Enumerations                                                 **
**                                                                            **
\*----------------------------------------------------------------------------*/



//-------------------------------------------------------------------
/*!
** \defgroup ComDefs  Definitions and enumerations
**
** @{
*/
#ifndef  CANPIE_H_
#define  CP_DATA_SIZE         8
#endif

//-------------------------------------------------------------------
/*!
** \def     COM_SDO_CLIENT_MAX
**
** The symbol defines the number of SDO clients that are supported.
*/
#define  COM_SDO_CLIENT_MAX   ((uint8_t)  2)


/*----------------------------------------------------------------------------*\
** SDO abort codes                                                            **
**                                                                            **
\*----------------------------------------------------------------------------*/

//-------------------------------------------------------------------
/*!
** \defgroup SDO_ERR  SDO error codes
** The SDO abort transfer service aborts the SDO upload service or
** SDO download service of an SDO referenced by its number. The
** reason is indicated by a 32-bit value.
*/

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_TOGGLE_BIT
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Toggle bit not altered.
*/
#define SDO_ERR_TOGGLE_BIT             0x05030000

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_TIMEOUT
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** SDO protocol timed out.
*/
#define SDO_ERR_TIMEOUT                0x05040000

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_COMMAND
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Client/server command specifier not valid or unknown.
*/
#define SDO_ERR_COMMAND                0x05040001

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_BLOCK_SIZE
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Invalid block size (block mode only).
*/
#define SDO_ERR_BLOCK_SIZE             0x05040002

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_BLOCK_SEQUENCE
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Invalid block sequence number (block mode only).
*/
#define SDO_ERR_BLOCK_SEQUENCE         0x05040003

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_BLOCK_CRC
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Invalid block CRC value (block mode only).
*/
#define SDO_ERR_BLOCK_CRC              0x05040004

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_MEMORY
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Out of memory.
*/
#define SDO_ERR_MEMORY                 0x05040005

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_ACCESS_UNSUPPORTED
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Unsupported access to an object.
*/
#define SDO_ERR_ACCESS_UNSUPPORTED     0x06010000

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_ACCESS_WO
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Attempt to read a write only object.
*/
#define SDO_ERR_ACCESS_WO              0x06010001

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_ACCESS_RO
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Attempt to write a read only object.
*/
#define SDO_ERR_ACCESS_RO              0x06010002

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_NO_OBJECT
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Object does not exist in the object dictionary.
*/
#define SDO_ERR_NO_OBJECT              0x06020000

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_MAPPING_OBJECT
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Object cannot be mapped to the PDO.
*/
#define SDO_ERR_MAPPING_OBJECT         0x06040041

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_MAPPING_LENGTH
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** The number and length of the objects to be mapped would exceed
** PDO length.
*/
#define SDO_ERR_MAPPING_LENGTH         0x06040042

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_GENERAL_PARAMETER
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** General parameter incompatibility reason.
*/
#define SDO_ERR_GENERAL_PARAMETER      0x06040043

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_GENERAL_DEVICE
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** General internal incompatibility in the device.
*/
#define SDO_ERR_GENERAL_DEVICE         0x06040047

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_HARDWARE
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Access failed due to an hardware error.
*/
#define SDO_ERR_HARDWARE               0x06060000

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_DATATYPE
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Data type does not match, length of service parameter does
** not match.
*/
#define SDO_ERR_DATATYPE               0x06070010

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_DATATYPE_HIGH
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Data type does not match, length of service parameter too high.
*/
#define SDO_ERR_DATATYPE_HIGH          0x06070012

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_DATATYPE_LOW
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Data type does not match, length of service parameter too low.
*/
#define SDO_ERR_DATATYPE_LOW           0x06070013

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_NO_SUB_INDEX
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Sub-index does not exist.
*/
#define SDO_ERR_NO_SUB_INDEX           0x06090011

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_VALUE_RANGE
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Invalid value for parameter (download only).
*/
#define SDO_ERR_VALUE_RANGE            0x06090030

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_VALUE_HIGH
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Value of parameter written too high (download only).
*/
#define SDO_ERR_VALUE_HIGH             0x06090031

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_VALUE_LOW
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Value of parameter written too low (download only).
*/
#define SDO_ERR_VALUE_LOW              0x06090032

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_VALUE_MIN_MAX
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Maximum value is less than minimum value.
*/
#define SDO_ERR_VALUE_MIN_MAX          0x06090036

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_SDO_CONNECTION
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Resource not available: SDO connection.
*/
#define SDO_ERR_SDO_CONNECTION         0x060A0023

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_GENERAL
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** General error.
*/
#define SDO_ERR_GENERAL                0x08000000

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_DATA_STORE
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Data cannot be transferred or stored to the application.
*/
#define SDO_ERR_DATA_STORE             0x08000020

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_DATA_STORE_LOCAL
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Data cannot be transferred or stored to the application because
** of local control.
*/
#define SDO_ERR_DATA_STORE_LOCAL       0x08000021

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_DATA_STORE_STATE
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Data cannot be transferred or stored to the application because
** of the present device state.
*/
#define SDO_ERR_DATA_STORE_STATE       0x08000022

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_OBJECT_DICTIONARY
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** Object dictionary dynamic generation fails or no object dictionary
** is present (e.g. object dictionary is generated from file and
** generation fails because of an file error).
*/
#define SDO_ERR_OBJECT_DICTIONARY      0x08000023

//-------------------------------------------------------------------
/*!
** \def     SDO_ERR_NO_DATA
** \ingroup SDO_ERR
** \brief   SDO Abort Code
**
** No data available.
*/
#define SDO_ERR_NO_DATA                0x08000024


/*!
** \enum    ComErr_e
** \brief   Error Codes of CANopen Master protocol stack
**
** All error codes of the CANopen Master protocol stack have
** the prefix <b>eCOM_ERR_</b>. Error return values are <b>always
** negative</b>, so it is quite simple to check in general if a
** functions fails. <p>
** Example:
** \code
** if(ComMgrStart(eCOM_NET_3) < eCOM_ERR_NONE)
** {
**    // handle error here
** }
** \endcode
**
**
*/
enum ComErr_e {

   /*!
   ** No error
   */
   eCOM_ERR_NONE = 0,

   eCOM_ERR_OK = 0,


   /*!
   ** Generic CAN driver error
   */
   eCOM_ERR_CAN = -1,


   /*!
   ** Setting of CAN bit-rate failed
   */
   eCOM_ERR_CAN_BITRATE = -2,

   /*!
   ** CAN function failed
   */
   eCOM_ERR_CAN_FUNCTION = -3,

   /*!
   ** Parameter out of range (generic)
   */
   eCOM_ERR_PARM = -10,

   /*!
   ** Generic Network error
   */
   eCOM_ERR_NET = -20,

   /*!
   ** Network index out of range, not valid
   */
   eCOM_ERR_NET_VALUE = -21,


   /*!
   ** Generic Node error
   */
   eCOM_ERR_NODE = -30,

   /*!
   ** Node ID (device address) is not valid or out of range
   */
   eCOM_ERR_NODE_ID = -31,

   /*!
   ** Node is already defined
   */
   eCOM_ERR_NODE_DEFINED = -32,

   /*!
   ** Node is not defined
   */
   eCOM_ERR_NODE_UNDEFINED = -33,


   /*!
   ** Generic COB error
   */
   eCOM_ERR_COB = -40,

   /*!
   ** Identifier is out of range
   */
   eCOM_ERR_COB_ID_VALUE = -41,

   /*!
   ** COB type out of range
   */
   eCOM_ERR_COB_TYPE = -42,

   /*!
   ** COB DLC out of range
   */
   eCOM_ERR_COB_DLC = -43,

   /*!
   ** Generic Service error
   */
   eCOM_ERR_SERVICE = -50,

   /*!
   ** Service mode error
   ** The service (NMT, SYNC, etc) is in a mode that does not allow
   ** this operation
   */
   eCOM_ERR_SERVICE_MODE = -52,

   /*!
   ** Service parameter error
   ** The service (NMT, SYNC, etc) does not accept this parameter
   */
   eCOM_ERR_SERVICE_PARAM = -53,

   /*!
   ** Generic SDO client error
   */
   eCOM_ERR_SDO_CLIENT = -60,

   /*!
   ** Value for SDO client is out of range
   */
   eCOM_ERR_SDO_CLIENT_VALUE = -61,

   /*!
   ** All available SDO clients are busy
   */
   eCOM_ERR_SDO_CLIENT_BUSY = -62,

   /*!
   ** Generic PDO error
   */
   eCOM_ERR_PDO = -70,

   /*!
   ** Number for PDO is out of range
   */
   eCOM_ERR_PDO_NUMBER = -71

};


/*----------------------------------------------------------------------------*/
/*!
** \enum    ComLssMode_e
** \see     ComLssSwitchModeGlobal()
** LSS mode
**
** This enumeration defines the allowed modes for the LSS switch mode
** global command.
*/
enum ComLssMode_e {

   /*! switch LSS state machine to LSS waiting mode         */
   eCOM_LSS_MODE_WAITING = 0,

   /*! switch LSS state machine to LSS configuration mode   */
   eCOM_LSS_MODE_CONFIGURATION
};

/*----------------------------------------------------------------------------*/
/*!
** \enum    ComLssProt_e
**
** CANopen Master LSS protocol
*/
enum ComLssProt_e {

   /*! switch global command                                */
   eCOM_LSS_PROT_SWI_GLB = 1,

   /*! switch mode selective, vendor ID                     */
   eCOM_LSS_PROT_SWI_VID,

   /*! switch mode selective, product code                  */
   eCOM_LSS_PROT_SWI_PRD,

   /*! switch mode selective, revision number               */
   eCOM_LSS_PROT_SWI_REV,

   /*! switch mode selective, serial number                 */
   eCOM_LSS_PROT_SWI_SRN,

   /*! inquire vendor ID                                    */
   eCOM_LSS_PROT_INQ_VID,

   /*! inquire product code                                 */
   eCOM_LSS_PROT_INQ_PRD,

   /*! inquire revision number                              */
   eCOM_LSS_PROT_INQ_REV,

   /*! inquire serial number                                */
   eCOM_LSS_PROT_INQ_SRN,

   /*! inquire node ID                                      */
   eCOM_LSS_PROT_INQ_NID,

   /*! store configuration                                  */
   eCOM_LSS_PROT_CONF_STORE,

   /*! configure node ID                                    */
   eCOM_LSS_PROT_CONF_ID,

   /*! configure bit-timing                                 */
   eCOM_LSS_PROT_CONF_BIT,

   /*! execute fastscan procedure                           */
   eCOM_LSS_PROT_FASTSCAN,

   /*! identify non-configured slave                        */
   eCOM_LSS_PROT_IDENTIFY

};

/*----------------------------------------------------------------------------*/
/*!
** \enum    ComLssStat_e
**
** CANopen Master LSS status
*/
enum ComLssStat_e {

   /*! LSS communication active                             */
   eCOM_LSS_STAT_ACTIVE = 1,

   /*! LSS communication success                            */
   eCOM_LSS_STAT_SUCCESS,

   /*! LSS protocol error                                   */
   eCOM_LSS_STAT_ERROR,

   /*! LSS communication timeout                            */
   eCOM_LSS_STAT_TIMEOUT,


};

/*----------------------------------------------------------------------------*/
/*!
** \enum    ComLssInqSrv_e
**
** CANopen Master LSS inquire services
*/
enum ComLssInqSrv_e {

   /*! inquire vendor ID                                       */
   eCOM_LSS_INQ_SRV_VID = 0,

   /*! inquire product code                                    */
   eCOM_LSS_INQ_SRV_PRD,

   /*! inquire revision number                                 */
   eCOM_LSS_INQ_SRV_REV,

   /*! inquire serial number                                   */
   eCOM_LSS_INQ_SRV_SRN,

   /*! inquire node ID                                         */
   eCOM_LSS_INQ_SRV_NID
};

/*----------------------------------------------------------------------------*/
/*!
** \enum    ComMode_e
** \brief   NMT startup mode
**
** The enumeration defines the values for starting the CANopen Master
** with the function ComMgrInit(). The CANopen NMT configuration is
** reflected by object 1F80h (least significant 8 bits).
*/
enum ComMode_e {

   /*! Device is NMT slave                                        */
   eCOM_MODE_NMT_SLAVE           = 0x0000,

   /*! Device is the NMT master                                   */
   eCOM_MODE_NMT_MASTER          = 0x0001,

   /*! NMT service start remote node with Node-ID = 0             */
   eCOM_MODE_NMT_START_ALL       = 0x0002,

   /*! Device does not switch into Operational by itself          */
   eCOM_MODE_NMT_PREOPERATIONAL  = 0x0004,

   /*! Application shall start the nodes                          */
   eCOM_MODE_NMT_APP_START_NODE  = 0x0008,

   /*! In case of an error event the NMT service "reset all nodes"
   **  shall be executed.
   */
   eCOM_MODE_NMT_RESET_ALL       = 0x0010,

   /*! CANopen device shall participate the NMT flying master
   **  negotiation.
   */
   eCOM_MODE_NMT_FLYING_MASTER   = 0x0020,

   /*! In case of an error event the NMT service "stop remote node"
   **  shall be executed.
   */
   eCOM_MODE_NMT_STOP_ALL        = 0x0040,

   /*! Device shall execute the NMT master detection protocol     */
   eCOM_MODE_NMT_MASTER_DETECT   = 0x0100,


   /*!
   ** Device shall start in CAN-Raw mode, no CANopen services
   ** (SDO, NMT, etc.) are executed. CAN messages are received
   ** and send via the PDO module. This is a mutually exclusive
   ** mode of operation.
   */
   eCOM_MODE_CAN_RAW             = 0x1000,


   /*! Device shall start in SAE J1939 mode                       */
   eCOM_MODE_J1939               = 0x2000

};


/*----------------------------------------------------------------------------*/
/*!
** \enum    ComNet_e
** \brief   Network channel definition
*/
enum ComNet_e {

   /*! CANopen Master network #1                   */
   eCOM_NET_1 = 0,

   /*! CANopen Master network #2                   */
   eCOM_NET_2,

   /*! CANopen Master network #3                   */
   eCOM_NET_3,

   /*! CANopen Master network #4                   */
   eCOM_NET_4
};


/*----------------------------------------------------------------------------*/
/*!
** \enum    ComNmtState_e
** \brief   NMT state codes
**
** The enumeration defines the values for setting the NMT state of
** a CANopen device via ComNmtSetNodeState() as well as for requesting
** the device state via ComNmtGetNodeState(). The values in this
** enumeration are not equal to the NMT command specifiers.
*/
enum ComNmtState_e {

   /*! Unknown NMT state                                 */
   eCOM_NMT_STATE_UNKNOWN = 0,

   /*! NMT command / state "Stopped"                     */
   eCOM_NMT_STATE_STOPPED,

   /*! NMT command / state "Pre-Operational"             */
   eCOM_NMT_STATE_PREOPERATIONAL,

   /*! NMT command / state "Operational"                 */
   eCOM_NMT_STATE_OPERATIONAL,

   /*! NMT command "Reset node"                          */
   eCOM_NMT_STATE_RESET_NODE,

   /*! NMT command "Reset communication"                 */
   eCOM_NMT_STATE_RESET_COM,

   /*! Device has sent Bootup message                    */
   eCOM_NMT_STATE_BOOTUP,

   /*! Device is in Initialisation state (Master only)   */
   eCOM_NMT_STATE_INIT
};



enum ComNmtDetect_e {
   eCOM_NMT_DETECT_TIMEOUT = 0,
   eCOM_NMT_DETECT_SUCCESS
};

enum ComNmtGuard_e {
   eCOM_NMT_GUARD_TIMEOUT = 0,
   eCOM_NMT_GUARD_TOGGLE
};

enum ComNodeCmd_e {
   eCOM_NODE_CMD_GET_INFO = 0xF0,
   eCOM_NODE_CMD_SET_HEARTBEAT,
   eCOM_NODE_CMD_STORE,
   eCOM_NODE_CMD_RESTORE
};


//-------------------------------------------------------------------------
/*!
** \enum    PgnDir_e
** \brief   PGN direction
**
** The following enumeration values define the direction of a PGN.
** The direction is seen from the device point of view.
*/
enum PgnDir_e {
   /*! Receive PGN                                       */
   ePGN_DIR_RCV = 0,

   /*! Transmit PGN                                      */
   ePGN_DIR_TRM
};


//-------------------------------------------------------------------------
/*!
** \enum    PdoDir_e
** \brief   PDO direction
**
** The following enumeration values define the direction of a PDO.
** The direction is seen from the device point of view, hence a RPDO
** is <b>received by the CANopen Master</b>, while a TPDO is 
** <b>sent by the CANopen Master</b>.
*/
enum PdoDir_e {
   /*! Receive-PDO (RPDO)                                   */
   ePDO_DIR_RCV = 0,

   /*! Transmit-PDO (TPDO)                                  */
   ePDO_DIR_TRM
};

/*!
** \enum    PdoType_e
** \brief   PDO transmission types
**
** The common used PDO transmission types are defined
** in this enumeration.
*/
enum PdoType_e {
   /*! Synchronous, acyclic PDO                             */
   ePDO_TYPE_SYNC_0 = 0,

   /*! Synchronous, cyclic every SYNC                       */
   ePDO_TYPE_SYNC_1,

   /*! Synchronous, cyclic every 2nd SYNC                   */
   ePDO_TYPE_SYNC_2,

   /*! Synchronous, cyclic every 3rd SYNC                   */
   ePDO_TYPE_SYNC_3,

   /*! Synchronous, cyclic every 4th SYNC                   */
   ePDO_TYPE_SYNC_4,
   ePDO_TYPE_SYNC_5,
   ePDO_TYPE_SYNC_6,
   ePDO_TYPE_SYNC_7,
   ePDO_TYPE_SYNC_8,

   /*! Synchronous, cyclic every 240th SYNC                 */
   ePDO_TYPE_SYNC_240 = 240,
   #if COM_J1939_SUPPORT == 0
   ePDO_TYPE_res241,
   ePDO_TYPE_res253 = 253,
   #else

   /*! Mark PDO as J1939 message with DLC of 8              */
   ePDO_TYPE_J1939,

   /*! Mark PDO as J1939 message with DLC > 8 (BAM)         */
   ePDO_TYPE_J1939_BAM,

   ePDO_TYPE_res253 = 253,
   #endif

   /*! Event-driven PDO, manufacturer specific              */
   ePDO_TYPE_EVENT_MANUFACTURER,

   /*! Event-driven PDO, profile specific                   */
   ePDO_TYPE_EVENT_PROFILE
};

//-------------------------------------------------------------------------
/*!
** \enum    ComSdoStat_e
** \brief   SDO transfer status
**
** The enumeration defines the status of a SDO client connection. It
** can be requested with the ComSdoGetStatus() function.
*/
enum ComSdoStat_e {
   /*! SDO client is free, no SDO communication present        */
   eCOM_SDO_STAT_EMPTY = 0,

   /*! Expedited transfer in progress (read)                   */
   eCOM_SDO_STAT_EXP_RD,

   /*! Segmented transfer in progress (read)                   */
   eCOM_SDO_STAT_SEG_RD,

   /*! Block transfer in progress (read)                       */
   eCOM_SDO_STAT_BLK_RD,

   /*! Expedited transfer in progress (write)                  */
   eCOM_SDO_STAT_EXP_WR,

   /*! Segmented transfer in progress (write)                  */
   eCOM_SDO_STAT_SEG_WR,

   /*! Block transfer in progress (write)                      */
   eCOM_SDO_STAT_BLK_WR,

   /*! SDO communication success                               */
   eCOM_SDO_STAT_SUCCESS,

   /*! SDO communication aborted                               */
   eCOM_SDO_STAT_ABORT,

   /*! SDO communication timeout                               */
   eCOM_SDO_STAT_TIMEOUT,

   /*! SDO protocol error                                      */
   eCOM_SDO_STAT_ERR,

   /*! Data size for client/server does not match              */
   eCOM_SDO_STAT_SIZE
};


//-------------------------------------------------------------------------
/*!
** \enum    ComSdoConfig_e
** \brief   SDO client configuration
**
** The enumeration defines configuration values for the SDO client
** behaviour, which is set via the function ComSdoSetConfiguration().
*/
enum ComSdoConfig_e {

   /*! Use SDO client default configuration                    */
   eCOM_SDO_CONFIG_DEFAULT = 0,

   /*! Set data length for command byte in expedited transfer  */
   eCOM_SDO_CONFIG_CMD_LEN = 1,

   /*! Set SDO block transfer for data length > 4 bytes        */
   eCOM_SDO_CONFIG_BLOCK = 2

};


//-------------------------------------------------------------------------
/*!
** \enum    ComVersion_e
** \brief   Get library information
**
** The enumeration defines values for function ComMgrGetVersionString().
*/
enum ComVersion_e {
   /*! Get information about the stack version        */
   eCOM_VERSION_STACK = 1,

   /*! Get information about the used compiler        */
   eCOM_VERSION_COMPILER,

   /*! Get information about the operating system     */
   eCOM_VERSION_SYSTEM
};



#ifndef  CANPIE_H_
/*----------------------------------------------------------------------------*/
/*!
** \enum    CpBitrate_e
** \brief   Fixed bit-rates
**
** The values of the enumeration CpBitrate_e are used as parameter for the
** function CpCoreBitrate().
*/
enum CpBitrate_e
{

   /*!
   ** No bit-rate defined
   */
   eCP_BITRATE_NONE = -1,

   /*!
   ** bit-rate 10 kBit/s
   */
   eCP_BITRATE_10K = 0,

   /*!
   ** bit-rate 20 kBit/s
   */
   eCP_BITRATE_20K = 1,

   /*!
   ** bit-rate 50 kBit/s
   */
   eCP_BITRATE_50K = 2,

   /*!
   ** bit-rate 100 kBit/s
   */
   eCP_BITRATE_100K = 3,

   /*!
   ** bit-rate 125 kBit/s
   */
   eCP_BITRATE_125K = 4,

   /*!
   ** bit-rate 250 kBit/s
   */
   eCP_BITRATE_250K = 5,

   /*!
   ** bit-rate 500 kBit/s
   */
   eCP_BITRATE_500K = 6,

   /*!
   ** bit-rate 800 kBit/s
   */
   eCP_BITRATE_800K = 7,

   /*!
   ** bit-rate 1 MBit/s
   */
   eCP_BITRATE_1M = 8,

   /*!
   ** bit-rate 2 MBit/s (ISO CAN FD, data phase)
   */
   eCP_BITRATE_2M = 10,

   /*!
   ** bit-rate 4 MBit/s (ISO CAN FD, data phase)
   */
   eCP_BITRATE_4M = 11,

   /*!
   ** bit-rate 5 MBit/s (ISO CAN FD, data phase)
   */
   eCP_BITRATE_5M = 12,

   /*!
   ** Use automatic bit-rate detection
   ** \internal Do not change the value of this enumerator in order
   **           to keep compatibility.
   */
   eCP_BITRATE_AUTO = 9,

   eCP_BITRATE_MAX = eCP_BITRATE_AUTO
};


/*----------------------------------------------------------------------------*/
/*!
** \enum    CpChannel_e
** \brief   Channel definition
**
** The physical CAN interfaces are numbered from 1 .. N (N: total
** number of physical CAN interfaces on the target system). The enumeration
** CpChannel_e lists up to 8 physical interfaces. The enumeration value
** eCP_CHANNEL_NONE denotes an invalid channel value.
*/
enum CpChannel_e {

   /*! CAN interface invalid        */
   eCP_CHANNEL_NONE = 0,

   /*! CAN interface 1              */
   eCP_CHANNEL_1,

   /*! CAN interface 2              */
   eCP_CHANNEL_2,

   /*! CAN interface 3              */
   eCP_CHANNEL_3,

   /*! CAN interface 4              */
   eCP_CHANNEL_4,

   /*! CAN interface 5              */
   eCP_CHANNEL_5,

   /*! CAN interface 6              */
   eCP_CHANNEL_6,

   /*! CAN interface 7              */
   eCP_CHANNEL_7,

   /*! CAN interface 8              */
   eCP_CHANNEL_8
};


/*----------------------------------------------------------------------------*/
/*!
** \enum    CpState_e
** \brief   State of CAN controller
**
** These values are used as return value for the function CpCoreCanState().
*/
enum CpState_e
{
   /*!
   ** CAN controller is in stopped mode
   */
   eCP_STATE_INIT = 0,

   eCP_STATE_STOPPED  = 0,    // deprecated definition

   /*!
   ** CAN controller is in Sleep mode
   */
   eCP_STATE_SLEEPING = 1,

   /*!
   ** CAN controller is error active
   */
   eCP_STATE_BUS_ACTIVE = 2,

   /*!
   ** CAN controller is active, warning level is reached
   */
   eCP_STATE_BUS_WARN = 3,

   /*!
   ** CAN controller is error passive
   */
   eCP_STATE_BUS_PASSIVE = 4,

   /*!
   ** CAN controller went into Bus Off
   */
   eCP_STATE_BUS_OFF = 5,

   /*!
   ** General failure of physical layer detected (if supported by hardware)
   */
   eCP_STATE_PHY_FAULT = 10,

   /*!
   ** Fault on CAN-H detected (Low Speed CAN)
   */
   eCP_STATE_PHY_H = 11,

   /*!
   ** Fault on CAN-L detected (Low Speed CAN)
   */
   eCP_STATE_PHY_L = 12

};

/*----------------------------------------------------------------------------*/
/*!
** \enum    CpErrType_e
** \brief   Error type
**
** These values are used as return value for the function CpCoreCanState().
*/
enum CpErrType_e
{

   /*! No error                        */
   eCP_ERR_TYPE_NONE   = 0,

   /*! Bit 0 error                     */
   eCP_ERR_TYPE_BIT0,

   /*! Bit 1 error                     */
   eCP_ERR_TYPE_BIT1,

   /*! Stuff error                     */
   eCP_ERR_TYPE_STUFF,

   /*! Format error                    */
   eCP_ERR_TYPE_FORM,

   /*! CRC error                       */
   eCP_ERR_TYPE_CRC,

   /*! Acknowledge error               */
   eCP_ERR_TYPE_ACK
};

#endif

/** @} */ // end of group ComDefs


/*----------------------------------------------------------------------------*\
** Structures                                                                 **
**                                                                            **
\*----------------------------------------------------------------------------*/

#ifndef  CANPIE_H_

/*----------------------------------------------------------------------------*/
/*!
** \struct  CpCanMsg_s
** \brief   CAN message structure
**
** For transmission and reception of CAN messages a structure which holds
** all necessary informations is used. The structure has the following
** data fields:
*/
typedef struct CpCanMsg_s
{

   /*!
   ** The identifier field may have 11 bits for standard frames
   ** (CAN specification 2.0A) or 29 bits for extended frames
   ** (CAN specification 2.0B). The three most significant bits
   ** are reserved (always read 0).
   ** \see CP_MASK
   */
   uint32_t  ulIdentifier;

   /*!
   ** The data field has up to 8 bytes (for classic CAN) or
   ** 64 bytes (for ISO CAN FD) of message data.
   ** The number of used bytes is described via the structure
   ** member \c ubMsgDLC.
   */
   union {
      /*!   byte access, array of bytes         */
      uint8_t   aubByte[CP_DATA_SIZE];

      /*!   16 bit access, array of words       */
      uint16_t  auwWord[CP_DATA_SIZE / 2];

      /*!   32 bit access, array of longs       */
      uint32_t  aulLong[CP_DATA_SIZE / 4];

      /*!   64 bit access, array of quadwords   */
      #if CPP_DATA_SIZE > 32
      uint64_t  auqQuad[CP_DATA_SIZE / 8];
      #endif
   } tuMsgData;

   /*!
   ** The data length code denotes the number of data bytes
   ** which are transmitted by a message.
   ** The possible value range for the data length code is
   ** from 0 to 8 for classic CAN and 0 to 15 for ISO CAN FD.
   */
   uint8_t  ubMsgDLC;


   /*!
   ** The structure member \c ubMsgCtrl defines the
   ** different data frames (2.0A / 2.0B) and the RTR frames.
   ** <ul>
   ** <li>Bit 0: Std. / Ext. Frame
   ** <li>Bit 1: ISO CAN FD: value of FDF bit
   ** <li>Bit 2: Remote Frame
   ** <li>Bit 3: Overload Frame
   ** <li>Bit 4: reserved, always 0
   ** <li>Bit 5: reserved, always 0
   ** <li>Bit 6: ISO CAN FD: value of BRS bit
   ** <li>Bit 7: ISO CAN FD: value of ESI bit
   ** </ul>
   ** \see CP_MSG_CTRL
   */
   uint8_t  ubMsgCtrl;


   #if CP_CAN_MSG_TIME == 1
   /*!
   ** The time stamp field defines the time when a CAN message
   ** was received by the CAN controller. This is an optional
   ** field (available if #CP_CAN_MSG_TIME is set to 1).
   */
   CpTime_ts tsMsgTime;
   #endif

   #if CP_CAN_MSG_USER == 1
   /*!
   ** The field user data can hold a 32 bit value, which is
   ** defined by the user. This is an optional field
   ** (available if #CP_CAN_MSG_USER is set to 1).
   */
   uint32_t  ulMsgUser;
   #endif

   #if CP_CAN_MSG_MARKER == 1
   /*!
   ** The field message marker can hold a 32 bit value, which is
   ** defined by the application. This is an optional field
   ** (available if #CP_CAN_MSG_MARKER is set to 1).
   */
   uint32_t  ulMsgMarker;
   #endif

} CpCanMsg_ts;

/*----------------------------------------------------------------------------*/
/*!
** \struct  CpState_s   canpie.h
** \brief   CAN state structure
**
*/
typedef struct CpState_s {

   /*!   CAN error state
   **    Value should correspond to values from #CP_STATE
   */
   uint8_t     ubCanErrState;

   /*!   Last error type occurred
   **    Value should correspond to values from #CP_ERR_TYPE
   */
   uint8_t     ubCanErrType;

   /*!   receive error counter
   */
   uint8_t     ubCanRcvErrCnt;

   /*!   transmit error counter
   */
   uint8_t     ubCanTrmErrCnt;

} CpState_ts;

#endif

//-------------------------------------------------------------------------
/*!
** \struct  CoObject_s
** \brief   Object structure
**
** The object structure is used to upload or download data between the
** CANopen Master and a CANopen Slave device.
*/
typedef struct CoObject_s {

   /*!   Index of the object                                         */
   uint16_t     uwIndex;

   /*!   Sub-Index of the object                                     */
   uint8_t     ubSubIndex;

   /*!   User defined marker for this entry                          */
   uint8_t     ubMarker;

   /*!   Data size of the object                                     */
   uint32_t     ulDataSize;

   /*!   Pointer to data                                             */
   void *   pvdData;

} CoObject_ts;


//-------------------------------------------------------------------
/*!
** \brief   CANopen device parameter
**
** The structure \e ComNode_s keeps information about a CANopen
** device with a specific node-ID. In fact it holds a copy of
** several values from a CANopen slave device.
** <p>
** The elements within this structure are not ordered by index,
** they are ordered by data type (starting with unit32_t) in order
** to allow better packing, thus avoiding unaligned access.
**
*/
typedef struct ComNode_s {

   //----------------------------------------------------------------
   // Real or last read values of a node
   //----------------------------------------------------------------

   /*! Device type                        */
   uint32_t ulIdx1000_DT;

   /*! Store parameters                   */
   uint32_t ulIdx1010_SP;

   /*! Restore parameters                 */
   uint32_t ulIdx1011_RP;

   /*! Vendor identification              */
   uint32_t ulIdx1018_VI;

   /*! Product code                       */
   uint32_t ulIdx1018_PC;

   /*! Revision number                    */
   uint32_t ulIdx1018_RN;

   /*! Serial number                      */
   uint32_t ulIdx1018_SN;

   /*! Heartbeat producer                 */
   uint16_t uwIdx1017_HB;

   uint16_t reserved0;

   /*! Error Register                     */
   uint8_t  ubIdx1001_ER;

   uint8_t  reserved1[3];

   /*! Device name                        */
   uint8_t  aubIdx1008_DN[32];

   /*! last received EMCY code            */
   uint8_t  aubEmcyCode[8];

   //----------------------------------------------------------------
   // Defined values for a node
   //
   //----------------------------------------------------------------

   /*!
   ** \brief NMT slave assignment
   **
   ** This object shall assign CANopen devices to the NMT master,
   ** the device that shall implement this object. Each sub-index
   ** of this object shall correspond to the node-ID of the according
   ** CANopen device in the network. The sub-index corresponding to its
   ** own node-ID shall be ignored.
   **
   ** <b>NMT Slave (Bit 0)</b>
   ** | Bit   | Value  | Description                                          |
   ** | :---- | :----  | :----                                                |
   ** | 0     | 0      | NMT master or not available in the network           |
   ** | 0     | 1      | NMT slave and available in the network               |
   */
   uint32_t ulIdx1F81_SA;


   /*!
   ** \brief   Device type identification
   **
   ** This object is used for verification of the device type of the CANopen
   ** devices in the network. The device type (object 1000h) of the CANopen
   ** device in the network shall be matched against the value of this
   ** object in case the value is unequal 0. An error event shall be
   ** generated if the values mismatch. In case the value of this object
   ** is 0 the device type of the CANopen device in the network may not
   ** be verified.
   */
   uint32_t ulIdx1F84_DT;

   /*!
   ** \brief   Vendor identification
   **
   ** This object shall be used for verification of the vendor-ID of the
   ** CANopen devices in the network. The vendor-ID (object 1018h:01h) of
   ** the CANopen device in the network shall be matched against the value
   ** of this object in case the value is unequal 0. An error event shall
   ** be generated if the values mismatch. In case the value of this object
   ** is 0 the vendor-ID of the CANopen device in the network may not be
   ** verified.
   */
   uint32_t ulIdx1F85_VI;

   /*!
   ** \brief   Product code identification
   **
   ** This object shall be used for verification of the product code of the
   ** CANopen devices in the network. The product code (object 1018h:02h)
   ** of the CANopen device in the network shall be matched against the
   ** value of this object in case the value is unequal 0. An error event
   ** shall be generated if the values mismatch. In case the value of this
   ** object is 0 the product code of the CANopen device in the network may
   ** not be verified.
   **
   */
   uint32_t ulIdx1F86_PC;

   /*!
   ** \brief   Revision number identification
   **
   ** This object shall be used for verification of the revision number of
   ** the CANopen devices in the network. The revision number (object
   ** 1018h:03h) of the CANopen device in the network shall be matched
   ** against the value of this object in case the value is unequal 0.
   ** An error event shall be generated if the values mismatch.
   ** A mismatch is defined as:
   ** \li the major revision number is unequal to the expected major revision
   **     number
   ** \li the minor revision number is less than the expected minor revision
   **     number
   **
   ** In case the value of this object is 0 the revision number of the CANopen
   ** device in the network shall not be verified.
   **
   */
   uint32_t ulIdx1F87_RN;

   /*!
   ** \brief   Serial number identification
   **
   ** This object shall be used for verification of the serial number of the
   ** CANopen devices in the network. The serial number (object 1018h:04h)
   ** of the CANopen device in the network shall be matched against the
   ** value of this object in case the value is unequal 0. An error event
   ** shall be generated if the values mismatch. In case the value of this
   ** object is 0 the serial number of the CANopen device in the network may
   ** not be verified.
   **
   */
   uint32_t ulIdx1F88_SN;

} ComNode_ts;


typedef struct ComNodeIdFlag_s {
   uint32_t aulNodePos[4];
} ComNodeIdFlag_ts;


/*----------------------------------------------------------------------------*\
** Function prototypes                                                        **
**                                                                            **
\*----------------------------------------------------------------------------*/


//-------------------------------------------------------------------
// ComEmcy functions
//-------------------------------------------------------------------
/*!
** \defgroup ComEmcy  EMCY service
**
** Emergency (EMCY) objects are triggered by the occurrence of a device
** internal error situation and are transmitted from an emergency producer on
** the device. Emergency objects are suitable for interrupt type error alerts.
** An emergency object is transmitted only once per 'error event'. As long
** as no new errors occur on a device no further emergency objects must be
** transmitted.
** The emergency object may be received by zero or more emergency consumers.
** The reaction on the emergency consumer(s) is not specified.
**
** @{
*/


//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubNodeIdV - Node-ID value of CANopen device
** \param[in]     ubEnableV  - Enable/Disable EMCY service
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function enables (\a ubEnableV = 1) or disables (\a ubEnableV = 0)
** the EMCY consumer service for a Node ID given by ubNodeIdV.
**
*/
ComStatus_tv   ComEmcyConsEnable(uint8_t ubNetV, uint8_t ubNodeIdV,
                                 uint8_t ubEnableV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubNodeIdV - Node-ID value of CANopen device
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** The function is called by the CANopen Master stack upon reception of
** an Emergency message (EMCY). The Emergency message has to be configured
** by ComEmcyConsEnable() in advance.
**
*/
void           ComEmcyConsEventReceive(uint8_t ubNetV, uint8_t ubNodeIdV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubNodeIdV - Node-ID value of CANopen device
** \param[in]     pubDataV - Pointer to data
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** The functions reads the data of the EMCY message from a CANopen device
** using the Node-ID value \a ubNodeIdV. The size of the data buffer is
** 8 bytes.
*/

ComStatus_tv   ComEmcyConsGetData(uint8_t ubNetV, uint8_t ubNodeIdV,
                                  uint8_t * pubDataV);

ComStatus_tv   ComEmcyConsGetId(uint8_t ubNetV, uint8_t ubNodeIdV,
                                uint32_t * pulIdV);

ComStatus_tv   ComEmcyConsIsEnabled(uint8_t ubNetV, uint8_t ubNodeIdV,
                                    uint8_t * pubEnableV);

ComStatus_tv   ComEmcyConsSetId(uint8_t ubNetV, uint8_t ubNodeIdV,
                                uint32_t ulIdV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubEnableV  - Enable/Disable EMCY service
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function enables (\a ubEnableV = 1) or disables (\a ubEnableV = 0)
** the EMCY service of the CANopen Master. The EMCY service is enabled by
** default.
**
*/
ComStatus_tv   ComEmcyEnable(uint8_t ubNetV, uint8_t ubEnableV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[out]    pulIdV  - Pointer to identifier value
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComEmcySetId()
**
** This function reads the identifier value used by the EMCY service.
**
*/
ComStatus_tv   ComEmcyGetId(uint8_t ubNetV, uint32_t * pulIdV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[out]    pulTimeV - Pointer to EMCY inhibit time
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComEmcySetInhibit()
**
** This function retrieves the inhibit time between two subsequent EMCY
** messages. The pointer \a pulTimeV points to a variable that holds the
** time value in multiples of one microsecond.
*/
ComStatus_tv   ComEmcyGetInhibit(uint8_t ubNetV, uint32_t * pulTimeV);


ComStatus_tv   ComEmcyIsEnabled(uint8_t ubNetV, uint8_t * pubEnableV);

ComStatus_tv   ComEmcySend(uint8_t ubNetV, uint16_t uwEmcyCodeV,
                           uint8_t *pubManCodeV);

ComStatus_tv   ComEmcySetId(uint8_t ubNetV, uint32_t ulIdV);

ComStatus_tv   ComEmcySetInhibit(uint8_t ubNetV, uint32_t ulTimeV);

/** @} */ // end of group ComEmcy


//-------------------------------------------------------------------
// ComLss functions
//-------------------------------------------------------------------
/*!
** \defgroup ComLss  LSS service
**
** LSS offers the possibility to inquire and change the settings of certain
** parameters of the local layers on a CANopen module with LSS Slave
** capabilities by a CANopen module with LSS Master capabilities via the
** CAN Network. The following parameters can be inquired and/or changed by
** the use of LSS:
** \li   Node-ID of the CANopen Slave
** \li   Bit timing parameters of the physical layer (bit-rate)
** \li   LSS address (Identity Object, Index 1018h)
**
** By using LSS a LSS Slave can be configured for a CANopen network without
** using any devices like DIP-switches for setting the parameters.
**
** @{
*/


//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubBittimeSelV - New bit-timing value
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** By means of the Configure Bit Timing Parameters service the LSS Master
** sets the new bit-timing on a LSS Slave.
*/
ComStatus_tv   ComLssConfigureBitTiming(uint8_t ubNetV, uint8_t ubBittimeSelV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubNodeIdV - New Node-ID value
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** By means of this service the LSS Master configures the NMT-address
** parameter of a LSS Slave. This service allows only one LSS Slave in
** configuration mode. The remote result parameter confirms the success
** or failure of the service. In case of a failure optionally the reason
** is confirmed.
*/
ComStatus_tv   ComLssConfigureNodeId(uint8_t ubNetV, uint8_t ubNodeIdV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubLssProtocolV - LSS protocol
**
** The function is called by the LSS master state machine upon reception of
** a LSS response message issued by the LSS slave device. The parameter
** \a ubNetV defines the CANopen network. The value of the  parameter
** \a ubLssProtocolV is defined by the enumeration #ComLssProt_e.
** <p>
*/
void           ComLssEventReceive(uint8_t ubNetV, uint8_t ubLssProtocolV);

//-----------------------------------------------------------------------------
/*!
** \brief   Run Fastscan protocol
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ulVendorIdV - Vendor ID (1018h, sub 1)
** \param[in]     ulProdCodeV - Product code (1018h, sub 2)
** \param[in]     ulRevisionNumV - Revision number (1018h, sub 3)
** \param[in]     ulSerialNumV - Serial number (1018h, sub 4)
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** The function starts the LSS Fastscan protocol on the given logical
** network \a ubNetV. If one of the parameters \a ulVendorIdV .. \a ulSerialNumV
** is not equal to zero the value is assumed to be known and will not be scanned.
** The result of the operation is notified via the ComLssEventReceive() function.
*/
ComStatus_tv   ComLssFastscan(uint8_t ubNetV,
                              uint32_t ulVendorIdV,
                              uint32_t ulProdCodeV,
                              uint32_t ulRevisionNumV,
                              uint32_t ulSerialNumV);

int32_t        ComLssGetAddrSerialNum(uint8_t ubNetV);

ComStatus_tv   ComLssGetStatus(uint8_t ubNetV, uint8_t * pubStatusV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function starts the Identify non-configured remote slave protocol.
** If there are non-configured remote slaves in the network, the status
** will be set to eCOM_LSS_STAT_SUCCESS, otherwise the status will be
** eCOM_LSS_STAT_TIMEOUT.
*/
ComStatus_tv   ComLssIdentifyNonConfiguredSlave(uint8_t ubNetV);

ComStatus_tv   ComLssInquiryService(uint8_t ubNetV, uint8_t ubServiceV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     uwTimeV  - Timeout value in milliseconds
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function sets a timeout value for a LSS communication. If the
** response to a LSS request by the master takes longer than this
** timeout value, the state of the communication will be changed
** to eCOM_LSS_STAT_TIMEOUT. The state of the LSS communication can
** be evaluated by calling ComLssGetStatus(). Please note that the
** timeout value is a multiple of the timer period (COM_TIMER_PERIOD).
** A value supplied to this function will be rounded towards the
** next lower value if necessary.
** <p>
** For LSS Fastscan, the configured timeout value is uwTimeV / 10
** in order to increase the speed of Fastscan algorithm.
*/
ComStatus_tv   ComLssSetTimeout(uint8_t ubNetV, uint16_t uwTimeV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function is used to store the configured parameters.
**
*/
ComStatus_tv   ComLssStoreConfiguration(uint8_t ubNetV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubModeV - LSS mode
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComLssSwitchModeSelective()
**
** The Switch Mode Services control the mode attribute of a LSS Slave.
** LSS provides two ways to put a LSS Slave into configuration mode,
** Switch Mode Global and Switch Mode Selective. Switch Mode Selective
** switches exactly one LSS Slave between configuration and operation mode.
** Switch Mode Global switches all LSS Slaves between configuration and
** operation mode.
** <p>
** Possible values for the parameter \a ubModeV are defined by the
** enumeration #ComLssMode_e.
*/
ComStatus_tv   ComLssSwitchModeGlobal(uint8_t ubNetV, uint8_t ubModeV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ulVendorIdV - Vendor ID (1018h, sub 1)
** \param[in]     ulProdCodeV - Product code (1018h, sub 2)
** \param[in]     ulRevisionNumV - Revision number (1018h, sub 3)
** \param[in]     ulSerialNumV - Serial number (1018h, sub 4)
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComLssSwitchModeGlobal()
**
** The Switch Mode Services control the mode attribute of a LSS Slave.
** LSS provides two ways to put a LSS Slave into configuration mode,
** Switch Mode Global and Switch Mode Selective. Switch Mode Selective
** switches exactly one LSS Slave between configuration and operation mode.
** Switch Mode Global switches all LSS Slaves between configuration and
** operation mode.
*/
ComStatus_tv   ComLssSwitchModeSelective(uint8_t ubNetV,
                                         uint32_t ulVendorIdV,
                                         uint32_t ulProdCodeV,
                                         uint32_t ulRevisionNumV,
                                         uint32_t ulSerialNumV);
/** @} */ // end of group ComLss


//-------------------------------------------------------------------
// ComMgr functions
//-------------------------------------------------------------------
/*!
** \defgroup ComMgr   CANopen manager
**
** This module holds all functions for the initialisation and control
** of the CANopen Master.
** <p>
** The CANopen Master is initialised with ComMgrInit(). This routine
** will setup the CAN controller and initialise all necessary services.
** Afterwards the stack can be started by calling the ComMgrStart(),
** which will issue a boot-up message for the CANopen Master.
** <p>
** In summary three steps are necessary to start the CANopen Master:
** \li Initialise CANopen Master Stack: ComMgrInit()
** \li Start CANopen Master: ComMgrStart()
** \li Start the timer event function: ComMgrTimerEvent()
**
** The following example depicts this process:
** \code
** void MyComInit(void)
** {
**   //------------------------------------------------------
**   // Initialise the CANopen Master stack with address 1
**   // Bitrate = 500kBit/s
**   //
**   ComMgrInit(eCP_CHANNEL_1, eCOM_NET_1,
**              eCP_BITRATE_500K, 1,
**              eCOM_MODE_NMT_MASTER);
**   //------------------------------------------------------
**   // start the CANopen master stack
**   //
**   ComMgrStart(eCOM_NET_1);
**
**   //------------------------------------------------------
**   // now the CANopen Master Stack is initialised and
**   // has to be triggered by calling ComMgrTimerEvent()
**}
** \endcode
**
** @{
*/

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ptsBusStateV - pointer to CpState_ts value of bus
**
** This function is called by the stack on a bus state change.
** The implementation on this function is application specific.
*/
void ComMgrEventBus(uint8_t ubNetV, CpState_ts * ptsBusStateV);

//-------------------------------------------------------------------
/*!
** This function returns the major version of the CANopen FD Master
** Library.
*/
uint8_t        ComMgrGetVersionMajor(void);

//-------------------------------------------------------------------
/*!
** This function returns the minor version of the CANopen FD Master
** Library.
*/
uint8_t        ComMgrGetVersionMinor(void);

//-------------------------------------------------------------------
/*!
** \param[in]     ubTypeV - Information type

** This function returns a version string of the CANopen FD Master
** Library. The parameter \a ubTypeV defines the requested information,
** possible values are defined by the enumeration #ComVersion_e.
*/
const char *   ComMgrGetVersionString(uint8_t ubTypeV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubCanIfV - CAN interface index
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubBitrateSelV - Bit-rate selection
** \param[in]     ubNodeIdV  - Node-ID value
** \param[in]     ulModeV    - Initial mode
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComMgrRelease()
**
** This function must be called before any other function of the CANopen
** Master stack. It is responsible for the initialisation of all services
** (NMT, SYNC, SDO, PDO, etc). <p>
**
** The function assigns the logical CANopen network number \a ubNetV to
** the CAN interface given by \c ubCanIfV. The value for \a ubNetV can
** be taken from the #ComNet_e enumeration. The maximum value is given by
** the symbol #COM_NET_MAX.
** <p>
** The initial mode parameter \a ulModeV defines the startup behaviour.
** Valid values are defined in the enumeration #ComMode_e.
**
**
*/
ComStatus_tv   ComMgrInit( uint8_t ubCanIfV, uint8_t ubNetV,
                           uint8_t ubBaudSelV, uint8_t ubNodeIdV,
                           uint32_t ulModeV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function is called by ComMgrInit() during the initialisation
** phase. It is responsible for setting internal values of the Master.
** The behaviour of this function is application specific.
*/
ComStatus_tv   ComMgrUserInit(uint8_t ubNetV);

ComStatus_tv   ComMgrNodeAdd(uint8_t ubNetV, uint8_t ubNodeIdV,
                             ComNode_ts * ptsNodeV);


ComStatus_tv   ComMgrNodeDelete(uint8_t ubNetV, uint8_t ubNodeIdV);

uint8_t        ComMgrNodeId(uint8_t ubNetV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return  Value of enumeration #ComErr_e
** \see     ComMgrInit()
**
** This function performs a shutdown of the CANopen FD Master.
*/

ComStatus_tv   ComMgrRelease(uint8_t ubNetV);


//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubSetErrorV - Set new new error state
** \param[in]     ubResetErrorV - Clear error state
** \return  Value of enumeration #ComErr_e
**
** This function sets and clears bit-masked error states of the
** error register.
**
*/
ComStatus_tv   ComMgrSetErrorRegister( uint8_t ubNetV,
                                       uint8_t ubSetErrorV,
                                       uint8_t ubResetErrorV);

//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return  Value of enumeration #ComErr_e
** \see     ComMgrStop()
*/
ComStatus_tv   ComMgrStart(uint8_t ubNetV);


//-------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return  Value of enumeration #ComErr_e
** \see     ComMgrStart()
*/
ComStatus_tv   ComMgrStop(uint8_t ubNetV);

//-------------------------------------------------------------------
/*!
** \brief   Execute Timer-based Services
**
** This routine must be called by a timer resource of the target
** system. It is responsible to call services that depend on a
** timer (e.g. Heartbeat). The period of the timer is defined
** via the ComTmrSetPeriod() value.
**
** \b Example
** \code
** //-------------------------------------------------------------//
** // Timer handler                                               //
** //                                                             //
** //-------------------------------------------------------------//
** void MyTimerHandler(void)
** {
**    //... timer services of application ...
**
**    //--- call CANopen stack timer function -------------
**    ComMgrTimerEvent();
**
** }
** \endcode
**
*/
void           ComMgrTimerEvent(void);



/** @} */ // end of group ComMgr


//-------------------------------------------------------------------
// ComNmt functions
//-------------------------------------------------------------------

/*!
** \defgroup ComNmt  NMT service
**
** The CANopen Network Management (NMT) is used to change the state
** of a CANopen slave node. This module holds functions for the protocol
** stack to behave in both ways: as Master or as Slave. If the protocol
** stack is started in Slave mode (refer to the ComMgrInit() function),
** the protocol stack must react on NMT messages. If started in Master
** mode, the protocol stack holds the NMT resource and is allowed to send
** NMT messages.
**
** @{
*/

//-----------------------------------------------------------------------------
/*!
** \brief   NMT event callback - Active NMT master
** \param   ubNetV - CANopen Network channel
** \param   ubPriorityV - NMT master priority
** \param   ubNodeIdV - Node-ID value
**
**
** This function is called by the stack on a NMT active master
** indication. The action on this function is application specific.
*/
void           ComNmtEventActiveMaster(uint8_t ubNetV,
                                       uint8_t ubPriorityV, uint8_t ubNodeIdV);

void           ComNmtEventGuarding(uint8_t ubNetV, uint8_t ubNodeIdV,
                                   uint8_t ubReasonV);


//-----------------------------------------------------------------------------
/*!
** \brief   NMT event callback - Heartbeat
** \param   ubNetV - CANopen Network channel
** \param   ubNodeIdV - Node-ID value
**
**
** This function is called by the stack on a NMT heartbeat event.
** The action on this function is application specific.
*/
void           ComNmtEventHeartbeat(uint8_t ubNetV, uint8_t ubNodeIdV);


//-----------------------------------------------------------------------------
/*!
** \brief   NMT event callback - State change
** \param   ubNetV - CANopen Network channel
** \param   ubNodeIdV - Node-ID value
** \param   ubNmtStateV - New NMT state
**
**
** This function is called by the stack on a NMT state change event.
** Possible values for \a ubNmtStateV are listed in the #ComNmtState_e
** enumeration. The action on this function is application specific.
*/
void           ComNmtEventStateChange( uint8_t ubNetV, uint8_t ubNodeIdV,
                                       uint8_t ubNmtStateV);


//-----------------------------------------------------------------------------
/*!
** \brief   NMT event callback - ID collision
** \param   ubNetV - CANopen Network channel
**
**
** This function is called by the stack on a NMT identifier collision.
** The action on this function is application specific.
*/
void           ComNmtEventIdCollision(uint8_t ubNetV);

//-----------------------------------------------------------------------------
/*!
** \brief   NMT master detection callback
** \param   ubNetV - CANopen Network channel
** \param   ubResultV - Result of NMT master detection
** \sa      ComNmtMasterDetection()
**
**
** This function is called by the stack as result on a NMT master detection
** procedure. Possible values for the parameter \a ubResultV are
** \li   eCOM_NMT_DETECT_SUCCESS
** \li   eCOM_NMT_DETECT_TIMEOUT
**
** The value \c eCOM_NMT_DETECT_SUCCESS means that a NMT master device is
** available in the network. The CANopen master stack shall not be used
** as NMT master in that case. The values \c eCOM_NMT_DETECT_TIMEOUT
** denotes that there was no response from another NMT master in the
** network and the CANopen master stack may be used as NMT master.
**
** The action on this function is application specific.
*/
void           ComNmtEventMasterDetection(uint8_t ubNetV, uint8_t ubResultV);

/*!
** \brief   NMT reset event callback
** \param   ubNetV - CANopen Network channel
**
**
** This function is called by the stack on a NMT reset remote node command.
** The action on this function is application specific.
*/
void           ComNmtEventResetNode(uint8_t ubNetV);


/*!
** \brief   NMT reset event callback
** \param   ubNetV - CANopen Network channel
**
**
** This function is called by the stack on a NMT reset communication command.
** The action on this function is application specific.
*/
void           ComNmtEventResetCommunication(uint8_t ubNetV);

ComStatus_tv   ComNmtGetHbConsTime( uint8_t ubNetV, uint8_t ubNodeIdV,
                                    uint16_t * puwTimeV);

//-----------------------------------------------------------------------------
/*!
** \param   ubNetV - CANopen Network channel
** \param   puwTimeV - Pointer to heartbeat timer value
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComNmtSetHbProdTime()
**
** This function retrieves the heartbeat producer time for the CANopen
** Master. The value passed to the pointer \a puwTimeV is given in
** multiples of 1 millisecond.
*/
ComStatus_tv   ComNmtGetHbProdTime(uint8_t ubNetV, uint16_t * puwTimeV);

//-----------------------------------------------------------------------------
/*!
** \param   ubNetV - CANopen Network channel
** \param   pulTimeV - Pointer to NMT inhibit time
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComNmtSetInhibit()
**
** This function retrieves the inhibit time between two subsequent NMT messages.
** The pointer \a pulTimeV points to a variable that holds the time value in
** multiples of one microsecond.
*/
ComStatus_tv   ComNmtGetInhibit(uint8_t ubNetV, uint32_t * pulTimeV);

//-----------------------------------------------------------------------------
/*!
** \param   ubNetV - CANopen Network channel
** \param   ubNodeIdV - Node-ID value
** \param   pubStateV - Pointer to NMT state variable
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComNmtSetNodeState()
**
** This function retrieves the NMT state of the CANopen device with the
** Node-ID \c ubNodeIdV. Possible values for \a ubNodeIdV are 1 .. 127.
** The value passed to the pointer \a pubStateV is taken from the
** #ComNmtState_e enumeration.
*/
ComStatus_tv   ComNmtGetNodeState(  uint8_t ubNetV, uint8_t ubNodeIdV,
                                    uint8_t * pubStateV);
//-----------------------------------------------------------------------------
/*!
** \param   ubNetV - CANopen Network channel
**
** \return  1 if NMT master, 0 if NMT slave
**
** This function checks if the device is the NMT master or not.
*/
ComStatus_tv   ComNmtIsMaster(uint8_t ubNetV);

//-----------------------------------------------------------------------------
/*!
** \param   ubNetV - CANopen Network channel
** \param   ubBootupV - set to 1 if run upon bootup
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComNmtEventMasterDetection()
**
**
** This function starts the NMT master detection.
*/
ComStatus_tv   ComNmtMasterDetection(uint8_t ubNetV, uint8_t ubBootupV);

ComStatus_tv   ComNmtFlyingMaster(uint8_t ubNetV);

ComStatus_tv   ComNmtSetHbConsTime( uint8_t ubNetV, uint8_t ubNodeIdV,
                                    uint16_t uwTimeV);

//-----------------------------------------------------------------------------
/*!
** \param   ubNetV - CANopen Network channel
** \param   uwTimeV - Heartbeat timer value
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComNmtGetHbProdTime()
**
** This function sets the heartbeat producer time for the CANopen Master.
** The value passed to \a uwTimeV is given in multiples of 1 millisecond.
**
*/
ComStatus_tv   ComNmtSetHbProdTime(uint8_t ubNetV, uint16_t uwTimeV);

//-----------------------------------------------------------------------------
/*!
** \param   ubNetV - CANopen Network channel
** \param   ulTimeV - NMT inhibit time
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComNmtGetInhibit()
**
** This function sets the inhibit time between two subsequent NMT messages.
** The parameter \a ulTimeV is given in multiples of 1 microsecond.
*/
ComStatus_tv   ComNmtSetInhibit(uint8_t ubNetV, uint32_t ulTimeV);

//-----------------------------------------------------------------------------
/*!
** \param   ubNetV - CANopen Network channel
** \param   ubNodeIdV - Node-ID value
** \param   ubStateV - New NMT state
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see     ComNmtGetNodeState()
**
** This function changes the NMT state of the CANopen device with the
** Node-ID \a ubNodeIdV. Possible values for \a ubNodeIdV are 0 .. 127.
** A value of 0 addresses all devices in the network. Passing the address
** of the CANopen Master to \a ubNodeIdV will change the NMT state of the
** Master. <p>
** The value passed to \a ubStateV is taken from the #ComNmtState_e
** enumeration.
*/
ComStatus_tv   ComNmtSetNodeState(  uint8_t ubNetV, uint8_t ubNodeIdV,
                                    uint8_t ubStateV);


/** @} */ // end of group ComNmt

//-----------------------------------------------------------------------------
// ComNode functions
//
uint8_t        ComNodeGetIdFlag(ComNodeIdFlag_ts * ptsNodeIdFlagV);

ComStatus_tv   ComNodeGetInfo(uint8_t ubNetV, uint8_t ubNodeIdV);

ComStatus_tv   ComNodeRestore(uint8_t ubNetV, uint8_t ubNodeIdV,
                              uint8_t ubParmSelV);

void           ComNodeSetDefault(ComNode_ts * ptsNodeV);

ComStatus_tv   ComNodeSetHbProdTime(uint8_t ubNetV, uint8_t ubNodeIdV,
                                    uint16_t uwHeartbeatV);

void           ComNodeSetIdFlag(uint8_t ubNodeIdV,
                                ComNodeIdFlag_ts * ptsNodeIdFlagV);

ComStatus_tv   ComNodeStore(uint8_t ubNetV, uint8_t ubNodeIdV,
                            uint8_t ubParmSelV);


//-----------------------------------------------------------------------------
// ComPdo functions
//-----------------------------------------------------------------------------
/*!
** \defgroup ComPdo  PDO service
**
** The real-time data transfer is performed by means of "Process Data Objects
** (PDO)". The transfer of PDOs is performed with no protocol overhead. The
** PDOs correspond to entries in the device Object Dictionary and provide the
** interface to the application objects. Data type and mapping of application
** objects into a PDO is determined by a corresponding default PDO mapping
** structure within the Device Object Dictionary. If variable PDO-mapping is
** supported the number of PDOs and the mapping of application objects into a
** PDO may be transmitted to a device during the device configuration process
** by applying the SDO services (see com_sdo_cln.h) to the corresponding entries
** of the Object Dictionary. Number and length of PDOs of a device is application
** specific and are specified within the device profile.
** <p>
** There are two kinds of use for PDOs. The first is data transmission and the
** second data reception. It is distinguished in Transmit-PDOs (TPDOs) and
** Receive-PDOs (RPDOs). Devices supporting TPDOs are PDO producer and devices
** which are able to receive PDOs are called PDO consumer.
** <p>
** In order to access the maximum number of PDOs, the API uses the parameter
** \a uwPdoNumV, which is called PDO number. The value for PDO number is 0 to
** #COM_PDO_RCV_MAX - 1 for Receive PDOs and 0 to #COM_PDO_TRM_MAX - 1 for
** Transmit PDOs.
**
** @{
*/

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     uwPdoNumV - PDO number
** \param[in]     ubPdoDirV - PDO direction
** \param[in]     ulIdV - PDO identifier
** \param[in]     ubDlcV - PDO DLC value
** \param[in]     ubTypeV - PDO transmission type
** \param[in]     uwTimeV - PDO timer
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function adds a new PDO to the CANopen Master. The PDO direction
** (TPDO or RPDO) is defined by the parameter \a ubPdoDirV. The parameter
** \a uwPdoNumV denotes the PDO number.
**
** \b Example
** \code
** void MyPdoSetup(void)
** {
**    //---------------------------------------------------
**    // add first receive PDO, ID = 0x201
**    //
**    ComPdoConfig(eCOM_NET_1, 0, ePDO_DIR_RCV,
**                 0x201, 8, ePDO_TYPE_EVENT_PROFILE, 0);
**
**    //---------------------------------------------------
**    // add two transmit PDOs, ID = 0x181 & 0x281
**    //
**    ComPdoConfig(eCOM_NET_1, 0, ePDO_DIR_TRM
**                 0x181, 8, ePDO_TYPE_EVENT_PROFILE, 0);
**    ComPdoConfig(eCOM_NET_1, 1, ePDO_DIR_TRM,
**                 0x281, 8, ePDO_TYPE_EVENT_PROFILE, 0);
**
** }
** \endcode
*/
ComStatus_tv   ComPdoConfig(uint8_t ubNetV, uint16_t uwPdoNumV, 
                            uint8_t ubPdoDirV, uint32_t ulIdV, uint8_t ubDlcV, 
                            uint8_t ubTypeV, uint16_t uwTimeV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     uwPdoNumV - PDO number
** \param[in]     ubPdoDirV - PDO direction
** \param[in]     ubEnableV  - Enable/Disable PDO
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function enables (\a ubEnableV = 1) or disables (\a ubEnableV = 0)
** the PDO with index \a uwPdoNumV. A PDO is disabled by default upon creation
** (see ComPdoConfig()).
**
*/
ComStatus_tv   ComPdoEnable(uint8_t ubNetV, uint16_t uwPdoNumV, 
                            uint8_t ubPdoDirV, uint8_t ubEnableV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     uwPdoNumV - PDO number
**
** The function is called by the CANopen Master stack upon reception of
** a Receive-PDO (RPDO). The Receive PDO has to be configured by
** ComPdoConfig() in advance.
*/
void           ComPdoEventReceive(uint8_t ubNetV, uint16_t uwPdoNumV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     uwPdoNumV - PDO number
**
** The function is called by the CANopen Master stack when reception of
** a Receive-PDO (RPDO) times out. The Receive PDO has to be configured by
** ComPdoConfig() in advance.
**
*/
void           ComPdoEventTimeout(uint8_t ubNetV, uint16_t uwPdoNumV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     uwPdoNumV - PDO number
** \param[out]    pulCounterV - Pointer to counter variable
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** The function returns the number of PDOs that have been sent (for
** Transmit-PDOs) or received (for Receive-PDOs) by the CANopen Master.
**
*/
ComStatus_tv   ComPdoGetCounter( uint8_t ubNetV, uint16_t uwPdoNumV,
                                 uint8_t ubPdoDirV, 
                                 uint32_t * pulCounterV);

//-----------------------------------------------------------------------------
/*!
** \brief   Get PDO data
** \param[in]     ubNetV    - CANopen Network channel
** \param[in]     uwPdoNumV - PDO number
** \param[in]     ubPdoDirV - PDO direction
** \param[out]    pubDataV  - Pointer to data buffer
**
** \return  Value of enumeration #ComErr_e
**
** The function reads 8 bytes of data from the PDO defined by the
** parameter \a uwPdoNumV. The application must guarantee that
** \a pubDataV points to a buffer with at least 8 bytes.
**
*/
ComStatus_tv   ComPdoGetData(uint8_t ubNetV, uint16_t uwPdoNumV,
                             uint8_t ubPdoDirV, uint8_t * pubDataV);


//-----------------------------------------------------------------------------
/*!
** \brief   Get DLC of a PDO
** \param[in]     ubNetV    - CANopen Network channel
** \param[in]     uwPdoNumV - PDO number
** \param[in]     ubPdoDirV - PDO direction
** \param[out]    pubDlcV   - Pointer to buffer for data length code
**
** \return  Value of enumeration #ComErr_e
**
** The function reads the DLC of a PDO and saves it inside the location
** pointed by \a pubDlcV.
**
*/
ComStatus_tv   ComPdoGetDlc(uint8_t ubNetV, uint16_t uwPdoNumV,
                            uint8_t ubPdoDirV, uint8_t * pubDlcV);

ComStatus_tv   ComPdoGetId(uint8_t ubNetV, uint16_t uwPdoNumV,
                           uint8_t ubPdoDirV, uint32_t * pulIdV);

ComStatus_tv   ComPdoGetTimer(uint8_t ubNetV, uint16_t uwPdoNumV,
                              uint8_t ubPdoDirV, uint16_t * puwTimeV);

ComStatus_tv   ComPdoGetType(uint8_t ubNetV, uint16_t uwPdoNumV,
                             uint8_t ubPdoDirV, uint8_t * ubTypeV);

ComStatus_tv   ComPdoIsEnabled(uint8_t ubNetV, uint16_t uwPdoNumV,
                               uint8_t ubPdoDirV);

//------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return        Value of enumeration #ComErr_e
**
** The function removes all messages inside the PDO receive queue.
*/
ComStatus_tv   ComPdoQueueClear(uint8_t ubNetV);


//------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[out]    puwCountV - Number of messages present in the queue
**
** \return        Value of enumeration #ComErr_e
**
** The function retrieves the number of pending elements inside a PDO
** receive queue.
*/
ComStatus_tv   ComPdoQueueCount(uint8_t ubNetV, uint16_t *puwCountV);


//------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return        Value of enumeration #ComErr_e
** \see           ComPdoQueueEnable()
**
** The function disables the PDO receive queue on the selected CANopen
** network channel.
**
*/
ComStatus_tv   ComPdoQueueDisable(uint8_t ubNetV);


//------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
**
** \return        Value of enumeration #ComErr_e
** \see           ComPdoQueueDisable()
**
** The function enables the PDO receive queue on the selected CANopen
** network channel.
*/
ComStatus_tv   ComPdoQueueEnable(uint8_t ubNetV);


//------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[out]    ptsCanMsgV - Pointer to CAN message structure
**
** \return        Value of enumeration #ComErr_e
**
** The function fetches one CAN message from the PDO receive queue.
*/
ComStatus_tv   ComPdoQueueFetch(uint8_t ubNetV, CpCanMsg_ts * ptsCanMsgV);


//-----------------------------------------------------------------------------
ComStatus_tv   ComPdoRelease(uint8_t ubNetV, uint16_t uwPdoNumV,
                             uint8_t ubPdoDirV);

//-----------------------------------------------------------------------------
ComStatus_tv   ComPdoSendAsync(uint8_t ubNetV, uint16_t uwPdoNumV);

//-----------------------------------------------------------------------------
ComStatus_tv   ComPdoSetCounter( uint8_t ubNetV, uint16_t uwPdoNumV,
                                 uint8_t ubPdoDirV, uint32_t ulCounterV);

//-----------------------------------------------------------------------------
/*!
** \brief   Set PDO Data
** \param[in]     ubNetV    - CANopen Network channel
** \param[in]     uwPdoNumV - PDO number
** \param[in]     ubPdoDirV - PDO direction
** \param[in]     pubDataV  - Pointer to data (an array of 8 byte)
**
** \return  Value of enumeration #ComErr_e
**
** The function writes 8 bytes of data to the PDO defined by the
** parameter \a uwPdoNumV.
**
*/
ComStatus_tv   ComPdoSetData( uint8_t ubNetV, uint16_t uwPdoNumV,
                              uint8_t ubPdoDirV, uint8_t * pubDataV);

//-----------------------------------------------------------------------------
ComStatus_tv   ComPdoSetTimer(uint8_t ubNetV, uint16_t uwPdoNumV,
                              uint8_t ubPdoDirV, uint16_t uwTimeV);


//-----------------------------------------------------------------------------
ComStatus_tv   ComPdoSetType( uint8_t ubNetV, uint16_t uwPdoNumV,
                              uint8_t ubPdoDirV, uint8_t ubTypeV);

/** @} */ // end of group ComPdo

//-------------------------------------------------------------------
// ComSafety functions
//-------------------------------------------------------------------
/*!
** \defgroup ComSafety  CANopen safety
*/
enum ComSafetyState_e
{

   /*! State machine is in initialisation state    */
   eCOM_SAFETY_STATE_INIT = 0x01,

   /*! State machine is in safe state              */
   eCOM_SAFETY_STATE_SAFE = 0xA5,

   /*! State machine is in working state           */
   eCOM_SAFETY_STATE_WORK = 0xCC
};


typedef struct ComSrdo_s
{

   /*! SRDO communication parameter, 130xh:01h        */
   uint8_t  ubDirection;

   /*! SRDO communication parameter, 130xh:02h        */
   uint16_t uwRefreshTime;

   /*! SRDO communication parameter, 130xh:03h        */
   uint8_t  ubValidationTime;

   /*! SRDO communication parameter, 130xh:05h        */
   uint32_t ulCobId1;

   /*! SRDO communication parameter, 130xh:06h        */
   uint32_t ulCobId2;

   /*! SRDO mapping parameter, 138xh:00h              */
   uint8_t  ubMappingSub0;

   //SRDO_Mapping_ts   atsMapping[COM_SAFETY_MAPPING_SIZE * 2];

}  ComSrdo_ts;

ComStatus_tv ComSafetyGetConfiguration(uint8_t ubNetV,
                                       uint8_t ubNodeIdV, uint8_t ubSrdoNumV);

uint16_t     ComSafetyGetCrcValue(ComSrdo_ts * ptsSrdoV);

ComStatus_tv ComSafetyGetSdoStatus(uint8_t ubNetV,
                                   uint8_t ubNodeIdV, uint8_t ubSrdoNumV,
                                   enum ComSdoStat_e * pteStatusV);

ComStatus_tv ComSafetySetConfigurationValid(uint8_t ubNetV, uint8_t ubNodeIdV);

ComStatus_tv ComSafetySetSignature(uint8_t ubNetV,
                                   uint8_t ubNodeIdV, uint8_t ubSrdoNumV,
                                   uint16_t uwSignatureV);

ComStatus_tv ComSafetySrdoInit(uint8_t ubNetV,
                               uint8_t ubNodeIdV, uint8_t ubSrdoNumV,
                               ComSrdo_ts * ptsSrdoV);

void     ComSafetySrdoRcvDataUpdate(uint8_t ubNetV,
                                    uint8_t ubNodeIdV, uint8_t ubSrdoNumberV);

void     ComSafetySrdoTrmDataUpdate(uint8_t ubNetV,
                                    uint8_t ubNodeIdV, uint8_t ubSrdoNumberV);

/** @} */ // end of group ComSafety


//------------------------------------------------------------------------------------------------------
// ComSdo functions
//------------------------------------------------------------------------------------------------------
/*!
** \defgroup ComSdo  SDO service
**
** With Service Data Objects (SDOs) the access to entries of a device Object Dictionary is provided. As
** these entries may contain data of arbitrary size and data type SDOs can be used to transfer multiple
** data sets (each containing an arbitrary large block of data) from a client to a server and vice versa.
** The client can control via a multiplexor (index and sub-index of the Object Dictionary) which data
** set is to be transferred. The contents of the data set are defined within the Object Dictionary.
** <p>
** The communication timeout between SDO client request and SDO server response is device/application
** specific. The initial SDO communication timeout for the client is set to 50 milliseconds. The
** connection timeout value can be change with the ComSdoSetTimeout() function.
**
** @{
*/

/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubNodeIdV - Node-ID value
** \param[in,out] ptsCoObjV - Pointer to object structure
** \param[out]    pulAbortV - Pointer to SDO abort code
**
** This handler is called after the SDO data transfer has finished. If the
** SDO transfer has been initiated by ComSdoReadObject() or ComSdoWriteObject()
** the parameter \a ptsCoObjV points to the last object which has been read or
** written. Otherwise the pointer \a ptsCoObjV is 0L. The user defined marker
** within the structure CoObject_ts can be used to track SDO operations.
** <p>
** In case of a SDO abort, the pointer \a pulAbortV allows to read the last
** abort code. The value of \a pulAbortV is 0L when no SDO error occurred.
*/
void           ComSdoEventObjectReady(uint8_t ubNetV, uint8_t ubNodeIdV,
                                      CoObject_ts * ptsCoObjV,
                                      uint32_t * pulAbortV);


//------------------------------------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubNodeIdV - Node-ID value
** \param[in]     uwIndexV  - Object index value
** \param[in]     ubSubIndexV - Object sub-index value
** \param[in]     ulByteCntV - Byte counter value
**
** This handler is called during a SDO block download or upload. The parameters \a uwIndexV and
** \a ubSubIndexV define the object which is accessed. The value \a ulByteCntV denotes the number of
** bytes that have been transmitted.
*/
void           ComSdoEventProgress(uint8_t ubNetV, uint8_t ubNodeIdV, 
                                   uint16_t uwIndexV, uint8_t ubSubIndexV,
                                   uint32_t ulByteCntV);


//------------------------------------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubNodeIdV - Node-ID value
** \param[in]     uwIndexV  - Object index value
** \param[in]     ubSubIndexV - Object sub-index value
**
** \see     ComSdoSetTimeout()
**
** This handler is called if a SDO response time-out condition occurred. The parameters \a uwIndexV and
** \a ubSubIndexV define the object that was accessed. The SDO communication timeout can be configured
** by the ComSdoSetTimeout() function.
*/
void           ComSdoEventTimeout(uint8_t ubNetV, uint8_t ubNodeIdV, 
                                  uint16_t uwIndexV, uint8_t ubSubIndexV);

//------------------------------------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubSdoV - SDO client index
** \param[out]    pulAbortV - Pointer to variable for abort code
**
** \return  #ComSdoStat_e value on success, negative #ComErr_e value on failure
**
** This function returns the last SDO abort code, if any occurred. The SDO client connection is selected
** by the index \c ubSdoV. A negative return value indicates an error. The error values are taken from
** the #ComErr_e enumeration. The return value #eCOM_ERR_NONE indicates that there was a SDO abort on the
** selected SDO client, which is copied to the variable pointed by \c pulAbortV.
** <p>
** Positive return values indicate the status of a SDO client in use.
*/
ComStatus_tv   ComSdoGetAbortCode(uint8_t ubNetV, uint8_t ubSdoV,
                                  uint32_t * pulAbortV);

//------------------------------------------------------------------------------------------------------
/*!
** \brief   Get available SDO client index
** \param[in]     ubNetV - CANopen Network channel
**
** \return  SDO client index
**
** This function returns the index of an available SDO client. If no SDO client is free, the function
** will return the value #COM_SDO_CLIENT_MAX. The first SDO client starts at index 0.
*/
uint8_t        ComSdoGetClient(uint8_t ubNetV);

//------------------------------------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubSdoV - SDO client index
**
** \return  #ComSdoStat_e value on success, negative #ComErr_e value on failure
**
** This function returns the status of a SDO transmission for
** the SDO client connection given by its index \c ubSdoV. A negative return
** value indicates an error. The error values are taken from the #ComErr_e
** enumeration. The return value #eCOM_SDO_STAT_EMPTY indicates that the
** SDO client is available for a read/write operation. Positive return values
** (see #ComSdoStat_e) indicate the status of a SDO client in use.
*/
ComStatus_tv   ComSdoGetStatus(uint8_t ubNetV, uint8_t ubSdoV);

ComStatus_tv   ComSdoReadData(uint8_t ubNetV, uint8_t ubSdoV, uint8_t ubNodeIdV,
                              uint16_t uwIndexV, uint8_t ubSubIndexV,
                              void * pvdDataV, uint32_t * pulDataSizeV,
                              uint32_t * pulErrCodeV);

//------------------------------------------------------------------------------------------------------
/*!
** \brief   Read object from CANopen device
** \param[in]     ubNetV     - CANopen Network channel
** \param[in]     ubSdoV     - SDO client index
** \param[in]     ubNodeIdV  - Node-ID value
** \param   ptsCoObjV - Pointer to CANopen object entry
** \param   pulObjCntV - Pointer to variable for object count
**
** \return  Value of enumeration #ComErr_e
** \see     ComSdoWriteObject()
**
** This function will start the read request for an object that is defined by the structure CoObject_ts.
**
*/
ComStatus_tv   ComSdoReadObject( uint8_t ubNetV, uint8_t ubSdoV,
                                 uint8_t ubNodeIdV, CoObject_ts * ptsCoObjV,
                                 uint32_t * pulObjCntV);

ComStatus_tv   ComSdoSendAbort(  uint8_t ubNetV, uint8_t ubSdoV,
                                 uint16_t uwIndexV, uint8_t ubSubIndexV,
                                 uint8_t ubErrCodeV);

ComStatus_tv   ComSdoSetConfiguration(uint8_t ubNetV, uint8_t ubSdoV,
                                      uint8_t ubConfigV);

//------------------------------------------------------------------------------------------------------
/*!
** \brief   Set communication timeout
** \param[in]     ubNetV     - CANopen Network channel
** \param[in]     ubSdoV     - SDO client index
** \param[in]     uwTimeV    - timeout value in milliseconds
**
** \return  Value of enumeration #ComErr_e
**
** This function sets a timeout value for a SDO communication. If the
** response to a SDO request by the master takes longer than this
** timeout value, the state of the communication will be changed
** to #eCOM_SDO_STAT_TIMEOUT. The state of the SDO communication can
** be evaluated by calling ComSdoGetStatus(). Please note that the
** timeout value is passed in multiples of 1 millisecond. The timeout
** value supplied to this function will be rounded towards the
** next lower value if necessary (depends on timer granularity).
*/
ComStatus_tv   ComSdoSetTimeout(uint8_t ubNetV, uint8_t ubSdoV,
                                uint16_t uwTimeV);

uint32_t       ComSdoSrvBlkUpObjectSize(uint8_t ubNetV, uint16_t uwIndexV,
                                        uint8_t ubSubIndexV);

ComStatus_tv   ComSdoWriteData( uint8_t ubNetV, uint8_t ubSdoV,
                                uint8_t ubNodeIdV,
                                uint16_t uwIndexV, uint8_t ubSubIndexV,
                                void * pvdDataV, uint32_t * pulDataSizeV,
                                uint32_t * pulErrCodeV);

//-----------------------------------------------------------------------------
/*!
** \brief   Write object to CANopen device
** \param[in]     ubNetV     - CANopen Network channel
** \param[in]     ubSdoV     - SDO client index
** \param[in]     ubNodeIdV  - Node-ID value
** \param[in]     ptsCoObjV  - Pointer to CANopen object entry
** \param[in,out] pulObjCntV - Pointer to variable for object count
**
** \return  Value of enumeration #ComErr_e
** \see     ComSdoReadObject()
**
** This function will start the write request for an object that is
** defined by the structure CoObject_ts.
**
*/
ComStatus_tv   ComSdoWriteObject(uint8_t ubNetV, uint8_t ubSdoV,
                                 uint8_t ubNodeIdV, CoObject_ts * ptsCoObjV,
                                 uint32_t * pulObjCntV);

/** @} */ // end of group ComSdo


//-----------------------------------------------------------------------------
// ComSync functions
//-----------------------------------------------------------------------------
/*!
** \defgroup ComSync  SYNC Service
**
** The Synchronisation (SYNC) Object is broadcasted periodically by the SYNC
** producer. This SYNC provides the basic network clock. The time period
** between the SYNCs is specified by the standard parameter communication cycle
** period (Object 1006h: Communication Cycle Period), which may be written by a
** configuration tool to the application devices during the boot-up process.
** There can be a time jitter in transmission by the SYNC producer corresponding
** approximately to the latency due to some other message being transmitted just
** before the SYNC. In order to guarantee timely access to the CAN bus the SYNC
** is given a very high priority identifier (1005h).
** <p>
** Devices which operate synchronously may use the SYNC object to synchronise
** their own timing with that of the Synchronisation Object producer. The
** details of this synchronisation are device dependent.
** <p>
** The generation of SYNC messages is disabled by default. The SYNC service
** identifier is set to 080h by default. The following code example shows
** how to change the default identifier to 181h and to generate SYNC messages
** with a cycle time of 10ms.
** \code
** ComSyncSetId(eCOM_NET_1, 0x181);          // set new identifier
** ComSyncSetCycleTime(eCOM_NET_1, 10000);   // set 10 ms cycle time
** ComSyncEnable(eCOM_NET_1, 1);             // start SYNC service
** \endcode
** @{
*/

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     ubEnableV  - Enable/Disable SYNC service
**
** \return     #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function enables (\a ubEnableV = 1) or disables (\a ubEnableV = 0)
** the SYNC service. The SYNC service is disabled by default.
**
*/
ComStatus_tv   ComSyncEnable(uint8_t ubNetV, uint8_t ubEnableV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]     pubCounterV  - Pointer to SYNC counter value
**
** \return        #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function reads the counter value for the SYNC service.
**
*/
ComStatus_tv   ComSyncGetCounter(uint8_t ubNetV, uint8_t * pubCounterV);

//-----------------------------------------------------------------------------
/*!
** \param[in]     ubNetV - CANopen Network channel
** \param[in]  pulIdV  - Pointer to identifier value
**
** \return     #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
** \see        ComSyncSetId()
**
** This function reads the identifier value for the SYNC service.
**
*/
ComStatus_tv   ComSyncGetId(uint8_t ubNetV, uint32_t * pulIdV);

ComStatus_tv   ComSyncGetCycleTime(uint8_t ubNetV, uint32_t * pulTimeV);

ComStatus_tv   ComSyncIsEnabled(uint8_t ubNetV, uint8_t * pubEnableV);

ComStatus_tv   ComSyncSetCounter(uint8_t ubNetV, uint8_t ubCounterV);

//-----------------------------------------------------------------------------
/*!
** \param[in]  ubNetV - CANopen Network channel
** \param[in]  ulIdV  - Identifier value
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function changes the identifier value for the SYNC service. The SYNC
** service must be disabled (see ComSyncEnable()) prior to changing the
** identifier.
**
*/
ComStatus_tv   ComSyncSetId(uint8_t ubNetV, uint32_t ulIdV);

//-----------------------------------------------------------------------------
/*!
** \param[in]  ubNetV - CANopen Network channel
** \param[in]  ulTimeV - cycle time
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function changes the cycle time for the SYNC service. The parameter
** \c ulTimeV is passed as multiple of 1 microsecond.<p>
** Here is an example for setting the SYNC cycle time:
** \dontinclude com_demo_sync.c
** \skip  ComStatus_tv DemoComSyncStart
** \until // DemoComSyncStart
**
*/
ComStatus_tv   ComSyncSetCycleTime(uint8_t ubNetV, uint32_t ulTimeV);

/** @} */ // end of group ComSync

//-----------------------------------------------------------------------------
// ComTmr functions
//-----------------------------------------------------------------------------

/*!
** \defgroup ComTmr  CANopen timer
**
** The are a number of CANopen services which require an internal
** timer (e.g. Heartbeat, timer-driven PDO). The timer values for
** these services are set in a multiple of 1 microsecond or
** 1 millisecond (depends on the service).
** <p>
** The requested time values are converted into timer ticks and
** vice versa with the functions ComTmrCalcTicks() and
** ComTmrCalcTime() respectively.
** @{
*/

//-----------------------------------------------------------------------------
/*!
** \brief   Calculate number of timer ticks
** \param   ulReqTimingV - requested time in microseconds
** \return  number of required timer ticks
** \see     ComTmrCalcTime()
**
** The function calculates the number of required timer ticks
** (i.e. timer interrupts) based on the required time \c ulReqTimingV
** (in microseconds) and the internal timer period (see
** ComTmrSetPeriod()).
**
*/
uint32_t       ComTmrCalcTicks(uint32_t ulReqTimingV);

//-----------------------------------------------------------------------------
/*!
** \brief   Calculate time based on timer ticks
** \param   ulTicksV - number of timer ticks
** \return  time in microseconds
** \see     ComTmrCalcTicks()
**
** The function calculates the time (in microseconds) based on
** the given number of timer ticks and the internal timer period (see
** ComTmrSetPeriod()).
**
*/
uint32_t       ComTmrCalcTime(uint32_t ulTicksV);

//-----------------------------------------------------------------------------
/*!
** \brief   Configure timer period
** \param   ulPeriodV - number of timer ticks
**
** The function sets the timer period which is used to call the
** function ComMgrTimerEvent(). The parameter \a ulPeriodV is a
** multiple of 1 microsecond.
** This function can be used to overwrite the default value during
** run-time.
**
*/
void           ComTmrSetPeriod(uint32_t ulPeriodV);

/** @} */ // end of group ComTmr

//-----------------------------------------------------------------------------
// ComJ1939 functions
//-----------------------------------------------------------------------------
/*!
** \defgroup ComJ1939  J1939 Support
**
** The SAE J1939 module is an optional function for the CANopen Master
** protocol stack. The J1939 support is enabled by setting the value
** #eCOM_MODE_J1939 for parameter \a ulModeV inside the function
** ComMgrInit().
** <p>
** The following example depicts the initialisation:
**
** \code
** void MyJ1939Init(void)
** {
**   //------------------------------------------------------
**   // Initialise J1939 stack with address 1
**   // Bitrate = 500kBit/s
**   //
**   ComMgrInit(eCP_CHANNEL_1, eCOM_NET_1,
**              eCP_BITRATE_500K, 1,
**              eCOM_MODE_J1939);
**   //------------------------------------------------------
**   // start the CANopen master stack
**   //
**   ComMgrStart(eCOM_NET_1);
**
**   //------------------------------------------------------
**   // now the CANopen Master Stack is initialised and
**   // has to be triggered by calling ComMgrTimerEvent()
**}
** \endcode
** @{
*/

//-----------------------------------------------------------------------------
/*!
** \brief   Add a PGN
** \param   ubNetV      - Network channel
** \param   uwPgnIdxV   - PGN index
** \param   ubPgnDirV   - PGN direction
** \param   ulPgnV      - PGN value
** \param   ubPriorityV - PGN priority
** \param   ubAddrV     - address information
** \param   uwTimeV     - PGN timer
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function adds a new PGN to the CANopen Master. The PGN type
** is defined by setting the definition #ePGN_DIR_RCV for Receive-PGNs
** and #ePGN_DIR_TRM for Transmit-PGNs to the parameter \a ubPgnDirV.
** The PGN index \a uwPgnIdxV starts at 0.
** <p>
** The parameter \a ubAddrV is evaluated for Receive-PGNs: only
** PDUs from ECUs with address \a ubAddrV are evaluated. In order
** to receive messages from all ECUs in the network on the defined
** index \a uwPgnIdxV the address parameter must be set to J1939_ADDR_BROADCAST.
**
** \b Example
** \code
** void MyPgnSetup(void)
** {
**    //---------------------------------------------------
**    // add first receive PDU, PGN = 61184, Priority = 3
**    // receive from every ECU in network
**    //
**    ComJ1939_PgnConfig(eCOM_NET_1, ePGN_DIR_RCV, 0, 61184, 3, J1939_ADDR_BROADCAST, 0);
**
**    //---------------------------------------------------
**    // add transmit PDU, PGN = 61444
**    //
**    ComJ1939_PgnAdd(eCOM_NET_1, 0, ePGN_DIR_TRM, 61444, 6, 0, 0);
**
**    //---------------------------------------------------
**    // add transmit PDU, PGN = 65260
**    //
**    ComJ1939_PgnAdd(eCOM_NET_1, 1, ePGN_DIR_TRM, 65260, 6, 0, 0);
**
** }
** \endcode
*/
ComStatus_tv ComJ1939_PgnConfig(uint8_t ubNetV, uint16_t uwPgnIdxV,
                                uint8_t ubPgnDirV, uint32_t ulPgnV,
                                uint8_t ubPriorityV, uint8_t ubAddrV,
                                uint16_t uwTimeV);


//-----------------------------------------------------------------------------
/*!
** \brief   Enable PGN
** \param   ubNetV    - Network channel
** \param   uwPgnIdxV - PGN index
** \param   ubPgnDirV - PGN direction
** \param   ubEnableV - Enable/Disable PGN
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function enables (\a ubEnableV = 1) or disables (\a ubEnableV = 0)
** the PGN with index \a uwPgnIdxV. A PGN is disabled by default upon creation
** (see ComJ1939_PgnConfig()).
**
*/
ComStatus_tv   ComJ1939_PgnEnable(  uint8_t ubNetV, uint16_t uwPgnIdxV,
                                    uint8_t ubPgnDirV, uint8_t ubEnableV);

//-----------------------------------------------------------------------------
/*!
** \brief   Get PGN counter
** \param   ubNetV      - Network channel
** \param   uwPgnIdxV   - PGN index
** \param   ubPgnDirV   - PGN direction
** \param   pulCounterV - Pointer to counter variable
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** The function returns the number of PGNs that have been sent (for
** Transmit-PGNs) or received (for Receive-PGNs) by the CANopen Master.
**
**
*/
ComStatus_tv   ComJ1939_PgnGetCounter( uint8_t ubNetV, uint16_t uwPgnIdxV,
                                       uint8_t ubPgnDirV, uint32_t * pulCounterV);


//-----------------------------------------------------------------------------
/*!
** \brief   Get PGN data
** \param   ubNetV      - Network channel
** \param   uwPgnIdxV   - PGN index
** \param   ubPgnDirV   - PGN direction
** \param   pubSrcAddrV - Pointer to ECU source address
** \param   pubDataV    - Pointer to data buffer
** \param   puwSizeV    - Pointer to size variable
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** The function reads data from the PGN defined by the
** parameter \a uwPgnIdxV. The application must guarantee that
** \a pubDataV points to a buffer with sufficient size (maximum
** 1785 bytes).
**
*/
ComStatus_tv   ComJ1939_PgnGetData( uint8_t ubNetV, uint16_t uwPgnIdxV,
                                    uint8_t ubPgnDirV,
                                    uint8_t * pubSrcAddrV,
                                    uint8_t * pubDataV,
                                    uint16_t * puwSizeV);


//-----------------------------------------------------------------------------
/*!
** \brief   Get destination address of a PDU identifier
** \param   ulIdentifierV - identifier value
**
** \return  Destination address
**
** The function calculates the destination address of the PDU identifier
** given by parameter \a ulIdentifierV. For a PDU2 type message the function
** will return the broadcast address (J1939_ADDR_BROADCAST).
**
*/
uint8_t ComJ1939_PgnGetDestination(uint32_t ulIdentifierV);


//-----------------------------------------------------------------------------
/*!
** \brief   Get size of a PGN
** \param   ubNetV - Network channel
** \param   uwPgnIdxV - PGN index
** \param   puwSizeV - Pointer to buffer for size
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** The function reads the size of a PGN.
**
*/
ComStatus_tv ComJ1939_PgnGetSize( uint8_t ubNetV, uint16_t uwPgnIdxV,
                                  uint16_t * puwSizeV);


//-----------------------------------------------------------------------------
/*!
** \brief   Get source address of a PDU identifier
** \param   ulIdentifierV - identifier value
**
** \return  Source address
**
** The function calculates the source address of the PDU identifier
** given by parameter \a ulIdentifierV.
**
*/
uint8_t ComJ1939_PgnGetSource(uint32_t ulIdentifierV);

//-----------------------------------------------------------------------------
/*!
** \brief   Check PGN
** \param   ubNetV - Network channel
** \param   uwPgnIdxV - PGN index
** \param   ubPgnDirV - PGN direction
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
*/
ComStatus_tv   ComJ1939_PgnIsEnabled(  uint8_t ubNetV, uint16_t uwPgnIdxV,
                                       uint8_t ubPgnDirV);

//-----------------------------------------------------------------------------
/*!
** \brief   Request PGN
** \param   ubNetV - Network channel
** \param   ulPgnV - PGN value
** \param   ubDestAddrV - ECU destination address
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function sends a PGN request message to an ECU with address
** \a ubDestAddrV. The value for \a ubDestAddrV can be set to
** #J1939_ADDR_BROADCAST in order to sent the request to all ECUs
** present in the network.
**
*/
ComStatus_tv   ComJ1939_PgnRequest( uint8_t ubNetV, uint32_t ulPgnV,
                                    uint8_t ubDestAddrV);

//-----------------------------------------------------------------------------
/*!
** \internal
** \brief   Send a PGN
** \param   ubNetV - Network channel
** \param   uwPgnIdxV - PGN index with TX/RX flag
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
*/
ComStatus_tv   ComJ1939_PgnSend(uint8_t ubNetV, uint16_t uwPgnIdxV);

//-----------------------------------------------------------------------------
/*!
** \brief   Send a PGN
** \param   ubNetV - Network channel
** \param   uwPgnIdxV - PDO index
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
** This function sends a PGN defined by the index \a uwPgnIdxV asynchronous.
**
*/
ComStatus_tv   ComJ1939_PgnSendAsync(uint8_t ubNetV, uint16_t uwPgnIdxV);

//-----------------------------------------------------------------------------
/*!
** \brief   Set PGN Data
** \param   ubNetV    - Network channel
** \param   uwPgnIdxV - PGN index
** \param   ubPgnDirV - PGN direction
** \param   pubDataV  - Pointer to data
** \param   uwSizeV   - Number of bytes
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
*/
ComStatus_tv ComJ1939_PgnSetData(uint8_t ubNetV, uint16_t uwPgnIdxV,
                                 uint8_t ubPgnDirV, uint8_t * pubDataV,
                                 uint16_t uwSizeV);

//-----------------------------------------------------------------------------
/*!
** \brief   Set PGN timer
** \param   ubNetV    - Network channel
** \param   uwPgnIdxV - PGN index
** \param   ubPgnDirV - PGN direction
** \param   uwTimeV   - Time value
**
** \return  #eCOM_ERR_NONE on success, negative #ComErr_e value on failure
**
*/
ComStatus_tv   ComJ1939_PgnSetTimer(uint8_t ubNetV, uint16_t uwPgnIdxV,
                                    uint8_t ubPgnDirV, uint16_t uwTimeV);


/** @} */ // end of group ComSync

//----------------------------------------------------------------------------//
#ifdef __cplusplus                                                            //
}                                                                             //
#endif                                                                        //
// end of C++ compiler wrapper                                                //
//----------------------------------------------------------------------------//

#endif   // CANOPEN_MASTER_H_

