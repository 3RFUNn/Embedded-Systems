/*
 * File: HW3_Q2.h
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

#ifndef RTW_HEADER_HW3_Q2_h_
#define RTW_HEADER_HW3_Q2_h_
#ifndef HW3_Q2_COMMON_INCLUDES_
#define HW3_Q2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* HW3_Q2_COMMON_INCLUDES_ */

#include "HW3_Q2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T c;                            /* '<Root>/A' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T clockTickCounter_g;          /* '<Root>/Pulse Generator5' */
  int32_T clockTickCounter_i;          /* '<Root>/Pulse Generator2' */
  int32_T clockTickCounter_f;          /* '<Root>/Pulse Generator4' */
  int32_T clockTickCounter_a;          /* '<Root>/Pulse Generator1' */
  int32_T clockTickCounter_c;          /* '<Root>/Pulse Generator3' */
  uint8_T is_active_c3_HW3_Q2;         /* '<Root>/A' */
  uint8_T is_B;                        /* '<Root>/A' */
  uint8_T is_C;                        /* '<Root>/A' */
  uint8_T is_D;                        /* '<Root>/A' */
} DW_HW3_Q2_T;

/* Real-time Model Data Structure */
struct tag_RTM_HW3_Q2_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_HW3_Q2_T HW3_Q2_DW;

/* Model entry point functions */
extern void HW3_Q2_initialize(void);
extern void HW3_Q2_step(void);
extern void HW3_Q2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HW3_Q2_T *const HW3_Q2_M;

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
 * '<Root>' : 'HW3_Q2'
 * '<S1>'   : 'HW3_Q2/A'
 */
#endif                                 /* RTW_HEADER_HW3_Q2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
