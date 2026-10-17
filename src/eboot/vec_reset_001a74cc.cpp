/* HSTMATCH module=EBOOT.BIN start=0x001a74cc end=0x001a7534 symbol=FUN_001a74cc lang=c++ */
/* Clone of src/eboot/vec_reset_000d9148.cpp (hstclone.py tag c23): addresses substituted; exact match verified; names and types await human review. */
/* Container reset to capacity n: clear the size (inline shrink with an empty allocator temporary), free
   and forget the old block, then reserve n through an inline wrapper that passes a by-value char flag
   (move v0,zero; andi; seb). The second argument is an unused empty allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_001a74cc {};
struct Flag_001a74cc { char v; Flag_001a74cc(char x) : v(x) {} };
struct Vec_001a74cc;
extern "C" void FUN_001a8a94(Vec_001a74cc *v, unsigned n, char f);
inline void Reserve2_001a74cc(Vec_001a74cc *v, unsigned n, Flag_001a74cc f) { FUN_001a8a94(v, n, f.v); }
inline void Reserve_001a74cc(Vec_001a74cc *v, unsigned n) { Reserve2_001a74cc(v, n, Flag_001a74cc(0)); }
struct Vec_001a74cc {
    int *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001a74cc) { size -= n; }
};
extern "C" void FUN_001a74cc(Vec_001a74cc *v, Alloc_001a74cc, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_001a74cc());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_001a74cc(v, n);
}
