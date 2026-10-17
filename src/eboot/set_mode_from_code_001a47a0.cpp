/* HSTMATCH module=EBOOT.BIN start=0x001a47a0 end=0x001a47e8 symbol=FUN_001a47a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x2ec];
    int f2ec;
};

extern "C" void FUN_001a47a0(Obj *o, int code)
{
    switch (code) {
    case 2:
        o->f2ec = 0;
        break;
    case 4:
        o->f2ec = 1;
        break;
    case 6:
        o->f2ec = 2;
        break;
    default:
        o->f2ec = 1;
        break;
    }
}
