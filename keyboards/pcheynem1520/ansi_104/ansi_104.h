#pragma once

#include "quantum.h"

enum userspace_layers {
    _BL = 0,  // Base Layer
    _FL = 1,  // Fn Layer
    _AL,      // Alt Layer
    _CL,      // Ctrl Layer
};

// Enum of custom keycodes defined in process_record_user
enum keycodes {
    MAC_0 = SAFE_RANGE, // Macro 0: Email signature
    MAC_1,              // Macro 1:
    MAC_2,              // Macro 2:
    MAC_3,              // Macro 3:
    MAC_4,              // Macro 4:
    MAC_5,              // Macro 5:
    MAC_6,              // Macro 6:
    MAC_7,              // Macro 7:
    MAC_8,              // Macro 8:
    MAC_9,              // Macro 9:
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {  // Custom keycode definitions i.e. macros
    switch (keycode) {
        case MAC_0:
            if (record->event.pressed) {  // When keycode MAC_0 is pressed
                SEND_STRING("\n\n\nBest regards,\n\nPJ Cheyne-Miller\n");
            } else {  // When keycode MAC_0 is released
            }
            break;

        case MAC_1:
            if (record->event.pressed) {  // When keycode MAC_1 is pressed

            } else {  // When keycode MAC_1 is released
            }
            break;

        case MAC_2:
            if (record->event.pressed) {  // When keycode MAC_2 is pressed

            } else {  // When keycode MAC_2 is released
            }
            break;

        case MAC_3:
            if (record->event.pressed) {  // When keycode MAC_3 is pressed

            } else {  // When keycode MAC_3 is released
            }
            break;

        case MAC_4:
            if (record->event.pressed) {  // When keycode MAC_4 is pressed

            } else {  // When keycode MAC_4 is released
            }
            break;

        case MAC_5:
            if (record->event.pressed) {  // When keycode MAC_5 is pressed

            } else {  // When keycode MAC_5 is released
            }
            break;

        case MAC_6:
            if (record->event.pressed) {  // When keycode MAC_6 is pressed

            } else {  // When keycode MAC_6 is released
            }
            break;

        case MAC_7:
            if (record->event.pressed) {  // When keycode MAC_7 is pressed

            } else {  // When keycode MAC_7 is released
            }
            break;

        case MAC_8:
            if (record->event.pressed) {  // When keycode MAC_8 is pressed

            } else {  // When keycode MAC_8 is released
            }
            break;

        case MAC_9:
            if (record->event.pressed) {  // When keycode MAC_9 is pressed

            } else {  // When keycode MAC_9 is released
            }
            break;
    }
    return true;
};

void keyboard_pre_init_user(void) {  // Hardware initialization, runs very early during startup, even before the USB has been started

}

void matrix_init_user(void) {  // Called when the matrix is initialized, and after some of the hardware has been set up, but before many of the features have been initialized.

}

void matrix_scan_user(void) {     // Custom matrix scan function (assumes COL2ROW and DEBOUNCING_DELAY > 0)

}
