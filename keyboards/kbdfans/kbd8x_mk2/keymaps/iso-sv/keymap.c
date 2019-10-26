#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

// Macros
// name macros here for keymap reference
enum {
  EMAIL_ADD = SAFE_RANGE,
  OTHER_MACRO
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed){
    switch(keycode) {
      // copy these lines to define new macro
      case EMAIL_ADD:
        SEND_STRING("youremail"SS_RALT("2")"youremail.com");
        return false; break;
      // copy to here
      case OTHER_MACRO:
        SEND_STRING("The Other Macro");
        return false; break;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    
	KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,   KC_F6,   KC_F7,   KC_F8,       KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_PAUS, \
	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,           KC_INS,  KC_HOME, KC_PGUP, \
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_NUHS,          KC_DEL,  KC_END,  KC_PGDN, \
	KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,                                      \
	KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_DEL,                    KC_UP,            \
	KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_ALGR, KC_RGUI, MO(1),   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  [1] = LAYOUT( /* Function Layer */
    
	_______,          _______, _______, _______, _______,      _______, _______, _______, _______,     _______, _______, _______, _______,          _______, _______, _______, \
	_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC,          _______, RESET,   _______, \
	KC_CAPS, _______, KC_PGUP, EMAIL_ADD,_______, _______, _______, _______, KC_UP,   _______, KC_MPRV, KC_MPLY, KC_MNXT,         _______,          _______, _______, _______, \
	_______, KC_HOME, KC_PGDN, KC_END,  _______, KC_VOLD, KC_VOLU, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______,                                     \
	_______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,          KC_PSCR, _______,                   KC_PGUP,          \
	_______, _______, _______,                            _______,                                     _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_END   \
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
