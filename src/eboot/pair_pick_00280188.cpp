/* HSTMATCH module=EBOOT.BIN start=0x00280188 end=0x002803d8 symbol=FUN_00280188 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// matching idioms: empty `Tag` by-value third argument of FUN_000545bc (retail `move v0,zero; seb a2,v0`); `i++` placed before the re-read of the element count (while loop) so it lands in the jal delay slot; trailing unused empty `False` parameter for the 80-byte frame.

struct False_280188 {};
struct Tag_280188 {};

struct Vec_280188 {
    int *p;            /* 0x00 */
    unsigned size;     /* 0x04 */
    unsigned cap;      /* 0x08 */
};

extern "C" {
extern char DAT_002fe8cc[];
extern void FUN_00286490(struct Vec_280188 *v, int n);
extern int FUN_000650e0(int obj);
extern int FUN_00065104(int obj, int idx, int sub);
extern int FUN_0006517c(int obj, int idx, int sub);
extern void FUN_002803d8(char *fmt, ...);
extern void FUN_000545bc(struct Vec_280188 *v, int *val, Tag_280188 flag);
extern void FUN_00054600(struct Vec_280188 *v, int flag);
extern unsigned FUN_0001342c(void);
extern unsigned char FUN_0000d62c(int v);
}

extern "C" int FUN_00280188(int *obj, unsigned char *out, int want, int sub, False_280188)
{
    struct Vec_280188 a;
    struct Vec_280188 b;
    int i, n;
    int v, w, res;
    unsigned cnt, r;

    a.p = 0;
    a.size = 0;
    a.cap = 0;
    b.p = 0;
    b.size = 0;
    b.cap = 0;
    if (a.cap < 0x20)
        FUN_00286490(&a, 0x20);
    if (b.cap < 0x20)
        FUN_00286490(&b, 0x20);

    i = 0;
    n = FUN_000650e0(*obj);
    while (i < n) {
        FUN_002803d8(DAT_002fe8cc, FUN_00065104(*obj, i, 0),
                     FUN_0006517c(*obj, i, sub + 2));
        if (want == FUN_00065104(*obj, i, 0)) {
            v = FUN_0006517c(*obj, i, sub + 2);
            if (a.size < a.cap) {
                a.size = a.size + 1;
                *(int *)((char *)a.p + a.size * 4 - 4) = v;
            } else {
                FUN_000545bc(&a, &v, Tag_280188());
            }
            w = FUN_0006517c(*obj, i, 1);
            if (b.size < b.cap) {
                b.size = b.size + 1;
                *(int *)((char *)b.p + b.size * 4 - 4) = w;
            } else {
                FUN_000545bc(&b, &w, Tag_280188());
            }
        }
        i++;
        n = FUN_000650e0(*obj);
    }

    cnt = a.size;
    if (cnt == 0 || b.size == 0) {
        FUN_00054600(&b, 0);
        FUN_00054600(&a, 0);
        return 0;
    }
    {
        r = FUN_0001342c() % cnt;
        *out = FUN_0000d62c(b.p[r] + 5);
        res = a.p[r];
        FUN_00054600(&b, 0);
        FUN_00054600(&a, 0);
        return res;
    }
}
