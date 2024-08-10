#include <unity.h>

#ifndef RTWTYPES_H
#define RTWTYPES_H

/* Logical type definitions */
#if (!defined(__cplusplus))
#  ifndef false
#   define false                       (0U)
#  endif

#  ifndef true
#   define true                        (1U)
#  endif
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


#ifndef ZERO_CROSSING_TYPES_H
#define ZERO_CROSSING_TYPES_H

/* Trigger directions: falling, either, and rising */
typedef enum {
  FALLING_ZERO_CROSSING = -1,
  ANY_ZERO_CROSSING = 0,
  RISING_ZERO_CROSSING = 1
} ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define UNINITIALIZED_ZCSIG            0x03U
#define NEG_ZCSIG                      0x02U
#define POS_ZCSIG                      0x01U
#define ZERO_ZCSIG                     0x00U

/* Current state of a trigger signal */
typedef enum {
  FALLING_ZCEVENT = -1,
  NO_ZCEVENT = 0,
  RISING_ZCEVENT = 1
} ZCEventType;

#endif                                 /* ZERO_CROSSING_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/* Copyright 2002-2017 The MathWorks, Inc. */
/**
 *
 * Types and define related to zero crossing signals and events
 *
 */

/* Leading _ in header guards violates MISRA standard rule 21.1 */
#ifndef solver_zc_hpp_
#define solver_zc_hpp_

/* slZcSignalType ==============================================================
 *
 */
typedef enum {

    SL_ZCS_TYPE_CONT   = 0,
    SL_ZCS_TYPE_DISC   = 1,
    SL_ZCS_TYPE_HYBRID = 2

} slZcSignalType;


/* slZcEventType ===============================================================
 *
 *  zcEvents are bit packed as follows:
 *
 *   .-----.-----.-----.-----.-----.-----.-----.-----.
 *   |     |     | z2n | p2z | p2n | z2p | n2z | n2p |
 *   '-----'-----'-----'-----'-----'-----'-----'-----'
 *            ^  |<----------- eventTypes ---------->|
 *            |
 *            `--- needsSolverReset 
 *            
 */
typedef uint8_T slZcEventType;
#define SL_ZCS_EVENT_NUL  0x00U
#define SL_ZCS_EVENT_N2P  0x01U
#define SL_ZCS_EVENT_N2Z  0x02U
#define SL_ZCS_EVENT_Z2P  0x04U
#define SL_ZCS_EVENT_P2N  0x08U
#define SL_ZCS_EVENT_P2Z  0x10U
#define SL_ZCS_EVENT_Z2N  0x20U

#define SL_ZCS_EVENT_ALL_UP  ( SL_ZCS_EVENT_N2P | \
                               SL_ZCS_EVENT_N2Z | \
                               SL_ZCS_EVENT_Z2P )

#define SL_ZCS_EVENT_ALL_DN  ( SL_ZCS_EVENT_P2N | \
                               SL_ZCS_EVENT_P2Z | \
                               SL_ZCS_EVENT_Z2N )

#define SL_ZCS_EVENT_ALL     ( SL_ZCS_EVENT_ALL_UP | SL_ZCS_EVENT_ALL_DN )

#define slZcSignalGetNeedsSolverReset(a) \
        (((a) & 0x40) != 0x00)

#define slZcSignalSetNeedsSolverReset(a, v) \
    (a) = (v) ? ((a) | 0x40) : ((a) & 0xBF)


/* slZcSignalAttribType ========================================================
 *
 *  ZcSignal attributes are bit packed as follows:
 *
 *   .-----.-----.-----.-----.-----.-----.-----.-----.
 *   |     |     | z2n | p2z | p2n | z2p | n2z | n2p |
 *   '-----'-----'-----'-----'-----'-----'-----'-----'
 *      ^     ^  |<---- which events to look for --->|
 *      |     |
 *      |     `--- isDiscrete 
 *      |
 *      `--------- needsEventNotification
 */
typedef uint8_T slZcSignalAttribType;

#define slZcSignalGetEventDirections(a) \
        ((a) & 0x3F)

#define slZcSignalSetEventDirections(a, d) \
    (a) = (((a) & 0xC0) | (d))

#define slZcSignalGetIsDiscrete(a) \
        (((a) & 0x40) != 0x00)

#define slZcSignalSetIsDiscrete(a, v) \
    (a) = (v) ? ((a) | 0x40) : ((a) & 0xBF)

#define slZcSignalGetNeedsEventNotification(a) \
        (((a) & 0x80) != 0x00)

#define slZcSignalSetNeedsEventNotification(a, v) \
    (a) = (v) ? ((a) | 0x80) : ((a) & 0x7F)


/* slZcSignalSignType ==========================================================
 *
 */
typedef uint8_T slZcSignalSignType;
#define SL_ZCS_SIGN_ZERO      0x00U
#define SL_ZCS_SIGN_POS       0x01U
#define SL_ZCS_SIGN_NEG       0x02U
#define SL_ZCS_SIGN_UNKNOWN   0x03U

#endif /* _solver_zc_hpp_ */

/* eof */

#ifndef RTW_HEADER_rt_zcfcn_h_
#define RTW_HEADER_rt_zcfcn_h_
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);

#endif                                 /* RTW_HEADER_rt_zcfcn_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */



/* Detect zero crossings events. */
ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState* prevZc, real_T currValue)
{
  slZcEventType zcsDir;
  slZcEventType tempEv;
  ZCEventType zcEvent = NO_ZCEVENT;    /* assume */

  /* zcEvent matrix */
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  /* get prevZcEvent and prevZcSign from prevZc */
  slZcEventType prevEv = (slZcEventType)(((uint8_T)(*prevZc)) >> 2);
  slZcSignalSignType prevSign = (slZcSignalSignType)(((uint8_T)(*prevZc)) &
    (uint8_T)0x03);

  /* get current zcSignal sign from current zcSignal value */
  slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

  /* get current zcEvent based on prev and current zcSignal value */
  slZcEventType currEv = eventMatrix[prevSign][currSign];

  /* get slZcEventType from ZCDirection */
  switch (zcDir) {
   case ANY_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL;
    break;

   case FALLING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_DN;
    break;

   case RISING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_UP;
    break;

   default:
    zcsDir = SL_ZCS_EVENT_NUL;
    break;
  }

  /*had event, check if double zc happend remove double detection. */
  if (slZcHadEvent(currEv, zcsDir)) {
    currEv = (slZcEventType)(slZcUnAliasEvents(prevEv, currEv));
  } else {
    currEv = SL_ZCS_EVENT_NUL;
  }

  /* Update prevZc */
  tempEv = (slZcEventType)(currEv << 2);/* shift left by 2 bits */
  *prevZc = (ZCSigState)((currSign) | (tempEv));
  if ((currEv & SL_ZCS_EVENT_ALL_DN) != 0) {
    zcEvent = FALLING_ZCEVENT;
  } else if ((currEv & SL_ZCS_EVENT_ALL_UP) != 0) {
    zcEvent = RISING_ZCEVENT;
  } else {
    zcEvent = NO_ZCEVENT;
  }

  return zcEvent;
}                                      /* rt_ZCFcn */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 1
#include "arduinoAVRScheduler.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE Arduino Uno
#define MW_CONNECTIONINFO_SERIAL_IPADDRESS codertarget.arduinobase.registry.getLoopbackIP;
#define MW_CONNECTIONINFO_SERIAL_PORT 17725
#define MW_CONNECTIONINFO_SERIAL_VERBOSE 0
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Ethernet')
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_WIFI_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Wifi')
#define MW_CONNECTIONINFO_WIFI_PORT 17725
#define MW_CONNECTIONINFO_WIFI_VERBOSE 0
#define MW_CONNECTIONINFO_XCPONSERIAL_BAUDRATE codertarget.arduinobase.registry.getBaudRate
#define MW_CONNECTIONINFO_XCPONSERIAL_COMPORT codertarget.arduinobase.internal.getExternalModeMexArgs('Serial')
#define MW_CONNECTIONINFO_XCPONSERIAL_VERBOSE 0
#define MW_CONNECTIONINFO_XCPONTCPIP_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Ethernet')
#define MW_CONNECTIONINFO_XCPONTCPIP_PORT 17725
#define MW_CONNECTIONINFO_XCPONTCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_XCPONWIFI_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Wifi')
#define MW_CONNECTIONINFO_XCPONWIFI_PORT 17725
#define MW_CONNECTIONINFO_XCPONWIFI_VERBOSE 0
#define MW_EXTMODE_CONFIGURATION Serial
#define MW_EXTMODE_COMPORTBAUD 921600
#define MW_EXTMODE_SIGNALBUFFERSIZE 250.000000
#define MW_RTOS Baremetal
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_RUNTIME_DISABLEPARALLELBUILD 0
#define MW_RUNTIME_FORCEBUILDSTATICLIBRARY 0
#define MW_HOSTCOMPORT_SET_HOST_COM_PORT 0
#define MW_HOSTCOMPORT_COM_PORT_NUMBER 1
#define MW_SIMULINKIO_ENABLE_SIMULINKIO 1
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
#define MW_DATAVERSION 2016.02

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
#ifndef ZERO_CROSSING_TYPES_H
#define ZERO_CROSSING_TYPES_H

/* Trigger directions: falling, either, and rising */
typedef enum {
  FALLING_ZERO_CROSSING = -1,
  ANY_ZERO_CROSSING = 0,
  RISING_ZERO_CROSSING = 1
} ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define UNINITIALIZED_ZCSIG            0x03U
#define NEG_ZCSIG                      0x02U
#define POS_ZCSIG                      0x01U
#define ZERO_ZCSIG                     0x00U

/* Current state of a trigger signal */
typedef enum {
  FALLING_ZCEVENT = -1,
  NO_ZCEVENT = 0,
  RISING_ZCEVENT = 1
} ZCEventType;

#endif                                 /* ZERO_CROSSING_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/* Copyright 2002-2017 The MathWorks, Inc. */
/**
 *
 * Types and define related to zero crossing signals and events
 *
 */

/* Leading _ in header guards violates MISRA standard rule 21.1 */
#ifndef solver_zc_hpp_
#define solver_zc_hpp_

/* slZcSignalType ==============================================================
 *
 */
typedef enum {

    SL_ZCS_TYPE_CONT   = 0,
    SL_ZCS_TYPE_DISC   = 1,
    SL_ZCS_TYPE_HYBRID = 2

} slZcSignalType;



typedef uint8_T slZcEventType;
#define SL_ZCS_EVENT_NUL  0x00U
#define SL_ZCS_EVENT_N2P  0x01U
#define SL_ZCS_EVENT_N2Z  0x02U
#define SL_ZCS_EVENT_Z2P  0x04U
#define SL_ZCS_EVENT_P2N  0x08U
#define SL_ZCS_EVENT_P2Z  0x10U
#define SL_ZCS_EVENT_Z2N  0x20U

#define SL_ZCS_EVENT_ALL_UP  ( SL_ZCS_EVENT_N2P | \
                               SL_ZCS_EVENT_N2Z | \
                               SL_ZCS_EVENT_Z2P )

#define SL_ZCS_EVENT_ALL_DN  ( SL_ZCS_EVENT_P2N | \
                               SL_ZCS_EVENT_P2Z | \
                               SL_ZCS_EVENT_Z2N )

#define SL_ZCS_EVENT_ALL     ( SL_ZCS_EVENT_ALL_UP | SL_ZCS_EVENT_ALL_DN )

#define slZcSignalGetNeedsSolverReset(a) \
        (((a) & 0x40) != 0x00)

#define slZcSignalSetNeedsSolverReset(a, v) \
    (a) = (v) ? ((a) | 0x40) : ((a) & 0xBF)

typedef uint8_T slZcSignalAttribType;

#define slZcSignalGetEventDirections(a) \
        ((a) & 0x3F)

#define slZcSignalSetEventDirections(a, d) \
    (a) = (((a) & 0xC0) | (d))

#define slZcSignalGetIsDiscrete(a) \
        (((a) & 0x40) != 0x00)

#define slZcSignalSetIsDiscrete(a, v) \
    (a) = (v) ? ((a) | 0x40) : ((a) & 0xBF)

#define slZcSignalGetNeedsEventNotification(a) \
        (((a) & 0x80) != 0x00)

#define slZcSignalSetNeedsEventNotification(a, v) \
    (a) = (v) ? ((a) | 0x80) : ((a) & 0x7F)


typedef uint8_T slZcSignalSignType;
#define SL_ZCS_SIGN_ZERO      0x00U
#define SL_ZCS_SIGN_POS       0x01U
#define SL_ZCS_SIGN_NEG       0x02U
#define SL_ZCS_SIGN_UNKNOWN   0x03U

#endif 
#ifndef RTW_HEADER_rt_zcfcn_h_
#define RTW_HEADER_rt_zcfcn_h_
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);

#endif                                 /* RTW_HEADER_rt_zcfcn_h_ */

/*
 * File: HW3_Q2.h
 *
 * Code generated for Simulink model 'HW3_Q2'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jun 16 15:12:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */


#define RTW_HEADER_HW3_Q2_h_
#ifndef HW3_Q2_COMMON_INCLUDES_
#define HW3_Q2_COMMON_INCLUDES_


/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/System' */
  uint8_T is_active_init;              /* '<Root>/System' */
  uint8_T is_B;                        /* '<Root>/System' */
  uint8_T is_active_B;                 /* '<Root>/System' */
  uint8_T is_C;                        /* '<Root>/System' */
  uint8_T is_active_C;                 /* '<Root>/System' */
  uint8_T is_D;                        /* '<Root>/System' */
  uint8_T was_D;                       /* '<Root>/System' */
} DW_HW3_Q2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState System_Trig_ZCE[5];       /* '<Root>/System' */
} PrevZCX_HW3_Q2_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Input[5];                     /* '<Root>/Input' */
} ExtU_HW3_Q2_T;

/* Real-time Model Data Structure */
struct tag_RTM_HW3_Q2_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_HW3_Q2_T HW3_Q2_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_HW3_Q2_T HW3_Q2_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_HW3_Q2_T HW3_Q2_U;

/* Model entry point functions */
extern void HW3_Q2_initialize(void);
extern void HW3_Q2_step(void);
extern void HW3_Q2_terminate(void);

/* Real-time Model object */

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
 * '<S1>'   : 'HW3_Q2/System'
 */
#endif                                 /* RTW_HEADER_HW3_Q2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */


#ifndef RTW_HEADER_HW3_Q2_types_h_
#define RTW_HEADER_HW3_Q2_types_h_

/* Model Code Variants */

/* Forward declaration for rtModel */
typedef struct tag_RTM_HW3_Q2_T RT_MODEL_HW3_Q2_T;

#endif                                 /* RTW_HEADER_HW3_Q2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: HW3_Q2.h
 *
 * Code generated for Simulink model 'HW3_Q2'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jun 16 15:12:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */


#define RTW_HEADER_HW3_Q2_h_
#ifndef HW3_Q2_COMMON_INCLUDES_
#define HW3_Q2_COMMON_INCLUDES_


/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/System' */
  uint8_T is_active_init;              /* '<Root>/System' */
  uint8_T is_B;                        /* '<Root>/System' */
  uint8_T is_active_B;                 /* '<Root>/System' */
  uint8_T is_C;                        /* '<Root>/System' */
  uint8_T is_active_C;                 /* '<Root>/System' */
  uint8_T is_D;                        /* '<Root>/System' */
  uint8_T was_D;                       /* '<Root>/System' */
} DW_HW3_Q2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState System_Trig_ZCE[5];       /* '<Root>/System' */
} PrevZCX_HW3_Q2_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Input[5];                     /* '<Root>/Input' */
} ExtU_HW3_Q2_T;

/* Real-time Model Data Structure */
struct tag_RTM_HW3_Q2_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_HW3_Q2_T HW3_Q2_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_HW3_Q2_T HW3_Q2_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_HW3_Q2_T HW3_Q2_U;

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
 * '<S1>'   : 'HW3_Q2/System'
 */
#endif                                 /* RTW_HEADER_HW3_Q2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */


/*
 * File: HW3_Q2.c
 *
 * Code generated for Simulink model 'HW3_Q2'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jun 16 15:12:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/* Named constants for Chart: '<Root>/System' */
#define HW3_Q2_CALL_EVENT              (-1L)
#define HW3_Q2_IN_D                    ((uint8_T)1U)
#define HW3_Q2_IN_D1                   ((uint8_T)1U)
#define HW3_Q2_IN_D2                   ((uint8_T)2U)
#define HW3_Q2_IN_G                    ((uint8_T)2U)
#define HW3_Q2_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define HW3_Q2_IN_a1                   ((uint8_T)1U)
#define HW3_Q2_IN_a2                   ((uint8_T)2U)
#define HW3_Q2_event_a                 (1L)
#define HW3_Q2_event_b                 (2L)
#define HW3_Q2_event_c                 (0L)
#define HW3_Q2_event_d                 (4L)
#define HW3_Q2_event_e                 (3L)
#define HW3_Q2_event_init              (5L)

/* Block states (default storage) */
DW_HW3_Q2_T HW3_Q2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_HW3_Q2_T HW3_Q2_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_HW3_Q2_T HW3_Q2_U;

/* Real-time model */
static RT_MODEL_HW3_Q2_T HW3_Q2_M_;


/* Forward declaration for local functions */
static void HW3_Q2_c3_HW3_Q2(void);
static void HW3_Q2_chartstep_c3_HW3_Q2(void);

/* Function for Chart: '<Root>/System' */
static void HW3_Q2_c3_HW3_Q2(void)
{
  if (HW3_Q2_DW.is_active_B != 0U) {
    switch (HW3_Q2_DW.is_B) {
     case HW3_Q2_IN_a1:
      if (HW3_Q2_DW.sfEvent == HW3_Q2_event_c) {
        HW3_Q2_DW.is_B = HW3_Q2_IN_a2;
      }
      break;

     case HW3_Q2_IN_a2:
      if ((HW3_Q2_DW.sfEvent == HW3_Q2_event_b) && (HW3_Q2_DW.is_D ==
           HW3_Q2_IN_D2)) {
        HW3_Q2_DW.is_B = HW3_Q2_IN_a1;
      }
      break;
    }
  }

  if (HW3_Q2_DW.is_active_C != 0U) {
    switch (HW3_Q2_DW.is_C) {
     case HW3_Q2_IN_D:
      if (HW3_Q2_DW.sfEvent == HW3_Q2_event_d) {
        HW3_Q2_DW.is_D = HW3_Q2_IN_NO_ACTIVE_CHILD;
        HW3_Q2_DW.is_C = HW3_Q2_IN_G;
      } else {
        switch (HW3_Q2_DW.is_D) {
         case HW3_Q2_IN_D1:
          if (HW3_Q2_DW.sfEvent == HW3_Q2_event_e) {
            HW3_Q2_DW.is_D = HW3_Q2_IN_D2;
            HW3_Q2_DW.was_D = HW3_Q2_IN_D2;
          }
          break;

         case HW3_Q2_IN_D2:
          if (HW3_Q2_DW.sfEvent == HW3_Q2_event_e) {
            HW3_Q2_DW.is_D = HW3_Q2_IN_D2;
            HW3_Q2_DW.was_D = HW3_Q2_IN_D2;
          }
          break;
        }
      }
      break;

     case HW3_Q2_IN_G:
      if (HW3_Q2_DW.sfEvent == HW3_Q2_event_a) {
        HW3_Q2_DW.sfEvent = HW3_Q2_event_c;

        /* Chart: '<Root>/System' */
        HW3_Q2_c3_HW3_Q2();
        HW3_Q2_DW.sfEvent = 1L;
        if (HW3_Q2_DW.is_C == HW3_Q2_IN_G) {
          HW3_Q2_DW.is_C = HW3_Q2_IN_D;
          switch (HW3_Q2_DW.was_D) {
           case HW3_Q2_IN_D1:
            HW3_Q2_DW.is_D = HW3_Q2_IN_D1;
            HW3_Q2_DW.was_D = HW3_Q2_IN_D1;
            break;

           case HW3_Q2_IN_D2:
            HW3_Q2_DW.is_D = HW3_Q2_IN_D2;
            HW3_Q2_DW.was_D = HW3_Q2_IN_D2;
            break;

           default:
            HW3_Q2_DW.is_D = HW3_Q2_IN_D1;
            HW3_Q2_DW.was_D = HW3_Q2_IN_D1;
            break;
          }
        }
      }
      break;
    }
  }

  if ((HW3_Q2_DW.is_active_init != 0U) && (HW3_Q2_DW.sfEvent ==
       HW3_Q2_event_init)) {
    /* Chart: '<Root>/System' */
    HW3_Q2_DW.is_D = HW3_Q2_IN_NO_ACTIVE_CHILD;
    HW3_Q2_DW.is_active_B = 1U;
    HW3_Q2_DW.is_B = HW3_Q2_IN_a1;
    HW3_Q2_DW.is_active_C = 1U;
    HW3_Q2_DW.is_C = HW3_Q2_IN_G;
    HW3_Q2_DW.is_active_init = 1U;
  }
}

/* Function for Chart: '<Root>/System' */
static void HW3_Q2_chartstep_c3_HW3_Q2(void)
{
  HW3_Q2_c3_HW3_Q2();
}

/* Model step function */
void HW3_Q2_step(void)
{
  int16_T i;
  int8_T rtb_inputevents[5];
  boolean_T zcEvent_0;
  ZCEventType zcEvent[5];

  /* Chart: '<Root>/System' incorporates:
   *  TriggerPort: '<S1>/input events'
   */
  for (i = 0; i < 5; i++) {
    /* Inport: '<Root>/Input' */
    zcEvent[i] = rt_ZCFcn(RISING_ZERO_CROSSING,&HW3_Q2_PrevZCX.System_Trig_ZCE[i],
                          (HW3_Q2_U.Input[i]));
  }

  zcEvent_0 = false;
  for (i = 0; i < 5; i++) {
    zcEvent_0 = (zcEvent_0 || (zcEvent[i] != NO_ZCEVENT));
  }

  if (zcEvent_0) {
    for (i = 0; i < 5; i++) {
      rtb_inputevents[i] = (int8_T)zcEvent[i];
    }

    if (rtb_inputevents[0UL] == 1) {
      HW3_Q2_DW.sfEvent = HW3_Q2_event_a;
      HW3_Q2_chartstep_c3_HW3_Q2();
    }

    if (rtb_inputevents[1UL] == 1) {
      HW3_Q2_DW.sfEvent = HW3_Q2_event_b;
      HW3_Q2_chartstep_c3_HW3_Q2();
    }

    if (rtb_inputevents[2UL] == 1) {
      HW3_Q2_DW.sfEvent = HW3_Q2_event_e;
      HW3_Q2_chartstep_c3_HW3_Q2();
    }

    if (rtb_inputevents[3UL] == 1) {
      HW3_Q2_DW.sfEvent = HW3_Q2_event_d;
      HW3_Q2_chartstep_c3_HW3_Q2();
    }

    if (rtb_inputevents[4UL] == 1) {
      HW3_Q2_DW.sfEvent = HW3_Q2_event_init;
      HW3_Q2_chartstep_c3_HW3_Q2();
    }
  }
}

/* Model initialize function */
void HW3_Q2_initialize(void)
{
  {
    int16_T i;
    for (i = 0; i < 5; i++) {
      HW3_Q2_PrevZCX.System_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }

    /* SystemInitialize for Chart: '<Root>/System' */
    HW3_Q2_DW.sfEvent = HW3_Q2_CALL_EVENT;

    /* Chart: '<Root>/System' */
    HW3_Q2_DW.is_active_B = 1U;
    HW3_Q2_DW.is_B = HW3_Q2_IN_a1;
    HW3_Q2_DW.is_active_C = 1U;
    HW3_Q2_DW.is_C = HW3_Q2_IN_G;
    HW3_Q2_DW.is_active_init = 1U;
  }
}

/* Model terminate function */
void HW3_Q2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
void setUp(void) {  
    // set stuff up here  
}  
  
void tearDown(void) {  
    // clean stuff up here  
}


void set_pulse_sequence(double a, double b, double e, double b2, double d,double b3, double init) {
    HW3_Q2_U.Input[0UL] = a;
    HW3_Q2_U.Input[1UL] = b,b2,b3;
    HW3_Q2_U.Input[2UL] = e;
    HW3_Q2_U.Input[3UL] = d;
    HW3_Q2_U.Input[4UL] = init;
    
}

void HW3_Q2_active_test() {
    TEST_ASSERT_EQUAL(1U, HW3_Q2_DW.is_active_B);
    TEST_ASSERT_EQUAL(1U, HW3_Q2_DW.is_active_C);
    TEST_ASSERT_EQUAL(1U, HW3_Q2_DW.is_active_init);
}

void test_initial_state() {
     // Set pulse initial
    set_pulse_sequence(0, 0, 0, 0, 0, 0, 1);
    // Call the step function
    HW3_Q2_step();

    HW3_Q2_active_test();
     // Check the conditions for initial
    TEST_ASSERT_EQUAL(HW3_Q2_IN_a1, HW3_Q2_DW.is_B);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_G, HW3_Q2_DW.is_C);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_NO_ACTIVE_CHILD, HW3_Q2_DW.is_D);
    
}

void test_HW3_Q2_step_a(void) {
     // Set pulse a
    set_pulse_sequence(1, 0, 0, 0, 0, 0, 0);
    // Call the step function
    HW3_Q2_step();

    HW3_Q2_active_test();
     // Check the conditions for pulse a
    TEST_ASSERT_EQUAL(HW3_Q2_IN_a2, HW3_Q2_DW.is_B);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_D, HW3_Q2_DW.is_C);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_D1, HW3_Q2_DW.is_D);
    
}

void test_HW3_Q2_step_b(void) {
     // Set pulse b
    set_pulse_sequence(0, 1, 0, 0, 0, 0, 0);
    // Call the step function
    HW3_Q2_step();

    HW3_Q2_active_test();
     // Check the conditions for pulse b
    TEST_ASSERT_EQUAL(HW3_Q2_IN_a1, HW3_Q2_DW.is_B);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_D, HW3_Q2_DW.is_C);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_D2, HW3_Q2_DW.is_D);
    
}

void test_HW3_Q2_step_e(void) {
     // Set pulse e
    set_pulse_sequence(0, 0, 1, 0, 0, 0, 0);
    // Call the step function
    HW3_Q2_step();

    HW3_Q2_active_test();
   // Check the conditions for pulse e
    TEST_ASSERT_EQUAL(HW3_Q2_IN_a2, HW3_Q2_DW.is_B);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_D, HW3_Q2_DW.is_C);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_D2, HW3_Q2_DW.is_D);
    
}

void test_HW3_Q2_step_d(void) {
     // Set pulse e
    set_pulse_sequence(0, 0, 0, 0, 1, 0, 0);
    // Call the step function
    HW3_Q2_step();

    HW3_Q2_active_test();
     // Check the conditions for pulse d
    TEST_ASSERT_EQUAL(HW3_Q2_IN_a1, HW3_Q2_DW.is_B);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_G, HW3_Q2_DW.is_C);
    TEST_ASSERT_EQUAL(HW3_Q2_IN_NO_ACTIVE_CHILD, HW3_Q2_DW.is_D);

}

int main(int argc, char **argv) {
    HW3_Q2_initialize();

    UNITY_BEGIN();
    // Initial
    RUN_TEST(test_initial_state);
    // pulse a
    RUN_TEST(test_HW3_Q2_step_a);
    // pulse b (because no changes is still a)
    RUN_TEST(test_HW3_Q2_step_a);
    // pulse e
    RUN_TEST(test_HW3_Q2_step_e);
    // pulse b2
    RUN_TEST(test_HW3_Q2_step_b);
    //pulse d
    RUN_TEST(test_HW3_Q2_step_d);
    //pulse b3 (because no changes still d)
    RUN_TEST(test_HW3_Q2_step_d);

    UNITY_END();
}

