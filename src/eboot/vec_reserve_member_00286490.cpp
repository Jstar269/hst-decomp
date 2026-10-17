/* HSTMATCH module=EBOOT.BIN start=0x00286490 end=0x0028658c symbol=FUN_00286490 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_00286490 {};
struct Elem_00286490 { int v; ~Elem_00286490() {} };
template <class T> inline void Swap_00286490(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00286490(Elem_00286490 *const &a, Elem_00286490 *const &b) { return b - a; }
struct V_00286490 {
    Elem_00286490 *data;
    int size;
    unsigned capacity;
    V_00286490() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_00286490) { size -= n; }
    ~V_00286490() { int n = size; shrink(n, Alloc_00286490()); delete data; }
};
extern "C" void FUN_00286688(V_00286490 *v, unsigned n, Alloc_00286490 a);
extern "C" void FUN_00286490(V_00286490 *v, unsigned n)
{
    V_00286490 buf;
    FUN_00286688(&buf, n, Alloc_00286490());
    Elem_00286490 *old = v->data;
    int count = Distance_00286490(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_00286490(v->capacity, buf.capacity);
    Swap_00286490(v->data, buf.data);
    Swap_00286490(v->size, buf.size);
}
