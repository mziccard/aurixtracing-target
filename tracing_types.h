/*
 * Copyright (c) 2015 Marco Ziccardi
 * Licensed under the MIT license.
 */

#ifndef TRACING_TYPES_H_
#define TRACING_TYPES_H_

#include <stdint.h>
#include "machine_headers.h"


typedef struct ipoint_time_t {
	unsigned int ipoint_id;
	unsigned long long timestamp;
} ipoint_time_t;

/**
 * Define whether the tracing process has
 * to fail if the trace reader is not fast enough
 */
#ifdef FAIL_ON_FULL_BUFFER
	#define FAIL_ON_FULL_BUFFER 0
#endif

/**
 * Size of the trace buffer
 */
#ifndef IPOINT_TRACE_BUFFER_SIZE
	#define IPOINT_TRACE_BUFFER_SIZE        1024
#endif

/**
 * Bit mask of the size of a tracebuffer
 */
#ifndef IPOINT_TRACE_BUFFER_BITMASK
	#define IPOINT_TRACE_BUFFER_BITMASK       (IPOINT_TRACE_BUFFER_SIZE-1)
#endif

typedef struct ipoint_buffer_t {
	uint16_t readIndex;
	uint16_t writeIndex;
	ipoint_time_t buffer[IPOINT_TRACE_BUFFER_SIZE];
} ipoint_buffer_t;

#endif /* TRACING_TYPES_H_ */

