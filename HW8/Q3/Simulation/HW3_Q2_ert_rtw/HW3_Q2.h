/*
 * File: HW3_Q2.h
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

#ifndef RTW_HEADER_HW3_Q2_h_
#define RTW_HEADER_HW3_Q2_h_
#ifndef HW3_Q2_COMMON_INCLUDES_
#define HW3_Q2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* HW3_Q2_COMMON_INCLUDES_ */

#include "HW3_Q2_types.h"
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
  real_T c;                            /* '<Root>/A' */
  int32_T clockTickCounter;            /* '<Root>/a' */
  int32_T clockTickCounter_g;          /* '<Root>/e' */
  int32_T clockTickCounter_i;          /* '<Root>/d' */
  int32_T clockTickCounter_f;          /* '<Root>/b2' */
  int32_T clockTickCounter_a;          /* '<Root>/b' */
  int32_T clockTickCounter_c;          /* '<Root>/b3' */
  uint8_T is_active_c3_HW3_Q2;         /* '<Root>/A' */
  uint8_T is_B;                        /* '<Root>/A' */
  uint8_T is_C;                        /* '<Root>/A' */
  uint8_T is_D;                        /* '<Root>/A' */
} DW_HW3_Q2_T;

/* Parameters (default storage) */
struct P_HW3_Q2_T_ {
  real_T a_Amp;                        /* Expression: 1
                                        * Referenced by: '<Root>/a'
                                        */
  real_T a_Period;                     /* Computed Parameter: a_Period
                                        * Referenced by: '<Root>/a'
                                        */
  real_T a_Duty;                       /* Computed Parameter: a_Duty
                                        * Referenced by: '<Root>/a'
                                        */
  real_T a_PhaseDelay;                 /* Expression: 2
                                        * Referenced by: '<Root>/a'
                                        */
  real_T e_Amp;                        /* Expression: 1
                                        * Referenced by: '<Root>/e'
                                        */
  real_T e_Period;                     /* Computed Parameter: e_Period
                                        * Referenced by: '<Root>/e'
                                        */
  real_T e_Duty;                       /* Computed Parameter: e_Duty
                                        * Referenced by: '<Root>/e'
                                        */
  real_T e_PhaseDelay;                 /* Expression: 6
                                        * Referenced by: '<Root>/e'
                                        */
  real_T d_Amp;                        /* Expression: 1
                                        * Referenced by: '<Root>/d'
                                        */
  real_T d_Period;                     /* Computed Parameter: d_Period
                                        * Referenced by: '<Root>/d'
                                        */
  real_T d_Duty;                       /* Computed Parameter: d_Duty
                                        * Referenced by: '<Root>/d'
                                        */
  real_T d_PhaseDelay;                 /* Expression: 10
                                        * Referenced by: '<Root>/d'
                                        */
  real_T b2_Amp;                       /* Expression: 1
                                        * Referenced by: '<Root>/b2'
                                        */
  real_T b2_Period;                    /* Computed Parameter: b2_Period
                                        * Referenced by: '<Root>/b2'
                                        */
  real_T b2_Duty;                      /* Computed Parameter: b2_Duty
                                        * Referenced by: '<Root>/b2'
                                        */
  real_T b2_PhaseDelay;                /* Expression: 8
                                        * Referenced by: '<Root>/b2'
                                        */
  real_T b_Amp;                        /* Expression: 1
                                        * Referenced by: '<Root>/b'
                                        */
  real_T b_Period;                     /* Computed Parameter: b_Period
                                        * Referenced by: '<Root>/b'
                                        */
  real_T b_Duty;                       /* Computed Parameter: b_Duty
                                        * Referenced by: '<Root>/b'
                                        */
  real_T b_PhaseDelay;                 /* Expression: 4
                                        * Referenced by: '<Root>/b'
                                        */
  real_T b3_Amp;                       /* Expression: 1
                                        * Referenced by: '<Root>/b3'
                                        */
  real_T b3_Period;                    /* Computed Parameter: b3_Period
                                        * Referenced by: '<Root>/b3'
                                        */
  real_T b3_Duty;                      /* Computed Parameter: b3_Duty
                                        * Referenced by: '<Root>/b3'
                                        */
  real_T b3_PhaseDelay;                /* Expression: 12
                                        * Referenced by: '<Root>/b3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_HW3_Q2_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_HW3_Q2_T HW3_Q2_P;

/* Block states (default storage) */
extern DW_HW3_Q2_T HW3_Q2_DW;

/* Model entry point functions */
extern void HW3_Q2_initialize(void);
extern void HW3_Q2_step(void);
extern void HW3_Q2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HW3_Q2_T *const HW3_Q2_M;
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
 * '<Root>' : 'HW3_Q2'
 * '<S1>'   : 'HW3_Q2/A'
 */
#endif                                 /* RTW_HEADER_HW3_Q2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
