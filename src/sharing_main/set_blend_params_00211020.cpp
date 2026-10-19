/* HSTMATCH module=hstp_trans_main.prx start=0x00211020 end=0x002110a8 symbol=FUN_00211020 lang=c++ */
/* Clone of src/eboot/set_blend_params_00202850.cpp (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x380];
    float f380;
    float f384;
    float f388;
    float f38c;
};

extern "C" void FUN_00211020(Obj *o, int mode)
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
