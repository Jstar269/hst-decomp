/* HSTMATCH module=EBOOT.BIN start=0x001ad350 end=0x001ad604 symbol=FUN_001ad350 lang=c++ */

struct Mgr {
    char pad[0x300];
    int f300;
    int f304;
    int pad308;
    int f30c;
    char pad310[0x388 - 0x310];
    int f388;
};

struct Elem {
    char pad[0x24];
    int f24;
    int f28;
};

struct Item {
    char pad[0xf8];
    void *f_f8;
    char padfc[0x138 - 0xfc];
    int f_138;
};

class SubObj {
public:
    virtual void v0();
    virtual void Method(int);
};

struct Obj {
    char pad[0x914];
    SubObj *sub_914;
};

extern "C" {
void *FUN_0019d474();
int FUN_001a49f4(void *, int);
void *FUN_001fea10(int, int, int);
void FUN_0010d4a8(Item *);
void FUN_000ffb3c(Elem *, int);
void FUN_0010b980(SubObj *, int, int);
void FUN_001ad350(Obj *self, bool flag);
}

extern "C" void FUN_001ad350(Obj *self, bool flag)
{
    int iVar1;
    int iVar4;
    bool is_neg1;

    iVar1 = ((Mgr *)FUN_0019d474())->f300;
    int s7 = ((Mgr *)FUN_0019d474())->f304;
    int s0 = FUN_001a49f4(FUN_0019d474(), iVar1);
    iVar4 = ((Mgr *)FUN_0019d474())->f30c;
    FUN_0019d474();
    is_neg1 = (s0 == -1);

    Item **s1 = (Item **)((char *)self + 2156);
    if (is_neg1) {
        void *uVar3 = FUN_001fea10(19, 0, 5);
        Item *item = s1[1];
        item->f_f8 = uVar3;
        item->f_138 = 1;
        FUN_0010d4a8(item);
    } else {
        void *uVar3 = FUN_001fea10(5, 0, s0);
        Item *item = s1[1];
        item->f_f8 = uVar3;
        item->f_138 = 1;
        FUN_0010d4a8(item);
    }

    int i = 0;
    int s3 = 0;
    do {
        int off2 = s3 + 1420;
        int off1 = s3 + 1240;
        Elem **s2 = (Elem **)((char *)self + off2 + 36);
        Elem **s1_loop = (Elem **)((char *)self + off1 + 36);
        int limit = ((Mgr *)FUN_0019d474())->f388;
        s0 = s7 + i;
        if (s0 < limit) {
            void *m = FUN_0019d474();
            int s6 = FUN_001a49f4(m, s0);
            bool s8 = (s6 == -1);
            FUN_000ffb3c(*s2, 0);
            if (s8) {
                Elem *e = *s2;
                e->f24 = e->f28 + 8;
            } else {
                Elem *e = *s2;
                e->f24 = e->f28 + s6;
            }
            if (iVar4 == s0) {
                FUN_000ffb3c(*s1_loop, 0);
                Elem *e = *s1_loop;
                e->f24 = e->f28;
            } else {
                FUN_000ffb3c(*s1_loop, 0);
                Elem *e = *s1_loop;
                e->f24 = e->f28 + 1;
            }
        } else {
            FUN_000ffb3c(*s2, 1);
            FUN_000ffb3c(*s1_loop, 1);
        }
        i++;
        s3 += 20;
    } while (i < 9);

    Elem **pe4ac = (Elem **)((char *)self + 1196);
    Elem **pe4c0 = (Elem **)((char *)self + 1216);
    Elem **pe4d4 = (Elem **)((char *)self + 1236);

    if (flag) {
        FUN_000ffb3c(*pe4ac, 0);
        if (is_neg1) {
            FUN_000ffb3c(*pe4c0, 1);
            FUN_000ffb3c(*pe4d4, 1);
        } else {
            FUN_000ffb3c(*pe4c0, 0);
            FUN_000ffb3c(*pe4d4, 0);
        }
    } else {
        FUN_000ffb3c(*pe4ac, 1);
        FUN_000ffb3c(*pe4c0, 1);
        FUN_000ffb3c(*pe4d4, 1);
    }

    if (flag) {
        self->sub_914->Method(0);
        FUN_0010b980(self->sub_914, iVar1 - s7, 0);
    }
}
// near miss from lane ag2 (unreviewed)
