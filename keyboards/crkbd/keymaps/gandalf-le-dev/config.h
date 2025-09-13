
#pragma once

#define MASTER_LEFT

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_ALPHAS_MODS
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

#    define ENABLE_RGB_MATRIX_ALPHAS_MODS

#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_WPM_ENABLE //Enable WPM across split keyboards (+268).
#define NO_ACTION_ONESHOT