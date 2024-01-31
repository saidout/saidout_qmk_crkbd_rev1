#ifdef TAP_DANCE_ENABLE

#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "process_tap_dance_adv.h"
#include "layer_names.h"

static bool is_oneshot_mods_on(uint8_t mods) {
    return (get_oneshot_mods() & mods) == mods;
}

static void tap_dance_adv_key_register(tap_dance_state_t *state, void *user_data, bool should_register_keycode) {
    if (state->count < 1 || state->count > 2) return;
    const tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    const uint16_t keycode = state->count == 1 ? pair->kc1 : pair->kc2;
    switch (keycode) {
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            if (should_register_keycode) {
                layer_invert(QK_TOGGLE_LAYER_GET_LAYER(keycode));
                if (layer_state_is(_NUMBERNAVIGATION) && !layer_state_is(_NUMBER)) {
                    layer_off(_NUMBERNAVIGATION);
                }
            }
            return;
        case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            if (should_register_keycode) {
                const uint8_t osh_layer = QK_ONE_SHOT_LAYER_GET_LAYER(keycode);
                set_oneshot_layer(osh_layer, ONESHOT_START);
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            return;
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX: ;
            const uint8_t osh_mods = QK_ONE_SHOT_MOD_GET_MODS(keycode);
            if (should_register_keycode) {
                if (state->interrupted || !state->pressed) { // User has tapped the key
                    if (is_oneshot_mods_on(osh_mods)) {
                        del_oneshot_mods(osh_mods);
                    } else {
                        add_oneshot_mods(osh_mods);
                    }
                } else { // User is holding the key
                    del_oneshot_mods(osh_mods);
                    register_mods(osh_mods);
                }
            } else {
                if (!state->interrupted || state->pressed) { // User has hold down the key
                    unregister_mods(osh_mods);
                }
            }
            return;
        default:
            if (should_register_keycode) {
                register_code16(keycode);
            } else {
                unregister_code16(keycode);
            }
            return;
    }
}

void tap_dance_adv_key_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_adv_key_register(state, user_data, true);
}

void tap_dance_adv_key_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_adv_key_register(state, user_data, false);
}

#endif // TAP_DANCE_ENABLE
