/* HSTMATCH module=EBOOT.BIN start=0x002919e4 end=0x00291a80 symbol=FUN_002919e4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-written from the disassembly; exact match verified. Names and types await human review. */
/* Matching idiom: a 12-byte `V3 v = *src;` local stages the record through sp+20..28 before the
   memberwise stores; the error case is the fall-through (`if (r < 0) { ... return 0; } return 1;`),
   and keeping the result in a local `r` leaves it in v0 for both the field store and the error call. */
struct V3 {
    float x, y, z;
};

struct Self {
    char pad0[4];
    int f4;         /* 0x04 */
    float fx;       /* 0x08 */
    float fy;       /* 0x0c */
    float fz;       /* 0x10 */
    int f14;        /* 0x14 */
    int f18;        /* 0x18 */
};

extern "C" {
    extern void LAB_002919d4();
    extern char DAT_002ffa04;
    extern int FUN_002b7920(int, void *, int, int, int, int);
    extern void FUN_0028fb44(void *, int);
}

extern "C" int FUN_002919e4(Self *p, int b, int c, const V3 *src, int e5, int e6, int e7)
{
    V3 v = *src;        /* 12-byte local -> the sp+20 float staging MWCC emits */
    p->f4 = c;
    p->fx = v.x;
    p->fy = v.y;
    p->fz = v.z;
    p->f18 = b;
    int r = FUN_002b7920(b, &LAB_002919d4, e5, e6, e7, 0);
    p->f14 = r;
    if (r < 0) {
        FUN_0028fb44(&DAT_002ffa04, r);
        return 0;
    }
    return 1;
}
