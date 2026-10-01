#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/i2c.h"      // Included for i2c_port_t enum definitions
#include "ssd1306.h"

#define I2C_MASTER_SCL_IO   22      // SCL Pin
#define I2C_MASTER_SDA_IO   21      // SDA Pin
#define I2C_MASTER_NUM      I2C_NUM_0
#define OLED_I2C_ADDRESS    0x3C    // Common OLED address

static const char *TAG = "OLED_DEMO";

void app_main(void)
{
    ESP_LOGI(TAG, "Initializing legacy I2C bus for SSD1306...");

    // 1. Configure and Install I2C Driver
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 400000, // 400kHz I2C speed
    };
    
    ESP_ERROR_CHECK(i2c_param_config(I2C_MASTER_NUM, &conf));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_MASTER_NUM, conf.mode, 0, 0, 0));

    // 2. Initialize SSD1306 OLED Device
    ssd1306_handle_t dev = ssd1306_create(I2C_MASTER_NUM, OLED_I2C_ADDRESS);
    if (dev == NULL) {
        ESP_LOGE(TAG, "Failed to create SSD1306 device handle");
        return;
    }

    // 3. Clear Screen
    char header[] = "Hello, Ricky!";
    char text[] = "Build me a body pls";
    ssd1306_clear_screen(dev, 0x00);

    // 4. Draw Text and Line
    // Signature: ssd1306_draw_string(dev, x, y, string, font_size, color)

    

    while(1) {
        // ssd1306_draw_string(dev, 0, 0, (const uint8_t *)header, 16, 1);
        // ssd1306_draw_string(dev, 0, 20, (const uint8_t *)text, 12, 1);
        
        // Signature: ssd1306_draw_line(dev, x1, y1, x2, y2)
        //ssd1306_draw_line(dev, 0, 40, 127, 40);

        ssd1306_fill_rectangle(dev, 60, 28, 68, 36 )

        // 5. Refresh RAM to update physical display
        ssd1306_refresh_gram(dev);
    }

    ESP_LOGI(TAG, "OLED screen updated!");
}