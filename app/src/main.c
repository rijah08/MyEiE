/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1
int main(void) {
  if (0 > BTN_init()) {
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }

  uint8_t count = 0;

  while (1) {
    if (BTN_check_clear_pressed(BTN0)) {
      count = (count + 1) % 16;

      LED_set(LED0, (count & 0x1) ? LED_ON : LED_OFF);
      LED_set(LED1, (count & 0x2) ? LED_ON : LED_OFF);
      LED_set(LED2, (count & 0x4) ? LED_ON : LED_OFF);
      LED_set(LED3, (count & 0x8) ? LED_ON : LED_OFF);
    }
    k_msleep(SLEEP_MS);
  }
  return 0;
}