/* HSTMATCH module=EBOOT.BIN start=0x001fc228 end=0x001fc2a8 symbol=FUN_001fc228 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj;
extern "C" int FUN_000487f4(Obj *o);
extern "C" void FUN_000ffb3c(void *p, int v);
extern "C" void FUN_00103128(Obj *o);
struct Obj {
    char pad[0x60];
    void *w0, *w1, *w2, *w3, *w4, *w5;
};
extern "C" void FUN_001fc228(Obj *o)
{
    if (FUN_000487f4(o) != 0) {
        FUN_000ffb3c(o->w0, 1);
        FUN_000ffb3c(o->w1, 1);
        FUN_000ffb3c(o->w2, 1);
        FUN_000ffb3c(o->w3, 1);
        FUN_000ffb3c(o->w4, 1);
        FUN_000ffb3c(o->w5, 1);
    }
    FUN_00103128(o);
}
