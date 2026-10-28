/* HSTMATCH module=EBOOT.BIN start=0x0029a8bc end=0x0029a9a0 symbol=FUN_0029a8bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: shared the owner-field assignment and used an explicit zero allocation case; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/net_adhoc.h"

extern u8 DAT_00309e64;
extern u32 DAT_0034b328;
extern int FUN_00000bcc();
extern int FUN_00010184();
extern u32 * FUN_0001f06c();
extern MatchState * FUN_0029a9a0();

/* Net task constructor: allocates the net context, its match state and work buffers. */
NetTask * FUN_0029a8bc(NetTask *self)
{
  NetCtx *ctx;
  int mem;
  u32 buf;
  
  FUN_0001f06c();
  self->vtbl = &DAT_00309e64;
  self->ctx = 0;
  DAT_0034b328 = (unsigned int)(self);
  ctx = (NetCtx *)FUN_00000bcc(0x2c);
  if (ctx != (NetCtx *)0x0) {
    ctx->active = 0;
    ctx->count = 0;
    ctx->mode = 0;
    ctx->match = 0;
    ctx->buf10 = 0;
    ctx->buf14 = 0;
    ctx->buf18 = 0;
    ctx->bundle = 0;
    ctx->bundleSize = 0;
    ctx->unk24 = 0;
    ctx->unk28 = 0;
    mem = FUN_00000bcc(0x1583c);
    switch (mem) {
    case 0:
      ctx->match = (MatchState *)mem;
      break;
    default:
      ctx->match = FUN_0029a9a0(mem);
      break;
    }
    buf = FUN_00000bcc(0x2c4);
    ctx->buf10 = (void *)buf;
    buf = FUN_00000bcc(0x50);
    ctx->buf14 = (void *)buf;
    buf = FUN_00000bcc(100);
    ctx->buf18 = (void *)buf;
    buf = FUN_00010184(0x40,0x216e00);
    ctx->bundle = (void *)buf;
  }
  self->ctx = ctx;
  return self;
}
