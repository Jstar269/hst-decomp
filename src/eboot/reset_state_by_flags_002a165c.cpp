/* HSTMATCH module=EBOOT.BIN start=0x002a165c end=0x002a1738 symbol=FUN_002a165c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: restructured the flag-state ladder into an if/else chain and regrouped the sum as s + (n*4+0xf) and typed the callee float parameters; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x1dc];
    int mode;
    char pad1[4];
    unsigned char fa;
    unsigned char fb;
};
extern "C" void FUN_002a1398(Obj *o, int a, int b);
extern "C" void FUN_00058ddc(Obj *o, int a, int b);
extern "C" void FUN_00058f38(float f, Obj *o, int a);
extern "C" void FUN_00058ec4(float f, Obj *o, int a);
extern "C" void FUN_00059084(Obj *o, int a);
extern "C" void FUN_002a165c(Obj *o, int n)
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
    FUN_002a1398(o, 0, s + (n * 4 + 0xf));
    FUN_00058ddc(o, 0, 0);
    FUN_00058f38(0.0f, o, 0);
    FUN_00058ec4(1.0f, o, 0);
    FUN_00059084(o, 0);
}
