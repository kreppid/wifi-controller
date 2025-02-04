#include "freertos/FreeRTOS.h"
#include "src/uart_transfer_impl.h"

void app_main() {

    uart_init();

    xTaskCreatePinnedToCore(uart1_task, "uart_recv_task", 4 * DEF_BUFF_SIZE , NULL, 10, NULL, 0);
    xTaskCreatePinnedToCore(uart_debug_task, "uart_debug_task", 4 * DEF_BUFF_SIZE , NULL, 10, NULL,1);

}