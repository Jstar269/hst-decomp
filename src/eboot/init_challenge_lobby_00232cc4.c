/* HSTMATCH module=EBOOT.BIN start=0x00232cc4 end=0x00232e2c symbol=FUN_00232cc4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: structured Obj/Inner, unified alloc/ctor idiom, loop typing; exact match verified; names and types await human review. */

extern char DAT_0030ebf4;
extern char DAT_002f3e24[];
extern char DAT_002f3e78[];
extern char DAT_002f3e94[];
extern char DAT_002f3eb0[];
extern void *DAT_0034a120;

extern void *FUN_00000bcc(unsigned int);
extern void FUN_000143b0(char *, const char *, ...);
extern void FUN_0001ca58(void *, const char *);
extern void FUN_0001cad0(void *, int, const char *);
extern void FUN_0001cb88(void *);
extern void *FUN_00050fc0(void *);
extern void FUN_000511c4(void *, const char *, int);
extern void FUN_00051398(void *, float);
extern void *FUN_002200d4(void *);
extern void *FUN_00220f00(void *);
extern void *FUN_0023167c(void *);
extern void FUN_002afb80(void *, int);
extern void FUN_002afce0(int);

typedef struct {
    void *p0;
    void *p1;
    void *p2;
} Obj;

typedef struct {
    char pad[0x1a8];
    void *items[10];
} Inner;

void FUN_00232cc4(Obj *param_1)
{
    char buf[256];
    void *p0;
    void *p1;
    void *p2;
    Inner *s0;
    int s1;
    void *item;

    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002f3e78);

    p0 = FUN_00000bcc(752);
    if (p0)
        p0 = FUN_0023167c(p0);
    param_1->p0 = p0;

    p1 = FUN_00000bcc(120);
    if (p1)
        p1 = FUN_002200d4(p1);
    param_1->p1 = p1;

    p2 = FUN_00000bcc(160);
    if (p2)
        p2 = FUN_00220f00(p2);
    param_1->p2 = p2;

    FUN_0001cb88(&DAT_0030ebf4);
    FUN_0001ca58(&DAT_0030ebf4, DAT_002f3e94);

    s0 = (Inner *)param_1->p0;
    for (s1 = 0; s1 < 10; s1++) {
        FUN_000143b0(buf, DAT_002f3e24, s1 + 1);
        item = FUN_00000bcc(72);
        if (item)
            item = FUN_00050fc0(item);
        s0->items[s1] = item;
        FUN_000511c4(item, buf, 0);
        FUN_00051398(s0->items[s1], 1100.0f);
    }

    FUN_0001cb88(&DAT_0030ebf4);
    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002f3eb0);
    FUN_002afb80(DAT_0034a120, 0);
    FUN_002afce0(1);
    FUN_0001cb88(&DAT_0030ebf4);
}
