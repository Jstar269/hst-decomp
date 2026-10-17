/* HSTMATCH module=hstp_trans_main.prx start=0x00213d18 end=0x00213dc0 symbol=FUN_00213d18 lang=c++ */
/* Clone of src/eboot/setup_object_sequence_002054b0.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad0[0xc4];
    float fc4;
    char pad1[0x8];
    float fd0;
};

extern "C" void FUN_000587ac(float, Obj *, int, int);
extern "C" void FUN_00059ac0(Obj *, int, int);
extern "C" void FUN_00059ba8(float, Obj *, int);
extern "C" void FUN_00059c1c(Obj *, float, int);
extern "C" void FUN_0005ff00(float, Obj *);
extern "C" void FUN_00059d68(Obj *, int);

extern "C" void FUN_00213d18(Obj *o, int a, int b, float t)
{
    if (o != 0) {
        FUN_000587ac(0.0f, o, 0, a);
        FUN_00059ac0(o, b, -1);
        FUN_00059ba8(1.0f, o, -1);
        o->fc4 = 1.0f;
        FUN_00059c1c(o, t, -1);
        FUN_0005ff00(t, o);
        FUN_00059d68(o, -1);
        o->fd0 = o->fc4;
    }
}
