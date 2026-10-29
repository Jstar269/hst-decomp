/* HSTMATCH module=EBOOT.BIN start=0x00154dc8 end=0x00154e30 symbol=FUN_00154dc8 lang=c99 data=0x002dca08 */
/* Ghidra pseudocode (hstgen.py tag q1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dca08-0x002dca22) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

typedef struct MoveCameraCmd {
  char pad00[8];
  int arg0; /* 0x08 */
  int arg1; /* 0x0c */
  int arg2; /* 0x10 */
} MoveCameraCmd;

extern u8 DAT_003402f0; /* script trace flag */
extern void *DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd55c();

/* Script command "MoveCamera": trace it and forward the three arguments to the host. */
u32 FUN_00154dc8(MoveCameraCmd *cmd, ScriptCtx *ctx)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("MoveCamera [%d, %d (%d)]\n", cmd->arg0, cmd->arg1, cmd->arg2);
  }
  FUN_001cd55c(DAT_0034a114, cmd->arg0, cmd->arg2, cmd->arg1);
  return 0;
}
