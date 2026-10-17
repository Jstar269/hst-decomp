/* HSTMATCH module=EBOOT.BIN start=0x001c09e8 end=0x001c0a44 symbol=FUN_001c09e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0xfcc];
    unsigned char slots[21];
};

static inline unsigned char *SlotAt(Block *b, int idx)
{
    if (idx >= 0 && idx < 21) {
        return &b->slots[idx];
    }
    return 0;
}

extern "C" int FUN_001c09e8(Block *b)
{
    int n = 0;
    for (int i = 0; i < 21; i++) {
        if ((unsigned)(*SlotAt(b, i) - 4) < 2) {
            n++;
        }
    }
    return n;
}
