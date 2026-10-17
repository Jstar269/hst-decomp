/* HSTMATCH module=hstp_trans_main.prx start=0x0026c8e8 end=0x0026c924 symbol=FUN_0026c8e8 lang=c++ */
/* Clone of src/eboot/cdeque_max_size_0011d570.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque<4-byte>::max_size(): guarded function-local static (guard 0x3f3af1, value 0x2dad74) set to
   allocator max_size() (0x3fffffff) minus one; the store-then-decrement is what keeps MWCC from folding the
   constant (see cdeque_reserve_0011dad8.cpp). The unused `this` is not touched. Names provisional. */
extern "C" {
extern char DAT_003f3af1;     /* max_size() static guard */
extern unsigned DAT_002dad74; /* max_size() static value */
}
struct Alloc_0026c8e8 {
    unsigned max_size() const { return 0x3fffffff; }
};
extern "C" unsigned FUN_0026c8e8(void)
{
    if (!DAT_003f3af1) {
        DAT_002dad74 = Alloc_0026c8e8().max_size();
        --DAT_002dad74;
        DAT_003f3af1 = 1;
    }
    return DAT_002dad74;
}
