/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 150

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define COMBO_COUNT 6
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// MK_KINETIC_SPEED	undefined	Enable kinetic mode
#undef  MOUSEKEY_DELAY
#define MOUSEKEY_DELAY	5 // Delay between pressing a movement key and cursor movement
#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL	3 // Time between cursor movements in milliseconds
#undef  MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA	1 // Step size for accelerating from initial to base speed
#undef  MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED	2 // Initial speed of the cursor in pixel per second
#undef  MOUSEKEY_BASE_SPEED
#define MOUSEKEY_BASE_SPEED	2 // Maximum cursor speed at which acceleration stops
#undef  MOUSEKEY_DECELERATED_SPEED
#define MOUSEKEY_DECELERATED_SPEED	4 // Decelerated cursor speed
#undef  MOUSEKEY_ACCELERATED_SPEED
#define MOUSEKEY_ACCELERATED_SPEED	10 // Accelerated cursor speed

// ホイールキー入力から反応までの遅延
#undef  MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 50

// ホイールキー押しっぱなしの時の反応までのインターバル
#undef  MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 80

// ホイールの移動スピード
#undef  MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 2

// ホイール操作がトップスピードになるまでの時間
#undef  MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100
