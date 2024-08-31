#include "rev1.h"           // physical matrix
#include "tklish.h"         // matrix_scan_user(), initialization functions, and custom keycodes

enum userspace_layers {
    _BL = 0,    // base Layer
    _FL = 1,    // Fn Layer (for keys' second functions)
    _FRCL = 2,   // Fn+RCtrl Layer (for quick-access macros)
    _FLCL = 3,   // Fn+RCtrl Layer (for extremely specific macros)
};

/* enum of custom keycodes defined in process_record_user */
/* TODO: convert all macros to linux equivalents */
enum keycodes { // macro declatations
    COMMENT = SAFE_RANGE,   // create block comment
    DEL_ALL,                // delete all
    DWNLOAD,                // open Downloads folder
    MEMELNK,                // "64-bit" video link
    M_EXCEL,                // open Microsoft Excel
    M_WORD,                 // open Microsoft Word
    NPP,                    // open notpad++
    PWR_DWN,                // power off
    QMK_HOM,                // cd to home directory of qmk_firmware
    QMK_SYN,                // sync all qmk_firmware repos
    SIGN,                   // email signature
    SLEEP,                  // sleep
    STARTUP,                // set up school computers for use
    W_CALC,                 // default Windows calculator
    VLC,                    // VLC media player
    ZOOM                    // open zoom web meetings
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // custom keycode definitions i.e. macros
    switch (keycode) {
        /* create C/C++ block comment */
        case COMMENT:
            if (record->event.pressed) { // when keycode COMMENT is pressed
                SEND_STRING("/*  */" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)); // type block comment strings
            } else { // when keycode COMMENT is released
            } break;

        /* delete all text in current text box */
        case DEL_ALL:
            if (record->event.pressed) { // when keycode DEL_ALL is pressed
                SEND_STRING(SS_DOWN(X_LCTRL) "a" SS_UP(X_LCTRL) SS_TAP(X_DEL));
            } else { // when keycode DEL_ALL is released
            } break;

		/* open Downloads folder */
        case DWNLOAD:
            if (record->event.pressed) { // when keycode DWNLOAD is pressed
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(250) "Downloads" SS_DELAY(250) SS_TAP(X_ENT)); // open Downloads folder
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
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(250) "excel" SS_DELAY(250) SS_TAP(X_ENT)); // open Excel
            } else { // when keycode M_EXCEL is released
            } break;

		/* open Word */
        case M_WORD:
            if (record->event.pressed) { // when keycode M_WORD is pressed
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(250) "word" SS_DELAY(250) SS_TAP(X_ENT)); // open Word
            } else { // when keycode M_WORD is released
            } break;

        /* open Notepad++ */
        case NPP:
            if (record->event.pressed) { // when keycode NPP is pressed
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(250) "notepad++" SS_DELAY(250) SS_TAP(X_ENT)); // open Notepad++
            } else { // when keycode NPP is released
            } break;

		/* turn off machine */
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

		/* email signature */
        case SIGN:
            if (record->event.pressed) { // when keycode SIGN is pressed
                SEND_STRING("\n\n\nAll the best,\n\nPJ Cheyne-Miller\n(He/Him)\n0886276\n200416896\n");
            } else { // when keycode SIGN is released
            } break;

		/* put machine to sleep */
        case SLEEP:
            if (record->event.pressed) { // when keycode SLEEP is pressed
                SEND_STRING(SS_DOWN(X_LGUI) "x" SS_UP(X_LGUI) SS_DELAY(200) "us");
            } else { // when keycode SLEEP is released
            } break;

		/* manual startup procedures */
        case STARTUP:
            if (record->event.pressed) { // when keycode STARTUP is pressed
            /* TODO: convert to work startup
                SEND_STRING(SS_DOWN(X_LGUI) "r" SS_UP(X_LGUI) SS_DELAY(250) "msedge" SS_TAP(X_ENT)); // open edge
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) "n" SS_UP(X_LCTL) SS_UP(X_LSFT) SS_DELAY(100) SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT) SS_DOWN(X_LALT) SS_TAP(X_F4) SS_UP(X_LALT)); // open incognito window and close main window
                SEND_STRING(SS_DOWN(X_LCTL) "l" SS_UP(X_LCTL) "drive.google.com" SS_TAP(X_ENT) SS_DELAY(100)); // open Google Drive
                SEND_STRING(SS_DOWN(X_LCTL) "t" SS_UP(X_LCTL) "mycourselink.lakeheadu.ca"); // open D2L

                SEND_STRING(SS_DOWN(X_LGUI) "e" SS_UP(X_LGUI) SS_DELAY(100)); // open windows explorer
                SEND_STRING(SS_DOWN(X_LCTL) "l" SS_UP(X_LCTL) "C:\\Users\\200416896\\Documents" SS_TAP(X_ENT) SS_DELAY(250)); // Navigate to Documents directory

                SEND_STRING(SS_DOWN(X_LGUI) "e" SS_UP(X_LGUI) SS_DELAY(100)); // open windows explorer
                SEND_STRING(SS_DOWN(X_LCTL) "l" SS_UP(X_LCTL) "D:\\University\\2021-2022\\Semester 1" SS_TAP(X_ENT)); // Navigate to USB drive directory
            */
            } else { // when keycode STARTUP is released
            } break;

		/* open calculator */
        case W_CALC:
            if (record->event.pressed) { // when keycode W_CALC is pressed
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(250) "calc" SS_DELAY(250) SS_TAP(X_ENT)); // open Windows calculator
            } else { // when keycode W_CALC is released
            } break;

		/* open VLC media player */
        case VLC:
            if (record->event.pressed) { // when keycode VLC is pressed
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(250) "vlc" SS_DELAY(250) SS_TAP(X_ENT)); // open VLC media player
            } else { // when keycode VLC is released
            } break;

		/* open Zoom */
        case ZOOM:
            if (record->event.pressed) { // when keycode ZOOM is pressed
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(250) "zoom" SS_DELAY(250) SS_TAP(X_ENT)); // open Zoom video meetings
            } else { // when keycode ZOOM is released
            } break;
    } return true;
};

/* Tap Dance declarations */
enum {
    VDN_MUT,    // tap once for KC_VOLD, twice for KC_MUTE
    CAPS        // only caps lock on double tap
};

/* Tap Dance definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    [VDN_MUT] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
    [CAPS] = ACTION_TAP_DANCE_DOUBLE(_______, KC_CAPS)
};

/* keyboard layers */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT( // keymap _BL: Base Layer (Default)
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,    KC_INS, KC_HOME,KC_PGUP,
        _______,KC_A,   KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,KC_QUOT,        KC_ENT,		KC_DEL, KC_END, KC_PGDN,
	    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,            KC_PSCR,KC_UP,  KC_PAUS,
        KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                         KC_RALT,KC_RGUI,        MO(_FL),KC_RCTL,    KC_LEFT,KC_DOWN,KC_RGHT
    ),

    [_FL] = LAYOUT( // keymap _FL: Fn Layer
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,	KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,_______,
        _______,KC_F13,	KC_F14,	KC_F15,	KC_F16, KC_F17,	KC_F18,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	KC_F23,	KC_F24,_______,     KC_P7,  KC_P8,  KC_P9,
        TD(CAPS),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,TG(_FRCL),			KC_P4,  KC_P5,  KC_P6,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,			KC_P1,  KC_P2,  KC_P3,
        MO(_FLCL),_______,_______,              _______,                        _______,DYN_MACRO_PLAY1,_______,MO(_FRCL),  KC_PDOT,KC_P0,  KC_PENT
    ),

    [_FRCL] = LAYOUT( // keymap _FRCL: press Fn+RCtrl for macro layer, press Fn+Enter to swap to permanent secondary kb mode for macros (press Enter again to return to normal function)
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,QMK_HOM,M_WORD, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,	MEMELNK,STARTUP,KC_VOLU,
        KC_NUM, _______,SIGN,   DWNLOAD,_______,_______,_______,_______,_______,_______,_______,_______,TG(_BL),			DEL_ALL,PWR_DWN,TD(VDN_MUT),
        _______,_______,M_EXCEL,W_CALC, VLC,    _______,NPP,    _______,_______,_______,COMMENT,        _______,			_______,QMK_SYN,SLEEP,
        _______,_______,_______,				KC_MPLY,                    DYN_REC_STOP,DYN_REC_START1,_______,_______,    KC_MPRV,_______,KC_MNXT
    ),

    [_FLCL] = LAYOUT( // keymap _FLCL: press Fn+LCtrl for macro layer
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,			_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,			_______,_______,_______,
        _______,_______,_______,				_______,                        _______,_______,_______,_______,            _______,_______,_______
    )
};
