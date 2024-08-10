/*
 * File: master.c
 *
 * Code generated for Simulink model 'master'.
 *
 * Model version                  : 5.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jul  1 03:43:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "master.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<S1>/master_chart' */
#define IN_bus_idle                    ((uint8_T)1U)
#define IN_process_data                ((uint8_T)2U)
#define IN_put_data                    ((uint8_T)3U)
#define IN_read_data                   ((uint8_T)4U)
#define IN_retrieve_leds               ((uint8_T)5U)
#define IN_send_physical_address       ((uint8_T)6U)
#define IN_send_register_address       ((uint8_T)7U)
#define IN_startup                     ((uint8_T)8U)
#define IN_update_leds                 ((uint8_T)9U)
#define IN_wait_bus_idle               ((uint8_T)10U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static uint8_T button_pressed(const uint8_T old_state[8], const uint8_T
    current_state[8]);
static void extract_bits(uint8_T data, uint8_T results[8]);
static uint8_T combine_bits(const uint8_T bits[8]);

/* Function for Chart: '<S1>/master_chart' */
static uint8_T button_pressed(const uint8_T old_state[8], const uint8_T
    current_state[8])
{
    uint8_T result;
    result = 0U;
    while ((result < sizeof(uint8_T [8])) && (!((old_state[result] == 0) &&
             (current_state[result] == 1)))) {
        /* NEW_PATTERN */
        result++;
    }

    return result;
}

/* Function for Chart: '<S1>/master_chart' */
static void extract_bits(uint8_T data, uint8_T results[8])
{
    int16_T i_0;
    uint8_T i;
    for (i_0 = 0; i_0 < 8; i_0++) {
        results[i_0] = 0U;
    }

    for (i = 0U; i < sizeof(uint8_T [8]); i++) {
        /* NEW_PATTERN */
        results[i] = (uint8_T)(data & 0x1);
        data >>= 1;
    }
}

/* Function for Chart: '<S1>/master_chart' */
static uint8_T combine_bits(const uint8_T bits[8])
{
    uint8_T i;
    uint8_T output;
    i = 0U;
    output = 0U;
    while (i < sizeof(uint8_T [8])) {
        /* NEW_PATTERN */
        output = (uint8_T)(bits[i] << i | output);
        i++;
    }

    return output;
}

/* Model step function */
void master_step(void)
{
    int16_T i;

    /* Chart: '<S1>/master_chart' incorporates:
     *  Inport: '<Root>/button'
     *  Inport: '<Root>/data_available'
     *  Inport: '<Root>/received_data'
     *  Inport: '<Root>/selected_device'
     *  Outport: '<Root>/leds'
     */
    if (rtDW.is_active_c2_master == 0U) {
        rtDW.is_active_c2_master = 1U;

        /* Outport: '<Root>/command' */
        rtY.command = MASTER_IDLE;
        rtDW.phy_addr = rtU.selected_device;
        rtDW.reg_addr = 128U;

        /* Outport: '<Root>/leds' incorporates:
         *  Inport: '<Root>/selected_device'
         */
        for (i = 0; i < 8; i++) {
            rtY.leds[i] = 0U;
            rtDW.button_old[i] = 0U;
        }

        rtDW.is_c2_master = IN_startup;
    } else {
        switch (rtDW.is_c2_master) {
          case IN_bus_idle:
            if (((rtDW.retrieve_timeout == 0) | (rtDW.last_selected_device !=
                    rtU.selected_device)) != 0) {
                /* Outport: '<Root>/command' */
                rtY.command = MASTER_IDLE;
                rtDW.phy_addr = rtU.selected_device;
                rtDW.reg_addr = 128U;
                rtDW.is_c2_master = IN_retrieve_leds;
            } else if (button_pressed(rtDW.button_old, rtU.button) != sizeof
                       (uint8_T [8])) {
                /* Outport: '<Root>/command' */
                rtY.command = MASTER_IDLE;

                /* Outport: '<Root>/leds' incorporates:
                 *  Inport: '<Root>/button'
                 */
                for (i = 0; i < 8; i++) {
                    rtY.leds[i] = (uint8_T)(rtU.button[i] ^ rtDW.button_old[i] ^
                                            rtY.leds[i]);
                    rtDW.button_old[i] = rtU.button[i];
                }

                rtDW.phy_addr = rtU.selected_device;
                rtDW.reg_addr = 0U;
                rtDW.is_c2_master = IN_update_leds;
            } else if (rtDW.retrieve_timeout > 0) {
                rtDW.retrieve_timeout--;
                rtDW.is_c2_master = IN_bus_idle;
            }
            break;

          case IN_process_data:
            /* Outport: '<Root>/command' */
            rtY.command = MASTER_IDLE;
            rtDW.idle_clocks = 0U;
            rtDW.is_c2_master = IN_wait_bus_idle;
            break;

          case IN_put_data:
            /* Outport: '<Root>/command' */
            rtY.command = MASTER_IDLE;
            rtDW.idle_clocks = 0U;
            rtDW.is_c2_master = IN_wait_bus_idle;
            break;

          case IN_read_data:
            if (rtU.data_available) {
                /* Outport: '<Root>/command' */
                rtY.command = MASTER_IDLE;
                extract_bits(rtU.received_data, rtY.leds);
                rtDW.is_c2_master = IN_process_data;
            }
            break;

          case IN_retrieve_leds:
            /* Outport: '<Root>/register_operation' */
            rtY.register_operation = OPERATION_WRITE;

            /* Outport: '<Root>/command' */
            rtY.command = MASTER_PUT;

            /* Outport: '<Root>/put_data' */
            rtY.put_data = rtDW.phy_addr;
            rtDW.is_c2_master = IN_send_physical_address;
            break;

          case IN_send_physical_address:
            /* Outport: '<Root>/register_operation' */
            rtY.register_operation = OPERATION_WRITE;

            /* Outport: '<Root>/command' */
            rtY.command = MASTER_PUT;

            /* Outport: '<Root>/put_data' */
            rtY.put_data = rtDW.reg_addr;
            rtDW.is_c2_master = IN_send_register_address;
            break;

          case IN_send_register_address:
            switch (rtDW.reg_addr) {
              case 0:
                /* Outport: '<Root>/register_operation' */
                rtY.register_operation = OPERATION_WRITE;

                /* Outport: '<Root>/command' */
                rtY.command = MASTER_PUT;

                /* Outport: '<Root>/put_data' incorporates:
                 *  Outport: '<Root>/leds'
                 */
                rtY.put_data = combine_bits(rtY.leds);
                rtDW.is_c2_master = IN_put_data;
                break;

              case 128:
                /* Outport: '<Root>/register_operation' */
                rtY.register_operation = OPERATION_READ;

                /* Outport: '<Root>/command' */
                rtY.command = MASTER_READ;
                rtDW.is_c2_master = IN_read_data;
                break;
            }
            break;

          case IN_startup:
            /* Outport: '<Root>/register_operation' */
            rtY.register_operation = OPERATION_WRITE;

            /* Outport: '<Root>/command' */
            rtY.command = MASTER_PUT;

            /* Outport: '<Root>/put_data' */
            rtY.put_data = rtDW.phy_addr;
            rtDW.is_c2_master = IN_send_physical_address;
            break;

          case IN_update_leds:
            /* Outport: '<Root>/register_operation' */
            rtY.register_operation = OPERATION_WRITE;

            /* Outport: '<Root>/command' */
            rtY.command = MASTER_PUT;

            /* Outport: '<Root>/put_data' */
            rtY.put_data = rtDW.phy_addr;
            rtDW.is_c2_master = IN_send_physical_address;
            break;

          default:
            /* case IN_wait_bus_idle: */
            if (rtDW.idle_clocks >= 5) {
                rtDW.retrieve_timeout = 50U;

                /* Outport: '<Root>/command' */
                rtY.command = MASTER_IDLE;
                for (i = 0; i < 8; i++) {
                    rtDW.button_old[i] = rtU.button[i];
                }

                rtDW.last_selected_device = rtU.selected_device;
                rtDW.is_c2_master = IN_bus_idle;
            } else {
                rtDW.idle_clocks++;
            }
            break;
        }
    }

    /* End of Chart: '<S1>/master_chart' */
}

/* Model initialize function */
void master_initialize(void)
{
    /* Registration code */

    /* external outputs */
    rtY.register_operation = OPERATION_READ;

    /* SystemInitialize for Outport: '<Root>/register_operation' incorporates:
     *  Chart: '<S1>/master_chart'
     */
    rtY.register_operation = OPERATION_READ;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
