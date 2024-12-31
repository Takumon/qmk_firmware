/* SPDX-License-Identifier: GPL-2.0-or-later */



#include QMK_KEYBOARD_H

///////////////////////////////
// Windows
///////////////////////////////

// #define JP_MHEN KC_INT5 // Muhenkan (無変換)
// #define JP_HENK KC_INT4 // Henkan (変換)

// #define JP_DQUO S(KC_2) // "

// #define JP_AMPR S(KC_6) // &
// #define JP_QUOT S(KC_7) // '
// #define JP_GRV S(KC_LBRC) // `
// #define JP_EQL S(KC_MINS) // =
// #define JP_COLN KC_QUOT // :

// #define JP_BSLS KC_INT1 // (backslash)
// #define JP_PLUS S(KC_SCLN) // +
// #define JP_ASTR S(KC_QUOT) // *
// #define JP_PIPE S(KC_INT3) // |

// #define JP_AT KC_LBRC // @
// #define JP_CIRC KC_EQL // ^
// #define JP_TILD S(KC_EQL) // ~
// #define JP_UNDS S(KC_INT1) // _

// #define JP_LPRN S(KC_8) // (
// #define JP_RPRN S(KC_9) // )
// #define JP_LBRC KC_RBRC // [
// #define JP_RBRC KC_NUHS // ]
// #define JP_LCBR S(KC_RBRC) // {
// #define JP_RCBR S(KC_NUHS) // }



///////////////////////////////
// Mac
///////////////////////////////

#define JP_MHEN KC_LANGUAGE_2  // 英数
#define JP_HENK KC_LANGUAGE_1 // かな

#define JP_DQUO S(KC_QUOT) // "

#define JP_AMPR S(KC_7) // &
#define JP_QUOT KC_QUOT // '
#define JP_GRV KC_GRV // `
#define JP_EQL KC_EQL // =
#define JP_COLN S(KC_SCLN) // :

#define JP_BSLS KC_NUHS // (backslash)
#define JP_PLUS S(KC_EQL) // +
#define JP_ASTR S(KC_8) // *
#define JP_PIPE S(KC_NUHS) // |

#define JP_AT S(KC_2) // @
#define JP_CIRC KC_CIRC // ^

#define JP_TILD S(KC_GRV) // ~
#define JP_UNDS S(KC_MINS) // _

#define JP_LPRN S(KC_9) // (
#define JP_RPRN S(KC_0) // )
#define JP_LBRC KC_LBRC // [

#define JP_RBRC KC_RBRC // ]
#define JP_LCBR S(KC_LBRC) // {
#define JP_RCBR S(KC_RBRC) // }



///////////////////////////////
// common
///////////////////////////////

#define WIN1 LGUI(KC_1)
#define WIN2 LGUI(KC_2)
#define WIN3 LGUI(KC_3)
#define WIN4 LGUI(KC_4)
#define WIN5 LGUI(KC_5)

#define WIN_TAB LGUI(KC_TAB)


#define WIN_UP LGUI(KC_UP)
#define WIN_DOWN LGUI(KC_DOWN)
#define WIN_RIGHT LGUI(KC_RIGHT)
#define WIN_LEFT LGUI(KC_LEFT)

#define DISP_RIGHT LGUI(LSFT(KC_RIGHT))
#define DISP_LEFT LGUI(LSFT(KC_LEFT))


#define WIN_SCR LGUI(LSFT(KC_S))
#define WIN_E LGUI(KC_E)
#define WIN_V LGUI(KC_V)

#define WIN_NXT LGUI(LCTL(KC_RIGHT))
#define WIN_PRV LGUI(LCTL(KC_LEFT))
#define APP_NXT LALT(KC_ESC)
#define APP_PRV LALT(LSFT(KC_ESC))
#define APP_END LALT(KC_F4)
#define TAB_NXT LCTL(KC_TAB)
#define TAB_PRV LCTL(LSFT(KC_TAB))
#define TAB_END LCTL(KC_W)

#define LSLP MT(MOD_LSFT, JP_LBRC)  // タップで[   全角時「   ホールドで左Shift
#define RSRP MT(MOD_RSFT, JP_RBRC)  // タップで]   全角時 」  ホールドで右Shift

#define WIN_ENT LGUI_T(KC_ENT)
#define ALT_SPC LALT(KC_SPACE)

#define CTRL_Z LCTL(KC_Z)
#define CTRL_X LCTL(KC_X)
#define CTRL_C LCTL(KC_C)
#define CTRL_V LCTL(KC_V)

#define HIS_NEXT LALT(KC_RIGHT)
#define HIS_PREV LALT(KC_LEFT)


enum custom_keycodes {
    UP5 = SAFE_RANGE,
    DOWN5,
    BSPC_DEL,
    SCLN_CLN,
    // MacのHomeとEndだとぶっ飛んでしまうので、Win風のHOMEキーにカスタマイズ
    MC_HOME,
    MC_END
};



enum {
    TD_APP_END,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_APP_END] = ACTION_TAP_DANCE_DOUBLE(XXXXXXX, APP_END),
};

enum combos {
    COMBO1,
    COMBO2,
    COMBO3,
    COMBO4,
    COMBO5,
    COMBO6,
};

const uint16_t PROGMEM combo1[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM combo5[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo6[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO1] = COMBO(combo1, JP_MHEN),
  [COMBO2] = COMBO(combo2, KC_ENT),
  [COMBO3] = COMBO(combo3, WIN1),
  [COMBO4] = COMBO(combo4, ALT_SPC),

  [COMBO5] = COMBO(combo5, JP_HENK),
  [COMBO6] = COMBO(combo6, OSM(MOD_RSFT)),
};


enum layer_number {
  _DEFAULTS = 0,
  _SYMBOL,
  _WINDOW,
  _NUM_CURSOR,
  _MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULTS] = LAYOUT(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, BSPC_DEL,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,SCLN_CLN,  KC_ENT,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_PAGE_DOWN,   KC_PAGE_UP,     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, JP_UNDS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                KC_LCTL, KC_LGUI, MO(_SYMBOL), LT(_WINDOW,KC_SPC),   LT(_MOUSE,KC_ESC), LT(_NUM_CURSOR,KC_SPC),   KC_RSFT, KC_RGUI // WinからMacへの変更に伴い GUIとCTRLは入れ替え
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
  ),

  // 記号
  // !~#$%   `{}<
  // \^&|@   "()>"
  // *+-_=   '[]
  [_SYMBOL] = LAYOUT(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, KC_EXLM, JP_TILD, KC_HASH,  KC_DLR, KC_PERC,                    JP_GRV,  JP_LCBR, JP_RCBR,   KC_LT, XXXXXXX,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, JP_BSLS, JP_CIRC, JP_AMPR, JP_PIPE,   JP_AT,                   JP_DQUO, JP_LPRN, JP_RPRN,   KC_GT,  KC_END,  KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, JP_ASTR, JP_PLUS, KC_MINS, JP_UNDS,  JP_EQL,KC_TRNS,  KC_TRNS, JP_QUOT,  JP_LBRC, JP_RBRC, XXXXXXX,  XXXXXXX, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
  ),

  [_WINDOW] = LAYOUT(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, XXXXXXX, XXXXXXX, TAB_PRV, TAB_NXT, TAB_END,                   XXXXXXX,DISP_LEFT, WIN_UP,DISP_RIGHT, XXXXXXX, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, XXXXXXX,   WIN_E, APP_PRV, APP_NXT, TD(TD_APP_END),            WIN_TAB,WIN_LEFT,WIN_DOWN,WIN_RIGHT,XXXXXXX, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, XXXXXXX, WIN_SCR, WIN_PRV, WIN_NXT,   WIN_V, KC_TRNS, KC_TRNS,    WIN1,    WIN2,    WIN3,    WIN4,    WIN5, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
  ),

  [_NUM_CURSOR] = LAYOUT(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   XXXXXXX,     UP5,   KC_UP, XXXXXXX, XXXXXXX, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   MC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  MC_END, KC_TRNS,  // HOME, ENDはカスタマイズキーを使用
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS,  CTRL_Z,  CTRL_X,  CTRL_C,  CTRL_V, XXXXXXX, KC_TRNS, KC_TRNS,BSPC_DEL,  KC_F12,   DOWN5,  KC_F2,  XXXXXXX, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
  ),

  [_MOUSE] = LAYOUT(
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_WH_L, KC_MS_U, XXXXXXX, KC_VOLU, KC_VOLD, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, XXXXXXX, XXXXXXX,LCTL(KC_BTN1),KC_BTN1,KC_BTN2,                KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
    KC_TRNS, XXXXXXX, XXXXXXX,HIS_PREV, HIS_NEXT, XXXXXXX,KC_TRNS, KC_TRNS,  KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, KC_TRNS,
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
                               KC_TRNS, KC_TRNS, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//+--------+--------+--------+--------+--------+--------+                 +--------+--------+--------+--------+--------+--------+
  ),
};

// void keyboard_post_init_user(void) {
//   rgblight_enable_noeeprom();
//   rgblight_sethsv_noeeprom(128, 255, rgblight_get_val());
//   rgblight_mode_noeeprom(1);
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//   switch (get_highest_layer(state)) {
//     case 1: //PURPLE
//       rgblight_sethsv_noeeprom(191, 255, rgblight_get_val());
//       break;
//     case 2: //GREEN
//       rgblight_sethsv_noeeprom(85, 255, rgblight_get_val());
//       break;
//     case 3: //YELLOW
//       rgblight_sethsv_noeeprom(43, 255, rgblight_get_val());
//       break;
//     default: //CYAN
//       rgblight_sethsv_noeeprom(128, 255, rgblight_get_val());
//       break;
//   }
//   return state;
// }

static uint8_t saved_mods = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

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
        case BSPC_DEL:
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
        case SCLN_CLN:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    saved_mods = get_mods() & MOD_MASK_SHIFT; // Mask off anything that isn't Shift
                    register_code(KC_SCLN);
                } else {
                    saved_mods = 0; // Clear saved mods so the add_mods() below doesn't add Shifts back when it shouldn't
                    register_code(KC_SCLN);
                }
            } else {
                del_mods(saved_mods); // Remove any Shifts present
                // unregister_code(JP_COLN);
                unregister_code(KC_SCLN);
            }
            return false;
        // MacのHomeとEndだとぶっ飛んでしまうので、Win風のHOMEキーにカスタマイズ
        case MC_HOME:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
            }
            return false;
        case MC_END:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_RGHT);
                unregister_code(KC_LGUI);
            }
            return false;
    }
  return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        // case JP_UNDS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;
    }
}
