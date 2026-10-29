/* Colour value types of the 0x216e00 sources: three channel words and four channel bytes. */
#ifndef HST_COLOR_WORDS_H
#define HST_COLOR_WORDS_H

#include "hst/types.h"

#define PACKED_ALPHA 0x80000000u /* alpha byte of a packed colour (0x80 in the top byte) */

typedef struct ColorWords {
  u32 r;        /* 0x00 */
  u32 g;        /* 0x04 */
  u32 b;        /* 0x08 */
} ColorWords;

typedef struct ColorBytes {
  u8 r;         /* 0x00 */
  u8 g;         /* 0x01 */
  u8 b;         /* 0x02 */
  u8 a;         /* 0x03 */
} ColorBytes;

#endif
