/* HSTMATCH module=hstp_trans_main.prx start=0x000684b0 end=0x000685b0 symbol=__dt__12Buf_000684b0Fv lang=c++ */
/* Clone of src/eboot/split_buf_dtor_0006705c.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split-buffer destructor (MWCC deleting form: this + short flag) for a buffer of 12-byte vector-like
   elements {data, size, capacity, alloc*, start}: destroy [data + start, data + start + size) back to front
   (destroy(p) checks p; derived and base element destructors add a null check each), clear the size, then
   the inline base destructor calls the out-of-line 0x14acc0 and frees the block (operator delete behind an
   explicit null test; `delete data` would run the element destructor again). Names provisional. */
#pragma inline_depth(8)
struct Alloc_000684b0 {};
struct Elem_000684b0 { int v; ~Elem_000684b0() {} };
struct IBase_000684b0 {
    Elem_000684b0 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_000684b0) { size -= n; }
    ~IBase_000684b0() { int n = size; shrink(n, Alloc_000684b0()); delete data; }
};
struct Inner_000684b0 : IBase_000684b0 { ~Inner_000684b0() {} };
inline void Destroy_000684b0(Inner_000684b0 *p) { if (p) p->~Inner_000684b0(); }
struct BufBase_000684b0;
extern "C" void FUN_000685b0(BufBase_000684b0 *b);
struct BufBase_000684b0 {
    Inner_000684b0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    ~BufBase_000684b0() { FUN_000685b0(this); if (data) operator delete(data); }
};
struct Buf_000684b0 : BufBase_000684b0 {
    ~Buf_000684b0();
};
Buf_000684b0::~Buf_000684b0()
{
    Inner_000684b0 *b = data + start;
    Inner_000684b0 *e = b + size;
    while (b < e)
        Destroy_000684b0(--e);
    size = 0;
}
