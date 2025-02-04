#ifndef UART_TRANSFER_IMPL_H
#define UART_TRANSFER_IMPL_H
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "driver/uart.h"


#define delay_ms(ms) vTaskDelay(ms / portTICK_PERIOD_MS)
#define DEF_BUFF_SIZE 1024


uart_config_t uart_config();
void uart_init();

#define DEFINITE_TASK(name, from, to) [[noreturn]] void name##_task(void *pvParameters) { \
                                                        uint8_t *buffer = malloc(DEF_BUFF_SIZE); \
                                                        while (true) { \
                                                            const int status = uart_read_bytes(from, buffer, DEF_BUFF_SIZE, portMAX_DELAY); \
                                                                if (status > 0) { \
                                                                    uart_write_bytes(to, buffer, status); \
                                                                } \
                                                                delay_ms(10); \
                                                                } \
                                                        }

// void uart1_task(void* pvParameters);
DEFINITE_TASK(uart1, UART_NUM_1, UART_NUM_0);
// void uart_debug_task(void* pvParameters);
DEFINITE_TASK(uart_debug, UART_NUM_0, UART_NUM_1);

#undef DEFINITE_TASK

#endif //UART_TRANSFER_IMPL_H
