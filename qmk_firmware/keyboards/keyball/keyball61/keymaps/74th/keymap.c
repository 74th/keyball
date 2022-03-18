/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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
#define _BASE_MAC 0
#define _LINUX 1
#define _RAISE 2
#define _LINUX_RAISE 3
#define _DOUBLE 4

enum custom_keycodes
{
  QWERTY = SAFE_RANGE,
  LINUX_ESC_EISU,
  MAC_ESC_EISU,
  USE_MAC,
  USE_LINUX,
};

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_MAC] = LAYOUT_universal(
 LALT_T(KC_GRV),KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
    KC_GRV,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_EQL,
  CTL_T(KC_TAB),KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                     KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LBRC,        KC_RBRC,      KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,SFT_T(KC_BSLS),
  MAC_ESC_EISU,CTL_T(KC_TAB),GUI_T(KC_LANG2),KC_SPC,SCRL_MO,  KC_MS_BTN1,  KC_MS_BTN2,LT(_RAISE, KC_ENT), ALT_T(KC_LANG1),KC_BSPC,KC_A,       KC_B,       KC_BSPC,    MO(_DOUBLE)
  ),

  [_LINUX] = LAYOUT_universal(
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,      _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
  LINUX_ESC_EISU,ALT_T(KC_TAB),CTL_T(KC_MHEN),_______, _______, _______,      _______,        _______,   GUI_T(KC_HENK),_______,  _______,    _______,    _______,    _______
  ),

  [_RAISE] = LAYOUT_universal(
    C(A(KC_Q)), G(KC_F1), S(G(KC_F2)),  G(KC_F3),   G(KC_F4),   G(KC_F5),                                 G(KC_F6),   G(KC_F7),   G(KC_F8),   G(KC_F9),   _______,    MO(_DOUBLE),
    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
    KC_GRV,     S(KC_1),  S(KC_2),      S(KC_3),    S(KC_4),    S(KC_5),                                  S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    S(KC_MINS),
    _______,    _______,    _______,    S(G(KC_3)), S(G(KC_4)), KC_F12,       _______,        _______,    KC_LEFT,  KC_DOWN,      KC_UP,      KC_RIGHT,   KC_HOME,    KC_END,
    _______,    _______,    _______,    _______,    _______,    _______,      _______,        _______,    _______,  KC_DEL,       _______,    _______,    _______,    _______
  ),

  [_LINUX_RAISE] = LAYOUT_universal(
   C(A(KC_F2)), G(KC_F1), S(G(KC_F2)),  G(KC_F3),   G(KC_F4),   C(A(KC_ESC)),                             G(KC_F6),   G(KC_F7),   G(KC_F8),   G(KC_F9),   _______,    MO(_DOUBLE),
    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
    KC_GRV,     S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),                                  S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    S(KC_MINS),
    _______,    _______,    _______,    A(KC_PSCR), S(KC_PSCR), KC_F12,       _______,        _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_HOME,    KC_END,
    _______,    _______,    _______,    _______,    _______,    _______,      _______,        _______,    _______,    KC_DEL,     _______,    _______,    _______,    _______
  ),

  [_DOUBLE] = LAYOUT_universal(
    _______,    _______,    _______,    _______,    _______,    _______,                                  USE_MAC,    USE_LINUX,  _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  BL_ON,      BL_OFF,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KBC_RST,    KBC_SAVE,   _______,    _______,    _______,      _______,        _______,    CPI_I100,   CPI_I1K,    CPI_D100,   CPI_D1K,    SCRL_DVI,   SCRL_DVD,
    _______,    _______,    _______,    _______,    _______,    _______,      _______,        _______,    _______,    KC_DEL,     _______,    _______,    _______,    _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state)
{
  // Auto enable scroll mode when the highest layer is 3
  keyball_set_scroll_mode(get_highest_layer(state) == 3);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (record->event.pressed)
  {
    switch (keycode)
    {
    case LINUX_ESC_EISU:
      SEND_STRING(SS_TAP(X_INT5) SS_TAP(X_ESCAPE));
      return false;
    case MAC_ESC_EISU:
      SEND_STRING(SS_TAP(X_LANG2) SS_TAP(X_ESCAPE));
      return false;
    case USE_MAC:
      layer_off(_LINUX);
      return false;
    case USE_LINUX:
      layer_on(_LINUX);
      return false;
    }
  }
  return true;
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void)
{
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
}
#endif
