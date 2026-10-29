/* HSTMATCH module=EBOOT.BIN start=0x001c352c end=0x001c35ec symbol=FUN_001c352c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte-check return and float/pointer helper arguments; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/menu_state.h"

extern u32 DAT_003415ac;
extern u32 DAT_003415d4;
extern void *DAT_0034a114;
extern void FUN_00103628();
extern int FUN_001155c0();
extern u32 FUN_001156d4();
extern void FUN_001905b8();
extern void FUN_001c6cfc(float,void *,int);
extern void FUN_001ca8f0();
extern void FUN_001cd3d8();
extern void FUN_001cd88c();

void FUN_001c352c(MenuState *self)
{
  int result;
  
  result = FUN_001155c0(DAT_003415ac);
  if (result != 0) {
    FUN_00103628(DAT_003415ac,1);
    result = FUN_001156d4(DAT_003415ac);
    if (result == 0) {
      FUN_001ca8f0(self->parent);
      self->unke8 = 1;
      self->unkf0 = 0;
      FUN_001905b8(DAT_003415d4,3);
      FUN_001cd88c(self,8,1);
      FUN_001cd3d8(self->parent);
    }
    else {
      FUN_001cd88c(self,0,1);
      FUN_001c6cfc(1.0f,DAT_0034a114,1);
    }
  }
}
