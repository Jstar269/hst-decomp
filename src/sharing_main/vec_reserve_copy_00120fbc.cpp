/* HSTMATCH module=hstp_trans_main.prx start=0x00120fbc end=0x001210b8 symbol=FUN_00120fbc lang=c++ */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vec_reserve_copy_00215b34.cpp with a 16-byte float element); exact match verified; names and types await human review. */
struct Tag {};
struct Elem { float x, y, z, w; };
inline void *operator new(unsigned, void *p) { return p; }
struct Vec;
extern "C" {
void FUN_00121a50(Vec *, unsigned, Tag);
void FUN_00121330(Vec *, int, Tag);
}
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec {
    Elem *data;
    int size;
    unsigned capacity;
    Vec() : data(0), size(0), capacity(0) {}
    ~Vec() { FUN_00121330(this, size, Tag()); if (data) operator delete(data); }
};
extern "C" void FUN_00120fbc(Vec *v, unsigned n)
{
    Vec buf;
    FUN_00121a50(&buf, n, Tag());
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
