/* HSTMATCH module=EBOOT.BIN start=0x0004f010 end=0x0004f130 symbol=FUN_0004f010 lang=c99 rodata=0x002cc3b0 */

extern char DAT_002d0a8c[];
extern char DAT_002d0a98[];
extern char DAT_002d0aa4[];
extern char DAT_002d0ac0[];
extern char DAT_002d0adc[];
extern char DAT_002d0af0[];
extern char DAT_002d0b14[];
extern char DAT_002d0b2c[];
extern char DAT_002d0b50[];
extern char DAT_002d0b74[];
extern char DAT_002d0b9c[];
extern char DAT_002d0bb8[];
extern char DAT_002d0bd0[];
extern char DAT_002d0be8[];
extern char DAT_002d0c00[];
extern char DAT_002d0c28[];

extern void FUN_0004ea98(const char *fmt, const char *file, int line, ...);

void FUN_0004f010(int param_1, int param_2, const char *param_3, int param_4, const char *param_5)
{
    const char *str = 0;
    switch (param_2) {
    case 0:  str = DAT_002d0a8c; break;
    case 1:  str = DAT_002d0a98; break;
    case 2:  str = DAT_002d0aa4; break;
    case 3:  str = DAT_002d0ac0; break;
    case 4:  str = DAT_002d0adc; break;
    case 5:  str = DAT_002d0af0; break;
    case 6:  str = DAT_002d0b14; break;
    case 7:  str = DAT_002d0b2c; break;
    case 8:  str = DAT_002d0b50; break;
    case 9:  str = DAT_002d0b74; break;
    case 10: str = DAT_002d0b9c; break;
    case 11: str = DAT_002d0bb8; break;
    case 12: str = DAT_002d0bd0; break;
    case 13: str = DAT_002d0be8; break;
    }

    if (str != 0) {
        FUN_0004ea98(DAT_002d0c00, param_3, param_4, str, param_5);
    } else {
        FUN_0004ea98(DAT_002d0c28, param_3, param_4, param_2, param_5);
    }
}

// NEAR MISS (72/72 words, 6 differ at +0x18..+0x2c; op1 lane 2026-10-21, converted from the Sharing twin wip/log_code_name_0004f864.c).
// The EBOOT twin needs the 5th argument: `FUN_0004ea98(fmt, param_3, param_4, str, param_5)` with param_5 arriving in t0.
// That unused argument pins t0, so MWCC puts the switch value in t2 and the result in t1 exactly like retail (without it the
// whole function shifts: param_2 in t1, result in t0, 40 words).
// Remaining: the jump-table dispatch registers. Retail `lui a0,0x2c; addiu a0,a0,-15440; sll v1,t2,2; addu v1,v1,a0; lw v1; jr v1`;
// ours `lui v1,0x2d; ...; sll v0,t2,2; addu v0,v0,v1; lw v0; jr v0` (table base v1, index v0).
// Ruled out here: `switch ((unsigned)param_2)`, a local `int sel = param_2; switch (sel)`, an explicit `default: str = 0;`
// (73 words, 71 off), and the Sharing variants noted below.
// near miss from lane op1 (unreviewed)
