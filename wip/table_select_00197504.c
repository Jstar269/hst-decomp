/* HSTMATCH module=EBOOT.BIN start=0x00197504 end=0x001975d4 symbol=FUN_00197504 lang=c99 */
extern float DAT_002c28e0[][4];
extern float DAT_002c28e4[][4];
extern float DAT_002c28e8[][4];
extern float DAT_002c29b0[][4];
extern float DAT_002c29b4[][4];
extern float DAT_002c29b8[][4];
extern void FUN_00043004(int, float *);
void FUN_00197504(int *param_1, unsigned int param_2)
{
    int idx = param_2 % 0xd;
    float c;
    float b;
    float a;
    float d;

    if (*(unsigned char *)((char *)param_1 + 0x88) != 0) {
        a = DAT_002c28e0[idx][0];
        b = DAT_002c28e4[idx][0];
        c = DAT_002c28e8[idx][0];
    } else {
        a = DAT_002c29b0[idx][0];
        b = DAT_002c29b4[idx][0];
        c = DAT_002c29b8[idx][0];
    }
    d = *(float *)((char *)param_1 + 0x1c);
    *(float *)((char *)param_1 + 0x10) = a;
    *(float *)((char *)param_1 + 0x14) = b;
    *(float *)((char *)param_1 + 0x18) = c;
    *(float *)((char *)param_1 + 0x1c) = d;
    *(float *)((char *)param_1 + 0x30) = a * *(float *)((char *)param_1 + 0x20);
    *(float *)((char *)param_1 + 0x34) = b * *(float *)((char *)param_1 + 0x24);
    *(float *)((char *)param_1 + 0x38) = c * *(float *)((char *)param_1 + 0x28);
    *(float *)((char *)param_1 + 0x3c) = d * *(float *)((char *)param_1 + 0x2c);
    FUN_00043004(param_1[0], (float *)((char *)param_1 + 0x30));
}
// near miss: 52/52 words, 2 differ: MWCC puts the divisor constant in v0 (`li v0,13; divu
// zero,a1,v0`) where retail uses v1 and then reuses v1 as the mfhi destination. Everything else,
// including the three separate `&DAT + idx*16` address computations, matches. Getting there needed
// three separate 2-D array symbols (`float DAT_x[][4]` at 0x2c28e0/4/8 and 0x2c29b0/4/8), the
// inverted guard (`if (b88 != 0) {28e0 table} else {29b0 table}` so the else body is laid out
// inline and the then body out of line), and the float temporaries DECLARED in reverse (c,b,a) so
// the loads colour f2/f3/f4 in retail's order. Ruled out: reading the flag byte first into a local
// (int, unsigned char or via a byte pointer), a named `n = 0xd` divisor, `13u`/`0x0d`/`(unsigned)13`,
// and computing `param_2 % 0xd` inline in each arm (55 words, layout changes).
// near miss from lane fm6 (unreviewed)
