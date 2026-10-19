/* HSTMATCH module=hstp_trans_main.prx start=0x001b7b24 end=0x001b7d3c symbol=FUN_001b7b24 lang=c++ */
/* Clone of src/eboot/ui_update_selection_001aa558.cpp (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_00389970;
extern int DAT_00389974;
extern void *DAT_003f3b1c;
extern void FUN_00105470(void *, int);
extern Single *FUN_001aa91c();
extern int FUN_001b1fa8(Single *, int);
extern int FUN_001b2140(Single *, int);
extern Info *FUN_00290230(void *, int);
}

inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001b7b24(Obj *self)
{
    Single *c = FUN_001aa91c();
    int n = FUN_001b1fa8(FUN_001aa91c(), c->cur);
    int sel = Clamp(n - 1, DAT_00389970, DAT_00389974);

    Info *info = FUN_00290230(DAT_003f3b1c, n);
    int b_val = info->b;
    int c_val = info->c;
    int a_val = info->a;

    List *l = self->list;
    int i = 0;
    if (l->count > 0) {
        do {
            FUN_00105470(l->data[i], i != sel);
            i++;
        } while (i < l->count);
    }

    for (int j = 0, off1 = 0; j < 5; ++j, off1 += 20) {
        char *p = (char *)self + (off1 + 300);
        Slot *s = (Slot *)(p + 32);
        if (j < b_val) {
            FUN_00105470(s->w, 0);
        } else {
            FUN_00105470(s->w, 1);
        }
    }

    for (int k = 0, off2 = 0; k < 5; ++k, off2 += 20) {
        char *p = (char *)self + (off2 + 400);
        Slot *s = (Slot *)(p + 32);
        if (k < c_val) {
            FUN_00105470(s->w, 0);
        } else {
            FUN_00105470(s->w, 1);
        }
    }

    FUN_00105470(*(void **)((char *)self + 532), 0);
    Link *link = *(Link **)((char *)self + 532);
    void **p1 = (void **)((char *)self + 292);
    int sum = link->f28 + a_val;
    void **p2 = (void **)((char *)self + 312);
    link->f24 = sum;
    if (FUN_001b2140(FUN_001aa91c(), 2)) {
        FUN_00105470(*p1, 0);
        FUN_00105470(*p2, 0);
    } else {
        FUN_00105470(*p1, 1);
        FUN_00105470(*p2, 1);
    }
}
