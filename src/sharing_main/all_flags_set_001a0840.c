/* HSTMATCH module=hstp_trans_main.prx start=0x001a0840 end=0x001a0920 symbol=FUN_001a0840 lang=c99 data=0x00388c04 */
/* Clone of src/eboot/all_flags_set_00194030.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388c04-0x00388c1c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_003b7ebc[];
extern void FUN_0001c5f4();
extern void FUN_0001c73c();
extern u32 FUN_0019fcd8();
extern u32 FUN_0019ff80();
extern u32 FUN_001a00e8();
extern u32 FUN_001a0238();
extern u32 FUN_001a039c();
extern u32 FUN_001a0650();

u32 FUN_001a0840(int param_1)
{
  int cVar1;
  int cVar2;
  int cVar3;
  int cVar4;
  int cVar5;
  int cVar6;

  if (param_1 != 0) {
    FUN_0001c5f4(DAT_003b7ebc,"menu/challenge_match.xb");
  }
  cVar1 = (u8)FUN_0019ff80();
  cVar2 = (u8)FUN_001a00e8();
  cVar3 = (u8)FUN_001a0650();
  cVar4 = (u8)FUN_001a0238();
  cVar5 = (u8)FUN_001a039c();
  if (param_1 != 0) {
    FUN_0001c73c(DAT_003b7ebc);
  }
  cVar6 = (u8)FUN_0019fcd8();
  if (cVar1 != '\0' && cVar2 != '\0' && cVar3 != '\0' && cVar4 != '\0' && cVar5 != '\0' && cVar6 != '\0') {
    return 1;
  }
  return 0;
}
