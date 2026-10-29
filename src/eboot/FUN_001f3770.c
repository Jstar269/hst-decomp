/* HSTMATCH module=EBOOT.BIN start=0x001f3770 end=0x001f37e4 symbol=FUN_001f3770 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001e2668();
extern u32 FUN_001f3144();
extern void FUN_001f94b8();
extern void FUN_001fb928();

typedef struct ActionObj {
  char pad00[0x3c];
  char sub3c[4];     /* 0x3c sub-object handed to the last helper */
  u32 unk40;         /* 0x40 */
  char pad44[0x510 - 0x44];
  u32 unk510;        /* 0x510 */
} ActionObj;

enum { ACTION_RESET = 0x14, ACTION_SPECIAL = 0xb };

void FUN_001f3770(ActionObj *self)
{
  int action;
  
  action = FUN_001f3144(self,self->unk40,0);
  if (action == ACTION_RESET) {
    FUN_001f94b8(self);
  }
  else {
    if (action == ACTION_SPECIAL) {
      FUN_001e2668(self->unk510);
    }
    FUN_001fb928(self->sub3c,action,1);
  }
}
