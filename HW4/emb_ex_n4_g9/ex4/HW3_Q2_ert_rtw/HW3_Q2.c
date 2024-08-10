/*
 * File: HW3_Q2.c
 *
 * Code generated for Simulink model 'HW3_Q2'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Apr 21 23:21:16 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HW3_Q2.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/A' */
#define HW3_Q2_IN_D                    ((uint8_T)1U)
#define HW3_Q2_IN_D1                   ((uint8_T)1U)
#define HW3_Q2_IN_D2                   ((uint8_T)2U)
#define HW3_Q2_IN_G                    ((uint8_T)2U)
#define HW3_Q2_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define HW3_Q2_IN_State_1              ((uint8_T)1U)
#define HW3_Q2_IN_State_2              ((uint8_T)2U)

/* Block states (default storage) */
DW_HW3_Q2_T HW3_Q2_DW;

/* Real-time model */
static RT_MODEL_HW3_Q2_T HW3_Q2_M_;
RT_MODEL_HW3_Q2_T *const HW3_Q2_M = &HW3_Q2_M_;

/* Model step function */
void HW3_Q2_step(void)
{
  int32_T rtb_PulseGenerator;
  int32_T rtb_PulseGenerator1;
  int32_T rtb_PulseGenerator2;
  int32_T rtb_PulseGenerator3;
  int32_T rtb_PulseGenerator4;
  int32_T rtb_PulseGenerator5;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = ((HW3_Q2_DW.clockTickCounter < 1) &&
                        (HW3_Q2_DW.clockTickCounter >= 0));
  if (HW3_Q2_DW.clockTickCounter >= 99) {
    HW3_Q2_DW.clockTickCounter = 0;
  } else {
    HW3_Q2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator5' */
  rtb_PulseGenerator5 = ((HW3_Q2_DW.clockTickCounter_g < 1) &&
    (HW3_Q2_DW.clockTickCounter_g >= 0));
  if (HW3_Q2_DW.clockTickCounter_g >= 99) {
    HW3_Q2_DW.clockTickCounter_g = 0;
  } else {
    HW3_Q2_DW.clockTickCounter_g++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator5' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator2' */
  rtb_PulseGenerator2 = ((HW3_Q2_DW.clockTickCounter_i < 1) &&
    (HW3_Q2_DW.clockTickCounter_i >= 0));
  if (HW3_Q2_DW.clockTickCounter_i >= 99) {
    HW3_Q2_DW.clockTickCounter_i = 0;
  } else {
    HW3_Q2_DW.clockTickCounter_i++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator2' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator4' */
  rtb_PulseGenerator4 = ((HW3_Q2_DW.clockTickCounter_f < 1) &&
    (HW3_Q2_DW.clockTickCounter_f >= 0));
  if (HW3_Q2_DW.clockTickCounter_f >= 99) {
    HW3_Q2_DW.clockTickCounter_f = 0;
  } else {
    HW3_Q2_DW.clockTickCounter_f++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator4' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator1 = ((HW3_Q2_DW.clockTickCounter_a < 1) &&
    (HW3_Q2_DW.clockTickCounter_a >= 0));
  if (HW3_Q2_DW.clockTickCounter_a >= 99) {
    HW3_Q2_DW.clockTickCounter_a = 0;
  } else {
    HW3_Q2_DW.clockTickCounter_a++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator3' */
  rtb_PulseGenerator3 = ((HW3_Q2_DW.clockTickCounter_c < 1) &&
    (HW3_Q2_DW.clockTickCounter_c >= 0));
  if (HW3_Q2_DW.clockTickCounter_c >= 99) {
    HW3_Q2_DW.clockTickCounter_c = 0;
  } else {
    HW3_Q2_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator3' */

  /* Chart: '<Root>/A' */
  if (HW3_Q2_DW.is_active_c3_HW3_Q2 == 0U) {
    HW3_Q2_DW.is_active_c3_HW3_Q2 = 1U;
    HW3_Q2_DW.is_B = HW3_Q2_IN_State_1;
    HW3_Q2_DW.is_C = HW3_Q2_IN_G;
  } else {
    if (HW3_Q2_DW.is_B == HW3_Q2_IN_State_1) {
      if (HW3_Q2_DW.c != 0.0) {
        HW3_Q2_DW.is_B = HW3_Q2_IN_State_2;
      }

      /* case IN_State_2: */
    } else if (((rtb_PulseGenerator1 != 0) || (rtb_PulseGenerator4 != 0) ||
                (rtb_PulseGenerator3 != 0)) && (HW3_Q2_DW.is_D == HW3_Q2_IN_D2))
    {
      HW3_Q2_DW.is_B = HW3_Q2_IN_State_1;
    }

    if (HW3_Q2_DW.is_C == HW3_Q2_IN_D) {
      if (rtb_PulseGenerator2 != 0) {
        HW3_Q2_DW.is_D = HW3_Q2_IN_NO_ACTIVE_CHILD;
        HW3_Q2_DW.is_C = HW3_Q2_IN_G;
      } else if (HW3_Q2_DW.is_D == HW3_Q2_IN_D1) {
        if (rtb_PulseGenerator5 != 0) {
          HW3_Q2_DW.c = 0.0;
          HW3_Q2_DW.is_D = HW3_Q2_IN_D2;
        }

        /* case IN_D2: */
      } else if (rtb_PulseGenerator5 != 0) {
        HW3_Q2_DW.is_D = HW3_Q2_IN_D2;
      }

      /* case IN_G: */
    } else if (rtb_PulseGenerator != 0) {
      HW3_Q2_DW.c = 1.0;
      HW3_Q2_DW.is_C = HW3_Q2_IN_D;
      HW3_Q2_DW.is_D = HW3_Q2_IN_D1;
    }
  }

  /* End of Chart: '<Root>/A' */
}

/* Model initialize function */
void HW3_Q2_initialize(void)
{
  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  HW3_Q2_DW.clockTickCounter = -2;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator5' */
  HW3_Q2_DW.clockTickCounter_g = -6;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator2' */
  HW3_Q2_DW.clockTickCounter_i = -10;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator4' */
  HW3_Q2_DW.clockTickCounter_f = -8;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  HW3_Q2_DW.clockTickCounter_a = -4;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator3' */
  HW3_Q2_DW.clockTickCounter_c = -12;
}

/* Model terminate function */
void HW3_Q2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
