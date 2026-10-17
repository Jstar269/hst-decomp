/* HSTMATCH module=hstp_trans_main.prx start=0x00297c8c end=0x00297d88 symbol=FUN_00297c8c lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_00297c8c {};
struct Elem_00297c8c { int v; ~Elem_00297c8c() {} };
template <class T> inline void Swap_00297c8c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00297c8c(Elem_00297c8c *const &a, Elem_00297c8c *const &b) { return b - a; }
struct V_00297c8c {
    Elem_00297c8c *data;
    int size;
    unsigned capacity;
    V_00297c8c() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_00297c8c) { size -= n; }
    ~V_00297c8c() { int n = size; shrink(n, Alloc_00297c8c()); delete data; }
};
extern "C" void FUN_00297e0c(V_00297c8c *v, unsigned n, Alloc_00297c8c a);
extern "C" void FUN_00297c8c(V_00297c8c *v, unsigned n)
{
    V_00297c8c buf;
    FUN_00297e0c(&buf, n, Alloc_00297c8c());
    Elem_00297c8c *old = v->data;
    int count = Distance_00297c8c(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_00297c8c(v->capacity, buf.capacity);
    Swap_00297c8c(v->data, buf.data);
    Swap_00297c8c(v->size, buf.size);
}
