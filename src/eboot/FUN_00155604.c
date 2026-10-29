/* HSTMATCH module=EBOOT.BIN start=0x00155604 end=0x0015562c symbol=FUN_00155604 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_cmd.h"

#define CALL_DELAY 1000 /* third argument of the helper call */

extern void FUN_00288828();

u32 FUN_00155604(ScriptCmd *cmd)
{
  FUN_00288828(cmd->arg0,cmd->arg1,CALL_DELAY);
  return 0;
}
