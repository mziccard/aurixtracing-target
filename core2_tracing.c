/*
 * Copyright (c) 2015 Marco Ziccardi
 * Licensed under the MIT license.
 */

#include "tracing_types.h"
#include "machine_headers.h"


/**
 * Pointer to the system clock for core 2
 */
volatile Ifx_STM * const stm  = (Ifx_STM *)&MODULE_STM2;


/**
 *Trace buffer
 */
volatile ipoint_buffer_t Trace_Buffer __attribute__ ((section (".TRACE_BUFFER"))) = { 0, 0, {{0,0}} };


