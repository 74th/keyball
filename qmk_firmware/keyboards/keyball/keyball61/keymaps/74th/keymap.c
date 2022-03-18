#include QMK_KEYBOARD_H
#define _BASE_MAC 0
#define _LINUX 1
#define _RAISE 2
#define _LINUX_RAISE 3
#define _DOUBLE 4
#define _CTL_T 5

enum custom_keycodes
{
  QWERTY = SAFE_RANGE,
  ESC_EN_LNX,
  ESC_EN_MAC,
  USE_MAC,
  USE_LINUX,
};

#include "quantum.h"

#define ALT_TAB ALT_T(KC_TAB)
#define CTL_TAB LT(_CTL_T, KC_TAB)
#define ALT_GRV LALT_T(KC_GRV)
#define CTL_EN_LNX CTL_T(KC_MHEN)
#define CMD_EN_MAC GUI_T(KC_LANG2)
#define GUI_JA_LNX ALT_T(KC_HENK)
#define ALT_JA_MAC ALT_T(KC_LANG1)
#define RAISE_ENT LT(_RAISE, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_MAC] = LAYOUT_right_ball(
    ALT_GRV,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
    KC_GRV,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_EQL,
    CTL_TAB,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                     KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LBRC,        KC_RBRC,      KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,
    ESC_EN_MAC, _______,    _______,    ESC_EN_MAC, CTL_TAB,    CMD_EN_MAC, KC_SPC,         RAISE_ENT,    ALT_JA_MAC,                                     KC_BSPC,    MO(_DOUBLE)
  ),

  [_LINUX] = LAYOUT_right_ball(
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,      _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,
    ESC_EN_LNX, _______,    _______,    ESC_EN_LNX, ALT_TAB,    CTL_EN_LNX,   _______,        _______,    GUI_JA_LNX,                                     _______,    _______
  ),

  [_RAISE] = LAYOUT_right_ball(
    C(A(KC_Q)), G(KC_F1), S(G(KC_F2)),  G(KC_F3),   G(KC_F4),   G(KC_F5),                                 G(KC_F6),   G(KC_F7),   G(KC_F8),   G(KC_F9),   _______,    MO(_DOUBLE),
    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
    _______,    S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),                                  S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    S(KC_MINS),
    _______,    _______,    _______,    S(G(KC_3)), S(G(KC_4)), KC_F12,       KC_MS_BTN3,     _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_HOME,    KC_END,
    _______,    _______,    _______,    _______,    _______,    _______,      C(KC_SPC),      _______,    KC_BSPC,                                        _______,    _______
  ),

  [_LINUX_RAISE] = LAYOUT_right_ball(
   C(A(KC_F2)), G(KC_F1), S(G(KC_F2)),  G(KC_F3),   G(KC_F4),   C(A(KC_ESC)),                             G(KC_F6),   G(KC_F7),   G(KC_F8),   G(KC_F9),   _______,    MO(_DOUBLE),
    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
    KC_GRV,     S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),                                  S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    S(KC_MINS),
    _______,    _______,    _______,    A(KC_PSCR), S(KC_PSCR), KC_F12,       _______,        _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_HOME,    KC_END,
    _______,    _______,    _______,    _______,    _______,    _______,      _______,        _______,    _______,                                        _______,    _______
  ),

  [_DOUBLE] = LAYOUT_right_ball(
    _______,    _______,    _______,    _______,    _______,    _______,                                  USE_MAC,    USE_LINUX,  _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  BL_ON,      BL_OFF,     _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                  _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KBC_RST,    KBC_SAVE,   _______,    _______,    _______,      _______,        _______,    CPI_I100,   CPI_I1K,    CPI_D100,   CPI_D1K,    SCRL_DVI,   SCRL_DVD,
    _______,    _______,    _______,    _______,    _______,    _______,      _______,        _______,    _______,                                        _______,    _______
  ),

  [_CTL_T] = LAYOUT_right_ball(
    C(KC_GRV),  C(KC_1),    C(KC_2),    C(KC_3),    C(KC_4),    C(KC_5),                                  C(KC_6),    C(KC_7),    C(KC_8),    C(KC_9),    C(KC_0),    C(KC_MINS),
    C(KC_GRV),  C(KC_Q),    C(KC_W),    C(KC_E),    C(KC_R),    C(KC_T),                                  C(KC_Y),    C(KC_U),    C(KC_I),    C(KC_O),    C(KC_P),    C(KC_EQL),
    _______,    C(KC_A),    C(KC_S),    C(KC_D),    C(KC_F),    C(KC_G),                                  C(KC_H),    C(KC_J),    C(KC_K),    C(KC_L),    C(KC_SCLN), C(KC_QUOT),
    KC_LSFT,    C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    C(KC_B),       KC_LBRC,        KC_RBRC,   C(KC_N),    C(KC_M),    C(KC_COMM), C(KC_DOT),  C(KC_SLSH), C(KC_BSLS),
    _______,    _______,    _______,    _______,    SCRL_MO,    KC_MS_BTN1,    KC_MS_BTN2,     _______,   _______,                                        _______,    _______
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
    case ESC_EN_LNX:
      SEND_STRING(SS_TAP(X_INT5) SS_TAP(X_ESCAPE));
      return false;
    case ESC_EN_MAC:
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
