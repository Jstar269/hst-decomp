/* HSTMATCH module=EBOOT.BIN start=0x002a43d4 end=0x002a4488 symbol=FUN_002a43d4 lang=c++ rodata=0x002cc064 */
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

extern "C" void FUN_0005f1e8(void *self, int zero);

extern "C" void FUN_002a43d4(Self *self)
{
    switch (self->mode) {
    case 0:
    case 1:
    case 3:
    case 4:
        FUN_0005f1e8(self, 0);
        self->a->v3();
        break;
    case 2: {
        Base **pair;

        FUN_0005f1e8(self, 0);
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
