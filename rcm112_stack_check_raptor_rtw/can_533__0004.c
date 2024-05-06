/*****************************************************************************
   can_533__0004.c
   Generated By:
   Raptor 2023b_1.0.0 (9999_9999)
   Matlab (R2023a) 9.14

   Copyright (c) 2024 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Wed Mar 27 13:31:34 2024
 *****************************************************************************/

/* CAN interface: CAN3_LOCAL */
/*   HW Resource: CAN3 */
#include "rcm112_stack_check.h"
#include "rcm112_stack_check_private.h"
#include "can_533__0004.h"
#include "bootmailbox.h"
#include "Crc.h"
#include "Mcu_api.h"
#include "raptor_gen.h"
#define MAX_AGE                        65535

/* Arrays containing the bit timings */
extern const tBiosCanNomBitTimCfg raptor_can_SubMcan_NominalBitTimings[];/* tBiosCanBitRates */
extern const tBiosCanDataBitTimCfg raptor_can_SubMcan_DataBitTimings[];/* tBiosDataCanBitRates */
extern uint8_T app_is_in_shutdown;
int started_533__0004 = 0;

/* Message Receive data storage */

/* Transmit CAN Object Declarations */

/* Functions */
void pre_start_CAN_533__0004(void)
{
}                                      // end pre_start_CAN_533__0004

void CAN_ReceiveDispatch_533__0004(uint8 IdType, uint32 Id, uint8* data, uint8
  datalen, uint8 operate, uint8 brs)
{
  (void)IdType;
  (void)Id;
  (void)data;
  (void)datalen;
  (void)operate;
  (void)brs;
}

const tBiosCanBitRates CAN_CAN3_LOCAL_baud_rate = BIOS_MCAN_BR_500KBPS;
uint32_T CAN_CAN3_LOCAL_get_baud_rate(void)
{
  uint32_T baud_rate;
  switch (CAN_CAN3_LOCAL_baud_rate)
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

void post_start_CAN_533__0004(void)
{
  if (started_533__0004) {
    return;
  }

  started_533__0004 = 1;
  Bios_Can_RegisterRxCallBack (BIOS_MCAN_3, CAN_ReceiveDispatch_533__0004);
  Bios_Can_Start(BIOS_MCAN_3,
                 &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
                 &raptor_can_SubMcan_NominalBitTimings[CAN_CAN3_LOCAL_baud_rate]);
}                                      // end post_start_CAN_533__0004

void CANBusOff_Recovery_CAN3_LOCAL(void)
{
  if ((Bios_Can_GetError (BIOS_MCAN_3) & (uint16)
       BIOS_CAN_STATE_BUSOFF_ERROR_MASK) == (uint16)
      BIOS_CAN_STATE_BUSOFF_ERROR_MASK) {
    Bios_Can_Start (BIOS_MCAN_3,
                    &raptor_can_SubMcan_DataBitTimings[BIOS_MCAN_DBR_500KBPS],
                    &raptor_can_SubMcan_NominalBitTimings[CAN_CAN3_LOCAL_baud_rate]);
  }
}
