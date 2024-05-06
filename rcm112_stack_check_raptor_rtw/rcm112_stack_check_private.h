/*
 * File: rcm112_stack_check_private.h
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

#ifndef RTW_HEADER_rcm112_stack_check_private_h_
#define RTW_HEADER_rcm112_stack_check_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rcm112_stack_check_types.h"
#include "rcm112_stack_check.h"

extern void Timer_FGND_10MS_SensPower(void);
extern void Timer_Foreground(void);
extern void Timer_Background_50MS(void);
extern void Timer_Background_50MS_SBN1H(void);
extern void Timed_Trigger_XCP(void);
extern void RxTrig_XCP_BC_XCP1(void);
extern void RxTrig_XCP_CMD_XCP1(void);
extern void XCP1_XCP_CAN_PreStart(uint32_T, uint32_T, uint32_T);
extern void rcm112_stack_check_Background_Init(void);
extern void rcm112_stack_check_Background_Reset(void);
extern void rcm112_stack_check_Background(void);
extern void rcm112_stack_check_Background1_Init(void);
extern void rcm112_stack_check_Background1(void);
extern void rcm112_stack_check_SensorPowerEnable_Init(void);
extern void rcm112_stack_check_SensorPowerEnable(void);
extern void rcm112_stack_check_Foreground_Init(void);
extern void rcm112_stack_check_Foreground_Enable(void);
extern void rcm112_stack_check_Foreground(void);

#endif                            /* RTW_HEADER_rcm112_stack_check_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
