/* HSTMATCH module=EBOOT.BIN start=0x000d4288 end=0x000d42fc symbol=FUN_000d4288 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the trailing `f40 = 0` is an inline `int n = f40; shrink(n, Alloc())` (unfolded lw/subu/sw, 16-byte allocator-temporary frame slot) and the 0 argument of FUN_000d5798 is an empty tag temporary; same recipe as ctor_clear_vec_000d3204; exact match verified; names and types await human review. */
struct Alloc {};
struct Tag {};
struct Self_000d4288 {
    int vptr;
    char pad4[0x38];
    int f3c, f40, f44, f48, f4c, f50;
    void shrink(int n, Alloc) { f40 -= n; }
};
extern "C" {
extern char DAT_00307468;
extern void FUN_0001f06c(void *);
extern void FUN_000d4430(void *);
extern void FUN_000d5798(void *, int, Tag);
}

extern "C" Self_000d4288 *FUN_000d4288(Self_000d4288 *p)
{
    FUN_0001f06c(p);
    p->vptr = (int)&DAT_00307468;
    p->f3c = 0;
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = 0;
    p->f4c = 0;
    p->f50 = 0;
    int n = p->f40;
    p->shrink(n, Alloc());
    FUN_000d5798(&p->f48, p->f4c, Tag());
    FUN_000d4430(p);
    return p;
}
