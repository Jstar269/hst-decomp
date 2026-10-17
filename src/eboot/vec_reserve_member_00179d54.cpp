/* HSTMATCH module=EBOOT.BIN start=0x00179d54 end=0x00179e50 symbol=FUN_00179d54 lang=c++ */
/* Clone of src/eboot/vec_reserve_member_000c4040.cpp (hstclone.py tag c8): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n (empty allocator passed by value), move the
   old elements into it, clear the old storage, swap, and let the temporary destructor free the old block.
   distance() takes its iterators by const reference, which keeps end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct Alloc_00179d54 {};
struct Elem_00179d54 { int v; ~Elem_00179d54() {} };
template <class T> inline void Swap_00179d54(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00179d54(Elem_00179d54 *const &a, Elem_00179d54 *const &b) { return b - a; }
struct V_00179d54 {
    Elem_00179d54 *data;
    int size;
    unsigned capacity;
    V_00179d54() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc_00179d54) { size -= n; }
    ~V_00179d54() { int n = size; shrink(n, Alloc_00179d54()); delete data; }
};
extern "C" void FUN_0017aa3c(V_00179d54 *v, unsigned n, Alloc_00179d54 a);
extern "C" void FUN_00179d54(V_00179d54 *v, unsigned n)
{
    V_00179d54 buf;
    FUN_0017aa3c(&buf, n, Alloc_00179d54());
    Elem_00179d54 *old = v->data;
    int count = Distance_00179d54(old, old + v->size);
    FUN_00011090(buf.data + buf.size, old, count * 4);
    FUN_000114c0(old, 0, count * 4);
    buf.size += count;
    v->size = 0;
    Swap_00179d54(v->capacity, buf.capacity);
    Swap_00179d54(v->data, buf.data);
    Swap_00179d54(v->size, buf.size);
}
