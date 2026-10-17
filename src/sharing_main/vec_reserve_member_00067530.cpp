/* HSTMATCH module=hstp_trans_main.prx start=0x00067530 end=0x0006762c symbol=FUN_00067530 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x4): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_00067530 {};
struct Elem_00067530 { int v; ~Elem_00067530() {} };
template <class T> inline void Swap_00067530(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00067530(Elem_00067530 *const &a, Elem_00067530 *const &b) { return b - a; }
struct V_00067530 {
    Elem_00067530 *data;
    int size;
    unsigned capacity;
    V_00067530() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_00067530) { size -= n; }
    ~V_00067530() { int n = size; shrink(n, Alloc_00067530()); delete data; }
};
extern "C" void FUN_00068098(V_00067530 *v, unsigned n, Alloc_00067530 a);
extern "C" void FUN_00067530(V_00067530 *v, unsigned n)
{
    V_00067530 buf;
    FUN_00068098(&buf, n, Alloc_00067530());
    Elem_00067530 *old = v->data;
    int count = Distance_00067530(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_00067530(v->capacity, buf.capacity);
    Swap_00067530(v->data, buf.data);
    Swap_00067530(v->size, buf.size);
}
