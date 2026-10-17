/* HSTMATCH module=EBOOT.BIN start=0x001ce64c end=0x001ce748 symbol=FUN_001ce64c lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_001ce64c {};
struct Elem_001ce64c { int v; ~Elem_001ce64c() {} };
template <class T> inline void Swap_001ce64c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001ce64c(Elem_001ce64c *const &a, Elem_001ce64c *const &b) { return b - a; }
struct V_001ce64c {
    Elem_001ce64c *data;
    int size;
    unsigned capacity;
    V_001ce64c() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_001ce64c) { size -= n; }
    ~V_001ce64c() { int n = size; shrink(n, Alloc_001ce64c()); delete data; }
};
extern "C" void FUN_001cf578(V_001ce64c *v, unsigned n, Alloc_001ce64c a);
extern "C" void FUN_001ce64c(V_001ce64c *v, unsigned n)
{
    V_001ce64c buf;
    FUN_001cf578(&buf, n, Alloc_001ce64c());
    Elem_001ce64c *old = v->data;
    int count = Distance_001ce64c(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_001ce64c(v->capacity, buf.capacity);
    Swap_001ce64c(v->data, buf.data);
    Swap_001ce64c(v->size, buf.size);
}
