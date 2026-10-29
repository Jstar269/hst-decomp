/* HSTMATCH module=EBOOT.BIN start=0x000ae68c end=0x000ae774 symbol=FUN_000ae68c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: control flow, byte and float fields, and bit tests; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/root_state.h"

/* Destination object: copies of the packed fields below land in these slots. */
typedef struct Dest {
  char pad0[0x1b4];
  u8 flag1b4;       /* 0x1b4 */
  char pad1b5[0x41c - 0x1b5];
  int unk41c;       /* 0x41c */
  char pad420[0x43c - 0x420];
  float unk43c;     /* 0x43c */
  char pad440[0x4cf - 0x440];
  bool flag4cf;     /* 0x4cf */
  char pad4d0[0x4d8 - 0x4d0];
  bool flag4d8;     /* 0x4d8 */
  bool flag4d9;     /* 0x4d9 */
  bool flag4da;     /* 0x4da */
  char pad4db;
  int unk4dc;       /* 0x4dc */
  char pad4e0[0x4e4 - 0x4e0];
  int unk4e4;       /* 0x4e4 */
  int unk4e8;       /* 0x4e8 */
} Dest;

/* Source record with two packed bytes at +0x22 and +0x23 (shift pairs below sign-extend bit ranges). */
typedef struct Src {
  char pad0[0x20];
  short unk20;      /* 0x20 */
  char packed22;    /* 0x22 */
  char packed23;    /* 0x23 */
  float unk24;      /* 0x24 */
} Src;

extern RootState * DAT_003386b0;
extern unsigned char DAT_003386b8;
extern void FUN_000a0410();

void FUN_000ae68c(Dest *self,Src *src)
{
  if (DAT_003386b0->mode != ROOT_MODE_SPECIAL) {
    int bVar2 = DAT_003386b8 != 0;
    if (bVar2) {
      bVar2 = self->flag1b4 != 0;
    }
    if (bVar2 == 0) {
      return;
    }
  }
  self->unk41c = (int)src->unk20;
  self->unk4e4 = ((int)src->packed22 << 0x1d) >> 0x1d;  /* low 3 bits, signed */
  self->unk4e8 = ((int)src->packed22 << 0x18) >> 0x1b;  /* bits 3..7 of the byte, signed */
  self->flag4cf = ((int)src->packed23 << 0x1e) >> 0x1e != 0;
  self->flag4d8 = (((int)src->packed23 << 0x1d) >> 31) != 0;
  self->flag4d9 = (((int)src->packed23 << 0x1c) >> 31) != 0;
  self->flag4da = (((int)src->packed23 << 0x1b) >> 31) != 0;
  self->unk4dc = ((int)src->packed23 << 0x18) >> 0x1d;  /* top 3 bits, signed */
  self->unk43c = src->unk24;
  FUN_000a0410(self,self->unk4dc);
}
