/*
 * File: controllers.c
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

#include "controllers.h"
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

/* Named constants for Chart: '<S2>/slave_chart' */
#define IN_read_register_address       ((uint8_T)5U)
#define IN_startup_b                   ((uint8_T)6U)
#define IN_update_leds_d               ((uint8_T)7U)
#define IN_wait_bus_idle_a             ((uint8_T)8U)

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static uint8_T button_pressed(const uint8_T old_state[8], const uint8_T
    current_state[8]);

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

/* Model step function */
void controllers_step(void)
{
    int16_T i;
    uint8_T rtb_TmpSignalConversionAtSFunct[8];

    /* Chart: '<S1>/master_chart' incorporates:
     *  SignalConversion generated from: '<S3>/ SFunction '
     */
    if (rtDW.is_active_c2_controllers == 0U) {
        rtDW.is_active_c2_controllers = 1U;
        rtDW.reg_addr = 128U;
        for (i = 0; i < 8; i++) {
            rtDW.leds_d[i] = 0U;
            rtDW.button_old_j[i] = 0U;
        }

        rtDW.is_c2_controllers = IN_startup;
    } else {
        switch (rtDW.is_c2_controllers) {
          case IN_bus_idle:
            if (((rtDW.retrieve_timeout == 0) | (rtDW.last_selected_device != 0))
                != 0) {
                rtDW.reg_addr = 128U;
                rtDW.is_c2_controllers = IN_retrieve_leds;
            } else {
                /* SignalConversion generated from: '<S3>/ SFunction ' */
                for (i = 0; i < 8; i++) {
                    rtb_TmpSignalConversionAtSFunct[i] = 0U;
                }

                if (button_pressed(rtDW.button_old_j,
                                   rtb_TmpSignalConversionAtSFunct) != sizeof
                        (uint8_T [8])) {
                    for (i = 0; i < 8; i++) {
                        rtDW.leds_d[i] ^= rtDW.button_old_j[i];
                        rtDW.button_old_j[i] = 0U;
                    }

                    rtDW.reg_addr = 0U;
                    rtDW.is_c2_controllers = IN_update_leds;
                } else if (rtDW.retrieve_timeout > 0) {
                    rtDW.retrieve_timeout--;
                    rtDW.is_c2_controllers = IN_bus_idle;
                }
            }
            break;

          case IN_process_data:
            rtDW.idle_clocks_d = 0U;
            rtDW.is_c2_controllers = IN_wait_bus_idle;
            break;

          case IN_put_data:
            rtDW.idle_clocks_d = 0U;
            rtDW.is_c2_controllers = IN_wait_bus_idle;
            break;

          case IN_read_data:
            break;

          case IN_retrieve_leds:
            rtDW.is_c2_controllers = IN_send_physical_address;
            break;

          case IN_send_physical_address:
            rtDW.is_c2_controllers = IN_send_register_address;
            break;

          case IN_send_register_address:
            switch (rtDW.reg_addr) {
              case 0:
                rtDW.is_c2_controllers = IN_put_data;
                break;

              case 128:
                rtDW.is_c2_controllers = IN_read_data;
                break;
            }
            break;

          case IN_startup:
            rtDW.is_c2_controllers = IN_send_physical_address;
            break;

          case IN_update_leds:
            rtDW.is_c2_controllers = IN_send_physical_address;
            break;

          default:
            /* case IN_wait_bus_idle: */
            if (rtDW.idle_clocks_d >= 5) {
                rtDW.retrieve_timeout = 50U;
                for (i = 0; i < 8; i++) {
                    rtDW.button_old_j[i] = 0U;
                }

                rtDW.last_selected_device = 0U;
                rtDW.is_c2_controllers = IN_bus_idle;
            } else {
                rtDW.idle_clocks_d++;
            }
            break;
        }
    }

    /* End of Chart: '<S1>/master_chart' */
    for (i = 0; i < 8; i++) {
        /* SignalConversion generated from: '<S4>/ SFunction ' incorporates:
         *  Chart: '<S2>/slave_chart'
         */
        rtb_TmpSignalConversionAtSFunct[i] = 0U;
    }

    /* Chart: '<S2>/slave_chart' incorporates:
     *  SignalConversion generated from: '<S4>/ SFunction '
     */
    if (rtDW.is_active_c1_controllers == 0U) {
        rtDW.is_active_c1_controllers = 1U;
        for (i = 0; i < 8; i++) {
            rtDW.leds[i] = 0U;
            rtDW.button_old[i] = 0U;
        }

        rtDW.is_c1_controllers = IN_startup_b;
    } else {
        switch (rtDW.is_c1_controllers) {
          case IN_bus_idle:
            if (button_pressed(rtDW.button_old, rtb_TmpSignalConversionAtSFunct)
                != sizeof(uint8_T [8])) {
                rtDW.from_wait_bus = false;
                for (i = 0; i < 8; i++) {
                    rtDW.leds[i] ^= rtDW.button_old[i];
                    rtDW.button_old[i] = 0U;
                }

                rtDW.is_c1_controllers = IN_update_leds_d;
            } else {
                for (i = 0; i < 8; i++) {
                    rtDW.button_old[i] = 0U;
                }
            }
            break;

          case IN_process_data:
            rtDW.is_c1_controllers = IN_bus_idle;
            break;

          case IN_put_data:
            rtDW.is_c1_controllers = IN_bus_idle;
            break;

          case IN_read_data:
          case IN_read_register_address:
            break;

          case IN_startup_b:
            rtDW.is_c1_controllers = IN_bus_idle;
            break;

          case IN_update_leds_d:
            if (button_pressed(rtDW.button_old, rtb_TmpSignalConversionAtSFunct)
                != sizeof(uint8_T [8])) {
                rtDW.is_c1_controllers = IN_update_leds_d;
            } else if (!rtDW.from_wait_bus) {
                rtDW.is_c1_controllers = IN_bus_idle;
            } else {
                for (i = 0; i < 8; i++) {
                    rtDW.button_old[i] = 0U;
                }

                rtDW.idle_clocks = 0U;
                rtDW.is_c1_controllers = IN_wait_bus_idle_a;
            }
            break;

          case IN_wait_bus_idle_a:
            if (rtDW.idle_clocks >= 3) {
                rtDW.is_c1_controllers = IN_bus_idle;
            } else if (button_pressed(rtDW.button_old,
                                      rtb_TmpSignalConversionAtSFunct) != sizeof
                       (uint8_T [8])) {
                rtDW.from_wait_bus = true;
                for (i = 0; i < 8; i++) {
                    rtDW.leds[i] ^= rtDW.button_old[i];
                    rtDW.button_old[i] = 0U;
                }

                rtDW.is_c1_controllers = IN_update_leds_d;
            } else {
                rtDW.idle_clocks++;
            }
            break;

          default:
            /* case IN_wait_for_master: */
            rtDW.is_c1_controllers = IN_read_data;
            break;
        }
    }
}

/* Model initialize function */
void controllers_initialize(void)
{
    /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
