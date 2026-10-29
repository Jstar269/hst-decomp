/* HSTMATCH module=EBOOT.BIN start=0x001c5084 end=0x001c51c8 symbol=FUN_001c5084 lang=c99 rodata=0x002c63ec */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/phase_obj.h"

typedef PhaseObj Obj;
extern int DAT_0034a678;
extern int DAT_0034a67c;
void FUN_001c627c(Obj *);
void FUN_001c6328(Obj *);
void FUN_001c6354(Obj *);
void FUN_001c6608(Obj *);
void FUN_0001f20c(int, int, int);

static inline _Bool Inner(int k)
{
    if ((unsigned)(DAT_0034a678 - 0x23) < 2) {
        return 0;
    }
    if (k == 0x20 && (unsigned)(DAT_0034a67c - 0x23) < 2) {
        return 0;
    }
    return 1;
}

static inline _Bool Pred(Obj *o)
{
    _Bool r = !o->unk16c;
    if (!r) {
        r = Inner(o->unk168);
    }
    return r;
}

/* Runs the handler for the object's current phase when it is ready, then reports readiness through the handle. */
void FUN_001c5084(Obj *o)
{
    _Bool ok = Pred(o);
    if (o->unkf0 != 0) {
        ok = 0;
    }
    if (ok) {
        switch (o->state) {
        case 0:
            FUN_001c627c(o);
            break;
        case 1:
            FUN_001c6328(o);
            break;
        case 2:
        case 3:
        case 4:
            FUN_001c6354(o);
            break;
        case 5:
            FUN_001c6608(o);
            ok = 0;
        }
    }
    int h = o->handle;
    if (h != 0) {
        FUN_0001f20c(h, 2, ok && o->state != 1);
    }
}
