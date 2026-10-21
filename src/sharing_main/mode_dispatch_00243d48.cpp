/* HSTMATCH module=hstp_trans_main.prx start=0x00243d48 end=0x00243e54 symbol=FUN_00243d48 lang=c++ rodata=0x002da284 */
/* Clone of src/eboot/mode_dispatch_00233c48.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *DAT_003f3458;
extern "C" void *FUN_001e7d7c(void *);
extern "C" int FUN_002b0bec(void *);

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

extern "C" void FUN_00243d48(Obj *o)
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
        if (DAT_003f3458 != 0 && FUN_001e7d7c(DAT_003f3458) != 0 && FUN_002b0bec(FUN_001e7d7c(DAT_003f3458)) != 0) {
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
