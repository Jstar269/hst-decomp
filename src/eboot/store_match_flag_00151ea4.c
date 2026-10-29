/* HSTMATCH module=EBOOT.BIN start=0x00151ea4 end=0x00151f24 symbol=FUN_00151ea4 lang=c99 data=0x002dc608 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored the dropped print arguments (&DAT_002dc608, cmd->arg1, cmd->arg0), typed Ctx/Obj views, and the global's field is read into a local before the single-statement store of the comparison (that is what keeps the compare before the call and in the retail load order); readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc608-0x002dc621) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Host object; only the current area word is read. */
typedef struct Host { char pad[0xec]; int area; } Host;
extern unsigned char DAT_003402f0; /* script trace flag */
extern Host *DAT_0034a114;
extern unsigned int *FUN_0014c384(int a, int b); /* register slot of a script register bank */
extern void FUN_0014d044(ScriptCtx *p);
extern void FUN_0014fd94(const char *fmt, int a, int b);

/* Script command "AreaInside": store (area argument == the host's current area) into the command's register. */
int FUN_00151ea4(ScriptCmd *cmd, ScriptCtx *ctx)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("AreaInside [%d, reg:%d]\n", cmd->arg1, cmd->arg0);
  }
  int area = DAT_0034a114->area;
  *FUN_0014c384(ctx->regs, cmd->arg0) = (cmd->arg1 == area);
  return 0;
}
