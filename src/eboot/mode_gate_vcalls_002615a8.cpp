/* HSTMATCH module=EBOOT.BIN start=0x002615a8 end=0x00261670 symbol=FUN_002615a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
class G {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12(int v);
};

class S {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual int a8();
    char pad0[0x60 - 4];
    int f60;
    unsigned char f64;
};

extern G *DAT_003386c0;
extern "C" void FUN_001031e8(S *s);

extern "C" void FUN_002615a8(S *s)
{
    if (s->f60 == 2)
        return;
    if (s->f64 != 0)
        goto T4;
    if (s->f60 == 3)
        goto M;
T4:
    if (s->f60 != 4)
        goto N;
M:
    DAT_003386c0->g12(1);
N:
    if (s->f64 != 0) {
        if (s->a8() != 0)
            DAT_003386c0->g12(1);
    }
    if (s->a8() != 0)
        FUN_001031e8(s);
}
