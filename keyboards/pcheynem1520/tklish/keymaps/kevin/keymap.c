#include "rev1.h" // physical matrix
#include "tklish.h" // matrix_scan_user(), initialization functions, and custom keycodes

enum userspace_layers {
    _BL = 0, // base Layer
    _FL = 1, // Fn Layer
    _FCL = 2, // Ctrl+Fn Layer
};

/* enum of custom keycodes defined in process_record_user */
enum keycodes { // macro declatations
    DEL_ALL = SAFE_RANGE, // delete all ("= SAFE RANGE" is a required quirk of QMK for first declaration)
    DWNLOAD, // open Downloads folder
    MEMELNK, // "64-bit" video link
    M_EXCEL, // open Microsoft Excel
    M_WORD, // open Microsoft Word
    PWR_DWN, // power off
    SCR_SAV, // print-screen and save to Pictures folder
    SIGN, // email signature
    SLEEP, // sleep
    W_CALC, // default Windows calculator
    VLC, // VLC media player
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // custom keycode definitions i.e. macros
    switch (keycode) {
        /* delete all text */
        case DEL_ALL:
            if (record->event.pressed) { // when keycode DEL_ALL is pressed
                SEND_STRING(SS_DOWN(X_LCTRL) "a" SS_UP(X_LCTRL) SS_TAP(X_DEL));
            } else { // when keycode DEL_ALL is released
            } break;

        /* open Discord */
        case DWNLOAD:
            if (record->event.pressed) { // when keycode DWNLOAD is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(250) "Downloads" SS_TAP(X_ENT)); // create new dektop
            } else { // when keycode DWNLOAD is released
            } break;

        /* "64-bit" video link */
        case MEMELNK:
            if (record->event.pressed) { // when keycode MEMELNK is pressed
                SEND_STRING("youtu.be/VUcI0p04XJw");
            } else { // when keycode MEMELNK is released
            } break;

        /* open Excel */
        case M_EXCEL:
            if (record->event.pressed) { // when keycode M_EXCEL is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(250) "excel" SS_TAP(X_ENT)); // open Excel
            } else { // when keycode M_EXCEL is released
            } break;

		/* open Word */
        case M_WORD:
            if (record->event.pressed) { // when keycode M_WORD is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(250) "winword" SS_TAP(X_ENT)); // open Word
            } else { // when keycode M_WORD is released
            } break;

		/* turn off windows machine */
        case PWR_DWN:
            if (record->event.pressed) { // when keycode PWR_DWN is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "x" SS_UP(X_LGUI) SS_DELAY(200) "uu");
            } else { // when keycode PWR_DWN is released
            } break;

        /* change directory to home directory of qmk_firmware (QMK terminal) */
        case QMK_HOM:
            if (record->event.pressed) { // when keycode QMK_HOM is pressed
                SEND_STRING("cd ~/Documents/GitHub/qmk_firmware\n"); // change directory to home directory of QMK
            } else { // when keycode QMK_HOM is released
            } break;

        /* sync all qmk_firmware repos in the VS code MINGW64 terminal */
        case QMK_SYN:
            if (record->event.pressed) { // when keycode QMK_SYN is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(250) "notepad" SS_TAP(X_ENT)); // open Notepad
                SEND_STRING(SS_DELAY(200) SS_DOWN(X_LCTL) "n" SS_UP(X_LCTL) "git checkout master\ngit fetch upstream\ngit pull upstream master\n\ngit push origin master\n\ngit checkout dev_personal\ngit pull . master\n\ngit push origin dev_personal\n\n"); // paste git commands for syncing qmk_firmware repos
                SEND_STRING(SS_DOWN(X_LCTL) "a" SS_UP(X_LCTL) SS_DOWN(X_LCTL) "c" SS_UP(X_LCTL)); // copy command string
                SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL)); // close Notepad
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) "`" SS_UP(X_LSFT) SS_UP(X_LCTL) SS_DELAY(250) SS_DOWN(X_LCTL) "v" SS_UP(X_LCTL)); // run sync commands
            } else { // when keycode QMK_SYN is released
            } break;

		/* print-screen and save to Pictures folder */
        case SCR_SAV:
            if (record->event.pressed) { // when keycode SCR_SAV is pressed
                SEND_STRING(SS_TAP(X_PSCR) SS_DELAY(100) SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(200) "mspaint" SS_TAP(X_ENT) SS_DELAY(500) SS_DOWN(X_LCTL) "v" SS_UP(X_LCTL)); // open paint and paste screenshot
                SEND_STRING(SS_TAP(X_LALT) "fa" SS_TAP(X_ENT) SS_DELAY(500) "y" SS_TAP(X_ENT) SS_DELAY(100)); // save picture
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(100) SS_TAP(X_F4) SS_UP(X_LALT)); // close paint
            } else { // when keycode SCR_SAV is released
            } break;

		/* email signature */
        case SIGN:
            if (record->event.pressed) { // when keycode SIGN is pressed
                SEND_STRING("\n\n\nAll the best,\n\nKevin Ott\n(He/Him/Il)\n");
            } else { // when keycode SIGN is released
            } break;

		/* put windows machine to sleep */
        case SLEEP:if (record->event.pressed) { // when keycode SLEEP is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "x" SS_UP(X_LGUI) SS_DELAY(200) "us");
            } else { // when keycode SLEEP is released
            } break;

		/* open calculator */
        case W_CALC:if (record->event.pressed) { // when keycode W_CALC is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(250) "calc" SS_TAP(X_ENT)); // open Windows calculator
            } else { // when keycode W_CALC is released
            } break;

		/* VLC media player */
        case VLC:
            if (record->event.pressed) { // when keycode VLC is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(250) "vlc" SS_TAP(X_ENT)); // open VLC media player
            } else { // when keycode VLC is released
            } break;
    } return true;
};

/* Tap Dance declarations */
enum {
    VDN_MUT, // tap once for KC_VOLD, twice for KC_MUTE
};

/* Tap Dance definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    [VDN_MUT] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
};

/* keyboard layers */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT( // keymap _BL: Base Layer (Default)
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,    KC_INS, KC_HOME,KC_PGUP,
        KC_CAPS,KC_A,   KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,KC_QUOT,KC_ENT,				KC_DEL, KC_END, KC_PGDN,
	    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,            KC_PSCR,KC_UP,  KC_PAUS,
        KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                         KC_RALT,KC_RGUI,        MO(_FL),KC_RCTL,    KC_LEFT,KC_DOWN,KC_RGHT
    ),

    [_FL] = LAYOUT( // keymap _FL: Fn Layer
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,	KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,_______,
        _______,KC_F13,	KC_F14,	KC_F15,	KC_F16, KC_F17,	KC_F18,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	KC_F23,	KC_F24,_______,     KC_P7,  KC_P8,  KC_P9,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,TG(_FCL),			KC_P4,  KC_P5,  KC_P6,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,			KC_P1,  KC_P2,  KC_P3,
        MO(_FCL),_______,_______,               _______,                        _______,DYN_MACRO_PLAY1,_______,MO(_FCL),   KC_PDOT,KC_P0,  KC_PENT
    ),

    [_FCL] = LAYOUT( // keymap _FCL: press Fn+Ctrl for macro layer, press Fn+Enter to swap to permanent secondary kb mode for macros (press Enter again to return to normal function)
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET,
        _______,_______,M_WORD, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,	MEMELNK,_______,KC_VOLU,
        _______,_______,SIGN,   DWNLOAD,_______,_______,_______,_______,_______,_______,_______,_______,TG(_BL),			DEL_ALL,PWR_DWN,TD(VDN_MUT),
        _______,_______,M_EXCEL,W_CALC, VLC,    _______,_______,_______,_______,_______,_______,        _______,			SCR_SAV,_______,SLEEP,
        _______,_______,_______,				KC_MPLY,                DYN_REC_STOP,DYN_REC_START1,    _______,_______,    KC_MPRV,_______,KC_MNXT
    )
};
