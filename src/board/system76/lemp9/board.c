#include <8051.h>

#include <board/board.h>
#include <board/gctrl.h>
#include <board/gpio.h>
#include <board/power.h>

extern uint8_t main_cycle;

void board_init(void) {
    RSTS = 0x44;
}

void board_event(void) {
    if (main_cycle == 0) {
        if (power_state == POWER_STATE_S0) {
            // System is on, CPU running
        } else if (power_state == POWER_STATE_S3 || power_state == POWER_STATE_DS3) {
            // System is suspended, sleep EC
            PCON |= 1;
        } else if (gpio_get(&ACIN_N)) {
            // Power off VDD3 if system should be off
            gpio_set(&XLP_OUT, 0);
        }
    }
}