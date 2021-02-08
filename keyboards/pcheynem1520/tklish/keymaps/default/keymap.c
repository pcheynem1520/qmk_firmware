#include "rev1.h" // Physical matrix
#include "tklish.h" // matrix_scan_user(), initialization functions, and custom keycodes

enum userspace_layers {
    _BL = 0, // Base Layer
    _FL = 1, // Fn Layer
    _CFL = 2, // Ctrl+Fn Layer
};

// Enum of custom keycodes defined in process_record_user
enum keycodes {
    MAC_SIGN = SAFE_RANGE, // Email signature
    MAC_1, // Macro 1: "64-bit" video link
    MAC_2A, // Macro 2: (single tap): create new dektop and open PuTTY terminal
    MAC_2B, // Macro 2: (double tap): create new dektop, open PuTTY terminal, AND VNC connection
//    MAC_3, // Macro 3: Volume up
    MAC_4, // Macro 4: delete all
    MAC_5, // Macro 5: power off
//    MAC_6, // Macro 6: defined in keymap.c
    MAC_7, // Macro 7: print-screen and save to Pictures folder
    MAC_8, // Macro 8: sync all qmk_firmware repos
    MAC_9, // Macro 9: sleep
//    MAC_10, // Macro 10: Previous track
    MAC_11, // Macro 11: open ssh and download the magnet file in clipboard to server
//    MAC_12, // Macro 12: Next track

    STARTUP, // Set up school computers for use
    AUTOCAD, // Open Autodesk AutoCAD
    M_EXCEL, // Open Microsoft Excel
    M_WORD, // Open Microsoft Word
    LTspice, // Open LTspice
    DESKTOP, // Create new Windows desktop
    W_CALC, // Default Windows calculator
    VLC, // VLC media player
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {  // Custom keycode definitions i.e. macros
    switch (keycode) {
        case MAC_SIGN:
            if (record->event.pressed) {  // When keycode MAC_0 is pressed
                SEND_STRING("\n\n\nAll the best,\n\nPJ Cheyne-Miller\n\n");
            } else {  // When keycode MAC_0 is released
            } break;

        case MAC_1: // "64-bit" video link
            if (record->event.pressed) {  // When keycode MAC_1 is pressed
                SEND_STRING("youtu.be/VUcI0p04XJw");
            } else {  // When keycode MAC_1 is released
            } break;

        case MAC_2A: // create new dektop, open PuTTY terminal, and VNC connection
            if (record->event.pressed) {  // When keycode MAC_2 is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) "d" SS_UP(X_LGUI) SS_UP(X_LCTL)); // new desktop
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "PuTTY" SS_TAP(X_ENT) SS_DELAY(200) SS_TAP(X_ENT)); // open default PuTTY connection
            } else {  // When keycode MAC_2 is released
            } break;

        case MAC_2B: // create new dektop, open PuTTY terminal, and VNC connection
            if (record->event.pressed) {  // When keycode MAC_2 is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) "d" SS_UP(X_LGUI) SS_UP(X_LCTL)); // new desktop
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "PuTTY" SS_TAP(X_ENT) SS_DELAY(200) SS_TAP(X_ENT)); // open default PuTTY connection
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "C:\\Program Files\\RealVNC\\VNC Viewer\\vncviewer.exe" SS_TAP(X_ENT) "Mnemosyne" SS_TAP(X_ENT)); // open vnc connection
            } else {  // When keycode MAC_2 is released
            } break;
/*
        case MAC_3:
            if (record->event.pressed) {  // When keycode MAC_3 is pressed

            } else {  // When keycode MAC_3 is released
            } break;
*/
        case MAC_4: // delete all
            if (record->event.pressed) {  // When keycode MAC_4 is pressed
                SEND_STRING(SS_DOWN(X_LCTRL) "a" SS_UP(X_LCTRL) SS_TAP(X_DEL));
            } else {  // When keycode MAC_4 is released
            } break;

        case MAC_5: // turn off windows machine
            if (record->event.pressed) {  // When keycode MAC_5 is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "x" SS_UP(X_LGUI) SS_DELAY(100) "uu");
            } else {  // When keycode MAC_5 is released
            } break;
/*
        case MAC_6:
            if (record->event.pressed) {  // When keycode MAC_6 is pressed

            } else {  // When keycode MAC_6 is released
            } break;
*/
        case MAC_7: // print-screen and save to Pictures folder
            if (record->event.pressed) {  // When keycode MAC_7 is pressed
                SEND_STRING(SS_TAP(X_PSCR) SS_DELAY(100) SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(200) "mspaint" SS_TAP(X_ENT) SS_DELAY(500) SS_DOWN(X_LCTL) "v" SS_UP(X_LCTL)); // open paint and paste screenshot
                SEND_STRING(SS_TAP(X_LALT) "fa" SS_TAP(X_ENT) SS_DELAY(500) "y" SS_TAP(X_ENT) SS_DELAY(100)); // save picture
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(100) SS_TAP(X_F4) SS_UP(X_LALT)); // close paint
            } else {  // When keycode MAC_7 is released
            } break;

        case MAC_8: // sync all qmk_firmware repos
            if (record->event.pressed) {  // When keycode MAC_8 is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "notepad++" SS_TAP(X_ENT)); // open Notepad++
                SEND_STRING(SS_DELAY(200) SS_DOWN(X_LCTL) "n" SS_UP(X_LCTL) "git checkout master\ngit fetch upstream\ngit pull upstream master\n\ngit push origin master\n\ngit checkout dev_personal\ngit pull . master\n\ngit push origin dev_personal\n\n"); // paste git commands for syncing qmk_firmware repos
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_UP(X_LSFT) SS_DOWN(X_LCTL) "c" SS_UP(X_LCTL)); // copy sommand string
                SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) SS_DELAY(100) "n" SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT)); // close Notepad++
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) "`" SS_UP(X_LSFT) SS_UP(X_LCTL) SS_DELAY(100) SS_DOWN(X_LCTL) "v" SS_UP(X_LCTL)); // run sync commands
            } else {  // When keycode MAC_8 is released
            } break;

        case MAC_9: // put windows machine to sleep
            if (record->event.pressed) {  // When keycode MAC_9 is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "x" SS_UP(X_LGUI) SS_DELAY(200) "us");
            } else {  // When keycode MAC_9 is released
            } break;
/*
        case MAC_10: // previous track (defined as such to maintain template form)
            if (record->event.pressed) {  // When keycode MAC_10 is pressed

            } else {  // When keycode MAC_10 is released
            } break;
*/
        case MAC_11: // download torrent magnet from clipboard to personal server
            if (record->event.pressed) {  // When keycode MAC_11 is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "PuTTY" SS_TAP(X_ENT) SS_DELAY(200) SS_TAP(X_ENT)); // open default PuTTY connection
                SEND_STRING(SS_DELAY(1500)); // wait for login
                SEND_STRING("screen" SS_TAP(X_ENT) SS_TAP(X_ENT) SS_DELAY(100)); // create new screen in PuTTY
                SEND_STRING("transmission-cli -er -v -w /srv/storage/'To Sort' " SS_DOWN(X_LGUI) SS_TAP(X_UP) SS_UP(X_LGUI) SS_DELAY(250) SS_TAP(X_MS_BTN2) SS_DOWN(X_LGUI) SS_TAP(X_DOWN) SS_UP(X_LGUI) SS_DELAY(200) SS_TAP(X_ENT)); // start torrent download in screen session
                SEND_STRING(SS_DOWN(X_LCTL) "a" SS_UP(X_LCTL) SS_DELAY(100) "d" SS_DELAY(100) SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT) SS_DELAY(100) SS_TAP(X_ENT)); // detach from screen and close PuTTY
            } else {  // When keycode MAC_11 is released
            } break;
/*
        case MAC_12: // next track (defined as such to maintain template form)
            if (record->event.pressed) {  // When keycode MAC_12 is pressed

            } else {  // When keycode MAC_12 is released
            } break;
*/
        case STARTUP: // Set up school computers for use
            if (record->event.pressed) {  // When keycode SCL_SET is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "msedge" SS_TAP(X_ENT)); // open edge
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) "n" SS_UP(X_LCTL) SS_UP(X_LSFT) SS_DELAY(100) SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT) SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT)); // open incognito window and close main window
                SEND_STRING(SS_DOWN(X_LCTL) "l" SS_UP(X_LCTL) "drive.google.com" SS_TAP(X_ENT) SS_DELAY(100)); // open Google Drive
                SEND_STRING(SS_DOWN(X_LCTL) "t" SS_UP(X_LCTL) "mycourselink.lakeheadu.ca"); // open D2L

                SEND_STRING(SS_DOWN(X_LGUI) "e" SS_UP(X_LGUI) SS_DELAY(100)); // open windows explorer
                SEND_STRING(SS_DOWN(X_LCTL) "l" SS_UP(X_LCTL) "C:\\Users\\200416896\\Documents" SS_TAP(X_ENT) SS_DELAY(250)); // Navigate to Documents directory

                SEND_STRING(SS_DOWN(X_LGUI) "e" SS_UP(X_LGUI) SS_DELAY(100)); // open windows explorer
                SEND_STRING(SS_DOWN(X_LCTL) "l" SS_UP(X_LCTL) "D:\\University\\2021-2022\\Semester 1" SS_TAP(X_ENT)); // Navigate to USB drive directory
            } else {  // When keycode SCL_SET is released
            } break;

        case AUTOCAD: // Open AutoCAD
            if (record->event.pressed) {  // When keycode SCL_SET is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "autocad" SS_TAP(X_ENT)); // open AutoCAD
            } else {  // When keycode SCL_SET is released
            } break;

        case M_EXCEL: // Open Excel
            if (record->event.pressed) {  // When keycode M_EXCEL is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "excel" SS_TAP(X_ENT)); // open Excel
            } else {  // When keycode M_EXCEL is released
            } break;

        case M_WORD: // Open Word
            if (record->event.pressed) {  // When keycode M_WORD is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "winword" SS_TAP(X_ENT)); // open Word
            } else {  // When keycode M_WORD is released
            } break;

        case LTspice: // Open LTspice
            if (record->event.pressed) {  // When keycode LTspice is pressed
                SEND_STRING( SS_TAP(X_LGUI) SS_DELAY(100) "LTspice" SS_TAP(X_ENT)); // open LTspices
            } else {  // When keycode LTspice is released
            } break;

        case DESKTOP: // Create new Windows desktop
            if (record->event.pressed) {  // When keycode DESKTOP is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) "d" SS_UP(X_LCTL) SS_UP(X_LGUI)); // create new dektop
            } else {  // When keycode DESKTOP is released
            } break;

        case W_CALC: // Create new Windows desktop
            if (record->event.pressed) {  // When keycode DESKTOP is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) "calculator" SS_UP(X_LCTL) SS_UP(X_LGUI)); // open Windows calculator
            } else {  // When keycode DESKTOP is released
            } break;

        case VLC: // VLC media player
            if (record->event.pressed) {  // When keycode DESKTOP is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) "vlc" SS_UP(X_LCTL) SS_UP(X_LGUI)); // open VLC media player
            } else {  // When keycode DESKTOP is released
            } break;
    } return true;
};

/* Tap Dance declarations */
enum {
    MAC_2, // Macro 2: tap once for MAC_2A, twice for MAC_2B
    MAC_6, // Macro 6: tap once for KC_VOLD, twice for KC_MUTE
};

/* Tap Dance definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    [MAC_2] = ACTION_TAP_DANCE_DOUBLE(MAC_2A, MAC_2B),
    [MAC_6] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
};

/* keyboard layers */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = ANSI_73(  // keymap _BL: Base Layer (Default)
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,    KC_INS, KC_HOME,KC_PGUP,
        KC_CAPS,KC_A,   KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,KC_QUOT,KC_ENT,				KC_DEL, KC_END, KC_PGDN,
	    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,            KC_PSCR,KC_UP,  KC_PAUS,
        KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                         KC_RALT,KC_RGUI,        MO(_FL),KC_RCTL,    KC_LEFT,KC_DOWN,KC_RGHT
    ),

    [_FL] = ANSI_73(  // keymap _FL: Fn Layer
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,	KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,_______,
        _______,KC_F13,	KC_F14,	KC_F15,	KC_F16, KC_F17,	KC_F18,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	KC_F23,	KC_F24,_______,     KC_7,   KC_8,   KC_9,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,TG(_CFL),			KC_4,   KC_5,   KC_6,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,			KC_1,   KC_2,   KC_3,
        MO(_CFL),_______,_______,               KC_MPLY,                        _______,DYN_MACRO_PLAY1,_______,MO(_CFL),   KC_PDOT,KC_0,   KC_EQL
    ),

    [_CFL] = ANSI_73(  // keymap _CFL: press Fn+Ctrl+Enter to swap to permanent secondary kb mode for macros
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET,
        _______,_______,M_WORD, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,	MAC_1,TD(MAC_2),KC_VOLU,
        _______,AUTOCAD,MAC_SIGN,DESKTOP,_______,_______,_______,_______,_______,LTspice,_______,_______,TG(_BL),			MAC_4,  MAC_5,  TD(MAC_6),
        _______,_______,M_EXCEL,W_CALC, VLC,    _______,_______,_______,_______,_______,_______,        _______,			MAC_7,  MAC_8,  MAC_9,
        _______,_______,_______,				KC_MPLY,                DYN_REC_STOP,DYN_REC_START1,    _______,_______,    KC_MPRV,MAC_11, KC_MNXT
    )
};
