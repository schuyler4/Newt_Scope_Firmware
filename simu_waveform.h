#ifndef SIMU_WAVEFORM_H
#define SIMU_WAVEFORM_H

#include <stdint.h>
#include <math.h>

#define PEAK_VOLTAGE 5
#define V_REF 1.0
#define OFFSET 0.5

#define ADC_BITS 8
#define RESOLUTION 256
#define LSB (double)(V_REF/RESOLUTION)

#define RESISTOR_LADDER (1000+499000+487000+8250)
#define MULT_RESISTOR 8250

void simulate_waveform(uint16_t* signal, uint16_t point_count);

#endif
