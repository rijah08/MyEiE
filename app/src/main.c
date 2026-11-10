/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1000

int main(void) {
  printk("start1\n");
  printk("start\n");
  if (0 > BTN_init()) {
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }
  printk("init2 done\n");
  printk("start while loop\n");
  while (1) {
    printk("while loop running\n");
    k_msleep(SLEEP_MS);
    }
  return 0;
}
