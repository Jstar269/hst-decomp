/* HSTMATCH module=EBOOT.BIN start=0x0005aff8 end=0x0005b0ec symbol=FUN_0005aff8 lang=c++ */
/* Clone of src/sharing_main/vec_reserve_move_0005bc80.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (twin of src/eboot/vec_reserve_member_00050dd8.cpp, here with the out-of-line destructor 0x5c10c and the empty tag temporaries of the sibling vec_append_0005bd74.cpp); exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n, move the old elements into it, clear the old
   storage, swap, and let the temporary's destructor (0x5c10c, called out of line) free the old block.
   Matching idiom: the empty tag arguments E_0005aff8 of the inline Move/Clear helpers (and of the out-of-line
   reserve) reserve the retail frame slots; distance() takes its iterators by const reference, which keeps
   end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct E_0005aff8 {};
struct Elem_0005b484 { int v; ~Elem_0005b484() {} };
template <class T> inline void Swap_0005aff8(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0005aff8(Elem_0005b484 *const &a, Elem_0005b484 *const &b) { return b - a; }
class V_0005b484 {
public:
    Elem_0005b484 *data;
    int size;
    unsigned capacity;
    V_0005b484() : data(0), size(0), capacity(0) {}
    ~V_0005b484();
};
inline void Move_0005aff8(Elem_0005b484 *dst, Elem_0005b484 *src, unsigned bytes, E_0005aff8) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
inline void Clear_0005aff8(V_0005b484 *v, E_0005aff8) { v->size = 0; }
extern "C" void FUN_0005b400(V_0005b484 *v, unsigned n, E_0005aff8 a);
extern "C" void FUN_0005aff8(V_0005b484 *v, unsigned n)
{
    V_0005b484 buf;
    FUN_0005b400(&buf, n, E_0005aff8());
    Elem_0005b484 *old = v->data;
    int count = Distance_0005aff8(old, old + v->size);
    Move_0005aff8(buf.data + buf.size, old, count * 4, E_0005aff8());
    buf.size += count;
    Clear_0005aff8(v, E_0005aff8());
    Swap_0005aff8(v->capacity, buf.capacity);
    Swap_0005aff8(v->data, buf.data);
    Swap_0005aff8(v->size, buf.size);
}
