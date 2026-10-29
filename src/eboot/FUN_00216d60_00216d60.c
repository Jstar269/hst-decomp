/* HSTMATCH module=EBOOT.BIN start=0x00216d60 end=0x00216de0 symbol=FUN_00216d60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: placed the nonzero dispatch arm first to match the target branch layout; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002c983c;
extern u32 DAT_002c9840;
extern u32 DAT_002c9844;
extern u32 DAT_002c9848;
extern void FUN_000513a0();

typedef struct Obj {
  u8 unk00;          /* 0x00 set to 1 */
  char pad01[3];
  u32 sub;           /* 0x04 passed to FUN_000513a0 with the mode */
  char pad08[0x100];
  u32 value_a;       /* 0x108 */
  u32 value_b;       /* 0x10c */
} Obj;

/* Select between two modes (1 when `first` is nonzero, else 2) and load the matching pair of values. */
void FUN_00216d60(Obj *self,int first)
{
  if (first != 0) {
    FUN_000513a0(self->sub,1);
    self->value_a = DAT_002c9840;
    self->value_b = DAT_002c983c;
    self->unk00 = 1;
  }
  else {
    FUN_000513a0(self->sub,2);
    self->value_a = DAT_002c9848;
    self->value_b = DAT_002c9844;
    self->unk00 = 1;
  }
}
