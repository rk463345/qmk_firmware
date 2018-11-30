#include QMK_KEYBOARD_H
#include <string.h>


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DVORAK 1
#define _GAMING 2
#define _LOWER 3
#define _RAISE 4


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  GAMING,
  LOWER,
  RAISE,
  REPROGRAM_MACRO,
  SCROT
};

//Tap Dance Declarations
enum {
  TD_EQUAL_ENTER= 0
  ,TD_DASH_SLASH
  ,TD_BSLASH_EQUAL
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap for enter, double tap for equal
  [TD_EQUAL_ENTER]  = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_EQUAL)
  //Tap for dash, double tap for slash
  ,[TD_DASH_SLASH]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_SLASH)
  //Tap for backslash, double tap for equal
  ,[TD_BSLASH_EQUAL]  = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_EQUAL)
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Short codes to make reading easier
#define UP_HYP LT(4, KC_MINS)
#define LOWER TT(3)
#define REPROGR REPROGRAM_MACRO

const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE
(
 UCIS_SYM("tm", 0x2122)
);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt | Lower|Raise |Space |Space |Enter | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_BSLS) , \
  KC_LCTRL,KC_LGUI, KC_LALT, LOWER,   KC_ENT,  KC_SPC,  KC_SPC,  UP_HYP,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),


/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   6  |   7  |   8  |   9  |   0  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  T   |  F1  |  F2  |  F3  |  F4  |  F5  |   B  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   R  |   F  | Lower|Space |   V  |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_ortho_4x12( \
  KC_GESC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_T,	   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTRL,KC_R,    KC_F,    KC_F6,   KC_SPC,  KC_V,    KC_SPC,  UP_HYP,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_GESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  KC_LCTRL,KC_LGUI, KC_LALT, LOWER,   KC_ENT,  KC_SPC,  KC_SPC,  UP_HYP,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |  7   |  8   |  9   | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |  4   |  5   |  6   |  +   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |  1   |  2   |  3   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RESET |      |      |      |      |             |      |  0   |  0   | ENT  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_LPRN, KC_RPRN, KC_7,    KC_8,    KC_9,    KC_MINS, \
  _______, XXXXXXX, KC_DEL,  XXXXXXX, KC_PGUP, KC_PGDN, KC_LBRC, KC_RBRC, KC_4,    KC_5,    KC_6,    KC_PLUS, \
  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_EQL,  KC_EXLM, KC_1,    KC_2,    KC_3,    XXXXXXX, \
  RESET,   REPROGR, _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_ENT,  KC_ENT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |RESET |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, RESET, \
  DF(0),   DF(1),   DF(2),   _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

};
void matrix_init_user(void) {
  wait_ms(500);
  set_unicode_input_mode(UC_LNX);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      return false;
      break;

    case REPROGRAM_MACRO:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI));
        wait_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        SEND_STRING(SS_UP(X_LGUI));
        wait_ms(1000);
        SEND_STRING("cd ~/keyboard/qmk_firmware" SS_TAP(X_ENTER));
        wait_ms(100);
        SEND_STRING("make "QMK_KEYBOARD":"QMK_KEYMAP":dfu && exit" SS_TAP(X_ENTER));
        reset_keyboard();
        return false;
        break;
     }

    case SCROT:
      if (record->event.pressed) {
      wait_ms(10);
      SEND_STRING(SS_LGUI(SS_TAP(X_R)));
      wait_ms(100);
      SEND_STRING("scrot");
      wait_ms(10);
      SEND_STRING(SS_TAP(X_ENTER));
      return false;
      break;
     }
  }
  return true;
}

