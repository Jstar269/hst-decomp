/* Sprite quad record (vertex colour plus two corner points) and the panel view that holds a list of quads. */
#ifndef HST_SPRITE_QUAD_H
#define HST_SPRITE_QUAD_H

#include "hst/types.h"

typedef struct SpriteQuad {
  u32 color;  /* 0x00 packed colour, alpha in the top byte */
  s16 x0;     /* 0x04 first corner */
  s16 y0;     /* 0x06 */
  s16 x1;     /* 0x08 opposite corner */
  s16 y1;     /* 0x0a */
} SpriteQuad;

/* Panel view: the quad pointers at 0x10 are laid out row by row (0, 2 and 6 are three of the corners). */
typedef struct PanelQuads {
  char pad00[0x10];
  SpriteQuad **quads; /* 0x10 */
} PanelQuads;

#endif
