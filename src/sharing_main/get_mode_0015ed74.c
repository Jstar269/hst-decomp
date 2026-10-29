/* HSTMATCH module=hstp_trans_main.prx start=0x0015ed74 end=0x0015ede8 symbol=FUN_0015ed74 lang=c99 helpers=FUN_00157280@0x00157280-0x001572ac,FUN_00158b2c@0x00158b2c-0x00158b90,FUN_0015bb68@0x0015bb68-0x0015bb94 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/get_mode_00152bec.c, completed with its same-file static helpers FUN_0014c610, FUN_0014d044, FUN_0014fd94 defined in front of it and placed at their own retail addresses by helpers=); matching idiom: the context pointer is reassigned (`ctx = *ctx`) so it shares s0 with the loaded value; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/script_cmd.h"
#include "hst/script_node.h"

extern unsigned char DAT_003e9630; /* script trace flag */
extern char DAT_00383bb0[];
extern char DAT_003836b8[];
extern char DAT_003836c4[];
extern unsigned int *FUN_00157e10(void *, int); /* register slot of a script register bank */
static void FUN_00157280(...)
{
}
/* Trace-line indent: one prefix, then one more per nesting level. */
static void FUN_00158b2c(ScriptRunCtx *ctx)
{
  int i;
  if (DAT_003e9630 != 0) {
    FUN_00157280(DAT_003836b8);
    for (i = 0; i < ctx->depth + 1; i++) {
      FUN_00157280(DAT_003836c4);
    }
  }
}
static void FUN_0015bb68(...)
{
}
extern int FUN_0029a304(void *);

/* Script command "GetMode": arg0 is the destination register; the actor's mode (low byte) is stored there.
   The context is read as raw words: ctx[0] register bank, ctx[3] actor. */
u32 FUN_0015ed74(ScriptCmd *cmd, void **ctx)
{
  u32 mode;
  u32 *slot;
  void *actor;
  if (DAT_003e9630 != 0) {
    FUN_00158b2c((ScriptRunCtx *)ctx);
    FUN_0015bb68(DAT_00383bb0, cmd->arg0);
  }
  actor = ctx[3];
  ctx = (void **)*ctx;
  mode = FUN_0029a304(actor) & 0xff;
  slot = FUN_00157e10(ctx, cmd->arg0);
  *slot = mode;
  return 0;
}
