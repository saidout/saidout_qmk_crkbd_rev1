#pragma once

#include QMK_KEYBOARD_H
#include "custom_keycode_ranges.h"

// NOTE: If adding new default layout keycodes make sure to check if the custom_keycode_ranges.h needs to be updated.
enum dfc_keycodes {
    DFC_FIRST_ = CKR_DEFAULT_LAYER,
    DFC_CUS    = DFC_FIRST_,
    DFC_CSE,
    DFC_CEN,
    DFC_QUS,
    DFC_QSE,
    DFC_QEN,
    DFC_LAY,
    DFC_LAST_  = DFC_LAY
};

bool process_default_layer_keycodes(uint16_t keycode, keyrecord_t *record);
