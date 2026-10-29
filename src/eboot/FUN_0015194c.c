/* HSTMATCH module=EBOOT.BIN start=0x0015194c end=0x001519b4 symbol=FUN_0015194c lang=c99 data=0x002dc554 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc554-0x002dc568) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

extern u8 DAT_003402f0; /* script trace flag */
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cc7d0();

/* Script command "Request Event": hand the event name to the host and trace it. */
u32 FUN_0015194c(ScriptCmd *cmd,ScriptCtx *ctx)
{
  FUN_001cc7d0(DAT_0034a114,cmd->arg0);
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("Request Event [%s]\n",cmd->arg0);
  }
  return 0;
}
