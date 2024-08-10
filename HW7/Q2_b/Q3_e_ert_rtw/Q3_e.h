/*
 * File: Q3_e.h
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

#ifndef RTW_HEADER_Q3_e_h_
#define RTW_HEADER_Q3_e_h_
#ifndef Q3_e_COMMON_INCLUDES_
#define Q3_e_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Q3_e_COMMON_INCLUDES_ */

#include "Q3_e_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T fan;                          /* '<Root>/Chart' */
  real_T dis;                          /* '<Root>/Chart' */
  real_T forward;                      /* '<Root>/Chart' */
} B_Q3_e_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_Q3_e;           /* '<Root>/Chart' */
  uint8_T is_c3_Q3_e;                  /* '<Root>/Chart' */
} DW_Q3_e_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  int16_T Input;                       /* '<Root>/Input' */
  int16_T Input1;                      /* '<Root>/Input1' */
} ExtU_Q3_e_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T Output;                      /* '<Root>/Output' */
  uint16_T Output1;                    /* '<Root>/Output1' */
  int16_T Output2;                     /* '<Root>/Output2' */
} ExtY_Q3_e_T;

/* Real-time Model Data Structure */
struct tag_RTM_Q3_e_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Q3_e_T Q3_e_B;

/* Block states (default storage) */
extern DW_Q3_e_T Q3_e_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Q3_e_T Q3_e_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Q3_e_T Q3_e_Y;

/* Model entry point functions */
extern void Q3_e_initialize(void);
extern void Q3_e_step(void);
extern void Q3_e_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Q3_e_T *const Q3_e_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Cast' : Eliminate redundant data type conversion
 * Block '<Root>/Cast1' : Eliminate redundant data type conversion
 */

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
#endif                                 /* RTW_HEADER_Q3_e_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
