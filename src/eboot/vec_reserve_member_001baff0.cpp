/* HSTMATCH module=EBOOT.BIN start=0x001baff0 end=0x001bb0ec symbol=FUN_001baff0 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_001baff0 {};
struct Elem_001baff0 { int v; ~Elem_001baff0() {} };
template <class T> inline void Swap_001baff0(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001baff0(Elem_001baff0 *const &a, Elem_001baff0 *const &b) { return b - a; }
struct V_001baff0 {
    Elem_001baff0 *data;
    int size;
    unsigned capacity;
    V_001baff0() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_001baff0) { size -= n; }
    ~V_001baff0() { int n = size; shrink(n, Alloc_001baff0()); delete data; }
};
extern "C" void FUN_001bb468(V_001baff0 *v, unsigned n, Alloc_001baff0 a);
extern "C" void FUN_001baff0(V_001baff0 *v, unsigned n)
{
    V_001baff0 buf;
    FUN_001bb468(&buf, n, Alloc_001baff0());
    Elem_001baff0 *old = v->data;
    int count = Distance_001baff0(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_001baff0(v->capacity, buf.capacity);
    Swap_001baff0(v->data, buf.data);
    Swap_001baff0(v->size, buf.size);
}
