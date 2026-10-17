/* HSTMATCH module=EBOOT.BIN start=0x00192b40 end=0x00192b7c symbol=FUN_00192b40 lang=c++ */
/* Clone of src/eboot/cdeque_max_size_0011d570.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque<4-byte>::max_size(): guarded function-local static (guard 0x3415d9, value 0x2c2784) set to
   allocator max_size() (0x3fffffff) minus one; the store-then-decrement is what keeps MWCC from folding the
   constant (see cdeque_reserve_0011dad8.cpp). The unused `this` is not touched. Names provisional. */
extern "C" {
extern char DAT_003415d9;     /* max_size() static guard */
extern unsigned DAT_002c2784; /* max_size() static value */
}
struct Alloc_00192b40 {
    unsigned max_size() const { return 0x3fffffff; }
};
extern "C" unsigned FUN_00192b40(void)
{
    if (!DAT_003415d9) {
        DAT_002c2784 = Alloc_00192b40().max_size();
        --DAT_002c2784;
        DAT_003415d9 = 1;
    }
    return DAT_002c2784;
}
