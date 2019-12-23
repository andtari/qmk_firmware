#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define _BL 0
#define _FL 1

// Macros
// name macros here for keymap reference
enum {
  EMAIL_ADD = SAFE_RANGE,
  OTHER_MACRO
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed){
    switch(keycode) {
      case EMAIL_ADD:
        SEND_STRING("youremail"SS_RALT("2")"youremail.com");
        return false; break;
      case OTHER_MACRO:
        SEND_STRING("The Other Macro");
        return false; break;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* This layout starts from a standard ISO 60% layout, and adds a function layer.
   *
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐2d  │
   * │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │1e │    │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬──┴────┤
   * │30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │3a │3c    │3d │3e │
   * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬───┼───┼───┤
   * │40  │41  │43  │44      │46  │48        │4a │4b │4c │4d │4e │
   * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
   *   
   * ,-----------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  +|  ´|Backspa|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  Å|  ¨| Ent-|
   * |-------------------------------------------------------| er|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ö|  Ä| ' |   |
   * |------------------------------------------------------------
   * |Shif| <>|  Z|  X|  C|  V|  B|  N|  M|  ,|  .| Shift| Up|  -|
   * |------------------------------------------------------------
   * |Ctrl|Win |Alt |        Space          |Alt| FN| Lef|Dow|Rig|
   * `------------------------------------------------------------
   * 
   */
   [_BL] = LAYOUT_60_b_iso(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_BSPC,
    KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, 
    KC_LCTL,            KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_BSLS,  KC_ENT,
    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,             KC_RSFT,  KC_UP,    KC_SLSH,   
    KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,             KC_SPC,             KC_SPC,             KC_RALT,  MO(_FL),  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),


   [_FL] = LAYOUT_60_b_iso(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_DEL,
    _______,            _______,  KC_UP,    EMAIL_ADD,RESET,    KC_BTN1,  KC_MS_U,  KC_BTN2,  _______,  _______,  KC_PSCR,  _______,  _______, 
    _______,            KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  _______,  _______,  _______,  _______,
    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_VOLD,  KC_VOLU,  KC_MUTE,            _______,  KC_PGUP,  _______,
    _______,  _______,  _______,            _______,            _______,            _______,            _______,  _______,  _______,  KC_PGDN,  _______
  ),

};
