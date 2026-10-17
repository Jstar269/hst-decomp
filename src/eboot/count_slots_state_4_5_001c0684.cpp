/* HSTMATCH module=EBOOT.BIN start=0x001c0684 end=0x001c06e0 symbol=FUN_001c0684 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0x84c];
    unsigned char slots[640];
};

static inline unsigned char *SlotAt(Block *b, int idx)
{
    if (idx >= 0 && idx < 640) {
        return &b->slots[idx];
    }
    return 0;
}

extern "C" int FUN_001c0684(Block *b)
{
    int n = 0;
    for (int i = 0; i < 640; i++) {
        if ((unsigned)(*SlotAt(b, i) - 4) < 2) {
            n++;
        }
    }
    return n;
}
