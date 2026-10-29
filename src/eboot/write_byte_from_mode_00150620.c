/* HSTMATCH module=EBOOT.BIN start=0x00150620 end=0x0015068c symbol=FUN_00150620 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_cmd.h"

extern u32 DAT_0034a114;
extern int FUN_0014c384(); /* register slot of a script register bank */
extern int FUN_001cd150();
extern u8 FUN_001cd290();

/* Script command: when the host query FUN_001cd150 returns 0, store the host byte value in the command source register and return 1. */
bool FUN_00150620(ScriptCmd *cmd,ScriptCtx *ctx)
{
  u32 regs;

  if (FUN_001cd150(DAT_0034a114) == 0) {
    regs = ctx->regs;
    *(u32 *)FUN_0014c384(regs,cmd->src->reg) =
         FUN_001cd290(DAT_0034a114) & 0xff;
    return 1;
  }
  return 0;
}
