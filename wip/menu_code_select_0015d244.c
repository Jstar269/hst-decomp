/* HSTMATCH module=EBOOT.BIN start=0x0015d244 end=0x0015d3fc symbol=FUN_0015d244 lang=c99 */
extern char DAT_00340408;
extern int DAT_003386b0;
extern int DAT_00338b44;
extern int DAT_002dcc1c;

void FUN_0015d244(int param_1, int param_2)
{
    char *t;
    unsigned char ready;
    unsigned char alt;
    int code;

    DAT_00340408 = 0;
    ready = 0;
    alt = 0;
    if (DAT_003386b0 != 0) {
        t = *(char **)(DAT_003386b0 + 0xa0);
        if (t != 0) {
            if (*(int *)(t + 0x817c) == 1) {
                if (*(int *)(t + 0x8178) == 1)
                    ready = 1;
                else
                    ready = 0;
            } else
                ready = 0;
            if (*(unsigned char *)(t + 0x8198) == 0) {
                alt = 0;
            } else {
                if (*(unsigned char *)(t + 0x517) == 0)
                    alt = 0;
                else
                    alt = 1;
            }
        }
    }
    if (param_2 != 0) {
        DAT_002dcc1c = 0x1e;
        return;
    }
    if (alt) {
        DAT_002dcc1c = 0x1d;
        return;
    }
    if (ready) {
        int b = 0;
        if (DAT_00338b44 != 0)
            b = *(unsigned char *)(DAT_00338b44 + 0x45) == 0;
        if (param_1 == 0)
            code = 3;
        else if (param_1 == 0x31)
            code = b ? 0x2d : 0x2c;
        else if (param_1 == 0x2a)
            code = b ? 0x26 : 0x25;
        else
            code = 0x1e;
        DAT_002dcc1c = code;
        return;
    }
    if (param_1 == 0)
        code = 0x1e;
    else if (param_1 == 0x31)
        code = 0x2b;
    else if (param_1 == 0x2a)
        code = 0x20;
    else
        code = 0x1e;
    DAT_002dcc1c = code;
}
// near miss: 103/110 (7 short). Full logic recovered: the two global guards, ready = (f817c==1 &&
// f8178==1) with EXPLICIT if/else 0-1 assignments (expression forms collapse to sltu/xori and lose
// 20+ words), alt = (byte 0x8198 && byte 0x517) with 0x517 > 0x7fff reached through the char* base,
// then the param_2/alt/ready chain of DAT_002dcc1c codes (0x1e,0x1d,3,0x2d/0x2c,0x26/0x25,0x2b,0x20).
// Remaining deltas: retail materialises ready through v1 (`bnel v1,a2; move v1,zero; ...;
// andi v1,a2,0xff; andi t0,v1,0xff`) where ours assigns t0 directly from the compare; the first
// test is branch-LIKELY in retail (`bnel`), plain `bne` in ours; unsigned char vs int locals made
// no difference.
// near miss from lane fm8 (unreviewed)
