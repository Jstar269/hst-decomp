/* HSTMATCH module=EBOOT.BIN start=0x0016b2b4 end=0x0016b300 symbol=FUN_0016b2b4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0x34c];
    short slots[640];
};

extern "C" Block *FUN_0016bb88();

extern "C" short *FUN_0016b2b4(int idx)
{
    Block *b = FUN_0016bb88();
    if (idx >= 0 && idx < 640) {
        return &b->slots[idx];
    }
    return 0;
}
