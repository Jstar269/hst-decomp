/* HSTMATCH module=EBOOT.BIN start=0x00237138 end=0x002371e0 symbol=FUN_00237138 lang=c++ */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vec_reserve_member_001a6594.cpp); exact match verified; names and types await human review. */
/* Container reserve(n) for a 72-byte element type: allocate a temporary vector of capacity n (0x2381f0, empty tag
   by value), copy-construct the old elements into it (0x2371e0, forward range append), swap capacity/data/size
   with the temporary and let its destructor free the old block (size cleared through the inline shrink).
   Names provisional. */
#pragma inline_depth(8)
struct Tag {};
struct Alloc {};
struct Elem { int w[18]; ~Elem() {} };
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec {
    Elem *data;
    int size;
    unsigned capacity;
    Vec() : data(0), size(0), capacity(0) {}
    void shrink(int n, Alloc) { size -= n; }
    ~Vec() { int n = size; shrink(n, Alloc()); delete data; }
};
extern "C" void FUN_002381f0(Vec *v, unsigned n, Tag);
extern "C" void FUN_002371e0(Vec *v, Elem *first, Elem *last, Tag);
extern "C" void FUN_00237138(Vec *v, unsigned n)
{
    Vec buf;
    FUN_002381f0(&buf, n, Tag());
    FUN_002371e0(&buf, v->data, v->data + v->size, Tag());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
}
