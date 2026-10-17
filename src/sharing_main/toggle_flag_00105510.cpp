/* HSTMATCH module=hstp_trans_main.prx start=0x00105510 end=0x00105570 symbol=FUN_00105510 lang=c++ */
/* Clone of src/eboot/toggle_flag_000ffbdc.cpp (hstclone.py tag u4r1-3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Target {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct Obj {
    char pad[14];
    unsigned short flags;
    char pad2[16];
    Target *target;

    bool IsSet() const {
        return (flags & 2) != 0;
    }
};

extern "C" void FUN_00105510(Obj *self)
{
    if (self->IsSet() ^ true) {
        self->flags |= 2;
    } else {
        self->flags &= ~2;
    }
    if (self->target != 0) {
        self->target->m3();
    }
}
