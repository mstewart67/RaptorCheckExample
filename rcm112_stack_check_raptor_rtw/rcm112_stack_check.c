/*
 * File: rcm112_stack_check.c
 *
 * Code generated for Simulink model 'rcm112_stack_check'.
 *
 * Model version                  : 9.19
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Mar 27 13:31:34 2024
 *
 * Target selection: raptor.tlc
 * Embedded hardware selection: Freescale->MPC55xx
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rcm112_stack_check.h"
#include "rcm112_stack_check_private.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block states (default storage) */
D_Work_rcm112_stack_check rcm112_stack_check_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_rcm112_stack_check rcm112_stack_check_PrevZCSigState;

/* Block : rcm112_stack_check/Foreground/raptor_timed_trigger */
void Timer_FGND_10MS_SensPower(void)
{
  /* Timer_FGND_10MS_SensPower  ------   Task_Core0_Fgnd  */
  {
    {
      rcm112_stack_check_SensorPowerEnable();
    }
  }
}

/* Block : rcm112_stack_check/raptor_timed_trigger */
void Timer_Foreground(void)
{
  /* Timer_Foreground  ------   Foreground  */
  {
    {
      rcm112_stack_check_Foreground();
    }
  }
}

/* Block : rcm112_stack_check/Power Up_Down/raptor_timed_trigger */
void Timer_Background_50MS(void)
{
  /* Timer_Background_50MS  ------   Background  */
  {
    {
      rcm112_stack_check_Background();
    }
  }
}

/* Block : rcm112_stack_check/Power Up_Down/raptor_timed_trigger1 */
void Timer_Background_50MS_SBN1H(void)
{
  /* Timer_Background_50MS_SBN1H  ------   Background  */
  {
    {
      rcm112_stack_check_Background1();
    }
  }
}

/* System initialize for function-call system: '<S2>/Background' */
void rcm112_stack_check_Background_Init(void)
{
  /* Start for S-Function (raptor_sfun_digital_in): '<S8>/raptor_digital_in' */

  /* S-Function Block: WAKE_INPUT1 */
  {
  }

  /* Start for S-Function (raptor_sfun_internal_measurement): '<S8>/raptor_internal_measurement1' */

  /* S-Function Block: EthLinkStatus */
  {
  }

  /* Start for S-Function (raptor_sfun_internal_measurement): '<S8>/raptor_internal_measurement' */

  /* S-Function Block: WAKE_SOURCE */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S8>/raptor_digital_out' */

  /* S-Function Block: POWER_HOLD */
  {
  }

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_m = true;

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S18>/raptor_delta_time' */
  rcm112_stack_check_DWork.raptor_delta_time_DWORK1 = Bios_Rtos_GetTicksUs()/
    1000;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_l = true;
}

/* System reset for function-call system: '<S2>/Background' */
void rcm112_stack_check_Background_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_m = true;

  /* InitializeConditions for S-Function (raptor_sfun_delta_time): '<S18>/raptor_delta_time' */
  rcm112_stack_check_DWork.raptor_delta_time_DWORK1 = Bios_Rtos_GetTicksUs()/
    1000;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_l = true;
}

/* Output and update for function-call system: '<S2>/Background' */
void rcm112_stack_check_Background(void)
{
  /* local block i/o variables */
  real_T rtb_raptor_delta_time;
  uint32_T rtb_raptor_can_state1_o2;
  uint32_T rtb_raptor_can_state1_o3;
  int16_T rtb_raptor_can_state1_o1;
  boolean_T rtb_raptor_internal_measurement1;
  real_T rtb_MultiportSwitch1;
  uint32_T rtb_MultiportSwitch1_i;
  uint32_T rtb_MultiportSwitch1_l;
  uint32_T rtb_MultiportSwitch1_o;
  uint16_T rtb_raptor_internal_measurement;
  boolean_T rtb_Logic;
  boolean_T rtb_Logic_i_idx_0;
  boolean_T rtb_LogicalOperator2_o;
  boolean_T rtb_LogicalOperator3_c4;
  boolean_T rtb_LogicalOperator3_p;
  boolean_T rtb_LogicalOperator4_l;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_LogicalOperator6;
  boolean_T rtb_LogicalOperator8;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_UnitDelay2;
  boolean_T rtb_UnitDelay_c;
  boolean_T rtb_raptor_digital_in;

  /* UnitDelay: '<S8>/Unit Delay2' */
  rtb_UnitDelay2 = rcm112_stack_check_DWork.UnitDelay2_DSTATE_m;

  /* Outputs for Triggered SubSystem: '<S8>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S20>/Trigger'
   */
  if ((!rcm112_stack_check_DWork.UnitDelay2_DSTATE_m) &&
      (rcm112_stack_check_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE !=
       ZERO_ZCSIG)) {
    /* S-Function (raptor_sfun_data_write): '<S20>/raptor_data_write' incorporates:
     *  Constant: '<S20>/Constant'
     */
    FgndTasksStopped_Data() = true;

    /* S-Function (fcgen): '<S20>/Function-Call Generator' incorporates:
     *  SubSystem: '<S20>/raptor_shutdown'
     */
    /* S-Function (raptor_sfun_shutdown): '<S25>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Shutdown(void);
      App_Shutdown();
    }

    /* End of Outputs for S-Function (fcgen): '<S20>/Function-Call Generator' */
  }

  /* End of UnitDelay: '<S8>/Unit Delay2' */
  rcm112_stack_check_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE = rtb_UnitDelay2;

  /* End of Outputs for SubSystem: '<S8>/Raise Shutdown Event' */
  /* Outputs for Enabled and Triggered SubSystem: '<S8>/Raise Startup Event' incorporates:
   *  EnablePort: '<S21>/Enable'
   *  TriggerPort: '<S21>/Trigger'
   */
  if (FgndTasksStopped_Data() && (rtb_UnitDelay2 &&
       (rcm112_stack_check_PrevZCSigState.RaiseStartupEvent_Trig_ZCE !=
        POS_ZCSIG))) {
    /* S-Function (fcgen): '<S21>/Function-Call Generator' incorporates:
     *  SubSystem: '<S21>/raptor_startup'
     */
    /* S-Function (raptor_sfun_startup): '<S26>/raptor_data_write' */
    /* S-Function Block */
    {
      extern void App_Startup(void);
      App_Startup();
    }

    /* End of Outputs for S-Function (fcgen): '<S21>/Function-Call Generator' */
  }

  /* End of S-Function (raptor_sfun_data_read): '<S8>/raptor_data_read' */

  /* Outputs for Triggered SubSystem: '<S8>/Raise Shutdown Event' incorporates:
   *  TriggerPort: '<S20>/Trigger'
   */
  rcm112_stack_check_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = rtb_UnitDelay2;

  /* End of Outputs for SubSystem: '<S8>/Raise Shutdown Event' */
  /* End of Outputs for SubSystem: '<S8>/Raise Startup Event' */
  /* UnitDelay: '<S8>/Unit Delay' */
  rtb_UnitDelay_c = rcm112_stack_check_DWork.UnitDelay_DSTATE_a;

  /* Outputs for Enabled and Triggered SubSystem: '<S8>/Store EEPROM' incorporates:
   *  EnablePort: '<S23>/Enable'
   *  TriggerPort: '<S23>/Trigger'
   */
  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   *  S-Function (raptor_sfun_data_read): '<S8>/raptor_data_read2'
   *  S-Function (sfix_bitop): '<S8>/Bitwise AND'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  if (((((uint16_T)Wake_Source_Data()) & 1) == 1) &&
      ((!rcm112_stack_check_DWork.UnitDelay_DSTATE_a) &&
       (rcm112_stack_check_PrevZCSigState.StoreEEPROM_Trig_ZCE != ZERO_ZCSIG)))
  {
    /* S-Function (fcgen): '<S23>/Function-Call Generator' incorporates:
     *  SubSystem: '<S23>/raptor_store_nv'
     */
    /* S-Function (raptor_sfun_store_nv): '<S27>/raptor_data_write' */
    /* S-Function Block */
    {
      App_EE_Store();
    }

    /* End of Outputs for S-Function (fcgen): '<S23>/Function-Call Generator' */
  }

  /* End of RelationalOperator: '<S17>/Compare' */
  rcm112_stack_check_PrevZCSigState.StoreEEPROM_Trig_ZCE = rtb_UnitDelay_c;

  /* End of Outputs for SubSystem: '<S8>/Store EEPROM' */

  /* S-Function (raptor_sfun_digital_in): '<S8>/raptor_digital_in' */
  /* S-Function Block: WAKE_INPUT1 */
  {
    {
      sint32 KEYSW_M_value;
      Bios_Adc_GetValue(KEYSW_M, &KEYSW_M_value);
      rtb_raptor_digital_in = ((KEYSW_M_value > 200) ? 1 : 0);
    }
  }

  /* S-Function (raptor_sfun_can_state): '<S8>/raptor_can_state1' */
  /* S-Function Block: <S8>/raptor_can_state1 */
  {
    rtb_raptor_can_state1_o1 = Bios_Can_GetError(BIOS_MCAN_5);
    Bios_Can_GetBusState(BIOS_MCAN_5, &rtb_raptor_can_state1_o2,
                         &rtb_raptor_can_state1_o3);
  }

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Logic: '<S10>/Logical Operator1'
   *  MultiPortSwitch: '<S10>/Multiport Switch1'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  UnitDelay: '<S19>/Delay Input1'
   */
  rtb_LogicalOperator4_l = (rtb_raptor_can_state1_o2 !=
    rcm112_stack_check_DWork.DelayInput1_DSTATE);

  /* MultiPortSwitch: '<S10>/Multiport Switch1' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Logic: '<S10>/Logical Operator4'
   */
  rtb_RelationalOperator = !rtb_LogicalOperator4_l;
  if (rtb_RelationalOperator) {
    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant'
     *  Logic: '<S10>/Logical Operator1'
     *  Sum: '<S10>/Add'
     *  UnitDelay: '<S10>/Unit Delay1'
     *  UnitDelay: '<S10>/Unit Delay2'
     */
    if (rcm112_stack_check_DWork.UnitDelay2_DSTATE_j || rtb_LogicalOperator4_l)
    {
      rtb_MultiportSwitch1_i = rcm112_stack_check_DWork.UnitDelay1_DSTATE;
    } else {
      rtb_MultiportSwitch1_i = rcm112_stack_check_DWork.UnitDelay1_DSTATE + 1U;
    }

    /* End of MultiPortSwitch: '<S10>/Multiport Switch' */
  } else {
    rtb_MultiportSwitch1_i = 0U;
  }

  /* Logic: '<S10>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S10>/Relational Operator'
   *  S-Function (raptor_sfun_adjustment): '<S10>/raptor_adjustment'
   */
  rtb_RelationalOperator = ((rtb_MultiportSwitch1_i >=
    (Wake_CAN5_SleepDelayTime_Data())) && rtb_RelationalOperator);

  /* Logic: '<S8>/Logical Operator4' incorporates:
   *  Constant: '<S13>/Constant'
   *  Logic: '<S8>/Logical Operator3'
   *  RelationalOperator: '<S13>/Compare'
   *  S-Function (raptor_sfun_data_read): '<S8>/raptor_data_read5'
   *  S-Function (sfix_bitop): '<S8>/Bitwise AND3'
   */
  rtb_LogicalOperator4_l = ((!rtb_RelationalOperator) && ((((uint16_T)
    Wake_Source_Data()) & 16) == 16));

  /* S-Function (raptor_sfun_internal_measurement): '<S8>/raptor_internal_measurement1' */
  /* S-Function Block: EthLinkStatus */
  {
    {
      uint8 Bios_Eth_GetLinkStatus (void);
      rtb_raptor_internal_measurement1 = (boolean_T)Bios_Eth_GetLinkStatus();
    }
  }

  /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  if (!rtb_raptor_internal_measurement1) {
    /* MultiPortSwitch: '<S11>/Multiport Switch' incorporates:
     *  Constant: '<S11>/Constant'
     *  Logic: '<S11>/Logical Operator1'
     *  RelationalOperator: '<S15>/Compare'
     *  Sum: '<S11>/Add'
     *  UnitDelay: '<S11>/Unit Delay1'
     *  UnitDelay: '<S11>/Unit Delay2'
     */
    if (rcm112_stack_check_DWork.UnitDelay2_DSTATE_b ||
        rtb_raptor_internal_measurement1) {
      rtb_MultiportSwitch1_l = rcm112_stack_check_DWork.UnitDelay1_DSTATE_m;
    } else {
      rtb_MultiportSwitch1_l = rcm112_stack_check_DWork.UnitDelay1_DSTATE_m + 1U;
    }

    /* End of MultiPortSwitch: '<S11>/Multiport Switch' */
  } else {
    rtb_MultiportSwitch1_l = 0U;
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch1' */
  /* Logic: '<S11>/Logical Operator3' incorporates:
   *  Logic: '<S11>/Logical Operator4'
   *  RelationalOperator: '<S11>/Relational Operator'
   *  S-Function (raptor_sfun_adjustment): '<S11>/raptor_adjustment'
   */
  rtb_LogicalOperator3_c4 = ((rtb_MultiportSwitch1_l >=
    (Wake_ETH_SleepDelayTime_Data())) && (!rtb_raptor_internal_measurement1));

  /* Logic: '<S8>/Logical Operator6' incorporates:
   *  Constant: '<S14>/Constant'
   *  Logic: '<S8>/Logical Operator7'
   *  RelationalOperator: '<S14>/Compare'
   *  S-Function (raptor_sfun_data_read): '<S8>/raptor_data_read3'
   *  S-Function (sfix_bitop): '<S8>/Bitwise AND1'
   */
  rtb_LogicalOperator6 = (((((uint16_T)Wake_Source_Data()) & 64) == 64) &&
    (!rtb_LogicalOperator3_c4));

  /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (!rcm112_stack_check_ConstB.LogicalOperator10) {
    /* MultiPortSwitch: '<S12>/Multiport Switch' incorporates:
     *  Constant: '<S12>/Constant'
     *  Sum: '<S12>/Add'
     *  UnitDelay: '<S12>/Unit Delay1'
     *  UnitDelay: '<S12>/Unit Delay2'
     */
    if (rcm112_stack_check_DWork.UnitDelay2_DSTATE_n) {
      rtb_MultiportSwitch1_o = rcm112_stack_check_DWork.UnitDelay1_DSTATE_g;
    } else {
      rtb_MultiportSwitch1_o = rcm112_stack_check_DWork.UnitDelay1_DSTATE_g + 1U;
    }

    /* End of MultiPortSwitch: '<S12>/Multiport Switch' */
  } else {
    rtb_MultiportSwitch1_o = 0U;
  }

  /* End of MultiPortSwitch: '<S12>/Multiport Switch1' */
  /* Logic: '<S12>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S12>/Relational Operator'
   *  S-Function (raptor_sfun_adjustment): '<S12>/raptor_adjustment'
   */
  rtb_LogicalOperator3_p = ((rtb_MultiportSwitch1_o >=
    (Wake_LIN2_SleepDelayTime_Data())) &&
    rcm112_stack_check_ConstB.LogicalOperator4);

  /* Logic: '<S8>/Logical Operator8' incorporates:
   *  Constant: '<S16>/Constant'
   *  Logic: '<S8>/Logical Operator9'
   *  RelationalOperator: '<S16>/Compare'
   *  S-Function (raptor_sfun_data_read): '<S8>/raptor_data_read4'
   *  S-Function (sfix_bitop): '<S8>/Bitwise AND2'
   */
  rtb_LogicalOperator8 = (((((uint16_T)Wake_Source_Data()) & 32) == 32) &&
    (!rtb_LogicalOperator3_p));

  /* Logic: '<S8>/Logical Operator5' */
  rtb_LogicalOperator5 = (rtb_raptor_digital_in || rtb_LogicalOperator4_l ||
    rtb_LogicalOperator6 || rtb_LogicalOperator8);

  /* S-Function (raptor_sfun_delta_time): '<S18>/raptor_delta_time' */
  {
    rtb_raptor_delta_time = (raptor_GetDeltaTime_ms((uint32_T*)
      &rcm112_stack_check_DWork.raptor_delta_time_DWORK1) * 0.001);
  }

  /* MultiPortSwitch: '<S18>/Multiport Switch1' incorporates:
   *  Constant: '<S18>/Constant'
   *  RelationalOperator: '<S24>/FixPt Relational Operator'
   *  Sum: '<S18>/Add'
   *  UnitDelay: '<S18>/Unit Delay'
   *  UnitDelay: '<S24>/Delay Input1'
   */
  if (rtb_LogicalOperator5 == rcm112_stack_check_DWork.DelayInput1_DSTATE_h) {
    rtb_MultiportSwitch1 = rtb_raptor_delta_time +
      rcm112_stack_check_DWork.UnitDelay_DSTATE_j;
  } else {
    rtb_MultiportSwitch1 = 0.0;
  }

  /* End of MultiPortSwitch: '<S18>/Multiport Switch1' */
  /* UnitDelay: '<S18>/Unit Delay2' */
  rtb_LogicalOperator2_o = rcm112_stack_check_DWork.UnitDelay2_DSTATE_l;

  /* CombinatorialLogic: '<S18>/Logic' incorporates:
   *  Logic: '<S18>/Logical Operator1'
   *  Logic: '<S18>/Logical Operator2'
   *  Logic: '<S18>/Logical Operator3'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  RelationalOperator: '<S18>/Relational Operator1'
   *  S-Function (raptor_sfun_adjustment): '<S18>/raptor_adjustment3'
   *  S-Function (raptor_sfun_adjustment): '<S18>/raptor_adjustment4'
   */
  rtb_Logic = rcm112_stack_check_ConstP.Logic_table[((((uint32_T)
    (rtb_LogicalOperator5 && (rtb_MultiportSwitch1 >= (KeySwHiTimeThr_Data()))) <<
    1) + (uint32_T)((!rtb_LogicalOperator5) && (rtb_MultiportSwitch1 >=
    (KeySwLoTimeThr_Data())))) << 1) + rtb_LogicalOperator2_o];

  /* S-Function (raptor_sfun_data_write): '<S8>/raptor_data_write' */
  KeySw_Bgnd_Data() = rtb_Logic;

  /* S-Function (raptor_sfun_nv_status): '<S8>/raptor_sfun_nv_status' */
  /* S-Function Block */
  {
    rtb_LogicalOperator2_o = (EEPROM_State_Data() == EE_STORE_IN_PROGESS);
  }

  /* Logic: '<S8>/Logical Operator2' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  rtb_LogicalOperator2_o = (rtb_LogicalOperator2_o || rtb_UnitDelay2 ||
    rcm112_stack_check_DWork.UnitDelay1_DSTATE_f);

  /* S-Function (raptor_sfun_data_write): '<S8>/raptor_data_write1' */
  MPRD_EN_Data() = rtb_LogicalOperator2_o;

  /* S-Function (raptor_sfun_internal_measurement): '<S8>/raptor_internal_measurement' */
  /* S-Function Block: WAKE_SOURCE */
  {
    extern uint16 Bios_Mcu_GetWakeUpReason(void);
    rtb_raptor_internal_measurement = (uint16_t)Bios_Mcu_GetWakeUpReason();
  }

  /* CombinatorialLogic: '<S22>/Logic' incorporates:
   *  Memory: '<S22>/Memory'
   */
  rtb_Logic_i_idx_0 = rcm112_stack_check_ConstP.pooled42[((uint32_T)
    rtb_raptor_digital_in << 2) +
    rcm112_stack_check_DWork.Memory_PreviousInput_c];

  /* S-Function (sfix_bitop): '<S8>/Bitwise OR' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   */
  rtb_raptor_internal_measurement |= rtb_Logic_i_idx_0;

  /* S-Function (raptor_sfun_data_write): '<S8>/raptor_data_write2' */
  Wake_Source_Data() = rtb_raptor_internal_measurement;

  /* S-Function (raptor_sfun_digital_out): '<S8>/raptor_digital_out' */
  /* S-Function Block: POWER_HOLD */
  {
    {
      static uint8_T prevInput = 0U;
      if (rtb_LogicalOperator2_o == 0U && prevInput == 1U) {
        Module_Shutdown(1);
      }

      prevInput = rtb_LogicalOperator2_o;
    }
  }

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement' */
  CANWakeIndicator_Data() = rtb_LogicalOperator4_l;

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement1' */
  EthWakeIndicator_Data() = rtb_LogicalOperator6;

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement2' */
  EthLinkStatus_Data() = rtb_raptor_internal_measurement1;

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement3' */
  LINWakeIndicator_Data() = rtb_LogicalOperator8;

  /* S-Function (raptor_sfun_measurement): '<S8>/raptor_measurement5' */
  Wake_CAN5_RxCount_Data() = rtb_raptor_can_state1_o2;

  /* S-Function (raptor_sfun_measurement): '<S10>/raptor_measurement' */
  Wake_CAN5_SleepDelayTTmr_Data() = rtb_MultiportSwitch1_i;

  /* S-Function (raptor_sfun_measurement): '<S11>/raptor_measurement' */
  Wake_ETH_SleepDelayTTmr_Data() = rtb_MultiportSwitch1_l;

  /* S-Function (raptor_sfun_measurement): '<S12>/raptor_measurement' */
  Wake_LIN2_SleepDelayTTmr_Data() = rtb_MultiportSwitch1_o;

  /* Logic: '<S8>/Logical Operator1' incorporates:
   *  S-Function (raptor_sfun_data_read): '<S8>/raptor_data_read1'
   */
  rtb_raptor_digital_in = (rtb_Logic || KeepModuleOn_Data());

  /* Update for UnitDelay: '<S8>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_m = rtb_raptor_digital_in;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  rcm112_stack_check_DWork.UnitDelay_DSTATE_a = rtb_UnitDelay2;

  /* Update for UnitDelay: '<S19>/Delay Input1' */
  rcm112_stack_check_DWork.DelayInput1_DSTATE = rtb_raptor_can_state1_o2;

  /* Update for UnitDelay: '<S10>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_j = rtb_RelationalOperator;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  rcm112_stack_check_DWork.UnitDelay1_DSTATE = rtb_MultiportSwitch1_i;

  /* Update for UnitDelay: '<S11>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_b = rtb_LogicalOperator3_c4;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  rcm112_stack_check_DWork.UnitDelay1_DSTATE_m = rtb_MultiportSwitch1_l;

  /* Update for UnitDelay: '<S12>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_n = rtb_LogicalOperator3_p;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  rcm112_stack_check_DWork.UnitDelay1_DSTATE_g = rtb_MultiportSwitch1_o;

  /* Update for UnitDelay: '<S24>/Delay Input1' */
  rcm112_stack_check_DWork.DelayInput1_DSTATE_h = rtb_LogicalOperator5;

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  rcm112_stack_check_DWork.UnitDelay_DSTATE_j = rtb_MultiportSwitch1;

  /* Update for UnitDelay: '<S18>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE_l = rtb_Logic;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  rcm112_stack_check_DWork.UnitDelay1_DSTATE_f = rtb_UnitDelay_c;

  /* Update for Memory: '<S22>/Memory' */
  rcm112_stack_check_DWork.Memory_PreviousInput_c = rtb_Logic_i_idx_0;
}

/* System initialize for function-call system: '<S2>/Background1' */
void rcm112_stack_check_Background1_Init(void)
{
  /* Start for S-Function (raptor_sfun_digital_out): '<S9>/raptor_digital_out1' */

  /* S-Function Block: MPRD_EN */
  {
  }
}

/* Output and update for function-call system: '<S2>/Background1' */
void rcm112_stack_check_Background1(void)
{
  /* S-Function (raptor_sfun_data_read): '<S9>/raptor_data_read1' */
  /* S-Function (raptor_sfun_digital_out): '<S9>/raptor_digital_out1' incorporates:
   *  S-Function (raptor_sfun_data_read): '<S9>/raptor_data_read1'
   */
  /* S-Function Block: MPRD_EN */
  {
    {
      Bios_Dio_SetOutputLevel(MPRD_EN, MPRD_EN_Data());
    }
  }
}

/* System initialize for function-call system: '<S1>/SensorPowerEnable' */
void rcm112_stack_check_SensorPowerEnable_Init(void)
{
  /* Start for S-Function (raptor_sfun_digital_out): '<S4>/raptor_digital_out' */

  /* S-Function Block: SENSOR_POWER_A_EN */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S4>/raptor_digital_out1' */

  /* S-Function Block: SENSOR_POWER_B_EN */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S4>/raptor_digital_out2' */

  /* S-Function Block: SENSOR_POWER_C_EN */
  {
  }

  /* Start for S-Function (raptor_sfun_digital_out): '<S4>/raptor_digital_out3' */

  /* S-Function Block: SENSOR_POWER_D_EN */
  {
  }
}

/* Output and update for function-call system: '<S1>/SensorPowerEnable' */
void rcm112_stack_check_SensorPowerEnable(void)
{
  /* local block i/o variables */
  boolean_T rtb_raptor_adjustment_m;
  int32_T rowIdx;
  boolean_T rtb_Logic[2];
  boolean_T rtb_Logic_g[2];
  boolean_T rtb_Logic_o[2];
  boolean_T rtb_NOT;
  boolean_T rtb_UnitDelay1_a;
  boolean_T rtb_UnitDelay2;

  /* S-Function (raptor_sfun_adjustment): '<S4>/raptor_adjustment' */
  rtb_raptor_adjustment_m = (SensorPowerEnable_Data());

  /* S-Function (raptor_sfun_digital_out): '<S4>/raptor_digital_out' */
  /* S-Function Block: SENSOR_POWER_A_EN */
  {
    {
      Bios_Dio_SetOutputLevel(SENSOR_POWER_A_EN_M, rtb_raptor_adjustment_m);
    }
  }

  /* UnitDelay: '<S4>/Unit Delay1' */
  rtb_UnitDelay1_a = rcm112_stack_check_DWork.UnitDelay1_DSTATE_c;

  /* Logic: '<S4>/NOT' */
  rtb_NOT = !rtb_raptor_adjustment_m;

  /* CombinatorialLogic: '<S5>/Logic' incorporates:
   *  Memory: '<S5>/Memory'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rowIdx = (int32_T)(((((uint32_T)rcm112_stack_check_DWork.UnitDelay1_DSTATE_c <<
                        1) + rtb_NOT) << 1) +
                     rcm112_stack_check_DWork.Memory_PreviousInput);
  rtb_Logic[0U] = rcm112_stack_check_ConstP.pooled42[(uint32_T)rowIdx];
  rtb_Logic[1U] = rcm112_stack_check_ConstP.pooled42[(uint32_T)rowIdx + 8U];

  /* S-Function (raptor_sfun_digital_out): '<S4>/raptor_digital_out1' */
  /* S-Function Block: SENSOR_POWER_B_EN */
  {
    {
      Bios_Dio_SetOutputLevel(SENSOR_POWER_B_EN_M, rtb_Logic[0]);
    }
  }

  /* UnitDelay: '<S4>/Unit Delay2' */
  rtb_UnitDelay2 = rcm112_stack_check_DWork.UnitDelay2_DSTATE;

  /* CombinatorialLogic: '<S6>/Logic' incorporates:
   *  Memory: '<S6>/Memory'
   *  UnitDelay: '<S4>/Unit Delay2'
   */
  rowIdx = (int32_T)(((((uint32_T)rcm112_stack_check_DWork.UnitDelay2_DSTATE <<
                        1) + rtb_NOT) << 1) +
                     rcm112_stack_check_DWork.Memory_PreviousInput_b);
  rtb_Logic_o[0U] = rcm112_stack_check_ConstP.pooled42[(uint32_T)rowIdx];
  rtb_Logic_o[1U] = rcm112_stack_check_ConstP.pooled42[(uint32_T)rowIdx + 8U];

  /* S-Function (raptor_sfun_digital_out): '<S4>/raptor_digital_out2' */
  /* S-Function Block: SENSOR_POWER_C_EN */
  {
    {
      Bios_Dio_SetOutputLevel(SENSOR_POWER_C_EN_M, rtb_Logic_o[0]);
    }
  }

  /* CombinatorialLogic: '<S7>/Logic' incorporates:
   *  Memory: '<S7>/Memory'
   *  UnitDelay: '<S4>/Unit Delay3'
   */
  rowIdx = (int32_T)(((((uint32_T)rcm112_stack_check_DWork.UnitDelay3_DSTATE <<
                        1) + rtb_NOT) << 1) +
                     rcm112_stack_check_DWork.Memory_PreviousInput_b4);
  rtb_Logic_g[0U] = rcm112_stack_check_ConstP.pooled42[(uint32_T)rowIdx];
  rtb_Logic_g[1U] = rcm112_stack_check_ConstP.pooled42[(uint32_T)rowIdx + 8U];

  /* S-Function (raptor_sfun_digital_out): '<S4>/raptor_digital_out3' */
  /* S-Function Block: SENSOR_POWER_D_EN */
  {
    {
      Bios_Dio_SetOutputLevel(SENSOR_POWER_D_EN_M, rtb_Logic_g[0]);
    }
  }

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  rcm112_stack_check_DWork.UnitDelay1_DSTATE_c = rtb_raptor_adjustment_m;

  /* Update for Memory: '<S5>/Memory' */
  rcm112_stack_check_DWork.Memory_PreviousInput = rtb_Logic[0];

  /* Update for UnitDelay: '<S4>/Unit Delay2' */
  rcm112_stack_check_DWork.UnitDelay2_DSTATE = rtb_UnitDelay1_a;

  /* Update for Memory: '<S6>/Memory' */
  rcm112_stack_check_DWork.Memory_PreviousInput_b = rtb_Logic_o[0];

  /* Update for UnitDelay: '<S4>/Unit Delay3' */
  rcm112_stack_check_DWork.UnitDelay3_DSTATE = rtb_UnitDelay2;

  /* Update for Memory: '<S7>/Memory' */
  rcm112_stack_check_DWork.Memory_PreviousInput_b4 = rtb_Logic_g[0];
}

/* System initialize for function-call system: '<Root>/Foreground' */
void rcm112_stack_check_Foreground_Init(void)
{
  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S1>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<S1>/SensorPowerEnable'
   */
  rcm112_stack_check_SensorPowerEnable_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S1>/raptor_timed_trigger' */
}

/* Enable for function-call system: '<Root>/Foreground' */
void rcm112_stack_check_Foreground_Enable(void)
{
  /* Enable for S-Function (raptor_sfun_timed_trigger): '<S1>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<S1>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<S1>/raptor_timed_trigger' */
}

/* Output and update for function-call system: '<Root>/Foreground' */
void rcm112_stack_check_Foreground(void)
{
  real_T rtb_Add_j;

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Add_j = rcm112_stack_check_DWork.UnitDelay_DSTATE + 1.0;

  /* S-Function (raptor_sfun_measurement): '<S1>/raptor_measurement' */
  Counter_Data() = rtb_Add_j;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  rcm112_stack_check_DWork.UnitDelay_DSTATE = rtb_Add_j;
}

/* Model step function */
void rcm112_stack_check_step(void)
{
  /* S-Function (raptor_sfun_target_def): '<Root>/raptor_target_def' */

  /*
   * New Eagle LLC 2011
   */
}

/* Model initialize function */
void rcm112_stack_check_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&rcm112_stack_check_DWork, 0,
                sizeof(D_Work_rcm112_stack_check));
  rcm112_stack_check_DWork.UnitDelay_DSTATE = 0.0;
  rcm112_stack_check_DWork.UnitDelay_DSTATE_j = 0.0;

  /* Start for S-Function (raptor_sfun_xcp): '<S3>/raptor_xcp_update' */

  /* S-Function Block - Start: <S3>/raptor_xcp_update */
  {
    XCP1_XCP_CAN_PreStart(XCP1__XCP_BC_ID_Data(), XCP1__XCP_RX_ID_Data(),
                          XCP1__XCP_TX_ID_Data());
  }

  /* Start for S-Function (raptor_sfun_target_def): '<Root>/raptor_target_def' */

  /* S-Function Block - Start: <Root>/raptor_target_def */
  {
    UDSClientAddr_RAM_Data() = 1619;
  }

  /* S-Function Block - Start: <Root>/raptor_target_def */
  {
    UDSServerAddr_RAM_Data() = 1539;
  }

  rcm112_stack_check_PrevZCSigState.RaiseShutdownEvent_Trig_ZCE = ZERO_ZCSIG;
  rcm112_stack_check_PrevZCSigState.RaiseStartupEvent_Trig_ZCE = POS_ZCSIG;
  rcm112_stack_check_PrevZCSigState.StoreEEPROM_Trig_ZCE = ZERO_ZCSIG;

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  rcm112_stack_check_Foreground_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<S2>/Background'
   */
  rcm112_stack_check_Background_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */

  /* SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger1' incorporates:
   *  SubSystem: '<S2>/Background1'
   */
  rcm112_stack_check_Background1_Init();

  /* End of SystemInitialize for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger1' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<Root>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */
  rcm112_stack_check_Foreground_Enable();

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' incorporates:
   *  SubSystem: '<Root>/Foreground'
   */
  rcm112_stack_check_Foreground_Enable();

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<Root>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */

  /* Level2 S-Function Block: '<S2>/raptor_timed_trigger' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger' */

  /* Enable for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger1' */

  /* Level2 S-Function Block: '<S2>/raptor_timed_trigger1' (raptor_sfun_timed_trigger) */

  /* Enable Subsystem */

  /* End of Enable for S-Function (raptor_sfun_timed_trigger): '<S2>/raptor_timed_trigger1' */
}

/* Model terminate function */
void rcm112_stack_check_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
