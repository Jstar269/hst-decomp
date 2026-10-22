/* HSTMATCH module=EBOOT.BIN start=0x00184fac end=0x001851e0 symbol=FUN_00184fac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the first call takes a third argument (p3) that Ghidra dropped, so a2 is passed unchanged and the a2->s2 copy is deferred into the entry branch delay slot; names and types await human review. */
struct Target { char pad[0x24]; int f24; int f28; };
struct Pair { Target *t; int v; };
struct Sub { char pad[0xf8]; int f0f8; char pad1[0x138 - 0xfc]; int f138; };
struct Obj {
    char pad[0x244c];
    Pair pair;
    char pad2[0x2804 - 0x2454];
    Sub *sub;
};
struct Info { char pad[100]; signed char v : 4; };
struct Flags { char pad[8]; unsigned char b8, b9, b10; };
struct Cfg { char pad[0x59e]; Flags flags; };

extern "C" {
extern Info *DAT_00338b08;
extern int FUN_001fea10(int, int, int);
extern void FUN_0010d4a8(Sub *);
extern Cfg *FUN_0016bc70(void);
extern Info *FUN_000d8c24(Info *, int, int);
extern void FUN_000ffb3c(Target *, int);

void FUN_00184fac(Obj *o, int mode, int p3)
{
    Sub *sub = o->sub;
    switch (mode) {
    case 0:
        sub->f0f8 = FUN_001fea10(3, 0, p3);
        sub->f138 = 0;
        FUN_0010d4a8(sub);
        break;
    case 1:
        sub->f0f8 = FUN_001fea10(1, 0, p3);
        sub->f138 = 0;
        FUN_0010d4a8(sub);
        break;
    case 2:
        sub->f0f8 = FUN_001fea10(0, 0, p3);
        sub->f138 = 0;
        FUN_0010d4a8(sub);
        break;
    case 3:
        sub->f0f8 = FUN_001fea10(0, 0, p3);
        sub->f138 = 0;
        FUN_0010d4a8(sub);
        break;
    case 4:
        break;
    }
    Pair *p = &o->pair;
    Flags *fl = &FUN_0016bc70()->flags;
    switch (mode) {
    case 0: {
        Info *r = FUN_000d8c24(DAT_00338b08, 1, p3);
        if (fl->b8 != 0 && r != 0 && r->v == 1) {
            FUN_000ffb3c(p->t, 0);
            int v = p->v + 1;
            Target *t = p->t;
            t->f24 = v;
            t->f28 = v;
        } else {
            FUN_000ffb3c(p->t, 1);
        }
        break;
    }
    case 2:
        if (fl->b9 != 0 && p3 != 0) {
            FUN_000ffb3c(p->t, 0);
            int v = p->v;
            Target *t = p->t;
            t->f24 = v;
            t->f28 = v;
        } else {
            FUN_000ffb3c(p->t, 1);
        }
        break;
    case 3:
        if (fl->b10 != 0 && p3 != 0) {
            FUN_000ffb3c(p->t, 0);
            int v = p->v;
            Target *t = p->t;
            t->f24 = v;
            t->f28 = v;
        } else {
            FUN_000ffb3c(p->t, 1);
        }
        break;
    default:
        FUN_000ffb3c(p->t, 1);
        break;
    }
}
}
