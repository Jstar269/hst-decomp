/* HSTMATCH module=EBOOT.BIN start=0x001532e4 end=0x001533b4 symbol=FUN_001532e4 lang=c++ data=0x002dc73c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc73c-0x002dc74b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Script-command factory: optional trace hook and debug print (0x14d044, variadic stub 0x14fd94), call 0x1ccf40
   on the manager global, then `new` a 4-byte command object (base vtable 0x3083cc = C_0014c8cc, derived vtable
   0x308ac0 whose slot 0 is the deleting destructor 0x1533b4 and slot 1 the init method 0x153410), run its
   init(t, ctx) and on failure delete it (explicit null test plus delete's own) and return 0. The float is
   declared before the context pointer: EABI gives the same registers either way, but the order of the
   prologue moves and of the call-argument setup follows the declaration order. Names provisional. */
struct Ctx_001532e4;
struct Mgr_001532e4;
extern "C" {
extern unsigned char DAT_003402f0;
extern Mgr_001532e4 *DAT_0034a114;
void FUN_0014d044(Ctx_001532e4 *ctx);
void FUN_0014fd94(char *fmt, ...);
void FUN_001ccf40(Mgr_001532e4 *m);
}
class C_0014c8cc {
public:
    virtual ~C_0014c8cc();
    virtual int Init(float t, Ctx_001532e4 *ctx) = 0;
};
class C_001533b4 : public C_0014c8cc {
public:
    virtual ~C_001533b4();
    virtual int Init(float t, Ctx_001532e4 *ctx);
};
extern "C" C_0014c8cc *FUN_001532e4(void *self, float t, Ctx_001532e4 *ctx)
{
    if (DAT_003402f0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("CompleteStage\n");
    }
    FUN_001ccf40(DAT_0034a114);
    C_0014c8cc *c = new C_001533b4;
    if (c->Init(t, ctx)) {
        if (c)
            delete c;
        return 0;
    }
    return c;
}
// EXACT (hstmatch) only with --symbols-extra holding `__vt__10C_001533b4 = 0x00308ac0;` (the derived class's
// vtable, stored by the inline constructor of `new C_001533b4`). Needs that entry in symbols/EBOOT.BIN.txt;
// then move to src/eboot/cmd_factory_001532e4.cpp. The family member 0x1554d0 needs its own derived vtable symbol.
