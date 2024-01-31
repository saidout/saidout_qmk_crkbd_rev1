#ifdef OLED_ENABLE

#include QMK_KEYBOARD_H
#include "layer_names.h"
#include "language_keys.h"

#define MMS  MOD_MASK_SHIFT
#define MMC  MOD_MASK_CTRL
#define MMA  MOD_MASK_ALT
#define MMG  MOD_MASK_GUI

/**
 * @brief QMK function for setting the rotation of the screen.
 *
 * @param rotation Default rotation of the screen.
 * @return Rotation the screen should have.
 */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

/**
 * @brief QMK function for rendering the OLED display.
 *
 * Function is called from keyboard_task function in
 * qmk_firmware/quantum/keyboard.c
 *
 * When the function is called:
 *  - the cursor is set to position 0, 0
 *
 * @return Does not seem to be in use. See qmk_firmware/drivers/oled/oled_driver.c
 *         But pattern in QMK is to return false if you handle the event/callback.
 */
bool oled_task_user(void) {
    // IMPORTANT: Code below assumes the OLED display will have 16 rows and 5 columns.
    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAKDH_US:
            if (current_lang == US) {
                oled_write_P(PSTR("COLus"), false);
            } else {
                oled_write_P(PSTR("COLen"), false);
            }
            break;
        case _COLEMAKDH_SE:
            if (current_lang == US) {
                oled_write_P(PSTR("COLxx"), false); // bad state should not happen
            } else {
                oled_write_P(PSTR("COLse"), false);
            }
            break;
        case _QWERTY_US:
            if (current_lang == US) {
                oled_write_P(PSTR("QWEus"), false);
            } else {
                oled_write_P(PSTR("QWEen"), false);
            }
            break;
        case _QWERTY_SE:
            if (current_lang == US) {
                oled_write_P(PSTR("QWExx"), false); // bad state should not happen
            } else {
                oled_write_P(PSTR("QWEse"), false);
            }
            break;
        default:
            oled_write_P(PSTR("UNK\n"), false);
    }
    oled_write_P(PSTR("-----"), false);
    oled_write_P(layer_state_is(_SYMBOL)   ? PSTR("SYM**") : PSTR("SYM  "), false);
    if (layer_state_is(_NUMBERNAVIGATION)) {
        oled_write_P(PSTR("NUMn*"), false);
    } else {
        oled_write_P(layer_state_is(_NUMBER)   ? PSTR("NUM**") : PSTR("NUM  "), false);
    }
    oled_write_P(layer_state_is(_NAVIGATION)  ? PSTR("NAV**") : PSTR("NAV  "), false);
    oled_write_P(layer_state_is(_FUNCMEDIA)   ? PSTR("FUN**") : PSTR("FUN  "), false);
    oled_write_P(layer_state_is(_MOUSE)       ? PSTR("MOU**") : PSTR("MOU  "), false);
    oled_write_P(layer_state_is(_MANAGEMENT)  ? PSTR("MNG**") : PSTR("MNG  "), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("MODS "), false);
    oled_write_P(PSTR("-----"), false);
    const uint8_t osh_mods = get_oneshot_mods();
    const uint8_t mods = get_mods();
    oled_write_P(is_caps_word_on()	   ? PSTR("CW   ") : PSTR("     "), false);
    oled_write_P(osh_mods & MMS ? PSTR("OSFT ") : mods & MMS ? PSTR("SFT  ") : PSTR("     "), false);
    oled_write_P(osh_mods & MMC ? PSTR("OCTRL") : mods & MMC ? PSTR("CTRL ") : PSTR("     "), false);
    oled_write_P(osh_mods & MMA ? PSTR("OALT ") : mods & MMA ? PSTR("ALT  ") : PSTR("     "), false);
    oled_write_P(osh_mods & MMG ? PSTR("OGUI ") : mods & MMG ? PSTR("GUI  ") : PSTR("     "), false);

    return false;
}

#endif // OLED_ENABLE
