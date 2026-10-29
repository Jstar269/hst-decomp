/* Host object of the entry and state sources: entry data block, animation state and the two flag bytes. */
#ifndef HST_ANIM_HOST_H
#define HST_ANIM_HOST_H

#include "hst/types.h"

/* State id with its own setup path (cleared channel, then the state is applied to it). */
#define HOST_STATE_SPECIAL 14

/* First animation id of the per-mode variants: id = HOST_ANIM_BASE + mode * 4 + variant. */
#define HOST_ANIM_BASE 0xf

/* Part held by the entry data; only a float at 0x78 is touched. */
typedef struct EntryPart {
  char pad00[0x78];
  float unk78;            /* 0x78 */
} EntryPart;

/* Small block inside the entry data, cleared by its initialiser. */
typedef struct EntryBlock {
  u32 id;                 /* 0x00 */
  u8 flag;                /* 0x04 */
  char pad05[0xff];
  u32 unk104;             /* 0x104 */
  u32 unk108;             /* 0x108 */
  u8 unk10c;              /* 0x10c */
} EntryBlock;

typedef struct EntryData {
  char pad00[0x5c];
  EntryPart *part;        /* 0x5c */
  char pad60[8];
  int unk68;              /* 0x68 */
  int unk6c;              /* 0x6c */
  u8 unk70;               /* 0x70 */
  char pad71[3];
  EntryBlock block;       /* 0x74 */
} EntryData;

/* Object that owns the entry data and the animation channels. */
typedef struct AnimHost {
  char pad00[0x1c8];
  EntryData *entry;       /* 0x1c8 */
  char pad1cc[0x1d8 - 0x1cc];
  int unk1d8;             /* 0x1d8 */
  int mode;               /* 0x1dc */
  int state;              /* 0x1e0 */
  u8 flag_a;              /* 0x1e4 */
  u8 flag_b;              /* 0x1e5 */
  char pad1e6[0x1f0 - 0x1e6];
  int unk1f0;             /* 0x1f0 */
} AnimHost;

#endif
