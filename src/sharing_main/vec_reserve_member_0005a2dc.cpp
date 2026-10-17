/* HSTMATCH module=hstp_trans_main.prx start=0x0005a2dc end=0x0005a3d8 symbol=FUN_0005a2dc lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00050dd8.cpp (hstclone.py tag x4): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_0005a2dc {};
struct Elem_0005a2dc { int v; ~Elem_0005a2dc() {} };
template <class T> inline void Swap_0005a2dc(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0005a2dc(Elem_0005a2dc *const &a, Elem_0005a2dc *const &b) { return b - a; }
struct V_0005a2dc {
    Elem_0005a2dc *data;
    int size;
    unsigned capacity;
    V_0005a2dc() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_0005a2dc) { size -= n; }
    ~V_0005a2dc() { int n = size; shrink(n, Alloc_0005a2dc()); delete data; }
};
extern "C" void FUN_0005a928(V_0005a2dc *v, unsigned n, Alloc_0005a2dc a);
extern "C" void FUN_0005a2dc(V_0005a2dc *v, unsigned n)
{
    V_0005a2dc buf;
    FUN_0005a928(&buf, n, Alloc_0005a2dc());
    Elem_0005a2dc *old = v->data;
    int count = Distance_0005a2dc(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_0005a2dc(v->capacity, buf.capacity);
    Swap_0005a2dc(v->data, buf.data);
    Swap_0005a2dc(v->size, buf.size);
}
