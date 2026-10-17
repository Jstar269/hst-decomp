/* HSTMATCH module=hstp_trans_main.prx start=0x000516ec end=0x000517e8 symbol=FUN_000516ec lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x4): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_000516ec {};
struct Elem_000516ec { int v; ~Elem_000516ec() {} };
template <class T> inline void Swap_000516ec(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000516ec(Elem_000516ec *const &a, Elem_000516ec *const &b) { return b - a; }
struct V_000516ec {
    Elem_000516ec *data;
    int size;
    unsigned capacity;
    V_000516ec() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_000516ec) { size -= n; }
    ~V_000516ec() { int n = size; shrink(n, Alloc_000516ec()); delete data; }
};
extern "C" void FUN_00051850(V_000516ec *v, unsigned n, Alloc_000516ec a);
extern "C" void FUN_000516ec(V_000516ec *v, unsigned n)
{
    V_000516ec buf;
    FUN_00051850(&buf, n, Alloc_000516ec());
    Elem_000516ec *old = v->data;
    int count = Distance_000516ec(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_000516ec(v->capacity, buf.capacity);
    Swap_000516ec(v->data, buf.data);
    Swap_000516ec(v->size, buf.size);
}
