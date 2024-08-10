/*
 * File: Q3_e.c
 *
 * Code generated for Simulink model 'Q3_e'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue May 30 21:50:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Q3_e.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Q3_e_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Q3_e_IN_Backward_Moving        ((uint8_T)1U)
#define Q3_e_IN_Forward_Moving         ((uint8_T)2U)

/* Block signals (default storage) */
B_Q3_e_T Q3_e_B;

/* Block states (default storage) */
DW_Q3_e_T Q3_e_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Q3_e_T Q3_e_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Q3_e_T Q3_e_Y;

/* Real-time model */
static RT_MODEL_Q3_e_T Q3_e_M_;
RT_MODEL_Q3_e_T *const Q3_e_M = &Q3_e_M_;

/* Model step function */
void Q3_e_step(void)
{
  real_T tmp;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   */
  if (Q3_e_DW.is_active_c3_Q3_e == 0U) {
    Q3_e_DW.is_active_c3_Q3_e = 1U;
    Q3_e_DW.is_c3_Q3_e = Q3_e_IN_Forward_Moving;
  } else if (Q3_e_DW.is_c3_Q3_e == Q3_e_IN_Backward_Moving) {
    if ((Q3_e_U.Input1 < 1600) || (Q3_e_U.Input > 1600)) {
      Q3_e_DW.is_c3_Q3_e = Q3_e_IN_Forward_Moving;
    } else if ((Q3_e_U.Input1 >= 1600) && (Q3_e_U.Input <= 1600)) {
      Q3_e_B.dis--;
    } else {
      Q3_e_B.fan = 0.0;
      Q3_e_B.forward = -1.0;
    }

    /* case IN_Forward_Moving: */
  } else if ((Q3_e_U.Input1 > 1600) || (Q3_e_U.Input < 1600)) {
    Q3_e_DW.is_c3_Q3_e = Q3_e_IN_Backward_Moving;
  } else if ((Q3_e_U.Input1 <= 1600) && (Q3_e_U.Input >= 1600)) {
    Q3_e_B.dis++;
    Q3_e_DW.is_c3_Q3_e = Q3_e_IN_Forward_Moving;
  } else {
    Q3_e_B.fan = 1.0;
    Q3_e_B.forward = 1.0;
  }

  /* End of Chart: '<Root>/Chart' */

  /* DataTypeConversion: '<Root>/Cast2' */
  tmp = floor(Q3_e_B.fan * 16.0);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Outport: '<Root>/Output' incorporates:
   *  DataTypeConversion: '<Root>/Cast2'
   */
  Q3_e_Y.Output = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp : (int16_T)(uint16_T)tmp;

  /* DataTypeConversion: '<Root>/Cast3' */
  tmp = floor(Q3_e_B.dis * 4096.0);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Outport: '<Root>/Output1' incorporates:
   *  DataTypeConversion: '<Root>/Cast3'
   */
  Q3_e_Y.Output1 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)
    tmp;

  /* DataTypeConversion: '<Root>/Cast4' */
  tmp = floor(Q3_e_B.forward * 16.0);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Outport: '<Root>/Output2' incorporates:
   *  DataTypeConversion: '<Root>/Cast4'
   */
  Q3_e_Y.Output2 = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp : (int16_T)(uint16_T)tmp;
}

/* Model initialize function */
void Q3_e_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Chart: '<Root>/Chart' */
  Q3_e_B.dis = 10.0;
}

/* Model terminate function */
void Q3_e_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
