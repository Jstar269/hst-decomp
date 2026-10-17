/* HSTMATCH module=EBOOT.BIN start=0x0016b300 end=0x0016b348 symbol=FUN_0016b300 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0x84c];
    char slots[640];
};

extern "C" Block *FUN_0016bb88();

extern "C" char *FUN_0016b300(int idx)
{
    Block *b = FUN_0016bb88();
    if (idx >= 0 && idx < 640) {
        return &b->slots[idx];
    }
    return 0;
}
