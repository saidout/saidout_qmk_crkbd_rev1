
LTO_ENABLE     = yes  # Enables Link Time Optimization (LTO) when compiling the keyboard.
SPLIT_KEYBOARD = yes

CONSOLE_ENABLE = no
COMMAND_ENABLE = no

TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
EXTRAKEY_ENABLE  = yes
MOUSEKEY_ENABLE  = yes

OLED_ENABLE = yes
OLED_DRIVER = ssd1306

RGBLIGHT_ENABLE   = no
RGB_MATRIX_ENABLE = yes

BOOTMAGIC_ENABLE  = no

SRC += ./oled.c \
       ./dfc_keys.c \
       ./language_keys.c \
       ./process_tap_dance_adv.c \
       ./rgb_layer.c \
       ./caps_word_split_sync.c
