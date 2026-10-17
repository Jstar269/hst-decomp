/* HSTMATCH module=hstp_trans_main.prx start=0x002b0a68 end=0x002b0b44 symbol=FUN_002b0a68 lang=c++ */
/* Clone of src/eboot/reset_state_by_flags_002a165c.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: restructured the flag-state ladder into an if/else chain and regrouped the sum as s + (n*4+0xf) and typed the callee float parameters; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x1dc];
    int mode;
    char pad1[4];
    unsigned char fa;
    unsigned char fb;
};
extern "C" void FUN_002b07a4(Obj *o, int a, int b);
extern "C" void FUN_00059ac0(Obj *o, int a, int b);
extern "C" void FUN_00059c1c(float f, Obj *o, int a);
extern "C" void FUN_00059ba8(float f, Obj *o, int a);
extern "C" void FUN_00059d68(Obj *o, int a);
extern "C" void FUN_002b0a68(Obj *o, int n)
{
    int s;
    if (o->fa != 0 && o->fb != 0) {
        s = 2;
    } else if (o->fa != 0) {
        s = 3;
    } else if (o->fb != 0) {
        s = 1;
    } else {
        s = 0;
    }
    if (n != 0) {
        if (s == 1) {
            s = 0;
        } else if (s == 2) {
            s = 3;
        }
    }
    o->mode = n;
    FUN_002b07a4(o, 0, s + (n * 4 + 0xf));
    FUN_00059ac0(o, 0, 0);
    FUN_00059c1c(0.0f, o, 0);
    FUN_00059ba8(1.0f, o, 0);
    FUN_00059d68(o, 0);
}
