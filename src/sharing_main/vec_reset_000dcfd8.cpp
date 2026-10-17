/* HSTMATCH module=hstp_trans_main.prx start=0x000dcfd8 end=0x000dd040 symbol=FUN_000dcfd8 lang=c++ */
/* Clone of src/eboot/vec_reset_000d9148.cpp (hstclone.py tag x19): addresses substituted; exact match verified; names and types await human review. */
/* Container reset to capacity n: clear the size (inline shrink with an empty allocator temporary), free
   and forget the old block, then reserve n through an inline wrapper that passes a by-value char flag
   (move v0,zero; andi; seb). The second argument is an unused empty allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_000dcfd8 {};
struct Flag_000dcfd8 { char v; Flag_000dcfd8(char x) : v(x) {} };
struct Vec_000dcfd8;
extern "C" void FUN_000dd0b0(Vec_000dcfd8 *v, unsigned n, char f);
inline void Reserve2_000dcfd8(Vec_000dcfd8 *v, unsigned n, Flag_000dcfd8 f) { FUN_000dd0b0(v, n, f.v); }
inline void Reserve_000dcfd8(Vec_000dcfd8 *v, unsigned n) { Reserve2_000dcfd8(v, n, Flag_000dcfd8(0)); }
struct Vec_000dcfd8 {
    int *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_000dcfd8) { size -= n; }
};
extern "C" void FUN_000dcfd8(Vec_000dcfd8 *v, Alloc_000dcfd8, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_000dcfd8());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_000dcfd8(v, n);
}
