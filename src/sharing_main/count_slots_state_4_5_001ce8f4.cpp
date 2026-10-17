/* HSTMATCH module=hstp_trans_main.prx start=0x001ce8f4 end=0x001ce950 symbol=FUN_001ce8f4 lang=c++ */
/* Clone of src/eboot/count_slots_state_4_5_001c06e0.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0xacc];
    unsigned char slots[640];
};

static inline unsigned char *SlotAt(Block *b, int idx)
{
    if (idx >= 0 && idx < 640) {
        return &b->slots[idx];
    }
    return 0;
}

extern "C" int FUN_001ce8f4(Block *b)
{
    int n = 0;
    for (int i = 0; i < 640; i++) {
        if ((unsigned)(*SlotAt(b, i) - 4) < 2) {
            n++;
        }
    }
    return n;
}
