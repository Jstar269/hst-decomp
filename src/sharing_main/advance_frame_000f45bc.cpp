/* HSTMATCH module=hstp_trans_main.prx start=0x000f45bc end=0x000f4618 symbol=FUN_000f45bc lang=c++ */
/* Clone of src/eboot/advance_frame_000eeef4.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: signed modulo 32 and inline setter target->Set(val); exact match verified; names and types await human review. */

extern "C" {
    extern int DAT_0037de4c;
}

struct Target {
    char pad[0x24];
    int f36;
    int f40;

    void Set(int val) {
        f36 = val;
        f40 = val;
    }
};

struct Owner {
    char pad0[0x54];
    unsigned char flag;
    char pad1[0x64 - 0x55];
    Target *target;
    char pad2[0x70 - 0x68];
    int counter;
};

extern "C" void FUN_00108a2c(Owner *);

extern "C" void FUN_000f45bc(Owner *self)
{
    if (self->flag != 0) {
        return;
    }
    self->counter = (self->counter + 1) % 32;
    self->target->Set(DAT_0037de4c + self->counter);
    FUN_00108a2c(self);
}
