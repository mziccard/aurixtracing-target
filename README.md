# On-Target Aurix Tracing
Application source code and header files for on-core time-tracing of the Aurix TriCore.

# Introduction 
This library can be used, if compiled with an Aurix Tricore application, to 
trace the application's execution time at specified points in the 
program. Timestamps are saved with an ID inside a buffer in the scratchpad 
memory of the core running the application.

## Time Sources
The Aurix TC26x, TC27x and TC29x processors are equipped with both a
system timer (STM) and a cycle counter (CCNT) for each core. CCNT and
STM work at different (configurable) frequencies.
Each time source has its own PROs:

### STM
-   Same time source for all cores, timestamps can be compared

### CCNT
-   Finer granularity

-   Faster access

-   No contention on the peripheral bus

STM is not only slower (as it is connected to the SPB peripheral bus)
but may also be cause of interference in case multiple cores access the
STM at the same time.

## On-core Tracing
Separate trace buffers are provided for each core, stored in the core's data scratchpad (DSPM). This draws several benefits when compared to off-core storage:

- Faster write accesses: DSPM is local so no bus arbitration

- No race conditions: each core has its own data structure 

- No need for storing the core ID


# Usage 

## coreX_tracing.c

Both CCNT and STM are memory mapped. CCNT is accessible at the same address on every 
core while STM provides different addresses for different cores in order to reduce 
interference. Three source files (`coreX_tracing.c`) are provided that have to be compiled with the application depending on which core it is going to run on.

Traces are stored in a buffer (`Trace_Buffer`) as pairs `(ipoint_id, timestamp)`. By default, `Trace_Buffer` holds 1024 of such pairs. The size of the trace
buffer can be configured by defining the macro
`IPOINT_TRACE_ BUFFER_SIZE`. `IPOINT_TRACE_ BUFFER_SIZE` is required to
be a power of 2.

`Trace_Buffer` is put into the `.TRACE_BUFFER` section that has to be
defined in the linker script. If the HighTech toolchain is being used
the following section definition has to be included at the very
beginning of the *SECTIONS* part of the linker script. 

```
.TRACE_BUFFER : { 
 *(.TRACE_BUFFER .TRACE_BUFFER.*) 
} > DMI_DSPR
```

## tracing.h

By default timestamps are captured from the STM clock. To use CCNT, instead, 
the macro `TRACE_CYCLE_COUNTER` can be defined before including `tracing.h`.
In order to use the core cycle counter, before
accessing the tracing capabilites CCNT has to be enabled on each core.
To that extent `tracing.h` provides the macro `ENABLE_CYCLE_COUNTER`. 

A macro `IPOINT` is available that stores in the trace buffer the specified
ipoint id and the current timestamp.

# Trace Extraction
To extract traces from the running target the host deamon available 
[here](https://github.com/mziccard/aurixtracing/tree/master) can be used. 
It supports trace extraction via the DAP miniWiggler v3. Otherwise, 
a debugger as Lauterbach's can be used.
