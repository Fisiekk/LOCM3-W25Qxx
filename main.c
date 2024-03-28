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
  rcc
}

int main(void)
{
  uint8_t page_buffer[]
  return 0;
}
