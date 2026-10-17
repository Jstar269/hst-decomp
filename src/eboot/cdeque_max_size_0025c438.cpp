/* HSTMATCH module=EBOOT.BIN start=0x0025c438 end=0x0025c474 symbol=FUN_0025c438 lang=c++ */
/* Clone of src/eboot/cdeque_max_size_0011d570.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque<4-byte>::max_size(): guarded function-local static (guard 0x34a7c1, value 0x2ca7b4) set to
   allocator max_size() (0x3fffffff) minus one; the store-then-decrement is what keeps MWCC from folding the
   constant (see cdeque_reserve_0011dad8.cpp). The unused `this` is not touched. Names provisional. */
extern "C" {
extern char DAT_0034a7c1;     /* max_size() static guard */
extern unsigned DAT_002ca7b4; /* max_size() static value */
}
struct Alloc_0025c438 {
    unsigned max_size() const { return 0x3fffffff; }
};
extern "C" unsigned FUN_0025c438(void)
{
    if (!DAT_0034a7c1) {
        DAT_002ca7b4 = Alloc_0025c438().max_size();
        --DAT_002ca7b4;
        DAT_0034a7c1 = 1;
    }
    return DAT_002ca7b4;
}
