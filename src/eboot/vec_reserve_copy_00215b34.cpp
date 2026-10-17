/* HSTMATCH module=EBOOT.BIN start=0x00215b34 end=0x00215c20 symbol=FUN_00215b34 lang=c++ */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vec_reserve_member_00237138.cpp with an inline forward copy loop as in src/eboot/vec_append_range_6b_000d9ccc.cpp); exact match verified; names and types await human review. */
struct Tag {};
struct Elem { float x, y; };
inline void *operator new(unsigned, void *p) { return p; }
struct Vec;
extern "C" {
void FUN_00215fb4(Vec *, unsigned, Tag);
void FUN_00215c8c(Vec *, int, Tag);
}
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec {
    Elem *data;
    int size;
    unsigned capacity;
    Vec() : data(0), size(0), capacity(0) {}
    ~Vec() { FUN_00215c8c(this, size, Tag()); if (data) operator delete(data); }
};
extern "C" void FUN_00215b34(Vec *v, unsigned n)
{
    Vec buf;
    FUN_00215fb4(&buf, n, Tag());
    Elem *first = v->data;
    Elem *last = first + v->size;
    Elem *p = buf.data + buf.size;
    for (; first < last; ++first) {
        new (p) Elem(*first);
        ++p;
        ++buf.size;
    }
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
}
// Container reserve(n) for an 8-byte element (two floats): allocate a temporary vector of capacity n with 0x215fb4
// (empty tag by value), copy the old elements into it with an inline placement-new loop (the temporary's size is
// bumped per element), swap capacity/data/size and let the temporary's destructor (out-of-line shrink 0x215c8c with
// the old size, then delete of the old block) release the old storage.
