#pragma once

#ifdef TAP_DANCE_ENABLE

#define ACTION_TAP_DANCE_ADV_KEY(kc1, kc2) \
    { .fn = {NULL, tap_dance_adv_key_finished, tap_dance_adv_key_reset}, .user_data = (void *)&((tap_dance_pair_t){kc1, kc2}), }

/** @brief Internal function to process_tap_dance_adv use the macro ACTION_TAP_DANCE_ADV_KEY when setting up advanced tap dancing. */
void tap_dance_adv_key_finished(tap_dance_state_t *state, void *user_data);
/** @brief Internal function to process_tap_dance_adv use the macro ACTION_TAP_DANCE_ADV_KEY when setting up advanced tap dancing. */
void tap_dance_adv_key_reset(tap_dance_state_t *state, void *user_data);

#endif // TAP_DANCE_ENABLE
