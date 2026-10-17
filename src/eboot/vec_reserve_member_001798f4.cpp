/* HSTMATCH module=EBOOT.BIN start=0x001798f4 end=0x001799f0 symbol=FUN_001798f4 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_001798f4 {};
struct Elem_001798f4 { int v; ~Elem_001798f4() {} };
template <class T> inline void Swap_001798f4(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001798f4(Elem_001798f4 *const &a, Elem_001798f4 *const &b) { return b - a; }
struct V_001798f4 {
    Elem_001798f4 *data;
    int size;
    unsigned capacity;
    V_001798f4() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_001798f4) { size -= n; }
    ~V_001798f4() { int n = size; shrink(n, Alloc_001798f4()); delete data; }
};
extern "C" void FUN_0017a430(V_001798f4 *v, unsigned n, Alloc_001798f4 a);
extern "C" void FUN_001798f4(V_001798f4 *v, unsigned n)
{
    V_001798f4 buf;
    FUN_0017a430(&buf, n, Alloc_001798f4());
    Elem_001798f4 *old = v->data;
    int count = Distance_001798f4(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_001798f4(v->capacity, buf.capacity);
    Swap_001798f4(v->data, buf.data);
    Swap_001798f4(v->size, buf.size);
}
