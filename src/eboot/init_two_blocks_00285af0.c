/* HSTMATCH module=EBOOT.BIN start=0x00285af0 end=0x00285c14 symbol=FUN_00285af0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (via the lane od3 near-miss wip; hstgen tag not recorded) corrected by hand: the memset at +0x34 gets its dropped third argument 1 (shares the constant with the store); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct TwoBlocks {
  u8 unk00;               /* 0x00 */
  char pad01[3];
  int unk04;              /* 0x04 */
  int unk08;              /* 0x08 */
  int unk0c;              /* 0x0c */
  int unk10;              /* 0x10 */
  int unk14;              /* 0x14 */
  int unk18;              /* 0x18 */
  int unk1c;              /* 0x1c */
  u8 head[0x14];          /* 0x20: cleared as a block, then head[0..3] = 0,1,2,0 */
  u8 unk34;               /* 0x34 */
  u8 tail[3];             /* 0x35 */
  u8 block38[0x5c - 0x38]; /* 0x38: start of a 0x6c-byte block cleared with the fields below */
  s16 unk5c;              /* 0x5c */
  char pad5e[0xa0 - 0x5e];
  s16 unka0;              /* 0xa0 */
  s16 unka2;              /* 0xa2 */
  int unka4;              /* 0xa4 */
  int unka8;              /* 0xa8 */
} TwoBlocks;

extern char DAT_002beaa8[];
extern u32 * FUN_000114c0();
extern void FUN_002803d8();

TwoBlocks * FUN_00285af0(TwoBlocks *self)
{
  FUN_000114c0(self->head,0,0x14);
  self->head[0] = 0;
  self->head[1] = 1;
  self->head[2] = 2;
  self->head[3] = 0;
  self->head[9] = 0;
  self->head[10] = 0;
  self->head[0x10] = 0;
  FUN_000114c0(&self->unk34,0,1);
  self->unk34 = 0;
  FUN_000114c0(self->tail,0,3);
  self->tail[0] = 0;
  self->tail[1] = 0;
  FUN_000114c0(self->block38,0,0x6c);
  self->unka0 = -1;
  self->unka2 = -1;
  self->unk5c = -1;
  self->unk00 = 0;
  self->unk04 = 0;
  self->unk08 = 0;
  self->unk0c = 0;
  self->unk18 = 0;
  self->unk1c = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  self->head[0] = 0;
  self->head[1] = 1;
  self->head[2] = 2;
  self->head[3] = 0;
  self->head[9] = 0;
  self->head[10] = 0;
  self->head[0x10] = 0;
  self->unk34 = 0;
  self->tail[0] = 0;
  self->tail[1] = 0;
  FUN_000114c0(self->block38,0,0x6c);
  self->unka0 = -1;
  self->unka2 = -1;
  self->unk5c = -1;
  self->unka4 = 0;
  self->unka8 = 0;
  FUN_002803d8(DAT_002beaa8);
  return self;
}
