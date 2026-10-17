/* HSTMATCH module=EBOOT.BIN start=0x0017df90 end=0x0017e08c symbol=FUN_0017df90 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_0017df90 {};
struct Elem_0017df90 { int v; ~Elem_0017df90() {} };
template <class T> inline void Swap_0017df90(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0017df90(Elem_0017df90 *const &a, Elem_0017df90 *const &b) { return b - a; }
struct V_0017df90 {
    Elem_0017df90 *data;
    int size;
    unsigned capacity;
    V_0017df90() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_0017df90) { size -= n; }
    ~V_0017df90() { int n = size; shrink(n, Alloc_0017df90()); delete data; }
};
extern "C" void FUN_0017e408(V_0017df90 *v, unsigned n, Alloc_0017df90 a);
extern "C" void FUN_0017df90(V_0017df90 *v, unsigned n)
{
    V_0017df90 buf;
    FUN_0017e408(&buf, n, Alloc_0017df90());
    Elem_0017df90 *old = v->data;
    int count = Distance_0017df90(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_0017df90(v->capacity, buf.capacity);
    Swap_0017df90(v->data, buf.data);
    Swap_0017df90(v->size, buf.size);
}
