/* HSTMATCH module=EBOOT.BIN start=0x00252fbc end=0x00253054 symbol=FUN_00252fbc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/disp_ctx.h"

struct Inner { char pad[0x318]; unsigned char f318; };
extern "C" DispCtx *DAT_0034a794;
extern "C" char DAT_0034a678[];
extern "C" void FUN_00234158(void *, int);
extern "C" void FUN_0023466c(void *);
extern "C" void FUN_002528ac(void *);

/* Reacts to the display controller's current state (3: one of two messages by a flag of the owned object; 5: a different call), then refreshes it. */
extern "C" void FUN_00252fbc(void)
{
    DispCtx *c = DAT_0034a794;
    if (c != 0) {
        if (c->state == 3) {
            bool t = !((Inner *)c->obj)->f318;
            if (t)
                FUN_00234158(DAT_0034a678, 0x2d);
            else
                FUN_00234158(DAT_0034a678, 0x2c);
        } else if (c->state == 5) {
            FUN_0023466c(DAT_0034a678);
        }
        FUN_002528ac(DAT_0034a794);
    }
}
