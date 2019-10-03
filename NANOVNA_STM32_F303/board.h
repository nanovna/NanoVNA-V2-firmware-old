/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for the Strawberry Linux STbee
 */

/*
 * Board identifier.
 */
#define BOARD_NANOVNA_STM32_F303
#define BOARD_NAME              "NanoVNA"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            24000000
#define STM32_USBPRE STM32_USBPRE_DIV1

#define STM32_HSE_BYPASS

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define STM32F303xC

#define STM32F303xC_SYSTEM_MEMORY 0x1FFFC800
#define BOOT_FROM_SYTEM_MEMORY_MAGIC_ADDRESS 0x20003FF0
#define BOOT_FROM_SYTEM_MEMORY_MAGIC 0xDEADBEEF
#define SYSTEM_BOOT_MSP 0x20002250

/*
 * IO pins assignments
 */

/* on-board */

#define GPIOA_BUTTON            0
#define GPIOA_LEVER1			8
#define GPIOA_LED               9
#define GPIOA_USB_DM            11
#define GPIOA_USB_DP            12
#define GPIOA_JTMS              13
#define GPIOA_JTCK              14
#define GPIOB_LEVER2			14
#define GPIOB_PUSH				15

#define GPIOB_SPI_SCLK          3
#define GPIOB_SPI_MISO          4
#define GPIOB_SPI_MOSI          5
#define GPIOB_LCD_CS	        6
#define GPIOB_LCD_CD    	    7
#define GPIOB_I2C1_SCL          10
#define GPIOB_I2C1_SDA          11


#define GPIOD_OSC_IN            0
#define GPIOD_OSC_OUT           1


/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2U))
#define PIN_OSPEED_25M(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_50M(n)           (2U << ((n) * 2U))
#define PIN_OSPEED_100M(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v##U) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 *
#define GPIOA_BUTTON			0
#define GPIOA_LEVER1			8
#define GPIOA_LED               9
#define GPIOA_USB_DM            11
#define GPIOA_USB_DP            12
#define GPIOA_JTMS              13
#define GPIOA_JTCK              14
 */
#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(0U) |           \
                                     PIN_MODE_INPUT(1U) |           \
                                     PIN_MODE_INPUT(2U) |  			\
                                     PIN_MODE_INPUT(3U) |   		\
                                     PIN_MODE_INPUT(4U) |           \
                                     PIN_MODE_INPUT(5U) |  \
                                     PIN_MODE_INPUT(6U) |    \
                                     PIN_MODE_INPUT(7U) |    \
                                     PIN_MODE_INPUT(8U) | \
                                     PIN_MODE_OUTPUT(9U) |           \
                                     PIN_MODE_INPUT(10U) | \
                                     PIN_MODE_INPUT(GPIOA_USB_DM) |  \
                                     PIN_MODE_INPUT(GPIOA_USB_DP) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_JTMS) |    \
                                     PIN_MODE_ALTERNATE(GPIOA_JTCK) |    \
                                     PIN_MODE_INPUT(15U))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(0U) |       \
                                     PIN_OTYPE_PUSHPULL(1U) |       \
                                     PIN_OTYPE_PUSHPULL(2U) |   \
                                     PIN_OTYPE_PUSHPULL(3U) |   \
                                     PIN_OTYPE_PUSHPULL(4U) |       \
                                     PIN_OTYPE_PUSHPULL(5U) |       \
                                     PIN_OTYPE_PUSHPULL(6U) |       \
                                     PIN_OTYPE_PUSHPULL(7U) |       \
                                     PIN_OTYPE_PUSHPULL(8U) |       \
                                     PIN_OTYPE_PUSHPULL(9U) |       \
                                     PIN_OTYPE_PUSHPULL(10U) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DM) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DP) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_JTMS) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_JTCK) |      \
                                     PIN_OTYPE_PUSHPULL(15U))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_2M(0) |          \
                                     PIN_OSPEED_2M(1) |          \
                                     PIN_OSPEED_2M(2) |       \
                                     PIN_OSPEED_2M(3) |       \
                                     PIN_OSPEED_2M(4) |          \
                                     PIN_OSPEED_2M(5) |           \
                                     PIN_OSPEED_2M(6) |          \
                                     PIN_OSPEED_2M(7) |          \
                                     PIN_OSPEED_2M(8U) | \
                                     PIN_OSPEED_2M(9U) |          \
                                     PIN_OSPEED_2M(10U) |         \
                                     PIN_OSPEED_100M(GPIOA_USB_DM) |     \
                                     PIN_OSPEED_100M(GPIOA_USB_DP) |     \
                                     PIN_OSPEED_2M(GPIOA_JTMS) |         \
                                     PIN_OSPEED_2M(GPIOA_JTCK) |         \
                                     PIN_OSPEED_2M(15U))
#define VAL_GPIOA_PUPDR           (PIN_PUPDR_PULLDOWN(0) | \
                                     PIN_PUPDR_PULLDOWN(1) | \
                                     PIN_PUPDR_PULLDOWN(2) | \
                                     PIN_PUPDR_PULLDOWN(3) | \
                                     PIN_PUPDR_PULLDOWN(4) |         \
                                     PIN_PUPDR_PULLDOWN(5) |         \
                                     PIN_PUPDR_PULLDOWN(6) |         \
                                     PIN_PUPDR_PULLDOWN(7) |         \
                                     PIN_PUPDR_PULLDOWN(8) | \
                                     PIN_PUPDR_PULLDOWN(9) |         \
                                     PIN_PUPDR_PULLDOWN(10U) | \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DM) | \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DP) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_JTMS) |   \
                                     PIN_PUPDR_PULLDOWN(GPIOA_JTCK) |   \
                                     PIN_PUPDR_PULLDOWN(15U))
#define VAL_GPIOA_ODR             (PIN_ODR_HIGH(0) |             \
                                     PIN_ODR_HIGH(1) |             \
                                     PIN_ODR_HIGH(2) |         \
                                     PIN_ODR_HIGH(3) |         \
                                     PIN_ODR_HIGH(4) |             \
                                     PIN_ODR_LOW(5) |              \
                                     PIN_ODR_HIGH(6) |             \
                                     PIN_ODR_HIGH(7) |             \
                                     PIN_ODR_HIGH(8) |     \
                                     PIN_ODR_HIGH(9) |             \
                                     PIN_ODR_HIGH(10) | \
                                     PIN_ODR_HIGH(GPIOA_USB_DM) |   \
                                     PIN_ODR_HIGH(GPIOA_USB_DP) |   \
                                     PIN_ODR_HIGH(GPIOA_JTMS) |     \
                                     PIN_ODR_HIGH(GPIOA_JTCK) |     \
                                     PIN_ODR_HIGH(15))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(0, 0) |           \
                                     PIN_AFIO_AF(1, 0) |           \
                                     PIN_AFIO_AF(2, 0) |       \
                                     PIN_AFIO_AF(3, 0) |       \
                                     PIN_AFIO_AF(4, 0) |           \
                                     PIN_AFIO_AF(5, 0) |           \
                                     PIN_AFIO_AF(6, 0) |           \
                                     PIN_AFIO_AF(7, 0))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(8, 0) |           \
                                     PIN_AFIO_AF(9, 0) |           \
                                     PIN_AFIO_AF(10, 0) |          \
                                     PIN_AFIO_AF(GPIOA_USB_DM, 0) |     \
                                     PIN_AFIO_AF(GPIOA_USB_DP, 0) |     \
                                     PIN_AFIO_AF(GPIOA_JTMS, 0) |          \
                                     PIN_AFIO_AF(GPIOA_JTCK, 0) |          \
                                     PIN_AFIO_AF(15, 0))

/*
 * GPIOB setup:
 *
#define GPIOB_SPI_SCLK          3
#define GPIOB_SPI_MISO          4
#define GPIOB_SPI_MOSI          5
#define GPIOB_LCD_CS	        6
#define GPIOB_LCD_CD    	    7
#define GPIOB_I2C1_SCL          10
#define GPIOB_I2C1_SDA          11
 */
#define VAL_GPIOB_MODER             (PIN_MODE_INPUT(0) |   \
                                     PIN_MODE_INPUT(1) |   \
                                     PIN_MODE_INPUT(2) |           \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI_SCLK) | \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI_MISO) | \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI_MOSI) | \
                                     PIN_MODE_OUTPUT(GPIOB_LCD_CS) | \
                                     PIN_MODE_OUTPUT(GPIOB_LCD_CD) | \
                                     PIN_MODE_INPUT(8) | \
                                     PIN_MODE_INPUT(9) | \
                                     PIN_MODE_ALTERNATE(GPIOB_I2C1_SCL) | \
                                     PIN_MODE_ALTERNATE(GPIOB_I2C1_SDA))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(0) |       \
                                     PIN_OTYPE_PUSHPULL(1) |       \
                                     PIN_OTYPE_PUSHPULL(2) |       \
                                     PIN_OTYPE_PUSHPULL(3) | \
                                     PIN_OTYPE_PUSHPULL(4) |       \
                                     PIN_OTYPE_PUSHPULL(5) |       \
                                     PIN_OTYPE_PUSHPULL(6) |       \
                                     PIN_OTYPE_PUSHPULL(7) |       \
                                     PIN_OTYPE_PUSHPULL(8) | \
                                     PIN_OTYPE_PUSHPULL(9) | \
                                     PIN_OTYPE_PUSHPULL(10) |      \
                                     PIN_OTYPE_PUSHPULL(11) |      \
                                     PIN_OTYPE_PUSHPULL(12) | \
                                     PIN_OTYPE_PUSHPULL(13) | \
                                     PIN_OTYPE_PUSHPULL(14) | \
                                     PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_2M(0) | \
                                     PIN_OSPEED_2M(1) | \
                                     PIN_OSPEED_2M(2) |          \
                                     PIN_OSPEED_2M(3) | \
                                     PIN_OSPEED_2M(4) |          \
                                     PIN_OSPEED_2M(5) |          \
                                     PIN_OSPEED_2M(6) |          \
                                     PIN_OSPEED_2M(7) |          \
                                     PIN_OSPEED_2M(8) | \
                                     PIN_OSPEED_2M(9) | \
                                     PIN_OSPEED_2M(GPIOB_I2C1_SCL) |         \
                                     PIN_OSPEED_2M(GPIOB_I2C1_SDA) |         \
                                     PIN_OSPEED_2M(12) | \
                                     PIN_OSPEED_2M(13) | \
                                     PIN_OSPEED_2M(14) | \
                                     PIN_OSPEED_2M(15))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLUP(0) |         \
                                     PIN_PUPDR_PULLUP(1) |         \
                                     PIN_PUPDR_PULLUP(2) |         \
                                     PIN_PUPDR_PULLUP(3) | 		   \
                                     PIN_PUPDR_PULLUP(4) |         \
                                     PIN_PUPDR_PULLUP(5) |         \
                                     PIN_PUPDR_PULLUP(6) |         \
                                     PIN_PUPDR_PULLUP(7) |         \
                                     PIN_PUPDR_PULLUP(8) |        \
                                     PIN_PUPDR_PULLUP(9) |        \
                                     PIN_PUPDR_PULLUP(GPIOB_I2C1_SCL) | \
                                     PIN_PUPDR_PULLUP(GPIOB_I2C1_SDA) | \
                                     PIN_PUPDR_PULLUP(12) | \
                                     PIN_PUPDR_PULLUP(13) | \
                                     PIN_PUPDR_PULLUP(14) | \
                                     PIN_PUPDR_PULLUP(15))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_I2C1_SCL) | \
                                     PIN_ODR_HIGH(GPIOB_I2C1_SDA))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(0, 0) |           \
                                     PIN_AFIO_AF(1, 0) |           \
                                     PIN_AFIO_AF(2, 0) |           \
                                     PIN_AFIO_AF(GPIOB_SPI_SCLK, 5) | \
                                     PIN_AFIO_AF(GPIOB_SPI_MOSI, 5) | \
                                     PIN_AFIO_AF(GPIOB_SPI_MISO, 5) | \
                                     PIN_AFIO_AF(6, 0) |           \
                                     PIN_AFIO_AF(7, 0))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(8, 0) | \
                                     PIN_AFIO_AF(9, 0) | \
                                     PIN_AFIO_AF(10, 0) |          \
                                     PIN_AFIO_AF(11, 0) |          \
                                     PIN_AFIO_AF(12, 0) | \
                                     PIN_AFIO_AF(13, 0) | \
                                     PIN_AFIO_AF(14, 0) | \
                                     PIN_AFIO_AF(15, 0))
/*
 * GPIOC setup:
 *
 */
#define VAL_GPIOC_MODER             (PIN_MODE_INPUT(0) |           \
                                     PIN_MODE_INPUT(1) |           \
                                     PIN_MODE_INPUT(2) |           \
                                     PIN_MODE_INPUT(3) |           \
                                     PIN_MODE_INPUT(4) |           \
                                     PIN_MODE_INPUT(5) |           \
                                     PIN_MODE_INPUT(6) |           \
                                     PIN_MODE_INPUT(7) |           \
                                     PIN_MODE_INPUT(8) |           \
                                     PIN_MODE_INPUT(9) |           \
                                     PIN_MODE_INPUT(10) |          \
                                     PIN_MODE_INPUT(11) |          \
                                     PIN_MODE_INPUT(12) |          \
                                     PIN_MODE_OUTPUT(13) | \
                                     PIN_MODE_INPUT(14) | \
                                     PIN_MODE_INPUT(15))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(0) |       \
                                     PIN_OTYPE_PUSHPULL(1) |       \
                                     PIN_OTYPE_PUSHPULL(2) |       \
                                     PIN_OTYPE_PUSHPULL(3) |       \
                                     PIN_OTYPE_PUSHPULL(4) |       \
                                     PIN_OTYPE_PUSHPULL(5) |       \
                                     PIN_OTYPE_PUSHPULL(6) |       \
                                     PIN_OTYPE_PUSHPULL(7) |       \
                                     PIN_OTYPE_PUSHPULL(8) |       \
                                     PIN_OTYPE_PUSHPULL(9) |       \
                                     PIN_OTYPE_PUSHPULL(10) |      \
                                     PIN_OTYPE_PUSHPULL(11) |      \
                                     PIN_OTYPE_PUSHPULL(12) |      \
                                     PIN_OTYPE_PUSHPULL(13) | \
                                     PIN_OTYPE_PUSHPULL(14) | \
                                     PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_100M(0) |          \
                                     PIN_OSPEED_100M(1) |          \
                                     PIN_OSPEED_100M(2) |          \
                                     PIN_OSPEED_100M(3) |          \
                                     PIN_OSPEED_100M(4) |          \
                                     PIN_OSPEED_100M(5) |          \
                                     PIN_OSPEED_100M(6) |          \
                                     PIN_OSPEED_100M(7) |          \
                                     PIN_OSPEED_100M(8) |          \
                                     PIN_OSPEED_100M(9) |          \
                                     PIN_OSPEED_100M(10) |         \
                                     PIN_OSPEED_100M(11) |         \
                                     PIN_OSPEED_100M(12) |         \
                                     PIN_OSPEED_100M(13) | \
                                     PIN_OSPEED_100M(14) | \
                                     PIN_OSPEED_100M(15))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLUP(0) |         \
                                     PIN_PUPDR_PULLUP(1) |         \
                                     PIN_PUPDR_PULLUP(2) |         \
                                     PIN_PUPDR_PULLUP(3) |         \
                                     PIN_PUPDR_PULLUP(4) |         \
                                     PIN_PUPDR_PULLUP(5) |         \
                                     PIN_PUPDR_PULLUP(6) |         \
                                     PIN_PUPDR_PULLUP(7) |         \
                                     PIN_PUPDR_PULLUP(8) |         \
                                     PIN_PUPDR_PULLUP(9) |         \
                                     PIN_PUPDR_PULLUP(10) |        \
                                     PIN_PUPDR_PULLUP(11) |        \
                                     PIN_PUPDR_PULLUP(12) |        \
                                     PIN_PUPDR_FLOATING(13) | \
                                     PIN_PUPDR_FLOATING(14) |        \
                                     PIN_PUPDR_PULLUP(15))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(0) |             \
                                     PIN_ODR_HIGH(1) |             \
                                     PIN_ODR_HIGH(2) |             \
                                     PIN_ODR_HIGH(3) |             \
                                     PIN_ODR_HIGH(4) |             \
                                     PIN_ODR_HIGH(5) |             \
                                     PIN_ODR_HIGH(6) |             \
                                     PIN_ODR_HIGH(7) |             \
                                     PIN_ODR_HIGH(8) |             \
                                     PIN_ODR_HIGH(9) |             \
                                     PIN_ODR_HIGH(10) |            \
                                     PIN_ODR_HIGH(11) |            \
                                     PIN_ODR_HIGH(12) |            \
                                     PIN_ODR_HIGH(13) | \
                                     PIN_ODR_HIGH(14) | \
                                     PIN_ODR_HIGH(15))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(0, 0) |           \
                                     PIN_AFIO_AF(1, 0) |           \
                                     PIN_AFIO_AF(2, 0) |           \
                                     PIN_AFIO_AF(3, 0) |           \
                                     PIN_AFIO_AF(4, 0) |           \
                                     PIN_AFIO_AF(5, 0) |           \
                                     PIN_AFIO_AF(6, 0) |           \
                                     PIN_AFIO_AF(7, 0))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(8, 0) |           \
                                     PIN_AFIO_AF(9, 0) |           \
                                     PIN_AFIO_AF(10, 0) |          \
                                     PIN_AFIO_AF(11, 0) |          \
                                     PIN_AFIO_AF(12, 0) |          \
                                     PIN_AFIO_AF(13, 0) | \
                                     PIN_AFIO_AF(14, 0) | \
                                     PIN_AFIO_AF(15, 0))

/*
 * GPIOD setup:
 */
#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(0) |           \
                                     PIN_MODE_INPUT(1) |           \
                                     PIN_MODE_INPUT(2) |           \
                                     PIN_MODE_INPUT(3) |           \
                                     PIN_MODE_INPUT(4) |           \
                                     PIN_MODE_INPUT(5) |           \
                                     PIN_MODE_INPUT(6) |           \
                                     PIN_MODE_INPUT(7) |           \
                                     PIN_MODE_INPUT(8) |           \
                                     PIN_MODE_INPUT(9) |           \
                                     PIN_MODE_INPUT(10) |          \
                                     PIN_MODE_INPUT(11) |          \
                                     PIN_MODE_INPUT(12) |          \
                                     PIN_MODE_INPUT(13) |          \
                                     PIN_MODE_INPUT(14) |          \
                                     PIN_MODE_INPUT(15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(0) |       \
                                     PIN_OTYPE_PUSHPULL(1) |       \
                                     PIN_OTYPE_PUSHPULL(2) |       \
                                     PIN_OTYPE_PUSHPULL(3) |       \
                                     PIN_OTYPE_PUSHPULL(4) |       \
                                     PIN_OTYPE_PUSHPULL(5) |       \
                                     PIN_OTYPE_PUSHPULL(6) |       \
                                     PIN_OTYPE_PUSHPULL(7) |       \
                                     PIN_OTYPE_PUSHPULL(8) |       \
                                     PIN_OTYPE_PUSHPULL(9) |       \
                                     PIN_OTYPE_PUSHPULL(10) |      \
                                     PIN_OTYPE_PUSHPULL(11) |      \
                                     PIN_OTYPE_PUSHPULL(12) |      \
                                     PIN_OTYPE_PUSHPULL(13) |      \
                                     PIN_OTYPE_PUSHPULL(14) |      \
                                     PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_100M(0) |          \
                                     PIN_OSPEED_100M(1) |          \
                                     PIN_OSPEED_100M(2) |          \
                                     PIN_OSPEED_100M(3) |          \
                                     PIN_OSPEED_100M(4) |          \
                                     PIN_OSPEED_100M(5) |          \
                                     PIN_OSPEED_100M(6) |          \
                                     PIN_OSPEED_100M(7) |          \
                                     PIN_OSPEED_100M(8) |          \
                                     PIN_OSPEED_100M(9) |          \
                                     PIN_OSPEED_100M(10) |         \
                                     PIN_OSPEED_100M(11) |         \
                                     PIN_OSPEED_100M(12) |         \
                                     PIN_OSPEED_100M(13) |         \
                                     PIN_OSPEED_100M(14) |         \
                                     PIN_OSPEED_100M(15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_PULLUP(0) |         \
                                     PIN_PUPDR_PULLUP(1) |         \
                                     PIN_PUPDR_PULLUP(2) |         \
                                     PIN_PUPDR_PULLUP(3) |         \
                                     PIN_PUPDR_PULLUP(4) |         \
                                     PIN_PUPDR_PULLUP(5) |         \
                                     PIN_PUPDR_PULLUP(6) |         \
                                     PIN_PUPDR_PULLUP(7) |         \
                                     PIN_PUPDR_PULLUP(8) |         \
                                     PIN_PUPDR_PULLUP(9) |         \
                                     PIN_PUPDR_PULLUP(10) |        \
                                     PIN_PUPDR_PULLUP(11) |        \
                                     PIN_PUPDR_PULLUP(12) |        \
                                     PIN_PUPDR_PULLUP(13) |        \
                                     PIN_PUPDR_PULLUP(14) |        \
                                     PIN_PUPDR_PULLUP(15))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(0) |             \
                                     PIN_ODR_HIGH(1) |             \
                                     PIN_ODR_HIGH(2) |             \
                                     PIN_ODR_HIGH(3) |             \
                                     PIN_ODR_HIGH(4) |             \
                                     PIN_ODR_HIGH(5) |             \
                                     PIN_ODR_HIGH(6) |             \
                                     PIN_ODR_HIGH(7) |             \
                                     PIN_ODR_HIGH(8) |             \
                                     PIN_ODR_HIGH(9) |             \
                                     PIN_ODR_HIGH(10) |            \
                                     PIN_ODR_HIGH(11) |            \
                                     PIN_ODR_HIGH(12) |            \
                                     PIN_ODR_HIGH(13) |            \
                                     PIN_ODR_HIGH(14) |            \
                                     PIN_ODR_HIGH(15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(0, 0) |           \
                                     PIN_AFIO_AF(1, 0) |           \
                                     PIN_AFIO_AF(2, 0) |           \
                                     PIN_AFIO_AF(3, 0) |           \
                                     PIN_AFIO_AF(4, 0) |           \
                                     PIN_AFIO_AF(5, 0) |           \
                                     PIN_AFIO_AF(6, 0) |           \
                                     PIN_AFIO_AF(7, 0))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(8, 0) |           \
                                     PIN_AFIO_AF(9, 0) |           \
                                     PIN_AFIO_AF(10, 0) |          \
                                     PIN_AFIO_AF(11, 0) |          \
                                     PIN_AFIO_AF(12, 0) |          \
                                     PIN_AFIO_AF(13, 0) |          \
                                     PIN_AFIO_AF(14, 0) |          \
                                     PIN_AFIO_AF(15, 0))

/*
 * GPIOE setup:
 *
 * PE0  - PIN0                      (input pullup).
 * PE1  - PIN1                      (input pullup).
 * PE2  - PIN2                      (input floating).
 * PE3  - PIN3                      (input pullup).
 * PE4  - PIN4                      (input floating).
 * PE5  - PIN5                      (input floating).
 * PE6  - PIN6                      (input floating).
 * PE7  - PIN7                      (input floating).
 * PE8  - PIN8                      (input floating).
 * PE9  - PIN9                      (input floating).
 * PE10 - PIN10                     (input floating).
 * PE11 - PIN11                     (input floating).
 * PE12 - PIN12                     (input floating).
 * PE13 - PIN13                     (input floating).
 * PE14 - PIN14                     (input floating).
 * PE15 - PIN15                     (input floating).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(0) |           \
                                     PIN_MODE_INPUT(1) |           \
                                     PIN_MODE_INPUT(2) |           \
                                     PIN_MODE_INPUT(3) |           \
                                     PIN_MODE_INPUT(4) |           \
                                     PIN_MODE_INPUT(5) |           \
                                     PIN_MODE_INPUT(6) |           \
                                     PIN_MODE_INPUT(7) |           \
                                     PIN_MODE_INPUT(8) |           \
                                     PIN_MODE_INPUT(9) |           \
                                     PIN_MODE_INPUT(10) |          \
                                     PIN_MODE_INPUT(11) |          \
                                     PIN_MODE_INPUT(12) |          \
                                     PIN_MODE_INPUT(13) |          \
                                     PIN_MODE_INPUT(14) |          \
                                     PIN_MODE_INPUT(15))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(0) |       \
                                     PIN_OTYPE_PUSHPULL(1) |       \
                                     PIN_OTYPE_PUSHPULL(2) |       \
                                     PIN_OTYPE_PUSHPULL(3) |       \
                                     PIN_OTYPE_PUSHPULL(4) |       \
                                     PIN_OTYPE_PUSHPULL(5) |       \
                                     PIN_OTYPE_PUSHPULL(6) |       \
                                     PIN_OTYPE_PUSHPULL(7) |       \
                                     PIN_OTYPE_PUSHPULL(8) |       \
                                     PIN_OTYPE_PUSHPULL(9) |       \
                                     PIN_OTYPE_PUSHPULL(10) |      \
                                     PIN_OTYPE_PUSHPULL(11) |      \
                                     PIN_OTYPE_PUSHPULL(12) |      \
                                     PIN_OTYPE_PUSHPULL(13) |      \
                                     PIN_OTYPE_PUSHPULL(14) |      \
                                     PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_100M(0) |          \
                                     PIN_OSPEED_100M(1) |          \
                                     PIN_OSPEED_100M(2) |          \
                                     PIN_OSPEED_100M(3) |          \
                                     PIN_OSPEED_100M(4) |          \
                                     PIN_OSPEED_100M(5) |          \
                                     PIN_OSPEED_100M(6) |          \
                                     PIN_OSPEED_100M(7) |          \
                                     PIN_OSPEED_100M(8) |          \
                                     PIN_OSPEED_100M(9) |          \
                                     PIN_OSPEED_100M(10) |         \
                                     PIN_OSPEED_100M(11) |         \
                                     PIN_OSPEED_100M(12) |         \
                                     PIN_OSPEED_100M(13) |         \
                                     PIN_OSPEED_100M(14) |         \
                                     PIN_OSPEED_100M(15))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_PULLUP(0) |         \
                                     PIN_PUPDR_PULLUP(1) |         \
                                     PIN_PUPDR_FLOATING(2) |       \
                                     PIN_PUPDR_PULLUP(3) |         \
                                     PIN_PUPDR_FLOATING(4) |       \
                                     PIN_PUPDR_FLOATING(5) |       \
                                     PIN_PUPDR_FLOATING(6) |       \
                                     PIN_PUPDR_FLOATING(7) |       \
                                     PIN_PUPDR_FLOATING(8) |       \
                                     PIN_PUPDR_FLOATING(9) |       \
                                     PIN_PUPDR_FLOATING(10) |      \
                                     PIN_PUPDR_FLOATING(11) |      \
                                     PIN_PUPDR_FLOATING(12) |      \
                                     PIN_PUPDR_FLOATING(13) |      \
                                     PIN_PUPDR_FLOATING(14) |      \
                                     PIN_PUPDR_FLOATING(15))
#define VAL_GPIOE_ODR               (PIN_ODR_HIGH(0) |             \
                                     PIN_ODR_HIGH(1) |             \
                                     PIN_ODR_HIGH(2) |             \
                                     PIN_ODR_HIGH(3) |             \
                                     PIN_ODR_HIGH(4) |             \
                                     PIN_ODR_HIGH(5) |             \
                                     PIN_ODR_HIGH(6) |             \
                                     PIN_ODR_HIGH(7) |             \
                                     PIN_ODR_HIGH(8) |             \
                                     PIN_ODR_HIGH(9) |             \
                                     PIN_ODR_HIGH(10) |            \
                                     PIN_ODR_HIGH(11) |            \
                                     PIN_ODR_HIGH(12) |            \
                                     PIN_ODR_HIGH(13) |            \
                                     PIN_ODR_HIGH(14) |            \
                                     PIN_ODR_HIGH(15))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(0, 0) |           \
                                     PIN_AFIO_AF(1, 0) |           \
                                     PIN_AFIO_AF(2, 0) |           \
                                     PIN_AFIO_AF(3, 0) |           \
                                     PIN_AFIO_AF(4, 0) |           \
                                     PIN_AFIO_AF(5, 0) |           \
                                     PIN_AFIO_AF(6, 0) |           \
                                     PIN_AFIO_AF(7, 0))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(8, 0) |           \
                                     PIN_AFIO_AF(9, 0) |           \
                                     PIN_AFIO_AF(10, 0) |          \
                                     PIN_AFIO_AF(11, 0) |          \
                                     PIN_AFIO_AF(12, 0) |          \
                                     PIN_AFIO_AF(13, 0) |          \
                                     PIN_AFIO_AF(14, 0) |          \
                                     PIN_AFIO_AF(15, 0))

/*
 * GPIOF setup:
 *
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(0) |           \
                                     PIN_MODE_INPUT(1) |           \
                                     PIN_MODE_INPUT(2) |           \
                                     PIN_MODE_INPUT(3) |           \
                                     PIN_MODE_INPUT(4) |           \
                                     PIN_MODE_INPUT(5) |           \
                                     PIN_MODE_INPUT(6) |           \
                                     PIN_MODE_INPUT(7) |           \
                                     PIN_MODE_INPUT(8) |           \
                                     PIN_MODE_INPUT(9) |           \
                                     PIN_MODE_INPUT(10) |          \
                                     PIN_MODE_INPUT(11) |          \
                                     PIN_MODE_INPUT(12) |          \
                                     PIN_MODE_INPUT(13) |          \
                                     PIN_MODE_INPUT(14) |          \
                                     PIN_MODE_INPUT(15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(0) |       \
                                     PIN_OTYPE_PUSHPULL(1) |       \
                                     PIN_OTYPE_PUSHPULL(2) |       \
                                     PIN_OTYPE_PUSHPULL(3) |       \
                                     PIN_OTYPE_PUSHPULL(4) |       \
                                     PIN_OTYPE_PUSHPULL(5) |       \
                                     PIN_OTYPE_PUSHPULL(6) |       \
                                     PIN_OTYPE_PUSHPULL(7) |       \
                                     PIN_OTYPE_PUSHPULL(8) |       \
                                     PIN_OTYPE_PUSHPULL(9) |       \
                                     PIN_OTYPE_PUSHPULL(10) |      \
                                     PIN_OTYPE_PUSHPULL(11) |      \
                                     PIN_OTYPE_PUSHPULL(12) |      \
                                     PIN_OTYPE_PUSHPULL(13) |      \
                                     PIN_OTYPE_PUSHPULL(14) |      \
                                     PIN_OTYPE_PUSHPULL(15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_100M(0) |          \
                                     PIN_OSPEED_100M(1) |          \
                                     PIN_OSPEED_100M(2) |          \
                                     PIN_OSPEED_100M(3) |          \
                                     PIN_OSPEED_100M(4) |          \
                                     PIN_OSPEED_100M(5) |          \
                                     PIN_OSPEED_100M(6) |          \
                                     PIN_OSPEED_100M(7) |          \
                                     PIN_OSPEED_100M(8) |          \
                                     PIN_OSPEED_100M(9) |          \
                                     PIN_OSPEED_100M(10) |         \
                                     PIN_OSPEED_100M(11) |         \
                                     PIN_OSPEED_100M(12) |         \
                                     PIN_OSPEED_100M(13) |         \
                                     PIN_OSPEED_100M(14) |         \
                                     PIN_OSPEED_100M(15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(0) |       \
                                     PIN_PUPDR_FLOATING(1) |       \
                                     PIN_PUPDR_FLOATING(2) |       \
                                     PIN_PUPDR_FLOATING(3) |       \
                                     PIN_PUPDR_FLOATING(4) |       \
                                     PIN_PUPDR_FLOATING(5) |       \
                                     PIN_PUPDR_FLOATING(6) |       \
                                     PIN_PUPDR_FLOATING(7) |       \
                                     PIN_PUPDR_FLOATING(8) |       \
                                     PIN_PUPDR_FLOATING(9) |       \
                                     PIN_PUPDR_FLOATING(10) |      \
                                     PIN_PUPDR_FLOATING(11) |      \
                                     PIN_PUPDR_FLOATING(12) |      \
                                     PIN_PUPDR_FLOATING(13) |      \
                                     PIN_PUPDR_FLOATING(14) |      \
                                     PIN_PUPDR_FLOATING(15))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(0) |             \
                                     PIN_ODR_HIGH(1) |             \
                                     PIN_ODR_HIGH(2) |             \
                                     PIN_ODR_HIGH(3) |             \
                                     PIN_ODR_HIGH(4) |             \
                                     PIN_ODR_HIGH(5) |             \
                                     PIN_ODR_HIGH(6) |             \
                                     PIN_ODR_HIGH(7) |             \
                                     PIN_ODR_HIGH(8) |             \
                                     PIN_ODR_HIGH(9) |             \
                                     PIN_ODR_HIGH(10) |            \
                                     PIN_ODR_HIGH(11) |            \
                                     PIN_ODR_HIGH(12) |            \
                                     PIN_ODR_HIGH(13) |            \
                                     PIN_ODR_HIGH(14) |            \
                                     PIN_ODR_HIGH(15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(0, 0) |           \
                                     PIN_AFIO_AF(1, 0) |           \
                                     PIN_AFIO_AF(2, 0) |           \
                                     PIN_AFIO_AF(3, 0) |           \
                                     PIN_AFIO_AF(4, 0) |           \
                                     PIN_AFIO_AF(5, 0) |           \
                                     PIN_AFIO_AF(6, 0) |           \
                                     PIN_AFIO_AF(7, 0))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(8, 0) |           \
                                     PIN_AFIO_AF(9, 0) |           \
                                     PIN_AFIO_AF(10, 0) |          \
                                     PIN_AFIO_AF(11, 0) |          \
                                     PIN_AFIO_AF(12, 0) |          \
                                     PIN_AFIO_AF(13, 0) |          \
                                     PIN_AFIO_AF(14, 0) |          \
                                     PIN_AFIO_AF(15, 0))

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
