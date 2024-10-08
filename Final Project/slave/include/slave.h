/*
 * File: slave.h
 *
 * Code generated for Simulink model 'slave'.
 *
 * Model version                  : 5.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jul  1 04:49:08 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_slave_h_
#define RTW_HEADER_slave_h_
#ifndef slave_COMMON_INCLUDES_
#define slave_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* slave_COMMON_INCLUDES_ */

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

#define slave_M                        (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_SlaveCommand_
#define DEFINED_TYPEDEF_FOR_SlaveCommand_

typedef enum {
    SLAVE_IDLE = 0,                    /* Default value */
    SLAVE_PUT,
    SLAVE_READ,
    SLAVE_IGNORE
} SlaveCommand;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Operation_
#define DEFINED_TYPEDEF_FOR_Operation_

typedef enum {
    OPERATION_READ = 1,                /* Default value */
    OPERATION_WRITE = 0
} Operation;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
    uint8_T button_old[8];             /* '<S1>/slave_chart' */
    uint8_T is_active_c1_slave;        /* '<S1>/slave_chart' */
    uint8_T is_c1_slave;               /* '<S1>/slave_chart' */
    uint8_T idle_clocks;               /* '<S1>/slave_chart' */
    boolean_T from_wait_bus;           /* '<S1>/slave_chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
    uint8_T received_data;             /* '<Root>/received_data' */
    boolean_T data_available;          /* '<Root>/data_available' */
    uint8_T physical_address;          /* '<Root>/physical_address' */
    uint8_T button[8];                 /* '<Root>/button' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
    Operation register_operation;      /* '<Root>/register_operation' */
    SlaveCommand command;              /* '<Root>/command' */
    uint8_T put_data;                  /* '<Root>/put_data' */
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
extern void slave_initialize(void);
extern void slave_step(void);

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
 * hilite_system('controllers/slave')    - opens subsystem controllers/slave
 * hilite_system('controllers/slave/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controllers'
 * '<S1>'   : 'controllers/slave'
 * '<S2>'   : 'controllers/slave/slave_chart'
 */
#endif                                 /* RTW_HEADER_slave_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
