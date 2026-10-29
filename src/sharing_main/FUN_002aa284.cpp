/* HSTMATCH module=hstp_trans_main.prx start=0x002aa284 end=0x002aa2cc symbol=FUN_002aa284 lang=c++ */
/* Clone of src/eboot/FUN_0029b014.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/net_adhoc.h"

extern "C" {
extern void *DAT_003e1a00;
}

/* Object with a virtual method taking one int (slot 12). */
struct NetListener {
  virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
  virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
  virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
  virtual void Notify(int arg);
};

extern "C" void FUN_002aa284(NetTask *task)
{
  NetCtx *ctx;

  ctx = task->ctx;
  if (DAT_003e1a00 != 0) {
    ((NetListener *)DAT_003e1a00)->Notify(1);
    ctx->unk24 = 1;
  }
}
