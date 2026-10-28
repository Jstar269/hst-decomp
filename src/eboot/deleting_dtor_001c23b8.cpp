/* HSTMATCH module=EBOOT.BIN start=0x001c23b8 end=0x001c2498 symbol=FUN_001c23b8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/menu_state.h"

struct GObj { virtual ~GObj(); };

extern "C" char DAT_0030933c;
extern "C" char DAT_00309350;
extern "C" GObj *DAT_0034a81c;
extern "C" void __dl__FPv(void *);

extern "C" void FUN_001c3b64(void *);
extern "C" void FUN_001c3a90(void *);
extern "C" void FUN_001c3ae0(void *);
extern "C" void FUN_001c3ae8(void *);
extern "C" void FUN_001c3a88(void *);
extern "C" void FUN_001c3a18(void *);
extern "C" void FUN_001c3a98(void *);
extern "C" void FUN_002291f8(void *, int);

/* MenuState deleting destructor: frees the shared object, runs the member cleanups, frees self when flag > 0. */
extern "C" void *FUN_001c23b8(MenuState *self, short flag) {
    if (self != 0) {
        self->vtbl = &DAT_0030933c;
        if (DAT_0034a81c != 0) {
            delete DAT_0034a81c;
            DAT_0034a81c = 0;
        }
        FUN_001c3b64(self);
        FUN_001c3a90(self);
        FUN_001c3ae0(self);
        FUN_001c3ae8(self);
        FUN_001c3a88(self);
        FUN_001c3a18(self);
        FUN_001c3a98(self);
        FUN_002291f8(self->sub34, -1);
        if (self != 0) self->vtbl = &DAT_00309350;
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
