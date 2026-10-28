/* HSTMATCH module=EBOOT.BIN start=0x000fb880 end=0x000fba28 symbol=FUN_000fb880 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: symbolized global references and expressed mode dispatch with switches; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003386b0;
extern u32 DAT_0034a820;
extern char DAT_002d823c[];
extern u8 DAT_0030ebf4;
extern void FUN_0001cad0(void *, int, char *);
extern void FUN_0001cb88(void *);
extern void FUN_000f79b8();
extern void FUN_000f7e30();
extern u32 FUN_000f9508();
extern void FUN_000fbaf4();
extern void FUN_000fbbf8();
extern void FUN_001fc3dc();
extern void FUN_001fc4e8();
extern void FUN_00291b8c();
extern void FUN_00291cdc();

u32 FUN_000fb880(int param_1,int param_2,u32 param_3,u32 param_4)
{
  u32 uVar1;
  
  if (((*(int *)(DAT_003386b0 + 0x3c) == 9) && (param_2 != 0x12)) && (param_2 != 0x18)) {
    return 0;
  }
  switch (param_2) {
    case 0:
      FUN_0001cad0(&DAT_0030ebf4,1,DAT_002d823c);
      FUN_000f79b8(*(u32 *)(param_1 + 0x3c));
      FUN_000fbaf4(*(u32 *)(param_1 + 0x44));
      if (DAT_0034a820 != 0) FUN_00291b8c(DAT_0034a820,2);
      FUN_0001cb88(&DAT_0030ebf4);
      FUN_001fc3dc(*(u32 *)(param_1 + 0x40),0);
      break;
    case 0x18:
      FUN_0001cad0(&DAT_0030ebf4,1,DAT_002d823c);
      FUN_000f79b8(*(u32 *)(param_1 + 0x3c));
      FUN_000fbaf4(*(u32 *)(param_1 + 0x44));
      if (DAT_0034a820 != 0) FUN_00291b8c(DAT_0034a820,2);
      FUN_0001cb88(&DAT_0030ebf4);
      FUN_001fc3dc(*(u32 *)(param_1 + 0x40),1);
      break;
  }
  uVar1 = *(u32 *)(param_1 + 0x3c);
LAB_000fb9ac:
  uVar1 = FUN_000f9508(uVar1,param_2,param_3,param_4);
  switch (param_2) {
    case 0x12:
      FUN_001fc4e8(*(u32 *)(param_1 + 0x40),1);
      FUN_000fbbf8(*(u32 *)(param_1 + 0x44));
      FUN_000f7e30(*(u32 *)(param_1 + 0x3c),0);
      if (DAT_0034a820 != 0) FUN_00291cdc(DAT_0034a820);
  }
  return uVar1;
}
