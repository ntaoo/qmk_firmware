#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols layer
#define NAVI 2 // navigation layer
// #define MDIA 3 // mouse and media layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `~   |  1!  |  2@  |  3#  |  4$  |   5%  |     |           |      |   6^  |  7& |  8*  |  9(  |  0)  | Delete |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  '"  |  ,<  |  .>  |   P  |   Y  |  [{  |           |  ]}  |   F  |   G  |   C  |   R  |   L  |   /?   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -_   |
 * |--------+------+------+------+------+------|  \|  |           |  =+  |------+------+------+------+------+--------|
 * | LShift |  ;:  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Down  |  Up  |option| LGui |      |                                       |space |  ~L2 | RGUI | Left | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Esc | Caps |       |      |       |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |  ~L1 | Eisu |------|       |------|  Kana  | Enter|
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,        KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_NO,
        KC_TAB,        KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,     KC_LBRC,
        KC_LCTL,       KC_A,           KC_O,    KC_E,   KC_U,   KC_I,
        KC_LSFT,       KC_SCLN,        KC_Q,    KC_J,   KC_K,   KC_X,     KC_BSLS,
        KC_DOWN,       KC_UP,          KC_LALT, KC_LGUI,KC_SPC,
                                               KC_ESC,  KC_CAPS,
                                                              KC_NO,
                                               LT(KC_FN1, KC_NO), KC_LANG2,  KC_NO,
        // right hand
             KC_NO,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
             KC_RBRC,     KC_F,   KC_G,   KC_C,   KC_R,   KC_L,             KC_SLSH,
                          KC_D,   KC_H,   KC_T,   KC_N,   KC_S,             KC_MINS,
             KC_EQL,      KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,             KC_RSFT,
                                  KC_SPC, LT(KC_FN2, KC_NO), KC_RGUI,  KC_LEFT, KC_RGHT,
             KC_NO,        KC_NO,
             KC_NO,
             KC_NO,  KC_LANG1, KC_ENT
    ),
/* Keymap 1: Symbol and Calculator Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |   _  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  7   |  8   |   9  |  *   |   /  |           |   ^  |   \  |  !   |   {  |   }  |  #   |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  4   |  5   |   6  |  -   |------|           |------|   @  |  =   |   (  |   )  |  &   |    -   |
 * |--------+------+------+------+------+------|      |           |   %  |------+------+------+------+------+--------|
 * |        |      |  1   |  2   |   3  |  +   |      |           |      |   $  |  /   |   [   |  ]  |  |   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  0   |  0   |   .  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_NO,
       KC_TRNS,KC_NO,  KC_7,   KC_8,   KC_9,   KC_ASTR,KC_SLSH,
       KC_TRNS,KC_AT,  KC_4,   KC_5,   KC_6,   KC_MINS,
       KC_NO,  KC_NO,  KC_1,   KC_2,   KC_3,   KC_PLUS,KC_NO,
       KC_TRNS,KC_TRNS,KC_0,   KC_0,   KC_DOT,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_UNDS,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
       KC_CIRC, KC_BSLS, KC_EXLM,  KC_LCBR, KC_RCBR,  KC_HASH, KC_F12,
                KC_AT, KC_EQL,  KC_LPRN, KC_RPRN,  KC_AMPR, KC_MINS,
       KC_PERC, KC_DLR,  KC_SLSH, KC_LBRC, KC_RBRC,  KC_PIPE, KC_NO,
                         KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgUp |  Up  | Home |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| FDel |  Left|  Down|  Rght|Delete| ENTER  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |PgDown|      | End  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Navigation Layer
[NAVI] = KEYMAP(
       KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,    KC_NO,   KC_PGUP, KC_UP,   KC_HOME, KC_NO,   KC_NO,
                 KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_ENT,
       KC_NO,    KC_NO,   KC_PGDN, KC_NO,   KC_END,  KC_NO,   KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap 3: Mouse and Media Layer(Not implemented.) -> calculator layer.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Reset |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |MsLeft|MsDown|MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Lclk | Rclk |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | VoDn | VoUp | Mute |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_ONESHOT(SYMB),               // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_ONESHOT(NAVI)                // FN2 - Momentary Layer 2 (Navigations)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }

};
