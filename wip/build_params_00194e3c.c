/* HSTMATCH module=EBOOT.BIN start=0x00194e3c end=0x00194f44 symbol=FUN_00194e3c lang=c99 */
// NEAR MISS (65/66 words, 55 differ, first at +0xc): frame, 11-argument call shape (5th-8th args in
// t0..t3 = &out, f9c, f9d, the f7c==2 flag; f25, f24, arg4 on the stack) and the out-struct layout
// (a@36,b@40,c@44,m1@48,m2@52,m3@56,o1@61,o2@62,o3@63) all match. The flag must be materialised
// (`n = 0; if (r->f7c == 2) n = 1;`) or MWCC emits xori+sltiu instead of retail's `li v0,2; bne;
// move t3,zero; li t3,1`. What remains is colouring/scheduling: retail keeps the record base in v1 (a
// temp) and, after `addiu s0,v1,24`, does every later load through s0 (6/8/10 = f1e..f22, 100 = f7c,
// 132..134 = f9c..f9e), while ours keeps the base in s0 for the whole function; retail also hoists the
// f25/f24 loads into t0/a1 before the branches. Ruled out: a separate short* local (same 55), the old
// pointer+stack-temp form (63/66, 57 differ).

struct Rec {
    char pad0[0x18];
    short f18, f1a, f1c, f1e, f20, f22;
    unsigned char f24, f25;
    char pad1[0x7c - 0x26];
    unsigned char f7c;
    char pad2[0x9c - 0x7d];
    unsigned char f9c, f9d, f9e;
    char pad3[288 - 0x9f];
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
    struct Rec *r = &DAT_003417b8[idx];
    struct Out out;
    int n;

    out.a = r->f18;
    out.b = r->f1a;
    out.c = r->f1c;
    out.m1 = out.m2 = out.m3 = 0x7fffffff;
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
                 r->f9c, r->f9d, n, r->f25, r->f24, arg4);
    FUN_00092630(ctx, r->f9e);
}
// near miss from lane ds1 (unreviewed)
