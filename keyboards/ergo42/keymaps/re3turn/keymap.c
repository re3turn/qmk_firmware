#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   `  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  @   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |   =  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   ,  |   .  |   /  |  -   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | IME  |ESC/  |Space/|Tab/  |   | BS/  |Enter/| Del  | GUI+ |=>META|=>SYMB|  \   |
 * |      |      |      |      |~SYMB |Ctrl  |Shift |   | Alt  |~META |      | Tab  |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = KEYMAP( \
  KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_AT, \
  KC_EQL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN, KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR, KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
  KC_LCTRL, KC_LGUI, KC_LALT, LALT(KC_GRV), LT(SYMB, KC_ESC), RCTL_T(KC_SPC), SFT_T(KC_TAB), ALT_T(KC_BSPC), LT(META, KC_ENT), KC_DEL, LGUI(KC_TAB), TG(META), TG(SYMB), KC_BSLS \
),

/* META
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |  [   |   |  ]   |   7  |   8  |   9  |   0  |   -  |  =   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      | PgUp | Home | End  | PgDn |  (   |   |  )   | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | IME  |ESC/  |Space/|Tab/  |   | BS/  |Enter/| Del  | GUI+ |=>META|=>SYMB|      |
 * |      |      |      |      |~SYMB |Ctrl  |Shift |   | Alt  |~META |      | Tab  |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[META] = KEYMAP( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    _______, _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
  XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, KC_END,  KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
  KC_F1  , KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX \
),

/* SYMB
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |  [   |   |  ]   |   &  |   *  |   (  |   )  |   _  |  +   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  (   |   |  )   |      |      |      |      |   {  |  }   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |  {   |   |  }   |      |      |   <  |   >  |   ?  |  _   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | IME  |ESC/  |Space/|Tab/  |   | BS/  |Enter/| Del  | GUI+ |=>META|=>SYMB|  |   |
 * |      |      |      |      |~SYMB |Ctrl  |Shift |   | Alt  |~META |      | Tab  |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[SYMB] = KEYMAP( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_QUES, KC_UNDS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE \
),

};

