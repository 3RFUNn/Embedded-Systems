/*
 * File: Q4.c
 *
 * Code generated for Simulink model 'Q4'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Apr 23 21:10:53 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Q4.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Q4_IN_D                        ((uint8_T)1U)
#define Q4_IN_D1                       ((uint8_T)1U)
#define Q4_IN_D2                       ((uint8_T)2U)
#define Q4_IN_G                        ((uint8_T)2U)
#define Q4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define Q4_IN_b1                       ((uint8_T)1U)
#define Q4_IN_b2                       ((uint8_T)2U)

/* Block states (default storage) */
DW_Q4_T Q4_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Q4_T Q4_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Q4_T Q4_Y;

/* Real-time model */
static RT_MODEL_Q4_T Q4_M_;
RT_MODEL_Q4_T *const Q4_M = &Q4_M_;

/* Model step function */
void Q4_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/input_a'
   *  Inport: '<Root>/input_b'
   *  Inport: '<Root>/input_d'
   *  Inport: '<Root>/input_e'
   */
  if (Q4_DW.is_active_c3_Q4 == 0U) {
    Q4_DW.is_active_c3_Q4 = 1U;
    Q4_DW.is_B = Q4_IN_b1;

    /* Outport: '<Root>/S1' */
    Q4_Y.S1 = 1.0;
    Q4_DW.is_C = Q4_IN_G;

    /* Outport: '<Root>/G' */
    Q4_Y.G = 1.0;
  } else {
    if (Q4_DW.is_B == Q4_IN_b1) {
      if (Q4_DW.c == 1.0) {
        /* Outport: '<Root>/S1' */
        Q4_Y.S1 = 0.0;
        Q4_DW.is_B = Q4_IN_b2;

        /* Outport: '<Root>/S2' */
        Q4_Y.S2 = 1.0;
      }

      /* case IN_b2: */
    } else if ((Q4_U.input_b != 0.0) && (Q4_DW.is_D == Q4_IN_D2)) {
      /* Outport: '<Root>/S2' */
      Q4_Y.S2 = 0.0;
      Q4_DW.is_B = Q4_IN_b1;

      /* Outport: '<Root>/S1' */
      Q4_Y.S1 = 1.0;
    }

    if (Q4_DW.is_C == Q4_IN_D) {
      if (Q4_U.input_d != 0.0) {
        /* Outport: '<Root>/D2' */
        Q4_Y.D2 = 0.0;

        /* Outport: '<Root>/D1' */
        Q4_Y.D1 = 0.0;
        Q4_DW.is_D = Q4_IN_NO_ACTIVE_CHILD;
        Q4_DW.is_C = Q4_IN_G;

        /* Outport: '<Root>/G' */
        Q4_Y.G = 1.0;
      } else if (Q4_DW.is_D == Q4_IN_D1) {
        if (Q4_U.input_e != 0.0) {
          /* Outport: '<Root>/D1' */
          Q4_Y.D1 = 0.0;
          Q4_DW.is_D = Q4_IN_D2;

          /* Outport: '<Root>/D2' */
          Q4_Y.D2 = 1.0;
        }

        /* case IN_D2: */
      } else if (Q4_U.input_e != 0.0) {
        Q4_DW.is_D = Q4_IN_D2;

        /* Outport: '<Root>/D2' */
        Q4_Y.D2 = 1.0;
      }

      /* case IN_G: */
    } else if (Q4_U.input_a != 0.0) {
      Q4_DW.c = 1.0;

      /* Outport: '<Root>/G' */
      Q4_Y.G = 0.0;
      Q4_DW.is_C = Q4_IN_D;
      Q4_DW.is_D = Q4_IN_D1;

      /* Outport: '<Root>/D1' */
      Q4_Y.D1 = 1.0;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Q4_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Q4_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
