/*
 * File: Q3_e.h
 *
 * Code generated for Simulink model 'Q3_e'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri May 12 03:51:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Q3_e_h_
#define RTW_HEADER_Q3_e_h_
#ifndef Q3_e_COMMON_INCLUDES_
#define Q3_e_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Q3_e_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "MW_target_hardware_resources.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T distance;                     /* '<Root>/Chart' */
  uint8_T is_active_c3_Q3_e;           /* '<Root>/Chart' */
  uint8_T is_c3_Q3_e;                  /* '<Root>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  creal_T dist;                        /* '<Root>/dist' */
  real_T ppm;                          /* '<Root>/ppm' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T forward;                      /* '<Root>/forward' */
  real_T fan;                          /* '<Root>/fan' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Q3_e_initialize(void);
extern void Q3_e_step(void);
extern void Q3_e_terminate(void);
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
 * '<Root>' : 'Q3_e'
 * '<S1>'   : 'Q3_e/Chart'
 */

/*-
 * Requirements for '<Root>': Q3_e
 */
#endif                                 /* RTW_HEADER_Q3_e_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
