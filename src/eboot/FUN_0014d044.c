/* HSTMATCH module=EBOOT.BIN start=0x0014d044 end=0x0014d0a8 symbol=FUN_0014d044 lang=c99 helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (the same-file helper of src/eboot/get_mode_00152bec.c as its own source, with its static log stub FUN_0014c610 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_node.h"

extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];

static void FUN_0014c610(...)
{
}

/* Debug log: prints a header line and one indent marker per nesting level (when logging is on). */
void FUN_0014d044(ScriptRunCtx *ctx)
{
  int i;
  if (DAT_003402f0 != 0) {
    FUN_0014c610(DAT_002dc240);
    for (i = 0; i < ctx->depth + 1; i++) {
      FUN_0014c610(DAT_002dc24c);
    }
  }
}
