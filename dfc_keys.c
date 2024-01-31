#include QMK_KEYBOARD_H
#include "dfc_keys.h"
#include "layer_names.h"
#include "language_keys.h"

void set_default_layer_and_lang(uint8_t layer, uint8_t lang) {
    current_lang = lang;
    default_layer_set((layer_state_t)1 << layer);
    layer_clear();
}

void switch_layer(void) {
    const uint8_t lang = current_lang;
    if (lang == US) { return; } // switching layer not possible for US keyboard language.
    const uint8_t df = get_highest_layer(default_layer_state);
    switch  (df)  {
        case _COLEMAKDH_US:
            set_default_layer_and_lang(_COLEMAKDH_SE, lang);
            break;
        case _COLEMAKDH_SE:
            set_default_layer_and_lang(_COLEMAKDH_US, lang);
            break;
        case _QWERTY_US:
            set_default_layer_and_lang(_QWERTY_SE, lang);
            break;
        case _QWERTY_SE:
            set_default_layer_and_lang(_QWERTY_US, lang);
            break;
        default:
            break;
    }
}

bool process_default_layer_keycodes(uint16_t keycode, keyrecord_t *record) {
    if (keycode < DFC_FIRST_ || keycode > DFC_LAST_) {
        return true;
    }

    if (!record->event.pressed) { return false; }
    switch (keycode) {
        case DFC_CUS:
            set_default_layer_and_lang(_COLEMAKDH_US, US);
            return false;
        case DFC_CSE:
            set_default_layer_and_lang(_COLEMAKDH_SE, SWE);
            return false;
        case DFC_CEN:
            set_default_layer_and_lang(_COLEMAKDH_US, SWE);
            return false;
        case DFC_QUS:
            set_default_layer_and_lang(_QWERTY_US, US);
            return false;
        case DFC_QSE:
            set_default_layer_and_lang(_QWERTY_SE, SWE);
            return false;
        case DFC_QEN:
            set_default_layer_and_lang(_QWERTY_US, SWE);
            return false;
        case DFC_LAY:
            switch_layer();
            return false;
        default:
            return false;
    }
}
