/* HSTMATCH module=EBOOT.BIN start=0x000eeef4 end=0x000eef50 symbol=FUN_000eeef4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: signed modulo 32 and inline setter target->Set(val); exact match verified; names and types await human review. */

extern "C" {
    extern int DAT_002d7074;
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

extern "C" void FUN_00103128(Owner *);

extern "C" void FUN_000eeef4(Owner *self)
{
    if (self->flag != 0) {
        return;
    }
    self->counter = (self->counter + 1) % 32;
    self->target->Set(DAT_002d7074 + self->counter);
    FUN_00103128(self);
}
