#ifdef RGB_MATRIX_ENABLE

#include QMK_KEYBOARD_H
#include "rgb_layer.h"

static bool rgb_enabled = true;

void set_layer_colors(void) {
    if (!rgb_enabled) { return; }
    const uint8_t layer = get_highest_layer(layer_state);
    const uint8_t color_idx = rgb_layer_colors_index[layer];
    if (color_idx == RGB_LAYER_ALL_COLORS_OFF) {
        rgb_matrix_set_color_all(0, 0, 0);
        return;
    }

    RgbColor colors[MATRIX_ROWS][MATRIX_COLS];
    memcpy_P(&colors[0][0], &rgb_layer_colors[color_idx][0][0], MATRIX_ROWS * MATRIX_COLS * sizeof(RgbColor));
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            const uint8_t idx = g_led_config.matrix_co[row][col];
            if (idx == NO_LED) { continue; }
            const RgbColor c = colors[row][col];
            rgb_matrix_set_color(idx, c.red, c.green, c.blue);
        }
    }
}

void rgb_layer_setup(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
    set_layer_colors();
}

/**
 * @brief QMK function that is called to set RGB colors for keys.
 *
 * Function is called from rgb_matrix_task which in turn is
 * called from keyboard_task function in qmk_firmware/quantum/keyboard.c
 *
 * @return
 * @return Does not seem to be in use. See qmk_firmware/quantum/rgb_matrix/rgb_matrix.c
 *         But pattern in QMK is to return false if you handle the event/callback.
 */
bool rgb_matrix_indicators_user(void) {
    set_layer_colors();
    return false;
}

bool rgb_layer_is_on(void) {
    return rgb_enabled;
}

void rgb_layer_on(void) {
    if (rgb_enabled) { return; }
    rgb_enabled = true;
    rgb_matrix_enable_noeeprom();
}

void rgb_layer_off(void) {
    if (!rgb_enabled) { return; }
    rgb_enabled = false;
    rgb_matrix_disable_noeeprom();
}

void rgb_layer_toggle(void) {
    if (rgb_enabled) {
        rgb_layer_off();
    } else {
        rgb_layer_on();
    }
}

bool process_rgb_keycodes(uint16_t keycode, keyrecord_t *record) {
    if (keycode < RLC_FIRST_ || keycode > RLC_LAST_) {
        return true;
    }

    if (record->event.pressed) {
        switch(keycode) {
            case RLC_ON:
                rgb_layer_on();
                break;
            case RLC_OFF:
                rgb_layer_off();
                break;
            case RLC_TG:
                rgb_layer_toggle();
                break;
        }
    }

    return false;
}

#endif // RGB_MATRIX_ENABLE
