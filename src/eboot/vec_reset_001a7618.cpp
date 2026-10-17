/* HSTMATCH module=EBOOT.BIN start=0x001a7618 end=0x001a7680 symbol=FUN_001a7618 lang=c++ */
/* Clone of src/eboot/vec_reset_000d9148.cpp (hstclone.py tag c23): addresses substituted; exact match verified; names and types await human review. */
/* Container reset to capacity n: clear the size (inline shrink with an empty allocator temporary), free
   and forget the old block, then reserve n through an inline wrapper that passes a by-value char flag
   (move v0,zero; andi; seb). The second argument is an unused empty allocator. Names provisional. */
#pragma inline_depth(8)
struct Alloc_001a7618 {};
struct Flag_001a7618 { char v; Flag_001a7618(char x) : v(x) {} };
struct Vec_001a7618;
extern "C" void FUN_001a8b30(Vec_001a7618 *v, unsigned n, char f);
inline void Reserve2_001a7618(Vec_001a7618 *v, unsigned n, Flag_001a7618 f) { FUN_001a8b30(v, n, f.v); }
inline void Reserve_001a7618(Vec_001a7618 *v, unsigned n) { Reserve2_001a7618(v, n, Flag_001a7618(0)); }
struct Vec_001a7618 {
    int *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001a7618) { size -= n; }
};
extern "C" void FUN_001a7618(Vec_001a7618 *v, Alloc_001a7618, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_001a7618());
    if (v->data) {
        delete v->data;
        v->data = 0;
        v->capacity = 0;
    }
    Reserve_001a7618(v, n);
}
