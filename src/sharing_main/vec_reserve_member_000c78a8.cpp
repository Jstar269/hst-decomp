/* HSTMATCH module=hstp_trans_main.prx start=0x000c78a8 end=0x000c79a4 symbol=FUN_000c78a8 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x4): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_000c78a8 {};
struct Elem_000c78a8 { int v; ~Elem_000c78a8() {} };
template <class T> inline void Swap_000c78a8(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000c78a8(Elem_000c78a8 *const &a, Elem_000c78a8 *const &b) { return b - a; }
struct V_000c78a8 {
    Elem_000c78a8 *data;
    int size;
    unsigned capacity;
    V_000c78a8() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_000c78a8) { size -= n; }
    ~V_000c78a8() { int n = size; shrink(n, Alloc_000c78a8()); delete data; }
};
extern "C" void FUN_000c7cb8(V_000c78a8 *v, unsigned n, Alloc_000c78a8 a);
extern "C" void FUN_000c78a8(V_000c78a8 *v, unsigned n)
{
    V_000c78a8 buf;
    FUN_000c7cb8(&buf, n, Alloc_000c78a8());
    Elem_000c78a8 *old = v->data;
    int count = Distance_000c78a8(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_000c78a8(v->capacity, buf.capacity);
    Swap_000c78a8(v->data, buf.data);
    Swap_000c78a8(v->size, buf.size);
}
