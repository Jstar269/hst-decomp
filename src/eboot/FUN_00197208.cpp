/* HSTMATCH module=EBOOT.BIN start=0x00197208 end=0x001972d0 symbol=FUN_00197208 lang=c++ data=0x002e1608 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 30 strings, 0x002e1608-0x002e17a8) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
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
extern "C" char *DAT_002e1730[] = {
    "btn_juji0",
    "btn_juji1",
    "btn_juji2",
    "btn_juji3",
    "btn_juji4",
    "btn_juji5",
    "btn_analog0",
    "btn_analog1",
    "btn_analog2",
    "btn_analog3",
    "btn_analog4",
    "btn_analog5",
    "btn0",
    "btn1",
    "btn2",
    "btn3",
    "btn4",
    "btn5",
    "btn_bg0",
    "btn_bg1",
    "btn_bg2",
    "btn_bg3",
    "btn_bg4",
    "btn_bg5",
    "btn_bg6",
    "btn_bg7",
    "btn_bg8",
    "btn_bg9",
    "btn_bg10",
    "btn_bg11",
};
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
