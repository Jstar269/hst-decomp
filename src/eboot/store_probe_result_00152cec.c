/* HSTMATCH module=EBOOT.BIN start=0x00152cec end=0x00152d70 symbol=FUN_00152cec lang=c99 data=0x002dc6f0 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored the dropped print argument (&DAT_002dc6f0, f8), typed host views, the callee's bool result kept in an int, and matching idiom: the context's actor pointer is read through a volatile ScriptCtx before ctx->regs (that fixes the load order so ctx and the register number share one saved register; plain locals, const, comma sequences and statement permutations all gave a third saved register); readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc6f0-0x002dc6ff) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Second-level host object; only one word is read. */
typedef struct HostInner {
  char pad00[0x1b4];
  int unk1b4;         /* 0x1b4 */
} HostInner;
typedef struct HostRoot {
  char pad00[0x50];
  HostInner *inner;   /* 0x50 */
} HostRoot;

extern unsigned char DAT_003402f0; /* script trace flag */
extern HostRoot *DAT_0034a118;
extern unsigned int *FUN_0014c384(int a, int b); /* register slot of a script register bank */
extern void FUN_0014d044(ScriptCtx *p);
extern void FUN_0014fd94(const char *fmt, int a);
extern bool FUN_00288be8(ScriptActor *a, int b);

/* Script command "IsMyBoss": arg0 is the destination register; stores the result of the actor's boss test. */
int FUN_00152cec(ScriptCmd *cmd, ScriptCtx *ctx)
{
  int result;
  int regs;
  ScriptActor *actor;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("IsMyBoss [%d]\n", cmd->arg0);
  }
  actor = ((volatile ScriptCtx *)ctx)->actor;
  regs = ctx->regs;
  result = FUN_00288be8(actor, DAT_0034a118->inner->unk1b4);
  *FUN_0014c384(regs, cmd->arg0) = result;
  return 0;
}
