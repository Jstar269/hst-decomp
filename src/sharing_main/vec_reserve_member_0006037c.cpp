/* HSTMATCH module=hstp_trans_main.prx start=0x0006037c end=0x00060478 symbol=FUN_0006037c lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x4): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_0006037c {};
struct Elem_0006037c { int v; ~Elem_0006037c() {} };
template <class T> inline void Swap_0006037c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0006037c(Elem_0006037c *const &a, Elem_0006037c *const &b) { return b - a; }
struct V_0006037c {
    Elem_0006037c *data;
    int size;
    unsigned capacity;
    V_0006037c() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_0006037c) { size -= n; }
    ~V_0006037c() { int n = size; shrink(n, Alloc_0006037c()); delete data; }
};
extern "C" void FUN_0006094c(V_0006037c *v, unsigned n, Alloc_0006037c a);
extern "C" void FUN_0006037c(V_0006037c *v, unsigned n)
{
    V_0006037c buf;
    FUN_0006094c(&buf, n, Alloc_0006037c());
    Elem_0006037c *old = v->data;
    int count = Distance_0006037c(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_0006037c(v->capacity, buf.capacity);
    Swap_0006037c(v->data, buf.data);
    Swap_0006037c(v->size, buf.size);
}
