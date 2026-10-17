/* HSTMATCH module=EBOOT.BIN start=0x00065dd0 end=0x00065e64 symbol=FUN_00065dd0 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146c4c.cpp (hstclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00065dd0 {};
struct Elem_00065dd0 { int v; ~Elem_00065dd0() {} };
struct Base_00065dd0 {
    Elem_00065dd0 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00065dd0) { size -= n; }
    ~Base_00065dd0() { int n = size; shrink(n, Alloc_00065dd0()); delete data; }
};
struct Inner_00065dd0 : Base_00065dd0 { ~Inner_00065dd0() {} };
inline void Destroy_00065dd0(Inner_00065dd0 *p) { if (p) p->~Inner_00065dd0(); }
struct Outer_00065dd0 { Inner_00065dd0 *data; int size; };
extern "C" void FUN_00065dd0(Outer_00065dd0 *v, int n)
{
    Inner_00065dd0 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_00065dd0(--p);
}
