/* HSTMATCH module=EBOOT.BIN start=0x0006705c end=0x0006715c symbol=__dt__12Buf_0006705cFv lang=c++ */
/* Clone of src/eboot/split_buf_dtor_0014aaa0.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split-buffer destructor (MWCC deleting form: this + short flag) for a buffer of 12-byte vector-like
   elements {data, size, capacity, alloc*, start}: destroy [data + start, data + start + size) back to front
   (destroy(p) checks p; derived and base element destructors add a null check each), clear the size, then
   the inline base destructor calls the out-of-line 0x14acc0 and frees the block (operator delete behind an
   explicit null test; `delete data` would run the element destructor again). Names provisional. */
#pragma inline_depth(8)
struct Alloc_0006705c {};
struct Elem_0006705c { int v; ~Elem_0006705c() {} };
struct IBase_0006705c {
    Elem_0006705c *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0006705c) { size -= n; }
    ~IBase_0006705c() { int n = size; shrink(n, Alloc_0006705c()); delete data; }
};
struct Inner_0006705c : IBase_0006705c { ~Inner_0006705c() {} };
inline void Destroy_0006705c(Inner_0006705c *p) { if (p) p->~Inner_0006705c(); }
struct BufBase_0006705c;
extern "C" void FUN_0006715c(BufBase_0006705c *b);
struct BufBase_0006705c {
    Inner_0006705c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    ~BufBase_0006705c() { FUN_0006715c(this); if (data) operator delete(data); }
};
struct Buf_0006705c : BufBase_0006705c {
    ~Buf_0006705c();
};
Buf_0006705c::~Buf_0006705c()
{
    Inner_0006705c *b = data + start;
    Inner_0006705c *e = b + size;
    while (b < e)
        Destroy_0006705c(--e);
    size = 0;
}
