// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "mitosis.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum mitosis_layers
{
	_QWERTY,
	_DVORAK,
	_LOWER,
	_RAISE,
	_MISC
};

enum mitosis_keycodes 
{
  LOWER = SAFE_RANGE,
  RAISE,
  DVORAK,
  QWERTY
};


// Macro definitions for readability
//enum mitosis_macros
//{
	//VOLU,
	//VOLD,
	//ESCM
//};

//#define LONGPRESS_DELAY 150
//#define LAYER_TOGGLE_DELAY 300

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = { 

  {KC_ESC,  KC_1,    KC_2,     KC_3,  KC_4,   KC_5,      KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_Q,    KC_W,     KC_E,  KC_R,   KC_T,      KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS},
  {KC_LCTRL,KC_A,    KC_S,     KC_D,  KC_F,   KC_G,      KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,     KC_C,  KC_V,   KC_B,      KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT},
  {KC_F17,  KC_LGUI, KC_LALT, LOWER,  KC_SPC, XXXXXXX, XXXXXXX,  KC_SPC,  RAISE,   KC_RALT, KC_RGUI, KC_ENT}
},

[_DVORAK] = {
  
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,       KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH},
  {KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_D,   KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,       KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT},
  {KC_F17,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  XXXXXXX, XXXXXXX,   KC_SPC,  RAISE,   KC_RALT, KC_RGUI, KC_ENT}
},

[_LOWER] = { 

  { KC_GRV, _______, _______, _______, _______, _______,       _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUSE},
  {_______, _______, _______, _______, _______, _______,       KC_P7,   KC_P8,   KC_P9,	  KC_INS,  KC_HOME, KC_PGUP },
  {_______, _______, _______, _______, _______, _______,       KC_P4,   KC_P5,   KC_P6,	  KC_DEL,  KC_END,  KC_PGDN },
  {_______, _______, _______, _______, _______, _______,       KC_P1,   KC_P2,   KC_P3,   KC_BSPC, KC_UP,   _______ },
  {_______, _______, _______, _______, _______, XXXXXXX,       XXXXXXX, KC_P0, _______,   KC_LEFT, KC_DOWN, KC_RIGHT}
},

[_RAISE] = { 

  {KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,    _______,       _______, _______, _______, KC_LBRC, KC_RBRC, _______ },
  {_______,KC_F5,   KC_F6,   KC_F7,   KC_F8,    _______,       _______, _______, _______, KC_MINS, KC_EQL,  _______ },
  {_______,KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______,       _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, _______ },
  {_______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ },
  {_______, _______, _______, _______, _______, XXXXXXX,       XXXXXXX, _______, _______, _______, _______, _______ }
},


[_MISC] = { 

  {_______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, RESET   },
  {_______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ },
  {KC_CAPS, _______, _______, _______, DVORAK,  _______,       _______, QWERTY,  _______, _______, _______, _______ },
  {_______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ },
  {_______, _______, _______, _______, _______, XXXXXXX,       XXXXXXX, _______, _______, _______, _______, _______ }
}

};


const uint16_t PROGMEM fn_actions[] = {

};

//static uint16_t key_timer;

/*const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
   // MACRODOWN only works in this function
    switch(id) {

      	//switch multiplexing for media, short tap for volume up, long press for play/pause
        case VOLU:
            if (record->event.pressed) {
            	key_timer = timer_read(); // if the key is being pressed, we start the timer.
          	} else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
            	if (timer_elapsed(key_timer) > LONGPRESS_DELAY) { // LONGPRESS_DELAY being 150ms, the threshhold we pick for counting something as a tap.
                  return MACRO(T(MPLY), END);
                } else {
                  return MACRO(T(VOLU), END);
                }
          	}
          	break;

		//switch multiplexing for media, short tap for volume down, long press for next track
        case VOLD:
            if (record->event.pressed) {
            	key_timer = timer_read();
          	} else {
            	if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
                  return MACRO(T(MNXT), END);
                } else {
                  return MACRO(T(VOLD), END);
                }
          	}
          	break;

        //switch multiplexing for escape, short tap for escape, long press for context menu
        case ESCM:
            if (record->event.pressed) {
            	key_timer = timer_read();
          	} else {
            	if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
                  return MACRO(T(APP), END);
                } else {
                  return MACRO(T(ESC), END);
                }
          	}
          	break;     
        

        break;

    }
    return MACRO_NONE;
};  */

//static bool singular_key = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	//uint8_t layer;
  //layer = biton32(layer_state);  // get the current layer

  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _MISC);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _MISC);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _MISC);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _MISC);
          }
          return false;
          break;
      }

  //custom layer handling for tri_layer,
  /*switch (keycode) {
  case FNKEY:
  	if (record->event.pressed) {
      key_timer = timer_read();
      singular_key = true;
    	layer_on(_FUNCTION);
  	} else {
      if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY || !singular_key) {
        layer_off(_FUNCTION);
      }
  	}
    update_tri_layer(_FUNCTION, _SHIFTED, _FUNCSHIFT);
  	return false;
  	break;
  //SHIFT is handled as LSHIFT in the general case
  case SHIFT:
  	if (record->event.pressed) {
      key_timer = timer_read();
      singular_key = true;
    	layer_on(_SHIFTED);
    	register_code(KC_LSFT);
  	} else {
    	if (timer_elapsed(key_timer) < LAYER_TOGGLE_DELAY || !singular_key) {
        layer_off(_SHIFTED);
    	  unregister_code(KC_LSFT);
      }
    }
    update_tri_layer(_FUNCTION, _SHIFTED, _FUNCSHIFT);
  	return false;
  	break;

  //If any other key was pressed during the layer mod hold period,
  //then the layer mod was used momentarily, and should block latching
  default:
    singular_key = false;
    break;
  }

  //FUNCSHIFT has been shifted by the SHIFT handling, some keys need to be excluded
  if (layer == _FUNCSHIFT) {
  	//F1-F12 should be sent as unshifted keycodes, 
  	//and ] needs to be unshifted or it is sent as }
  	if ( (keycode >= KC_F1 && keycode <= KC_F12)
  	   || keycode == KC_RBRC ) {
  		if (record->event.pressed) {
              unregister_mods(MOD_LSFT);
          } else {
              register_mods(MOD_LSFT);
          }
  	}
  }*/

  return true;
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    
    switch (layer) {
    	case _QWERTY:
    		set_led_off;
    		break;
    	case _DVORAK:
    		set_led_red;
    		break;
        case _LOWER:
            set_led_blue;
            break;
        case _RAISE:
            set_led_green;
            break;
        case _MISC:
        	set_led_white;
        	break;
        default:
            break;
    }
};

