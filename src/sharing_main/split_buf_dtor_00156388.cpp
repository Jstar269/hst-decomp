/* HSTMATCH module=hstp_trans_main.prx start=0x00156388 end=0x00156488 symbol=__dt__12Buf_00156388Fv lang=c++ */
/* Clone of src/eboot/split_buf_dtor_0006705c.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split-buffer destructor (MWCC deleting form: this + short flag) for a buffer of 12-byte vector-like
   elements {data, size, capacity, alloc*, start}: destroy [data + start, data + start + size) back to front
   (destroy(p) checks p; derived and base element destructors add a null check each), clear the size, then
   the inline base destructor calls the out-of-line 0x14acc0 and frees the block (operator delete behind an
   explicit null test; `delete data` would run the element destructor again). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00156388 {};
struct Elem_00156388 { int v; ~Elem_00156388() {} };
struct IBase_00156388 {
    Elem_00156388 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00156388) { size -= n; }
    ~IBase_00156388() { int n = size; shrink(n, Alloc_00156388()); delete data; }
};
struct Inner_00156388 : IBase_00156388 { ~Inner_00156388() {} };
inline void Destroy_00156388(Inner_00156388 *p) { if (p) p->~Inner_00156388(); }
struct BufBase_00156388;
extern "C" void FUN_001565a8(BufBase_00156388 *b);
struct BufBase_00156388 {
    Inner_00156388 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    ~BufBase_00156388() { FUN_001565a8(this); if (data) operator delete(data); }
};
struct Buf_00156388 : BufBase_00156388 {
    ~Buf_00156388();
};
Buf_00156388::~Buf_00156388()
{
    Inner_00156388 *b = data + start;
    Inner_00156388 *e = b + size;
    while (b < e)
        Destroy_00156388(--e);
    size = 0;
}
