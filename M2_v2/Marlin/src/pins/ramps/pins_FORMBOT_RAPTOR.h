/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Formbot Raptor pin assignments
 */

#ifndef __AVR_ATmega2560__
  #error "Oops! Select 'Arduino/Genuino Mega or Mega 2560' in 'Tools > Board.'"
#elif HOTENDS > 3 || E_STEPPERS > 3
  #error "Formbot supports up to 3 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_NAME           "Formbot Raptor"
#define DEFAULT_MACHINE_NAME BOARD_NAME

//
// Servos
//
#define SERVO0_PIN         11
#define SERVO1_PIN          6
#define SERVO2_PIN          5

//
// Limit Switches
//
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  32
#endif

//
// Steppers
//
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
  #define X_CS_PIN         53
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
  #define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
  #define Z_CS_PIN         40
#endif

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24
#ifndef E0_CS_PIN
  #define E0_CS_PIN        42
#endif

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30
#ifndef E1_CS_PIN
  #define E1_CS_PIN        44
#endif

#define E2_STEP_PIN        42
#define E2_DIR_PIN         43
#define E2_ENABLE_PIN      44

//
// Temperature Sensors
//
#define TEMP_0_PIN         13   // Analog Input
#define TEMP_1_PIN         15   // Analog Input
#define TEMP_BED_PIN       14   // Analog Input

// SPI for Max6675 or Max31855 Thermocouple
#if DISABLED(SDSUPPORT)
  #define MAX6675_SS_PIN   66   // Don't use 53 if there is even the remote possibility of using Display/SD card
#else
  #define MAX6675_SS_PIN   66   // Don't use 49 as this is tied to the switch inside the SD card socket to detect if there is an SD card present
#endif

//
// Augmentation for auto-assigning RAMPS plugs
//
#if NONE(IS_RAMPS_EEB, IS_RAMPS_EEF, IS_RAMPS_EFB, IS_RAMPS_EFF, IS_RAMPS_SF) && !PIN_EXISTS(MOSFET_D)
  #if HOTENDS > 1
    #if TEMP_SENSOR_BED
      #define IS_RAMPS_EEB
    #else
      #define IS_RAMPS_EEF
    #endif
  #elif TEMP_SENSOR_BED
    #define IS_RAMPS_EFB
  #else
    #define IS_RAMPS_EFF
  #endif
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN       10
#define HEATER_1_PIN        7
#define HEATER_BED_PIN      8

#ifndef FAN_PIN
  #define FAN_PIN           9
#endif

#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN   57
#endif

#if !HAS_FILAMENT_SENSOR
  #define FAN1_PIN          4
#endif

//
// Misc. Functions
//
#ifndef SDSS
  #define SDSS             53
#endif
#define LED_PIN            13
#define LED4_PIN            5

// Use the RAMPS 1.4 Analog input 5 on the AUX2 connector
#define FILWIDTH_PIN        5   // Analog Input

#ifndef PS_ON_PIN
  #define PS_ON_PIN        12
#endif

#define CASE_LIGHT_PIN      5

//
// LCD / Controller
//
// Formbot only supports REPRAP_DISCOUNT_SMART_CONTROLLER
//
#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
  #define BEEPER_PIN       37
  #define BTN_EN1          31
  #define BTN_EN2          33
  #define BTN_ENC          35
  #define SD_DETECT_PIN    49
  #define KILL_PIN         41
  #define LCD_PINS_RS      16
  #define LCD_PINS_ENABLE  17
  #define LCD_PINS_D4      23
  #define LCD_PINS_D5      25
  #define LCD_PINS_D6      27
  #define LCD_PINS_D7      29
#endif
