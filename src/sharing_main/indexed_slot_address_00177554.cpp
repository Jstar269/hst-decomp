/* HSTMATCH module=hstp_trans_main.prx start=0x00177554 end=0x0017759c symbol=FUN_00177554 lang=c++ */
/* Clone of src/eboot/indexed_slot_address_0016b390.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0xd4c];
    char slots[640];
};

extern "C" Block *FUN_00177d4c();

extern "C" char *FUN_00177554(int idx)
{
    Block *b = FUN_00177d4c();
    if (idx >= 0 && idx < 640) {
        return &b->slots[idx];
    }
    return 0;
}
