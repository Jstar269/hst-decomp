/* HSTMATCH module=EBOOT.BIN start=0x002291cc end=0x002291f8 symbol=__ct__10C_002291ccFv */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Two 16-byte tree-like members (destroyed by different dtors 0x229b94 / 0x229a54 in 0x2291f8): word 0 and
   the root slot at +4 cleared, +12 points at the root slot. The member ctor writes through a local copy of
   `this`, which keeps `&y + 4` as a separate add (retail `addiu v0,a0,16; addiu v0,v0,4`). Names provisional. */
struct L_002291cc {
    int a;
    int b;
    int c;
    int *last;
    L_002291cc()
    {
        L_002291cc *self = this;
        self->a = 0;
        self->b = 0;
        self->last = &self->b;
    }
};
class C_002291cc {
public:
    L_002291cc x, y;
    C_002291cc();
};
C_002291cc::C_002291cc() {}
