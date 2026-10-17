/* HSTMATCH module=EBOOT.BIN start=0x0028658c end=0x00286688 symbol=FUN_0028658c lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_0028658c {};
struct Elem_0028658c { int v; ~Elem_0028658c() {} };
template <class T> inline void Swap_0028658c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0028658c(Elem_0028658c *const &a, Elem_0028658c *const &b) { return b - a; }
struct V_0028658c {
    Elem_0028658c *data;
    int size;
    unsigned capacity;
    V_0028658c() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_0028658c) { size -= n; }
    ~V_0028658c() { int n = size; shrink(n, Alloc_0028658c()); delete data; }
};
extern "C" void FUN_0028670c(V_0028658c *v, unsigned n, Alloc_0028658c a);
extern "C" void FUN_0028658c(V_0028658c *v, unsigned n)
{
    V_0028658c buf;
    FUN_0028670c(&buf, n, Alloc_0028658c());
    Elem_0028658c *old = v->data;
    int count = Distance_0028658c(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_0028658c(v->capacity, buf.capacity);
    Swap_0028658c(v->data, buf.data);
    Swap_0028658c(v->size, buf.size);
}
