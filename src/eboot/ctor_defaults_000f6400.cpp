/* HSTMATCH module=EBOOT.BIN start=0x000f6400 end=0x000f64d8 symbol=FUN_000f6400 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: each container is cleared by an inline `int n = size; shrink(n, Alloc());` (unfolded lw/subu/sw, 16-byte allocator-temporary frame slot) after its fields were zeroed, as in 0xd3204. */
struct Alloc {};
struct Buf4 {
    int w0, w4, size, w12;
    void shrink(int n, Alloc) { size -= n; }
};
struct Vec3 {
    int w0, size, w8;
    void shrink(int n, Alloc) { size -= n; }
};
struct Self {
    Buf4 a;
    int f10;
    char pad14[0x830 - 0x14];
    Vec3 b;
    float f83c, f840, f844, f848, f84c, f850, f854, f858;
    int f85c;
    float f860, f864, f868, f86c;
    unsigned char f870;
};
extern "C" {
extern float DAT_002d6ca0;
void FUN_000f6b0c(Self *, int);
}

extern "C" Self *FUN_000f6400(Self *p)
{
    p->a.w0 = 0;
    p->a.w4 = 0;
    p->a.size = 0;
    p->a.w12 = 0;
    p->b.w0 = 0;
    p->b.size = 0;
    p->b.w8 = 0;
    int n = p->a.size;
    p->a.shrink(n, Alloc());
    n = p->b.size;
    p->b.shrink(n, Alloc());
    FUN_000f6b0c(p, 0);
    p->f10 = (int)DAT_002d6ca0;
    p->f83c = 20.0f;
    p->f840 = 5.0f;
    p->f844 = 5.0f;
    p->f848 = 0.6f;
    p->f84c = 2.0f;
    p->f850 = 1.0f;
    p->f854 = 5.0f;
    p->f858 = 10.0f;
    p->f85c = 1;
    p->f860 = 512.0f;
    p->f864 = 128.0f;
    p->f868 = 64.0f;
    p->f86c = 64.0f;
    p->f870 = 1;
    return p;
}
