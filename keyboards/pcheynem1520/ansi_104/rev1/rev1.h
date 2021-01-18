#ifndef REV1_H
#define REV1_H

#pragma once
#include "quantum.h"

#define LAYOUT_104_ANSI( \
	K000,       K002, K003, K004, K005,       K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017,                         \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114, K115, K116, K117, K118, K119, K120, K121, \
	K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220,       \
	K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313,                         K318, K319, K320, K321, \
	      K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411,       K413,             K416,       K418, K419, K420,       \
	K500, K501,       K503,             K506,                   K510, K511,       K513, K514, K515, K516, K517,       K519, K520, K521  \
) { \
	{ K000,  KC_NO, K002,  K003,  K004,  K005,  KC_NO, K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014,  K015,  K016,  K017,  KC_NO, KC_NO, KC_NO, KC_NO }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  KC_NO, K114,  K115,  K116,  K117,  K118,  K119,  K120,  K121 }, \
	{ K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  K214,  K215,  K216,  K217,  K218,  K219,  K220,  KC_NO }, \
	{ K300,  KC_NO, K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  K313,  KC_NO, KC_NO, KC_NO, KC_NO, K318,  K319,  K320,  K321 }, \
	{ KC_NO, K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  KC_NO, K413,  KC_NO, KC_NO, K416,  KC_NO, K418,  K419,  K420,  KC_NO }, \
	{ K500,  K501,  KC_NO, K503,  KC_NO, KC_NO, K506,  KC_NO, KC_NO, KC_NO, K510,  K511,  KC_NO, K513,  K514,  K515,  K516,  K517,  KC_NO, K519,  K520,  K521 }  \
}

#endif
