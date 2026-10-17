/* HSTMATCH module=EBOOT.BIN start=0x001a63ec end=0x001a64e8 symbol=FUN_001a63ec lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_001a63ec {};
struct Elem_001a63ec { int v; ~Elem_001a63ec() {} };
template <class T> inline void Swap_001a63ec(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001a63ec(Elem_001a63ec *const &a, Elem_001a63ec *const &b) { return b - a; }
struct V_001a63ec {
    Elem_001a63ec *data;
    int size;
    unsigned capacity;
    V_001a63ec() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_001a63ec) { size -= n; }
    ~V_001a63ec() { int n = size; shrink(n, Alloc_001a63ec()); delete data; }
};
extern "C" void FUN_001a7994(V_001a63ec *v, unsigned n, Alloc_001a63ec a);
extern "C" void FUN_001a63ec(V_001a63ec *v, unsigned n)
{
    V_001a63ec buf;
    FUN_001a7994(&buf, n, Alloc_001a63ec());
    Elem_001a63ec *old = v->data;
    int count = Distance_001a63ec(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_001a63ec(v->capacity, buf.capacity);
    Swap_001a63ec(v->data, buf.data);
    Swap_001a63ec(v->size, buf.size);
}
