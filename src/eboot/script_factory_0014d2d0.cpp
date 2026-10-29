/* HSTMATCH module=EBOOT.BIN start=0x0014d2d0 end=0x0014d3fc symbol=FUN_0014d2d0 lang=c++ helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (near miss wip/script_factory_0014d2d0.cpp, completed with its same-file static helper FUN_0014c610 defined in front of it and placed at its own retail address by helpers=; parameters reordered (float first)); exact match verified; names and types await human review. */
#include "hst/script_node.h"
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
    virtual int Init(float arg, ScriptRunCtx *ctx) = 0;
};
class C_0014d3fc : public C_0014c8cc {
public:
    C_0014d3fc(float v) : f4(v) {}
    virtual ~C_0014d3fc();
    virtual int Init(float arg, ScriptRunCtx *ctx);
    float f4;
};
/* Creates the float-carrying command object for a node and initialises it; returns 0 (and deletes it) if init fails. */
extern "C" C_0014c8cc *FUN_0014d2d0(float arg, FloatNode *node, ScriptRunCtx *ctx)
{
    if (DAT_003402f0) {
        if (DAT_003402f0) {
            FUN_0014c610(DAT_002dc240);
            for (int i = 0; i < ctx->depth + 1; i++) FUN_0014c610(DAT_002dc24c);
        }
        FUN_0014c610(DAT_002dc25c, (double)node->value);
    }
    C_0014c8cc *c = new C_0014d3fc(node->value);
    if (c->Init(arg, ctx)) {
        if (c)
            delete c;
        return 0;
    }
    return c;
}
