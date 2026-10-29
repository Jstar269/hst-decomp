/* HSTMATCH module=EBOOT.BIN start=0x0027da94 end=0x0027db44 symbol=FUN_0027da94 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: typed delete calls with arguments; readability pass; exact match verified; names and types await human review. */
#include "hst/entry_pool.h"

extern "C" {
extern void *DAT_00309c60;
extern int DAT_0034a7e0;
extern void *DAT_0034a7e4;
extern void FUN_00000a00(void *);
extern void *FUN_0001f0f0(void *, int);
}

struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: clear the singleton pointer, delete the sub-object, free the entry pool, run the base destructor, free self when flags > 0. */
extern "C" void *FUN_0027da94(EntryPoolObj *self, short flags)
{
    if (self != 0) {
        self->vtable = &DAT_00309c60;
        DAT_0034a7e0 = 0;
        if (self->sub != 0) {
            delete (VC_0 *)self->sub;
            self->sub = 0;
        }
        if (DAT_0034a7e4 != 0) {
            FUN_00000a00(DAT_0034a7e4);
            DAT_0034a7e4 = 0;
        }
        FUN_0001f0f0(self, 0);
        if (flags > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}
