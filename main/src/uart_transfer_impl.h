#ifndef UART_TRANSFER_IMPL_H
#define UART_TRANSFER_IMPL_H

#include "freertos/queue.h"
#include "driver/uart.h"


#define delay_ms(ms) vTaskDelay(ms / portTICK_PERIOD_MS)
#define DEF_BUFF_SIZE 1024

uart_config_t uart_config();
void uart_init(QueueHandle_t *queue);

// TODO получение данных с одного uart и передача в данных в другой через queue
void uart_recv_task();
void uart_send_task();

#endif //UART_TRANSFER_IMPL_H
