#pragma once

#ifdef RGB_MATRIX_ENABLE

#include QMK_KEYBOARD_H
#include "custom_keycode_ranges.h"

// NOTE: If adding new rgb keycodes make sure to check if the custom_keycode_ranges.h needs to be updated.
enum rgb_keycodes {
    RLC_FIRST_ = CKR_RLC,
    RLC_ON     = RLC_FIRST_,
    RLC_OFF,
    RLC_TG,
    RLC_LAST_  = RLC_TG
};

#if defined(__GNUC__)
#    define PACKED __attribute__((__packed__))
#else
#    define PACKED
#endif // defined(__GNUC__)

typedef struct PACKED {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RgbColor;

/** @brief Indicates that all keys on the layer should be turned OFF. */
#define RGB_LAYER_ALL_COLORS_OFF  0xFF
/**
 * @brief Each layer should have either an index into color layour in rgb_layer_colors or
 *        be set to RGB_LAYER_ALL_COLORS_OFF.
 */
extern const uint8_t rgb_layer_colors_index[];
/** @brief Each element contain a layer color layout that defines the RGB color that should be set for each key. */
extern const RgbColor PROGMEM rgb_layer_colors[][MATRIX_ROWS][MATRIX_COLS];

bool process_rgb_keycodes(uint16_t keycode, keyrecord_t *record);
void rgb_layer_setup(void);

bool rgb_layer_is_on(void);
void rgb_layer_on(void);
void rgb_layer_off(void);
void rgb_layer_toggle(void);

#define CXX   { 0x00, 0x00, 0x00 }
#define COLOR_split_3x6_3( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05 }, \
        { L10, L11, L12, L13, L14, L15 }, \
        { L20, L21, L22, L23, L24, L25 }, \
        { CXX, CXX, CXX, L30, L31, L32 }, \
        { R05, R04, R03, R02, R01, R00 }, \
        { R15, R14, R13, R12, R11, R10 }, \
        { R25, R24, R23, R22, R21, R20 }, \
        { CXX, CXX, CXX, R32, R31, R30 } \
    }

#endif // RGB_MATRIX_ENABLE
