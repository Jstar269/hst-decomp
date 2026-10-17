/* HSTMATCH module=hstp_trans_main.prx start=0x0018a684 end=0x0018a780 symbol=FUN_0018a684 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_0018a684 {};
struct Elem_0018a684 { int v; ~Elem_0018a684() {} };
template <class T> inline void Swap_0018a684(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0018a684(Elem_0018a684 *const &a, Elem_0018a684 *const &b) { return b - a; }
struct V_0018a684 {
    Elem_0018a684 *data;
    int size;
    unsigned capacity;
    V_0018a684() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_0018a684) { size -= n; }
    ~V_0018a684() { int n = size; shrink(n, Alloc_0018a684()); delete data; }
};
extern "C" void FUN_0018aafc(V_0018a684 *v, unsigned n, Alloc_0018a684 a);
extern "C" void FUN_0018a684(V_0018a684 *v, unsigned n)
{
    V_0018a684 buf;
    FUN_0018aafc(&buf, n, Alloc_0018a684());
    Elem_0018a684 *old = v->data;
    int count = Distance_0018a684(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_0018a684(v->capacity, buf.capacity);
    Swap_0018a684(v->data, buf.data);
    Swap_0018a684(v->size, buf.size);
}
