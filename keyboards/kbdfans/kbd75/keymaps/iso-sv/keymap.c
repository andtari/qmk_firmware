#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define _BL 0
#define _FL 1

enum {
  M_EMAIL = SAFE_RANGE,
  M_OTHER
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed){
    switch(keycode) {
      case M_EMAIL:
        SEND_STRING("youremail"SS_RALT("2")"youremail.com");
        return false; break;
      case M_OTHER:
        SEND_STRING("The Other Macro");
        return false; break;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap 0: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc |F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|PSCR|FN |Del|
   * |----------------------------------------------------------------|
   * |§   | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  +|  ´| Bksp   |Hme|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  Å|  ¨| Ent-|End |
   * |-------------------------------------------------------| er|----|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ö|  Ä| ' |   |PgUp|
   * |----------------------------------------------------------------|
   * |Shif| <>|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  -| Shift| Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |Cmd |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */

	[_BL] = LAYOUT_iso_1u(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_PAUS,  KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,             KC_BSPC,  KC_HOME,
    KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,   KC_END,
    KC_LCTL,            KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  NO_APOS,            KC_PGUP,
    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_PGDN,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                           KC_RALT,  MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |Esc |F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|PSCR|FN |   |
   * |----------------------------------------------------------------|
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |  RESET|    |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |    |
   * |------------------------------------------------------|    |----|
   * |      |<- |Dn | ->|   |   |   |   |   |   |   |   |   |    |    |
   * |----------------------------------------------------------------|
   * |    |   |   |   |Bl-|BL |BL+|   |VU-|VU+|MUT|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */

	[_FL] = LAYOUT_iso_1u(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            RESET,    _______,
    _______,            _______,  _______,  M_EMAIL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,            RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,            KC_BTN1,  KC_MS_U,  KC_BTN2,
    _______,  _______,  _______,                      _______,                                          _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R
  )
};
