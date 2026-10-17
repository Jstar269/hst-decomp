/* HSTMATCH module=hstp_trans_main.prx start=0x0020a940 end=0x0020a9c0 symbol=FUN_0020a940 lang=c++ */
/* Clone of src/eboot/enable_six_widgets_001fc228.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj;
extern "C" int FUN_00048984(Obj *o);
extern "C" void FUN_00105470(void *p, int v);
extern "C" void FUN_00108a2c(Obj *o);
struct Obj {
    char pad[0x60];
    void *w0, *w1, *w2, *w3, *w4, *w5;
};
extern "C" void FUN_0020a940(Obj *o)
{
    if (FUN_00048984(o) != 0) {
        FUN_00105470(o->w0, 1);
        FUN_00105470(o->w1, 1);
        FUN_00105470(o->w2, 1);
        FUN_00105470(o->w3, 1);
        FUN_00105470(o->w4, 1);
        FUN_00105470(o->w5, 1);
    }
    FUN_00108a2c(o);
}
