/* HSTMATCH module=EBOOT.BIN start=0x00159f08 end=0x0015a01c symbol=FUN_00159f08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00159f08.c) corrected by hand: reordered the local declarations and cursor initializations to match retail register assignments; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

enum { SLOT_COUNT = 3 };
enum { DEFAULT_LIMIT = 100 };
enum { SUBOBJ_INIT_ARG = 8 };

/* Per-slot record, 16 bytes. */
typedef struct SlotRec {
  u32 unk0;    /* 0x0 */
  u32 unk4;    /* 0x4 */
  u32 unk8;    /* 0x8 */
  float scale; /* 0xc */
} SlotRec;

/* Embedded sub-object, 256 bytes, initialised by FUN_000149a8. */
typedef struct SubObj {
  char data[0x100];
} SubObj;

typedef struct Obj_00159f08 {
  const void *vtable;       /* 0x00 */
  u32 unk04;                /* 0x04 */
  char pad08[4];
  u32 unk0c;                /* 0x0c, starts at 1, then FUN_0001342c() */
  u32 limit;                /* 0x10, starts at DEFAULT_LIMIT */
  char pad14[4];
  u32 unk18;                /* 0x18 */
  u8 initFlag;              /* 0x1c, constructor argument */
  char pad1d[3];
  u32 unk20;                /* 0x20 */
  u32 unk24;                /* 0x24 */
  u32 unk28;                /* 0x28 */
  u32 unk2c;                /* 0x2c */
  u32 unk30;                /* 0x30 */
  u32 slotWord[SLOT_COUNT]; /* 0x34 */
  SlotRec slot[SLOT_COUNT]; /* 0x40 */
  SubObj sub[SLOT_COUNT];   /* 0x70 */
  SubObj tail;              /* 0x370 */
} Obj_00159f08;

extern u8 DAT_002de04c;
extern u8 DAT_00309070;
extern u32 DAT_003403f8;
extern u32 DAT_00340400;
extern u32 FUN_0001342c();
extern u32 * FUN_000149a8();
extern void FUN_0015a2b0();
extern void FUN_0015ced4();
extern code * FUN_0022cd60();

Obj_00159f08 * FUN_00159f08(Obj_00159f08 *self,u8 init_flag)
{
  int i;
  u32 id;

  self->vtable = &DAT_00309070;
  self->unk0c = 1;
  self->unk24 = 0;
  self->unk28 = 0;
  DAT_00340400 = (unsigned int)(FUN_0022cd60());
  FUN_0015ced4(self);
  DAT_003403f8 = (unsigned int)(self);
  id = FUN_0001342c();
  self->unk0c = id;
  self->unk04 = 0;
  self->unk20 = 0;
  self->unk18 = 0;
  self->initFlag = init_flag;
  self->unk2c = 0;
  self->unk30 = 0;
  for (i = 0; i < SLOT_COUNT; i++) {
    self->slotWord[i] = 0;
    self->slot[i].unk0 = 0;
    self->slot[i].unk4 = 0;
    self->slot[i].unk8 = 0;
    self->slot[i].scale = 1.0f;
    FUN_000149a8(&self->sub[i],&DAT_002de04c);
  }
  FUN_000149a8(&self->tail,&DAT_002de04c);
  self->limit = DEFAULT_LIMIT;
  FUN_0015a2b0(self,SUBOBJ_INIT_ARG);
  return self;
}
