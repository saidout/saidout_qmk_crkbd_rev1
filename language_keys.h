#pragma once

#include "custom_keycode_ranges.h"

enum langs {
    US,
    SWE
};
extern uint8_t current_lang;

// NOTE: If adding new language keycodes make sure to check if the custom_keycode_ranges.h needs to be updated.
enum ll_keycodes {
    LL_FIRST_ = CKR_LANGUAGE,
    LL_QUOT = LL_FIRST_,
    LL_DQUO,
    LL_QUAD,
    LL_MOAD,
    LL_MOQU,
    LL_MOMO,
    LL_WTOD,
    LL_WTWT,
    LL_SLAR,
    LL_SCLN,
    LL_TILD,
    LL_ASTR,
    LL_COLN,
    LL_LCBR,
    LL_RCBR,
    LL_LBRC,
    LL_RBRC,
    LL_LABK,
    LL_RABK,
    LL_LPRN,
    LL_RPRN,
    LL_SLSH,
    LL_BSLS,
    LL_UNDS,
    LL_MINS,
    LL_PLUS,
    LL_EQL,
    LL_PERC,
    LL_ACUT,
    LL_GRV,
    LL_DLR,
    LL_AMPR,
    LL_QUES,
    LL_PIPE,
    LL_EXLM,
    LL_AT,
    LL_HASH,
    LL_CIRC,
    LL_SECT,
    LL_DIAE,
    LL_HALF,
    LL_CURR,
    LL_PND,
    LL_EURO,
    LL_MICR,
    LL_LAST_ = LL_MICR
};

bool process_lang_keycodes(uint16_t keycode, keyrecord_t *record);

#define ACTION_TAP_DANCE_LANG(kc1, kc2) \
    { \
        .fn = { tap_dance_lang_on_each_tap, tap_dance_lang_finished, tap_dance_lang_reset }, \
        .user_data = (void *)&((tap_dance_pair_t){kc1, kc2}), \
    }

#ifdef SPLIT_LANG_ENABLE
void current_lang_register_slave_handler(void);
void current_lang_sync_if_changed(void);
#endif // SPLIT_LANG_ENABLE

/** @brief Internal function to language_keys use the macro ACTION_TAP_DANCE_LANG when setting up language tap dancing. */
void tap_dance_lang_on_each_tap(tap_dance_state_t *state, void *user_data);
/** @brief Internal function to language_keys use the macro ACTION_TAP_DANCE_LANG when setting up language tap dancing. */
void tap_dance_lang_finished(tap_dance_state_t *state, void *user_data);
/** @brief Internal function to language_keys use the macro ACTION_TAP_DANCE_LANG when setting up language tap dancing. */
void tap_dance_lang_reset(tap_dance_state_t *state, void *user_data);
