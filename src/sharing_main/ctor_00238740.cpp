/* HSTMATCH module=hstp_trans_main.prx start=0x00238740 end=0x0023876c symbol=__ct__10C_00238740Fv */
/* Clone of src/eboot/ctor_002291cc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Two 16-byte tree-like members (destroyed by different dtors 0x229b94 / 0x229a54 in 0x2291f8): word 0 and
   the root slot at +4 cleared, +12 points at the root slot. The member ctor writes through a local copy of
   `this`, which keeps `&y + 4` as a separate add (retail `addiu v0,a0,16; addiu v0,v0,4`). Names provisional. */
struct L_00238740 {
    int a;
    int b;
    int c;
    int *last;
    L_00238740()
    {
        L_00238740 *self = this;
        self->a = 0;
        self->b = 0;
        self->last = &self->b;
    }
};
class C_00238740 {
public:
    L_00238740 x, y;
    C_00238740();
};
C_00238740::C_00238740() {}
