/*****************************************************************************
   raptor_can_config.c
   Generated By:
   Raptor 2023b_1.0.0 (9999_9999)
   Matlab (R2023a) 9.14

   Copyright (c) 2024 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Wed Mar 27 13:31:34 2024
 *****************************************************************************/

#include "Can_def.h"
#include "Can_Cfg.h"
#include "Can_Queue.h"
#include "raptor_can_config.h"

/* Arrays containing the bit timings */
extern const tBiosCanNomBitTimCfg raptor_can_SubMcan_NominalBitTimings[];/* tBiosCanBitRates */
extern const tBiosCanDataBitTimCfg raptor_can_SubMcan_DataBitTimings[];/* tBiosDataCanBitRates */
extern const tBiosCanNomBitTimCfg raptor_can_CustomNomBitTimings[];/* tBiosCustomCanBitRates */
extern const tBiosCanDataBitTimCfg raptor_can_CustomDataBitTimings[];/* tBiosCustomCanDataBitRates */

/* Array contain define the queue items for Tx frame of CAN 1 */
tBiosCanFrame bios_Can1_TxFrame[BIOS_MCAN_1_TXQUEUE_SIZE];

/* Array contain define the queue items for Tx frame of CAN 2 */
tBiosCanFrame bios_Can2_TxFrame[BIOS_MCAN_2_TXQUEUE_SIZE];

/* Array contain define the queue items for Tx frame of CAN 3 */
tBiosCanFrame bios_Can3_TxFrame[BIOS_MCAN_3_TXQUEUE_SIZE];

/* Array contain define the queue items for Tx frame of CAN 4 */
tBiosCanFrame bios_Can4_TxFrame[BIOS_MCAN_4_TXQUEUE_SIZE];

/* Array contain define the queue items for Tx frame of CAN 5 */
tBiosCanFrame bios_Can5_TxFrame[BIOS_MCAN_5_TXQUEUE_SIZE];

/* Array contain define the queue items for Rx frame of CAN 1 */
tBiosCanFrame bios_Can1_RxFrame[BIOS_MCAN_1_RXQUEUE_SIZE];

/* Array contain define the queue items for Rx frame of CAN 2 */
tBiosCanFrame bios_Can2_RxFrame[BIOS_MCAN_2_RXQUEUE_SIZE];

/* Array contain define the queue items for Rx frame of CAN 3 */
tBiosCanFrame bios_Can3_RxFrame[BIOS_MCAN_3_RXQUEUE_SIZE];

/* Array contain define the queue items for Rx frame of CAN 4 */
tBiosCanFrame bios_Can4_RxFrame[BIOS_MCAN_4_RXQUEUE_SIZE];

/* Array contain define the queue items for Rx frame of CAN 5 */
tBiosCanFrame bios_Can5_RxFrame[BIOS_MCAN_5_RXQUEUE_SIZE];

/* TX queue frame buffer which is shared between Main core 0 and FIFO of dedicated CAN instance hardware */
tBiosCanQueueBuffer bios_Can_TxQueueBuffer[BIOS_NUM_PLATFORM_MCAN_CHAN] = {
  /* BIOS_MCAN_1 */
  {
    .CanFrameQueue = bios_Can1_TxFrame,
    .maxlen = BIOS_MCAN_1_TXQUEUE_SIZE
  },

  /* BIOS_MCAN_2 */
  {
    .CanFrameQueue = bios_Can2_TxFrame,
    .maxlen = BIOS_MCAN_2_TXQUEUE_SIZE
  },

  /* BIOS_MCAN_3 */
  {
    .CanFrameQueue = bios_Can3_TxFrame,
    .maxlen = BIOS_MCAN_3_TXQUEUE_SIZE
  },

  /* BIOS_MCAN_4 */
  {
    .CanFrameQueue = bios_Can4_TxFrame,
    .maxlen = BIOS_MCAN_4_TXQUEUE_SIZE
  },

  /* BIOS_MCAN_5 */
  {
    .CanFrameQueue = bios_Can5_TxFrame,
    .maxlen = BIOS_MCAN_5_TXQUEUE_SIZE
  },
};

/* RX queue frame buffer which is shared between Main core 0 and FIFO of dedicated CAN instance hardware */
tBiosCanQueueBuffer bios_Can_RxQueueBuffer[BIOS_NUM_PLATFORM_MCAN_CHAN] = {
  /* BIOS_MCAN_1 */
  {
    .CanFrameQueue = bios_Can1_RxFrame,
    .maxlen = BIOS_MCAN_1_RXQUEUE_SIZE
  },

  /* BIOS_MCAN_2 */
  {
    .CanFrameQueue = bios_Can2_RxFrame,
    .maxlen = BIOS_MCAN_2_RXQUEUE_SIZE
  },

  /* BIOS_MCAN_3 */
  {
    .CanFrameQueue = bios_Can3_RxFrame,
    .maxlen = BIOS_MCAN_3_RXQUEUE_SIZE
  },

  /* BIOS_MCAN_4 */
  {
    .CanFrameQueue = bios_Can4_RxFrame,
    .maxlen = BIOS_MCAN_4_RXQUEUE_SIZE
  },

  /* BIOS_MCAN_5 */
  {
    .CanFrameQueue = bios_Can5_RxFrame,
    .maxlen = BIOS_MCAN_5_RXQUEUE_SIZE
  },
};

const tBiosCanConfig bios_can_SubMcan1Cfg = {
  &raptor_can_SubMcan_NominalBitTimings[BIOS_MCAN_BR_500KBPS],
  /* Nominal CAN bit rate                                                             */
  &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
  /* CANFD bit rate value                                                             */
  CANFD_ISO_FORMAT,
  /* CanFDFormat                                                                      */
  STD_OFF,
  /* Enable CAN FD                                                                    */
  STD_OFF,
  /* Enable CANFD BRS                                                                 */
  STD_OFF,
  /* is TX Queue enabled (instead of TX FIFO)                                         */
  30U,
  /* Number of RXFIFO 0 buffers                                                       */
  0U,
  /* Number of RXFIFO 1 buffers                                                       */
  24U,
  /* Number of TXFIFO buffers                                                         */
  BIOS_MCAN_NO_LOOPBACK
  /* Loop Back mode                                                                   */
};

const tBiosCanConfig bios_can_SubMcan2Cfg = {
  &raptor_can_SubMcan_NominalBitTimings[BIOS_MCAN_BR_500KBPS],
  /* Nominal CAN bit rate                                                             */
  &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
  /* CANFD bit rate value                                                             */
  CANFD_ISO_FORMAT,
  /* CanFDFormat                                                                      */
  STD_OFF,
  /* Enable CAN FD                                                                    */
  STD_OFF,
  /* Enable CANFD BRS                                                                 */
  STD_OFF,
  /* is TX Queue enabled (instead of TX FIFO)                                         */
  30U,
  /* Number of RXFIFO 0 buffers                                                       */
  0U,
  /* Number of RXFIFO 1 buffers                                                       */
  24U,
  /* Number of TXFIFO buffers                                                         */
  BIOS_MCAN_NO_LOOPBACK
  /* Loop Back mode                                                                   */
};

const tBiosCanConfig bios_can_SubMcan3Cfg = {
  &raptor_can_SubMcan_NominalBitTimings[BIOS_MCAN_BR_500KBPS],
  /* Nominal CAN bit rate                                                             */
  &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
  /* CANFD bit rate value                                                             */
  CANFD_ISO_FORMAT,
  /* CanFDFormat                                                                      */
  STD_OFF,
  /* Enable CAN FD                                                                    */
  STD_OFF,
  /* Enable CANFD BRS                                                                 */
  STD_OFF,
  /* is TX Queue enabled (instead of TX FIFO)                                         */
  30U,
  /* Number of RXFIFO 0 buffers                                                       */
  0U,
  /* Number of RXFIFO 1 buffers                                                       */
  24U,
  /* Number of TXFIFO buffers                                                         */
  BIOS_MCAN_NO_LOOPBACK
  /* Loop Back mode                                                                   */
};

const tBiosCanConfig bios_can_SubMcan4Cfg = {
  &raptor_can_SubMcan_NominalBitTimings[BIOS_MCAN_BR_500KBPS],
  /* Nominal CAN bit rate                                                             */
  &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
  /* CANFD bit rate value                                                             */
  CANFD_ISO_FORMAT,
  /* CanFDFormat                                                                      */
  STD_OFF,
  /* Enable CAN FD                                                                    */
  STD_OFF,
  /* Enable CANFD BRS                                                                 */
  STD_OFF,
  /* is TX Queue enabled (instead of TX FIFO)                                         */
  30U,
  /* Number of RXFIFO 0 buffers                                                       */
  0U,
  /* Number of RXFIFO 1 buffers                                                       */
  24U,
  /* Number of TXFIFO buffers                                                         */
  BIOS_MCAN_NO_LOOPBACK
  /* Loop Back mode                                                                   */
};

const tBiosCanConfig bios_can_SubMcan5Cfg = {
  &raptor_can_SubMcan_NominalBitTimings[BIOS_MCAN_BR_500KBPS],
  /* Nominal CAN bit rate                                                             */
  &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
  /* CANFD bit rate value                                                             */
  CANFD_ISO_FORMAT,
  /* CanFDFormat                                                                      */
  STD_OFF,
  /* Enable CAN FD                                                                    */
  STD_OFF,
  /* Enable CANFD BRS                                                                 */
  STD_OFF,
  /* is TX Queue enabled (instead of TX FIFO)                                         */
  30U,
  /* Number of RXFIFO 0 buffers                                                       */
  0U,
  /* Number of RXFIFO 1 buffers                                                       */
  24U,
  /* Number of TXFIFO buffers                                                         */
  BIOS_MCAN_NO_LOOPBACK
  /* Loop Back mode                                                                   */
};

const tBiosCANRAMcfg Bios_CAN_RAMCfgs[5] = {
  {
    /* CAN1 RAM Config: ElementSize: 16 */
    .stdFilterStartAddr = 0x0,
    .extFilterStartAddr = 0x0,
    .rxFifo0StartAddr = 0x0,
    .rxFifo1StartAddr = 0x1E0,
    .rxDedBuffStartAddr = 0x1E0,
    .txEvtStartAddr = 0x1E0,
    .txBuffStartAddr = 0x1E0,
    .stdFilterSize = 0U,
    .extFilterSize = 0U,
    .rxFifo0Size = 30U,
    .rxFifo1Size = 0U,
    .rxDedBuffSize = 0U,
    .txEvtSize = 0U,
    .txBuffSize = 24U,
  },

  {
    /* CAN2 RAM Config: ElementSize: 16 */
    .stdFilterStartAddr = 0x0,
    .extFilterStartAddr = 0x0,
    .rxFifo0StartAddr = 0x0,
    .rxFifo1StartAddr = 0x1E0,
    .rxDedBuffStartAddr = 0x1E0,
    .txEvtStartAddr = 0x1E0,
    .txBuffStartAddr = 0x1E0,
    .stdFilterSize = 0U,
    .extFilterSize = 0U,
    .rxFifo0Size = 30U,
    .rxFifo1Size = 0U,
    .rxDedBuffSize = 0U,
    .txEvtSize = 0U,
    .txBuffSize = 24U,
  },

  {
    /* CAN3 RAM Config: ElementSize: 16 */
    .stdFilterStartAddr = 0x3C0,
    .extFilterStartAddr = 0x3C0,
    .rxFifo0StartAddr = 0x3C0,
    .rxFifo1StartAddr = 0x5A0,
    .rxDedBuffStartAddr = 0x5A0,
    .txEvtStartAddr = 0x5A0,
    .txBuffStartAddr = 0x5A0,
    .stdFilterSize = 0U,
    .extFilterSize = 0U,
    .rxFifo0Size = 30U,
    .rxFifo1Size = 0U,
    .rxDedBuffSize = 0U,
    .txEvtSize = 0U,
    .txBuffSize = 24U,
  },

  {
    /* CAN4 RAM Config: ElementSize: 16 */
    .stdFilterStartAddr = 0x780,
    .extFilterStartAddr = 0x780,
    .rxFifo0StartAddr = 0x780,
    .rxFifo1StartAddr = 0x960,
    .rxDedBuffStartAddr = 0x960,
    .txEvtStartAddr = 0x960,
    .txBuffStartAddr = 0x960,
    .stdFilterSize = 0U,
    .extFilterSize = 0U,
    .rxFifo0Size = 30U,
    .rxFifo1Size = 0U,
    .rxDedBuffSize = 0U,
    .txEvtSize = 0U,
    .txBuffSize = 24U,
  },

  {
    /* CAN5 RAM Config: ElementSize: 16 */
    .stdFilterStartAddr = 0xB40,
    .extFilterStartAddr = 0xB40,
    .rxFifo0StartAddr = 0xB40,
    .rxFifo1StartAddr = 0xD20,
    .rxDedBuffStartAddr = 0xD20,
    .txEvtStartAddr = 0xD20,
    .txBuffStartAddr = 0xD20,
    .stdFilterSize = 0U,
    .extFilterSize = 0U,
    .rxFifo0Size = 30U,
    .rxFifo1Size = 0U,
    .rxDedBuffSize = 0U,
    .txEvtSize = 0U,
    .txBuffSize = 24U,
  },
};

const tBiosCANfilterCfgSet Bios_Can_FilterConfigs[5] = {
  {
    .SIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .EIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .RemoteReject = FALSE,
    .numOfSIDFilter = 0U,
    .pTableSIDFilter = NULL_PTR,
    .numOfEIDFilter = 0U,
    .pTableEIDFilter = NULL_PTR,
  },

  {
    .SIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .EIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .RemoteReject = FALSE,
    .numOfSIDFilter = 0U,
    .pTableSIDFilter = NULL_PTR,
    .numOfEIDFilter = 0U,
    .pTableEIDFilter = NULL_PTR,
  },

  {
    .SIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .EIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .RemoteReject = FALSE,
    .numOfSIDFilter = 0U,
    .pTableSIDFilter = NULL_PTR,
    .numOfEIDFilter = 0U,
    .pTableEIDFilter = NULL_PTR,
  },

  {
    .SIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .EIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .RemoteReject = FALSE,
    .numOfSIDFilter = 0U,
    .pTableSIDFilter = NULL_PTR,
    .numOfEIDFilter = 0U,
    .pTableEIDFilter = NULL_PTR,
  },

  {
    .SIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .EIDUnmatchBehavior = BIOS_CAN_GLOBAL_EID_UNMATCH_FIFO_0,
    .RemoteReject = FALSE,
    .numOfSIDFilter = 0U,
    .pTableSIDFilter = NULL_PTR,
    .numOfEIDFilter = 0U,
    .pTableEIDFilter = NULL_PTR,
  },
};

void Bios_Can_1RxCallBackFunction_IOP (uint8 IdType, uint32 Id, uint8* data,
  uint8 data_len, uint8 operate, uint8 brs)
{
}

void Bios_Can_2RxCallBackFunction_IOP (uint8 IdType, uint32 Id, uint8* data,
  uint8 data_len, uint8 operate, uint8 brs)
{
}

void Bios_Can_3RxCallBackFunction_IOP (uint8 IdType, uint32 Id, uint8* data,
  uint8 data_len, uint8 operate, uint8 brs)
{
}

void Bios_Can_4RxCallBackFunction_IOP (uint8 IdType, uint32 Id, uint8* data,
  uint8 data_len, uint8 operate, uint8 brs)
{
}

void Bios_Can_5RxCallBackFunction_IOP (uint8 IdType, uint32 Id, uint8* data,
  uint8 data_len, uint8 operate, uint8 brs)
{
}

const tBiosCanRxCallBack
  Bios_Can_IOPReceivedCallbackArr[BIOS_NUM_PLATFORM_MCAN_CHAN] = {
  Bios_Can_1RxCallBackFunction_IOP,
  Bios_Can_2RxCallBackFunction_IOP,
  Bios_Can_3RxCallBackFunction_IOP,
  Bios_Can_4RxCallBackFunction_IOP,
  Bios_Can_5RxCallBackFunction_IOP,
};
