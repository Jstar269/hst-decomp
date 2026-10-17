/* HSTMATCH module=hstp_trans_main.prx start=0x0024729c end=0x00247344 symbol=FUN_0024729c lang=c++ */
/* Clone of src/eboot/vec_reserve_member_00237138.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_00248328(Vec *v, unsigned n, Tag);
extern "C" void FUN_00247344(Vec *v, Elem *first, Elem *last, Tag);
extern "C" void FUN_0024729c(Vec *v, unsigned n)
{
    Vec buf;
    FUN_00248328(&buf, n, Tag());
    FUN_00247344(&buf, v->data, v->data + v->size, Tag());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
}
