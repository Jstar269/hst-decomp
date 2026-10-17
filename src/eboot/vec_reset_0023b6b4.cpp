/* HSTMATCH module=EBOOT.BIN start=0x0023b6b4 end=0x0023b71c symbol=FUN_0023b6b4 lang=c++ */
/* Clone of src/eboot/vec_reset_000d9148.cpp (hstclone.py tag c23): addresses substituted; exact match verified; names and types await human review. */
/* Container reset to capacity n: clear the size (inline shrink with an empty allocator temporary), free
   and forget the old block, then reserve n through an inline wrapper that passes a by-value char flag
   (move v0,zero; andi; seb). The second argument is an unused empty allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_0023b6b4 {};
struct Flag_0023b6b4 { char v; Flag_0023b6b4(char x) : v(x) {} };
struct Vec_0023b6b4;
extern "C" void FUN_0023b71c(Vec_0023b6b4 *v, unsigned n, char f);
inline void Reserve2_0023b6b4(Vec_0023b6b4 *v, unsigned n, Flag_0023b6b4 f) { FUN_0023b71c(v, n, f.v); }
inline void Reserve_0023b6b4(Vec_0023b6b4 *v, unsigned n) { Reserve2_0023b6b4(v, n, Flag_0023b6b4(0)); }
struct Vec_0023b6b4 {
    int *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0023b6b4) { size -= n; }
};
extern "C" void FUN_0023b6b4(Vec_0023b6b4 *v, Alloc_0023b6b4, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_0023b6b4());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_0023b6b4(v, n);
}
