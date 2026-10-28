/* HSTMATCH module=hstp_trans_main.prx start=0x001c5ca4 end=0x001c5d10 symbol=FUN_001c5ca4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the fields and retained state as the second helper argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003eaad8;
extern u32 FUN_001bfc3c(const void *, int);
extern int FUN_001c0010(const void *, int);

typedef struct Obj_001c5ca4 {
  char pad0[0x64];
  int state;
  char pad1[0x20];
  int count;
} Obj_001c5ca4;

void FUN_001c5ca4(Obj_001c5ca4 *param_1)
{
  int iVar1;
  
  if (param_1->state >= 0) {
    if (FUN_001c0010(&DAT_003eaad8,param_1->state) == 0) {
      param_1->state = -1;
    }
  }
  iVar1 = param_1->count;
  if ((0 < iVar1) && ((param_1->count = iVar1 + -1), iVar1 + -1 < 1)) {
    FUN_001bfc3c(&DAT_003eaad8,0x45);
  }
}
