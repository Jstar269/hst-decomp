/* HSTMATCH module=EBOOT.BIN start=0x0011d5fc end=0x0011d638 symbol=FUN_0011d5fc lang=c++ */
/* Clone of src/eboot/cdeque_max_size_0011d570.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque<4-byte>::max_size(): guarded function-local static (guard 0x33b492, value 0x2c1330) set to
   allocator max_size() (0x3fffffff) minus one; the store-then-decrement is what keeps MWCC from folding the
   constant (see cdeque_reserve_0011dad8.cpp). The unused `this` is not touched. Names provisional. */
extern "C" {
extern char DAT_0033b492;     /* max_size() static guard */
extern unsigned DAT_002c1330; /* max_size() static value */
}
struct Alloc_0011d5fc {
    unsigned max_size() const { return 0x3fffffff; }
};
extern "C" unsigned FUN_0011d5fc(void)
{
    if (!DAT_0033b492) {
        DAT_002c1330 = Alloc_0011d5fc().max_size();
        --DAT_002c1330;
        DAT_0033b492 = 1;
    }
    return DAT_002c1330;
}
