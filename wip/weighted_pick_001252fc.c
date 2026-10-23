/* HSTMATCH module=EBOOT.BIN start=0x001252fc end=0x00125514 symbol=FUN_001252fc lang=c99 */
extern int FUN_00131b54(int, int, int);
extern int FUN_001318dc(int, int);
extern int DAT_00340284;
extern int DAT_00310fc8;
extern unsigned char DAT_0033b584[];

int FUN_001252fc(int param_1, int param_2)
{
    unsigned char a[64];
    unsigned char b[64];
    unsigned char *e;
    unsigned char *q;
    int *pa;
    int *pb;
    short key;
    int cnt;
    int total;
    int i;
    int n;
    int r;
    int v;

    key = *(short *)(DAT_0033b584 + param_2 * 0x58 + 0x44);
    cnt = *(int *)(DAT_0033b584 + param_2 * 0x58 + 0x40);
    q = b;
    n = 64;
    if (q != 0) {
        do {
            *q++ = 0;
        } while (--n);
    }
    q = a;
    n = 64;
    if (q != 0) {
        do {
            *q++ = 0;
        } while (--n);
    }
    i = 0;
    total = 0;
    e = DAT_0033b584;
    pa = (int *)b;
    pb = (int *)a;
    do {
        if (e != 0 && *(short *)(e + 0x44) == key &&
            FUN_00131b54(DAT_00340284, (char)e[0x51], *(int *)(e + 0x38)) != 0 &&
            FUN_00131b54(DAT_00340284, (char)e[0x52], *(int *)(e + 0x3c)) != 0 &&
            (e[0x53] == 0 || FUN_001318dc(DAT_00340284, (char)e[0x4a]) == 0)) {
            v = *(int *)(DAT_0033b584 + i * 0x58 + 0x34);
            *pa = i;
            pa++;
            *pb = v;
            total = total + v;
            pb++;
        }
        i++;
        e = e + 0x58;
    } while (i < 0xe0);
    if (total < 1)
        return -1;
    DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
    r = (int)((DAT_00310fc8 & 0x7fffffff) >> 0x10) % total;
    i = 0;
    if (cnt > 0) {
        pb = (int *)a;
        do {
            if (r < *pb)
                return *(int *)(b + i * 4);
            r = r - *pb;
            i++;
            pb++;
        } while (i < cnt);
    }
    return param_2;
}

// 130/134 words, one extra callee-saved register (s8 for idx). Retail: key=s6,
// cnt=s0, idx=s7 (reused for the return value), total=s5, i=s4, e=s3, pa=s2, pb=s1.
// Here cnt takes s6 and idx needs s8. The two 64-byte zero loops and the 224-entry
// collection loop are otherwise the same shape (do/while with --n, beqz null guard);
// retail zeroes sp+112 first. Ruled out: swapping the array declarations and the
// zero order (sp+48 is still zeroed first - the slots follow first use, not
// declaration), declaring cnt before key.
// near miss from lane fm8 (unreviewed)
