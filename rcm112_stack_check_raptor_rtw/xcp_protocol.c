/*****************************************************************************
   xcp_protocol.c
   Generated By:
   Raptor 2023b_1.0.0 (9999_9999)
   Matlab (R2023a) 9.14

   Copyright (c) 2024 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Wed Mar 27 13:31:34 2024
 *****************************************************************************/

#include "rtwtypes.h"
#include "xcp_protocol.h"
#include "rcm112_stack_check.h"
#include "rcm112_stack_check_private.h"
#ifdef XCP_ENABLE

const uint16_T* Xcp_IdTableRevPtr = IdTableRev_Ptr() ;
Xcp_SlaveId_t Xcp_SlaveIds[] = {
  {
    22,
    (Xcp_CfgPtr8)"rcm112_stack_check_019",
    (Xcp_CfgPtr8)HardwareType_Ptr(),
    (Xcp_CfgPtr8)EcuAddr_RAM_Ptr(),
    25,
    (Xcp_CfgPtr8)"rcm112_stack_check_019_A4",
    26,
    (Xcp_CfgPtr8)CalIdTxt_Ptr(),
    21,
    (Xcp_CfgPtr8)BuildUID_Ptr(),
    (Xcp_CfgPtr8)UDSServerAddr_RAM_Ptr(),
    (Xcp_CfgPtr8)UDSClientAddr_RAM_Ptr(),
  },
};

/******************************************************************************
 *
 * CAN channel structures
 *
 ******************************************************************************/
XcpCan_ChannelCfg_t XCP1_ChannelCfg[] = {
  {                                    /* Command channel */
    XCP_CAN_RX_CMD_START,              /* idxStart */
    XCP_CAN_RX_CMD_END,                /* idxEnd */
    XCP1_CAN_RX_MSGID,                 /* msgId */
    XCPCAN_INVALID_MSGOBJID,           /* msgObjId - unused */
  },

  {                                    /* EVENT channel */
    XCP_CAN_TX_EVENT_START,            /* idxStart */
    XCP_CAN_TX_EVENT_END,              /* idxEnd */
    XCP1_CAN_TX_MSGID,                 /* msgId */
    1,                                 /* msgObjId */
  },

  {                                    /* Response channel */
    XCP_CAN_TX_CRM_START,              /* idxStart */
    XCP_CAN_TX_CRM_END,                /* idxEnd */
    XCP1_CAN_TX_MSGID,                 /* msgId */
    1,                                 /* msgObjId */
  },

  {                                    /* DYNDAQ0 channel */
    XCP_CAN_DYNDAQ0_START,             /* idxStart */
    XCP_CAN_DYNDAQ0_END,               /* idxEnd   */
    XCP1_CAN_DYNDAQ_MSGID,             /* Default msgId    */
    1,                                 /* msgObjId */
  },

  {                                    /* DYNDAQ1 channel */
    XCP_CAN_DYNDAQ1_START,             /* idxStart */
    XCP_CAN_DYNDAQ1_END,               /* idxEnd   */
    XCP1_CAN_DYNDAQ_MSGID,             /* Default msgId    */
    1,                                 /* msgObjId */
  },

  {                                    /* DYNDAQ2 channel */
    XCP_CAN_DYNDAQ2_START,             /* idxStart */
    XCP_CAN_DYNDAQ2_END,               /* idxEnd   */
    XCP1_CAN_DYNDAQ_MSGID,             /* Default msgId    */
    1,                                 /* msgObjId */
  },

  {                                    /* DYNDAQ3 channel */
    XCP_CAN_DYNDAQ3_START,             /* idxStart */
    XCP_CAN_DYNDAQ3_END,               /* idxEnd   */
    XCP1_CAN_DYNDAQ_MSGID,             /* Default msgId    */
    1,                                 /* msgObjId */
  },

  {                                    /* DYNDAQ4 channel */
    XCP_CAN_DYNDAQ4_START,             /* idxStart */
    XCP_CAN_DYNDAQ4_END,               /* idxEnd   */
    XCP1_CAN_DYNDAQ_MSGID,             /* Default msgId    */
    1,                                 /* msgObjId */
  },
};

/******************************************************************************
 *
 * CAN queue structures
 *
 ******************************************************************************/
XcpCan_QueuePos_t XCP1_QueuePositions [ XCP1_CAN_NUM_CHANNELS ];
XcpCan_QueueBuf_t XCP1_QueueBuffers [ XCP_CAN_QUEUEALL_NUMBUF ];

/* Each element has values from XcpCan_QueueBufStates_t. If an element contains XCP_TXNOTSENT or XCP_TXINPROGRESS,
 * the upper nibble will also contain the number of bytes currently used in the corresponding buffer. */
XcpCan_QueueBufProps_t XCP1_QueueBufferStates [ XCP_CAN_QUEUEALL_NUMBUF ];
XcpCan_DynDaqMsgId_t XCP1_DynDaqMsgIds [ XCP_NUM_DYN_DAQ ];

/******************************************************************************
 *
 * CAN session structures
 *
 ******************************************************************************/
XCP_STATE_TYPE uint8_T XcpCan_TxPendingOnMsgObj [ XCP_CAN_MAX_TXMSGOBJID + 1 ];
XcpCan_Session_t XCP1_Session;
XcpCan_SessionCfg_t XCP1_SessionCfg = {
  XCP1_ChannelCfg,                     /* pChannelCfgs */
  XCP1_QueuePositions,                 /* pQueuePositions */
  XCP1_QueueBuffers,                   /* pQueueBuffers */
  XCP1_QueueBufferStates,              /* pQueueBufferStates */
  XCP1_DynDaqMsgIds,                   /* pDynDaqMsgIds */
  XCP1_CAN_BROADCAST_MSGID,            /* broadcastMsgId */
  XCP1_CAN_NUM_CHANNELS,               /* numChannels */
  XCP1_CAN_NUM_CHANNELS,               /* firstRxStimChannel */
  5,                                   /* lastTxChannel */
};

/******************************************************************************
 *
 * SEGMENT and PAGE data structures
 *
 ******************************************************************************/
Xcp_PageConfig_t XCP1_PageConfigs0[] = { { 0 }, { 1 } };
        // the second entry here is to allow CM0711 to build with a bad LCF file

Xcp_PageConfig_t XCP1_PageConfigs1[] = { { 1 }, { 1 } };

Xcp_SegConfig_t XCP1_SegConfigs[] = { { XCP1_PageConfigs0, 1 }, {
    XCP1_PageConfigs1, 2 } };

Xcp_SegState_t XCP1_SegStates[ 2 ];

/******************************************************************************
 *
 * DAQ data structures
 *
 ******************************************************************************/
Xcp_OdtEntryAddr_t XCP1_OdtEntryAddrs[ XCP_ODT_LIST_SIZE ];
Xcp_OdtEntryCfg_t XCP1_OdtEntryCfgs[ XCP_ODT_LIST_SIZE ];
Xcp_Daq_t XCP1_DaqStates[ XCP_NUM_ALL_DAQ ];
uint8_T odtEntryNums1[XCP_NUM_DYN_DAQ][ XCP_MAX_ODT_ENTRIES_DYNDAQ ];
Xcp_DaqDynConfig_t XCP1_DaqDynConfigs[ XCP_NUM_DYN_DAQ ]= {
  { 0, &odtEntryNums1[0][0] },

  { 0, &odtEntryNums1[1][0] },

  { 0, &odtEntryNums1[2][0] },

  { 0, &odtEntryNums1[3][0] },

  { 0, &odtEntryNums1[4][0] },
};

Xcp_DaqConfig_t XCP1_DaqConfigs[XCP_NUM_ALL_DAQ] = {
  {                                    /* DYNDAQ0 */
    XCP_FIRST_PID_DYNDAQ0,             /* firstPid */
    XCP_NUM_ODT_DYNDAQ,                /* numOdt - Max ODT per DAQ list */
    XCP_DYNDAQ0_START,                 /* idxDaqStart */
    XCP_NUM_ODT_ENTRIES_DYNDAQ,        /* numOdtEntries */
    XCP_DAQLISTPROPERTY_DAQ,           /* properties */
    0                                  /* defaultEvent */
  },

  {                                    /* DYNDAQ1 */
    XCP_FIRST_PID_DYNDAQ1,             /* firstPid */
    XCP_NUM_ODT_DYNDAQ,                /* numOdt - Max ODT per DAQ list */
    XCP_DYNDAQ1_START,                 /* idxDaqStart */
    XCP_NUM_ODT_ENTRIES_DYNDAQ,        /* numOdtEntries */
    XCP_DAQLISTPROPERTY_DAQ,           /* properties */
    0                                  /* defaultEvent */
  },

  {                                    /* DYNDAQ2 */
    XCP_FIRST_PID_DYNDAQ2,             /* firstPid */
    XCP_NUM_ODT_DYNDAQ,                /* numOdt - Max ODT per DAQ list */
    XCP_DYNDAQ2_START,                 /* idxDaqStart */
    XCP_NUM_ODT_ENTRIES_DYNDAQ,        /* numOdtEntries */
    XCP_DAQLISTPROPERTY_DAQ,           /* properties */
    0                                  /* defaultEvent */
  },

  {                                    /* DYNDAQ3 */
    XCP_FIRST_PID_DYNDAQ3,             /* firstPid */
    XCP_NUM_ODT_DYNDAQ,                /* numOdt - Max ODT per DAQ list */
    XCP_DYNDAQ3_START,                 /* idxDaqStart */
    XCP_NUM_ODT_ENTRIES_DYNDAQ,        /* numOdtEntries */
    XCP_DAQLISTPROPERTY_DAQ,           /* properties */
    0                                  /* defaultEvent */
  },

  {                                    /* DYNDAQ4 */
    XCP_FIRST_PID_DYNDAQ4,             /* firstPid */
    XCP_NUM_ODT_DYNDAQ,                /* numOdt - Max ODT per DAQ list */
    XCP_DYNDAQ4_START,                 /* idxDaqStart */
    XCP_NUM_ODT_ENTRIES_DYNDAQ,        /* numOdtEntries */
    XCP_DAQLISTPROPERTY_DAQ,           /* properties */
    0                                  /* defaultEvent */
  },
};

/******************************************************************************
 *
 * Session data structures
 *
 ******************************************************************************/
const uint32_T Xcp_NumSessions = XCP_SESSION_SIZE;
const Xcp_SessionConfig_t Xcp_SessionConfigs[XCP_SESSION_SIZE] = {
  {
    &XCP1_SessionCfg,                  /* pTransportCfg */
    &XCP1_Session,                     /* pTransport */
    XcpCan_GetTxBuf,                   /* pGetTxBuf */
    XcpCan_GetRxBuf,                   /* pGetRxBuf */

#ifdef XCP_ENABLE_STIM

    XcpCan_PeekRxBuf,                  /* pPeekRxBuf */

#endif

    XcpCan_TxNext,                     /* pTxNext */
    XcpCan_RxNext,                     /* pRxNext */
    XcpCan_CmdProc,                    /* pCmdProc */

#ifdef XCP_ENABLE_RESUME

    XcpCan_PrepareResume,              /* pPrepareResume */
    XcpCan_DoResume,                   /* pDoResume */

#endif

    XcpCan_ResetDaqList,               /* pResetDaqList */
    XCP1_OdtEntryAddrs,                /* pOdtEntryAddrs */
    XCP1_OdtEntryCfgs,                 /* pOdtEntryCfgs */
    XCP1_DaqConfigs,                   /* pDaqConfigs */

#ifdef XCP_ENABLE_DYNDAQ

    XCP1_DaqDynConfigs,                /* pDaqDynConfigs */

#endif

    XCP1_DaqStates,                    /* pDaqStates */
    XCP_NUM_STATIC_DAQ,                /* numStatDaqLists */
    XCP_NUM_DYN_DAQ,                   /* maxDynDaqLists */
    XCP_ODT_LIST_SIZE,                 /* totOdtEntries */
    XCP_MAXDTO,                        /* maxDtoLen */
    XCP_MAXCTO,                        /* maxCtoLen */
    XCP_RESOURCE_CAL_PAG | XCP_RESOURCE_STIM | XCP_RESOURCE_PGM |
    XCP_RESOURCE_DAQ,                  /* defResourceProtection */
    100 / XCP_POLL_INTERVAL,           /* eventPendingTimeout */
    4,                                 /* numBytesTimestamp */
    8,                                 /* maxOdtEntryLen */

#ifdef XCP_ENABLE_CALPAG

    2,                                 /* numSegs */
    XCP1_SegConfigs,                   /* pSegConfigs */
    XCP1_SegStates,                    /* pSegStates */

#endif

#ifdef XCP_ENABLE_RESUME

    XCP_NV_START_IDX,                  /* nvStartIdx */

#endif

    XCP_CAN                            /* transportLayerId */
  },
};

void XcpApp_CanTransmit( XcpCan_MsgObjId_t msgObjId, uint32_T msgId, uint8_T
  numBytes, Xcp_StatePtr8 pBytes )
{
  if (msgObjId == 1) {
    XcpApp_CanTransmit_XCP1(msgObjId, msgId, numBytes, pBytes);
  }
}

#if defined __cplusplus || defined _cplusplus

extern "C"
{

#endif

  extern Xcp_Session_t Xcp_Sessions[ XCP_SESSION_SIZE ];
  extern const uint8_T XCP_NUM_EVENTS;
  extern uint32_T XCP_MSG_RX_ID;

#ifdef XCP_ENABLE_SEEDNKEY

  extern const uint16_T *XcpProjectIdPtr;
  extern const uint32_T XcpPGMSecret;
  extern const uint32_T XcpSTIMSecret;
  extern const uint32_T XcpDAQSecret;
  extern const uint32_T XcpCALSecret;
  extern XCPSecurityFn XcpCustSecurity;

#endif

#if defined __cplusplus || defined _cplusplus

}

#endif

Xcp_Session_t Xcp_Sessions[ XCP_SESSION_SIZE ];
const uint8_T XCP_NUM_EVENTS = 5;
uint32_T XCP_MSG_RX_ID = 0;

#ifdef XCP_ENABLE_SEEDNKEY

const uint16_T *XcpProjectIdPtr = XCP1__XCP_Security_Ptr();
const uint32_T XcpPGMSecret = 0;
const uint32_T XcpSTIMSecret = 0;
const uint32_T XcpDAQSecret = 0;
const uint32_T XcpCALSecret = 0;
XCPSecurityFn XcpCustSecurity = 0;

#endif
#endif                                 /* XCP_ENABLE */
