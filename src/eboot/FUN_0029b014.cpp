/* HSTMATCH module=EBOOT.BIN start=0x0029b014 end=0x0029b05c symbol=FUN_0029b014 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/net_adhoc.h"

extern "C" {
extern void *DAT_003386c0;
}

/* Object with a virtual method taking one int (slot 12). */
struct NetListener {
  virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
  virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
  virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
  virtual void Notify(int arg);
};

extern "C" void FUN_0029b014(NetTask *task)
{
  NetCtx *ctx;

  ctx = task->ctx;
  if (DAT_003386c0 != 0) {
    ((NetListener *)DAT_003386c0)->Notify(1);
    ctx->unk24 = 1;
  }
}
