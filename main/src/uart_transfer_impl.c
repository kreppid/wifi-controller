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

void uart_init() {
    const uart_config_t config = uart_config();

    // Configure uart1
    const uart_port_t uart1 = UART_NUM_1;

    const size_t buff_size = 2 * DEF_BUFF_SIZE;

    ESP_ERROR_CHECK(uart_param_config(uart1, &config));

    // TODO изменить пины
    ESP_ERROR_CHECK(uart_set_pin(uart1, UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE));

    ESP_ERROR_CHECK(uart_driver_install(uart1, buff_size, buff_size, 0, NULL, 0));

    // Configure uart0 (debug)
    const uart_port_t uart_debug = UART_NUM_0;

    ESP_ERROR_CHECK(uart_param_config(uart_debug, &config));

    ESP_ERROR_CHECK(uart_set_pin(uart_debug, UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE));

    ESP_ERROR_CHECK(uart_driver_install(uart_debug, buff_size, buff_size, 0, NULL, 0));
}
