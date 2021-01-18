#include "rev1.h" // Physical matrix
#include "tklish.h" // matrix_scan_user(), initialization functions, and custom keycodes

/* Tap Dance declarations */
enum {
    MAC_2, // Macro 2: tap once for MAC_2A, twice for MAC_2B
    MAC_6, // Macro 6: tap once for KC_VOLD, twice for KC_MUTE
};

/* Tap Dance definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    [MAC_2] = ACTION_TAP_DANCE_DOUBLE(MAC_2A, MAC_2B),
    [MAC_2] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
};

/* keyboard layers */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = KC_OUT(  // keymap _BL: Base Layer (Default)
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,         KC_BSPC,
        KC_TAB,         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,    KC_INS, KC_HOME,KC_PGUP,
        KC_CAPS,        KC_A,   KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,KC_QUOT,KC_ENT,				KC_DEL, KC_END, KC_PGDN,
	            KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,            KC_PSCR,KC_UP,  KC_PAUS,
        KC_LCTL,KC_LGUI,        KC_LALT,                KC_SPC,                 KC_RALT,KC_LGUI,        MO(_FL),        KC_RCTL,    KC_LEFT,KC_DOWN,KC_RGHT
    ),

    [_FL] = KC_OUT(  // keymap _FL: Fn Layer
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,	KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,         _______,
        _______,        KC_F13,	KC_F14,	KC_F15,	KC_F16, KC_F17,	KC_F18,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	KC_F23,	KC_F24, _______,	KC_7,   KC_8,   KC_9,
        _______,        _______,_______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,			KC_4,   KC_5,   KC_6,
	            _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,			KC_1,   KC_2,   KC_3,
        MO(_CFL),_______,        _______,				KC_MPLY,				_______,DYN_MACRO_PLAY1, _______,	    MO(_CFL),	KC_PDOT, KC_0,  KC_EQL
    ),

    [_CFL] = KC_OUT(  // keymap _CFL: Ctrl+Fn Layer
        RESET, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,
        _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,	MAC_1,TD(MAC_2),MAC_3,
        _______,        _______,MAC_SIGN,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,			MAC_4,  MAC_5,  TD(MAC_6),
	            _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,			MAC_7,  MAC_8,  MAC_9,
        _______,_______,        _______,				_______,				_______,DYN_REC_START1,_______,	        _______,    MAC_10, MAC_11, MAC_12
    )
};
