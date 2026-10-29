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

/* Load the five challenge tables (with the menu archive opened around them when asked), build the name index,
   and return 1 when all six steps report success. */
u32 FUN_00194030(int openArchive)
{
  int ok1;
  int ok2;
  int ok3;
  int ok4;
  int ok5;
  int ok6;

  if (openArchive != 0) {
    FUN_0001ca58(DAT_0030ebf4,"menu/challenge_match.xb");
  }
  ok1 = (u8)FUN_00193770();
  ok2 = (u8)FUN_001938d8();
  ok3 = (u8)FUN_00193e40();
  ok4 = (u8)FUN_00193a28();
  ok5 = (u8)FUN_00193b8c();
  if (openArchive != 0) {
    FUN_0001cb88(DAT_0030ebf4);
  }
  ok6 = (u8)FUN_001934c8();
  if (ok1 != '\0' && ok2 != '\0' && ok3 != '\0' && ok4 != '\0' && ok5 != '\0' && ok6 != '\0') {
    return 1;
  }
  return 0;
}
