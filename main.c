#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/usart.h>


#define sector_beg(sec, blc) (((0x1000 * sec) + 0x10000 * blc))
#define sector_end(sec, blc) ((0xFFF * (sec + 1) + sec) + 0x10000 * blc)

/*
 * 1 block (65536 B) = 256 pages
 * 1 block = 16 sectors
 * 1 sector (4096 B) = 16 pages
 * 1 page = 256 B
 * 
 * numer of pages depends on model
 * eg. 64Mbit version has 128 blocks
 * 256Mbit has 512 blocks etc.
 */


void clock_setup(void)
{
  rcc_clock_setup(&rcc_clock_config[RCC_CLOCK_CONFIG_HSI_PLL_64MHZ])
  
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_GPIOB);
  
  rcc_periph_clock_enable(RCC_SPI1);
  rcc_periph_clock_enable(RCC_USART1);

}

void gpio_setup(void)
{
  //gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO4);

  /*
   * SPI1
   * PA4 = CS; PA5 = CS
   * PA6 = MISO; PA7 = MOSI
   */
  gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO4 | GPIO5 | GPIO6 | GPIO7);
  gpio_set_af(GPIOA, GPIO_AF0, GPIO4 | GPIO5 | GPIO6 | GPIO7);

  spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_64, SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE, SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_LSBFIRST);
  
}

int main(void)
{
  clock_setup();
  gpio_setup();
  
  //uint8_t page_buffer[32] = {0};
  
  gpio_set(GPIOA, GPIO4);
  
  return 0;
}
