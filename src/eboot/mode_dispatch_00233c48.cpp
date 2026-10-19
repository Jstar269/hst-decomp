/* HSTMATCH module=EBOOT.BIN start=0x00233c48 end=0x00233d54 symbol=FUN_00233c48 lang=c++ rodata=0x002c9cc4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *DAT_0034a120;
extern "C" void *FUN_001d9cc4(void *);
extern "C" int FUN_002a17e0(void *);

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Obj {
    VObj *p0;
    VObj *p1;
    VObj *p2;
    int mode;
};

extern "C" void FUN_00233c48(Obj *o)
{
    switch (o->mode) {
    case 0:
    case 7:
    case 9:
        return;
    case 2:
    case 3:
        o->p2->v3();
        o->p0->v3();
        break;
    case 1:
    case 4:
    case 5:
    case 6:
    case 8:
    default:
        if (DAT_0034a120 != 0 && FUN_001d9cc4(DAT_0034a120) != 0 && FUN_002a17e0(FUN_001d9cc4(DAT_0034a120)) != 0) {
        } else {
            if ((unsigned)(o->mode - 4) < 2) {
                o->p1->v2();
                o->p1->v3();
            }
        }
        o->p0->v3();
        break;
    }
}
