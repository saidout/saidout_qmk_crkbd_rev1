#pragma once

#define OLED_RBG_TIMEOUT    45000

#ifndef NO_DEBUG
#    define NO_DEBUG
#endif //  NO_DEBUG
#ifndef NO_PRINT
#    define NO_PRINT
#endif // NO_PRINT

#define MASTER_LEFT
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_LANG_ENABLE
#ifdef  CAPS_WORD_ENABLE
#    define SPLIT_CAPS_WORD_ENABLE
#endif // CAPS_WORD_ENABLE

#define SPLIT_TRANSACTION_IDS_USER PUT_CURRENT_LANG, PUT_CAPS_WORD

#ifdef MOUSEKEY_ENABLE
#    define MK_COMBINED
#endif // MOUSEKEY_ENABLE

#ifdef TAP_DANCE_ENABLE
#    define TAPPING_TERM 175
#endif // TAP_DANCE_ENABLE

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define SPLIT_OLED_ENABLE
#    define OLED_TIMEOUT         OLED_RBG_TIMEOUT
#endif // OLED_ENABLE

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_TIMEOUT   OLED_RBG_TIMEOUT
#endif // RGB_MATRIX_ENABLE

#ifdef BOOTMAGIC_ENABLE
#    /* Top left key on left half */
#    define BOOTMAGIC_LITE_ROW 0
#    define BOOTMAGIC_LITE_COLUMN 5
#    /* Top right key on right half */
#    define BOOTMAGIC_LITE_ROW_RIGHT 4
#    define BOOTMAGIC_LITE_COLUMN_RIGHT 5
#endif // BOOTMAGIC_ENABLE
