#pragma once

#include "quantum.h"

/* ########## User defined functions ########## */
/* Hardware initialization, runs very early during startup, even before the USB has been started */
void keyboard_pre_init_user(void) {

}

/* Called when the matrix is initialized, and after some of the hardware has been set up, but before many of the features have been initialized */
void matrix_init_user(void) {

}

/* Custom matrix scan function (assumes COL2ROW and DEBOUNCING_DELAY > 0) */
void matrix_scan_user(void) {

}
