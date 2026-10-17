/* HSTMATCH module=hstp_trans_main.prx start=0x001774c4 end=0x0017750c symbol=FUN_001774c4 lang=c++ */
/* Clone of src/eboot/indexed_slot_address_0016b300.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0x84c];
    char slots[640];
};

extern "C" Block *FUN_00177d4c();

extern "C" char *FUN_001774c4(int idx)
{
    Block *b = FUN_00177d4c();
    if (idx >= 0 && idx < 640) {
        return &b->slots[idx];
    }
    return 0;
}
