/* HSTMATCH module=hstp_trans_main.prx start=0x001b4a98 end=0x001b4b00 symbol=FUN_001b4a98 lang=c++ */
/* Clone of src/eboot/vec_reset_000d9148.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reset to capacity n: clear the size (inline shrink with an empty allocator temporary), free
   and forget the old block, then reserve n through an inline wrapper that passes a by-value char flag
   (move v0,zero; andi; seb). The second argument is an unused empty allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_001b4a98 {};
struct Flag_001b4a98 { char v; Flag_001b4a98(char x) : v(x) {} };
struct Vec_001b4a98;
extern "C" void FUN_001b6060(Vec_001b4a98 *v, unsigned n, char f);
inline void Reserve2_001b4a98(Vec_001b4a98 *v, unsigned n, Flag_001b4a98 f) { FUN_001b6060(v, n, f.v); }
inline void Reserve_001b4a98(Vec_001b4a98 *v, unsigned n) { Reserve2_001b4a98(v, n, Flag_001b4a98(0)); }
struct Vec_001b4a98 {
    int *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001b4a98) { size -= n; }
};
extern "C" void FUN_001b4a98(Vec_001b4a98 *v, Alloc_001b4a98, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_001b4a98());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_001b4a98(v, n);
}
