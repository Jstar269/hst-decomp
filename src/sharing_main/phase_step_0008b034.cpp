/* HSTMATCH module=hstp_trans_main.prx start=0x0008b034 end=0x0008b104 symbol=FUN_0008b034 lang=c++ */
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

extern Global *DAT_003751d4;
extern int DAT_003e95c4;
extern "C" int FUN_0013bc98(int);
extern "C" void FUN_0008c400(Obj *);
extern "C" int FUN_0008c498(Obj *);

extern "C" void FUN_0008b034(Obj *self)
{
    switch (self->phase) {
    case 0:
        self->counter = 0;
        self->phase++;
        break;
    case 1:
        self->counter++;
        if (FUN_0013bc98(DAT_003e95c4) != 0 || (self->counter >= 30 && DAT_003751d4->flags.b23 == 0)) {
            self->phase++;
        }
        break;
    case 2:
        FUN_0008c400(self);
        if (FUN_0008c498(self) != 0) {
            self->f40 = 3;
        }
        break;
    }
}
