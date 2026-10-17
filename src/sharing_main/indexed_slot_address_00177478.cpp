/* HSTMATCH module=hstp_trans_main.prx start=0x00177478 end=0x001774c4 symbol=FUN_00177478 lang=c++ */
/* Clone of src/eboot/indexed_slot_address_0016b2b4.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0x34c];
    short slots[640];
};

extern "C" Block *FUN_00177d4c();

extern "C" short *FUN_00177478(int idx)
{
    Block *b = FUN_00177d4c();
    if (idx >= 0 && idx < 640) {
        return &b->slots[idx];
    }
    return 0;
}
