/*
 * File: HW3_Q2.c
 *
 * Code generated for Simulink model 'HW3_Q2'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jun  6 17:22:44 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
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
  real_T rtb_a;
  real_T rtb_b;
  real_T rtb_b2;
  real_T rtb_b3;
  real_T rtb_d;
  real_T rtb_e;

  /* DiscretePulseGenerator: '<Root>/a' */
  rtb_a = (HW3_Q2_DW.clockTickCounter < HW3_Q2_P.a_Duty) &&
    (HW3_Q2_DW.clockTickCounter >= 0L) ? HW3_Q2_P.a_Amp : 0.0;
  if (HW3_Q2_DW.clockTickCounter >= HW3_Q2_P.a_Period - 1.0) {
    HW3_Q2_DW.clockTickCounter = 0L;
  } else {
    HW3_Q2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/a' */

  /* DiscretePulseGenerator: '<Root>/e' */
  rtb_e = (HW3_Q2_DW.clockTickCounter_g < HW3_Q2_P.e_Duty) &&
    (HW3_Q2_DW.clockTickCounter_g >= 0L) ? HW3_Q2_P.e_Amp : 0.0;
  if (HW3_Q2_DW.clockTickCounter_g >= HW3_Q2_P.e_Period - 1.0) {
    HW3_Q2_DW.clockTickCounter_g = 0L;
  } else {
    HW3_Q2_DW.clockTickCounter_g++;
  }

  /* End of DiscretePulseGenerator: '<Root>/e' */

  /* DiscretePulseGenerator: '<Root>/d' */
  rtb_d = (HW3_Q2_DW.clockTickCounter_i < HW3_Q2_P.d_Duty) &&
    (HW3_Q2_DW.clockTickCounter_i >= 0L) ? HW3_Q2_P.d_Amp : 0.0;
  if (HW3_Q2_DW.clockTickCounter_i >= HW3_Q2_P.d_Period - 1.0) {
    HW3_Q2_DW.clockTickCounter_i = 0L;
  } else {
    HW3_Q2_DW.clockTickCounter_i++;
  }

  /* End of DiscretePulseGenerator: '<Root>/d' */

  /* DiscretePulseGenerator: '<Root>/b2' */
  rtb_b2 = (HW3_Q2_DW.clockTickCounter_f < HW3_Q2_P.b2_Duty) &&
    (HW3_Q2_DW.clockTickCounter_f >= 0L) ? HW3_Q2_P.b2_Amp : 0.0;
  if (HW3_Q2_DW.clockTickCounter_f >= HW3_Q2_P.b2_Period - 1.0) {
    HW3_Q2_DW.clockTickCounter_f = 0L;
  } else {
    HW3_Q2_DW.clockTickCounter_f++;
  }

  /* End of DiscretePulseGenerator: '<Root>/b2' */

  /* DiscretePulseGenerator: '<Root>/b' */
  rtb_b = (HW3_Q2_DW.clockTickCounter_a < HW3_Q2_P.b_Duty) &&
    (HW3_Q2_DW.clockTickCounter_a >= 0L) ? HW3_Q2_P.b_Amp : 0.0;
  if (HW3_Q2_DW.clockTickCounter_a >= HW3_Q2_P.b_Period - 1.0) {
    HW3_Q2_DW.clockTickCounter_a = 0L;
  } else {
    HW3_Q2_DW.clockTickCounter_a++;
  }

  /* End of DiscretePulseGenerator: '<Root>/b' */

  /* DiscretePulseGenerator: '<Root>/b3' */
  rtb_b3 = (HW3_Q2_DW.clockTickCounter_c < HW3_Q2_P.b3_Duty) &&
    (HW3_Q2_DW.clockTickCounter_c >= 0L) ? HW3_Q2_P.b3_Amp : 0.0;
  if (HW3_Q2_DW.clockTickCounter_c >= HW3_Q2_P.b3_Period - 1.0) {
    HW3_Q2_DW.clockTickCounter_c = 0L;
  } else {
    HW3_Q2_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<Root>/b3' */

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
    } else if (((rtb_b != 0.0) || (rtb_b2 != 0.0) || (rtb_b3 != 0.0)) &&
               (HW3_Q2_DW.is_D == HW3_Q2_IN_D2)) {
      HW3_Q2_DW.is_B = HW3_Q2_IN_State_1;
    }

    if (HW3_Q2_DW.is_C == HW3_Q2_IN_D) {
      if (rtb_d != 0.0) {
        HW3_Q2_DW.is_D = HW3_Q2_IN_NO_ACTIVE_CHILD;
        HW3_Q2_DW.is_C = HW3_Q2_IN_G;
      } else if (HW3_Q2_DW.is_D == HW3_Q2_IN_D1) {
        if (rtb_e != 0.0) {
          HW3_Q2_DW.c = 0.0;
          HW3_Q2_DW.is_D = HW3_Q2_IN_D2;
        }

        /* case IN_D2: */
      } else if (rtb_e != 0.0) {
        HW3_Q2_DW.is_D = HW3_Q2_IN_D2;
      }

      /* case IN_G: */
    } else if (rtb_a != 0.0) {
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
  /* Start for DiscretePulseGenerator: '<Root>/a' */
  HW3_Q2_DW.clockTickCounter = -2L;

  /* Start for DiscretePulseGenerator: '<Root>/e' */
  HW3_Q2_DW.clockTickCounter_g = -6L;

  /* Start for DiscretePulseGenerator: '<Root>/d' */
  HW3_Q2_DW.clockTickCounter_i = -10L;

  /* Start for DiscretePulseGenerator: '<Root>/b2' */
  HW3_Q2_DW.clockTickCounter_f = -8L;

  /* Start for DiscretePulseGenerator: '<Root>/b' */
  HW3_Q2_DW.clockTickCounter_a = -4L;

  /* Start for DiscretePulseGenerator: '<Root>/b3' */
  HW3_Q2_DW.clockTickCounter_c = -12L;
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
