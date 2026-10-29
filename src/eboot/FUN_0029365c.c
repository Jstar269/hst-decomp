/* HSTMATCH module=EBOOT.BIN start=0x0029365c end=0x0029368c symbol=FUN_0029365c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/komono_obj.h"

extern void FUN_00059174();
extern void FUN_0005f0d8();

void FUN_0029365c(KomonoObj *obj)
{
  ModelHolder *sub;
  
  sub = obj->sub;
  FUN_00059174(sub);
  FUN_0005f0d8(sub);
}
