/* HSTMATCH module=EBOOT.BIN start=0x0014ba88 end=0x0014bee4 symbol=FUN_0014ba88 rodata=0x002c1918 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Expr {
    virtual void v0();
    virtual void v1();
    virtual int IsFloat();
    virtual int GetInt(int ctx);
    virtual float GetFloat(int ctx);
};
struct Op {
    int pad0;
    int kind;
};
union Num {
    float f;
    int i;
};
struct Result {
    void *vt;
    int type;
    float val;
};
extern "C" {
extern char DAT_00308460[];
extern char DAT_003083f0[];
void *FUN_00000bcc(unsigned);
}

extern "C" void FUN_0014ba88(Expr *a, Op *op, Expr *b, int ctx)
{
    int type = 1;
    Num r;
    if (a->IsFloat() || b->IsFloat()) {
        Num va;
        if (a->IsFloat())
            va.f = a->GetFloat(ctx);
        else
            va.f = (float)a->GetInt(ctx);
        Num vb;
        if (b->IsFloat())
            vb.f = b->GetFloat(ctx);
        else
            vb.f = (float)b->GetInt(ctx);
        switch (op->kind) {
        case 4:
            type = 2;
            r.f = va.f + vb.f;
            break;
        case 5:
            type = 2;
            r.f = va.f - vb.f;
            break;
        case 6:
            type = 2;
            r.f = va.f * vb.f;
            break;
        case 7:
            type = 2;
            r.f = va.f / vb.f;
            break;
        case 8:
            r.i = va.f == vb.f;
            break;
        case 9:
            r.i = va.f != vb.f;
            break;
        case 10:
            r.i = va.f > vb.f;
            break;
        case 11:
            r.i = va.f < vb.f;
            break;
        case 12:
            r.i = va.f >= vb.f;
            break;
        case 13:
            r.i = va.f <= vb.f;
            break;
        case 14:
            r.i = va.f && vb.f;
            break;
        case 15:
            r.i = va.f || vb.f;
            break;
        }
    } else {
        Num va2;
        va2.i = a->GetInt(ctx);
        Num vb2;
        vb2.i = b->GetInt(ctx);
        switch (op->kind) {
        case 4:
            r.i = va2.i + vb2.i;
            break;
        case 5:
            r.i = va2.i - vb2.i;
            break;
        case 6:
            r.i = va2.i * vb2.i;
            break;
        case 7:
            r.i = va2.i / vb2.i;
            break;
        case 8:
            r.i = va2.i == vb2.i;
            break;
        case 9:
            r.i = va2.i != vb2.i;
            break;
        case 10:
            r.i = va2.i > vb2.i;
            break;
        case 11:
            r.i = va2.i < vb2.i;
            break;
        case 12:
            r.i = va2.i >= vb2.i;
            break;
        case 13:
            r.i = va2.i <= vb2.i;
            break;
        case 14:
            r.i = va2.i && vb2.i;
            break;
        case 15:
            r.i = va2.i || vb2.i;
            break;
        }
    }
    Result *p = (Result *)FUN_00000bcc(12);
    if (p != 0) {
        p->vt = DAT_00308460;
        p->type = type;
        p->vt = DAT_003083f0;
        p->val = r.f;
    }
}
