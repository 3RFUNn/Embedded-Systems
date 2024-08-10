/*
 * File: master_chart.h
 *
 * Code generated for Simulink model 'master_chart'.
 *
 * Model version                  : 5.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jul  1 03:15:23 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_master_chart_h_
#define RTW_HEADER_master_chart_h_
#ifndef master_chart_COMMON_INCLUDES_
#define master_chart_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* master_chart_COMMON_INCLUDES_ */

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

#define master_chart_M                 (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_MasterCommand_
#define DEFINED_TYPEDEF_FOR_MasterCommand_

typedef enum {
    MASTER_IDLE = 0,                   /* Default value */
    MASTER_PUT,
    MASTER_READ
} MasterCommand;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Operation_
#define DEFINED_TYPEDEF_FOR_Operation_

typedef enum {
    OPERATION_READ = 1,                /* Default value */
    OPERATION_WRITE = 0
} Operation;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Log_
#define DEFINED_TYPEDEF_FOR_Log_

typedef enum {
    LOG_NOTHING = 0,                   /* Default value */
    LOG_SEND,
    LOG_RECEIVE,
    LOG_REPLY,
    LOG_BUTTON_PRESSED,
    LOG_RETRIEVE_STATE
} Log;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
    uint8_T button_old[8];             /* '<Root>/master_chart' */
    uint8_T is_active_c2_master_chart; /* '<Root>/master_chart' */
    uint8_T is_c2_master_chart;        /* '<Root>/master_chart' */
    uint8_T idle_clocks;               /* '<Root>/master_chart' */
    uint8_T phy_addr;                  /* '<Root>/master_chart' */
    uint8_T reg_addr;                  /* '<Root>/master_chart' */
    uint8_T retrieve_timeout;          /* '<Root>/master_chart' */
    uint8_T last_selected_device;      /* '<Root>/master_chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
    uint8_T received_data;             /* '<Root>/received_data' */
    boolean_T data_available;          /* '<Root>/data_available' */
    uint8_T selected_device;           /* '<Root>/selected_device' */
    uint8_T button[8];                 /* '<Root>/button' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
    MasterCommand command;             /* '<Root>/command' */
    Operation register_operation;      /* '<Root>/register_operation' */
    uint8_T put_data;                  /* '<Root>/put_data' */
    Log log_type;                      /* '<Root>/log_type' */
    uint8_T log_data[3];               /* '<Root>/log_data' */
    uint8_T leds[8];                   /* '<Root>/leds' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
    const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void master_chart_initialize(void);
extern void master_chart_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('controllers/master/master_chart')    - opens subsystem controllers/master/master_chart
 * hilite_system('controllers/master/master_chart/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controllers/master'
 * '<S1>'   : 'controllers/master/master_chart'
 */
#endif                                 /* RTW_HEADER_master_chart_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
