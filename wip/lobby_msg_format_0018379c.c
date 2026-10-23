/* HSTMATCH module=EBOOT.BIN start=0x0018379c end=0x00183954 symbol=FUN_0018379c lang=c99 */
extern char DAT_002e082c[];
extern char DAT_002e097c[];
extern int FUN_001fea10(int, int, int);
extern int FUN_001fec00(int);
extern int FUN_0016bc70(void);
extern int FUN_00014a40(int);
extern int FUN_00000a90(int);
extern void FUN_000149a8(int, char *);
extern void FUN_000143b0(char *, char *, ...);
extern void FUN_00110a78(int, char *, int);
extern int FUN_00014934(int, char *);
extern void FUN_000009e4(int);

void FUN_0018379c(int param_1, int param_2, int param_3, int param_4)
{
    char *s;
    int c;
    int b;
    int a;

    if (param_4 != 0) {
        int *q = (int *)FUN_0016bc70();
        if (*(unsigned char *)((char *)q + 0x43) != 0)
            a = FUN_001fea10(0x12, 0x1a, 1);
        else
            a = FUN_001fea10(0x12, 0x18, 0);
    } else {
        a = FUN_001fea10(0x12, 0x18, 3);
    }
    b = FUN_001fea10(0xd, 0, param_2);
    c = FUN_001fec00(param_2);
    FUN_00014a40((int)DAT_002e082c);
    FUN_00014a40(b);
    FUN_00014a40(a);
    FUN_00014a40(c);
    s = (char *)FUN_00000a90(0x800);
    FUN_000149a8((int)s, (char *)(param_1 + 0x1744));
    if (param_3 == 0) {
        FUN_000143b0((char *)(param_1 + 0x1744), DAT_002e097c, b, DAT_002e082c, c, DAT_002e082c, a);
        FUN_00110a78(*(int *)(param_1 + 4), (char *)(param_1 + 0x1744), 1);
    } else {
        FUN_000143b0((char *)(param_1 + 0x1744), DAT_002e097c, a, DAT_002e082c, b, DAT_002e082c, c);
        if (FUN_00014934((int)s, (char *)(param_1 + 0x1744)) == 0)
            FUN_00110a78(*(int *)(param_1 + 4), (char *)(param_1 + 0x1744), 0);
        else
            FUN_00110a78(*(int *)(param_1 + 4), (char *)(param_1 + 0x1744), 1);
    }
    if (s != 0)
        FUN_000009e4((int)s);
}
// near miss: 110/110 words, 55 differing -- ALL of them downstream of the parameter->s-register
// map. Retail: param_1=s5, param_3=s4, a=s3, b=s2, c=s1, param_2=s0 (param_2 dies at the buffer
// alloc and its register is reused for the 0x800-byte buffer). Ours: param_1=s1, param_2=s3,
// param_3=s0, a/b/c below. Body is word-for-word retail's otherwise: the param_4==0 arm must be
// written LAST (`if (param_4 != 0) {...} else {a = ...3;}`) to get `beqz a3` to the out-of-line 3
// arm; the inner byte test needs `if (byte != 0) a = (0x12,0x1a,1); else a = (0x12,0x18,0);` for
// retail's beqzl polarity; the buffer address must stay inline (`(char *)(param_1 + 0x1744)`)
// rather than a local, which is what drops the 7th saved register.
// Ruled out: local declaration orders a,b,c,s and s,c,b,a (only changed param_2/param_3).
// near miss from lane fm8 (unreviewed)
