/* HSTMATCH module=hstp_trans_main.prx start=0x0015a960 end=0x0015aa7c symbol=FUN_0015a960 lang=c++ helpers=FUN_00157280@0x00157280-0x001572ac */
/* Clone of src/eboot/script_trace_0014e958.cpp (hstclone.py tag a0db26h2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (near miss wip/script_trace_0015a960.cpp, completed with its same-file static helper FUN_00157280 defined in front of it and placed at its own retail address by helpers=; callee prototype (Obj*, float, Node*) and the kind read moved first); exact match verified; names and types await human review. */
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

extern unsigned char DAT_003e9630;
extern char DAT_003836b8[];
extern char DAT_003836c4[];
extern char DAT_00383840[];
extern "C" {
static void FUN_00157280(...) {}
void FUN_0015b3cc(Out *, int *, Thing **);
int FUN_00159fc4(Obj *, float, Node *);
void FUN_0015b43c(Out *, int *, Thing ***, int *);

int FUN_0015a960(Obj *self, Node *node, float f)
{
    int two;
    Out o1;
    Thing *thing;
    Out o2;
    Thing **pt;
    int kind = node->thing->kind;
    thing = node->thing;
    FUN_0015b3cc(&o1, &node->depth, &thing);
    if (kind == 1) {
        return FUN_00159fc4(self, f, node);
    }
    if (DAT_003e9630 != 0) {
        if (DAT_003e9630 != 0) {
            FUN_00157280(DAT_003836b8);
            for (int i = 0; i < node->depth + 1; i++) {
                FUN_00157280(DAT_003836c4);
            }
        }
        FUN_00157280(DAT_00383840, self->m5());
    }
    two = 2;
    pt = &node->thing;
    FUN_0015b43c(&o2, &node->depth, &pt, &two);
    return 0;
}
}
