/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "keymap_french.h"
#include "os_detection.h"


enum custom_keycodes {
    MY_DOT= QK_USER,
    MY_SCLN,
    MY_EXLM,
    MY_GRV,
    MY_CIRC,
    MY_TILD,
    MY_COPY,
    MY_PAST,
    MY_LABK,
    MY_RABK,
    MY_SUP2,
    MY_RGB_RAINBOW,
    MY_RGB_REACTIVE,
    MY_RGB_SPLASH,
    MY_RGB_HEATMAP,
    MY_RGB_RESET,
    MY_OE,
    MY_AE,
    MY_LDAQ,
    MY_RDAQ
};

// Helper to tap a keycode with all modifiers temporarily cleared
void tap_unmodified_key(uint16_t keycode) {
    uint8_t saved_mods = get_mods();
    uint8_t saved_weak_mods = get_weak_mods();
    clear_mods();
    clear_weak_mods();
    send_keyboard_report();

    register_code(keycode);
    unregister_code(keycode);

    set_mods(saved_mods);
    set_weak_mods(saved_weak_mods);
    send_keyboard_report();
}

// Helper to tap a keycode with Shift temporarily held
void tap_shifted_key(uint16_t keycode) {
    uint8_t saved_mods = get_mods();
    uint8_t saved_weak_mods = get_weak_mods();
    clear_mods();
    clear_weak_mods();
    add_mods(MOD_BIT(KC_LSFT));
    send_keyboard_report();

    register_code(keycode);
    unregister_code(keycode);

    set_mods(saved_mods);
    set_weak_mods(saved_weak_mods);
    send_keyboard_report();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3( // NORMAL
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    FR_Q,    FR_C,    FR_O,    FR_P,    FR_W,                         FR_J,    FR_M,    FR_D, MY_EXLM,   FR_Y,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    FR_A,    FR_S,    FR_E,    FR_N,    FR_F,                         FR_L,    FR_R,    FR_T,    FR_I,    FR_U,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    FR_Z,    FR_X, MY_DOT ,    FR_V,    FR_B,                      XXXXXXX,    FR_H,    FR_G, MY_SCLN,    FR_K,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, LT(2, KC_LALT), LT(8, KC_ENT),  KC_SPC, LT(3, KC_RALT), KC_LCTL
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3( // AZERTY
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,                         FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,                         FR_H,    FR_J,    FR_K,    FR_L,    FR_M,   KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    FR_W,    FR_X,    FR_C,    FR_V,    FR_B,                      FR_N, FR_COMM, FR_SCLN, FR_COLN, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, LT(2, KC_LALT), LT(8, KC_ENT),  KC_SPC, LT(3, KC_RALT), KC_LCTL
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3( // SYMBOLES
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TG(4),   MY_GRV,  FR_DQUO,  FR_LCBR,  FR_RCBR,  XXXXXXX,                XXXXXXX,  MY_LABK,  MY_RABK,  FR_SCLN,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MY_COPY,  FR_EURO,   FR_DLR,  FR_LBRC,  FR_RBRC,  MY_PAST,                XXXXXXX,  FR_LPRN,  FR_RPRN,  XXXXXXX,  FR_UNDS,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,  FR_BSLS,  FR_SLSH,  FR_PIPE,  FR_AMPR,  FR_ASTR,                FR_EXLM,   FR_EQL,  XXXXXXX,   FR_DOT,  FR_MINS,  FR_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,       _______, _______, _______
                                       //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3( // Chiffres et caracteres francias
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     MY_SUP2,  FR_DEG,  FR_CCED, FR_CIRC,  FR_GRV,   TG(4),                         FR_7,    FR_8,    FR_9, FR_COMM, FR_CIRC, FR_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      FR_PND, FR_AGRV, FR_EGRV, FR_EACU, FR_TILD, FR_MICR,                         FR_4,    FR_5,    FR_6, FR_DIAE, FR_UGRV, FR_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_SECT,                         FR_1,    FR_2,    FR_3,  FR_DOT, FR_MINS, FR_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,       _______, _______,    FR_0
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3( // Leds
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, RM_PREV, RM_SPDU, RM_SPDD,   RM_ON,  RM_OFF,                      MY_RGB_RAINBOW, MY_RGB_REACTIVE, MY_RGB_SPLASH, MY_RGB_HEATMAP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_FLGN, RM_FLGP,                      DF(0),   DF(1),   TO(0),   XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, MY_RGB_RESET, XXXXXXX,                 TG(5), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,       _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [5] = LAYOUT_split_3x6_3( // JEU (Mappable dans VIA)
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,      FR_1,      FR_2,    FR_Z,      FR_3,      FR_4,              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_LSFT,    FR_Q,    FR_S,    FR_D,      FR_F,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         FR_I,   KC_LCTL,      FR_T,      FR_C,      FR_V,  XXXXXXX,                  TO(0),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,    MO(6),     KC_SPC,      XXXXXXX,  XXXXXXX,  XXXXXXX
                                       //`--------------------------'  `--------------------------'
  ),

    [6] = LAYOUT_split_3x6_3( // JEU plus
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    FR_5,    FR_3,    FR_1,    FR_2,    FR_4,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX
                                       //`--------------------------'  `--------------------------'
  ),

    [7] = LAYOUT_split_3x6_3( // Accents (activé en maintenant les deux pouces)
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX,  MY_SUP2,   FR_DEG,  FR_CIRC,  FR_DIAE,  XXXXXXX,                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,  FR_UGRV,  FR_AGRV,  FR_EGRV,  FR_EACU,  FR_CCED,                XXXXXXX,  FR_CIRC,  FR_DIAE,  FR_GRV,   FR_TILD,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,  MY_LDAQ,  MY_RDAQ,  XXXXXXX,  XXXXXXX,  XXXXXXX,                XXXXXXX,   MY_OE,    MY_AE,   XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,       _______, _______, _______
                                       //`--------------------------'  `--------------------------'
  ),

    [8] = LAYOUT_split_3x6_3( // Medias/FN (activé en maintenant LT(8, KC_ENT))
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,                KC_MPRV,   KC_MNXT,   KC_MPLY,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,     KC_F8,     KC_F9,    KC_F10,    KC_F11,    KC_F12,                KC_VOLD,   KC_VOLU,   KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                KC_BRID,   KC_BRIU,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,       _______, _______, _______
                                       //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [5] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [6] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [7] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [8] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [9] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [10] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_DOT:
            if (record->event.pressed) {
                if ((get_mods() | get_weak_mods()) & MOD_MASK_SHIFT) {
                    tap_unmodified_key(FR_COMM); // Sends ',' (FR_COMM = KC_M)
                } else {
                    tap_shifted_key(FR_SCLN); // Sends '.' (FR_DOT = Shift + FR_SCLN)
                }
            }
            return false;

        case MY_SCLN:
            if (record->event.pressed) {
                if ((get_mods() | get_weak_mods()) & MOD_MASK_SHIFT) {
                    tap_unmodified_key(FR_COLN); // Sends ':' (FR_COLN = KC_DOT)
                } else {
                    tap_unmodified_key(FR_SCLN); // Sends ';' (FR_SCLN = KC_COMM)
                }
            }
            return false;

        case MY_EXLM:
            if (record->event.pressed) {
                if ((get_mods() | get_weak_mods()) & MOD_MASK_SHIFT) {
                    tap_shifted_key(FR_COMM); // Sends '?' (FR_QUES = Shift + FR_COMM)
                } else {
                    tap_unmodified_key(FR_EXLM); // Sends '!' (FR_EXLM = KC_SLSH)
                }
            }
            return false;

        case MY_GRV:
            if (record->event.pressed) {
                tap_code16(FR_GRV);
                tap_code16(KC_SPC);
            }
            return false;

        case MY_CIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);
                tap_code16(KC_SPC);
            }
            return false;

        case MY_TILD:
            if (record->event.pressed) {
                tap_code16(FR_TILD);
                tap_code16(KC_SPC);
            }
            return false;

        case MY_COPY:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS || detected_host_os() == OS_IOS) {
                    tap_code16(LGUI(KC_C));
                } else {
                    tap_code16(LCTL(KC_C));
                }
            }
            return false;

        case MY_PAST:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS || detected_host_os() == OS_IOS) {
                    tap_code16(LGUI(KC_V));
                } else {
                    tap_code16(LCTL(KC_V));
                }
            }
            return false;

        case MY_LABK:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS || detected_host_os() == OS_IOS) {
                    tap_code16(KC_GRV);
                } else {
                    tap_code16(KC_NUBS);
                }
            }
            return false;

        case MY_RABK:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS || detected_host_os() == OS_IOS) {
                    tap_code16(LSFT(KC_GRV));
                } else {
                    tap_code16(LSFT(KC_NUBS));
                }
            }
            return false;

        case MY_SUP2:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS || detected_host_os() == OS_IOS) {
                    tap_code16(KC_NUBS);
                } else {
                    tap_code16(KC_GRV);
                }
            }
            return false;

        case MY_RGB_RAINBOW:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            }
            return false;

        case MY_RGB_REACTIVE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
            }
            return false;

        case MY_RGB_SPLASH:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SPLASH);
            }
            return false;

        case MY_RGB_HEATMAP:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
            }
            return false;

        case MY_RGB_RESET:
            if (record->event.pressed) {
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv(0, 255, 120);
                #endif
            }
            return false;

        case MY_OE:
            if (record->event.pressed) {
                tap_code16(LALT(FR_O));
            }
            return false;

        case MY_AE:
            if (record->event.pressed) {
                tap_code16(LALT(FR_A));
            }
            return false;

        case MY_LDAQ:
            if (record->event.pressed) {
                tap_code16(LALT(FR_EGRV));
            }
            return false;

        case MY_RDAQ:
            if (record->event.pressed) {
                tap_code16(LALT(S(FR_EGRV)));
            }
            return false;

        default:
            return true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 2, 3, 7);
}

#ifdef OLED_ENABLE
static void oled_render_layout_mode_and_os(void) {
    switch (get_highest_layer(default_layer_state)) {
        case 0:
            oled_write_P(PSTR("Mode: AY "), false);
            break;
        case 1:
            oled_write_P(PSTR("Mode: AZ "), false);
            break;
        default:
            oled_write_P(PSTR("Mode: ?  "), false);
            break;
    }

    oled_write_P(PSTR("OS: "), false);
    switch (detected_host_os()) {
        case OS_MACOS:
            oled_write_ln_P(PSTR("Mac  "), false);
            break;
        case OS_WINDOWS:
            oled_write_ln_P(PSTR("Win  "), false);
            break;
        case OS_LINUX:
            oled_write_ln_P(PSTR("Linux"), false);
            break;
        case OS_IOS:
            oled_write_ln_P(PSTR("iOS  "), false);
            break;
        default:
            oled_write_ln_P(PSTR("?    "), false);
            break;
    }
}

static void oled_render_layer_state_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Layer: Base         "), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Layer: AZERTY Base  "), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Layer: Symboles     "), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("Layer: Chiffres     "), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("Layer: Systeme/LED  "), false);
            break;
        case 5:
            oled_write_ln_P(PSTR("Layer: Mode Jeu     "), false);
            break;
        case 6:
            oled_write_ln_P(PSTR("Layer: Jeu Chiffres "), false);
            break;
        case 7:
            oled_write_ln_P(PSTR("Layer: Accents      "), false);
            break;
        case 8:
            oled_write_ln_P(PSTR("Layer: Medias/FN    "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Layer: Inconnu      "), false);
            break;
    }
}

static void oled_render_modifiers(void) {
    uint8_t mods = get_mods() | get_weak_mods();
#ifdef ONE_SHOT_MODS_ENABLE
    mods |= get_oneshot_mods();
#endif

    oled_write_P(PSTR("Mods: "), false);
    oled_write_P(PSTR("S"), (mods & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (mods & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (mods & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (mods & MOD_MASK_GUI));

    if (host_keyboard_led_state().caps_lock) {
        oled_write_P(PSTR(" CAP"), true);
    } else {
        oled_write_P(PSTR("    "), false);
    }
    oled_write_P(PSTR("\n"), false);
}

static void oled_render_rgb_state(void) {
    char rgb_str[32];
    uint8_t active_layer = get_highest_layer(layer_state);
    if (active_layer == 5) {
        snprintf(rgb_str, sizeof(rgb_str), "Jeu: Custom        ");
    } else if (rgb_matrix_is_enabled()) {
        uint8_t h_simple = (uint16_t)rgb_matrix_config.hsv.h * 9 / 255;
        uint8_t s_simple = (uint16_t)rgb_matrix_config.hsv.s * 9 / 255;
        uint8_t v_simple = (uint16_t)rgb_matrix_config.hsv.v * 9 / 255;
        snprintf(rgb_str, sizeof(rgb_str), "M:%-2d H:%d S:%d V:%d     ",
                 rgb_matrix_get_mode(),
                 h_simple,
                 s_simple,
                 v_simple);
    } else {
        snprintf(rgb_str, sizeof(rgb_str), "RGB: OFF            ");
    }
    oled_write(rgb_str, false);
}

static void oled_render_arkan_logo(void) {
    oled_write_ln_P(PSTR("---------------------"), false);
    oled_write_ln_P(PSTR("     ARKAN YOTA      "), false);
    oled_write_ln_P(PSTR("   CORNE KEYBOARD    "), false);
    oled_write_ln_P(PSTR("---------------------"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_set_cursor(0, 0);
        oled_render_layout_mode_and_os();
        oled_render_layer_state_user();
        oled_render_modifiers();
        oled_render_rgb_state();
    } else {
        oled_set_cursor(0, 0);
        oled_render_arkan_logo();
    }
    return false;
}
#endif

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    uint8_t active_layer = get_highest_layer(layer_state);
    if (active_layer == 5 || active_layer == 8) {
        // Couleur thématique (Violet par défaut)
        uint8_t r_key = 120, g_key = 0, b_key = 255;

        // Parcourir toute la matrice du clavier pour éclairer dynamiquement les touches actives
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            for (uint8_t col = 0; col < MATRIX_COLS; col++) {
                uint8_t led = g_led_config.matrix_co[row][col];
                if (led == NO_LED) continue;

                // Lire la touche programmée sur cette couche (dynamique, compatible VIA !)
                keypos_t pos = { .col = col, .row = row };
                uint16_t keycode = keymap_key_to_keycode(active_layer, pos);

                // ZQSD (physique) garde son effet RGB dynamique (cycle arc-en-ciel)
                if (keycode == FR_Z || keycode == FR_Q || keycode == FR_S || keycode == FR_D) {
                    uint32_t time = timer_read() / 15;
                    uint8_t hue = (time + (row * 30) + (col * 15)) & 255;
                    hsv_t hsv_val = {hue, 255, rgb_matrix_config.hsv.v};
                    rgb_t rgb_val = hsv_to_rgb(hsv_val);
                    rgb_matrix_set_color(led, rgb_val.r, rgb_val.g, rgb_val.b);
                    continue;
                }

                // Touche Echap en haut à gauche avec la couleur du jeu
                if (keycode == KC_ESC) {
                    rgb_matrix_set_color(led, r_key, g_key, b_key);
                    continue;
                }

                // Modificateurs / Actions système actives (Blanc standard)
                if (keycode == KC_LSFT || keycode == KC_LCTL || keycode == MO(6) || keycode == TO(0)) {
                    rgb_matrix_set_color(led, 255, 255, 255);
                    continue;
                }

                // Toutes les autres touches de gameplay actives (Blanc standard)
                if (keycode != XXXXXXX) {
                    rgb_matrix_set_color(led, 255, 255, 255);
                    continue;
                }

                // Les touches non configurées (XXXXXXX) sont éteintes
                rgb_matrix_set_color(led, 0, 0, 0);
            }
        }
    } else if (active_layer == 6) {
        uint8_t n5_led = g_led_config.matrix_co[0][1];
        uint8_t n3_led = g_led_config.matrix_co[0][2];
        uint8_t n1_led = g_led_config.matrix_co[0][3];
        uint8_t n2_led = g_led_config.matrix_co[0][4];
        uint8_t n4_led = g_led_config.matrix_co[0][5];
        uint8_t mo6_led = g_led_config.matrix_co[3][4];

        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            if (i == n5_led || i == n3_led || i == n1_led || i == n2_led || i == n4_led) {
                rgb_matrix_set_color(i, 0, 255, 0); // Vert pour les chiffres actifs
            } else if (i == mo6_led) {
                rgb_matrix_set_color(i, 0, 0, 255); // Bleu pour la touche d'activation
            } else {
                rgb_matrix_set_color(i, 0, 0, 0); // Éteindre tout le reste
            }
        }
    } else if (active_layer == 4) {
        // Obtenir l'état HSV actuel
        uint8_t current_h = rgb_matrix_config.hsv.h;
        uint8_t current_s = rgb_matrix_config.hsv.s;

        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            for (uint8_t col = 0; col < MATRIX_COLS; col++) {
                uint8_t led = g_led_config.matrix_co[row][col];
                if (led == NO_LED) continue;

                keypos_t pos = { .col = col, .row = row };
                uint16_t keycode = keymap_key_to_keycode(4, pos);
                
                switch (keycode) {
                    // 1. Teinte (Hue) : affiche la couleur actuelle
                    case RM_HUEU:
                    case RM_HUED: {
                        hsv_t hsv = {current_h, 255, 255};
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
                        break;
                    }
                    // 2. Saturation : RM_SATU = saturé (couleur pure), RM_SATD = délavé (presque blanc)
                    case RM_SATU: {
                        hsv_t hsv = {current_h, 255, 255};
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
                        break;
                    }
                    case RM_SATD: {
                        hsv_t hsv = {current_h, 60, 255};
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
                        break;
                    }
                    // 3. Luminosité (Value) : RM_VALU = brillant, RM_VALD = sombre
                    case RM_VALU: {
                        hsv_t hsv = {current_h, current_s, 255};
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
                        break;
                    }
                    case RM_VALD: {
                        hsv_t hsv = {current_h, current_s, 50};
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
                        break;
                    }
                    // 4. Bouton Reset HSV : rouge vif
                    case MY_RGB_RESET:
                        rgb_matrix_set_color(led, 255, 0, 0);
                        break;
                    
                    // 5. Modes et Effets RGB
                    case MY_RGB_RAINBOW: {
                        // Vague arc-en-ciel animée sur cette touche !
                        uint32_t time = timer_read() / 10;
                        uint8_t hue = (time + (row * 30) + (col * 15)) & 255;
                        hsv_t hsv = {hue, 255, 255};
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
                        break;
                    }
                    case MY_RGB_REACTIVE:
                        rgb_matrix_set_color(led, 0, 255, 255); // Cyan réactif
                        break;
                    case MY_RGB_SPLASH:
                        rgb_matrix_set_color(led, 0, 255, 0); // Vert splash
                        break;
                    case MY_RGB_HEATMAP:
                        rgb_matrix_set_color(led, 255, 60, 0); // Orange chaud
                        break;

                    // 6. Navigation calques et sortie
                    case DF(0): // Base AY
                        rgb_matrix_set_color(led, 59, 130, 246); // Bleu AY
                        break;
                    case DF(1): // Base AZERTY
                        rgb_matrix_set_color(led, 148, 163, 184); // Gris AZERTY
                        break;
                    case TO(0): // Sortie
                        rgb_matrix_set_color(led, 239, 68, 68); // Rouge Exit
                        break;

                    // 7. Touches de contrôle général (RM_ON, RM_OFF, RM_TOGG, etc.)
                    case RM_ON:
                    case RM_TOGG:
                        rgb_matrix_set_color(led, 34, 197, 94); // Vert pour allumé/toggle
                        break;
                    case RM_OFF:
                        rgb_matrix_set_color(led, 150, 0, 0); // Rouge sombre pour éteint
                        break;
                    case RM_SPDU:
                    case RM_SPDD:
                        rgb_matrix_set_color(led, 168, 85, 247); // Violet pour vitesse animation
                        break;
                    case RM_PREV:
                    case RM_NEXT:
                        rgb_matrix_set_color(led, 234, 179, 8); // Jaune pour changer de mode
                        break;

                    default:
                        // Éteindre les touches non configurées
                        rgb_matrix_set_color(led, 0, 0, 0);
                        break;
                }
            }
        }
    }
    return false;
}
#endif


