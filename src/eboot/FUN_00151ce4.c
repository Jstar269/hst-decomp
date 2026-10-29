/* HSTMATCH module=EBOOT.BIN start=0x00151ce4 end=0x00151d68 symbol=FUN_00151ce4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00151ce4.c) corrected by hand: typed the byte and pointer globals, inverted the message branch, and materialized the post-cleanup zero flag; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_cmd.h"

/* Command record whose argument is a single state byte. */
typedef struct StateCmd { char pad00[8]; u8 state; } StateCmd;

extern u8 DAT_002dc440;
extern u8 DAT_002dc5d8;
extern unsigned char DAT_003402f0; /* script trace flag */
extern void *DAT_0034a2e0;
extern char DAT_002dc5c0[];
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_00225d54(void *, int, int);
extern void FUN_0022bf40();

/* Script command: log the state when tracing, then pass the inverted state to the DAT_0034a2e0 object. */
u32 FUN_00151ce4(StateCmd *cmd,ScriptCtx *ctx)
{
  u8 *message;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    if (cmd->state != 0) {
      message = &DAT_002dc5d8;
    } else {
      message = &DAT_002dc440;
    }
    FUN_0014fd94(DAT_002dc5c0,message);
  }
  FUN_0022bf40(0);
  u8 state = cmd->state;
  int is_zero = ((state != 0) ^ 1);
  FUN_00225d54(DAT_0034a2e0,0,is_zero);
  return 0;
}
