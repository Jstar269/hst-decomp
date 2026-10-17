/* HSTMATCH module=EBOOT.BIN start=0x0017c304 end=0x0017c344 symbol=FUN_0017c304 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Slot {
    int active;
};

struct Container {
    char pad[0x14];
    Slot **slots;
    unsigned int count;
};

extern "C" int FUN_0017c304(Container *self, int index)
{
    if (index >= 0) {
        if ((unsigned int)index < self->count) {
            return (*self->slots[index]).active != 0;
        }
    }
    return 0;
}
