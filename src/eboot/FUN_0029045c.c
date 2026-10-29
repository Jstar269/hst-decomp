/* HSTMATCH module=EBOOT.BIN start=0x0029045c end=0x002904d4 symbol=FUN_0029045c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002ff4e4[];
extern char DAT_002ff50c[];
extern void FUN_0028fb44();
extern int FUN_002b7800();
extern int FUN_002b7808();

/* Stops and unloads a module; returns 1 on success, 0 after logging a failure. */
u32 FUN_0029045c(u32 module_id)
{
  int result;
  u32 ok;
  
  result = FUN_002b7808(module_id,0,0,0,0);
  if (result < 0) {
    FUN_0028fb44(DAT_002ff4e4,result);
    ok = 0;
  }
  else {
    result = FUN_002b7800(module_id);
    if (result < 0) {
      FUN_0028fb44(DAT_002ff50c,result);
      ok = 0;
    }
    else {
      ok = 1;
    }
  }
  return ok;
}
