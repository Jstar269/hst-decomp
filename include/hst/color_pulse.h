/* State and table length shared by the colour-pulse sources. */
#ifndef HST_COLOR_PULSE_H
#define HST_COLOR_PULSE_H

#define PULSE_TABLE_LEN 30 /* entries in the pulse byte table; the phase wraps modulo this */

typedef struct PulseState {
  int unk0;                 /* 0x0 */
  int phase;                /* 0x4 index into the pulse table, advanced by a step each update */
  unsigned int baseColor;   /* 0x8 packed colour the pulse starts from */
} PulseState;

#endif
