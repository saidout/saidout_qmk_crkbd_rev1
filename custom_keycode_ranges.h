#pragma once

#include QMK_KEYBOARD_H

enum custom_keycode_ranges {
    CKR_LANGUAGE      = SAFE_RANGE,
    CKR_DEFAULT_LAYER = CKR_LANGUAGE + 50,
    CKR_RLC           = CKR_DEFAULT_LAYER + 10,
    CKR_SAFE_RANGE    = CKR_RLC + 10
};
