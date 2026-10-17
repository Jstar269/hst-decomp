/* HSTMATCH module=EBOOT.BIN start=0x000d3204 end=0x000d3298 symbol=FUN_000d3204 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the trailing `f40 = 0` is an inline `int n = f40; shrink(n, Alloc())` (unfolded lw/subu/sw, 16-byte allocator-temporary frame slot) and the 0 argument of FUN_000d564c is an empty tag temporary; exact match verified; names and types await human review. */
struct Alloc {};
struct Tag {};
struct Self_000d3204 {
    int vptr;
    char pad4[0x38];
    int f3c, f40, f44, f48, f4c, f50;
    void shrink(int n, Alloc) { f40 -= n; }
};
extern "C" {
extern char DAT_00307484;
extern void FUN_000007f4(void *, void *, void *, int, int);
extern void FUN_0001f06c(void *);
extern void FUN_000d3414(void *);
extern void FUN_000d564c(void *, int, Tag);
extern void FUN_00056b98();
extern void FUN_00056cb0();
}

extern "C" Self_000d3204 *FUN_000d3204(Self_000d3204 *p)
{
    FUN_0001f06c(p);
    p->vptr = (int)&DAT_00307484;
    p->f3c = 0;
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = 0;
    p->f4c = 0;
    p->f50 = 0;
    FUN_000007f4((char *)p + 0xe0, (void *)FUN_00056b98, (void *)FUN_00056cb0, 0x1b0, 4);
    int n = p->f40;
    p->shrink(n, Alloc());
    FUN_000d564c(&p->f48, p->f4c, Tag());
    FUN_000d3414(p);
    return p;
}
