/* HSTMATCH module=EBOOT.BIN start=0x000d9148 end=0x000d91b0 symbol=FUN_000d9148 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reset to capacity n: clear the size (inline shrink with an empty allocator temporary), free
   and forget the old block, then reserve n through an inline wrapper that passes a by-value char flag
   (move v0,zero; andi; seb). The second argument is an unused empty allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_000d9148 {};
struct Flag_000d9148 { char v; Flag_000d9148(char x) : v(x) {} };
struct Vec_000d9148;
extern "C" void FUN_000d9220(Vec_000d9148 *v, unsigned n, char f);
inline void Reserve2_000d9148(Vec_000d9148 *v, unsigned n, Flag_000d9148 f) { FUN_000d9220(v, n, f.v); }
inline void Reserve_000d9148(Vec_000d9148 *v, unsigned n) { Reserve2_000d9148(v, n, Flag_000d9148(0)); }
struct Vec_000d9148 {
    int *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_000d9148) { size -= n; }
};
extern "C" void FUN_000d9148(Vec_000d9148 *v, Alloc_000d9148, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_000d9148());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_000d9148(v, n);
}
