ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

BOOTLOADER        = qmk-dfu # caterina is bad and it should feel bad. I don't use anything but DFU
BACKLIGHT_ENABLE  = no      # Enable keyboard backlight functionality
TAP_DANCE_ENABLE  = yes     # Enable tap dance.
UNICODE_ENABLE    = no
UNICODEMAP_ENABLE = yes
UCIS_ENABLE       = yes
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend

USE_IC2         = no
AUDIO_ENABLE    = no
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.

