/* HSTMATCH module=hstp_trans_main.prx start=0x0015d9f4 end=0x0015da5c symbol=FUN_0015d9f4 lang=c99 data=0x00383a3c */
/* Clone of src/eboot/FUN_0015194c.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383a3c-0x00383a50) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

extern u8 DAT_003e9630; /* script trace flag */
extern u32 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001daf04();

/* Script command "Request Event": hand the event name to the host and trace it. */
u32 FUN_0015d9f4(ScriptCmd *cmd,ScriptCtx *ctx)
{
  FUN_001daf04(DAT_003f344c,cmd->arg0);
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(ctx);
    FUN_0015bb68("Request Event [%s]\n",cmd->arg0);
  }
  return 0;
}
