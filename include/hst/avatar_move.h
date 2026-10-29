/* Avatar movement state (C view): velocity, position and the heading derived from it. */
#ifndef HST_AVATAR_MOVE_H
#define HST_AVATAR_MOVE_H

#include "hst/types.h"
#include "hst/vec.h"

/* Offset of the avatar's second vtable; the secondary entry points subtract it to get the object start. */
#define AVATAR_SECONDARY_OFFSET 0xe0

typedef struct AvatarMove {
  char pad000[0x1a0];
  Float4 velocity;    /* 0x1a0 gets the gravity step added, then is clamped */
  Float4 pos;         /* 0x1b0 */
  Float4 prev_pos;    /* 0x1c0 */
  Float4 ref_pos;     /* 0x1d0 position the heading is measured against; refreshed when the heading is reset */
  u8 active;          /* 0x1e0 set while the heading must be recomputed from ref_pos */
  char pad1e1[3];
  float angle;        /* 0x1e4 heading, atan of the horizontal direction */
  float prev_angle;   /* 0x1e8 heading before the last update */
} AvatarMove;

#endif
