/* Path object read from a stream: a short list of 4-float points stored as running sums, with its vtable pointer. */
#ifndef HST_VEC4_PATH_H
#define HST_VEC4_PATH_H

#include "hst/vec.h"

typedef struct Vec4Path {
  const void *vtable; /* 0x00 */
  unsigned char unk04; /* 0x04 */
  int unk08;          /* 0x08 11-bit value from the stream, or -1 */
  int count;          /* 0x0c number of points, 0..15 */
  Float4 *points;     /* 0x10 array of count points (allocated with a 16-byte header) */
} Vec4Path;

#endif
