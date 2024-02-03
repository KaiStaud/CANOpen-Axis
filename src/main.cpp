#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>

#define SPI1_NODE           DT_NODELABEL(spi1)


int main() {
    struct device *spi1_dev = device_get_binding(SPI1_NODE);

    struct spi_config spi_cfg {
        .frequency = 1625000U,
        .operation = SPI_WORD_SET(8) | SPI_TRANSFER_MSB | SPI_OP_MODE_MASTER,
    };

    struct spi_buf bufs[] = {
            {
                    .buf = (uint8_t *)"Hello, Zephyr",
                    .len = 13
            },
    };

    struct spi_buf_set tx = {
            .buffers =  bufs,
            .count = 1
    };

    return spi_write(spi1_dev, spi_cfg, &tx);

    while (true) {}
return 0;
}
