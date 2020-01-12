#ifndef _BOARD_KEYMAP_H
#define _BOARD_KEYMAP_H

#include <stdint.h>

#define ___ 0

// Conversion of physical layout to keyboard matrix
#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, \
    K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, \
    K60, K61, K62 \
) { \
    { ___, ___, ___, ___, ___, ___, K52, ___ }, \
    { ___, ___, ___, ___, ___, ___, K50, K56 }, \
    { ___, ___, ___, ___, ___, ___, K53, K55 }, \
    { ___, ___, ___, ___, ___, ___, K40, K4B }, \
    { K42, K41, K30, K31, K20, ___, K54, K21 }, \
    { K44, K43, ___, K33, ___, ___, ___, K23 }, \
    { K51, K45, K34, K35, K24, K25, ___, ___ }, \
    { ___, K46, K36, K26, K12, K11, K10, K00 }, \
    { K28, K47, K27, K15, K14, K13, K02, K01 }, \
    { K22, K37, K38, ___, K17, K16, K04, K03 }, \
    { K32, K48, K39, K29, K19, K18, K06, K05 }, \
    { ___, K58, K49, K3A, K2A, K1A, K08, K07 }, \
    { ___, ___, K4A, K3B, K2B, K1B, K0A, K09 }, \
    { ___, ___, K0D, K2C, K1C, K62, K0E, K0B }, \
    { ___, K2D, K60, K1D, K57, K0F, ___, K0G }, \
    { ___, ___, K3C, ___, K61, K0C, ___, K59 } \
}

// Keymap output pins
#define KM_OUT 16
// Keymap input pins
#define KM_IN 8
// Keymap layers (normal, Fn)
#define KM_LAY 2

// Keymap
extern uint16_t __code KEYMAP[KM_LAY][KM_OUT][KM_IN];

// Get a keycode from the keymap
uint16_t keymap(int output, int input, int layer);

// Translate a keycode from PS/2 set 2 to PS/2 set 1
uint16_t keymap_translate(uint16_t key);

// Key types
#define KT_MASK (0xF000)

// Normal keys
#define KT_NORMAL (0x0000)

// Layer selection
#define KT_FN (0x1000)

// SCI
#define KT_SCI (0x2000)

#define SCI_BRIGHTNESS_DOWN (0x11)
#define SCI_BRIGHTNESS_UP (0x12)
#define SCI_AIRPLANE_MODE (0x14)
#define SCI_SUSPEND (0x15)

// See http://www.techtoys.com.hk/Downloads/Download/Microchip/PS2_driver/ScanCode.pdf

// Should send 0xE0 before scancode bytes
#define K_E0 (0x0100)

// Hotkeys

#define K_PLAY_PAUSE (K_E0 | 0x34)
#define K_MUTE (K_E0 | 0x23)
#define K_VOLUME_DOWN (K_E0 | 0x21)
#define K_VOLUME_UP (K_E0 | 0x32)
// Custom scancode
#define K_TOUCHPAD (K_E0 | 0x63)

// Function keys

#define K_F1 (0x05)
#define K_F2 (0x06)
#define K_F3 (0x04)
#define K_F4 (0x0C)
#define K_F5 (0x03)
#define K_F6 (0x0B)
#define K_F7 (0x83)
#define K_F8 (0x0A)
#define K_F9 (0x01)
#define K_F10 (0x09)
#define K_F11 (0x78)
#define K_F12 (0x07)

// Number keys

#define K_0 (0x45)
#define K_1 (0x16)
#define K_2 (0x1E)
#define K_3 (0x26)
#define K_4 (0x25)
#define K_5 (0x2E)
#define K_6 (0x36)
#define K_7 (0x3D)
#define K_8 (0x3E)
#define K_9 (0x46)

// Letter keys

#define K_A (0x1C)
#define K_B (0x32)
#define K_C (0x21)
#define K_D (0x23)
#define K_E (0x24)
#define K_F (0x2B)
#define K_G (0x34)
#define K_H (0x33)
#define K_I (0x43)
#define K_J (0x3B)
#define K_K (0x42)
#define K_L (0x4B)
#define K_M (0x3A)
#define K_N (0x31)
#define K_O (0x44)
#define K_P (0x4D)
#define K_Q (0x15)
#define K_R (0x2D)
#define K_S (0x1B)
#define K_T (0x2C)
#define K_U (0x3C)
#define K_V (0x2A)
#define K_W (0x1D)
#define K_X (0x22)
#define K_Y (0x35)
#define K_Z (0x1A)

// Special keys

// Escape key
#define K_ESC (0x76)

//TODO: Print screen, scroll lock, pause

// Tick/tilde key
#define K_TICK (0x0E)
// Minus/underline key
#define K_MINUS (0x4E)
// Equals/plus key
#define K_EQUALS (0x55)
// Backspace key
#define K_BKSP (0x66)

// Tab key
#define K_TAB (0x0D)
// Bracket open key
#define K_BRACE_OPEN (0x54)
// Bracket close key
#define K_BRACE_CLOSE (0x5B)
// Backslash/pipe key
#define K_BACKSLASH (0x5D)

// Capslock
#define K_CAPS (0x58)
// Semicolon key
#define K_SEMICOLON (0x4C)
// Quote key
#define K_QUOTE (0x52)
// Enter key
#define K_ENTER (0x5A)

// Left shift
#define K_LEFT_SHIFT (0x12)
// Comma key
#define K_COMMA (0x41)
// Period key
#define K_PERIOD (0x49)
// Slash key
#define K_SLASH (0x4A)
// Right shift
#define K_RIGHT_SHIFT (0x59)

// Left control key
#define K_LEFT_CTRL (0x14)
// Left super key
#define K_LEFT_SUPER (K_E0 | 0x1F)
// Left alt key
#define K_LEFT_ALT (0x11)
// Space key
#define K_SPACE (0x29)
// Right alt key
#define K_RIGHT_ALT (K_E0 | 0x11)
// Right super key
#define K_RIGHT_SUPER (K_E0 | 0x27)
// Application key
#define K_APP (K_E0 | 0x2F)
// Right control key
#define K_RIGHT_CTRL (K_E0 | 0x14)

// Arrow keys and related

// Insert key
#define K_INSERT (K_E0 | 0x70)
// Delete key
#define K_DEL (K_E0 | 0x71)
// Home key
#define K_HOME (K_E0 | 0x6C)
// End key
#define K_END (K_E0 | 0x69)
// Page up key
#define K_PGUP (K_E0 | 0x7D)
// Page down key
#define K_PGDN (K_E0 | 0x7A)

#define K_UP (K_E0 | 0x75)
#define K_LEFT (K_E0 | 0x6B)
#define K_DOWN (K_E0 | 0x72)
#define K_RIGHT (K_E0 | 0x74)

// Numpad

#define K_NUM_LOCK (0x77)
#define K_NUM_SLASH (K_E0 | 0x4A)
#define K_NUM_ASTERISK (0x7C)
#define K_NUM_MINUS (0x7B)
#define K_NUM_PLUS (0x79)
#define K_NUM_PERIOD (0x71)
#define K_NUM_ENTER (K_E0 | 0x5A)
#define K_NUM_0 (0x70)
#define K_NUM_1 (0x69)
#define K_NUM_2 (0x72)
#define K_NUM_3 (0x7A)
#define K_NUM_4 (0x6B)
#define K_NUM_5 (0x73)
#define K_NUM_6 (0x74)
#define K_NUM_7 (0x6C)
#define K_NUM_8 (0x75)
#define K_NUM_9 (0x7D)

#endif // _BOARD_KEYMAP_H