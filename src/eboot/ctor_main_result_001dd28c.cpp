/* HSTMATCH module=EBOOT.BIN start=0x001dd28c end=0x001dd370 symbol=FUN_001dd28c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the global read of DAT_002eba54 uses an empty loop as the join that makes MWCC keep
   the address unfolded (retail: lui v0,hi ; addiu v0,v0,lo ; lw a1,0(v0)). */
#include "hst/main_result_obj.h"

/* One lookup request: slot in the child's table, name to look up, and where the result's field is stored. */
typedef struct { int idx; int name; int out; } Rec;

extern "C" Rec DAT_002eba68[];
extern "C" void *DAT_002eba54;
extern "C" char DAT_002eba80;
extern "C" char DAT_00309440;

extern "C" void FUN_00102e38();
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void *FUN_001039d8(void *, void *, int);
extern "C" void *FUN_001026b8(void *, void *);

#define MAIN_RESULT_MODE_INITIAL 5
#define MAIN_RESULT_ITEM_COUNT 2

extern "C" MainResultObj *FUN_001dd28c(MainResultObj *self) {
    char *o = (char *)self; // raw byte view: typed field access here changes the loop code
    int i;
    Rec *r;
    int off;
    FUN_00102e38();
    *(void **)o = &DAT_00309440;
    FUN_00104118(o, &DAT_002eba80, 0);
    FUN_00103540(o, 5000.0f);
    void **gp = &DAT_002eba54;
    for (int i = 0; i < 0; i++) { }
    *(void **)(o + 0x58) = FUN_001039d8(o, *gp, 0);
    i = 0;
    r = DAT_002eba68;
    off = 0;
    do {
        void *q = FUN_001026b8(*(void **)(o + 0x58 + r->idx * 4), (void *)r->name);
        *(void **)(o + 0x5c + off) = q;
        r->out = *(int *)((char *)q + 0x24);
        i = i + 1;
        off = off + 4;
        r++;
    } while (i < MAIN_RESULT_ITEM_COUNT);
    *(int *)(o + 0x54) = MAIN_RESULT_MODE_INITIAL;
    return self;
}
