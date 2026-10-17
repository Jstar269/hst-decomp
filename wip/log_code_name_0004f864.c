/* HSTMATCH module=hstp_trans_main.prx start=0x0004f864 end=0x0004f984 symbol=FUN_0004f864 lang=c99 rodata=0x002cc200 */

extern char DAT_00376548[];
extern char DAT_00376554[];
extern char DAT_00376560[];
extern char DAT_0037657c[];
extern char DAT_00376598[];
extern char DAT_003765ac[];
extern char DAT_003765d0[];
extern char DAT_003765e8[];
extern char DAT_0037660c[];
extern char DAT_00376630[];
extern char DAT_00376658[];
extern char DAT_00376674[];
extern char DAT_0037668c[];
extern char DAT_003766a4[];
extern char DAT_003766bc[];
extern char DAT_003766e4[];

extern void FUN_0004efe0(const char *fmt, const char *file, int line, ...);

void FUN_0004f864(int param_1, int param_2, const char *param_3, int param_4, const char *param_5)
{
    const char *str = 0;
    switch (param_2) {
    case 0:  str = DAT_00376548; break;
    case 1:  str = DAT_00376554; break;
    case 2:  str = DAT_00376560; break;
    case 3:  str = DAT_0037657c; break;
    case 4:  str = DAT_00376598; break;
    case 5:  str = DAT_003765ac; break;
    case 6:  str = DAT_003765d0; break;
    case 7:  str = DAT_003765e8; break;
    case 8:  str = DAT_0037660c; break;
    case 9:  str = DAT_00376630; break;
    case 10: str = DAT_00376658; break;
    case 11: str = DAT_00376674; break;
    case 12: str = DAT_0037668c; break;
    case 13: str = DAT_003766a4; break;
    }

    if (str != 0) {
        FUN_0004efe0(DAT_003766bc, param_3, param_4, str, param_5);
    } else {
        FUN_0004efe0(DAT_003766e4, param_3, param_4, param_2, param_5);
    }
}

// NEAR MISS: 6 of 72 words differ (+0x18 to +0x2c).
// Differs only in temporary register choice for the switch jump table address calculation:
// Retail loads the rodata table address into a0 and uses v1 for offset and jump:
//   4f87c: lui   a0, 0x2d
//   4f880: addiu a0, a0, -15872
//   4f884: sll   v1, t2, 0x2
//   4f888: addu  v1, v1, a0
//   4f88c: lw    v1, 0(v1)
//   4f890: jr    v1
// Whereas MWCC uses v1 for table base and v0 for offset and jump:
//   4f87c: lui   v1, 0x2d
//   4f880: addiu v1, v1, -15872
//   4f884: sll   v0, t2, 0x2
//   4f888: addu  v0, v0, v1
//   4f88c: lw    v0, 0(v0)
//   4f890: jr    v0
// All 14 switch cases (28 words), argument setup, branch-likely delay slot duplication,
// and function epilogue match exactly.
// Passing param_5 in t0 confirmed from caller 0x0004fa2c and format string specifiers "%s, %s".
// near miss from lane u1r2-3 (unreviewed)
