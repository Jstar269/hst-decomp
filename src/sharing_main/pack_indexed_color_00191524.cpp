/* HSTMATCH module=hstp_trans_main.prx start=0x00191524 end=0x001916f8 symbol=FUN_00191524 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: switch statement on index 0..4 and right-nested bitwise-OR color packing helper; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern int *FUN_00177eb4();
extern int FUN_00225dec(int);
}

static inline u32 PackColor(u16 r, u16 g, u16 b)
{
    return (r & 0xff) | (((g & 0xff) << 8) | (((b & 0xff) << 16) | 0x80000000));
}

extern "C" u32 FUN_00191524(int param_1, int param_2)
{
    int *puVar1 = FUN_00177eb4();
    u32 res = 0;
    u16 r, g, b;
    switch (param_2) {
    case 0:
        r = FUN_00225dec(puVar1[27]);
        g = FUN_00225dec(puVar1[28]);
        b = FUN_00225dec(puVar1[29]);
        res = PackColor(r, g, b);
        break;
    case 1:
        r = FUN_00225dec(puVar1[30]);
        g = FUN_00225dec(puVar1[31]);
        b = FUN_00225dec(puVar1[32]);
        res = PackColor(r, g, b);
        break;
    case 2:
        r = FUN_00225dec(puVar1[33]);
        g = FUN_00225dec(puVar1[34]);
        b = FUN_00225dec(puVar1[35]);
        res = PackColor(r, g, b);
        break;
    case 3:
        r = FUN_00225dec(puVar1[36]);
        g = FUN_00225dec(puVar1[37]);
        b = FUN_00225dec(puVar1[38]);
        res = PackColor(r, g, b);
        break;
    case 4:
        r = FUN_00225dec(puVar1[39]);
        g = FUN_00225dec(puVar1[40]);
        b = FUN_00225dec(puVar1[41]);
        res = PackColor(r, g, b);
        break;
    }
    return res;
}
