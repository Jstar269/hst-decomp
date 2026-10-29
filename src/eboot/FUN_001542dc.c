/* HSTMATCH module=EBOOT.BIN start=0x001542dc end=0x0015435c symbol=FUN_001542dc lang=c99 data=0x002dc8a0 */
/* Ghidra pseudocode (hstgen.py tag a1v0) corrected by hand: DAT_003402f0 is unsigned char (lbu), the ctx->regs load is hoisted into a local before the value test, and the value is selected with if (x != 0) val else 0 so the branch stays non-likely; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc8a0-0x002dc8b2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

typedef struct GetPcNumberCmd {
  char pad00[8];
  int reg; /* 0x08 script register that receives the result */
} GetPcNumberCmd;

typedef struct PcObj {
  char pad00[0x1b4];
  u32 number; /* 0x1b4 */
} PcObj;

typedef struct PcOwner {
  char pad00[0x50];
  PcObj *pc; /* 0x50 */
} PcOwner;

extern unsigned char DAT_003402f0; /* script trace flag */
extern PcOwner *DAT_0034a118;
extern u32 *FUN_0014c384(u32 regs, int reg);
extern void FUN_0014d044(ScriptCtx *ctx);
extern void FUN_0014fd94(const char *fmt, int b);

/* Script command "GetPcNumber": store the number of the current PC (0 when there is none) in a register. */
u32 FUN_001542dc(GetPcNumberCmd *cmd, ScriptCtx *ctx)
{
  u32 *slot;
  u32 number;

  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("GetPcNumber [%d]\n", cmd->reg);
  }
  u32 regs = ctx->regs;
  if (DAT_0034a118->pc != 0) {
    number = DAT_0034a118->pc->number;
  }
  else {
    number = 0;
  }
  slot = FUN_0014c384(regs, cmd->reg);
  *slot = number;
  return 0;
}
