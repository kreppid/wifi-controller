idf_component_register(
        SRCS "main.c"
        SRCS "src/uart_transfer_impl.c"
        REQUIRES esp_driver_uart
        INCLUDE_DIRS "src")
