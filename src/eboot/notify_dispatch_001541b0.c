/* HSTMATCH module=EBOOT.BIN start=0x001541b0 end=0x00154208 symbol=FUN_001541b0 lang=c99 data=0x002dc870 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu); readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc870-0x002dc889) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

typedef struct TargetCameraCmd {
  char pad00[8];
  int point; /* 0x08 */
} TargetCameraCmd;

extern unsigned char DAT_003402f0; /* script trace flag */
extern void *DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001c7df0();

/* Script command "Target Camera": trace it and point the camera at the given point. */
u32 FUN_001541b0(TargetCameraCmd *cmd, ScriptCtx *ctx)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("Target Camera[point:%d]\n", cmd->point);
  }
  FUN_001c7df0(DAT_0034a114, cmd->point);
  return 0;
}
