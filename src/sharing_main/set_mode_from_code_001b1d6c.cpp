/* HSTMATCH module=hstp_trans_main.prx start=0x001b1d6c end=0x001b1db4 symbol=FUN_001b1d6c lang=c++ */
/* Clone of src/eboot/set_mode_from_code_001a47a0.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x2ec];
    int f2ec;
};

extern "C" void FUN_001b1d6c(Obj *o, int code)
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
