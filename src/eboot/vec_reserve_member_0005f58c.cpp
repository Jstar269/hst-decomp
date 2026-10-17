/* HSTMATCH module=EBOOT.BIN start=0x0005f58c end=0x0005f688 symbol=FUN_0005f58c lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_0005f58c {};
struct Elem_0005f58c { int v; ~Elem_0005f58c() {} };
template <class T> inline void Swap_0005f58c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0005f58c(Elem_0005f58c *const &a, Elem_0005f58c *const &b) { return b - a; }
struct V_0005f58c {
    Elem_0005f58c *data;
    int size;
    unsigned capacity;
    V_0005f58c() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_0005f58c) { size -= n; }
    ~V_0005f58c() { int n = size; shrink(n, Alloc_0005f58c()); delete data; }
};
extern "C" void FUN_0005fb5c(V_0005f58c *v, unsigned n, Alloc_0005f58c a);
extern "C" void FUN_0005f58c(V_0005f58c *v, unsigned n)
{
    V_0005f58c buf;
    FUN_0005fb5c(&buf, n, Alloc_0005f58c());
    Elem_0005f58c *old = v->data;
    int count = Distance_0005f58c(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_0005f58c(v->capacity, buf.capacity);
    Swap_0005f58c(v->data, buf.data);
    Swap_0005f58c(v->size, buf.size);
}
