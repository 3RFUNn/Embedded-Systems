/*
 * File: ert_main.c
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

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
    /* Check for overrun. Protect OverrunFlag against preemption */
    if (OverrunFlag++) {
        IsrOverrun = 1;
        OverrunFlag--;
        return;
    }

#ifndef _MW_ARDUINO_LOOP_

    sei();

#endif;

    master_step();

    /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

    cli();

#endif;

    OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
    float modelBaseRate = 1.0;
    float systemClock = 0;

    /* Initialize variables */
    stopRequested = false;
    runModel = false;
    init();
    MW_Arduino_Init();
    rtmSetErrorStatus(rtM, 0);
    master_initialize();
    cli();
    configureArduinoAVRTimer();
    runModel = rtmGetErrorStatus(rtM) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

    sei();

#endif;

    sei();
    while (runModel) {
        stopRequested = !(rtmGetErrorStatus(rtM) == (NULL));
        runModel = !(stopRequested);
        MW_Arduino_Loop();
    }

    cli();
    return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
