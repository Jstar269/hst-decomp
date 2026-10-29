/* HSTMATCH module=hstp_trans_main.prx start=0x0015f7b4 end=0x0015f820 symbol=FUN_0015f7b4 lang=c99 data=0x00383c48 */
/* Clone of src/eboot/FUN_00153584.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383c48-0x00383c59) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Game host object; only the field passed back to the room change is used. */
typedef struct Host {
  char pad00[0xcc];
  u32 unkcc;        /* 0xcc */
} Host;

extern u8 DAT_003e9630;     /* script trace flag */
extern Host * DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001d61c4();

/* Script command "GotoRoom": arg0 is the 1-based room number, arg1 the entry point. */
u32 FUN_0015f7b4(ScriptCmd *cmd,ScriptCtx *ctx)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(ctx);
    FUN_0015bb68("GotoRoom[%d:%d]\n",cmd->arg0,cmd->arg1);
  }
  FUN_001d61c4(DAT_003f344c,DAT_003f344c->unkcc,cmd->arg0 + -1,cmd->arg1,0);
  return 0;
}
