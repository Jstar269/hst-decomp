/* HSTMATCH module=hstp_trans_main.prx start=0x0019f350 end=0x0019f38c symbol=FUN_0019f350 lang=c++ */
/* Clone of src/eboot/cdeque_max_size_0011d570.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque<4-byte>::max_size(): guarded function-local static (guard 0x3ea919, value 0x2d2c84) set to
   allocator max_size() (0x3fffffff) minus one; the store-then-decrement is what keeps MWCC from folding the
   constant (see cdeque_reserve_0011dad8.cpp). The unused `this` is not touched. Names provisional. */
extern "C" {
extern char DAT_003ea919;     /* max_size() static guard */
extern unsigned DAT_002d2c84; /* max_size() static value */
}
struct Alloc_0019f350 {
    unsigned max_size() const { return 0x3fffffff; }
};
extern "C" unsigned FUN_0019f350(void)
{
    if (!DAT_003ea919) {
        DAT_002d2c84 = Alloc_0019f350().max_size();
        --DAT_002d2c84;
        DAT_003ea919 = 1;
    }
    return DAT_002d2c84;
}
