/*
 * File: controllers.h
 *
 * Code generated for Simulink model 'controllers'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jul  1 05:14:16 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controllers_h_
#define RTW_HEADER_controllers_h_
#ifndef controllers_COMMON_INCLUDES_
#define controllers_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* controllers_COMMON_INCLUDES_ */

#include <stddef.h>

/* Model Code Variants */
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define controllers_M                  (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
    uint8_T leds[8];                   /* '<S2>/slave_chart' */
    uint8_T leds_d[8];                 /* '<S1>/master_chart' */
    uint8_T button_old[8];             /* '<S2>/slave_chart' */
    uint8_T button_old_j[8];           /* '<S1>/master_chart' */
    uint8_T is_active_c1_controllers;  /* '<S2>/slave_chart' */
    uint8_T is_c1_controllers;         /* '<S2>/slave_chart' */
    uint8_T idle_clocks;               /* '<S2>/slave_chart' */
    uint8_T is_active_c2_controllers;  /* '<S1>/master_chart' */
    uint8_T is_c2_controllers;         /* '<S1>/master_chart' */
    uint8_T idle_clocks_d;             /* '<S1>/master_chart' */
    uint8_T reg_addr;                  /* '<S1>/master_chart' */
    uint8_T retrieve_timeout;          /* '<S1>/master_chart' */
    uint8_T last_selected_device;      /* '<S1>/master_chart' */
    boolean_T from_wait_bus;           /* '<S2>/slave_chart' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
    const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void controllers_initialize(void);
extern void controllers_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/master_scopes' : Unused code path elimination
 * Block '<Root>/slave_scopes' : Unused code path elimination
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
 * '<Root>' : 'controllers'
 * '<S1>'   : 'controllers/master'
 * '<S2>'   : 'controllers/slave'
 * '<S3>'   : 'controllers/master/master_chart'
 * '<S4>'   : 'controllers/slave/slave_chart'
 */
#endif                                 /* RTW_HEADER_controllers_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
