/*
 * File: rcm112_stack_check_data.c
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

/* Invariant block signals (default storage) */
const ConstBlockIO_rcm112_stack_check rcm112_stack_check_ConstB = {
  0,                                   /* '<S8>/Logical Operator10' */
  1                                    /* '<S12>/Logical Operator4' */
};

/* Constant parameters (default storage) */
const ConstParam_rcm112_stack_check rcm112_stack_check_ConstP = {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S18>/Logic'
   */
  { false, true, false, false, true, true, false, false },

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S5>/Logic'
   *   '<S6>/Logic'
   *   '<S7>/Logic'
   *   '<S22>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
