/* HSTMATCH module=EBOOT.BIN start=0x0014d2d0 end=0x0014d3fc symbol=FUN_0014d2d0 lang=c++ helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (near miss wip/script_factory_0014d2d0.cpp, completed with its same-file static helper FUN_0014c610 defined in front of it and placed at its own retail address by helpers=; parameters reordered (float first)); exact match verified; names and types await human review. */
struct Seq {
    char pad[0x18];
    int depth;
};
struct Rule {
    char pad[8];
    float f8;
};
extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc25c[];
}
extern "C" {
static void FUN_0014c610(...) {}
}
class C_0014c8cc {
public:
    virtual ~C_0014c8cc();
    virtual int Init(float dt, Seq *seq) = 0;
};
class C_0014d3fc : public C_0014c8cc {
public:
    C_0014d3fc(float v) : f4(v) {}
    virtual ~C_0014d3fc();
    virtual int Init(float dt, Seq *seq);
    float f4;
};
extern "C" C_0014c8cc *FUN_0014d2d0(float dt, Rule *self, Seq *seq)
{
    if (DAT_003402f0) {
        if (DAT_003402f0) {
            FUN_0014c610(DAT_002dc240);
            for (int i = 0; i < seq->depth + 1; i++) FUN_0014c610(DAT_002dc24c);
        }
        FUN_0014c610(DAT_002dc25c, (double)self->f8);
    }
    C_0014c8cc *c = new C_0014d3fc(self->f8);
    if (c->Init(dt, seq)) {
        if (c)
            delete c;
        return 0;
    }
    return c;
}
