#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define QGMLW 0
#define SYMBOLS 1
#define MOUSE 2
#define COMMAND 3
#define GAME 4

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  MY_TILD,
  MY_CIRC,
  MY_SLSH,
  MY_SQUOT,
  MY_DQUOT,
  DELETE_LAST_30,
  SGDUH,
  MFG,
  VG,
  FIND_NAME,
  GIT_ADD,
  GIT_PULL,
  GIT_PUSH,
  GIT_STATUS,
  GIT_COMMIT,
  GIT_COMMIT_A,
  GIT_CHECKOUT,
  GIT_CHECKOUT_B,
  GIT_BRANCH,
  GIT_REBASE,
  PS_AUX_GREP,
  SCREEN_1,
  SCREEN_2,
  SCREEN_3,
  SCREEN_4,
  SELECT_ALL,
  AUML,
  OUML,
  UUML,
  SSS,
  USB_RESET
};

enum custom_macros {
  COPY_PASTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/******* QGMLW Layer *****************************************************************************************************
 *
 * ,------------------------------------------------------.       ,------------------------------------------------------.
 * | ESC        |   1  |   2  |   3  |   4  |   5  |      |       |      |   6  |   7  |   8  |   9  |   0  |            |
 * |------------+------+------+------+------+-------------|       |------+------+------+------+------+------+------------|
 * | TAB        |   Q  |   G  |   M  |   L  |   W  |      |       |      |   B  |   Y  |   U  |   V  |   Ü  |            |
 * |------------+------+------+------+------+------|      |       |      |------+------+------+------+------+------------|
 * | To Symbols |   D  |   S  |   T  |   N  |   R  |------|       |------|   I  |   A  |   E  |   O  |   H  | To Symbols |
 * |------------+------+------+------+------+------| To   |       |      |------+------+------+------+------+------------|
 * | LShift     |   Z  |   X  |   C  |   F  |   J  |Mouse |       |      |   K  |   P  |   ,  |   .  |   ß  |   RShift   |
 * `------------+------+------+------+------+-------------'       `-------------+------+------+------+------+------------'
 *      | LCtrl | LAlt | LGui | Home | End  |                                   |   Ö  |   Ä  | RGui | RAlt  | RCtrl |
 *      `-----------------------------------'                                   `-----------------------------------'
 *                                          ,-------------.       ,-------------.
 *                                          | Del  | Ins  |       | Left | Right|
 *                                   ,------|------|------|       |------+------+------.
 *                                   |      |      | PUp  |       |  Up  |      |      |
 *                                   |Enter | LGui |------|       |------|BckSpa| Space|
 *                                   |      |      | PDown|       | Down |      |      |
 *                                   `--------------------'       `--------------------'
 */
[QGMLW] = LAYOUT_ergodox(
 KC_ESC     ,KC_1        ,KC_2        ,KC_3       ,KC_4     ,KC_5  ,SELECT_ALL
,KC_TAB     ,KC_Q        ,KC_G        ,KC_M       ,KC_L     ,KC_W  ,M(COPY_PASTE)
,MO(SYMBOLS),KC_D        ,KC_S        ,KC_T       ,KC_N     ,KC_R
,KC_LSFT    ,KC_Z        ,KC_X        ,KC_C       ,KC_F     ,KC_J  ,MO(MOUSE)
,KC_LCTL    ,KC_LALT     ,KC_LGUI     ,KC_HOME    ,KC_END
                                                  ,KC_DEL   ,KC_INS
                                                            ,KC_PGUP
                                      ,KC_ENT     ,KC_LGUI  ,KC_PGDN
                                                                   ,DELETE_LAST_30  ,KC_6    ,KC_7       ,KC_8        ,KC_9      ,KC_0            ,MO(COMMAND)
                                                                   ,TG(GAME)        ,KC_B    ,KC_Y       ,KC_U        ,KC_V      ,UUML            ,KC_TRNS
                                                                                    ,KC_I    ,KC_A       ,KC_E        ,KC_O      ,KC_H            ,MO(SYMBOLS)
                                                                   ,MO(MOUSE)       ,KC_K    ,KC_P       ,KC_COMM     ,KC_DOT    ,SSS             ,KC_RSFT
                                                                                             ,OUML       ,AUML        ,KC_RGUI   ,KC_RALT         ,KC_RCTL
                                                                   ,KC_LEFT         ,KC_RGHT
                                                                   ,KC_UP          
                                                                   ,KC_DOWN         ,KC_BSPC ,KC_SPC
),
/******* Symbols Layer (equal to second neo2 layer) **********************************************************************
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  | F12  |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   _  |   [  |   ]  |   ^  |  ☺   |           |      |   !  |   <  |   >  |   =  |   &  |   @    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   \  |   /  |   {  |   }  |   *  |------|           |------|   ?  |   (  |   )  |   -  |   :  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   |  |   ~  |      |      |           |      |   +  |   %  |   "  |   '  |   ;  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |   H  |   J  |   K  |   L  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMBOLS] = LAYOUT_ergodox(
       VRSN    ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5      ,KC_F12
      ,KC_TRNS ,KC_GRAVE,KC_UNDS ,KC_LBRC ,KC_RBRC ,MY_CIRC    ,UC(0x263a)
      ,KC_TRNS ,KC_BSLS ,KC_SLSH ,KC_LCBR ,KC_RCBR ,KC_ASTR
      ,KC_TRNS ,KC_HASH ,KC_DLR  ,KC_PIPE ,MY_TILD ,KC_TRNS    ,KC_TRNS
      ,EPRM    ,KC_TRNS ,KC_TRNS ,KC_CIRC ,KC_TILD
                                          ,KC_TRNS ,KC_TRNS
                                                   ,KC_TRNS
                               ,KC_TRNS   ,KC_TRNS ,KC_TRNS
                                                                ,KC_TRNS    ,KC_F6         ,KC_F7         ,KC_F8               ,KC_F9         ,KC_F10     ,KC_F11
                                                                ,KC_TRNS    ,KC_EXLM       ,LSFT(KC_COMM) ,LSFT(KC_DOT)        ,KC_EQL        ,KC_AMPR    ,KC_AT
                                                                            ,LSFT(KC_SLSH) ,KC_LPRN       ,KC_RPRN             ,KC_MINS       ,KC_COLN    ,KC_TRNS
                                                                ,KC_TRNS    ,KC_PLUS       ,KC_PERC       ,MY_DQUOT            ,MY_SQUOT      ,KC_SCLN    ,KC_TRNS
                                                                                           ,KC_H          ,KC_J                ,KC_K          ,KC_L       ,KC_TRNS
                                                                ,RGB_TOG    ,KC_TRNS
                                                                ,KC_TRNS
                                                                ,KC_TRNS    ,RGB_HUD, RGB_HUI
),
/******* Mouse control Layer *********************************************************************************************
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |MsLeft|MsDown| MsUp |MsRght|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Lclk | Rclk |
 *                                 |      |      |      |       | Mclk |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOUSE] = LAYOUT_ergodox(
       KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_Q,         KC_W,         KC_E,     KC_R,    KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_A,         KC_S,         KC_D,     KC_F,    KC_G,   
       KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                           KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPLY,
                                                                 KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                                                                                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,
                                                                 KC_BTN3, KC_BTN1, KC_BTN2
),
/******* Command Layer ***************************************************************************************************
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[COMMAND] = LAYOUT_ergodox(
       USB_RESET,  SCREEN_1,     SCREEN_2,       SCREEN_3,    SCREEN_4,          KC_TRNS,    KC_TRNS,
       KC_TRNS,    GIT_PULL,     GIT_COMMIT_A,   GIT_PUSH,    GIT_CHECKOUT_B,    GIT_REBASE, KC_TRNS,
       KC_TRNS,    GIT_STATUS,   GIT_BRANCH,     GIT_ADD,     GIT_CHECKOUT,      KC_TRNS,
       KC_TRNS,    PS_AUX_GREP,  FIND_NAME,      KC_TRNS,     KC_TRNS,           KC_TRNS,    KC_TRNS,
       KC_TRNS,    KC_TRNS,      KC_TRNS,        KC_TRNS,     KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,  MFG,     VG,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                           SGDUH,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                                                                                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,
                                                                 KC_TRNS, KC_TRNS, KC_TRNS
),
/******* Game (qwerty) Layer ***************************************************************************************************
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  1   |  2   |  3   |  4   |  5   |      |           |      |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  Q   |  W   |  E   |  R   |  T   |      |           |      |  Y   |  U   |  I   |  O   |  P   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   P    |  A   |  S   |  D   |  F   |  G   |------|           |------|  H   |  J   |  K   |  L   |  ;   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSFT   |  Z   |  X   |  C   |  V   |  B   |      |           |      |  N   |  M   |  ,   |  .   |  /   | RSFT   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | LALT | WIN  | HOME | END  |                                       |      |      | RALT | RCTL |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | DEL  | INS  |       | LEFT | RGHT |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PUP  |       |  UP  |      |      |
 *                                 | ENTR | WIN  |------|       |------| BSPC | SPC  |
 *                                 |      |      | PDWN |       |  DWN |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAME] = LAYOUT_ergodox(
       KC_ESC,   KC_1,         KC_2,         KC_3,     KC_4,    KC_5,    KC_TRNS,
       KC_TAB,   KC_Q,         KC_W,         KC_E,     KC_R,    KC_T,    KC_TRNS,
       KC_P,     KC_A,         KC_S,         KC_D,     KC_F,    KC_G,
       KC_LSFT,  KC_Z,         KC_X,         KC_C,     KC_V,    KC_B,    KC_TRNS,
       KC_LCTL,  KC_LALT,      KC_LGUI,      KC_HOME,  KC_END,
                                           KC_DEL,  KC_INS, 
                                                    KC_PGUP,
                                  KC_ENT,  KC_BSPC, KC_PGDN,
                                                                 KC_TRNS,  KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_TRNS,
                                                                 KC_TRNS,  KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_TRNS,
                                                                           KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_TRNS,
                                                                 KC_TRNS,  KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                                                                    KC_VOLU,    KC_VOLD, KC_RALT, KC_RCTL, KC_TRNS,
                                                                 KC_LEFT, KC_RGHT,
                                                                 KC_UP,
                                                                 KC_DOWN, KC_BSPC, KC_SPC
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AUML:
      if (record->event.pressed) { SEND_STRING(SS_RALT("q")); }
      return false; break;
    case OUML:
      if (record->event.pressed) { SEND_STRING(SS_RALT("p")); }
      return false; break;
    case UUML:
      if (record->event.pressed) { SEND_STRING(SS_RALT("y")); }
      return false; break;
    case SSS:
      if (record->event.pressed) { SEND_STRING(SS_RALT("s")); }
      return false; break;
    case SELECT_ALL:
      if (record->event.pressed) { SEND_STRING(SS_LCTRL("a")); }
      return false; break;
    case USB_RESET:
      if (record->event.pressed) { SEND_STRING(SS_TAP(X_NUMLOCK)SS_TAP(X_NUMLOCK)); }
      return false; break;
    case SCREEN_1:
      if (record->event.pressed) { SEND_STRING(SS_TAP(X_SCROLLLOCK)SS_TAP(X_SCROLLLOCK)"1"); }
      return false; break;
    case SCREEN_2:
      if (record->event.pressed) { SEND_STRING(SS_TAP(X_SCROLLLOCK)SS_TAP(X_SCROLLLOCK)"2"); }
      return false; break;
    case SCREEN_3:
      if (record->event.pressed) { SEND_STRING(SS_TAP(X_SCROLLLOCK)SS_TAP(X_SCROLLLOCK)"3"); }
      return false; break;
    case SCREEN_4:
      if (record->event.pressed) { SEND_STRING(SS_TAP(X_SCROLLLOCK)SS_TAP(X_SCROLLLOCK)"4"); }
      return false; break;
    case DELETE_LAST_30:
      if (record->event.pressed) { SEND_STRING(SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)SS_TAP(X_BSPACE)); }
      return false; break;
    case SGDUH:
      if (record->event.pressed) { SEND_STRING ("Sehr geehrte Damen und Herren,"); }
      return false; break;
    case VG:
      if (record->event.pressed) { SEND_STRING ("Viele Gr"SS_RALT("y")SS_RALT("s")"e"); }
      return false; break;
    case MFG:
      if (record->event.pressed) { SEND_STRING ("Mit freundlichen Gr"SS_RALT("y")SS_RALT("s")"en"); }
      return false; break;
    case FIND_NAME:
      if (record->event.pressed) { SEND_STRING ("find . -name "); }
      return false; break;
    case PS_AUX_GREP:
      if (record->event.pressed) { SEND_STRING ("ps aux | grep "); }
      return false; break;
    case GIT_ADD:
      if (record->event.pressed) { SEND_STRING ("git add"); }
      return false; break;
    case GIT_STATUS:
      if (record->event.pressed) { SEND_STRING ("git status"); }
      return false; break;
    case GIT_PULL:
      if (record->event.pressed) { SEND_STRING ("git pull --rebase"); }
      return false; break;
    case GIT_PUSH:
      if (record->event.pressed) { SEND_STRING ("git push"); }
      return false; break;
    case GIT_COMMIT:
      if (record->event.pressed) { SEND_STRING ("git commit -v"); }
      return false; break;
    case GIT_COMMIT_A:
      if (record->event.pressed) { SEND_STRING ("git commit -va"); }
      return false; break;
    case GIT_CHECKOUT:
      if (record->event.pressed) { SEND_STRING ("git checkout"); }
      return false; break;
    case GIT_CHECKOUT_B:
      if (record->event.pressed) { SEND_STRING ("git checkout -b"); }
      return false; break;
    case GIT_BRANCH:
      if (record->event.pressed) { SEND_STRING ("git branch"); }
      return false; break;
    case GIT_REBASE:
      if (record->event.pressed) { SEND_STRING ("git rebase -i HEAD~~"); }
      return false; break;
    case MY_TILD:
      if (record->event.pressed) { SEND_STRING ("~ "); }
      return false; break;
    case MY_CIRC:
      if (record->event.pressed) { SEND_STRING("^ "); }
      return false; break;
    case MY_SQUOT:
      if (record->event.pressed) { SEND_STRING("' "); }
      return false; break;
    case MY_DQUOT:
      if (record->event.pressed) { SEND_STRING("\" "); }
      return false; break;
    case MY_SLSH:
      if (record->event.pressed) { SEND_STRING("/"); }
      return false; break;
    case EPRM:
      if (record->event.pressed) { eeconfig_init(); }
      return false; break;
    case VRSN:
      if (record->event.pressed) { SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION); }
      return false; break;
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case COPY_PASTE: {
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(C), U(LCTL), END  );
            } else {
                return MACRO( D(LCTL), T(V), U(LCTL), END  );
            }
            break;
        }
    }
    return MACRO_NONE;
}; 

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  set_unicode_input_mode(UC_LNX);
};
