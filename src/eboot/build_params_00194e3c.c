/* HSTMATCH module=EBOOT.BIN start=0x00194e3c end=0x00194f44 symbol=FUN_00194e3c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: f25/f24 are read into int locals before the out-struct is filled (retail loads them early into t0/a1). */
struct Sub {
    short f18, f1a, f1c, f1e, f20, f22;
    unsigned char f24, f25;
    char pad1[0x7c - 0xe];
    unsigned char f7c;
    char pad2[0x9c - 0x7d];
    unsigned char f9c, f9d, f9e;
    char pad3[288 - 0x18 - 0x9f];
};
struct Rec {
    char pad0[0x18];
    struct Sub s;
};

struct Out {
    int a, b, c, m1, m2, m3;
    char o0, o1, o2, o3;
};

extern struct Rec DAT_003417b8[];

extern void FUN_00204c88(void *ctx, char *p1, char *p2, char *p3, struct Out *o,
                         int a, int b, int c, int d, int e, int f);
extern void FUN_00092630(void *ctx, int x);

void FUN_00194e3c(void *ctx, int idx, int flags, int arg4)
{
    struct Sub *r = &DAT_003417b8[idx].s;
    struct Out out;
    int n;
    out.a = r->f18;
    int g25 = r->f25;
    int g24 = r->f24;
    out.b = r->f1a;
    out.c = r->f1c;
    out.m1 = 0x7fffffff;
    out.m2 = 0x7fffffff;
    out.m3 = 0x7fffffff;
    out.o1 = out.o2 = out.o3 = 0;
    if (!(flags & 8))
        out.m1 = r->f1e;
    if (!(flags & 0x10))
        out.m2 = r->f20;
    if (!(flags & 0x20))
        out.m3 = r->f22;
    n = 0;
    if (r->f7c == 2)
        n = 1;
    FUN_00204c88(ctx, (char *)&out.o2, (char *)&out.o3, (char *)&out.o1, &out,
                 r->f9c, r->f9d, n, g25, g24, arg4);
    FUN_00092630(ctx, r->f9e);
}
