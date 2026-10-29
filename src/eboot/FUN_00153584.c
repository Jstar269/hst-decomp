/* HSTMATCH module=EBOOT.BIN start=0x00153584 end=0x001535f0 symbol=FUN_00153584 lang=c99 data=0x002dc760 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc760-0x002dc771) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Game host object; only the field passed back to the room change is used. */
typedef struct Host {
  char pad00[0xcc];
  u32 unkcc;        /* 0xcc */
} Host;

extern u8 DAT_003402f0;     /* script trace flag */
extern Host * DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001c7d30();

/* Script command "GotoRoom": arg0 is the 1-based room number, arg1 the entry point. */
u32 FUN_00153584(ScriptCmd *cmd,ScriptCtx *ctx)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("GotoRoom[%d:%d]\n",cmd->arg0,cmd->arg1);
  }
  FUN_001c7d30(DAT_0034a114,DAT_0034a114->unkcc,cmd->arg0 + -1,cmd->arg1,0);
  return 0;
}
