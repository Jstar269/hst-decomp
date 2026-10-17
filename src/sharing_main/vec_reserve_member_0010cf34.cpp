/* HSTMATCH module=hstp_trans_main.prx start=0x0010cf34 end=0x0010d030 symbol=FUN_0010cf34 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x4): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_0010cf34 {};
struct Elem_0010cf34 { int v; ~Elem_0010cf34() {} };
template <class T> inline void Swap_0010cf34(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0010cf34(Elem_0010cf34 *const &a, Elem_0010cf34 *const &b) { return b - a; }
struct V_0010cf34 {
    Elem_0010cf34 *data;
    int size;
    unsigned capacity;
    V_0010cf34() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_0010cf34) { size -= n; }
    ~V_0010cf34() { int n = size; shrink(n, Alloc_0010cf34()); delete data; }
};
extern "C" void FUN_0010dee0(V_0010cf34 *v, unsigned n, Alloc_0010cf34 a);
extern "C" void FUN_0010cf34(V_0010cf34 *v, unsigned n)
{
    V_0010cf34 buf;
    FUN_0010dee0(&buf, n, Alloc_0010cf34());
    Elem_0010cf34 *old = v->data;
    int count = Distance_0010cf34(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_0010cf34(v->capacity, buf.capacity);
    Swap_0010cf34(v->data, buf.data);
    Swap_0010cf34(v->size, buf.size);
}
