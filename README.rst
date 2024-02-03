.. _hello_world:

Hello World
###########

Overview
********

Firmware for CANOpen-Drives.
H-Bridge: ST-Micro L476
Devboard: nucleo_g474re
Encoder: AS5600
Powercontrol: INA219
CAN: On-Board MCAN

Device-Tree needs to reference SPI-Device with:
&spi1 {
    /* ... other properties ... */
    label = "SPI_1";
};


Building and Running
********************

This application can be built and executed on QEMU as follows:

.. zephyr-app-commands::
   :zephyr-app: samples/hello_world
   :host-os: unix
   :board: qemu_x86
   :goals: run
   :compact:

To build for another board, change "qemu_x86" above to that board's name.

Sample Output
=============

.. code-block:: console

    Hello World! x86

Exit QEMU by pressing :kbd:`CTRL+A` :kbd:`x`.
