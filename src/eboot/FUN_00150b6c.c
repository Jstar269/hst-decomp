/* HSTMATCH module=EBOOT.BIN start=0x00150b6c end=0x00150c1c symbol=FUN_00150b6c lang=c99 data=0x002dc424 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00150b6c.c) corrected by hand: typed the global byte and helper arguments, and reused one materialized resource flag across logging; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc424-0x002dc42d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/script_cmd.h"

#define MATCH_REG 0xb /* register read and cleared by the command */

extern u8 DAT_002dc440;
extern unsigned char DAT_003402f0; /* script trace flag */
extern void *DAT_0034a114;
extern char DAT_002dc430[];
extern int *FUN_0014c384(u32, int); /* register slot of a script register bank */
extern void FUN_0014d044(ScriptCtx *);
extern void FUN_0014fd94(char *, char *);
extern void FUN_001cc988(void *, int);

/* Script command "Match": pass the register's non-zero state to the host, flag the actor and clear the register. */
u32 FUN_00150b6c(u32 cmd,ScriptCtx *ctx)
{
  u32 regs = ctx->regs;
  int value = *FUN_0014c384(regs,MATCH_REG);
  int has_resource = value != 0;
  char *message;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    if (has_resource) {
      message = DAT_002dc430;
    }
    else {
      message = (char *)(&DAT_002dc440);
    }
    FUN_0014fd94("Match%s\n",message);
  }
  FUN_001cc988(DAT_0034a114,has_resource);
  ctx->actor->unk5a = 1;
  *FUN_0014c384(regs,MATCH_REG) = 0;
  return 0;
}
