// modified following file.
// https://github.com/msc654/qmk_firmware/blob/master/keyboard%2Fergodox_ez%2Fkeymaps%2Fdefault%2Fkeymap.c

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define MAIN 0  // default layer (for Windows)
#define TENKEY 1  // default layer (for tenkey)
#define FN      2  // functions
#define MOUSE   3  // mouse mode

#define C_S(kc) kc | 0x0300

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Default layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `~   |   1  |   2  |   3  |   4  |   5  |   6  |           |  7   |   8  |   9  |   0  |   -  |   =  |  BkSp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | ESC  |           | LFn  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '"   |
 * |--------+------+------+------+------+------| Ctl+ |           | BkSp |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |Sht+Sp|           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Left |  Up  |                                       | Down | Right|   [  |   ]  | RTen |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | LAlt |       | Alt  | Esc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space |Delete|------|       |------| Space  |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[MAIN] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,        KC_3,      KC_4,   KC_5,   KC_6,
        KC_TAB,         KC_Q,         KC_W,        KC_E,      KC_R,   KC_T,   KC_ESC,
        KC_LCTL,        KC_A,         KC_S,        KC_D,      KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,        KC_C,      KC_V,   KC_B,   C_S(KC_SPC),
        KC_NO,          KC_NO,        KC_NO,       KC_LEFT,   KC_UP,
                                                               KC_LGUI,       KC_LALT,
                                                                              KC_HOME,
                                                               KC_SPC,KC_DELT,KC_END,
        // right hand
        KC_7,           KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,           KC_BSPC,
        MO(FN),         KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_BSPC,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                  KC_DOWN,  KC_RGHT,KC_LBRC,KC_RBRC,          TO(TENKEY,1),
             KC_LALT,        KC_ESC,
             KC_PGUP,
             KC_PGDN,KC_SPC, KC_ENT
    ),

/* Keymap 1: Ten-key Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |   =  |  /   |   *  |   -  |  +   |      |  BkSp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  7   |   8  |   9  |  [   |   ]  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  4   |   5  |   6  |      |      | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  1   |   2  |   3  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   ,  |   .  |      |NumLK | RMain|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |Enter |------|       |------| Ent  |   0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// tenkey
[TENKEY] = KEYMAP(
       // left hand
       KC_NO,       KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,       KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,       KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,       KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,       KC_NO,    KC_NO, KC_NO, KC_NO,
                                                            KC_NO, KC_NO,
                                                                     KC_NO,
                                                     KC_SPC, KC_ENT, KC_NO,
       // right hand
       KC_PEQL,   KC_PSLS,  KC_PAST, KC_PMNS, KC_PPLS, KC_NO, KC_BSPC,
       KC_NO,       KC_P7,    KC_P8, KC_P9, KC_LBRC, KC_RBRC, KC_NO,
                    KC_P4,    KC_P5, KC_P6, KC_NO, KC_NO, KC_PENT,
       KC_NO,       KC_P1,    KC_P2, KC_P3, KC_NO, KC_NO, KC_NO,
                              KC_PCMM, KC_PDOT, KC_NO, KC_NLCK, TO(MAIN,1),
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_PENT, KC_P0
    ),

/* Keymap 2: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | RESET|       |      | Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |Enter |------|       |------| Vol- | Vol+ |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Fnctions
[FN] = KEYMAP(
       // left hand
       KC_TRNS,       KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                            KC_TRNS, RESET,
                                                                     KC_TRNS,
                                                     KC_SPC, KC_ENT, KC_TRNS,
       // right hand
       KC_F7,     KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_MUTE,
       KC_TRNS,
       KC_TRNS, KC_VOLD, KC_VOLU
    ),
    
/* Keymap 3: Mouse Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | M-Up |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           | LMac |------+------+------+------+------+--------|
 * |        |  M-L | M-Dn | M-R  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | LWin |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | WH-L | WH-R |                                       | Sp+2 | Sp+1 | Sp+0 |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | M2   |MClick|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 |Space |Enter |------|       |------|RClick|LClick|
 *                                 |      |      |      |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Mouse
[MOUSE] = KEYMAP(
       // left hand
       KC_TRNS,       KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS,     KC_TRNS,    KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_MS_L,    KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_WH_L, KC_WH_R,
                                                            KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,
                                                     KC_SPC, KC_ENT, KC_TRNS,
       // right hand
       KC_F7,           KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       TO(MAIN,1),     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       TO(TENKEY,1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_ACL2, KC_ACL1, KC_ACL0, KC_TRNS,  KC_TRNS,
       KC_BTN4, KC_BTN3,
       KC_PGUP,
       KC_PGDN, KC_BTN1, KC_BTN2
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FN)                // FN1 - Momentary Layer 1 (functions)
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
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();    
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
        case MAIN:
            ergodox_right_led_1_off();
            break;
        case TENKEY:
            ergodox_right_led_2_on();
            break;
        case FN:
            ergodox_right_led_3_on();
            break;
        case MOUSE:
            ergodox_led_all_on();
            break;
        default:
            // none
            break;
    }

};
