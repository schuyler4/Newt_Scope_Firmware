#ifndef MAIN_H
#define MAIN_H

#define TRIGGER_PIN_COUNT 9
#define FORCE_TRIGGER_PIN_COUNT 8
#define FIFO_REGISTER_WIDTH 32
#define PIN_BASE 0
#define SAMPLE_COUNT 20000

#define CLOCK_PIN 21
#define PS_SET_PIN 23
#define RANGE_PIN 27 

#define TRIGGER_PIN 8

#define SIMU_WAVEFORM_POINTS 50

#define SPI_SCK_FREQUENCY 10000
#define SPI_SCK 10
#define SPI_RX 12
#define SPI_TX 11
#define CS_PIN 13
#define CAL_PIN 14

#define MAX_STRING_LENGTH 100

#define PWM_HIGH_COUNT 32770
#define PWM_CLK_DIV 2

#define CHARACTER_TIMEOUT 100

#include "pico/stdlib.h"
#include "hardware/pio.h"

typedef enum
{
    FALLING_EDGE,
    RISING_EDGE
} TriggerType;

void setup_IO(void);
void setup_SPI(void);
uint8_t sampler_init(pio_sm_config* c, PIO pio, uint8_t sm, uint8_t pin_base);
void arm_sampler(PIO pio, uint sm, uint dma_channel, uint32_t *capture_buffer, 
                 size_t capture_size_words, uint trigger_pin, bool trigger_level, 
                 uint8_t force_trigger);
void trigger(uint8_t forced);
void trigger_callback(uint gpio, uint32_t event_mask);
void print_samples(uint32_t* sample_buffer, uint sample_buffer_length, uint8_t force_trigger);
void transmit_vector(uint16_t* vector, uint16_t point_count);
void get_string(char* str);
void setup_cal_pin(void);
void run_trigger(void);
void reset_triggers(void);

#endif
