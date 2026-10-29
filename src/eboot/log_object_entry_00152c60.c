/* HSTMATCH module=EBOOT.BIN start=0x00152c60 end=0x00152cec symbol=FUN_00152c60 lang=c99 data=0x002dc6d8 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc6d8-0x002dc6ee) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py candidate FUN_00152c60) corrected by hand: pointer-typed self parameter, inverted ternary and the (x != 0) ^ 1 flag with an unsigned char parameter; readability pass; exact match verified; names and types await human review. */
#include "hst/script_cmd.h"

extern unsigned char DAT_003402f0; /* script trace flag */
extern char DAT_002dc57c;
extern char DAT_002dc580;
extern void FUN_0014c3ac(int, int, unsigned char);
extern void FUN_0014d044(void *);
extern void FUN_0014fd94(char *, int, char *);

/* Script command "SetActiveArea": arg0 is the area number, the low byte of arg1 its on/off state (passed on inverted). */
int FUN_00152c60(ScriptCmd *cmd, ScriptCtx *ctx)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("SetActiveArea[%d:%s]\n", cmd->arg0,
                 *(unsigned char *)&cmd->arg1 != 0 ? &DAT_002dc57c : &DAT_002dc580);
  }
  FUN_0014c3ac(ctx->regs, cmd->arg0, (*(unsigned char *)&cmd->arg1 != 0) ^ 1);
  return 0;
}
