/* HSTMATCH module=hstp_trans_main.prx start=0x0010cdf4 end=0x0010cef0 symbol=FUN_0010cdf4 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x4): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_0010cdf4 {};
struct Elem_0010cdf4 { int v; ~Elem_0010cdf4() {} };
template <class T> inline void Swap_0010cdf4(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0010cdf4(Elem_0010cdf4 *const &a, Elem_0010cdf4 *const &b) { return b - a; }
struct V_0010cdf4 {
    Elem_0010cdf4 *data;
    int size;
    unsigned capacity;
    V_0010cdf4() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_0010cdf4) { size -= n; }
    ~V_0010cdf4() { int n = size; shrink(n, Alloc_0010cdf4()); delete data; }
};
extern "C" void FUN_0010da60(V_0010cdf4 *v, unsigned n, Alloc_0010cdf4 a);
extern "C" void FUN_0010cdf4(V_0010cdf4 *v, unsigned n)
{
    V_0010cdf4 buf;
    FUN_0010da60(&buf, n, Alloc_0010cdf4());
    Elem_0010cdf4 *old = v->data;
    int count = Distance_0010cdf4(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_0010cdf4(v->capacity, buf.capacity);
    Swap_0010cdf4(v->data, buf.data);
    Swap_0010cdf4(v->size, buf.size);
}
