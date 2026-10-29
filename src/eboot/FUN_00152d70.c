/* HSTMATCH module=EBOOT.BIN start=0x00152d70 end=0x00152de0 symbol=FUN_00152d70 lang=c99 data=0x002dc700 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc700-0x002dc714) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"
typedef int code();

/* Game settings object; only the difficulty is read. */
typedef struct Settings {
  char pad00[0x138];
  u32 difficulty;   /* 0x138 */
} Settings;

extern u8 DAT_003402f0; /* script trace flag */
extern u32 *FUN_0014c384(); /* register slot of a script register bank */
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern code * FUN_0022cd60(); /* settings accessor */

/* Script command "GetDifficulty": arg0 is the destination register. */
u32 FUN_00152d70(ScriptCmd *cmd,ScriptCtx *ctx)
{
  Settings *settings;
  u32 *slot;
  u32 regs;
  u32 difficulty;

  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("GetDifficulty [%d]\n",cmd->arg0);
  }
  regs = ctx->regs;
  settings = (Settings *)(FUN_0022cd60());
  difficulty = settings->difficulty;
  slot = (u32 *)FUN_0014c384(regs,cmd->arg0);
  *slot = difficulty;
  return 0;
}
