/* Owner of spawned objects (name-keyed creators and slot panes) and the layout of the objects it creates. */
#ifndef HST_SPAWN_OWNER_H
#define HST_SPAWN_OWNER_H

#include "hst/types.h"

#define SPAWNED_OBJ_SIZE 0xd0 /* bytes allocated per spawned object */
#define SPAWNED_NO_LINK (-1)  /* value of the link field before it is set */

/* Spawned object: a vtable, two 64-byte matrix blocks and a few scalars. */
typedef struct SpawnedObj {
  const void *vtable;   /* 0x00 */
  char pad04[0x2c];
  u32 matA[16];         /* 0x30 matrix block, set from the reference matrix */
  int unk70;            /* 0x70 */
  int link;             /* 0x74 SPAWNED_NO_LINK until set */
  float unk78;          /* 0x78 */
  float unk7c;          /* 0x7c */
  u32 matB[16];         /* 0x80 matrix block, set from the reference matrix */
  int name;             /* 0xc0 name string pointer the object was created with */
  char padc4[0xc];
} SpawnedObj;

/* Owner: a sub-object at +0x60, a handle, a mode flag and a counter. */
typedef struct SpawnOwner {
  char pad00[0x60];
  char sub[0x5e0];      /* 0x60 sub-object passed to the update helper */
  u32 handle;           /* 0x640 */
  u8 altNames;          /* 0x644 selects the second of two name strings */
  char pad645[3];
  int remaining;        /* 0x648 uses left; decremented on each match */
} SpawnOwner;

#define SPAWNED_SLOT_COUNT 3 /* slots in a slot pane */
#define SPAWNED_SLOT_SIZE 0xf0

/* Slot: a small header followed by an embedded spawned object. */
typedef struct SpawnedSlot {
  char pad00[0x20];
  SpawnedObj obj;       /* 0x20 */
} SpawnedSlot;

/* Pane holding an array of slots. */
typedef struct SpawnedSlotPane {
  const void *vtable;   /* 0x00 */
  char pad04[0x2ec];
  SpawnedSlot slot[SPAWNED_SLOT_COUNT]; /* 0x2f0 */
} SpawnedSlotPane;

#endif
