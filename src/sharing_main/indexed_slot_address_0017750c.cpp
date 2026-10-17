/* HSTMATCH module=hstp_trans_main.prx start=0x0017750c end=0x00177554 symbol=FUN_0017750c lang=c++ */
/* Clone of src/eboot/indexed_slot_address_0016b348.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Block {
    char pad[0xacc];
    char slots[640];
};

extern "C" Block *FUN_00177d4c();

extern "C" char *FUN_0017750c(int idx)
{
    Block *b = FUN_00177d4c();
    if (idx >= 0 && idx < 640) {
        return &b->slots[idx];
    }
    return 0;
}
