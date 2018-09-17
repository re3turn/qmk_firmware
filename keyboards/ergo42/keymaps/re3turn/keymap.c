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

#define LTSY_SPC LT(SYMB, KC_SPC)
#define LTME_ENT LT(META, KC_ENT)
#define IME LALT(KC_GRV)
#define CTLT_ESC CTL_T(KC_ESC)
#define SFTT_TAB SFT_T(KC_TAB)
#define GUI_TAB LGUI(KC_TAB)

#define CTLT_V CTL_T(KC_V)
#define SFTT_C SFT_T(KC_C)
#define ALTT_X ALT_T(KC_X)
#define GUIT_Z GUI_T(KC_Z)

#define CTLT_M RCTL_T(KC_M)
#define SFTT_COM RSFT_T(KC_COMM)
#define ALTT_DOT RALT_T(KC_DOT)
#define GUIT_SLS RGUI_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   `  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------+------|   |------+\-----+------+------+------+------+------|
 * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   ,  |   .  |   /  |  -   |
 * |      | /GUI | /Alt | /Sft | /Ctl |      |      |   |      |      | /Ctl | /Sft | /Alt | /GUI |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | IME  | Esc/ |Space/| Tab/ |   | BS   |Enter/| Del  | GUI+ | Alt  | GUI  |  \   |
 * |      |      |      |      | Ctl  |~SYMB | Sft  |   |      |~META |      | Tab  |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = LAYOUT( \
  KC_GRV,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,     KC_LBRC,  KC_RBRC, KC_Y,     KC_U,   KC_I,     KC_O,     KC_P,     KC_EQL, \
  KC_LALT, KC_A,    KC_S,    KC_D,   KC_F,     KC_G,     KC_LPRN,  KC_RPRN, KC_H,     KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
  KC_LSFT, GUIT_Z,  ALTT_X,  SFTT_C, CTLT_V,   KC_B,     KC_LCBR,  KC_RCBR, KC_N,     CTLT_M, SFTT_COM, ALTT_DOT, GUIT_SLS, KC_MINS, \
  KC_LCTL, KC_LGUI, KC_LALT, IME,    CTLT_ESC, LTSY_SPC, SFTT_TAB, KC_BSPC, LTME_ENT, KC_DEL, GUI_TAB,  KC_RALT,  KC_RGUI,  KC_BSLS \
),

/* META
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |  [   |   |  ]   |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |PtrScr| PgUp | Home | End  | PgDn |  (   |   |  )   | Left | Down |  Up  | Right| F11  | F12  |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  {   |   |  }   |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[META] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  _______, KC_PSCR, KC_PGUP, KC_HOME, KC_END,  KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,  KC_F12, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* SYMB
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  [   |   |  ]   |   ^  |   &  |   *  |   (  |   )  |   _  |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  (   |   |  )   |      |      |      |   {  |   }  |   +  |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  {   |   |  }   |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[SYMB] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PLUS, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

};

