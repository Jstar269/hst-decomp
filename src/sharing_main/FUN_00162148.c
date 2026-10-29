/* HSTMATCH module=hstp_trans_main.prx start=0x00162148 end=0x001621b4 symbol=FUN_00162148 lang=c99 data=0x00384078 */
/* Clone of src/eboot/FUN_00155c40.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00384078-0x0038408b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

extern u8 DAT_003e9630; /* script trace flag */
extern void *DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern int FUN_001d54e8();
extern void FUN_002a4d70();

/* Script command "UnlinkKomono": looks up the object for the argument id and, if found, releases it. */
u32 FUN_00162148(ScriptCmd *cmd,ScriptCtx *ctx)
{
  int obj;
  
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(ctx);
    FUN_0015bb68("UnlinkKomono [%d]\n",cmd->arg0);
  }
  obj = FUN_001d54e8(DAT_003f344c,cmd->arg0);
  if (obj != 0) {
    FUN_002a4d70(obj,0);
  }
  return 0;
}
