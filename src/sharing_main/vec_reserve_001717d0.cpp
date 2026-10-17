/* HSTMATCH module=hstp_trans_main.prx start=0x001717d0 end=0x00171878 symbol=FUN_001717d0 lang=c++ */
/* Clone of src/eboot/vec_reserve_001655e0.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vec_reserve_member_001baff0.cpp); exact match verified; names and types await human review. */
/* Container reserve(n) for a 556-byte element type: build a temporary vector of capacity n (0x165e60), copy the old elements into it
   (0x165688), swap capacity/data/size, and let the temporary's destructor (`int n = size; shrink(n, Alloc()); if (data) delete data`) free the old block.
   Empty `False` tags are passed by value to both helpers. Names provisional. */
#pragma inline_depth(8)
struct False {};
struct Elem { int w[139]; };
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct V {
    Elem *data;
    int size;
    unsigned capacity;
    V() : data(0), size(0), capacity(0) {}
    void shrink(int n, False) { size -= n; }
    ~V() { int n = size; shrink(n, False()); if (data) operator delete(data); }
};
extern "C" void FUN_00172050(V *v, unsigned n, False a);
extern "C" void FUN_00171878(V *b, Elem *first, Elem *last, False a);
extern "C" void FUN_001717d0(V *v, unsigned n)
{
    V buf;
    FUN_00172050(&buf, n, False());
    FUN_00171878(&buf, v->data, v->data + v->size, False());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
}
