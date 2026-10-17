/* HSTMATCH module=EBOOT.BIN start=0x0029acec end=0x0029ade8 symbol=FUN_0029acec lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Res;
struct Node {
    int pad0;
    int count;
    int mode;
};
struct Self {
    char pad[0x3c];
    Node *node;
};
struct Hook {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
};
extern Res *DAT_003415ac;
extern Hook *DAT_003386c0;
extern char DAT_0034179c;
extern "C" int FUN_001155c0(Res *r);
extern "C" int FUN_001156d4(Res *r);
extern "C" void FUN_001b1c44(void *p, int v);
extern "C" void FUN_00295cdc(Res *r);
extern "C" void FUN_0029ade8(Node *n, int v);
extern "C" void FUN_0029acec(Self *self)
{
    Node *n = self->node;
    switch (n->mode) {
    case 1:
        if (FUN_001155c0(DAT_003415ac) != 0) {
            FUN_001b1c44(&DAT_0034179c, 3);
            FUN_0029ade8(n, 0);
            FUN_00295cdc(DAT_003415ac);
        }
        break;
    case 2:
        if (FUN_001155c0(DAT_003415ac) != 0) {
            if (FUN_001156d4(DAT_003415ac) == 0) {
                FUN_0029ade8(n, 4);
            } else {
                FUN_0029ade8(n, 0);
            }
            FUN_00295cdc(DAT_003415ac);
        }
        break;
    }
    if (DAT_003386c0 != 0) {
        DAT_003386c0->v11();
    }
    n->count++;
}
