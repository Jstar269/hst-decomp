/* HSTMATCH module=EBOOT.BIN start=0x000ff98c end=0x000ffa60 symbol=FUN_000ff98c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d8a28;
extern u8 DAT_0033b394;
extern u32 DAT_0033b45c;
extern char DAT_0033a6e0[];
extern u32 * FUN_000114c0();
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();

void FUN_000ff98c(u32 param_1,u32 param_2)
{
  int *piVar1;
  u32 uVar2;
  int iVar3;
  
  if (DAT_0033b45c == 0) {
    FUN_000114c0(&DAT_0033b394,0,200);
  }
  uVar2 = 0;
  piVar1 = (int *)&DAT_0033b394;
  do {
    if (*piVar1 == 0) {
      iVar3 = (int)(DAT_0033a6e0 + uVar2 * 0x41);
      FUN_000149a8(iVar3,param_1);
      FUN_00014788(iVar3,&DAT_002d8a28);
      *(u32 *)(&DAT_0033b394 + uVar2 * 4) = param_2;
      DAT_0033b45c = DAT_0033b45c + 1;
      return;
    }
    uVar2 = uVar2 + 1;
    piVar1 = piVar1 + 1;
  } while (uVar2 < 0x32);
}
