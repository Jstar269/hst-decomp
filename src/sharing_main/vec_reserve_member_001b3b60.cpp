/* HSTMATCH module=hstp_trans_main.prx start=0x001b3b60 end=0x001b3c5c symbol=FUN_001b3b60 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_001b3b60 {};
struct Elem_001b3b60 { int v; ~Elem_001b3b60() {} };
template <class T> inline void Swap_001b3b60(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001b3b60(Elem_001b3b60 *const &a, Elem_001b3b60 *const &b) { return b - a; }
struct V_001b3b60 {
    Elem_001b3b60 *data;
    int size;
    unsigned capacity;
    V_001b3b60() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_001b3b60) { size -= n; }
    ~V_001b3b60() { int n = size; shrink(n, Alloc_001b3b60()); delete data; }
};
extern "C" void FUN_001b52f8(V_001b3b60 *v, unsigned n, Alloc_001b3b60 a);
extern "C" void FUN_001b3b60(V_001b3b60 *v, unsigned n)
{
    V_001b3b60 buf;
    FUN_001b52f8(&buf, n, Alloc_001b3b60());
    Elem_001b3b60 *old = v->data;
    int count = Distance_001b3b60(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_001b3b60(v->capacity, buf.capacity);
    Swap_001b3b60(v->data, buf.data);
    Swap_001b3b60(v->size, buf.size);
}
