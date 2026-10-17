/* HSTMATCH module=hstp_trans_main.prx start=0x001b5c9c end=0x001b5d9c symbol=__dt__12Buf_001b5c9cFv lang=c++ */
/* Clone of src/eboot/split_buf_dtor_0006705c.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split-buffer destructor (MWCC deleting form: this + short flag) for a buffer of 12-byte vector-like
   elements {data, size, capacity, alloc*, start}: destroy [data + start, data + start + size) back to front
   (destroy(p) checks p; derived and base element destructors add a null check each), clear the size, then
   the inline base destructor calls the out-of-line 0x14acc0 and frees the block (operator delete behind an
   explicit null test; `delete data` would run the element destructor again). Names provisional. */
#pragma inline_depth(8)
struct Alloc_001b5c9c {};
struct Elem_001b5c9c { int v; ~Elem_001b5c9c() {} };
struct IBase_001b5c9c {
    Elem_001b5c9c *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001b5c9c) { size -= n; }
    ~IBase_001b5c9c() { int n = size; shrink(n, Alloc_001b5c9c()); delete data; }
};
struct Inner_001b5c9c : IBase_001b5c9c { ~Inner_001b5c9c() {} };
inline void Destroy_001b5c9c(Inner_001b5c9c *p) { if (p) p->~Inner_001b5c9c(); }
struct BufBase_001b5c9c;
extern "C" void FUN_001b5d9c(BufBase_001b5c9c *b);
struct BufBase_001b5c9c {
    Inner_001b5c9c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    ~BufBase_001b5c9c() { FUN_001b5d9c(this); if (data) operator delete(data); }
};
struct Buf_001b5c9c : BufBase_001b5c9c {
    ~Buf_001b5c9c();
};
Buf_001b5c9c::~Buf_001b5c9c()
{
    Inner_001b5c9c *b = data + start;
    Inner_001b5c9c *e = b + size;
    while (b < e)
        Destroy_001b5c9c(--e);
    size = 0;
}
