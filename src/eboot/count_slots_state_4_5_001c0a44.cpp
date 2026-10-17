/* HSTMATCH module=EBOOT.BIN start=0x001c0a44 end=0x001c0aa0 symbol=FUN_001c0a44 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0xfe1];
    unsigned char slots[8];
};

static inline unsigned char *SlotAt(Block *b, int idx)
{
    if (idx >= 0 && idx < 8) {
        return &b->slots[idx];
    }
    return 0;
}

extern "C" int FUN_001c0a44(Block *b)
{
    int n = 0;
    for (int i = 0; i < 8; i++) {
        if ((unsigned)(*SlotAt(b, i) - 4) < 2) {
            n++;
        }
    }
    return n;
}
