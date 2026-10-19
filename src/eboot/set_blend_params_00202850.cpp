/* HSTMATCH module=EBOOT.BIN start=0x00202850 end=0x002028d8 symbol=FUN_00202850 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x380];
    float f380;
    float f384;
    float f388;
    float f38c;
};

extern "C" void FUN_00202850(Obj *o, int mode)
{
    switch (mode) {
    case 0:
    case 2:
        o->f380 = 500.0f;
        o->f384 = 400.0f;
        o->f38c = 133.33333f;
        break;
    case 1:
        o->f380 = 700.0f;
        o->f384 = 500.0f;
        o->f38c = 50.0f;
        break;
    case 3:
        o->f380 = 300.0f;
        o->f384 = 200.0f;
        o->f38c = 400.0f;
        break;
    }
}
