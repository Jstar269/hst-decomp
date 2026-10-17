/* HSTMATCH module=hstp_trans_main.prx start=0x0024b84c end=0x0024b8b4 symbol=FUN_0024b84c lang=c++ */
/* Clone of src/eboot/vec_reset_000d9148.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reset to capacity n: clear the size (inline shrink with an empty allocator temporary), free
   and forget the old block, then reserve n through an inline wrapper that passes a by-value char flag
   (move v0,zero; andi; seb). The second argument is an unused empty allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_0024b84c {};
struct Flag_0024b84c { char v; Flag_0024b84c(char x) : v(x) {} };
struct Vec_0024b84c;
extern "C" void FUN_0024b8b4(Vec_0024b84c *v, unsigned n, char f);
inline void Reserve2_0024b84c(Vec_0024b84c *v, unsigned n, Flag_0024b84c f) { FUN_0024b8b4(v, n, f.v); }
inline void Reserve_0024b84c(Vec_0024b84c *v, unsigned n) { Reserve2_0024b84c(v, n, Flag_0024b84c(0)); }
struct Vec_0024b84c {
    int *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0024b84c) { size -= n; }
};
extern "C" void FUN_0024b84c(Vec_0024b84c *v, Alloc_0024b84c, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_0024b84c());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_0024b84c(v, n);
}
