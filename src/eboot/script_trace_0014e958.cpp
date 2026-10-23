/* HSTMATCH module=EBOOT.BIN start=0x0014e958 end=0x0014ea74 symbol=FUN_0014e958 lang=c++ helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (near miss wip/script_trace_0014e958.cpp, completed with its same-file static helper FUN_0014c610 defined in front of it and placed at its own retail address by helpers=; callee prototype (Obj*, float, Node*) and the kind read moved first); exact match verified; names and types await human review. */
struct Thing { char pad[8]; int kind; };
struct Node { char pad[0x18]; int depth; Thing *thing; };
struct Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual int m5();
};
struct Out { int v; };

extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc358[];
extern "C" {
static void FUN_0014c610(...) {}
void FUN_0014f3cc(Out *, int *, Thing **);
int FUN_0014e11c(Obj *, float, Node *);
void FUN_0014f43c(Out *, int *, Thing ***, int *);

int FUN_0014e958(Obj *self, Node *node, float f)
{
    int two;
    Out o1;
    Thing *thing;
    Out o2;
    Thing **pt;
    int kind = node->thing->kind;
    thing = node->thing;
    FUN_0014f3cc(&o1, &node->depth, &thing);
    if (kind == 1) {
        return FUN_0014e11c(self, f, node);
    }
    if (DAT_003402f0 != 0) {
        if (DAT_003402f0 != 0) {
            FUN_0014c610(DAT_002dc240);
            for (int i = 0; i < node->depth + 1; i++) {
                FUN_0014c610(DAT_002dc24c);
            }
        }
        FUN_0014c610(DAT_002dc358, self->m5());
    }
    two = 2;
    pt = &node->thing;
    FUN_0014f43c(&o2, &node->depth, &pt, &two);
    return 0;
}
}
