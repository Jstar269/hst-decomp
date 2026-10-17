/* HSTMATCH module=EBOOT.BIN start=0x000c4040 end=0x000c413c symbol=FUN_000c4040 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_000c4040 {};
struct Elem_000c4040 { int v; ~Elem_000c4040() {} };
template <class T> inline void Swap_000c4040(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000c4040(Elem_000c4040 *const &a, Elem_000c4040 *const &b) { return b - a; }
struct V_000c4040 {
    Elem_000c4040 *data;
    int size;
    unsigned capacity;
    V_000c4040() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_000c4040) { size -= n; }
    ~V_000c4040() { int n = size; shrink(n, Alloc_000c4040()); delete data; }
};
extern "C" void FUN_000c4450(V_000c4040 *v, unsigned n, Alloc_000c4040 a);
extern "C" void FUN_000c4040(V_000c4040 *v, unsigned n)
{
    V_000c4040 buf;
    FUN_000c4450(&buf, n, Alloc_000c4040());
    Elem_000c4040 *old = v->data;
    int count = Distance_000c4040(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_000c4040(v->capacity, buf.capacity);
    Swap_000c4040(v->data, buf.data);
    Swap_000c4040(v->size, buf.size);
}
