/* HSTMATCH module=hstp_trans_main.prx start=0x0015eef8 end=0x0015ef68 symbol=FUN_0015eef8 lang=c99 data=0x00383be8 */
/* Clone of src/eboot/FUN_00152d70.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383be8-0x00383bfc) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"
typedef int code();

/* Game settings object; only the difficulty is read. */
typedef struct Settings {
  char pad00[0x138];
  u32 difficulty;   /* 0x138 */
} Settings;

extern u8 DAT_003e9630; /* script trace flag */
extern u32 *FUN_00157e10(); /* register slot of a script register bank */
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern code * FUN_0023ce60(); /* settings accessor */

/* Script command "GetDifficulty": arg0 is the destination register. */
u32 FUN_0015eef8(ScriptCmd *cmd,ScriptCtx *ctx)
{
  Settings *settings;
  u32 *slot;
  u32 regs;
  u32 difficulty;

  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(ctx);
    FUN_0015bb68("GetDifficulty [%d]\n",cmd->arg0);
  }
  regs = ctx->regs;
  settings = (Settings *)(FUN_0023ce60());
  difficulty = settings->difficulty;
  slot = (u32 *)FUN_00157e10(regs,cmd->arg0);
  *slot = difficulty;
  return 0;
}
