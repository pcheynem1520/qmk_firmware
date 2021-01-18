#pragma once

#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

enum userspace_layers {
    _BL = 0,  // Base Layer
    _FL = 1,  // Fn Layer
    _AL,      // Alt Layer
    _CL,      // Ctrl Layer
};

// Enum of custom keycodes defined in process_record_user
enum keycodes {
    SIGN = SAFE_RANGE,  // Email signature
    MAC_0,              // Macro 0:
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
        case SIGN:
            if (record->event.pressed) {  // When keycode SIGN is pressed
                SEND_STRING("\n\n\nBest regards,\n\nPJ Cheyne-Miller\n");
            } else {  // When keycode SIGN is released

            }
            break;

        case MAC_0:
            if (record->event.pressed) {  // When keycode MAC_0 is pressed

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
#if (DIODE_DIRECTION == COL2ROW)  // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
#    if (DEBOUNCING_DELAY > 0)
        bool matrix_changed = read_cols_on_row_user(matrix_debouncing, current_row);

        if (matrix_changed) {
            debouncing      = true;
            debouncing_time = timer_read();
        }
#    else
        read_cols_on_row_user(matrix, current_row);
#    endif
    }
#endif

#if (DEBOUNCING_DELAY > 0)
    if (debouncing && (timer_elapsed(debouncing_time) > DEBOUNCING_DELAY)) {
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            matrix[i] = matrix_debouncing[i];
        }
        debouncing = false;
    }
#endif

    return 1;
}

static bool read_cols_on_row_user(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    // Select row and wait for row selecton to stabilize
    select_row(current_row);
    matrix_io_delay();

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Select the col pin to read (active low)
        uint8_t pin_state = readPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_row_value |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }

    // Unselect row
    unselect_row(current_row);

    // If the row has changed, store the row and return the changed flag.
    if (current_matrix[current_row] != current_row_value) {
        current_matrix[current_row] = current_row_value;
        return true;
    }
    return false;
}
