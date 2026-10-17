/* HSTMATCH module=hstp_trans_main.prx start=0x00185fe8 end=0x001860e4 symbol=FUN_00185fe8 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_00185fe8 {};
struct Elem_00185fe8 { int v; ~Elem_00185fe8() {} };
template <class T> inline void Swap_00185fe8(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00185fe8(Elem_00185fe8 *const &a, Elem_00185fe8 *const &b) { return b - a; }
struct V_00185fe8 {
    Elem_00185fe8 *data;
    int size;
    unsigned capacity;
    V_00185fe8() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_00185fe8) { size -= n; }
    ~V_00185fe8() { int n = size; shrink(n, Alloc_00185fe8()); delete data; }
};
extern "C" void FUN_00186b24(V_00185fe8 *v, unsigned n, Alloc_00185fe8 a);
extern "C" void FUN_00185fe8(V_00185fe8 *v, unsigned n)
{
    V_00185fe8 buf;
    FUN_00186b24(&buf, n, Alloc_00185fe8());
    Elem_00185fe8 *old = v->data;
    int count = Distance_00185fe8(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_00185fe8(v->capacity, buf.capacity);
    Swap_00185fe8(v->data, buf.data);
    Swap_00185fe8(v->size, buf.size);
}
