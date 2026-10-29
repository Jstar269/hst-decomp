/* HSTMATCH module=EBOOT.BIN start=0x00155bb0 end=0x00155bf8 symbol=FUN_00155bb0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the flag global typed as a byte and the object address Ghidra dropped from the call restored; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_cmd.h"

extern u8 DAT_003402f0; /* script trace flag */
extern u8 DAT_002dcb78;
extern u8 DAT_0034179c;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001b46bc();

/* Script command "EnvSeStart": runs the helper on the global object. */
u32 FUN_00155bb0(ScriptCmd *cmd,ScriptCtx *ctx)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(ctx);
    FUN_0014fd94(&DAT_002dcb78);
  }
  FUN_001b46bc((int *)&DAT_0034179c);
  return 0;
}
