#ifndef CONFIG_H
    #define CONFIG_H
    #include "config_common.h"

    /* USB device descriptor parameters */
    #define VENDOR_ID       0x504A
    #define PRODUCT_ID      0x434D
    #define DEVICE_VER      0x0001
    #define MANUFACTURER    PJ Cheyne-Miller
    #define PRODUCT         Redragon Vara QMK Mod
    #define DESCRIPTION     ANSI 104-Key Keyboard

    /* key matrix size */
    #define MATRIX_ROWS 6
    #define MATRIX_COLS 21

    /* key matrix pins */
    #define MATRIX_ROW_PINS { C13, C14, C15, A0, B5, A1 }
    #define MATRIX_COL_PINS { A2, A3, A4, A5, A6, A7, B0, B1, B10, B12, B13, B14, B15, A8, A15, B3, B4, B6, B7, B8, B9 }

    /* COL2ROW or ROW2COL */
    #define DIODE_DIRECTION COL2ROW

    /* set 0 ms if software debouncing isn't needed (default 5)*/
    #define DEBOUNCING_DELAY 5

    /* key combination for command */
    #define IS_COMMAND() ( \
        keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
    )

    /* prevent stuck modifiers */
    #define PREVENT_STUCK_MODIFIERS

    /* Tap Dance time between presses (in milliseconds) */
    #define TAPPING_TERM 200

    /* defining these options will disable the associated feature, which can save on code size */
    // #define NO_DEBUG // Disable debugging
    // #define NO_PRINT // Disable printing / debugging using hid_listen
    // #define NO_ACTION_LAYER // Disable layers
    // #define NO_ACTION_TAPPING // Disable tap dance and other tapping features
    // #define NO_ACTION_ONESHOT // Disable one-shot modifiers
    #define NO_ACTION_MACRO // Disable old - style macro handling using MACRO(), action_get_macro() (deprecated)
    #define NO_ACTION_FUNCTION // Disable old - style function handling using fn_actions, action_function() (deprecated)
    #define FORCE_NKRO // NKRO by default requires to be turned on, this forces it on during keyboard startup regardless of EEPROM setting. NKRO can still be turned off but will be turned on again if the keyboard reboots.
    // #define STRICT_LAYER_RELEASE // Force a key release to be evaluated using the current layer stack instead of remembering which layer it came from (used for advanced cases)
#endif
