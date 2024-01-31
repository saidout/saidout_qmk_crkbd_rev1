#ifdef SPLIT_CAPS_WORD_ENABLE

#include QMK_KEYBOARD_H
#include <transactions.h>
#include <stdbool.h>
#include "caps_word_split_sync.h"

typedef struct _split_current_caps_word_sync_t {
    bool is_caps_word_on;
} split_caps_word_sync_t;

static void caps_word_slave_handler(uint8_t in_data_size, const void* in_data, uint8_t out_data_size, void* out_data) {
    const split_caps_word_sync_t *m2s = (const split_caps_word_sync_t*)in_data;
    const bool is_caps_word_active = m2s->is_caps_word_on;
    if (is_caps_word_active) {
        caps_word_on();
    } else {
        caps_word_off();
    }
    split_caps_word_sync_t *s2m = (split_caps_word_sync_t*)out_data;
    s2m->is_caps_word_on = is_caps_word_on();
}

void caps_word_register_slave_handler(void) {
    transaction_register_rpc(PUT_CAPS_WORD, caps_word_slave_handler);
}

void caps_word_sync_if_changed(void) {
    if (!is_keyboard_master()) { return; }
    static bool last_sync_caps_word_on = false;  // QMK sets caps word to false at startup, see qmk_firmware/quantum/caps_word.c
    static uint32_t last_sync_time = 0;
    const bool is_caps_word_active = is_caps_word_on();
    if (last_sync_caps_word_on == is_caps_word_active || timer_elapsed32(last_sync_time) < 500) { return; }
    split_caps_word_sync_t m2s = { .is_caps_word_on = is_caps_word_active };
    split_caps_word_sync_t s2m = { false };
    if (transaction_rpc_exec(PUT_CAPS_WORD, sizeof(m2s), &m2s, sizeof(s2m), &s2m)) {
        last_sync_caps_word_on = s2m.is_caps_word_on;
        last_sync_time = timer_read32();
    }
}

#endif // SPLIT_CAPS_WORD_ENABLE
