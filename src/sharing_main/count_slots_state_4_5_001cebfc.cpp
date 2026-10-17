/* HSTMATCH module=hstp_trans_main.prx start=0x001cebfc end=0x001cec58 symbol=FUN_001cebfc lang=c++ */
/* Clone of src/eboot/count_slots_state_4_5_001c09e8.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" int FUN_001cebfc(Block *b)
{
    int n = 0;
    for (int i = 0; i < 21; i++) {
        if ((unsigned)(*SlotAt(b, i) - 4) < 2) {
            n++;
        }
    }
    return n;
}
