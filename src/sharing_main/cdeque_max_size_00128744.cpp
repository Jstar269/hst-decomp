/* HSTMATCH module=hstp_trans_main.prx start=0x00128744 end=0x00128780 symbol=FUN_00128744 lang=c++ */
/* Clone of src/eboot/cdeque_max_size_0011d570.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque<4-byte>::max_size(): guarded function-local static (guard 0x3e47d3, value 0x2d1714) set to
   allocator max_size() (0x3fffffff) minus one; the store-then-decrement is what keeps MWCC from folding the
   constant (see cdeque_reserve_0011dad8.cpp). The unused `this` is not touched. Names provisional. */
extern "C" {
extern char DAT_003e47d3;     /* max_size() static guard */
extern unsigned DAT_002d1714; /* max_size() static value */
}
struct Alloc_00128744 {
    unsigned max_size() const { return 0x3fffffff; }
};
extern "C" unsigned FUN_00128744(void)
{
    if (!DAT_003e47d3) {
        DAT_002d1714 = Alloc_00128744().max_size();
        --DAT_002d1714;
        DAT_003e47d3 = 1;
    }
    return DAT_002d1714;
}
