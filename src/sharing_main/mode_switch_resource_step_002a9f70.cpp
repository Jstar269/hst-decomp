/* HSTMATCH module=hstp_trans_main.prx start=0x002a9f70 end=0x002aa06c symbol=FUN_002a9f70 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/mode_switch_resource_step_0029acec.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/net_adhoc.h"

struct Res;
struct Hook {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
};
extern Res *DAT_003ea8ec;
extern Hook *DAT_003e1a00;
extern char DAT_003eaad8;
extern "C" int FUN_001204dc(Res *r);
extern "C" int FUN_001205f0(Res *r);
extern "C" void FUN_001bfc3c(void *p, int v);
extern "C" void FUN_002a5ba8(Res *r);
extern "C" void FUN_002aa06c(NetCtx *n, int v);

/* Bundle-read modes (NetCtx.mode) */
enum { BUNDLE_IDLE = 0, BUNDLE_READ = 4 };

/* Per-frame step of the net task: reacts to the dialog result by starting or cancelling the bundle read. */
extern "C" void FUN_002a9f70(NetTask *self)
{
    NetCtx *n = self->ctx;
    switch (n->mode) {
    case 1:
        if (FUN_001204dc(DAT_003ea8ec) != 0) {
            FUN_001bfc3c(&DAT_003eaad8, 3);
            FUN_002aa06c(n, BUNDLE_IDLE);
            FUN_002a5ba8(DAT_003ea8ec);
        }
        break;
    case 2:
        if (FUN_001204dc(DAT_003ea8ec) != 0) {
            if (FUN_001205f0(DAT_003ea8ec) == 0) {
                FUN_002aa06c(n, BUNDLE_READ);
            } else {
                FUN_002aa06c(n, BUNDLE_IDLE);
            }
            FUN_002a5ba8(DAT_003ea8ec);
        }
        break;
    }
    if (DAT_003e1a00 != 0) {
        DAT_003e1a00->v11();
    }
    n->count++;
}
