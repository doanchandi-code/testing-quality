#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define BLINK_GPIO GPIO_NUM_2 
static const char *TAG = "ESP32_APP";
int led_state = 0;

void setup() {
    // Không cần Serial.begin() nếu chỉ dùng ESP_LOGI
    
    // 1. Cấu hình phần cứng (Sử dụng API của ESP-IDF)
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

void loop() {
    // 2. Vòng lặp chính của ứng dụng
    ESP_LOGI(TAG, "Trạng thái LED hiện tại: %s", led_state == 1 ? "BẬT" : "TẮT");
    
    gpio_set_level(BLINK_GPIO, led_state);
    led_state = !led_state; 
    
    vTaskDelay(1000 / portTICK_PERIOD_MS); 
}