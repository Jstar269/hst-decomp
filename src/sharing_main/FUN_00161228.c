/* HSTMATCH module=hstp_trans_main.prx start=0x00161228 end=0x00161290 symbol=FUN_00161228 lang=c99 data=0x00383ef0 */
/* Clone of src/eboot/FUN_00154dc8.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383ef0-0x00383f0a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

typedef struct MoveCameraCmd {
  char pad00[8];
  int arg0; /* 0x08 */
  int arg1; /* 0x0c */
  int arg2; /* 0x10 */
} MoveCameraCmd;

extern u8 DAT_003e9630; /* script trace flag */
extern void *DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001dbc38();

/* Script command "MoveCamera": trace it and forward the three arguments to the host. */
u32 FUN_00161228(MoveCameraCmd *cmd, ScriptCtx *ctx)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(ctx);
    FUN_0015bb68("MoveCamera [%d, %d (%d)]\n", cmd->arg0, cmd->arg1, cmd->arg2);
  }
  FUN_001dbc38(DAT_003f344c, cmd->arg0, cmd->arg2, cmd->arg1);
  return 0;
}
