#include "rev1.h" // physical matrix
#include "tklish.h" // matrix_scan_user(), initialization functions, and custom keycodes

enum userspace_layers {
    _BL = 0, // base Layer
    _FL = 1, // Fn Layer
    _CFL = 2, // Ctrl+Fn Layer
};

// enum of custom keycodes defined in process_record_user
enum keycodes {
    MAC_SIGN = SAFE_RANGE, // email signature
    MAC_1, // macro 1: "64-bit" video link
    MAC_2, // macro 2:
    MAC_3, // macro 3:
    MAC_4, // macro 4: delete all
    MAC_5, // macro 5: power off
//    MAC_6, // macro 6:
    MAC_7, // macro 7: print-screen and save to Pictures folder
    MAC_8, // macro 8: sync all qmk_firmware repos
    MAC_9, // macro 9: sleep
    MAC_10, // macro 10:
    MAC_11, // macro 11: open ssh and download the magnet file in clipboard to server
    MAC_12, // macro 12:

    M_EXCEL, // open Microsoft Excel
    M_WORD, // open Microsoft Word
    DESKTOP, // Create new Windows desktop
    W_CALC, // Default Windows calculator
    VLC, // VLC media player
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {  // custom keycode definitions i.e. macros
    switch (keycode) {
        case MAC_SIGN:
            if (record->event.pressed) {  // when keycode MAC_0 is pressed
                SEND_STRING("\n\n\nSincerely,\n\nKevin Ott\n\n");
            } else {  // when keycode MAC_0 is released
            } break;

        case MAC_1: // "64-bit" video link
            if (record->event.pressed) {  // when keycode MAC_1 is pressed
                SEND_STRING("youtu.be/VUcI0p04XJw");
            } else {  // when keycode MAC_1 is released
            } break;

        case MAC_2:
            if (record->event.pressed) {  // when keycode MAC_2 is pressed

            } else {  // when keycode MAC_2 is released
            } break;

        case MAC_3:
            if (record->event.pressed) {  // when keycode MAC_3 is pressed

            } else {  // when keycode MAC_3 is released
            } break;

        case MAC_4: // delete all
            if (record->event.pressed) {  // when keycode MAC_4 is pressed
                SEND_STRING(SS_DOWN(X_LCTRL) "a" SS_UP(X_LCTRL) SS_TAP(X_DEL));
            } else {  // when keycode MAC_4 is released
            } break;

        case MAC_5: // turn off windows machine
            if (record->event.pressed) {  // when keycode MAC_5 is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "x" SS_UP(X_LGUI) SS_DELAY(100) "uu");
            } else {  // when keycode MAC_5 is released
            } break;
/* currently used by Tap Dance
        case MAC_6:
            if (record->event.pressed) {  // when keycode MAC_6 is pressed

            } else {  // when keycode MAC_6 is released
            } break;
*/
        case MAC_7: // print-screen and save to Pictures folder
            if (record->event.pressed) {  // when keycode MAC_7 is pressed
                SEND_STRING(SS_TAP(X_PSCR) SS_DELAY(100) SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(200) "mspaint" SS_TAP(X_ENT) SS_DELAY(500) SS_DOWN(X_LCTL) "v" SS_UP(X_LCTL)); // open paint and paste screenshot
                SEND_STRING(SS_TAP(X_LALT) "fa" SS_TAP(X_ENT) SS_DELAY(500) "y" SS_TAP(X_ENT) SS_DELAY(100)); // save picture
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(100) SS_TAP(X_F4) SS_UP(X_LALT)); // close paint
            } else {  // when keycode MAC_7 is released
            } break;

        case MAC_8:
            if (record->event.pressed) {  // when keycode MAC_8 is pressed

            } else {  // when keycode MAC_8 is released
            } break;

        case MAC_9: // put windows machine to sleep
            if (record->event.pressed) {  // when keycode MAC_9 is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "x" SS_UP(X_LGUI) SS_DELAY(200) "us");
            } else {  // when keycode MAC_9 is released
            } break;

        case MAC_10:
            if (record->event.pressed) {  // when keycode MAC_10 is pressed

            } else {  // when keycode MAC_10 is released
            } break;

        case MAC_11: // download torrent magnet from clipboard to personal server
            if (record->event.pressed) {  // when keycode MAC_11 is pressed

            } else {  // when keycode MAC_11 is released
            } break;

        case MAC_12:
            if (record->event.pressed) {  // when keycode MAC_12 is pressed

            } else {  // when keycode MAC_12 is released
            } break;

        case M_EXCEL: // open Excel
            if (record->event.pressed) {  // when keycode M_EXCEL is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "excel" SS_TAP(X_ENT)); // open Excel
            } else {  // when keycode M_EXCEL is released
            } break;

        case M_WORD: // open Word
            if (record->event.pressed) {  // when keycode M_WORD is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(100) "winword" SS_TAP(X_ENT)); // open Word
            } else {  // when keycode M_WORD is released
            } break;

        case DESKTOP: // create new Windows desktop
            if (record->event.pressed) {  // when keycode DESKTOP is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) "d" SS_UP(X_LCTL) SS_UP(X_LGUI)); // create new dektop
            } else {  // when keycode DESKTOP is released
            } break;

        case W_CALC: // open Windows calculator
            if (record->event.pressed) {  // when keycode DESKTOP is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) "calculator" SS_UP(X_LCTL) SS_UP(X_LGUI)); // open Windows calculator
            } else {  // when keycode DESKTOP is released
            } break;

        case VLC: // VLC media player
            if (record->event.pressed) {  // when keycode DESKTOP is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) "vlc" SS_UP(X_LCTL) SS_UP(X_LGUI)); // open VLC media player
            } else {  // when keycode DESKTOP is released
            } break;
    } return true;
};

/* Tap Dance declarations */
enum {
    MAC_6, // macro 6: tap once for KC_VOLD, twice for KC_MUTE
};

/* Tap Dance definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
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
        _______,_______,MAC_SIGN,DESKTOP,_______,_______,_______,_______,_______,_______,_______,_______,TG(_BL),			MAC_4,  MAC_5,  TD(MAC_6),
        _______,_______,M_EXCEL,W_CALC, VLC,    _______,_______,_______,_______,_______,_______,        _______,			MAC_7,  MAC_8,  MAC_9,
        _______,_______,_______,				KC_MPLY,                DYN_REC_STOP,DYN_REC_START1,    _______,_______,    KC_MPRV,MAC_11, KC_MNXT
    )
};
