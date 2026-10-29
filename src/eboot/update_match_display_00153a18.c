/* HSTMATCH module=EBOOT.BIN start=0x00153a18 end=0x00153aac symbol=FUN_00153a18 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: keep status as int and put success work inside the zero-status arm. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Node whose command record sits at 4. */
typedef struct CmdNode {
  char pad00[4];
  ScriptCmd *cmd;    /* 0x04 */
} CmdNode;

extern void *DAT_0034a114;
extern char DAT_002dc7c8[];
extern void FUN_000143b0(char *, const char *, u32);
extern u32 *FUN_0014c384(u32, u32);
extern void FUN_001cc784(void *, void *);
extern int FUN_001cd13c(void *);
extern u32 FUN_001cd284(void *);

/* If the host is ready: store its result byte into the command's register and show the name (arg0). */
bool FUN_00153a18(CmdNode *node,ScriptCtx *ctx)
{
  u32 result;
  u32 *slot;
  u32 regs;
  char name [32];
  
  if (FUN_001cd13c(DAT_0034a114) == 0) {
    regs = ctx->regs;
    result = FUN_001cd284(DAT_0034a114) & 0xff;
    slot = (u32 *)FUN_0014c384(regs,node->cmd->arg1);
    *slot = result;
    FUN_000143b0(name,DAT_002dc7c8,node->cmd->arg0);
    FUN_001cc784(DAT_0034a114,name);
    return true;
  }
  return false;
}
