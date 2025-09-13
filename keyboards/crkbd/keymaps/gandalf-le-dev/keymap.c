#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,  KC_A,    KC_R,LCTL_T(KC_S),LSFT_T(KC_T),KC_G,                    KC_M,LSFT_T(KC_N), KC_E,    KC_I,   KC_O,     KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,  KC_H,LCTL_T(KC_COMM),KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LALT,   MO(2), KC_SPC,       KC_ENT, MO(1), RSFT_T(KC_CAPS)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______,  KC_0,   KC_1,   KC_2,   KC_3,   KC_PMNS,                          KC_PGUP, KC_HOME, XXXXXXX,  KC_END,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_PSLS,  KC_4,   KC_5,   KC_6,   KC_PPLS,                         KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_PAST,  KC_7,   KC_8,   KC_9,   KC_PEQL,                         KC_PGDN, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,  TG(4),  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_DEL ,  XXXXXXX,  KC_LBRC, KC_LCBR, KC_LPRN, XXXXXXX,                      KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, XXXXXXX, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX	,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_MINS, KC_PLUS, KC_TILD, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,  _______,  _______,    _______, MO(3), _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,                        KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F13,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,  _______,  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

      [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LALT,  XXXXXXX, KC_SPC,    KC_ENT, TG(4), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE


    uint32_t anim_sleep = 0;
    /* status variables */
    int   current_wpm = 0;
    led_t led_usb_state;

    /* 32 * 32 logo */
    static void render_logo(void) {
        static const char PROGMEM hexagram_logo[] = {
        0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x70, 0x18, 0x06,
        0x06, 0x18, 0x70, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x07, 0x1f, 0x32, 0x66, 0xc4, 0x6c, 0x38, 0x1e, 0x37, 0x61, 0xc0, 0x80, 0x80,
        0x80, 0x80, 0xc0, 0x61, 0x37, 0x1e, 0x38, 0x6c, 0xc4, 0x66, 0x32, 0x1f, 0x07, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x80, 0xe0, 0xf8, 0x4c, 0x66, 0x23, 0x36, 0x1c, 0x78, 0xec, 0x86, 0x03, 0x01, 0x01,
        0x01, 0x01, 0x03, 0x86, 0xec, 0x78, 0x1c, 0x36, 0x23, 0x66, 0x4c, 0xf8, 0xe0, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0e, 0x18, 0x60,
        0x60, 0x18, 0x0e, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00
    };
        oled_write_raw_P(hexagram_logo, sizeof(hexagram_logo));
    }

    static void print_logo_narrow(void) {
        render_logo();
        if (current_wpm > 0) {
            anim_sleep = timer_read32();
            /* wpm counter */
            oled_set_cursor(0, 14);
            oled_write(get_u8_str(get_current_wpm(), '0'), false);

            oled_set_cursor(0, 15);
            oled_write(" wpm", false);

            /* this fixes the screen on and off bug */

        } else if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            /* clear */
            oled_set_cursor(0,0);
            oled_write("                                                                                                                        ", false);
            oled_off();


        }
    }

    static void print_status_narrow(void) {
        render_logo();
        /* Print current layer */
        oled_set_cursor(0, 6);
        oled_write("LAYER", false);

        oled_set_cursor(0, 8);

        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write("Base ", false);
                break;
            case 1:
                oled_write("Lower", false);
                break;
            case 2:
                oled_write("Raise", false);
                break;
            case 3:
                oled_write("Func ", false);
                break;
            case 4:
                oled_write("Game ", false);
                break;
            default:
                oled_write("Undef", false);
        }
    }

    oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

    bool oled_task_user(void) {

        current_wpm   = get_current_wpm();
        led_usb_state = host_keyboard_led_state();

        if (is_keyboard_master()) {
            print_status_narrow();
        } else {
            print_logo_narrow();
        }
        return false;
    }
#endif
