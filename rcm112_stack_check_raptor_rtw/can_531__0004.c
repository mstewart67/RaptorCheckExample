/*****************************************************************************
   can_531__0004.c
   Generated By:
   Raptor 2023b_1.0.0 (9999_9999)
   Matlab (R2023a) 9.14

   Copyright (c) 2024 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Wed Mar 27 13:31:34 2024
 *****************************************************************************/

/* CAN interface: CAN1 */
/*   HW Resource: CAN1 */
#include "rcm112_stack_check.h"
#include "rcm112_stack_check_private.h"
#include "can_531__0004.h"
#include "bootmailbox.h"
#include "Crc.h"
#include "Mcu_api.h"
#include "raptor_gen.h"
#define MAX_AGE                        65535

/* Arrays containing the bit timings */
extern const tBiosCanNomBitTimCfg raptor_can_SubMcan_NominalBitTimings[];/* tBiosCanBitRates */
extern const tBiosCanDataBitTimCfg raptor_can_SubMcan_DataBitTimings[];/* tBiosDataCanBitRates */
extern uint8_T app_is_in_shutdown;
int started_531__0004 = 0;

/* Message Receive data storage */
/* Block: <S3>/raptor_xcp_update */
void rxFn_RxTrig_XCP_BC_XCP1(unsigned int id, uint8_T length, uint8_T* data,
  uint8_T operate, uint8_T brs);
uint8_T rxBuf_RxTrig_XCP_BC_XCP1[1][8];
uint8_T rxLen_RxTrig_XCP_BC_XCP1[1];
uint16_T rxAge_RxTrig_XCP_BC_XCP1 = MAX_AGE;
uint32_T rxID_RxTrig_XCP_BC_XCP1[1];
uint8_T rxQHead_RxTrig_XCP_BC_XCP1 = 0;
uint8_T rxQTail_RxTrig_XCP_BC_XCP1 = 0;

/* Block: <S3>/raptor_xcp_update */
void rxFn_RxTrig_XCP_CMD_XCP1(unsigned int id, uint8_T length, uint8_T* data,
  uint8_T operate, uint8_T brs);
uint8_T rxBuf_RxTrig_XCP_CMD_XCP1[1][8];
uint8_T rxLen_RxTrig_XCP_CMD_XCP1[1];
uint16_T rxAge_RxTrig_XCP_CMD_XCP1 = MAX_AGE;
uint32_T rxID_RxTrig_XCP_CMD_XCP1[1];
uint8_T rxQHead_RxTrig_XCP_CMD_XCP1 = 0;
uint8_T rxQTail_RxTrig_XCP_CMD_XCP1 = 0;

/* Block: UDS_receive */
void rxFn_uds_receive(unsigned int id, uint8_T length, uint8_T* data, uint8_T
                      operate, uint8_T brs);
uint8_T rxBuf_uds_receive[1][8];
uint8_T rxLen_uds_receive[1];
uint16_T rxAge_uds_receive = MAX_AGE;
uint32_T rxID_uds_receive[1];
uint8_T rxQHead_uds_receive = 0;
uint8_T rxQTail_uds_receive = 0;

/* Transmit CAN Object Declarations */
/* <S3>/raptor_xcp_update */
uint8_T txData_Tx_XCP_XCP1[20U][8];
uint32_T txID_Tx_XCP_XCP1[20U];
uint8_T txExt_Tx_XCP_XCP1[20U];
uint8_T txLen_Tx_XCP_XCP1[20U];
uint8_T txQHead_Tx_XCP_XCP1 = 0;
uint8_T txQTail_Tx_XCP_XCP1 = 0;

/* UDS_send */
uint8_T txData_uds_send[1][8];
uint32_T txID_uds_send[1];
uint8_T txExt_uds_send[1];
uint8_T txLen_uds_send[1];
uint8_T txQHead_uds_send = 0;
uint8_T txQTail_uds_send = 0;

/* Functions */
void uds_request_trigger(void)
{
  uint16_T age;
  uint32_T id;
  uint8_T extended;
  uint8_T data[8];
  uint16_T length = 8;
  const tBiosCanDrivers * CanDrvPtr;
  extern void App_Shutdown(void);
  length = can_get_uds_receive(&age, &id, &extended, data, length);
  if (length >= 3 && data[0] == 0x2 && data[1] == 0x10 && data[2] == 0x02) {
    {
      CanDrvPtr = &bios_Can_SubMCanDriver[BIOS_MCAN_1];
      bootmailbox.BootRequest = BOOT_REQ_FLASH;
      bootmailbox.canConfig.prescalerDivisionFactor = (uint8_T)((CanDrvPtr->
        mcan->NBTP.B.NBRP + 1U) / 2.0) - 1U;
      bootmailbox.canConfig.propSegment = 0x0u;
      bootmailbox.canConfig.phaseSeg1 = CanDrvPtr->mcan->NBTP.B.NTSEG1;
      bootmailbox.canConfig.phaseSeg2 = CanDrvPtr->mcan->NBTP.B.NTSEG2;
      bootmailbox.canConfig.resynchJumpWidth = CanDrvPtr->mcan->NBTP.B.NSJW;
      bootmailbox.canConfig.rxId = UDSServerAddr_RAM_Data();
      bootmailbox.canConfig.txId = UDSClientAddr_RAM_Data();
      bootmailbox.canConfig.busId = BIOS_MCAN_1;
      bootmailbox.CRC = Bios_crc16_calculation( &bootmailbox, sizeof(bootmailbox)
        -2, 0xFFFF );
      App_Shutdown();
      Module_BootRequest();
    }
  }
}

void pre_start_CAN_531__0004(void)
{
  {
    memset((void *)&rxBuf_RxTrig_XCP_BC_XCP1[0][0], 0, sizeof
           (rxBuf_RxTrig_XCP_BC_XCP1));
    memset((void *)&rxLen_RxTrig_XCP_BC_XCP1[0], 0, sizeof
           (rxLen_RxTrig_XCP_BC_XCP1));
    rxAge_RxTrig_XCP_BC_XCP1 = MAX_AGE;
  }

  {
    memset((void *)&rxBuf_RxTrig_XCP_CMD_XCP1[0][0], 0, sizeof
           (rxBuf_RxTrig_XCP_CMD_XCP1));
    memset((void *)&rxLen_RxTrig_XCP_CMD_XCP1[0], 0, sizeof
           (rxLen_RxTrig_XCP_CMD_XCP1));
    rxAge_RxTrig_XCP_CMD_XCP1 = MAX_AGE;
  }

  {
    memset((void *)&rxBuf_uds_receive[0][0], 0, sizeof(rxBuf_uds_receive));
    memset((void *)&rxLen_uds_receive[0], 0, sizeof(rxLen_uds_receive));
    rxAge_uds_receive = MAX_AGE;
  }
}                                      // end pre_start_CAN_531__0004

void rxFn_RxTrig_XCP_BC_XCP1(unsigned int id, uint8_T length, uint8_T* data,
  uint8_T operate, uint8_T brs)
{
  uint8_T i;
  uint8_T* b = data;
  if (1 && (operate == BIOS_MCAN_OP_NORMAL) && (brs == 0) ) {
    for (i = 0; i < 8; i++) {
      if (i < length)
        rxBuf_RxTrig_XCP_BC_XCP1[rxQHead_RxTrig_XCP_BC_XCP1][i] = b[i];
      else
        rxBuf_RxTrig_XCP_BC_XCP1[rxQHead_RxTrig_XCP_BC_XCP1][i] = 0;
    }

    rxLen_RxTrig_XCP_BC_XCP1[rxQHead_RxTrig_XCP_BC_XCP1] = length;
    rxID_RxTrig_XCP_BC_XCP1[rxQHead_RxTrig_XCP_BC_XCP1] = id;
    if ((rxQHead_RxTrig_XCP_BC_XCP1 == rxQTail_RxTrig_XCP_BC_XCP1) &&
        (rxAge_RxTrig_XCP_BC_XCP1 == 0))
      rxQTail_RxTrig_XCP_BC_XCP1 = (rxQTail_RxTrig_XCP_BC_XCP1 + 1) % 1;
    if ((rxQHead_RxTrig_XCP_BC_XCP1 == (rxQTail_RxTrig_XCP_BC_XCP1 + 1)% 1) &&
        (rxAge_RxTrig_XCP_BC_XCP1 != 0))
      rxQTail_RxTrig_XCP_BC_XCP1 = (rxQTail_RxTrig_XCP_BC_XCP1 + 1) % 1;
    rxQHead_RxTrig_XCP_BC_XCP1 = (rxQHead_RxTrig_XCP_BC_XCP1 + 1 ) % 1;
    rxAge_RxTrig_XCP_BC_XCP1 = 0;

    {
      RxTrig_XCP_BC_XCP1();
    }
  }
}

uint32_T RxTrig_XCP_BC_XCP1_msgID = 0x100;
uint8_T RxTrig_XCP_BC_XCP1_msgExtended = 0;
void can_init_rxIdRxTrig_XCP_BC_XCP1(uint32_T id, uint8_T extended)
{
  RxTrig_XCP_BC_XCP1_msgID = id;
  RxTrig_XCP_BC_XCP1_msgExtended = extended;
}

uint8_T can_get_RxTrig_XCP_BC_XCP1(uint16_T *age, uint32_T* id, uint8_T
  * extended, uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_RxTrig_XCP_BC_XCP1;
  if (id != NULL)
    *id = rxID_RxTrig_XCP_BC_XCP1[rxQTail_RxTrig_XCP_BC_XCP1];
  if (extended != NULL)
    *extended = 0;
  if (length > 8)
    length = 8;
  if (length > rxLen_RxTrig_XCP_BC_XCP1[rxQTail_RxTrig_XCP_BC_XCP1])
    length = rxLen_RxTrig_XCP_BC_XCP1[rxQTail_RxTrig_XCP_BC_XCP1];
  if (data != NULL)
    for (i = 0; i < 8; i++)
      data[i] = rxBuf_RxTrig_XCP_BC_XCP1[rxQTail_RxTrig_XCP_BC_XCP1][i];
  if ((rxQHead_RxTrig_XCP_BC_XCP1 != (rxQTail_RxTrig_XCP_BC_XCP1 + 1)% 1) &&
      (rxAge_RxTrig_XCP_BC_XCP1 == 0))
    rxQTail_RxTrig_XCP_BC_XCP1 = (rxQTail_RxTrig_XCP_BC_XCP1 + 1) % 1;
  else if (rxAge_RxTrig_XCP_BC_XCP1 < MAX_AGE)
    rxAge_RxTrig_XCP_BC_XCP1++;
  return length;
}

void rxFn_RxTrig_XCP_CMD_XCP1(unsigned int id, uint8_T length, uint8_T* data,
  uint8_T operate, uint8_T brs)
{
  uint8_T i;
  uint8_T* b = data;
  if (1 && (operate == BIOS_MCAN_OP_NORMAL) && (brs == 0) ) {
    for (i = 0; i < 8; i++) {
      if (i < length)
        rxBuf_RxTrig_XCP_CMD_XCP1[rxQHead_RxTrig_XCP_CMD_XCP1][i] = b[i];
      else
        rxBuf_RxTrig_XCP_CMD_XCP1[rxQHead_RxTrig_XCP_CMD_XCP1][i] = 0;
    }

    rxLen_RxTrig_XCP_CMD_XCP1[rxQHead_RxTrig_XCP_CMD_XCP1] = length;
    rxID_RxTrig_XCP_CMD_XCP1[rxQHead_RxTrig_XCP_CMD_XCP1] = id;
    if ((rxQHead_RxTrig_XCP_CMD_XCP1 == rxQTail_RxTrig_XCP_CMD_XCP1) &&
        (rxAge_RxTrig_XCP_CMD_XCP1 == 0))
      rxQTail_RxTrig_XCP_CMD_XCP1 = (rxQTail_RxTrig_XCP_CMD_XCP1 + 1) % 1;
    if ((rxQHead_RxTrig_XCP_CMD_XCP1 == (rxQTail_RxTrig_XCP_CMD_XCP1 + 1)% 1) &&
        (rxAge_RxTrig_XCP_CMD_XCP1 != 0))
      rxQTail_RxTrig_XCP_CMD_XCP1 = (rxQTail_RxTrig_XCP_CMD_XCP1 + 1) % 1;
    rxQHead_RxTrig_XCP_CMD_XCP1 = (rxQHead_RxTrig_XCP_CMD_XCP1 + 1 ) % 1;
    rxAge_RxTrig_XCP_CMD_XCP1 = 0;

    {
      RxTrig_XCP_CMD_XCP1();
    }
  }
}

uint32_T RxTrig_XCP_CMD_XCP1_msgID = 0x200;
uint8_T RxTrig_XCP_CMD_XCP1_msgExtended = 0;
void can_init_rxIdRxTrig_XCP_CMD_XCP1(uint32_T id, uint8_T extended)
{
  RxTrig_XCP_CMD_XCP1_msgID = id;
  RxTrig_XCP_CMD_XCP1_msgExtended = extended;
}

uint8_T can_get_RxTrig_XCP_CMD_XCP1(uint16_T *age, uint32_T* id, uint8_T
  * extended, uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_RxTrig_XCP_CMD_XCP1;
  if (id != NULL)
    *id = rxID_RxTrig_XCP_CMD_XCP1[rxQTail_RxTrig_XCP_CMD_XCP1];
  if (extended != NULL)
    *extended = 0;
  if (length > 8)
    length = 8;
  if (length > rxLen_RxTrig_XCP_CMD_XCP1[rxQTail_RxTrig_XCP_CMD_XCP1])
    length = rxLen_RxTrig_XCP_CMD_XCP1[rxQTail_RxTrig_XCP_CMD_XCP1];
  if (data != NULL)
    for (i = 0; i < 8; i++)
      data[i] = rxBuf_RxTrig_XCP_CMD_XCP1[rxQTail_RxTrig_XCP_CMD_XCP1][i];
  if ((rxQHead_RxTrig_XCP_CMD_XCP1 != (rxQTail_RxTrig_XCP_CMD_XCP1 + 1)% 1) &&
      (rxAge_RxTrig_XCP_CMD_XCP1 == 0))
    rxQTail_RxTrig_XCP_CMD_XCP1 = (rxQTail_RxTrig_XCP_CMD_XCP1 + 1) % 1;
  else if (rxAge_RxTrig_XCP_CMD_XCP1 < MAX_AGE)
    rxAge_RxTrig_XCP_CMD_XCP1++;
  return length;
}

void rxFn_uds_receive(unsigned int id, uint8_T length, uint8_T* data, uint8_T
                      operate, uint8_T brs)
{
  uint8_T i;
  uint8_T* b = data;
  if (1 && (operate == BIOS_MCAN_OP_NORMAL) && (brs == 0) ) {
    for (i = 0; i < 8; i++) {
      if (i < length)
        rxBuf_uds_receive[rxQHead_uds_receive][i] = b[i];
      else
        rxBuf_uds_receive[rxQHead_uds_receive][i] = 0;
    }

    rxLen_uds_receive[rxQHead_uds_receive] = length;
    rxID_uds_receive[rxQHead_uds_receive] = id;
    if ((rxQHead_uds_receive == rxQTail_uds_receive) && (rxAge_uds_receive == 0))
      rxQTail_uds_receive = (rxQTail_uds_receive + 1) % 1;
    if ((rxQHead_uds_receive == (rxQTail_uds_receive + 1)% 1) &&
        (rxAge_uds_receive != 0))
      rxQTail_uds_receive = (rxQTail_uds_receive + 1) % 1;
    rxQHead_uds_receive = (rxQHead_uds_receive + 1 ) % 1;
    rxAge_uds_receive = 0;

    {
      uds_request_trigger();
    }
  }
}

uint8_T can_get_uds_receive(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_uds_receive;
  if (id != NULL)
    *id = rxID_uds_receive[rxQTail_uds_receive];
  if (extended != NULL)
    *extended = 0;
  if (length > 8)
    length = 8;
  if (length > rxLen_uds_receive[rxQTail_uds_receive])
    length = rxLen_uds_receive[rxQTail_uds_receive];
  if (data != NULL)
    for (i = 0; i < 8; i++)
      data[i] = rxBuf_uds_receive[rxQTail_uds_receive][i];
  if ((rxQHead_uds_receive != (rxQTail_uds_receive + 1)% 1) &&
      (rxAge_uds_receive == 0))
    rxQTail_uds_receive = (rxQTail_uds_receive + 1) % 1;
  else if (rxAge_uds_receive < MAX_AGE)
    rxAge_uds_receive++;
  return length;
}

void can_send_Tx_XCP_XCP1(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
  if (!started_531__0004) {
    pre_start_CAN_531__0004();
  }

  tBiosCanFrame t_CanFrame = { 0 };

  int i;
  t_CanFrame.ID = id;
  t_CanFrame.Operation = BIOS_MCAN_OP_NORMAL;
  t_CanFrame.RTR = 0u;
  t_CanFrame.IdType = extended;
  if (length > 8) {
    t_CanFrame.DLC = 8;
  } else {
    t_CanFrame.DLC = length;
  }

  for (i = 0; i < t_CanFrame.DLC; i++) {
    t_CanFrame.PayLoad[i] = data[i];
  }

  Bios_Can_SendMessage(BIOS_MCAN_1, &t_CanFrame);
}

void can_send_uds_send(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
  if (!started_531__0004) {
    pre_start_CAN_531__0004();
  }

  tBiosCanFrame t_CanFrame = { 0 };

  int i;
  t_CanFrame.ID = id;
  t_CanFrame.Operation = BIOS_MCAN_OP_NORMAL;
  t_CanFrame.RTR = 0u;
  t_CanFrame.IdType = extended;
  if (length > 8) {
    t_CanFrame.DLC = 8;
  } else {
    t_CanFrame.DLC = length;
  }

  for (i = 0; i < t_CanFrame.DLC; i++) {
    t_CanFrame.PayLoad[i] = data[i];
  }

  Bios_Can_SendMessage(BIOS_MCAN_1, &t_CanFrame);
}

void CAN_ReceiveDispatch_531__0004(uint8 IdType, uint32 Id, uint8* data, uint8
  datalen, uint8 operate, uint8 brs)
{
  if (IdType == 0) {
    if ((Id & 0x1FFFFFFF) == (RxTrig_XCP_BC_XCP1_msgID & 0x1FFFFFFF)) {
      rxFn_RxTrig_XCP_BC_XCP1(Id, datalen, data, operate, brs);
    }
  }

  if (IdType == 0) {
    if ((Id & 0x1FFFFFFF) == (RxTrig_XCP_CMD_XCP1_msgID & 0x1FFFFFFF)) {
      rxFn_RxTrig_XCP_CMD_XCP1(Id, datalen, data, operate, brs);
    }
  }

  if (IdType == 0) {
    if ((Id & 0x1FFFFFFF) == 0x603) {
      rxFn_uds_receive(Id, datalen, data, operate, brs);
    }
  }
}

const tBiosCanBitRates CAN_CAN1_baud_rate = BIOS_MCAN_BR_500KBPS;
uint32_T CAN_CAN1_get_baud_rate(void)
{
  uint32_T baud_rate;
  switch (CAN_CAN1_baud_rate)
  {
   case BIOS_MCAN_BR_33KBPS:
    baud_rate = 33000;
    break;

   case BIOS_MCAN_BR_50KBPS:
    baud_rate = 50000;
    break;

   case BIOS_MCAN_BR_100KBPS:
    baud_rate = 100000;
    break;

   case BIOS_MCAN_BR_125KBPS:
    baud_rate = 125000;
    break;

   case BIOS_MCAN_BR_200KBPS:
    baud_rate = 200000;
    break;

   case BIOS_MCAN_BR_250KBPS:
    baud_rate = 250000;
    break;

   case BIOS_MCAN_BR_333KBPS:
    baud_rate = 333333;
    break;

   case BIOS_MCAN_BR_500KBPS:
    baud_rate = 500000;
    break;

   case BIOS_MCAN_BR_667KBPS:
    baud_rate = 667000;
    break;

   case BIOS_MCAN_BR_800KBPS:
    baud_rate = 800000;
    break;

   case BIOS_MCAN_BR_1000KBPS:
    baud_rate = 1000000;
    break;

   default:
    baud_rate = 0;
  }

  return(baud_rate);
}

void post_start_CAN_531__0004(void)
{
  if (started_531__0004) {
    return;
  }

  started_531__0004 = 1;
  Bios_Can_RegisterRxCallBack (BIOS_MCAN_1, CAN_ReceiveDispatch_531__0004);
  Bios_Can_Start(BIOS_MCAN_1,
                 &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
                 &raptor_can_SubMcan_NominalBitTimings[CAN_CAN1_baud_rate]);
}                                      // end post_start_CAN_531__0004

void CANBusOff_Recovery_CAN1(void)
{
  if ((Bios_Can_GetError (BIOS_MCAN_1) & (uint16)
       BIOS_CAN_STATE_BUSOFF_ERROR_MASK) == (uint16)
      BIOS_CAN_STATE_BUSOFF_ERROR_MASK) {
    Bios_Can_Start (BIOS_MCAN_1,
                    &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
                    &raptor_can_SubMcan_NominalBitTimings[CAN_CAN1_baud_rate]);
  }
}