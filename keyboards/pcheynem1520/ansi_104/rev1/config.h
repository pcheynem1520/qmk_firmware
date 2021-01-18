#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7A44
#define PRODUCT_ID      0xA104
#define DEVICE_VER      1
#define MANUFACTURER    PJ Cheyne-Miller
#define PRODUCT         Keyboard
#define DESCRIPTION     ANSI_104-Key_Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 22

/* key matrix pins */
#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5 }
#define MATRIX_COL_PINS { B7, D0, D1, D2, D3, D4, D5, D6, D7, E0, E1, C0, C1, C2, C3, C4, C5, C6, C7, F7, F6 }
#define UNUSED_PINS { A6, A7, B0, B1, B2, B3, B4, B5, B5, B6, E4, E5, E6, E7, F0, F1, F2, F3, F4, F5 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

/* Defining these options will disable the associated feature, which can save on code size */
// #define NO_DEBUG // Disable debugging
// #define NO_PRINT // Disable printing / debugging using hid_listen
// #define NO_ACTION_LAYER // Disable layers
#define NO_ACTION_TAPPING // Disable tap dance and other tapping features
#define NO_ACTION_ONESHOT // Disable one-shot modifiers
#define NO_ACTION_MACRO // Disable old - style macro handling using MACRO(), action_get_macro() (deprecated)
#define NO_ACTION_FUNCTION // Disable old - style function handling using fn_actions, action_function() (deprecated)

/* Defining these options will enable the associated feature, which may increase your code size */
//#define FORCE_NKRO // NKRO by default requires to be turned on, this forces it on during keyboard startup regardless of EEPROM setting. NKRO can still be turned off but will be turned on again if the keyboard reboots.
//#define STRICT_LAYER_RELEASE // Force a key release to be evaluated using the current layer stack instead of remembering which layer it came from (used for advanced cases)

#endif
