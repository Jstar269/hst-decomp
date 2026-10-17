/* HSTMATCH module=EBOOT.BIN start=0x00089974 end=0x00089a44 symbol=FUN_00089974 lang=c++ */
/* Clone of src/sharing_main/phase_step_0008b034.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Flags {
    signed char b01 : 2;
    signed char b23 : 2;
};
struct Global {
    char pad[0x8b];
    Flags flags;
};
struct Obj {
    char pad[0x40];
    int f40;
    int phase;
    int counter;
};

extern Global *DAT_002cfc8c;
extern int DAT_00340284;
extern "C" int FUN_001306e0(int);
extern "C" void FUN_0008ad40(Obj *);
extern "C" int FUN_0008add8(Obj *);

extern "C" void FUN_00089974(Obj *self)
{
    switch (self->phase) {
    case 0:
        self->counter = 0;
        self->phase++;
        break;
    case 1:
        self->counter++;
        if (FUN_001306e0(DAT_00340284) != 0 || (self->counter >= 30 && DAT_002cfc8c->flags.b23 == 0)) {
            self->phase++;
        }
        break;
    case 2:
        FUN_0008ad40(self);
        if (FUN_0008add8(self) != 0) {
            self->f40 = 3;
        }
        break;
    }
}
