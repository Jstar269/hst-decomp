/* HSTMATCH module=EBOOT.BIN start=0x0014aaa0 end=0x0014aba0 symbol=__dt__12Buf_0014aaa0Fv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split-buffer destructor (MWCC deleting form: this + short flag) for a buffer of 12-byte vector-like
   elements {data, size, capacity, alloc*, start}: destroy [data + start, data + start + size) back to front
   (destroy(p) checks p; derived and base element destructors add a null check each), clear the size, then
   the inline base destructor calls the out-of-line 0x14acc0 and frees the block (operator delete behind an
   explicit null test; `delete data` would run the element destructor again). Names provisional. */
#pragma inline_depth(8)
struct Alloc_0014aaa0 {};
struct Elem_0014aaa0 { int v; ~Elem_0014aaa0() {} };
struct IBase_0014aaa0 {
    Elem_0014aaa0 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0014aaa0) { size -= n; }
    ~IBase_0014aaa0() { int n = size; shrink(n, Alloc_0014aaa0()); delete data; }
};
struct Inner_0014aaa0 : IBase_0014aaa0 { ~Inner_0014aaa0() {} };
inline void Destroy_0014aaa0(Inner_0014aaa0 *p) { if (p) p->~Inner_0014aaa0(); }
struct BufBase_0014aaa0;
extern "C" void FUN_0014acc0(BufBase_0014aaa0 *b);
struct BufBase_0014aaa0 {
    Inner_0014aaa0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    ~BufBase_0014aaa0() { FUN_0014acc0(this); if (data) operator delete(data); }
};
struct Buf_0014aaa0 : BufBase_0014aaa0 {
    ~Buf_0014aaa0();
};
Buf_0014aaa0::~Buf_0014aaa0()
{
    Inner_0014aaa0 *b = data + start;
    Inner_0014aaa0 *e = b + size;
    while (b < e)
        Destroy_0014aaa0(--e);
    size = 0;
}
