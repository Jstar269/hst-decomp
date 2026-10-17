/* HSTMATCH module=EBOOT.BIN start=0x001a86d0 end=0x001a87d0 symbol=__dt__12Buf_001a86d0Fv lang=c++ */
/* Clone of src/eboot/split_buf_dtor_0014aaa0.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split-buffer destructor (MWCC deleting form: this + short flag) for a buffer of 12-byte vector-like
   elements {data, size, capacity, alloc*, start}: destroy [data + start, data + start + size) back to front
   (destroy(p) checks p; derived and base element destructors add a null check each), clear the size, then
   the inline base destructor calls the out-of-line 0x14acc0 and frees the block (operator delete behind an
   explicit null test; `delete data` would run the element destructor again). Names provisional. */
#pragma inline_depth(8)
struct Alloc_001a86d0 {};
struct Elem_001a86d0 { int v; ~Elem_001a86d0() {} };
struct IBase_001a86d0 {
    Elem_001a86d0 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001a86d0) { size -= n; }
    ~IBase_001a86d0() { int n = size; shrink(n, Alloc_001a86d0()); delete data; }
};
struct Inner_001a86d0 : IBase_001a86d0 { ~Inner_001a86d0() {} };
inline void Destroy_001a86d0(Inner_001a86d0 *p) { if (p) p->~Inner_001a86d0(); }
struct BufBase_001a86d0;
extern "C" void FUN_001a87d0(BufBase_001a86d0 *b);
struct BufBase_001a86d0 {
    Inner_001a86d0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    ~BufBase_001a86d0() { FUN_001a87d0(this); if (data) operator delete(data); }
};
struct Buf_001a86d0 : BufBase_001a86d0 {
    ~Buf_001a86d0();
};
Buf_001a86d0::~Buf_001a86d0()
{
    Inner_001a86d0 *b = data + start;
    Inner_001a86d0 *e = b + size;
    while (b < e)
        Destroy_001a86d0(--e);
    size = 0;
}
