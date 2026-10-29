/* HSTMATCH module=EBOOT.BIN start=0x00152bec end=0x00152c60 symbol=FUN_00152bec lang=c99 helpers=FUN_0014c610@0x0014c610-0x0014c63c,FUN_0014d044@0x0014d044-0x0014d0a8,FUN_0014fd94@0x0014fd94-0x0014fdc0 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/get_mode_00152bec.c, completed with its same-file static helpers FUN_0014c610, FUN_0014d044, FUN_0014fd94 defined in front of it and placed at their own retail addresses by helpers=); matching idiom: the context pointer is reassigned (`ctx = *ctx`) so it shares s0 with the loaded value; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_cmd.h"
#include "hst/script_node.h"

extern unsigned char DAT_003402f0; /* script trace flag */
extern char DAT_002dc6c8[];
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern unsigned int *FUN_0014c384(void *, int); /* register slot of a script register bank */
static void FUN_0014c610(...)
{
}
/* Trace-line indent: one prefix, then one more per nesting level. */
static void FUN_0014d044(ScriptRunCtx *ctx)
{
  int i;
  if (DAT_003402f0 != 0) {
    FUN_0014c610(DAT_002dc240);
    for (i = 0; i < ctx->depth + 1; i++) {
      FUN_0014c610(DAT_002dc24c);
    }
  }
}
static void FUN_0014fd94(...)
{
}
extern int FUN_00288b68(void *);

/* Script command "GetMode": arg0 is the destination register; the actor's mode (low byte) is stored there.
   The context is read as raw words: ctx[0] register bank, ctx[3] actor. */
u32 FUN_00152bec(ScriptCmd *cmd, void **ctx)
{
  u32 mode;
  u32 *slot;
  void *actor;
  if (DAT_003402f0 != 0) {
    FUN_0014d044((ScriptRunCtx *)ctx);
    FUN_0014fd94(DAT_002dc6c8, cmd->arg0);
  }
  actor = ctx[3];
  ctx = (void **)*ctx;
  mode = FUN_00288b68(actor) & 0xff;
  slot = FUN_0014c384(ctx, cmd->arg0);
  *slot = mode;
  return 0;
}
