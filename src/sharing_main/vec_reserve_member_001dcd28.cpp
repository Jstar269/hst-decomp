/* HSTMATCH module=hstp_trans_main.prx start=0x001dcd28 end=0x001dce24 symbol=FUN_001dcd28 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_001dcd28 {};
struct Elem_001dcd28 { int v; ~Elem_001dcd28() {} };
template <class T> inline void Swap_001dcd28(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001dcd28(Elem_001dcd28 *const &a, Elem_001dcd28 *const &b) { return b - a; }
struct V_001dcd28 {
    Elem_001dcd28 *data;
    int size;
    unsigned capacity;
    V_001dcd28() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_001dcd28) { size -= n; }
    ~V_001dcd28() { int n = size; shrink(n, Alloc_001dcd28()); delete data; }
};
extern "C" void FUN_001ddc54(V_001dcd28 *v, unsigned n, Alloc_001dcd28 a);
extern "C" void FUN_001dcd28(V_001dcd28 *v, unsigned n)
{
    V_001dcd28 buf;
    FUN_001ddc54(&buf, n, Alloc_001dcd28());
    Elem_001dcd28 *old = v->data;
    int count = Distance_001dcd28(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_001dcd28(v->capacity, buf.capacity);
    Swap_001dcd28(v->data, buf.data);
    Swap_001dcd28(v->size, buf.size);
}
