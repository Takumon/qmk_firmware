/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

#define JP_MHEN KC_INT5 // Muhenkan (無変換)
#define JP_HENK KC_INT4 // Henkan (変換)

#define JP_DQUO S(KC_2) // "

#define JP_AMPR S(KC_6) // &
#define JP_QUOT S(KC_7) // '
#define JP_GRV S(KC_LBRC) // `
#define JP_EQL S(KC_MINS) // =
#define JP_COLN KC_QUOT // :

#define JP_BSLS KC_INT1 // (backslash)
#define JP_PLUS S(KC_SCLN) // +
#define JP_ASTR S(KC_QUOT) // *
#define JP_PIPE S(KC_INT3) // |

#define JP_AT KC_LBRC // @
#define JP_CIRC KC_EQL // ^
#define JP_TILD S(KC_EQL) // ~
#define JP_UNDS S(KC_INT1) // _

#define JP_LPRN S(KC_8) // (
#define JP_RPRN S(KC_9) // )
#define JP_LBRC KC_RBRC // [
#define JP_RBRC KC_NUHS // ]
#define JP_LCBR S(KC_RBRC) // {
#define JP_RCBR S(KC_NUHS) // }

#define WIN1 LGUI(KC_1)
#define WIN2 LGUI(KC_2)
#define WIN3 LGUI(KC_3)
#define WIN4 LGUI(KC_4)
#define WIN_LEFT LGUI(LCTL(KC_LEFT))
#define WIN_RGHT LGUI(LCTL(KC_RIGHT))
#define WIN_SCRNSHT LGUI(LSFT(KC_S))

enum custom_keycodes {
    UP5 = SAFE_RANGE,
    DOWN5,
    BSPCDEL,
};

enum {
  TD_HENKAN = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_HENKAN] = ACTION_TAP_DANCE_DOUBLE(JP_MHEN, JP_HENK),
};


// TODO 日本語の鉤括弧の入力
// TODO alt tab入力を簡単に
static uint8_t saved_mods = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LWIN,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  BSPCDEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, LT(3,KC_ENT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     KC_LALT, KC_LCTL, LT(2,KC_SPC),  LT(2,KC_ESC), LT(1,KC_SPC), TD(TD_HENKAN)
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LWIN, KC_EXLM, JP_DQUO, KC_HASH,  KC_DLR, KC_PERC,                        JP_AT,     UP5,   KC_UP, JP_CIRC, JP_TILD, BSPCDEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, JP_AMPR, JP_QUOT,  JP_GRV,  JP_EQL, JP_COLN,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, JP_BSLS, JP_PLUS, KC_MINS, JP_ASTR, JP_PIPE,                      BSPCDEL,  KC_F12,   DOWN5,   KC_F2,  JP_UNDS, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LCTL, KC_TRNS,    KC_TRNS, KC_TRNS, TD(TD_HENKAN)
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LWIN,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, BSPCDEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    WIN1,    WIN2,    WIN3,    WIN4,  KC_ENT,                      JP_LPRN, JP_RPRN, JP_LBRC, JP_RBRC, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, WIN_SCRNSHT,WIN_LEFT,WIN_RGHT,KC_F13,                    JP_LCBR, JP_RCBR,   KC_LT,   KC_GT, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LCTL, KC_TRNS,    KC_TRNS, KC_TRNS, TD(TD_HENKAN)
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LWIN, XXXXXXX,   KC_F2, XXXXXXX, XXXXXXX,   KC_F5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F10, BSPCDEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_VOLU, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LCTL, KC_TRNS,     KC_TRNS, KC_TRNS, TD(TD_HENKAN)
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  switch (keycode) {
        case UP5:
            if (record->event.pressed) {
                // five times
                tap_code(KC_UP);
                tap_code(KC_UP);
                tap_code(KC_UP);
                tap_code(KC_UP);
                tap_code(KC_UP);
            }
            return false;
        case DOWN5:
            if (record->event.pressed) {
                // five times
                tap_code(KC_DOWN);
                tap_code(KC_DOWN);
                tap_code(KC_DOWN);
                tap_code(KC_DOWN);
                tap_code(KC_DOWN);
            }
            return false;
        case BSPCDEL:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    saved_mods = get_mods() & MOD_MASK_SHIFT; // Mask off anything that isn't Shift
                    del_mods(saved_mods); // Remove any Shifts present
                    register_code(KC_DEL);
                } else {
                    saved_mods = 0; // Clear saved mods so the add_mods() below doesn't add Shifts back when it shouldn't
                    register_code(KC_BSPC);
                }
            } else {
                add_mods(saved_mods);
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
            }
            return false;
    }
  return true;
}
#endif // OLED_ENABLE
