/* HSTMATCH module=EBOOT.BIN start=0x00107034 end=0x00107130 symbol=FUN_00107034 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_00107034 {};
struct Elem_00107034 { int v; ~Elem_00107034() {} };
template <class T> inline void Swap_00107034(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00107034(Elem_00107034 *const &a, Elem_00107034 *const &b) { return b - a; }
struct V_00107034 {
    Elem_00107034 *data;
    int size;
    unsigned capacity;
    V_00107034() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_00107034) { size -= n; }
    ~V_00107034() { int n = size; shrink(n, Alloc_00107034()); delete data; }
};
extern "C" void FUN_00107ca0(V_00107034 *v, unsigned n, Alloc_00107034 a);
extern "C" void FUN_00107034(V_00107034 *v, unsigned n)
{
    V_00107034 buf;
    FUN_00107ca0(&buf, n, Alloc_00107034());
    Elem_00107034 *old = v->data;
    int count = Distance_00107034(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_00107034(v->capacity, buf.capacity);
    Swap_00107034(v->data, buf.data);
    Swap_00107034(v->size, buf.size);
}
