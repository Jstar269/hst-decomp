/* HSTMATCH module=EBOOT.BIN start=0x00194030 end=0x00194110 symbol=FUN_00194030 lang=c99 data=0x002e1528 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e1528-0x002e1540) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char DAT_0030ebf4[];
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern u32 FUN_001934c8();
extern u32 FUN_00193770();
extern u32 FUN_001938d8();
extern u32 FUN_00193a28();
extern u32 FUN_00193b8c();
extern u32 FUN_00193e40();

u32 FUN_00194030(int param_1)
{
  int cVar1;
  int cVar2;
  int cVar3;
  int cVar4;
  int cVar5;
  int cVar6;

  if (param_1 != 0) {
    FUN_0001ca58(DAT_0030ebf4,"menu/challenge_match.xb");
  }
  cVar1 = (u8)FUN_00193770();
  cVar2 = (u8)FUN_001938d8();
  cVar3 = (u8)FUN_00193e40();
  cVar4 = (u8)FUN_00193a28();
  cVar5 = (u8)FUN_00193b8c();
  if (param_1 != 0) {
    FUN_0001cb88(DAT_0030ebf4);
  }
  cVar6 = (u8)FUN_001934c8();
  if (cVar1 != '\0' && cVar2 != '\0' && cVar3 != '\0' && cVar4 != '\0' && cVar5 != '\0' && cVar6 != '\0') {
    return 1;
  }
  return 0;
}
