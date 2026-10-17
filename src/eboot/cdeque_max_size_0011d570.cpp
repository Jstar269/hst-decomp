/* HSTMATCH module=EBOOT.BIN start=0x0011d570 end=0x0011d5ac symbol=FUN_0011d570 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque<4-byte>::max_size(): guarded function-local static (guard 0x33b493, value 0x2c1334) set to
   allocator max_size() (0x3fffffff) minus one; the store-then-decrement is what keeps MWCC from folding the
   constant (see cdeque_reserve_0011dad8.cpp). The unused `this` is not touched. Names provisional. */
extern "C" {
extern char DAT_0033b493;     /* max_size() static guard */
extern unsigned DAT_002c1334; /* max_size() static value */
}
struct Alloc_0011d570 {
    unsigned max_size() const { return 0x3fffffff; }
};
extern "C" unsigned FUN_0011d570(void)
{
    if (!DAT_0033b493) {
        DAT_002c1334 = Alloc_0011d570().max_size();
        --DAT_002c1334;
        DAT_0033b493 = 1;
    }
    return DAT_002c1334;
}
