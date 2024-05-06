/*
 * File: rcm112_stack_check.h
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

#ifndef RTW_HEADER_rcm112_stack_check_h_
#define RTW_HEADER_rcm112_stack_check_h_
#ifndef rcm112_stack_check_COMMON_INCLUDES_
#define rcm112_stack_check_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "data.h"
#include "Adc_api.h"
#include "Dio_api.h"
#include "IO_Config_api.h"
#include "Eth_api.h"
#include "raptor_gen.h"
#include "raptor_time.h"
#include "Dio.h"
#include "CanTrcv_cfg.h"
#include "CanTrcv_map.h"
#include "CanTrcv_api.h"
#include "Std_Types.h"
#include "TLE9255_drv.h"
#include "xcp_protocol.h"
#include "can_531__0004.h"
#include "stdio.h"
#include "string.h"
#include "can_532__0004.h"
#include "can_533__0004.h"
#include "can_534__0004.h"
#include "can_535__0004.h"
#endif                                 /* rcm112_stack_check_COMMON_INCLUDES_ */

#include "rcm112_stack_check_types.h"
#include <string.h>
#include "zero_crossing_types.h"

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay_DSTATE_j;           /* '<S18>/Unit Delay' */
  uint32_T DelayInput1_DSTATE;         /* '<S19>/Delay Input1' */
  uint32_T UnitDelay1_DSTATE;          /* '<S10>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_m;        /* '<S11>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_g;        /* '<S12>/Unit Delay1' */
  uint32_T raptor_delta_time_DWORK1;   /* '<S18>/raptor_delta_time' */
  boolean_T UnitDelay1_DSTATE_c;       /* '<S4>/Unit Delay1' */
  boolean_T UnitDelay2_DSTATE;         /* '<S4>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE;         /* '<S4>/Unit Delay3' */
  boolean_T UnitDelay2_DSTATE_m;       /* '<S8>/Unit Delay2' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S8>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_j;       /* '<S10>/Unit Delay2' */
  boolean_T UnitDelay2_DSTATE_b;       /* '<S11>/Unit Delay2' */
  boolean_T UnitDelay2_DSTATE_n;       /* '<S12>/Unit Delay2' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S24>/Delay Input1' */
  boolean_T UnitDelay2_DSTATE_l;       /* '<S18>/Unit Delay2' */
  boolean_T UnitDelay1_DSTATE_f;       /* '<S8>/Unit Delay1' */
  boolean_T Memory_PreviousInput;      /* '<S5>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S6>/Memory' */
  boolean_T Memory_PreviousInput_b4;   /* '<S7>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S22>/Memory' */
} D_Work_rcm112_stack_check;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StoreEEPROM_Trig_ZCE;     /* '<S8>/Store EEPROM' */
  ZCSigState RaiseStartupEvent_Trig_ZCE;/* '<S8>/Raise Startup Event' */
  ZCSigState RaiseShutdownEvent_Trig_ZCE;/* '<S8>/Raise Shutdown Event' */
} PrevZCSigStates_rcm112_stack_check;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T LogicalOperator10;   /* '<S8>/Logical Operator10' */
  const boolean_T LogicalOperator4;    /* '<S12>/Logical Operator4' */
} ConstBlockIO_rcm112_stack_check;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S18>/Logic'
   */
  boolean_T Logic_table[8];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S5>/Logic'
   *   '<S6>/Logic'
   *   '<S7>/Logic'
   *   '<S22>/Logic'
   */
  boolean_T pooled42[16];
} ConstParam_rcm112_stack_check;

/* Block states (default storage) */
extern D_Work_rcm112_stack_check rcm112_stack_check_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_rcm112_stack_check rcm112_stack_check_PrevZCSigState;
extern const ConstBlockIO_rcm112_stack_check rcm112_stack_check_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_rcm112_stack_check rcm112_stack_check_ConstP;

/* Model entry point functions */
extern void rcm112_stack_check_initialize(void);
extern void rcm112_stack_check_step(void);
extern void rcm112_stack_check_terminate(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'rcm112_stack_check'
 * '<S1>'   : 'rcm112_stack_check/Foreground'
 * '<S2>'   : 'rcm112_stack_check/Power Up_Down'
 * '<S3>'   : 'rcm112_stack_check/raptor_xcp_def'
 * '<S4>'   : 'rcm112_stack_check/Foreground/SensorPowerEnable'
 * '<S5>'   : 'rcm112_stack_check/Foreground/SensorPowerEnable/S-R Flip-Flop'
 * '<S6>'   : 'rcm112_stack_check/Foreground/SensorPowerEnable/S-R Flip-Flop1'
 * '<S7>'   : 'rcm112_stack_check/Foreground/SensorPowerEnable/S-R Flip-Flop2'
 * '<S8>'   : 'rcm112_stack_check/Power Up_Down/Background'
 * '<S9>'   : 'rcm112_stack_check/Power Up_Down/Background1'
 * '<S10>'  : 'rcm112_stack_check/Power Up_Down/Background/CntrSat'
 * '<S11>'  : 'rcm112_stack_check/Power Up_Down/Background/CntrSat1'
 * '<S12>'  : 'rcm112_stack_check/Power Up_Down/Background/CntrSat2'
 * '<S13>'  : 'rcm112_stack_check/Power Up_Down/Background/Compare To Constant'
 * '<S14>'  : 'rcm112_stack_check/Power Up_Down/Background/Compare To Constant1'
 * '<S15>'  : 'rcm112_stack_check/Power Up_Down/Background/Compare To Constant2'
 * '<S16>'  : 'rcm112_stack_check/Power Up_Down/Background/Compare To Constant3'
 * '<S17>'  : 'rcm112_stack_check/Power Up_Down/Background/Compare To Constant4'
 * '<S18>'  : 'rcm112_stack_check/Power Up_Down/Background/Debounce'
 * '<S19>'  : 'rcm112_stack_check/Power Up_Down/Background/Dtc'
 * '<S20>'  : 'rcm112_stack_check/Power Up_Down/Background/Raise Shutdown Event'
 * '<S21>'  : 'rcm112_stack_check/Power Up_Down/Background/Raise Startup Event'
 * '<S22>'  : 'rcm112_stack_check/Power Up_Down/Background/S-R Flip-Flop'
 * '<S23>'  : 'rcm112_stack_check/Power Up_Down/Background/Store EEPROM'
 * '<S24>'  : 'rcm112_stack_check/Power Up_Down/Background/Debounce/Detect Change'
 * '<S25>'  : 'rcm112_stack_check/Power Up_Down/Background/Raise Shutdown Event/raptor_shutdown'
 * '<S26>'  : 'rcm112_stack_check/Power Up_Down/Background/Raise Startup Event/raptor_startup'
 * '<S27>'  : 'rcm112_stack_check/Power Up_Down/Background/Store EEPROM/raptor_store_nv'
 */
#endif                                 /* RTW_HEADER_rcm112_stack_check_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
