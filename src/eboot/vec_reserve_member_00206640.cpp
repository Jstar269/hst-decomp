/* HSTMATCH module=EBOOT.BIN start=0x00206640 end=0x0020673c symbol=FUN_00206640 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_00206640 {};
struct Elem_00206640 { int v; ~Elem_00206640() {} };
template <class T> inline void Swap_00206640(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00206640(Elem_00206640 *const &a, Elem_00206640 *const &b) { return b - a; }
struct V_00206640 {
    Elem_00206640 *data;
    int size;
    unsigned capacity;
    V_00206640() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_00206640) { size -= n; }
    ~V_00206640() { int n = size; shrink(n, Alloc_00206640()); delete data; }
};
extern "C" void FUN_0020673c(V_00206640 *v, unsigned n, Alloc_00206640 a);
extern "C" void FUN_00206640(V_00206640 *v, unsigned n)
{
    V_00206640 buf;
    FUN_0020673c(&buf, n, Alloc_00206640());
    Elem_00206640 *old = v->data;
    int count = Distance_00206640(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_00206640(v->capacity, buf.capacity);
    Swap_00206640(v->data, buf.data);
    Swap_00206640(v->size, buf.size);
}
