/*
 * File: Q4.h
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

#ifndef RTW_HEADER_Q4_h_
#define RTW_HEADER_Q4_h_
#ifndef Q4_COMMON_INCLUDES_
#define Q4_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Q4_COMMON_INCLUDES_ */

#include "Q4_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T c;                            /* '<Root>/Chart' */
  uint8_T is_active_c3_Q4;             /* '<Root>/Chart' */
  uint8_T is_B;                        /* '<Root>/Chart' */
  uint8_T is_C;                        /* '<Root>/Chart' */
  uint8_T is_D;                        /* '<Root>/Chart' */
} DW_Q4_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T input_a;                      /* '<Root>/input_a' */
  real_T input_b;                      /* '<Root>/input_b' */
  real_T input_d;                      /* '<Root>/input_d' */
  real_T input_e;                      /* '<Root>/input_e' */
} ExtU_Q4_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T D1;                           /* '<Root>/D1' */
  real_T D2;                           /* '<Root>/D2' */
  real_T G;                            /* '<Root>/G' */
  real_T S1;                           /* '<Root>/S1' */
  real_T S2;                           /* '<Root>/S2' */
} ExtY_Q4_T;

/* Real-time Model Data Structure */
struct tag_RTM_Q4_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Q4_T Q4_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Q4_T Q4_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Q4_T Q4_Y;

/* Model entry point functions */
extern void Q4_initialize(void);
extern void Q4_step(void);
extern void Q4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Q4_T *const Q4_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Q4'
 * '<S1>'   : 'Q4/Chart'
 */
#endif                                 /* RTW_HEADER_Q4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
