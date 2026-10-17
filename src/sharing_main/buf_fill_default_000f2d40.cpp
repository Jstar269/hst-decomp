/* HSTMATCH module=hstp_trans_main.prx start=0x000f2d40 end=0x000f2d8c symbol=FUN_000f2d40 lang=c++ */
/* Clone of src/eboot/buf_fill_default_000ed678.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Fill n copies of a default-constructed element (ctor 0xebd14) into the split buffer (fill 0xed6c4, which takes
   an empty tag by value: `move v0,zero; seb a3,v0`). Matching idiom: retail's frame is 16 bytes larger than the
   96-byte element at sp+32 needs; the local is therefore a 112-byte type deriving from Elem (the real origin of
   the extra bytes, probably empty-tag/allocator temporaries of an inlined caller, was not found; plain Elem,
   aligned Elem, tag-taking inline wrappers and Elem() temporaries all give a 128-byte frame). Names provisional. */
struct False {};
struct Elem { int w[24]; };
struct ElemLocal : Elem { int pad[4]; };
class Buf;
extern "C" Elem *FUN_000f126c(Elem *);
extern "C" void FUN_000f2d8c(Buf *, unsigned, const Elem &, False);

extern "C" void FUN_000f2d40(Buf *b, unsigned n)
{
    ElemLocal x;
    FUN_000f126c(&x);
    FUN_000f2d8c(b, n, x, False());
}
