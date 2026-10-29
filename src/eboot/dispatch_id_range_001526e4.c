/* HSTMATCH module=EBOOT.BIN start=0x001526e4 end=0x00152768 symbol=FUN_001526e4 lang=c99 data=0x002dc674 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is unsigned char (lbu) and the if/else tests iVar1 >= 10000 first; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc674-0x002dc68b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Camera numbers from this value upward select the second camera table, relative to it. */
#define CAMERA_SECOND_TABLE 10000

extern unsigned char DAT_003402f0; /* script trace flag */
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd440();
extern void FUN_001cd490();

/* Script command "ChangeCamera": arg0 is the camera number, arg1 the extra argument passed through. */
u32 FUN_001526e4(ScriptCmd *cmd,ScriptCtx *ctx)
{
  int camera;

  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("ChangeCamera [%d, %d]\n",cmd->arg0,
                 cmd->arg1);
  }
  camera = cmd->arg0;
  if (camera >= CAMERA_SECOND_TABLE) {
    FUN_001cd440(DAT_0034a114,camera + -CAMERA_SECOND_TABLE,cmd->arg1);
  }
  else {
    FUN_001cd490(DAT_0034a114,camera,cmd->arg1);
  }
  return 0;
}
