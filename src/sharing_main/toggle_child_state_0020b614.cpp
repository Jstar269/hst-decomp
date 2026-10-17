/* HSTMATCH module=hstp_trans_main.prx start=0x0020b614 end=0x0020b684 symbol=FUN_0020b614 lang=c++ */
/* Clone of src/eboot/toggle_child_state_001fcef4.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_00108f54(Device *, unsigned char);

extern "C" void FUN_0020b614(Owner *self)
{
    Device *device = self->device;
    unsigned char state = device->state;
    FUN_00108f54(device, 0);
    device->state = 0;
    self->device->refresh();
    device = self->device;
    FUN_00108f54(device, state);
    device->state = state;
}
