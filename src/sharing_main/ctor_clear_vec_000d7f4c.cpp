/* HSTMATCH module=hstp_trans_main.prx start=0x000d7f4c end=0x000d7fc0 symbol=FUN_000d7f4c lang=c++ */
/* Clone of src/eboot/ctor_clear_vec_000d4288.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the trailing `f40 = 0` is an inline `int n = f40; shrink(n, Alloc())` (unfolded lw/subu/sw, 16-byte allocator-temporary frame slot) and the 0 argument of FUN_000d9488 is an empty tag temporary; same recipe as ctor_clear_vec_000d3204; exact match verified; names and types await human review. */
struct Alloc {};
struct Tag {};
struct Self_000d7f4c {
    int vptr;
    char pad4[0x38];
    int f3c, f40, f44, f48, f4c, f50;
    void shrink(int n, Alloc) { f40 -= n; }
};
extern "C" {
extern char DAT_003b0734;
extern void FUN_0001ec44(void *);
extern void FUN_000d80f4(void *);
extern void FUN_000d9488(void *, int, Tag);
}

extern "C" Self_000d7f4c *FUN_000d7f4c(Self_000d7f4c *p)
{
    FUN_0001ec44(p);
    p->vptr = (int)&DAT_003b0734;
    p->f3c = 0;
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = 0;
    p->f4c = 0;
    p->f50 = 0;
    int n = p->f40;
    p->shrink(n, Alloc());
    FUN_000d9488(&p->f48, p->f4c, Tag());
    FUN_000d80f4(p);
    return p;
}
