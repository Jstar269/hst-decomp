/* Set of up to six model objects owned by one scene entity (the 0x93000 sources) and the model object view they use. */
#ifndef HST_MODEL_SET_H
#define HST_MODEL_SET_H

#include "hst/vec.h"

#include "hst/types.h"

#define MODEL_SLOT_COUNT 6 /* model[] length; DAT_002beb1c lists the slots in update order */
#define MODEL_SLOT_MAIN 2  /* slot most helpers forward to */

/* One model object. */
typedef struct ModelObj {
  char pad00[0x30];
  char unk30[0x30];   /* 0x30 sub-record passed by address */
  float unk60[4];     /* 0x60 vector returned by the fallback getter */
  char pad70[0x54];
  float unkc4;        /* 0xc4 */
  char padc8[8];
  float unkd0;        /* 0xd0 */
  char padd4[0xac];
  int unk180;         /* 0x180 */
  char pad184[0x2c];
  int unk1b0;         /* 0x1b0 state id (5 and 2 are tested by the update) */
} ModelObj;

/* Owner of the model slots. */
typedef struct ModelSet {
  char pad00[0x20];
  int unk20;          /* 0x20 index; negative when unset */
  char *unk24;        /* 0x24 table of 8-byte entries */
  int unk28;          /* 0x28 */
  char pad2c[0x24];
  ModelObj *model[MODEL_SLOT_COUNT]; /* 0x50 */
  char pad68[0x18];
  char unk80[0x30];   /* 0x80 float4 area, passed by address */
  char unkb0[0x30];   /* 0xb0 float4 area, passed by address */
} ModelSet;

#endif
