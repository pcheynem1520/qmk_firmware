/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
  LIN_BASE,
  LIN_FN,
  WIN_BASE,
  WIN_FN,
  WIN_FNCL
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

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
                SEND_STRING(SS_LCTL("a") SS_TAP(X_DEL));
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
                SEND_STRING(SS_LGUI("x") SS_DELAY(200) "uu");
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
                SEND_STRING("\n\n\nAll the best,\n\nPJ (He/They)");
            } else { // when keycode SIGN is released
            } break;

		/* put machine to sleep */
        case SLEEP:
            if (record->event.pressed) { // when keycode SLEEP is pressed
                SEND_STRING(SS_LGUI("x") SS_DELAY(200) "us");
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
    CAPS        // only caps lock on double tap
};

/* Tap Dance definitions */
tap_dance_action_t tap_dance_actions[] = {
    [CAPS] = ACTION_TAP_DANCE_DOUBLE(_______, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    transparent template layer
    [BLANK] = LAYOUT_ansi_98(
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,           _______,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,           _______,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,           _______,   _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,           _______,   _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______, _______,   _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______, _______,   _______,  _______,  _______),
    */

    [LIN_BASE] = LAYOUT_ansi_98(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,    KC_VOLD,  KC_VOLU,            KC_DEL,   KC_HOME,  KC_END,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  MO(LIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,  KC_PENT),
    [LIN_FN] = LAYOUT_ansi_98(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,             _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______),



    [WIN_BASE] = LAYOUT_ansi_98(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,             KC_DEL,   KC_PGUP,  KC_PGDN,  KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_P7,    KC_P8,    KC_P9,
        CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_98(
        DM_RSTP,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,    KC_VOLD,  KC_VOLU,            _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,
        KC_CAPS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                DM_REC1,                                DM_PLY1,  _______,MO(WIN_FNCL),_______,  _______,  _______,  _______,  _______,  _______),
    [WIN_FNCL] = LAYOUT_ansi_98(
        _______,             KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,    KC_F23,    KC_F24,           DEL_ALL,   _______,  SLEEP,    PWR_DWN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,           _______,   _______,  _______,  _______,
        _______,  _______,  M_WORD,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,           _______,   _______,  _______,
        _______,  _______,  SIGN,     DWNLOAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,           _______,   _______,  _______,  _______,
        _______,            ZOOM,     M_EXCEL,  W_CALC,   VLC,      _______,      NPP,  MEMELNK,  _______,  _______,  COMMENT,              _______,  _______, _______,   _______,  _______,
        _______,  _______,  _______,                                DM_REC2,                                DM_PLY2,  _______,    _______,  _______,  _______, _______,   _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_FNCL] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE
