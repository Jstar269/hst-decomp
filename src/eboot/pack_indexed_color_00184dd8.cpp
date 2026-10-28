/* HSTMATCH module=EBOOT.BIN start=0x00184dd8 end=0x00184fac symbol=FUN_00184dd8 lang=c++ */
/* Clone of src/sharing_main/pack_indexed_color_00191524.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: switch statement on index 0..4 and right-nested bitwise-OR color packing helper; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern int *FUN_0016bc8c();
extern int FUN_00216de8(int);
}

static inline u32 PackColor(u16 r, u16 g, u16 b)
{
    return (r & 0xff) | (((g & 0xff) << 8) | (((b & 0xff) << 16) | 0x80000000));
}

extern "C" u32 FUN_00184dd8(int param_1, int param_2)
{
    int *puVar1 = FUN_0016bc8c();
    u32 res = 0;
    u16 r, g, b;
    switch (param_2) {
    case 0:
        r = FUN_00216de8(puVar1[27]);
        g = FUN_00216de8(puVar1[28]);
        b = FUN_00216de8(puVar1[29]);
        res = PackColor(r, g, b);
        break;
    case 1:
        r = FUN_00216de8(puVar1[30]);
        g = FUN_00216de8(puVar1[31]);
        b = FUN_00216de8(puVar1[32]);
        res = PackColor(r, g, b);
        break;
    case 2:
        r = FUN_00216de8(puVar1[33]);
        g = FUN_00216de8(puVar1[34]);
        b = FUN_00216de8(puVar1[35]);
        res = PackColor(r, g, b);
        break;
    case 3:
        r = FUN_00216de8(puVar1[36]);
        g = FUN_00216de8(puVar1[37]);
        b = FUN_00216de8(puVar1[38]);
        res = PackColor(r, g, b);
        break;
    case 4:
        r = FUN_00216de8(puVar1[39]);
        g = FUN_00216de8(puVar1[40]);
        b = FUN_00216de8(puVar1[41]);
        res = PackColor(r, g, b);
        break;
    }
    return res;
}
