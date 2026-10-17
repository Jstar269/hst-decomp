/* HSTMATCH module=EBOOT.BIN start=0x001fcef4 end=0x001fcf64 symbol=FUN_001fcef4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: modeled the child vtable call and byte field in a typed class; exact match verified; names and types await human review. */
struct Device {
    virtual void first() = 0;
    virtual void second() = 0;
    virtual void third() = 0;
    virtual void refresh() = 0;
    char pad[0x58];
    unsigned char state;
};
struct Owner {
    char pad[0x44];
    Device *device;
};
extern "C" void FUN_00103628(Device *, unsigned char);

extern "C" void FUN_001fcef4(Owner *self)
{
    Device *device = self->device;
    unsigned char state = device->state;
    FUN_00103628(device, 0);
    device->state = 0;
    self->device->refresh();
    device = self->device;
    FUN_00103628(device, state);
    device->state = state;
}
