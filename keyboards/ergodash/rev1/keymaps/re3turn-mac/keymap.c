#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

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

#define XXXXXXX KC_NO
#define _______ KC_TRNS
#define LTAD_GUI LT(_ADJUST, KC_RGUI)
#define LTLO_SPC LT(_LOWER, KC_SPC)
#define LTLO_BS LT(_LOWER, KC_BSPC)
#define LTRA_ENT LT(_RAISE, KC_ENT)
#define IME LCTL(KC_SPC)
#define CMDT_ESC CMD_T(KC_ESC)
#define SFTT_TAB SFT_T(KC_TAB)
#define CMD_TAB LGUI(KC_TAB)
#define CMD_SPC LGUI(KC_SPC)
#define TD_LBRC TD(TD_LBRC_LCBR)
#define TD_RBRC TD(TD_RBRC_RCBR)
#define TD_SCLN TD(TD_SCLN_COLN)
#define TD_QUOT TD(TD_QUOT_DQT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------.
   * |CMDSPC|   1  |   2  |   3  |   4  |   5  |   (  |              |   )  |   6  |   7  |   8  |   9  |   0  |PtrScr|
   * |------+------+------+------+------+------+------+--------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |              |   ]  |   Y  |   U  |   I  |   O  |   P  |  =   |
   * |------+------+------+------+------+------+------+--------------+------+------+------+------+------+------+------|
   * | Cmd  |   A  |   S  |   D  |   F  |   G  |   `  |              |   =  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  IME |              |   \  |   N  |   M  |   ,  |   .  |   /  |  -   |
   * |-------------+------+------+------+------+------+------++------+------+------+------+------+------+-------------|
   * | Ctrl |  Opt |  Cmd | Esc/ ||||||||Space/| Tab/ |      ||      | BS/  |Enter/||||||||  Del | Cmd+ | Cmd/ |  Opt |
   * |      |      |      | Ctrl ||||||||~Lower| Shift|      ||      |~Lower|~Raise||||||||      | Tab  |~Adjst|      |
   * ,----------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    CMD_SPC, KC_1,    KC_2,    KC_3,    KC_4, KC_5,     KC_LPRN,                        KC_RPRN, KC_6,     KC_7, KC_8,    KC_9,    KC_0,     KC_PSCR, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R, KC_T,     TD_LBRC,                        TD_RBRC, KC_Y,     KC_U, KC_I,    KC_O,    KC_P,     KC_EQL, \
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F, KC_G,     KC_GRV,                         KC_EQL,  KC_H,     KC_J, KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V, KC_B,     IME,                            KC_BSLS, KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH,  KC_MINS, \
    KC_LCTL, KC_LALT, KC_LGUI, CMDT_ESC,      LTLO_SPC, SFTT_TAB, XXXXXXX,     XXXXXXX, LTLO_BS, LTRA_ENT,       KC_DEL,  CMD_TAB, LTAD_GUI, KC_LALT \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |              |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------+------+------+------+------+------+------+------|
   * |      |      |      | PgUp | Home |      |      |              |      |      |      |  Up  |      |      |      |
   * |------+------+------+------+------+------+---------------------+------+------+------+------+------+------+------|
   * |      |      |      | PgDn | End  |      |      |              |      |      | Left | Down | Right|      |      |
   * |------+------+------+------+------+------+------+--------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |              |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------++------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, _______, _______, _______,          _______, _______, _______,     _______, _______, _______,          _______, _______, _______, _______ \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |      |              |      |  ^   |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------+------+--------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |   {  |              |   }  |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+---------------------+------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |   ~  |              |   +  |   ^  |   &  |   *  |   (  |   )  |  F12 |
   * |------+------+------+------+------+------+------+--------------+------+------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |              |   |  |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
   * |-------------+------+------+------+------+------+------++------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LCBR,                        KC_RCBR, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        KC_PIPE, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    _______, _______, _______, _______,          _______, _______, _______,     _______, _______, _______,          _______, _______, _______, _______ \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |              |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |              |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |              |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |              |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------++------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
