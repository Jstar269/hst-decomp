/* HSTMATCH module=hstp_trans_main.prx start=0x000d9170 end=0x000d926c symbol=FUN_000d9170 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x4): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_000d9170 {};
struct Elem_000d9170 { int v; ~Elem_000d9170() {} };
template <class T> inline void Swap_000d9170(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000d9170(Elem_000d9170 *const &a, Elem_000d9170 *const &b) { return b - a; }
struct V_000d9170 {
    Elem_000d9170 *data;
    int size;
    unsigned capacity;
    V_000d9170() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_000d9170) { size -= n; }
    ~V_000d9170() { int n = size; shrink(n, Alloc_000d9170()); delete data; }
};
extern "C" void FUN_000d9e68(V_000d9170 *v, unsigned n, Alloc_000d9170 a);
extern "C" void FUN_000d9170(V_000d9170 *v, unsigned n)
{
    V_000d9170 buf;
    FUN_000d9e68(&buf, n, Alloc_000d9170());
    Elem_000d9170 *old = v->data;
    int count = Distance_000d9170(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_000d9170(v->capacity, buf.capacity);
    Swap_000d9170(v->data, buf.data);
    Swap_000d9170(v->size, buf.size);
}
