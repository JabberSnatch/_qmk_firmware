#include QMK_KEYBOARD_H

#include "split_util.h"

enum sofle_layers {
    _QWERTY,
    _RTRIGGER,
    _LTRIGGER,
    //_FKEYS,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // | X | X | X | X | X | X |        | X | X | X | X | X | X |
    // | X | X | X | X | X | X |        | X | X | X | X | X | X |
    // | X | X | X | X | X | X |        | X | X | X | X | X | X |
    // | X | X | X | X | X | X | O || O | X | X | X | X | X | X |
    //     | X | X | X | X | X |        | X | X | X | X | X |

[_QWERTY] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,  KC_6, KC_7, KC_8, KC_9, KC_0, KC_BACKSPACE,
    KC_EQUAL, KC_Q, KC_W, KC_E, KC_R, KC_T,  KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LEFT_BRACKET,
    KC_MINUS, KC_A, KC_S, KC_D, KC_F, KC_G,  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_RIGHT_BRACKET,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,  KC_MUTE, KC_NO,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LWIN, KC_LALT, KC_LCTRL, KC_SPC, MO(_LTRIGGER),  MO(_RTRIGGER), KC_ENTER, KC_RCTRL, KC_RALT, KC_RWIN
),

#if 0
[_FKEYS] = LAYOUT(
    KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
#endif

[_RTRIGGER] = LAYOUT(
#if 1
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
#else
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
#endif
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_HOME, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, SH_TG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_LTRIGGER] = LAYOUT(
#if 1
    KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
#else
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
#endif
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BACKSLASH,
    KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOTE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  SH_TG, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};


const uint16_t PROGMEM capscombo[] = { KC_LSFT, KC_RSFT, COMBO_END };
combo_t key_combos[] = {
    COMBO(capscombo, KC_CAPS)
};
uint16_t COMBO_LEN = sizeof(key_combos)/sizeof(key_combos[0]);

#ifdef OLED_ENABLE

static void render_logo(void) {
    static uint32_t counter = 0;

    if (!(counter & 0x00000080))
    {
        uint8_t row = 0xaa;
        for (uint32_t index = 0u; index < 8 * 16 * 4; ++index)
        {
            if (!(index & 0x10))
                row = row ^ 0xff;

            for (uint32_t biti = 0u; biti < 8; ++biti)
            {
                bool bit = ((row >> biti) & 1);
                uint32_t pixelindex = index * 8 + biti;
                uint32_t pixelx = pixelindex % (8 * 16);
                uint32_t pixely = pixelindex / (8 * 16);
                oled_write_pixel(pixelx, pixely, bit);
            }
        }
    }
    else
    {
        for (uint32_t index = 0u; index < 8 * 16 * 4; ++index)
            for (uint32_t biti = 0u; biti < 8; ++biti)
            {
                uint32_t pixelindex = index * 8 + biti;
                uint32_t pixelx = pixelindex % (8 * 16);
                uint32_t pixely = pixelindex / (8 * 16);
                oled_write_pixel(pixelx, pixely, false);
            }
    }

    ++counter;
    return;
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("hella"), false);

    if (IS_LAYER_ON(_LTRIGGER) && IS_LAYER_ON(_RTRIGGER))
        oled_write_P(PSTR("LT+RT"), false);
    else if (IS_LAYER_ON(_LTRIGGER))
        oled_write_ln_P(PSTR("LT"), false);
    else if (IS_LAYER_ON(_RTRIGGER))
        oled_write_ln_P(PSTR("RT"), false);
    else
        oled_write_ln_P(PSTR(""), false);

    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CAPS"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        oled_clear();
        print_status_narrow();
    } else {
        render_logo();
    }

    return false;
}

#endif

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

#if 0
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#if 0
    case KC_RTRIGGER:
        if (record->event.pressed)
        {
            layer_on(_RTRIGGER);
            layer_on(_FKEYS);
            //layer_or((1 << _RTRIGGER) || (1 << _FKEYS));
        }
        else
        {
            layer_off(_RTRIGGER);
            if (IS_LAYER_OFF(_LTRIGGER))
                layer_off(_FKEYS);
            //layer_and(~((1 << _RTRIGGER) || (IS_LAYER_OFF(_LTRIGGER) ? (1 << _FKEYS) : 0)));
        }

        //MO(_RTRIGGER);
        return false;
    case KC_LTRIGGER:
        if (record->event.pressed)
        {
            layer_on(_LTRIGGER);
            layer_on(_FKEYS);
            //layer_or((1 << _LTRIGGER) || (1 << _FKEYS));
        }
        else
        {
            layer_off(_LTRIGGER);
            if (IS_LAYER_OFF(_RTRIGGER))
                layer_off(_FKEYS);
            //layer_and(~((1 << _LTRIGGER) || (IS_LAYER_OFF(_RTRIGGER) ? (1 << _FKEYS) : 0)));
        }


        //MO(_LTRIGGER);
        return false;
#endif
    }
    return true;
}
#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    clockwise = !clockwise;
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
