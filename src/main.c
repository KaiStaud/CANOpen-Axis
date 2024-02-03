#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>
#include <stdint.h>  // Include the header for uint8_t
void main(void)
{
    const struct device *spi_dev;
    struct spi_config spi_cfg = {
        .frequency = 500000,
        .operation = SPI_OP_MODE_MASTER | SPI_TRANSFER_MSB |
                     SPI_WORD_SET(8) | SPI_LINES_SINGLE,
    };

        spi_dev = device_get_binding("SPI_1");

    if (!spi_dev) {
        printk("SPI: Device not found.\n");
        return;
    }

    printk("SPI: Device found.\n");

    while (1) {
        uint8_t tx_data[] = "Hello, SPI!";
        uint8_t rx_data[sizeof(tx_data)];

        struct spi_buf tx_buf = {
            .buf = tx_data,
            .len = sizeof(tx_data),
        };

        struct spi_buf_set tx = {
            .buffers = &tx_buf,
            .count = 1,
        };

        struct spi_buf rx_buf = {
            .buf = rx_data,
            .len = sizeof(rx_data),
        };

        struct spi_buf_set rx = {
            .buffers = &rx_buf,
            .count = 1,
        };

        int err = spi_transceive(spi_dev, &spi_cfg, &tx, &rx);
        if (err) {
            printk("SPI: Transfer error %d\n", err);
        } else {
            printk("SPI: Received: %s\n", rx_data);
        }

        k_sleep(K_MSEC(1000));
    }
}

