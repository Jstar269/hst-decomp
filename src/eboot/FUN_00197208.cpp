/* HSTMATCH module=EBOOT.BIN start=0x00197208 end=0x001972d0 symbol=FUN_00197208 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct Ctx {
    Obj *obj;
    int a[30];
    int b[30];
};

extern "C" Ctx *DAT_00341768;
extern "C" char DAT_002e17a8[];
extern "C" char DAT_002e17c8[];
extern "C" char *DAT_002e1730[];
extern "C" void FUN_00104118(void *, void *, int);
extern "C" Obj *FUN_001039d8(void *, void *, int);
extern "C" void *FUN_001026b8(Obj *, void *);

extern "C" void FUN_00197208(void)
{
    Ctx *c;
    Obj *o;
    int i;
    char **p;
    int *q;

    c = DAT_00341768;
    if (c != 0) {
        FUN_00104118(c->obj, DAT_002e17a8, 0);
        o = FUN_001039d8(c->obj, DAT_002e17c8, 0);
        i = 0;
        p = DAT_002e1730;
        q = (int *)c;
        do {
            int *r = (int *)FUN_001026b8(o, *p);
            q[1] = (int)r;
            i++;
            p++;
            q[31] = r[9];
            q++;
        } while (i < 30);
        c->obj->m2();
    }
}
