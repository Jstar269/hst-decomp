/* HSTMATCH module=hstp_trans_main.prx start=0x001f4334 end=0x001f4394 symbol=FUN_001f4334 lang=c++ */
/* Clone of src/eboot/set_two_widgets_flag_001e611c.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the two member addresses are taken into locals before the branch; names and types await human review. */
extern "C" void FUN_00105470(void *p, int v);
struct Holder {
    void *w;
    int pad[4];
    void Set(int v) { FUN_00105470(w, v); }
};
struct Obj {
    char pad0[0x1a84];
    Holder h0;
    Holder h1;
};
extern "C" void FUN_001f4334(Obj *o, int enable)
{
    Holder *a = &o->h0;
    Holder *b = &o->h1;
    if (enable != 0) {
        a->Set(0);
        b->Set(0);
    } else {
        a->Set(1);
        b->Set(1);
    }
}
