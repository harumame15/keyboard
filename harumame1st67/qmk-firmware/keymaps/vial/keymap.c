// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
//#include "keymap_jp.h"
#include "keymap_japanese.h"

//custom keymap
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EXPL,
    APSTP,
    TM_MUTE,
    KANA
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    //                  Encoder 1                                     Encoder 2
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐                      ┌───┬───┬───┬───┬───┬───┬───┬───┐
     * │ESC   │ 1    │ 2    │ 3    │ 4    │ 5    │                      │ 6    │ 7    │ 8    │ 9    │ 0    │ -    │ =    │MUTE  │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │TAB   │ Q    │ W    │ E    │ R    │ T    │                      │ Y    │ U    │ I    │ O    │ P    │[     │ ]    │PGUP  │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │`     │ A    │ S    │ D    │ F    │ G    │                      │ H    │ J    │ K    │ L    │ ;    │ '    │ SHIFT│PGDN  │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │SHIFT │ Z    │ X    │ C    │ V    │ B    │                      │ N    │ M    │ ,    │ .    │ /    │\     │ CTRL │ UP   │
     * ├───┼───┴───┼───┼───┼───┼───┬───┬───┼───┼───┼───┼───┴───┴───┼───┼───┼───┐
     * │CTRL  │              │ALT   │ FN1  │SPC   │MENU  │BS/DEL│TAB   │ENT   │FN2   │ALT   │                      │ LEFT │ DOWN │ RIGHT│ 
     * └───┘              └───┴───┴───┴───┴───┴───┴───┴───┴───┘                      └───┴───┴───┘ 
     */
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_PGUP,
        KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_RSFT, KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,  KC_RCTL, KC_UP,  
        KC_LCTL, KC_LALT,          MO(1),   KC_SPC,  KC_APP,  KC_BSPC,KC_TAB ,      KC_ENT,  MO(2),   KC_RALT,                             KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    /*
     * ┌───┬───┬───┬───┬───┬───┐                      ┌───┬───┬───┬───┬───┬───┬───┬───┐
     * │ESC   │ F1   │ F2   │ F3   │ F4   │ F5   │                      │ F6   │ F7   │ F8   │ F9   │ F10  │ F11  │ F12  │MUTE  │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │TAB   │ Q    │ W    │ E    │ R    │ T    │                      │ Y    │ PGUP │ UP   │ PDOWN│ P    │[     │ ]    │DEL   │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │`     │ A    │ S    │ D    │ F    │ G    │                      │ H    │ LEFT │ DOWN │ RIGHT│ ;    │ '    │ SHIFT│WIN   │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │SHIFT │ Z    │ X    │ C    │ V    │ B    │                      │ N    │ HOME │ DEL  │ END  │ /    │MENU  │ CTRL │PGUP  │
     * ├───┼───┴───┼───┼───┼───┼───┬───┬───┼───┼───┼───┼───┴───┴───┼───┼───┼───┐
     * │CTRL  │              │ALT   │ FN1  │SPC   │WIN   │MLCLIC│MRCLIC│ENT   │FN2   │ALT   │                      │ HOME │PGDN  │ END  │ 
     * └───┘              └───┴───┴───┴───┴───┴───┴───┴───┴───┘                      └───┴───┴───┘ 
     */
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  TM_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_PGUP, KC_UP,   KC_PGDN, KC_P,    KC_LBRC,  KC_RBRC, KC_DEL,
        KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_SCLN, KC_QUOT,  KC_RSFT, KC_RWIN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_HOME, KC_DEL,  KC_END,  KC_SLSH, KC_BSLS,  KC_RCTL, KC_PGUP,
        KC_LCTL, KC_LALT,          MO(1),   KC_SPC,  KC_LWIN,  KC_BTN1, KC_BTN2,    KC_ENT,  MO(2),   KC_RALT,                             KC_HOME, KC_PGDN, KC_END
    ),
    /*
     * ┌───┬───┬───┬───┬───┬───┐                      ┌───┬───┬───┬───┬───┬───┬───┬───┐
     * │ESC   │ 1    │ 2    │ 3    │ 4    │ 5    │                      │ 6    │ 7    │ 8    │ 9    │ 0    │ -    │ =    │MUTE  │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │TAB   │ Q    │ W    │ E    │ R    │ T    │                      │ Y    │ U    │ I    │ O    │ P    │[     │ ]    │HOME  │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │`     │ A    │ S    │ D    │ F    │ G    │                      │ H    │ J    │ K    │ L    │ ;    │ '    │ SHIFT│END   │
     * ├───┼───┼───┼───┼───┼───┤                      ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │SHIFT │ Z    │ X    │ C    │ V    │ B    │                      │ N    │ M    │ ,    │ .    │ /    │\     │ CTRL │ UP   │
     * ├───┼───┴───┼───┼───┼───┼───┬───┬───┼───┼───┼───┼───┴───┴───┼───┼───┼───┐
     * │CTRL  │              │ALT   │ FN1  │SPC   │MENU  │EXPLOR│ALT+F4│ENT   │FN2   │ ALT  │                      │ LEFT │ DOWN │ RIGHT│ 
     * └───┘              └───┴───┴───┴───┴───┴───┴───┴───┴───┘                      └───┴───┴───┘ 
     */
    [2] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_HOME,
        KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_RSFT, KC_END,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,  KC_RCTL, KC_UP,  
        KC_LCTL, KC_LALT,          MO(1),   KC_SPC,  KC_APP,  EXPL,     APSTP,      KC_ENT,  MO(2),   KC_RALT,                             KC_LEFT, KC_DOWN, KC_RIGHT
    )
};




//ctrl,shift position
static bool ctrl_pressed = false;
static bool shift_pressed = false;
static int speed = 5;
static int high = 5;
static int speed2 = 5;
uint8_t mod_state;



//rotally encorder
bool encoder_update_user(uint8_t index, bool clockwise) {
    //Layer position
    uint8_t layer = biton32(layer_state);
    int i = 1;
//    int speed = 5;  //mouse speed
//    int high = 1;   //ctrl speed up
    
    if (index == 0) {
        if (layer == 0) {
            if (clockwise) {
                tap_code16(KC_KB_VOLUME_DOWN);
            } else {
                tap_code16(KC_KB_VOLUME_UP);
            }
            return true;
        } else if (layer == 1) {
            if (clockwise) {
                if (speed < 20){
                    speed++;
                }
            } else {
                if (speed > 1){
                    speed--;
                }
            }
            return false;
        } else if (layer == 2) {  //mouse cursour move
            if (clockwise) {
                if (high < 10){
                    high++;
                }
            } else {
                if (high > 1){
                    high--;
                }
            }
            return false;
        }

    } else if (index == 1) {
        if (layer == 0) {  //mouse cursour move
            if (ctrl_pressed){
                speed2 = speed * high;
            }else{
                speed2 = speed;
            }
            
            if (clockwise) {
                if (shift_pressed) {
                    for (i = 1 ;i <= speed2 ; i++){
                        tap_code16(KC_MS_D);
                    }
                } else {
                    for (i = 1 ;i <= speed2 ; i++){
                        tap_code16(KC_MS_R);
                    }
                }
                return false;
            } else {
                if (shift_pressed) {
                    for (i = 1 ;i <= speed2 ; i++){
                        tap_code16(KC_MS_U);
                    }
                } else {
                    for (i = 1 ;i <= speed2 ; i++){
                        tap_code16(KC_MS_L);
                    }
                }
                return false;
            }

        } else if (layer == 1){
        
            if (clockwise) {
                if (shift_pressed) {
                    tap_code16(KC_MS_WH_RIGHT);
                } else {
                    tap_code16(KC_MS_WH_DOWN);
                }
            } else {
                if (shift_pressed) {
                    tap_code16(KC_MS_WH_LEFT);
            } else {
                    tap_code16(KC_MS_WH_UP);
                }
            }
            return false;
        }
        return false;
    }
    return false;
};




/*
 *キーマクロ設定
 *
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {
      case KANA:
        SEND_STRING(SS_LALT("`"));
        return false;
        break;
      /* sift pressed */
      case KC_LSFT:
        if (record->event.pressed){
          shift_pressed = true;
        } else {
          shift_pressed = false;
        }
        break;
      case KC_RSFT:
        if (record->event.pressed){
          shift_pressed = true;
        } else {
          shift_pressed = false;
        }
        break;
      /* ctrl pressed */
      case KC_LCTL:
        if (record->event.pressed){
          ctrl_pressed = true;
        } else {
          ctrl_pressed = false;
        }
        break;
      case KC_RCTL:
        if (record->event.pressed){
          ctrl_pressed = true;
        } else {
          ctrl_pressed = false;
        }
        break;
    // Run Explorer
    case EXPL:
        if (record->event.pressed){
            register_code(KC_RWIN);
            register_code(KC_E);
            unregister_code(KC_RWIN);
            unregister_code(KC_E);
        }
        break;
        
    case APSTP:
        if (record->event.pressed){
            register_code(KC_LALT);
            register_code(KC_F4);
            unregister_code(KC_LALT);
            unregister_code(KC_F4);
        }
        break;
    // TM_MUTE
    case TM_MUTE:
        if (record->event.pressed){
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_M);
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_M);
        }
        break;

    case KC_BSPC:
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
    }
    return true;
};
