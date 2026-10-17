/* HSTMATCH module=EBOOT.BIN start=0x002291cc end=0x002291f8 symbol=__ct__10C_002291ccFv */
struct L_002291cc {
    int a;
    int b;
    int c;
    int *last;
    L_002291cc() : a(0), b(0), last(&b) {}
};
class C_002291cc {
public:
    L_002291cc x, y;
    C_002291cc();
};
C_002291cc::C_002291cc() {}
// MATCHED (2026-10-15): EXACT as src/eboot/ctor_002291cc.cpp; the member ctor writes through a local `L *self = this` copy.
