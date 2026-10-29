/* HSTMATCH module=hstp_trans_main.prx start=0x002a26f8 end=0x002a2860 symbol=FUN_002a26f8 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/holder_release_inner_00290ff0.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Deleting-destructor-style wrapper: the held object's inlined destructor resets three 0x1c-byte members (vtable store, close the handle like FUN_002a2670) and frees it, then the holder itself is freed when release > 0. Matching idiom: the held pointer is tested twice (`if (o) { if (o) {...free...} self->service = 0; }`), as retail does; the member addresses are tested with `&o->m != 0` (inlined member destructors). */
#include "hst/player_service.h"

extern char DAT_003b30a8;
extern char DAT_002db244[];
extern int DAT_003f3b38;
extern int DAT_003f3b48;
extern void FUN_00000a00(void *);
extern void FUN_002a130c(const char *, int);
extern int FUN_002c76a0(int);

ServiceHolder *FUN_002a26f8(ServiceHolder *self, short release)
{
    if (self != 0) {
        DAT_003f3b48 = 0;
        PlayerService *o = self->service;
        if (o != 0) {
            if (o != 0) {
                DAT_003f3b38 = 0;
                if (&o->c != 0) {
                    o->c.vtable = (unsigned int)&DAT_003b30a8;
                    if (o->c.handle >= 0) {
                        int r = FUN_002c76a0(o->c.handle);
                        if (r != 0)
                            FUN_002a130c(DAT_002db244, r);
                        o->c.handle = -1;
                    }
                }
                if (&o->b != 0) {
                    o->b.vtable = (unsigned int)&DAT_003b30a8;
                    if (o->b.handle >= 0) {
                        int r = FUN_002c76a0(o->b.handle);
                        if (r != 0)
                            FUN_002a130c(DAT_002db244, r);
                        o->b.handle = -1;
                    }
                }
                if (&o->a != 0) {
                    o->a.vtable = (unsigned int)&DAT_003b30a8;
                    if (o->a.handle >= 0) {
                        int r = FUN_002c76a0(o->a.handle);
                        if (r != 0)
                            FUN_002a130c(DAT_002db244, r);
                        o->a.handle = -1;
                    }
                }
                FUN_00000a00(o);
            }
            self->service = 0;
        }
        if (release > 0)
            FUN_00000a00(self);
    }
    return self;
}
