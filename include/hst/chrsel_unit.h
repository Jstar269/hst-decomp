/* Unit object: handle of a shared model object, a kind index, six attribute ids and a few flag bytes. */
#ifndef HST_CHRSEL_UNIT_H
#define HST_CHRSEL_UNIT_H

#include "hst/types.h"

#define CHRSEL_ATTR_COUNT 6 /* attribute ids per unit */

typedef struct ChrSelUnit {
  void *handle;                   /* 0x00 shared object for this kind */
  int kind;                       /* 0x04 index of the shared object table */
  u8 unk08;                       /* 0x08 */
  u8 unk09;                       /* 0x09 */
  char pad0a[2];
  int unk0c;                      /* 0x0c */
  int unk10;                      /* 0x10 */
  int unk14;                      /* 0x14 */
  char pad18[8];
  float unk20;                    /* 0x20 */
  float unk24;                    /* 0x24 */
  float unk28;                    /* 0x28 */
  float unk2c;                    /* 0x2c */
  int unk30;                      /* 0x30 */
  int unk34;                      /* 0x34 */
  int unk38;                      /* 0x38 */
  int unk3c;                      /* 0x3c */
  float unk40;                    /* 0x40 */
  int unk44;                      /* 0x44 */
  int unk48;                      /* 0x48 */
  int unk4c;                      /* 0x4c */
  int unk50;                      /* 0x50 */
  int attr[CHRSEL_ATTR_COUNT];    /* 0x54 attr[0] is the id used to look up the info record */
  u8 unk6c;                       /* 0x6c */
  char pad6d[3];
  int unk70;                      /* 0x70 */
  u8 flag;                        /* 0x74 */
  u8 unk75;                       /* 0x75 */
  u8 unk76;                       /* 0x76 */
  u8 unk77;                       /* 0x77 */
  u8 unk78;                       /* 0x78 */
} ChrSelUnit;

#endif
