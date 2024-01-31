#include QMK_KEYBOARD_H
#include <transactions.h>
#include <keymap_swedish.h>
#include "layer_names.h"
#include "language_keys.h"

uint8_t current_lang = US;

#define TG_MOUS   TG(_MOUSE)

typedef struct {
    uint16_t us_key;
    uint16_t swe_key;
} lang_key_mapping_t;

const lang_key_mapping_t PROGMEM lang_key_mappings[] = {
    [LL_QUOT - LL_FIRST_] = { .us_key = KC_QUOT, .swe_key = SE_QUOT },
    [LL_DQUO - LL_FIRST_] = { .us_key = KC_DQUO, .swe_key = SE_DQUO },
    [LL_QUAD - LL_FIRST_] = { .us_key = KC_QUOT, .swe_key = SE_ADIA },
    [LL_MOAD - LL_FIRST_] = { .us_key = TG_MOUS, .swe_key = SE_ADIA },
    [LL_MOQU - LL_FIRST_] = { .us_key = TG_MOUS, .swe_key = SE_QUOT },
    [LL_MOMO - LL_FIRST_] = { .us_key = TG_MOUS, .swe_key = TG_MOUS },
    [LL_WTOD - LL_FIRST_] = { .us_key = CW_TOGG, .swe_key = SE_ODIA },
    [LL_WTWT - LL_FIRST_] = { .us_key = CW_TOGG, .swe_key = CW_TOGG },
    [LL_SLAR - LL_FIRST_] = { .us_key = KC_SLSH, .swe_key = SE_ARNG },
    [LL_SCLN - LL_FIRST_] = { .us_key = KC_SCLN, .swe_key = SE_SCLN },
    [LL_TILD - LL_FIRST_] = { .us_key = KC_TILD, .swe_key = SE_TILD },
    [LL_ASTR - LL_FIRST_] = { .us_key = KC_ASTR, .swe_key = SE_ASTR },
    [LL_COLN - LL_FIRST_] = { .us_key = KC_COLN, .swe_key = SE_COLN },
    [LL_LCBR - LL_FIRST_] = { .us_key = KC_LCBR, .swe_key = SE_LCBR },
    [LL_RCBR - LL_FIRST_] = { .us_key = KC_RCBR, .swe_key = SE_RCBR },
    [LL_LBRC - LL_FIRST_] = { .us_key = KC_LBRC, .swe_key = SE_LBRC },
    [LL_RBRC - LL_FIRST_] = { .us_key = KC_RBRC, .swe_key = SE_RBRC },
    [LL_LABK - LL_FIRST_] = { .us_key = KC_LABK, .swe_key = SE_LABK },
    [LL_RABK - LL_FIRST_] = { .us_key = KC_RABK, .swe_key = SE_RABK },
    [LL_LPRN - LL_FIRST_] = { .us_key = KC_LPRN, .swe_key = SE_LPRN },
    [LL_RPRN - LL_FIRST_] = { .us_key = KC_RPRN, .swe_key = SE_RPRN },
    [LL_SLSH - LL_FIRST_] = { .us_key = KC_SLSH, .swe_key = SE_SLSH },
    [LL_BSLS - LL_FIRST_] = { .us_key = KC_BSLS, .swe_key = SE_BSLS },
    [LL_UNDS - LL_FIRST_] = { .us_key = KC_UNDS, .swe_key = SE_UNDS },
    [LL_MINS - LL_FIRST_] = { .us_key = KC_MINS, .swe_key = SE_MINS },
    [LL_PLUS - LL_FIRST_] = { .us_key = KC_PLUS, .swe_key = SE_PLUS },
    [LL_EQL  - LL_FIRST_] = { .us_key =  KC_EQL, .swe_key = SE_EQL  },
    [LL_PERC - LL_FIRST_] = { .us_key = KC_PERC, .swe_key = SE_PERC },
    [LL_ACUT - LL_FIRST_] = { .us_key = XXXXXXX, .swe_key = SE_ACUT },
    [LL_GRV  - LL_FIRST_] = { .us_key =  KC_GRV, .swe_key = SE_GRV  },
    [LL_DLR  - LL_FIRST_] = { .us_key =  KC_DLR, .swe_key = SE_DLR  },
    [LL_AMPR - LL_FIRST_] = { .us_key = KC_AMPR, .swe_key = SE_AMPR },
    [LL_QUES - LL_FIRST_] = { .us_key = KC_QUES, .swe_key = SE_QUES },
    [LL_PIPE - LL_FIRST_] = { .us_key = KC_PIPE, .swe_key = SE_PIPE },
    [LL_EXLM - LL_FIRST_] = { .us_key = KC_EXLM, .swe_key = SE_EXLM },
    [LL_AT   - LL_FIRST_] = { .us_key =   KC_AT, .swe_key = SE_AT   },
    [LL_HASH - LL_FIRST_] = { .us_key = KC_HASH, .swe_key = SE_HASH },
    [LL_CIRC - LL_FIRST_] = { .us_key = KC_CIRC, .swe_key = SE_CIRC },
    [LL_SECT - LL_FIRST_] = { .us_key = XXXXXXX, .swe_key = SE_SECT },
    [LL_DIAE - LL_FIRST_] = { .us_key = XXXXXXX, .swe_key = SE_DIAE },
    [LL_HALF - LL_FIRST_] = { .us_key = XXXXXXX, .swe_key = SE_HALF },
    [LL_CURR - LL_FIRST_] = { .us_key = XXXXXXX, .swe_key = SE_CURR },
    [LL_PND  - LL_FIRST_] = { .us_key = XXXXXXX, .swe_key = SE_PND  },
    [LL_EURO - LL_FIRST_] = { .us_key = XXXXXXX, .swe_key = SE_EURO },
    [LL_MICR - LL_FIRST_] = { .us_key = XXXXXXX, .swe_key = SE_MICR }
};

bool process_lang_keycodes(uint16_t keycode, keyrecord_t *record) {
    if (keycode < LL_FIRST_ || keycode > LL_LAST_) {
        return true;
    }

    lang_key_mapping_t lkm;
    const uint8_t lang_idx = keycode - LL_FIRST_;
    memcpy_P(&lkm, &lang_key_mappings[lang_idx], sizeof(lang_key_mapping_t));
    const uint16_t lang_kc = current_lang == US ? lkm.us_key : lkm.swe_key;
    switch (lang_kc) {
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            if (record->event.pressed) { layer_invert(QK_TOGGLE_LAYER_GET_LAYER(lang_kc)); }
            return false;
        case CW_TOGG:
            if (record->event.pressed) { caps_word_toggle(); }
            return false;
        case KC_NO:
            return false;
        default:
            if (record->event.pressed) {
                register_code16(lang_kc);
            } else {
                unregister_code16(lang_kc);
            }
            return false;
    }
}

enum tap_dance_stage {
    TS_TAP,
    TS_FINISHED,
    TS_RESET
};

static void tap_dance_lang_register_kc(uint16_t keycode, tap_dance_state_t *state, enum tap_dance_stage tds) {
    // assumes state->count is either 1 or 2
    if (tds == TS_TAP && state->count == 1) { return; }
    if (tds == TS_TAP && state->count == 2) { state->finished = true; }
    switch (keycode) {
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            if (tds == TS_RESET) { layer_invert(QK_TOGGLE_LAYER_GET_LAYER(keycode)); }
            return;
        case CW_TOGG:
            if (tds == TS_RESET) { caps_word_toggle(); }
            return;
        case KC_NO:
            return;
        default:
            if (tds == TS_TAP || tds == TS_FINISHED) {
                register_code16(keycode);
            } else {
                if (state->count == 1) { wait_ms(TAP_CODE_DELAY); }
                unregister_code16(keycode);
            }
            return;
    }
}

static void tap_dance_lang_process(tap_dance_state_t *state, void *user_data, enum tap_dance_stage tds) {
    if (state->count < 1 || state->count > 2) return;
    const tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    const uint16_t keycode = state->count == 1 ? pair->kc1 : pair->kc2;

    if (keycode < LL_FIRST_ || keycode > LL_LAST_) {
        tap_dance_lang_register_kc(keycode, state, tds);
        return;
    }

    lang_key_mapping_t lkm;
    const uint8_t lang_idx = keycode - LL_FIRST_;
    memcpy_P(&lkm, &lang_key_mappings[lang_idx], sizeof(lang_key_mapping_t));
    const uint16_t lang_kc = current_lang == US ? lkm.us_key : lkm.swe_key;
    tap_dance_lang_register_kc(lang_kc, state, tds);
}

void tap_dance_lang_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_lang_process(state, user_data, TS_TAP);
}

void tap_dance_lang_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_lang_process(state, user_data, TS_FINISHED);
}

void tap_dance_lang_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_lang_process(state, user_data, TS_RESET);
}

#ifdef SPLIT_LANG_ENABLE
typedef struct _split_current_lang_sync_t {
    uint8_t current_lang;
} split_current_lang_sync_t;

static void current_lang_slave_handler(uint8_t in_data_size, const void* in_data, uint8_t out_data_size, void* out_data) {
    const split_current_lang_sync_t *m2s = (const split_current_lang_sync_t*)in_data;
    current_lang = m2s->current_lang;
    split_current_lang_sync_t *s2m = (split_current_lang_sync_t*)out_data;
    s2m->current_lang = current_lang;
}

void current_lang_register_slave_handler(void) {
    transaction_register_rpc(PUT_CURRENT_LANG, current_lang_slave_handler);
}

void current_lang_sync_if_changed(void) {
    if (!is_keyboard_master()) { return; }
    static uint8_t last_sync_lang = 0xFF;
    static uint32_t last_sync_time = 0;
    if (last_sync_lang == current_lang || timer_elapsed32(last_sync_time) < 500 ) { return; }
    split_current_lang_sync_t m2s = { .current_lang = current_lang };
    split_current_lang_sync_t s2m = { 0xFF };
    if (transaction_rpc_exec(PUT_CURRENT_LANG, sizeof(m2s), &m2s, sizeof(s2m), &s2m)) {
        last_sync_lang = s2m.current_lang;
        last_sync_time = timer_read32();
    }
}
#endif // SPLIT_LANG_ENABLE
