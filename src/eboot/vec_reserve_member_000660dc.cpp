/* HSTMATCH module=EBOOT.BIN start=0x000660dc end=0x000661d8 symbol=FUN_000660dc lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_000660dc {};
struct Elem_000660dc { int v; ~Elem_000660dc() {} };
template <class T> inline void Swap_000660dc(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000660dc(Elem_000660dc *const &a, Elem_000660dc *const &b) { return b - a; }
struct V_000660dc {
    Elem_000660dc *data;
    int size;
    unsigned capacity;
    V_000660dc() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_000660dc) { size -= n; }
    ~V_000660dc() { int n = size; shrink(n, Alloc_000660dc()); delete data; }
};
extern "C" void FUN_00066c44(V_000660dc *v, unsigned n, Alloc_000660dc a);
extern "C" void FUN_000660dc(V_000660dc *v, unsigned n)
{
    V_000660dc buf;
    FUN_00066c44(&buf, n, Alloc_000660dc());
    Elem_000660dc *old = v->data;
    int count = Distance_000660dc(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_000660dc(v->capacity, buf.capacity);
    Swap_000660dc(v->data, buf.data);
    Swap_000660dc(v->size, buf.size);
}
