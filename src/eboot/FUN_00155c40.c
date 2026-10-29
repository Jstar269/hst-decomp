/* HSTMATCH module=EBOOT.BIN start=0x00155c40 end=0x00155cac symbol=FUN_00155c40 lang=c99 data=0x002dcb90 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_cmd.h"

extern u8 DAT_003402f0; /* script trace flag */
extern void *DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern int FUN_001c70c0();
extern void FUN_00293764();

/* Script command "UnlinkKomono": looks up the object for the argument id and, if found, releases it. */
u32 FUN_00155c40(ScriptCmd *cmd,ScriptCtx *ctx)
{
  int obj;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94("UnlinkKomono [%d]\n",cmd->arg0);
  }
  obj = FUN_001c70c0(DAT_0034a114,cmd->arg0);
  if (obj != 0) {
    FUN_00293764(obj,0);
  }
  return 0;
}
