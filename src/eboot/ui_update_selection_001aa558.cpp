/* HSTMATCH module=EBOOT.BIN start=0x001aa558 end=0x001aa770 symbol=FUN_001aa558 lang=c++ */
/* Hand-written reconstruction from the disassembly (sibling of ui_state_enter_001aa450.cpp and update_slots_001aa770.cpp); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

struct Single {
    char pad[0x2c4];
    int cur;
};

struct Info {
    char pad[10];
    short a;
    short b;
    short c;
};

struct List {
    char pad[0x10];
    void **data;
    int count;
};

struct Link {
    char pad[0x24];
    int f24;
    int f28;
};

struct Obj {
    char pad[0x3f4];
    List *list;
};

struct Slot {
    void *w;
};

extern "C" {
extern int DAT_002e20a0;
extern int DAT_002e20a4;
extern void *DAT_0034a7ec;
extern void FUN_000ffb3c(void *, int);
extern Single *FUN_0019d474();
extern int FUN_001a49dc(Single *, int);
extern int FUN_001a4b74(Single *, int);
extern Info *FUN_0027edbc(void *, int);
}

inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001aa558(Obj *self)
{
    Single *c = FUN_0019d474();
    int n = FUN_001a49dc(FUN_0019d474(), c->cur);
    int sel = Clamp(n - 1, DAT_002e20a0, DAT_002e20a4);

    Info *info = FUN_0027edbc(DAT_0034a7ec, n);
    int b_val = info->b;
    int c_val = info->c;
    int a_val = info->a;

    List *l = self->list;
    int i = 0;
    if (l->count > 0) {
        do {
            FUN_000ffb3c(l->data[i], i != sel);
            i++;
        } while (i < l->count);
    }

    for (int j = 0, off1 = 0; j < 5; ++j, off1 += 20) {
        char *p = (char *)self + (off1 + 300);
        Slot *s = (Slot *)(p + 32);
        if (j < b_val) {
            FUN_000ffb3c(s->w, 0);
        } else {
            FUN_000ffb3c(s->w, 1);
        }
    }

    for (int k = 0, off2 = 0; k < 5; ++k, off2 += 20) {
        char *p = (char *)self + (off2 + 400);
        Slot *s = (Slot *)(p + 32);
        if (k < c_val) {
            FUN_000ffb3c(s->w, 0);
        } else {
            FUN_000ffb3c(s->w, 1);
        }
    }

    FUN_000ffb3c(*(void **)((char *)self + 532), 0);
    Link *link = *(Link **)((char *)self + 532);
    void **p1 = (void **)((char *)self + 292);
    int sum = link->f28 + a_val;
    void **p2 = (void **)((char *)self + 312);
    link->f24 = sum;
    if (FUN_001a4b74(FUN_0019d474(), 2)) {
        FUN_000ffb3c(*p1, 0);
        FUN_000ffb3c(*p2, 0);
    } else {
        FUN_000ffb3c(*p1, 1);
        FUN_000ffb3c(*p2, 1);
    }
}
