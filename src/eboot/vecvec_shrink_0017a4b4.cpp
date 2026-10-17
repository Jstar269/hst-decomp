/* HSTMATCH module=EBOOT.BIN start=0x0017a4b4 end=0x0017a548 symbol=FUN_0017a4b4 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146c4c.cpp (hstclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_0017a4b4 {};
struct Elem_0017a4b4 { int v; ~Elem_0017a4b4() {} };
struct Base_0017a4b4 {
    Elem_0017a4b4 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0017a4b4) { size -= n; }
    ~Base_0017a4b4() { int n = size; shrink(n, Alloc_0017a4b4()); delete data; }
};
struct Inner_0017a4b4 : Base_0017a4b4 { ~Inner_0017a4b4() {} };
inline void Destroy_0017a4b4(Inner_0017a4b4 *p) { if (p) p->~Inner_0017a4b4(); }
struct Outer_0017a4b4 { Inner_0017a4b4 *data; int size; };
extern "C" void FUN_0017a4b4(Outer_0017a4b4 *v, int n)
{
    Inner_0017a4b4 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_0017a4b4(--p);
}
