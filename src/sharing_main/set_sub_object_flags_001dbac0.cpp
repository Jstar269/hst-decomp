/* HSTMATCH module=hstp_trans_main.prx start=0x001dbac0 end=0x001dbb1c symbol=FUN_001dbac0 lang=c++ */
/* Clone of src/eboot/set_sub_object_flags_001cd3e4.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_003e48c0;
extern "C" void FUN_0013936c(int, int, int, int);

extern "C" void FUN_001dbac0(Obj *o)
{
    bool stateIsNot4 = o->state != 4;
    Mid *m = o->mid;
    m->f60 = 0;
    m->inner->f6d = 1;
    if (DAT_003e48c0 != 0 && stateIsNot4) {
        FUN_0013936c(DAT_003e48c0, 0, 0, 0);
    }
}
