/* Object driven by the timed-blend sources: elapsed/duration timer, two mode override slots and a node reference. */
#ifndef HST_BLEND_OBJ_H
#define HST_BLEND_OBJ_H

#define BLEND_MODE_NONE (-1) /* override slot unset */

struct BlendNode;

typedef struct BlendObj {
  char pad0[0x3c];
  void *target;            /* 0x3c object that receives an update virtual call */
  char pad40[8];
  int unk48;               /* 0x48 */
  char pad4c[8];
  int tableIndex;          /* 0x54 index into a 64-byte-entry table */
  char pad58[0x6c - 0x58];
  float elapsed;           /* 0x6c */
  float duration;          /* 0x70 */
  char pad74[4];
  int overrideA;           /* 0x78 BLEND_MODE_NONE when unset */
  int overrideB;           /* 0x7c */
  char pad80[0x10];
  struct BlendNode **nodeRef; /* 0x90 */
  int unk94;               /* 0x94 */
} BlendObj;

#endif
