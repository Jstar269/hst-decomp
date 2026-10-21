/* HSTMATCH module=EBOOT.BIN start=0x0014d2d0 end=0x0014d3fc symbol=FUN_0014d2d0 lang=c++ */
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
static void FUN_0014c610(const char *fmt, ...) {}
extern "C" {
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
extern "C" C_0014c8cc *FUN_0014d2d0(Rule *self, float dt, Seq *seq)
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
// BLOCKED (lane sn2): this source reproduces retail except for placement. The retail loop keeps its counter in v1 ACROSS the
// `jal 0x14c610` calls (`move v1,zero ... addiu v1,v1,1 ... slt v0,v1,v0`), which MWCC only does when the callee is an EMPTY function
// defined EARLIER IN THE SAME TU (here: `static void FUN_0014c610(const char *, ...) {}`; retail's stub at 0x14c610 is in the same object).
// With that static stub the prologue (s1=self, s0=seq, s2=c), the counter in v1 and every other word match, but hstmatch reports
// MISPLACED (the helper is emitted in front and pushes the function to 0x14d2f8). With the stub only declared extern the counter
// takes a saved register (s0) and 23 words differ. The derived vtable symbol __vt__10C_0014d3fc = 0x0030837c was appended to symbols/EBOOT.BIN.txt.
// near miss from lane sn2 (unreviewed)
