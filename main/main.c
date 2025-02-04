#include "src/uart_transfer_impl.h"

void app_main() {
    QueueHandle_t queue;
    uart_init(&queue);
    // TODO 2 таска, в которых прием и отправка данных через разные uart
}