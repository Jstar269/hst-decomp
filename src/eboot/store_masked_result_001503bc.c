/* HSTMATCH module=EBOOT.BIN start=0x001503bc end=0x00150458 symbol=FUN_001503bc lang=c99 data=0x002dc3c0 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global typed unsigned char (lbu), the call result masked with 0xff before the store, uVar4/uVar5 declaration order swapped for the s-registers; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc3c0-0x002dc3df) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

extern u8 DAT_003402f0; /* script trace flag */
extern u32 DAT_0034a114;
extern u32 * FUN_0014c384(); /* register slot of a script register bank */
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern int FUN_001cd1b8();

/* Script command "IsExistText": ask the host whether the text exists and store the 0/1 answer in a register. */
u32 FUN_001503bc(ScriptCmd *cmd,ScriptCtx *ctx)
{
  u32 *trace_reg;
  u32 found;
  u32 *slot;
  u32 regs;
  u32 actor;
  
  actor = (u32)ctx->actor;
  regs = ctx->regs;
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    trace_reg = FUN_0014c384(regs,8);
    FUN_0014fd94("IsExistText [%s_%02d, reg:%d]\n",cmd->arg0,*trace_reg,
                 cmd->arg1);
  }
  found = FUN_001cd1b8(DAT_0034a114,actor,cmd->arg0) & 0xff;
  slot = FUN_0014c384(regs,cmd->arg1);
  *slot = found;
  return 0;
}
