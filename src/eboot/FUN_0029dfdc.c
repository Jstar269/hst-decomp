/* HSTMATCH module=EBOOT.BIN start=0x0029dfdc end=0x0029e024 symbol=FUN_0029dfdc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415ac;
extern void FUN_000fe43c();
extern void FUN_00295cdc();
extern void FUN_0029ade8();
extern int FUN_0029e024();

typedef struct Target {
  char pad00[0x28];
  u32 unk28;  /* 0x28 cleared */
} Target;

typedef struct Holder {
  char pad00[0x3c];
  Target *target;  /* 0x3c */
} Holder;

void FUN_0029dfdc(Holder *self)
{
  Target *target;
  
  target = self->target;
  FUN_0029e024();
  FUN_000fe43c(0);
  target->unk28 = 0;
  FUN_0029ade8(target,3);
  FUN_00295cdc(DAT_003415ac);
}
