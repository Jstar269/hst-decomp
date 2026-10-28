/* HSTMATCH module=EBOOT.BIN start=0x0029aa6c end=0x0029ab94 symbol=FUN_0029aa6c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/net_adhoc.h"

extern unsigned char DAT_00309e64[];
extern unsigned int DAT_0034b328;
extern void FUN_00000a00(void *);
extern void FUN_000104e0(void *);
extern void FUN_0001f0f0(void *, int);
extern void FUN_0029a5b0();
extern void FUN_0029a830();
extern void FUN_0029ab94(void *, int);

/* Net task deleting destructor: frees the net context and its buffers, stops the network if up. */
void *FUN_0029aa6c(NetTask *self, short flag)
{
  if (self != 0)
  {
  self->vtbl = DAT_00309e64;
  DAT_0034b328 = 0;
  NetCtx *c = self->ctx;
  if (c != 0)
  {
    if (c != 0)
    {
    if (c->bundle != 0)
    {
      FUN_000104e0(c->bundle);
      c->bundle = 0;
    }
    if (c->buf18 != 0)
    {
      FUN_00000a00(c->buf18);
      c->buf18 = 0;
    }
    if (c->buf14 != 0)
    {
      FUN_00000a00(c->buf14);
      c->buf14 = 0;
    }
    if (c->buf10 != 0)
    {
      FUN_00000a00(c->buf10);
      c->buf10 = 0;
    }
    if (c->match != 0)
    {
      FUN_0029ab94(c->match, 1);
      c->match = 0;
    }
    if (c->active != 0)
    {
      c->active = 0;
      FUN_0029a830();
      FUN_0029a5b0();
    }
    FUN_00000a00(c);
    }
    self->ctx = 0;
  }
  FUN_0001f0f0(self, 0);
  if (flag > 0)
    FUN_00000a00(self);
  }
  return self;
}
