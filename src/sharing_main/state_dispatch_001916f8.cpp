/* HSTMATCH module=hstp_trans_main.prx start=0x001916f8 end=0x0019192c symbol=FUN_001916f8 lang=c++ */
/* Clone of src/eboot/state_dispatch_00184fac.cpp (hstclone.py tag fm1): addresses substituted; exact match verified; names and types await human review. */
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
extern Info *DAT_003e1e48;
extern int FUN_0020d1e0(int, int, int);
extern void FUN_00113a50(Sub *);
extern Cfg *FUN_00177e98(void);
extern Info *FUN_000dca74(Info *, int, int);
extern void FUN_00105470(Target *, int);

void FUN_001916f8(Obj *o, int mode, int p3)
{
    Sub *sub = o->sub;
    switch (mode) {
    case 0:
        sub->f0f8 = FUN_0020d1e0(3, 0, p3);
        sub->f138 = 0;
        FUN_00113a50(sub);
        break;
    case 1:
        sub->f0f8 = FUN_0020d1e0(1, 0, p3);
        sub->f138 = 0;
        FUN_00113a50(sub);
        break;
    case 2:
        sub->f0f8 = FUN_0020d1e0(0, 0, p3);
        sub->f138 = 0;
        FUN_00113a50(sub);
        break;
    case 3:
        sub->f0f8 = FUN_0020d1e0(0, 0, p3);
        sub->f138 = 0;
        FUN_00113a50(sub);
        break;
    case 4:
        break;
    }
    Pair *p = &o->pair;
    Flags *fl = &FUN_00177e98()->flags;
    switch (mode) {
    case 0: {
        Info *r = FUN_000dca74(DAT_003e1e48, 1, p3);
        if (fl->b8 != 0 && r != 0 && r->v == 1) {
            FUN_00105470(p->t, 0);
            int v = p->v + 1;
            Target *t = p->t;
            t->f24 = v;
            t->f28 = v;
        } else {
            FUN_00105470(p->t, 1);
        }
        break;
    }
    case 2:
        if (fl->b9 != 0 && p3 != 0) {
            FUN_00105470(p->t, 0);
            int v = p->v;
            Target *t = p->t;
            t->f24 = v;
            t->f28 = v;
        } else {
            FUN_00105470(p->t, 1);
        }
        break;
    case 3:
        if (fl->b10 != 0 && p3 != 0) {
            FUN_00105470(p->t, 0);
            int v = p->v;
            Target *t = p->t;
            t->f24 = v;
            t->f28 = v;
        } else {
            FUN_00105470(p->t, 1);
        }
        break;
    default:
        FUN_00105470(p->t, 1);
        break;
    }
}
}
