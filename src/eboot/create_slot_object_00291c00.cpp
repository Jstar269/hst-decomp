/* HSTMATCH module=EBOOT.BIN start=0x00291c00 end=0x00291cdc symbol=FUN_00291c00 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/material_set.h"

extern float DAT_002ffabc;
extern float DAT_002ffac0;
extern float DAT_002ffac4;
extern float DAT_002ffac8;
extern float DAT_002ffacc;
extern float DAT_002ffad0;
extern float DAT_002ffad4;

extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00050fc0(void *);
extern "C" void FUN_000511c4(void *, void *, int);
extern "C" void FUN_00051398(float, void *);

/* Creates slot i of the set on first use; the new object gets the i-th entry of a 7-entry table. */
extern "C" void FUN_00291c00(MaterialSet *set, int i) {
    if (set->slot[i] != 0) return;
    float names[7];
    void *p;
    names[0] = DAT_002ffabc;
    names[1] = DAT_002ffac0;
    names[2] = DAT_002ffac4;
    names[3] = DAT_002ffac8;
    names[4] = DAT_002ffacc;
    names[5] = DAT_002ffad0;
    names[6] = DAT_002ffad4;
    p = FUN_00000bcc(0x48);
    if (p != 0) p = FUN_00050fc0(p);
    set->slot[i] = p;
    FUN_000511c4(p, ((void **)names)[i], 0);
    FUN_00051398(203010.0f, set->slot[i]);
}
