/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

static const char *TAG = "example";

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO 15
#define TRIGGER_GPIO 18
#define ECHO_GPIO 19
#define SPEED_OF_SOUND 764 //MPh


static configure_tech(void) {
    // Configure the peripherals so that TRIGGER CONSTANTLY SENDS PULSES
    gpio_reset_pin(TRIGGER_GPIO);
    gpio_set_direction(TRIGGER_GPIO, GPIO_MODE_OUTPUT);

    // Then ECHO_GPIO is configured to recieve signals
    gpio_reset_pin(ECHO_GPIO)
    gpio_set_direction(ECHO_GPIO, GPIO_MODE_INPUT);
}

static float calculate_distance(int trig_time, int echo_time) {
    // Ideally to calculate the distance, we have to multiply the difference in time by the speed of sound
    // Speed of sound in miles per hour = 764

    // Convert it into inches per hour, 63360 inches in a mile
    int conversion1 = SPEED_OF_SOUND * 63360
    // Convert it into inches per ms, 3.6 mil ms in an hour
    float conversion2 = conversion1 / 3600000
    // Multiply it by the difference in time
    int difference = echo_time - trig_time;
    float distance = conversion2 * difference;
    // The distance in inches
    return distance * 160// Convert time into actual ms;
}


static start_pulse(void) {
    // Ideally this function sends out the wave using the trigger gpio and returns the time
    gpio_set_level(TRIGGER_GPIO, true);
}

static stop_pulse(void) {
    // This is supposed to stop the pulse so that there can be an actual time to measure
    gpio_set_level(TRIGGER_GPIO, false);
}

void app_main(void)
{
    long int timer = 0;
    long int pulse_sent = 0;
    long int pulse_recieved = 0;

    /* Configure the peripheral */
    configure_tech();

    while (1) {
        // Increments a timer
        timer++;

        // Send a pulse
        start_pulse();
        pulse_sent = timer;
        vTaskDelay(CONFIG_BLINK_PERIOD / (portTICK_PERIOD_MS * 100)); // For a super short amount of time
        stop_pulse();


        // Check if pulse has been recieved yet
        if(gpio_get_level(ECHO_GPIO) == true) {
            pulse_recieved = timer;
            // If so, then use the start time and the current time to calculate distance s*t=d
            // Print out message displaying calculated distance
            float distance = calculate_distance(pulse_sent, pulse_recieved)
            printf("Pulse Recieved \nDistance is: %f inches\n\n", distance);
        }
        // else do nothing and keep sending pulse
        // if not recieving a pulse, return an error message <ECHO NOT RECIEVED>
        else {
            printf("ERROR | Pulse not recieved\n");
        }
    }
}
