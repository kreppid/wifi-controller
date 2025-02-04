#include "uart_transfer_impl.h"

uart_config_t uart_config() {
    return uart_config_t{
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_ODD,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT
    };
}

void uart_init(QueueHandle_t *queue) {
    uart_config_t config = uart_config();

    const uart_port_t uart_recv = UART_NUM_1;
    const uart_port_t uart_send = UART_NUM_2;

    size_t buff_size = DEF_BUFF_SIZE * 2;

    ESP_ERROR_CHECK(uart_set_pin(uart_recv, 0,0,0,0));
    ESP_ERROR_CHECK(uart_set_pin(uart_send, 0,0,0,0));

    // TODO добавить общую очередь для двух uart (QueueHandle_t??)
    ESP_ERROR_CHECK(uart_driver_install(uart_recv, buff_size, 0, 0, queue, 0));


}

[[noreturn]] void uart_recv_task() {
    while (true) {

    }
}

[[noreturn]] void uart_send_task() {
    while (true) {

    }
}
