#include QMK_KEYBOARD_H
#include "layer_names.h"
#include "dfc_keys.h"
#include "language_keys.h"
#include "process_tap_dance_adv.h"
#include "custom_keycode_ranges.h"
#include "rgb_layer.h"
#include "caps_word_split_sync.h"

enum custom_keycodes {
    CK_CLEAR_ONE_SHOT_LAYER_AND_TG_SYMBOL = CKR_SAFE_RANGE
};

enum tap_dance_names {
    TD_SYMBOL_NAVIGATION,
    TD_NUMBER_FUNCMEDIA,
    TD_OSFT_OGUI,
    TD_OCTL_OALT,
    TD_SPC_OCTL,
    TD_ENT_OSFT,
    TD_XX_MANG,
    TD_GRV_ACUT,
    TD_MOAD_XXMO,
    TD_MOQU_XXMO,
    TD_WTOD_XXWT,
    TD_SLAR_XXSL,
    TD_SECT_HALF,
    TD_EURO_PND,
    TD_CURR_DIAE
};

#ifdef RGB_MATRIX_ENABLE
#    define CK_RLTG   RLC_TG
#else
#    define CK_RLTG   XXXXXXX
#endif // RGB_MATRIX_ENABLE

#define KC_CBSP   LCTL(KC_BSPC)
#define KC_STAB   LSFT(KC_TAB)
#define KC_CADE   LCA(KC_DEL)
#define KC_SALT   LSFT(KC_LALT)
#define OSM_GUI   OSM(MOD_LGUI)
#define OSM_CTL   OSM(MOD_LCTL)
#define OSM_ALT   OSM(MOD_LALT)
#define OSM_SFT   OSM(MOD_LSFT)

#define OSL_SYM   OSL(_SYMBOL)
#define OTG_SYM   CK_CLEAR_ONE_SHOT_LAYER_AND_TG_SYMBOL
#define TG_NUMB   TG(_NUMBER)
#define TG_NUNA   TG(_NUMBERNAVIGATION)
#define TG_NAVI   TG(_NAVIGATION)
#define TG_FUNC   TG(_FUNCMEDIA)
#define TG_MOUS   TG(_MOUSE)
#define TG_MANG   TG(_MANAGEMENT)

#define TD_SYNA   TD(TD_SYMBOL_NAVIGATION)
#define TD_NUFU   TD(TD_NUMBER_FUNCMEDIA)
#define TD_OSOG   TD(TD_OSFT_OGUI)
#define TD_OCOA   TD(TD_OCTL_OALT)
#define TD_GRAC   TD(TD_GRV_ACUT)
#define TD_MOAD   TD(TD_MOAD_XXMO)
#define TD_MOQU   TD(TD_MOQU_XXMO)
#define TD_WTOD   TD(TD_WTOD_XXWT)
#define TD_SLAR   TD(TD_SLAR_XXSL)
#define TD_SEHA   TD(TD_SECT_HALF)
#define TD_EUPN   TD(TD_EURO_PND)
#define TD_CUDI   TD(TD_CURR_DIAE)

tap_dance_action_t tap_dance_actions[] = {
    [TD_SYMBOL_NAVIGATION] = ACTION_TAP_DANCE_ADV_KEY(OSL_SYM, TG_NAVI),
    [TD_NUMBER_FUNCMEDIA]  = ACTION_TAP_DANCE_ADV_KEY(TG_NUMB, TG_FUNC),
    [TD_OSFT_OGUI]         = ACTION_TAP_DANCE_ADV_KEY(OSM_SFT, OSM_GUI),
    [TD_OCTL_OALT]         = ACTION_TAP_DANCE_ADV_KEY(OSM_CTL, OSM_ALT),
    [TD_XX_MANG]           = ACTION_TAP_DANCE_ADV_KEY(KC_NO, TG_MANG),
    [TD_GRV_ACUT]          = ACTION_TAP_DANCE_LANG(LL_GRV, LL_ACUT),
    [TD_MOAD_XXMO]         = ACTION_TAP_DANCE_LANG(LL_MOAD, LL_MOMO),
    [TD_MOQU_XXMO]         = ACTION_TAP_DANCE_LANG(LL_MOQU, LL_MOMO),
    [TD_WTOD_XXWT]         = ACTION_TAP_DANCE_LANG(LL_WTOD, LL_WTWT),
    [TD_SLAR_XXSL]         = ACTION_TAP_DANCE_LANG(LL_SLAR, LL_SLSH),
    [TD_SECT_HALF]         = ACTION_TAP_DANCE_LANG(LL_SECT, LL_HALF),
    [TD_EURO_PND]          = ACTION_TAP_DANCE_LANG(LL_EURO, LL_PND),
    [TD_CURR_DIAE]         = ACTION_TAP_DANCE_LANG(LL_CURR, LL_DIAE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAKDH_US] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,    KC_U,    KC_Y, LL_SCLN, TG_MOUS,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,    KC_E,    KC_I,    KC_O, LL_QUOT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H, KC_COMM,  KC_DOT, LL_SLSH, LL_WTWT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TD_OSOG, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_COLEMAKDH_SE] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,    KC_U,    KC_Y, LL_SCLN, TD_MOQU,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,    KC_E,    KC_I,    KC_O, LL_QUAD,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H, KC_COMM,  KC_DOT, TD_SLAR, TD_WTOD,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TD_OSOG, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_QWERTY_US] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, TG_MOUS,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L, LL_SCLN, LL_QUOT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, LL_SLSH, LL_WTWT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TD_OSOG, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_QWERTY_SE] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, TD_MOQU,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L, LL_SCLN, LL_QUAD,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, TD_SLAR, TD_WTOD,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TD_OSOG, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_SYMBOL] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC, LL_TILD, LL_ASTR, LL_COLN, LL_LCBR, LL_LBRC,         LL_RBRC, LL_RCBR, LL_SCLN, LL_QUOT, KC_COMM, TD_GRAC,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP, LL_SLSH, LL_PLUS, LL_UNDS, LL_LPRN, LL_LABK,         LL_RABK, LL_RPRN, LL_MINS, LL_DQUO,  LL_EQL, LL_PERC,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC, LL_BSLS,  LL_GRV,  LL_DLR, LL_AMPR, LL_QUES,         LL_PIPE, LL_EXLM,   LL_AT,  KC_DOT, LL_HASH, LL_CIRC,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, OTG_SYM, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_NUMBER] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC, TD_SEHA, LL_LPRN,  LL_EQL, LL_PLUS, LL_CIRC,         XXXXXXX, LL_MINS,  KC_DOT, LL_RPRN, TD_CUDI, DFC_LAY,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP,    KC_4,    KC_3,    KC_2,    KC_1,    KC_5,            KC_6,    KC_0,    KC_9,    KC_8,    KC_7, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC, XXXXXXX, XXXXXXX, LL_COLN, LL_ASTR, KC_STAB,          KC_TAB, LL_SLSH, KC_COMM, TD_EUPN, LL_MICR, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TG_NUNA, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_NUMBERNAVIGATION] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, LL_LCBR, LL_LBRC,         LL_RBRC, LL_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, DFC_LAY,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP, KC_HOME, XXXXXXX, KC_LEFT,   KC_UP, KC_PGUP,         KC_PGDN, KC_DOWN, KC_RGHT, XXXXXXX,  KC_END, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_STAB,          KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TG_NUNA, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_NAVIGATION] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC, XXXXXXX, KC_LALT,   KC_UP, KC_PGUP, KC_SCRL,         KC_LWIN,  KC_APP, KC_STAB,  KC_TAB, KC_PAUS, KC_CADE,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP, LL_SLSH, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,         KC_PSCR,  KC_INS,  KC_DEL, KC_HOME,  KC_END, TG_MOUS,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC, LL_BSLS, XXXXXXX, OSM_GUI, OSM_CTL, KC_STAB,          KC_TAB,  KC_DOT, OSM_ALT, XXXXXXX, XXXXXXX, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TD_OSOG, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_FUNCMEDIA] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,         XXXXXXX, KC_MNXT, KC_MSTP, KC_MPLY, XXXXXXX, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, TG_MOUS,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC,  KC_F15,  KC_F14,  KC_F13,  KC_F12,  KC_F11,         XXXXXXX, KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TD_OSOG, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_MOUSE] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, KC_WFWD,         KC_WREF, KC_ACL2, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WBAK,         KC_ACL1, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, TG_MOUS,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_MANG,         XXXXXXX, KC_ACL0, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_SYNA, KC_BTN1, KC_BTN3,         KC_BTN2, KC_LSFT, KC_LCTL
                               /*.--------------------------.       .--------------------------.*/
    ),
    [_MANAGEMENT] = LAYOUT_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         KC_ESC, XXXXXXX, DFC_CUS, DFC_QUS, XXXXXXX, XXXXXXX,         CK_RLTG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_CBSP, XXXXXXX, DFC_CSE, DFC_QSE, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_MOUS,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
        KC_BSPC, XXXXXXX, DFC_CEN, DFC_QEN, XXXXXXX, TG_MANG,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                   TD_OCOA, TD_OSOG, TD_SYNA,          KC_ENT,  KC_SPC, TD_NUFU
                               /*.--------------------------.       .--------------------------.*/
    )
};

#ifdef RGB_MATRIX_ENABLE
#    define C_OFF   { 0x00, 0x00, 0x00 }
#    define C_STBL  { 0x46, 0x82, 0xB4 }  /* Steel Blue   */
#    define C_YELL  { 0xFF, 0xFF, 0x00 }  /* Yellow       */
#    define C_WHIT  { 0xFF, 0xFF, 0xFF }  /* White        */
#    define C_PURP  { 0x7A, 0x00, 0xFF }  /* Purple       */
#    define C_GOLD  { 0xD9, 0xA5, 0x21 }  /* Goldenrod    */
#    define C_BLUE  { 0x00, 0x00, 0xFF }  /* Blue         */
#    define C_ORAN  { 0xFF, 0x80, 0x00 }  /* Orange       */
#    define C_RED   { 0xFF, 0x00, 0x00 }  /* Red          */
#    define C_SPGR  { 0x00, 0xFF, 0x80 }  /* Spring Green */
#    define C_PINK  { 0xFF, 0x80, 0xBF }  /* Pink         */
#    define C_CYAN  { 0x00, 0xFF, 0xFF }  /* Cyan         */
#    define C_MAGE  { 0xFF, 0x00, 0xFF }  /* Magents      */

enum layer_color_index {
    LI_SYMBOL,
    LI_NUMBER,
    LI_NUMBERNAVIGATION,
    LI_NAVIGATION,
    LI_FUNCMEDIA,
    LI_MOUSE,
    LI_MANAGEMENT
};

const uint8_t rgb_layer_colors_index[] = {
    [_COLEMAKDH_US] = RGB_LAYER_ALL_COLORS_OFF,
    [_COLEMAKDH_SE] = RGB_LAYER_ALL_COLORS_OFF,
    [_QWERTY_US] = RGB_LAYER_ALL_COLORS_OFF,
    [_QWERTY_SE] = RGB_LAYER_ALL_COLORS_OFF,
    [_SYMBOL] = LI_SYMBOL,
    [_NUMBER] = LI_NUMBER,
    [_NUMBERNAVIGATION] = LI_NUMBERNAVIGATION,
    [_NAVIGATION] = LI_NAVIGATION,
    [_FUNCMEDIA] = LI_FUNCMEDIA,
    [_MOUSE] = LI_MOUSE,
    [_MANAGEMENT] = LI_MANAGEMENT
};

const RgbColor PROGMEM rgb_layer_colors[][MATRIX_ROWS][MATRIX_COLS] = {
    [LI_SYMBOL] = COLOR_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,          C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,          C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,          C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,  C_STBL,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                    C_STBL,  C_STBL,  C_STBL,          C_STBL,  C_STBL,  C_STBL
                               /*.--------------------------.       .--------------------------.*/
    ),
    [LI_NUMBER] = COLOR_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         C_WHIT,  C_YELL,  C_BLUE,  C_GOLD,  C_GOLD,  C_GOLD,           C_OFF,  C_GOLD,  C_PURP,  C_BLUE,  C_YELL,  C_SPGR,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,  C_PURP,  C_PURP,  C_PURP,  C_PURP,  C_PURP,          C_PURP,  C_PURP,  C_PURP,  C_PURP,  C_PURP,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,   C_OFF,   C_OFF,  C_BLUE,  C_GOLD,  C_ORAN,          C_ORAN,  C_GOLD,  C_PURP,  C_YELL,  C_YELL,  C_SPGR,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                    C_PURP,  C_PURP,  C_PURP,          C_PURP,  C_PURP,  C_PURP
                               /*.--------------------------.       .--------------------------.*/
    ),
    [LI_NUMBERNAVIGATION] = COLOR_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         C_WHIT,   C_OFF,   C_OFF,   C_OFF,  C_STBL,  C_STBL,          C_STBL,  C_STBL,   C_OFF,   C_OFF,   C_OFF,  C_SPGR,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,  C_YELL,   C_OFF,  C_GOLD,  C_GOLD,  C_YELL,          C_YELL,  C_GOLD,  C_GOLD,   C_OFF,  C_YELL,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,   C_OFF,   C_OFF,   C_OFF,   C_OFF,  C_ORAN,          C_ORAN,   C_OFF,   C_OFF,   C_OFF,   C_OFF,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                    C_PURP,  C_PURP,  C_PURP,          C_PURP,  C_PURP,  C_PURP
                               /*.--------------------------.       .--------------------------.*/
    ),
    [LI_NAVIGATION] = COLOR_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         C_WHIT,   C_OFF,  C_BLUE,  C_GOLD,  C_YELL,  C_SPGR,          C_BLUE,  C_BLUE,  C_ORAN,  C_ORAN,  C_SPGR,  C_BLUE,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,  C_PINK,  C_GOLD,  C_GOLD,  C_GOLD,  C_YELL,          C_SPGR,   C_RED,   C_RED,  C_YELL,  C_YELL,  C_WHIT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,  C_PINK,   C_OFF,  C_BLUE,  C_BLUE,  C_ORAN,          C_ORAN,  C_PINK,  C_BLUE,   C_OFF,   C_OFF,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                    C_GOLD,  C_GOLD,  C_GOLD,          C_GOLD,  C_GOLD,  C_GOLD
                               /*.--------------------------.       .--------------------------.*/
    ),
    [LI_FUNCMEDIA] = COLOR_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         C_WHIT,  C_CYAN,  C_CYAN,  C_GOLD,  C_CYAN,  C_CYAN,           C_OFF,  C_MAGE,  C_MAGE,  C_MAGE,   C_OFF,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,  C_CYAN,  C_CYAN,  C_CYAN,  C_GOLD,  C_CYAN,           C_OFF,  C_SPGR,  C_SPGR,  C_SPGR,   C_OFF,  C_WHIT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,  C_CYAN,  C_CYAN,  C_CYAN,  C_GOLD,  C_CYAN,           C_OFF,  C_MAGE,   C_OFF,   C_OFF,   C_OFF,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                    C_CYAN,  C_CYAN,  C_CYAN,          C_CYAN,  C_CYAN,  C_CYAN
                               /*.--------------------------.       .--------------------------.*/
    ),
    [LI_MOUSE] = COLOR_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         C_WHIT,   C_OFF,   C_OFF,  C_GOLD,   C_OFF,  C_YELL,          C_YELL,  C_PURP, C_GOLD,   C_OFF,   C_OFF,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,   C_OFF,  C_GOLD,  C_GOLD,  C_GOLD,  C_YELL,          C_PURP,  C_GOLD,  C_GOLD,  C_GOLD,   C_OFF,  C_WHIT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,   C_OFF,   C_OFF,   C_OFF,   C_OFF,  C_ORAN,           C_OFF,  C_PURP,  C_BLUE,   C_OFF,   C_OFF,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                    C_WHIT,  C_SPGR,  C_SPGR,          C_SPGR,  C_BLUE,  C_BLUE
                               /*.--------------------------.       .--------------------------.*/
    ),
    [LI_MANAGEMENT] = COLOR_split_3x6_3(
    /*.-----------------------------------------------------.       .-----------------------------------------------------.*/
         C_WHIT,   C_OFF,  C_SPGR,  C_SPGR,   C_OFF,   C_OFF,          C_BLUE,   C_OFF,   C_OFF,   C_OFF,   C_OFF,   C_RED,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,   C_OFF,  C_SPGR,  C_SPGR,   C_OFF,   C_OFF,           C_OFF,   C_OFF,   C_OFF,   C_OFF,   C_OFF,  C_WHIT,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
         C_WHIT,   C_OFF,  C_SPGR,  C_SPGR,   C_OFF,  C_ORAN,           C_OFF,   C_OFF,   C_OFF,   C_OFF,   C_OFF,   C_OFF,
    /*|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|*/
                                    C_ORAN,  C_ORAN,  C_ORAN,          C_ORAN,  C_ORAN,  C_ORAN
                               /*.--------------------------.       .--------------------------.*/
    )
};
#endif // RGB_MATRIX_ENABLE

/**
 * @brief QMK function that is called after the keyboard initialization process has finished.
 */
void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_layer_setup();
#endif // RGB_MATRIX_ENABLE
#ifdef SPLIT_LANG_ENABLE
    current_lang_register_slave_handler();
#endif // SPLIT_LANG_ENABLE
#ifdef SPLIT_CAPS_WORD_ENABLE
    caps_word_register_slave_handler();
#endif // SPLIT_CAPS_WORD_ENABLE
}

/**
 * @brief QMK function that is called at the end of all QMK processing.
 *
 * Function is called before the next iteration and you can safely assume that QMK has:
 *  - dealt with the last matrix scan
 *  - updated layer states
 *  - sent all USB reports
 *  - updated LEDs
 *  - drawn the displays
 * when the function gets called.
 */
void housekeeping_task_user(void) {
#ifdef SPLIT_LANG_ENABLE
    current_lang_sync_if_changed();
#endif // SPLIT_LANG_ENABLE
#ifdef SPLIT_CAPS_WORD_ENABLE
    caps_word_sync_if_changed();
#endif // SPLIT_CAPS_WORD_ENABLE
#ifdef RGB_MATRIX_ENABLE
    //rgb_check_timeout();
#endif // RGB_MATRIX_ENABLE
}

/**
 * @brief QMK function that gets called every time a key is pressed or released.
 *
 * The function is called by QMK during key processing before the actual key
 * event is handled.
 *
 * @param keycode keycode (that is defined in keymaps variable) that is associated with the affected key.
 * @param record information about the actual press event.
 * @return If true QMK will process the keycode as usual. If false QMK will
 *         skip the normal key handling.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == OTG_SYM) {
        if (record->event.pressed) {
            if (is_oneshot_layer_active()) {
                reset_oneshot_layer();
                layer_on(_SYMBOL);
            } else {
                layer_off(_SYMBOL);
            }
        }
        return true;
    }

    return
#ifdef RGB_MATRIX_ENABLE
        process_rgb_keycodes(keycode, record) &&
#endif // RGB_MATRIX_ENABLE
        process_lang_keycodes(keycode, record) &&
        process_default_layer_keycodes(keycode, record);
}

/*
 * @brief QMK callback function tha is called on every key pressed when Caps Word is active.
 *
 * @keycode The keycode of the key that was pressed.
 * @return true to cotinue the "word", i.e. Caps Word will still be active. false indicates
 *         "word breaking", i.e. it deactivates Caps Word.
 */
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        /* Keycodes that continue Caps Word, with shift applied. */
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  /* Apply shift to next key. */
            return true;
        /* Keycodes that continue Caps Word, without shifting. */
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
