/* HSTMATCH module=EBOOT.BIN start=0x002054b0 end=0x00205558 symbol=FUN_002054b0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad0[0xc4];
    float fc4;
    char pad1[0x8];
    float fd0;
};

extern "C" void FUN_00057b58(float, Obj *, int, int);
extern "C" void FUN_00058ddc(Obj *, int, int);
extern "C" void FUN_00058ec4(float, Obj *, int);
extern "C" void FUN_00058f38(Obj *, float, int);
extern "C" void FUN_0005f110(float, Obj *);
extern "C" void FUN_00059084(Obj *, int);

extern "C" void FUN_002054b0(Obj *o, int a, int b, float t)
{
    if (o != 0) {
        FUN_00057b58(0.0f, o, 0, a);
        FUN_00058ddc(o, b, -1);
        FUN_00058ec4(1.0f, o, -1);
        o->fc4 = 1.0f;
        FUN_00058f38(o, t, -1);
        FUN_0005f110(t, o);
        FUN_00059084(o, -1);
        o->fd0 = o->fc4;
    }
}
