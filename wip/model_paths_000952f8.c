/* HSTMATCH module=EBOOT.BIN start=0x000952f8 end=0x0009547c symbol=FUN_000952f8 lang=c99 rodata=0x002ceb60 */
extern char DAT_002d2b04[];
extern char DAT_002d2b1c[];
extern char DAT_002d2b24[];
extern char DAT_002d2b3c[];
extern char DAT_002d2ae4[];
extern char DAT_002d2afc[];
extern char DAT_002d2b44[];
extern char DAT_002d2b5c[];
extern char DAT_002d2b60[];
extern char DAT_002d2b7c[];
extern char DAT_002d2b84[];
extern char DAT_002d2b8c[];
extern char DAT_002d2bac[];
extern char DAT_002d2bcc[];
extern char DAT_002d2be8[];
extern void FUN_000143b0(int, char *, ...);

void FUN_000952f8(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    char *a;
    char *b;

    switch (param_1) {
    case 0:
        a = DAT_002d2b04;
        b = DAT_002d2b1c;
        break;
    case 1:
        a = DAT_002d2b24;
        b = DAT_002d2b3c;
        break;
    case 2:
        a = DAT_002d2ae4;
        b = DAT_002d2afc;
        break;
    case 3:
        a = DAT_002d2b44;
        b = DAT_002d2b5c;
        break;
    case 4:
        a = DAT_002d2b44;
        b = DAT_002d2b5c;
        break;
    case 5:
        a = DAT_002d2b60;
        b = DAT_002d2b7c;
        break;
    }
    FUN_000143b0(param_4, DAT_002d2b84, a, param_2);
    if (param_5 != 0) {
        if (param_1 == 4 || param_1 == 3)
            a = DAT_002d2bcc;
        else if (param_1 == 1)
            a = DAT_002d2bac;
        else if (param_1 == 2)
            a = DAT_002d2b8c;
    }
    FUN_000143b0(param_3, DAT_002d2be8, a, param_2, b, param_2);
}
// near miss: 91/97 words. Full switch recovered (cases 0-5 with the 0x2ceb60 jump table, 3 and 4
// sharing the "etc" pair) plus both FUN_000143b0 calls; the second call is varargs -- "(dst,
// fmt, a, param_2, b, param_2)" i.e. four varargs after the format. Deltas: register roles are
// shifted (retail s4/s3/s2/s5 = param_1/2/3/5 with a->s1, b->s0; ours s3/s2/s1/s0), so the
// prologue saves and every use differ, and ours is 6 words short around the switch dispatch.
// near miss from lane fm6 (unreviewed)
