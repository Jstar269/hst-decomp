/* HSTMATCH module=EBOOT.BIN start=0x001cd3e4 end=0x001cd440 symbol=FUN_001cd3e4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: state != 4 held in an early bool local); names and types await human review. */
struct Inner {
    char pad[0x6d];
    unsigned char f6d;
};
struct Mid {
    char pad[0x20];
    Inner *inner;
    char pad2[0x3c];
    unsigned char f60;
};
struct Obj {
    char pad[0xc4];
    int state;
    char pad2[0x15c - 0xc4 - 4];
    Mid *mid;
};
extern int DAT_0033b580;
extern "C" void FUN_0012de6c(int, int, int, int);

extern "C" void FUN_001cd3e4(Obj *o)
{
    bool stateIsNot4 = o->state != 4;
    Mid *m = o->mid;
    m->f60 = 0;
    m->inner->f6d = 1;
    if (DAT_0033b580 != 0 && stateIsNot4) {
        FUN_0012de6c(DAT_0033b580, 0, 0, 0);
    }
}
