/*
 * Copyright (c) 2015 Marco Ziccardi
 * Licensed under the MIT license.
 */

#ifndef TRACING_H_
#define TRACING_H_

#include "tracing_types.h"

/**
 * Cycle counter control register address
 */
#define CCTRL 0xfc00

/**
 * Cycle counter register address
 */
#define CCNT 0xfc04

/**
 * MACRO to enable the cycle counter
 */
#define ENABLE_CYCLE_COUNTER __mtcr( CCTRL, 0x00000002)

/**
 * MACRO to read the cycle counter
 */
#define READ_CYCLE_COUNTER (__mfcr( CCNT ) & 0xffffffff);

/**
 * Traces buffer
 */
extern volatile ipoint_buffer_t Trace_Buffer;

/**
 * Pointer to the system clock for core i
 */
extern volatile Ifx_STM * const stm;

/**
 * MACRO to get a timestamp
 * if TRACE_CYCLE_COUNTER is set we read it from the local cycle counter
 * otherwhise it is read from the STM
 */
#ifdef TRACE_CYCLE_COUNTER
	#define GET_TIMESTAMP READ_CYCLE_COUNTER
#else
	#define GET_TIMESTAMP stm->TIM0.U
#endif

#define IPOINT(IPOINT_ID) \
  Trace_Buffer.buffer[Trace_Buffer.writeIndex].ipoint_id = IPOINT_ID; \
  Trace_Buffer.buffer[Trace_Buffer.writeIndex].timestamp = GET_TIMESTAMP; \
  Trace_Buffer.writeIndex = (Trace_Buffer.writeIndex + 1) & IPOINT_TRACE_BUFFER_BITMASK;

#endif /* TRACING_H_ */
