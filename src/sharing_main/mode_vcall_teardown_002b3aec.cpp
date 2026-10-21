/* HSTMATCH module=hstp_trans_main.prx start=0x002b3aec end=0x002b3ba0 symbol=FUN_002b3aec lang=c++ rodata=0x002dc104 */
/* Clone of src/eboot/mode_vcall_teardown_002a43d4.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Self {
    char pad0[0x1b0];
    int mode;
    char pad1[0x1c8 - 0x1b4];
    Base *a;
    char pad2[0x1d4 - 0x1cc];
    Base **pair;
};

extern "C" void FUN_0005ffd8(void *self, int zero);

extern "C" void FUN_002b3aec(Self *self)
{
    switch (self->mode) {
    case 0:
    case 1:
    case 3:
    case 4:
        FUN_0005ffd8(self, 0);
        self->a->v3();
        break;
    case 2: {
        Base **pair;

        FUN_0005ffd8(self, 0);
        self->a->v3();
        pair = self->pair;
        pair[0]->v3();
        pair[1]->v3();
    }
    case 5:
    default:
        break;
    }
}
