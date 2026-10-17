/* HSTMATCH module=EBOOT.BIN start=0x001a6594 end=0x001a6690 symbol=FUN_001a6594 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_001a6594 {};
struct Elem_001a6594 { int v; ~Elem_001a6594() {} };
template <class T> inline void Swap_001a6594(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001a6594(Elem_001a6594 *const &a, Elem_001a6594 *const &b) { return b - a; }
struct V_001a6594 {
    Elem_001a6594 *data;
    int size;
    unsigned capacity;
    V_001a6594() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_001a6594) { size -= n; }
    ~V_001a6594() { int n = size; shrink(n, Alloc_001a6594()); delete data; }
};
extern "C" void FUN_001a7d2c(V_001a6594 *v, unsigned n, Alloc_001a6594 a);
extern "C" void FUN_001a6594(V_001a6594 *v, unsigned n)
{
    V_001a6594 buf;
    FUN_001a7d2c(&buf, n, Alloc_001a6594());
    Elem_001a6594 *old = v->data;
    int count = Distance_001a6594(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_001a6594(v->capacity, buf.capacity);
    Swap_001a6594(v->data, buf.data);
    Swap_001a6594(v->size, buf.size);
}
