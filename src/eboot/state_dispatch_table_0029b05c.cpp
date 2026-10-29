/* HSTMATCH module=EBOOT.BIN start=0x0029b05c end=0x0029b148 symbol=FUN_0029b05c lang=c++ rodata=0x002cb524 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/net_xfer.h"

extern "C" void *DAT_003415ac;

extern "C" void FUN_0029ade8(NetCtx *, int);
extern "C" void FUN_0029d72c();
extern "C" void FUN_0029d2b8();
extern "C" void FUN_0029ce64();
extern "C" void FUN_0029c7d0();
extern "C" void FUN_0029bf68();
extern "C" void FUN_0029bd0c();
extern "C" void FUN_00295cdc(void *);
extern "C" void FUN_0029b148();

#define BUNDLE_WAIT_FRAMES 10 /* frames to wait in the reset mode before the bundle is read */

/* Per-frame dispatch on the net context's mode. */
extern "C" void FUN_0029b05c(NetTask *task) {
    NetCtx *ctx = task->ctx;
    switch (ctx->mode) {
    case NET_MODE_BUNDLE_RESET:
        if (ctx->count >= BUNDLE_WAIT_FRAMES) FUN_0029ade8(ctx, NET_MODE_BUNDLE_READ);
        break;
    case NET_MODE_BUNDLE_READ:
        FUN_0029d72c();
        break;
    case 5:
        FUN_0029d2b8();
        break;
    case 6:
        FUN_0029ce64();
        break;
    case 7:
        FUN_0029c7d0();
        break;
    case NET_MODE_XFER_START:
        FUN_0029bf68();
        break;
    case NET_MODE_XFER_STOP:
        FUN_0029bf68();
        break;
    case 10:
        FUN_0029bd0c();
        FUN_00295cdc(DAT_003415ac);
        break;
    case NET_MODE_XFER_RUN:
        FUN_0029b148();
    }
}
