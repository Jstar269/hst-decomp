/* HSTMATCH module=EBOOT.BIN start=0x000d5480 end=0x000d557c symbol=FUN_000d5480 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_000d5480 {};
struct Elem_000d5480 { int v; ~Elem_000d5480() {} };
template <class T> inline void Swap_000d5480(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000d5480(Elem_000d5480 *const &a, Elem_000d5480 *const &b) { return b - a; }
struct V_000d5480 {
    Elem_000d5480 *data;
    int size;
    unsigned capacity;
    V_000d5480() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_000d5480) { size -= n; }
    ~V_000d5480() { int n = size; shrink(n, Alloc_000d5480()); delete data; }
};
extern "C" void FUN_000d6178(V_000d5480 *v, unsigned n, Alloc_000d5480 a);
extern "C" void FUN_000d5480(V_000d5480 *v, unsigned n)
{
    V_000d5480 buf;
    FUN_000d6178(&buf, n, Alloc_000d5480());
    Elem_000d5480 *old = v->data;
    int count = Distance_000d5480(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_000d5480(v->capacity, buf.capacity);
    Swap_000d5480(v->data, buf.data);
    Swap_000d5480(v->size, buf.size);
}
