/* HSTMATCH module=EBOOT.BIN start=0x001527e8 end=0x00152858 symbol=FUN_001527e8 lang=c99 data=0x002dc68c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu), not undefined4; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc68c-0x002dc69c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

extern unsigned char DAT_003402f0; /* script trace flag */
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_002878cc();

/* Script command "SePlay": arg1 is the sound name (a string) and arg0 an integer; both go to the actor's sound call,
   which is skipped when the actor is missing. */
u32 FUN_001527e8(ScriptCmd *cmd,ScriptCtx *ctx)
{
  if (ctx->actor != 0) {
    FUN_002878cc(ctx->actor,cmd->arg1,cmd->arg0
                );
  }
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("SePlay [%s:%d]\n",cmd->arg1,
                 cmd->arg0);
  }
  return 0;
}
