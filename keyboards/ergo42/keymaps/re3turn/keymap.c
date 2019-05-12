#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Tap Dance Declarations
enum {
  TD_LBRC_LCBR = 0,
  TD_RBRC_RCBR,
  TD_SCLN_COLN,
  TD_QUOT_DQT,
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_LCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRC_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  [TD_SCLN_COLN]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  [TD_QUOT_DQT]   = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
};

#define _BASE 0
#define _LOWER 1
#define _RAISE 2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LTLO_SPC LT(_LOWER, KC_SPC)
#define LTRA_ENT LT(_RAISE, KC_ENT)
#define LTLO_BS LT(_LOWER, KC_BSPC)
#define IME LALT(KC_GRV)
#define CTLT_ESC CTL_T(KC_ESC)
#define SFTT_TAB SFT_T(KC_TAB)
#define GUI_TAB LGUI(KC_TAB)
#define GUI_SPC LGUI(KC_SPC)
#define TD_LBRC TD(TD_LBRC_LCBR)
#define TD_RBRC TD(TD_RBRC_RCBR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |GUISPC|   Q  |   W  |   E  |   R  |   T  |  (   |   |  )   |   Y  |   U  |   I  |   O  |   P  |PtrScr|
 * |------+------+------+------+------+------+------|   |------+\-----+------+------+------+------+------|
 * | Alt  |   A  |   S  |   D  |   F  |   G  |  [   |   |  ]   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |  `   |   |  =   |   N  |   M  |   ,  |   .  |   /  |  -   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | IME  | Esc/ |Space/| Tab/ |   | BS/  |Enter/| Del  | GUI+ | Alt  | GUI  |  \   |
 * |      |      |      |      | Ctrl |~Lower| Shift|   |~Lower|~Raise|      | Tab  |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[_BASE] = LAYOUT( \
  GUI_SPC, KC_Q,    KC_W,    KC_E, KC_R,     KC_T,     KC_LPRN,  KC_RPRN,  KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_PSCR, \
  KC_LALT, KC_A,    KC_S,    KC_D, KC_F,     KC_G,     TD_LBRC,  TD_RBRC,  KC_H,     KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V,     KC_B,     KC_GRV,   KC_EQL,   KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
  KC_LCTL, KC_LGUI, KC_LALT, IME,  CTLT_ESC, LTLO_SPC, SFTT_TAB, LTLO_BS,  LTRA_ENT, KC_DEL, GUI_TAB, KC_RALT, KC_RGUI, KC_BSLS \
),

/* Lower
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |      |      |      | PgUp | Home |      |      |   |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |      | PgDn | End  |      |      |   |      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[_LOWER] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX \
),

/* Raise
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |      |   |      |   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |  {   |   |   }  |   ^  |   &  |   *  |   (  |   )  |  F12 |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  ~   |   |   +  |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |   |  |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[_RAISE] = LAYOUT( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TILD, KC_PLUS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE \
),

};

