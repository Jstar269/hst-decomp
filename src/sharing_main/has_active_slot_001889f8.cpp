/* HSTMATCH module=hstp_trans_main.prx start=0x001889f8 end=0x00188a38 symbol=FUN_001889f8 lang=c++ */
/* Clone of src/eboot/has_active_slot_0017c304.cpp (hstclone.py tag u1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Slot {
    int active;
};

struct Container {
    char pad[0x14];
    Slot **slots;
    unsigned int count;
};

extern "C" int FUN_001889f8(Container *self, int index)
{
    if (index >= 0) {
        if ((unsigned int)index < self->count) {
            return (*self->slots[index]).active != 0;
        }
    }
    return 0;
}
