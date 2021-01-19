#pragma once

#include "quantum.h"

enum userspace_layers {
    _BL = 0,  // Base Layer
    _FL = 1,  // Fn Layer
    _CFL = 2,  // Ctrl Layer
    _AL = 3,  // Alt Layer
};

// Enum of custom keycodes defined in process_record_user
enum keycodes {
    MAC_SIGN = SAFE_RANGE, // Email signature
    MAC_1, // Macro 1: "64-bit" video link
    MAC_2A, // Macro 2 (single tap): create new dektop and open PuTTY terminal
    MAC_2B, // Macro 2 (double tap): create new dektop, open PuTTY terminal, AND VNC connection
    MAC_3, // Macro 3: volume up
    MAC_4, // Macro 4:
    MAC_5, // Macro 5: power off
//  MAC_6, // Macro 6: (single tap): volume down, (double tap): mute *****currently defined directly in keymap.c, below kept to maintain template form*****
    MAC_7, // Macro 7: print-screen and save to Pictures folder
    MAC_8, // Macro 8: sync all qmk_firmware repos
    MAC_9, // Macro 9: sleep
    MAC_10, // Macro 10: skip to previous track (defined as such to maintain template form)
    MAC_11, // Macro 11: open ssh and download the magnet file in clipboard to server
    MAC_12, // Macro 12: skip to next track (defined as such to maintain template form)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {  // Custom keycode definitions i.e. macros
    switch (keycode) {
        case MAC_SIGN:
            if (record->event.pressed) {  // When keycode MAC_0 is pressed
                SEND_STRING("\n\n\nAll the best,\n\nPJ Cheyne-Miller\n");
            } else {  // When keycode MAC_0 is released
            }
            break;

        case MAC_1: // "64-bit" video link
            if (record->event.pressed) {  // When keycode MAC_1 is pressed
                SEND_STRING("youtu.be/VUcI0p04XJw");
            } else {  // When keycode MAC_1 is released
            }
            break;

        case MAC_2A: // create new dektop, open PuTTY terminal, and VNC connection
            if (record->event.pressed) {  // When keycode MAC_2 is pressed
                SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)"d"SS_UP(X_LGUI)SS_UP(X_LCTL)); // new desktop
                SEND_STRING(SS_DOWN(X_LGUI)"r"SS_UP(X_LGUI)"PuTTY"SS_TAP(X_ENT)); // open default PuTTY connection
            } else {  // When keycode MAC_2 is released
            }
            break;

        case MAC_2B: // create new dektop, open PuTTY terminal, and VNC connection
            if (record->event.pressed) {  // When keycode MAC_2 is pressed
                SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)"d"SS_UP(X_LGUI)SS_UP(X_LCTL)); // new desktop
                SEND_STRING(SS_DOWN(X_LGUI)"r"SS_UP(X_LGUI)"PuTTY"SS_TAP(X_ENT)SS_TAP(X_ENT)); // open default PuTTY connection
                SEND_STRING(SS_DOWN(X_LGUI)"r"SS_UP(X_LGUI)"C:\\Program Files\\RealVNC\\VNC Viewer\\vncviewer.exe"SS_TAP(X_ENT)"Mnemosyne"SS_TAP(X_ENT)); // open vnc connection
            } else {  // When keycode MAC_2 is released
            }
            break;

        case MAC_3: // volume up (in macro to maintain form)
            if (record->event.pressed) {  // When keycode MAC_3 is pressed
                SEND_STRING(SS_TAP(X_VOLU));
            } else {  // When keycode MAC_3 is released
            }
            break;

        case MAC_4:
            if (record->event.pressed) {  // When keycode MAC_4 is pressed

            } else {  // When keycode MAC_4 is released
            }
            break;

        case MAC_5: // turn off machine (defined as such to maintain template form)
            if (record->event.pressed) {  // When keycode MAC_5 is pressed
                SEND_STRING(SS_TAP(X_PWR));
            } else {  // When keycode MAC_5 is released
            }
            break;
        /*
        case MAC_6: // currently defined directly in keymap.c, below kept to maintain template form
            if (record->event.pressed) {  // When keycode MAC_6 is pressed

            } else {  // When keycode MAC_6 is released
            }
            break;
        */
        case MAC_7: // print-screen and save to Pictures folder
            if (record->event.pressed) {  // When keycode MAC_7 is pressed
                SEND_STRING(SS_TAP(X_PSCR)SS_DOWN(X_LGUI)"r"SS_UP(X_LGUI)"mspaint"SS_TAP(X_ENT)SS_DOWN(X_LCTL)"v"SS_UP(X_LCTL)); // open paint and paste screenshot
                SEND_STRING(SS_TAP(X_LALT)"fa"SS_DOWN(X_LCTL)"l"SS_UP(X_LCTL)"Pictures"SS_TAP(X_ENT)SS_DOWN(X_LALT)SS_TAP(X_F4)SS_UP(X_LALT)); // save picture and close paint
            } else {  // When keycode MAC_7 is released
            }
            break;

        case MAC_8: // sync all qmk_firmware repos
            if (record->event.pressed) {  // When keycode MAC_8 is pressed
                SEND_STRING(SS_DOWN(X_LGUI)"r"SS_UP(X_LGUI)"notepad"SS_TAP(X_ENT)); // open notepad
                SEND_STRING("git checkout master\ngit fetch original\ngit pull original master\ngit push fork master\ngit checkout personal\ngit pull . master\ngit push fork personal\n"); // paste git commands for syncing qmk_firmware repos
                SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_UP(X_LSFT)SS_DOWN(X_LCTL)"c"SS_UP(X_LCTL)); // copy sommand string
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F4)SS_UP(X_LALT)); // close Notepad
                SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)"`"SS_UP(X_LSFT)SS_UP(X_LCTL)SS_DOWN(X_LCTL)"v"SS_UP(X_LCTL)); // run sync commands
            } else {  // When keycode MAC_8 is released
            }
            break;

        case MAC_9: // put machine to sleep (defined as such to maintain template form)
            if (record->event.pressed) {  // When keycode MAC_9 is pressed
                SEND_STRING(SS_TAP(X_SLEP));
            } else {  // When keycode MAC_9 is released
            }
            break;
        case MAC_10: // previous track (defined as such to maintain template form)
            if (record->event.pressed) {  // When keycode MAC_10 is pressed
                SEND_STRING(SS_TAP(X_MPRV));
            } else {  // When keycode MAC_10 is released
            }
            break;
        case MAC_11: // download torrent magnet from clipboard to personal server
            if (record->event.pressed) {  // When keycode MAC_11 is pressed
                SEND_STRING(SS_DOWN(X_LGUI)"r"SS_UP(X_LGUI)"PuTTY"SS_TAP(X_ENT)SS_TAP(X_ENT)); // open default PuTTY connection
                SEND_STRING(SS_DELAY(1500)); // wait for login
                SEND_STRING("screen"SS_TAP(ENTER)); // create new screen in PuTTY
                SEND_STRING("transmission-cli -er -v -w /srv/storage/'To Sort' "SS_DOWN(X_LGUI)"v"SS_UP(X_LGUI)SS_TAP(X_DOWN)SS_TAP(X_ENT)SS_TAP(X_ENT)); // start torrent download in screen session
                SEND_STRING(SS_DOWN(X_LGUI)"a"SS_UP(X_LGUI)"d"SS_DOWN(X_LALT)SS_TAP(X_F4)SS_UP(X_LALT)); // detach from screen and close PuTTY
            } else {  // When keycode MAC_11 is released
            }
            break;
        case MAC_12: // next track (defined as such to maintain template form)
            if (record->event.pressed) {  // When keycode MAC_12 is pressed
                SEND_STRING(SS_TAP(X_MNXT));
            } else {  // When keycode MAC_12 is released
            }
            break;
    }
    return true;
};

/* Hardware initialization, runs very early during startup, even before the USB has been started */
void keyboard_pre_init_user(void) {

}

/* Called when the matrix is initialized, and after some of the hardware has been set up, but before many of the features have been initialized */
void matrix_init_user(void) {

}

/* Custom matrix scan function (assumes COL2ROW and DEBOUNCING_DELAY > 0) */
void matrix_scan_user(void) {

}
