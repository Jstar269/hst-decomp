/* HSTMATCH module=hstp_trans_main.prx start=0x00158db8 end=0x00158ee4 symbol=FUN_00158db8 lang=c++ helpers=FUN_00157280@0x00157280-0x001572ac */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT twin src/eboot/script_factory_0014d2d0.cpp: same source with the Sharing log stub FUN_00157280 defined static in front of it and placed at its own retail address by helpers=, Sharing strings, flag byte and class vtables); exact match verified; names and types await human review. */
/* Twin of EBOOT 0x14d2d0. Script "Wait" command factory: optional debug trace (indentation by sequence depth and the
   wait time), then a new command object (base vtable 0x3b1698, derived 0x3b1648) whose virtual Init (slot 1) gets
   the time and the sequence; a failed Init deletes it (virtual deleting dtor) and returns 0. Names provisional. */
struct Seq {
    char pad[0x18];
    int depth;
};
struct Rule {
    char pad[8];
    float f8;
};
extern "C" {
extern unsigned char DAT_003e9630;
extern char DAT_003836b8[];
extern char DAT_003836c4[];
extern char DAT_003836d4[];
}
extern "C" {
static void FUN_00157280(...) {}
}
class C_001583b4 {
public:
    virtual ~C_001583b4();
    virtual int Init(float dt, Seq *seq) = 0;
};
class C_00158ee4 : public C_001583b4 {
public:
    C_00158ee4(float v) : f4(v) {}
    virtual ~C_00158ee4();
    virtual int Init(float dt, Seq *seq);
    float f4;
};
extern "C" C_001583b4 *FUN_00158db8(float dt, Rule *self, Seq *seq)
{
    if (DAT_003e9630) {
        if (DAT_003e9630) {
            FUN_00157280(DAT_003836b8);
            for (int i = 0; i < seq->depth + 1; i++) FUN_00157280(DAT_003836c4);
        }
        FUN_00157280(DAT_003836d4, (double)self->f8);
    }
    C_001583b4 *c = new C_00158ee4(self->f8);
    if (c->Init(dt, seq)) {
        if (c)
            delete c;
        return 0;
    }
    return c;
}
