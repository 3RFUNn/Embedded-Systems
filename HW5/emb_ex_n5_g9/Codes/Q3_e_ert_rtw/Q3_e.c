/*
 /*
 * File: rtwtypes.h
 *
 * Code generated for Simulink model 'Q3_e'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri May 12 03:42:56 2023
 */

#ifndef RTWTYPES_H
#define RTWTYPES_H

/* Logical type definitions */
#if (!defined(__cplusplus))
#ifndef false
#define false                          (0U)
#endif

#ifndef true
#define true                           (1U)
#endif
#endif

/*=======================================================================*
 * Target hardware information
 *   Device type: Atmel->AVR
 *   Number of bits:     char:   8    short:   16    int:  16
 *                       long:  32
 *                       native word size:   8
 *   Byte ordering: LittleEndian
 *   Signed integer division rounds to: Zero
 *   Shift right on a signed integer as arithmetic shift: on
 *=======================================================================*/

/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *   real32_T, real64_T           - 32 and 64 bit floating point numbers *
 *=======================================================================*/
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef int int16_T;
typedef unsigned int uint16_T;
typedef long int32_T;
typedef unsigned long uint32_T;
typedef float real32_T;
typedef double real64_T;

/*===========================================================================*
 * Generic type definitions: boolean_T, char_T, byte_T, int_T, uint_T,       *
 *                           real_T, time_T, ulong_T.                        *
 *===========================================================================*/
typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

/*===========================================================================*
 * Complex number type definitions                                           *
 *===========================================================================*/
#define CREAL_T

typedef struct {
  real32_T re;
  real32_T im;
} creal32_T;

typedef struct {
  real64_T re;
  real64_T im;
} creal64_T;

typedef struct {
  real_T re;
  real_T im;
} creal_T;

#define CINT8_T

typedef struct {
  int8_T re;
  int8_T im;
} cint8_T;

#define CUINT8_T

typedef struct {
  uint8_T re;
  uint8_T im;
} cuint8_T;

#define CINT16_T

typedef struct {
  int16_T re;
  int16_T im;
} cint16_T;

#define CUINT16_T

typedef struct {
  uint16_T re;
  uint16_T im;
} cuint16_T;

#define CINT32_T

typedef struct {
  int32_T re;
  int32_T im;
} cint32_T;

#define CUINT32_T

typedef struct {
  uint32_T re;
  uint32_T im;
} cuint32_T;

/*=======================================================================*
 * Min and Max:                                                          *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255U))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535U))
#define MAX_int32_T                    ((int32_T)(2147483647L))
#define MIN_int32_T                    ((int32_T)(-2147483647L-1L))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFUL))

/* Block D-Work pointer type */
typedef void * pointer_T;

#endif                                 /* RTWTYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
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
#endif                                 /* Q3_e_COMMON_INCLUDES_ */

/* Model Code Variants */
#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 1
#include "arduinoAVRScheduler.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE Arduino Uno
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_HOSTINTERFACE Simulink
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERAUTO 1
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERSIZE 250
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERNUM 2
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_MAXCONTIGSAMPLES 10
#define MW_EXTMODEPROTOCOLINFO_XCPONTCPIP_HOSTINTERFACE Simulink
#define MW_EXTMODEPROTOCOLINFO_XCPONTCPIP_LOGGINGBUFFERAUTO 1
#define MW_EXTMODEPROTOCOLINFO_XCPONTCPIP_LOGGINGBUFFERSIZE 250
#define MW_EXTMODEPROTOCOLINFO_XCPONTCPIP_LOGGINGBUFFERNUM 2
#define MW_EXTMODEPROTOCOLINFO_XCPONTCPIP_MAXCONTIGSAMPLES 10
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_HOSTINTERFACE Simulink
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_LOGGINGBUFFERAUTO 1
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_LOGGINGBUFFERSIZE 250
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_LOGGINGBUFFERNUM 2
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_MAXCONTIGSAMPLES 10
#define MW_CONNECTIONINFO_XCPONSERIAL_BAUDRATE codertarget.arduinobase.registry.getBaudRate
#define MW_CONNECTIONINFO_XCPONSERIAL_COMPORT codertarget.arduinobase.internal.getExternalModeMexArgs('Serial')
#define MW_CONNECTIONINFO_XCPONSERIAL_VERBOSE 0
#define MW_CONNECTIONINFO_XCPONTCPIP_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Ethernet')
#define MW_CONNECTIONINFO_XCPONTCPIP_PORT 17725
#define MW_CONNECTIONINFO_XCPONTCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_XCPONWIFI_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Wifi')
#define MW_CONNECTIONINFO_XCPONWIFI_PORT 17725
#define MW_CONNECTIONINFO_XCPONWIFI_VERBOSE 0
#define MW_CONNECTIONINFO_SERIAL_IPADDRESS codertarget.arduinobase.registry.getLoopbackIP;
#define MW_CONNECTIONINFO_SERIAL_PORT 17725
#define MW_CONNECTIONINFO_SERIAL_VERBOSE 0
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Ethernet')
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_WIFI_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Wifi')
#define MW_CONNECTIONINFO_WIFI_PORT 17725
#define MW_CONNECTIONINFO_WIFI_VERBOSE 0
#define MW_EXTMODE_CONFIGURATION XCP on Serial
#define MW_EXTMODE_COMPORTBAUD 115200
#define MW_RTOS Baremetal
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_RUNTIME_DISABLEPARALLELBUILD 0
#define MW_RUNTIME_FORCEBUILDSTATICLIBRARY 0
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_PORT_SOURCE 0
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_COMPORT_SELECT -1
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_COMPORT_SPECIFY 1
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_BAUD 0
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_BAUD_SPECIFY 9600
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_SERIAL_PORT 0
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_PORT_SOURCE1 0
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_PORT_SOURCE2 0
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_COMPORT_SELECT -1
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_COMPORT_SPECIFY 1
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_BAUD 0
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_BAUD_SPECIFY 9600
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_SERIAL_PORT 0
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_PORT_SOURCE1 0
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_PORT_SOURCE2 0
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_COMPORT_SELECT -1
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_COMPORT_SPECIFY 1
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_BAUD -1
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_BAUD_SPECIFY 9600
#define MW_HOSTBOARDCONNECTION_PIL_SERIAL_PORT 0
#define MW_HOSTBOARDCONNECTION_PIL_PORT_SOURCE1 0
#define MW_HOSTBOARDCONNECTION_PIL_PORT_SOURCE2 0
#define MW_HOSTBOARDCONNECTION_PIL_COMPORT_SELECT -1
#define MW_HOSTBOARDCONNECTION_PIL_COMPORT_SPECIFY 1
#define MW_HOSTBOARDCONNECTION_PIL_BAUD 0
#define MW_HOSTBOARDCONNECTION_PIL_BAUD_SPECIFY 9600
#define MW_CONNECTEDIO_CONNECTEDIOMODE 0
#define MW_CONNECTEDIO_ACTIONONOVERRUN 0
#define MW_OVERRUNDETECTION_ENABLE_OVERRUN_DETECTION 0
#define MW_OVERRUNDETECTION_DIGITAL_OUTPUT_TO_SET_ON_OVERRUN 13
#define MW_ANALOGINREFVOLTAGE_ANALOG_INPUT_REFERENCE_VOLTAGE 0.000000
#define MW_SERIAL_SERIAL0_BAUD_RATE 3
#define MW_I2C_I2C0BUSSPEEDHZ 100000
#define MW_SPI_SPI_CLOCK_OUT_FREQUENCY 1
#define MW_SPI_SPI_MODE 0
#define MW_SPI_SPI_BITORDER 0
#define MW_SPI_SDSLAVESELECT 4.000000
#define MW_SPI_CANCHIPSELECT 9.000000
#define MW_ETHERNET_DISABLE_DHCP_ETHERNET 0
#define MW_ETHERNET_LOCAL_IP_ADDRESS 192.168.0.20
#define MW_ETHERNET_LOCAL_MAC_ADDRESS DE:AD:BE:EF:FE:ED
#define MW_WIFI_WIFI_HARDWARE 0
#define MW_WIFI_DISABLE_DHCP_WIFI 0
#define MW_WIFI_WIFI_IP_ADDRESS 192.168.1.20
#define MW_WIFI_WIFI_SSID yourNetwork
#define MW_WIFI_SET_WIFI_ENCRYPTION 0
#define MW_WIFI_WIFI_WEP_KEY D0D0DEADF00DABBADEAFBEADED
#define MW_WIFI_WIFI_WEP_KEY_INDEX 0
#define MW_WIFI_WIFI_WPA_PASSWORD secretPassword
#define MW_WIFI_WIFI_ESP8266_HW_SERIAL_PORT 0
#define MW_THINGSPEAK_ENABLE_CUSTOMSERVER 48
#define MW_THINGSPEAK_IP_ADDRESS 184.106.153.149
#define MW_THINGSPEAK_PORT 80
#define MW_CAN_CANBUSSPEED 10
#define MW_CAN_CANOSCILLATORFREQUENCY 1
#define MW_CAN_INTERRUPTPIN 2.000000
#define MW_CAN_ALLOWALLFILTER 0
#define MW_CAN_BUFFER0IDTYPE 0
#define MW_CAN_ACCEPTANCEMASK0_NOR 0
#define MW_CAN_ACCEPTANCEFILTER0_NOR 255
#define MW_CAN_ACCEPTANCEFILTER1_NOR 255
#define MW_CAN_ACCEPTANCEMASK0_EXT 0
#define MW_CAN_ACCEPTANCEFILTER0_EXT 255
#define MW_CAN_ACCEPTANCEFILTER1_EXT 255
#define MW_CAN_BUFFER1IDTYPE 0
#define MW_CAN_ACCEPTANCEMASK1_NOR 0
#define MW_CAN_ACCEPTANCEFILTER2_NOR 255
#define MW_CAN_ACCEPTANCEFILTER3_NOR 255
#define MW_CAN_ACCEPTANCEFILTER4_NOR 255
#define MW_CAN_ACCEPTANCEFILTER5_NOR 255
#define MW_CAN_ACCEPTANCEMASK1_EXT 0
#define MW_CAN_ACCEPTANCEFILTER2_EXT 255
#define MW_CAN_ACCEPTANCEFILTER3_EXT 255
#define MW_CAN_ACCEPTANCEFILTER4_EXT 255
#define MW_CAN_ACCEPTANCEFILTER5_EXT 255
#define MW_MODBUS_MODBUS_COMMS 0
#define MW_MODBUS_MODBUS_MODE 0
#define MW_MODBUS_MODBUS_SLAVEID 1
#define MW_MODBUS_MODBUS_CONFIGCOIL 49
#define MW_MODBUS_MODBUS_COILADDR 0
#define MW_MODBUS_MODBUS_COILNUM 1
#define MW_MODBUS_MODBUS_CONFIGINPUT 49
#define MW_MODBUS_MODBUS_INPUTADDR 0
#define MW_MODBUS_MODBUS_INPUTNUM 1
#define MW_MODBUS_MODBUS_CONFIGHOLDINGREG 49
#define MW_MODBUS_MODBUS_HOLDINGREGADDR 0
#define MW_MODBUS_MODBUS_HOLDINGREGNUM 1
#define MW_MODBUS_MODBUS_CONFIGINPUTREG 49
#define MW_MODBUS_MODBUS_INPUTREGADDR 0
#define MW_MODBUS_MODBUS_INPUTREGNUM 1
#define MW_MODBUS_MODBUS_MASTERTIMEOUT 100
#define MW_RS485_RS485_SERIAL 0
#define MW_RS485_RS485_BAUD 9600
#define MW_RS485_RS485_CONFIG 3
#define MW_RS485_RS485_DEPIN 8
#define MW_RS485_RS485_REPIN 9
#define MW_DISPLAY_ENABLECODEGEN 0
#define MW_DISPLAY_APPLAUNCHBUTTON 
#define MW_DATAVERSION 2016.02
#define MW_DASHBOARDCODEGENINFO_ENABLECODEGEN 0
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_BLOCKCLASS codertarget.targetHiddenBlkInsert.internal.circularGauge
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_REGFCN codertarget.arduinobase.blocks.registerDashboardBlk
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_BLOCKCLASS codertarget.targetHiddenBlkInsert.internal.lcdTextDisplay
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_REGFCN codertarget.arduinobase.blocks.registerDashboardBlk
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_BLOCKCLASS codertarget.targetHiddenBlkInsert.internal.pushButton
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_REGFCN codertarget.arduinobase.blocks.registerDashboardBlk
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_IOBLOCKSMODE deployed

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif


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


/* Named constants for Chart: '<Root>/Chart' */
#define IN_Backward_Moving             ((uint8_T)1U)
#define IN_Forward_Moving              ((uint8_T)2U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Q3_e_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/dist'
   *  Inport: '<Root>/ppm'
   */
  if (rtDW.is_active_c3_Q3_e == 0U) {
    rtDW.is_active_c3_Q3_e = 1U;

    /* Outport: '<Root>/forward' */
    rtY.forward = 1.0;

    /* Outport: '<Root>/fan' incorporates:
     *  Inport: '<Root>/ppm'
     */
    rtY.fan = rtU.ppm;
    rtDW.is_c3_Q3_e = IN_Forward_Moving;
  } else if (rtDW.is_c3_Q3_e == IN_Backward_Moving) {
    if ((rtU.ppm < 50.0) && (rtU.dist.re > 100.0)) {
      /* Outport: '<Root>/forward' */
      rtY.forward = 1.0;

      /* Outport: '<Root>/fan' */
      rtY.fan = rtU.ppm;
      rtDW.is_c3_Q3_e = IN_Forward_Moving;
    } else if ((rtU.ppm > 50.0) || (rtU.dist.re < 100.0)) {
      /* Outport: '<Root>/forward' */
      rtY.forward = -1.0;

      /* Outport: '<Root>/fan' */
      rtY.fan = 0.0;
      rtDW.distance--;
    }

    /* case IN_Forward_Moving: */
  } else if ((rtU.ppm < 50.0) && (rtU.dist.re > 100.0)) {
    /* Outport: '<Root>/forward' */
    rtY.forward = 1.0;

    /* Outport: '<Root>/fan' */
    rtY.fan = rtU.ppm / 4.0;
    rtDW.distance++;
    rtDW.is_c3_Q3_e = IN_Forward_Moving;
  } else if ((rtU.ppm > 50.0) || (rtU.dist.re < 100.0)) {
    /* Outport: '<Root>/forward' */
    rtY.forward = -1.0;

    /* Outport: '<Root>/fan' */
    rtY.fan = 0.0;
    rtDW.is_c3_Q3_e = IN_Backward_Moving;
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Q3_e_initialize(void)
{
  /* SystemInitialize for Chart: '<Root>/Chart' */
  rtDW.distance = 1.0;
}

/* Model terminate function */
void Q3_e_terminate(void)
{
  /* (no terminate code required) */
}
void loop()
{

}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
