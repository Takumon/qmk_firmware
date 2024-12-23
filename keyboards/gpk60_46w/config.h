// Copyright 2023 Daraku-Neko (@Daraku-Neko)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define VIAL_KEYBOARD_UID {0xCC, 0x42, 0xB1, 0x59, 0xE3, 0xBA, 0xD5, 0xA4}

#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define TAPPING_TERM 150
#define COMBO_COUNT 6
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define USB_POLLING_INTERVAL_MS 10
