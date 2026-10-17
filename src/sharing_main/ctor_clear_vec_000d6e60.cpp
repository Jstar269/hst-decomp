/* HSTMATCH module=hstp_trans_main.prx start=0x000d6e60 end=0x000d6ef4 symbol=FUN_000d6e60 lang=c++ */
/* Clone of src/eboot/ctor_clear_vec_000d3204.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the trailing `f40 = 0` is an inline `int n = f40; shrink(n, Alloc())` (unfolded lw/subu/sw, 16-byte allocator-temporary frame slot) and the 0 argument of FUN_000d933c is an empty tag temporary; exact match verified; names and types await human review. */
struct Alloc {};
struct Tag {};
struct Self_000d6e60 {
    int vptr;
    char pad4[0x38];
    int f3c, f40, f44, f48, f4c, f50;
    void shrink(int n, Alloc) { f40 -= n; }
};
extern "C" {
extern char DAT_003b0750;
extern void FUN_000007f4(void *, void *, void *, int, int);
extern void FUN_0001ec44(void *);
extern void FUN_000d7070(void *);
extern void FUN_000d933c(void *, int, Tag);
extern void FUN_000577ec();
extern void FUN_00057904();
}

extern "C" Self_000d6e60 *FUN_000d6e60(Self_000d6e60 *p)
{
    FUN_0001ec44(p);
    p->vptr = (int)&DAT_003b0750;
    p->f3c = 0;
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = 0;
    p->f4c = 0;
    p->f50 = 0;
    FUN_000007f4((char *)p + 0xe0, (void *)FUN_000577ec, (void *)FUN_00057904, 0x1b0, 4);
    int n = p->f40;
    p->shrink(n, Alloc());
    FUN_000d933c(&p->f48, p->f4c, Tag());
    FUN_000d7070(p);
    return p;
}
