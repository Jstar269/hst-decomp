/* HSTMATCH module=EBOOT.BIN start=0x00206290 end=0x00206640 symbol=FUN_00206290 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Elem {
    char pad[0x1b4];
    int f1b4;
};
struct Slots {
    char pad[0x50];
    Elem *s[6];
};
struct Slots2 {
    char pad[0x64];
    Elem *f64;
};
class Part {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};
struct Core {
    char pad[0x50];
    Elem *s0;
    Elem *s1;
    Elem *s2;
    Elem *s3;
    Elem *s4;
    Elem *s5;
};
struct PVec {
    void **data;
    unsigned size;
    void *&operator[](unsigned i) { return data[i]; }
    unsigned count() const { return size; }
};
struct Player {
    Core *core;
    char pad4[0xc - 4];
    PVec v;
    char pad14[0x48 - 0x14];
    int f48;
    int f4c;
    int f50;
    int tab[6];
    unsigned char f6c;
    char pad6d[3];
    int f70;
    unsigned char f74;
    unsigned char f75, f76, f77;
    unsigned char f78;
};
struct Arg {
    char pad[0x24];
    unsigned char f24;
    char pad25[0x7c - 0x25];
    unsigned char f7c;
};

extern int DAT_002c93b0[6];
extern char DAT_002ef6d4[];
extern char DAT_002ef700[];
extern char DAT_002ef724[];
extern char DAT_002ef734[];

inline void *operator new[](unsigned int, void *p) { return p; }

extern "C" {
int FUN_00049094(int);
void FUN_002059ec(...);
void FUN_00092c38(Core *, int);
void FUN_00055e48(void *, int);
void FUN_0019487c(Core *, Arg *, int, int, int, int);
int FUN_00194420(int);
void FUN_00011090(void *, void *, int);
void FUN_0020507c(Player *, int);
void FUN_002052b8(Player *, int, int);
void FUN_0005743c(Elem *, int, void *, int);
void FUN_00094424(Core *);

struct Tag {};
static inline int SlotValue(int i, Tag)
{
    int v;
    if (i >= 0 && i < 6) {
        v = DAT_002c93b0[i];
    } else {
        v = 0;
    }
    return v;
}

void FUN_00206290(Player *self, unsigned char mode, Arg *arg)
{
    int a[6];
    int b[6];
    self->f74 = mode;
    if (FUN_00049094(0) == 0) {
        FUN_002059ec(DAT_002ef6d4);
        FUN_002059ec(DAT_002ef700, DAT_002ef724, 1150);
        FUN_002059ec(DAT_002ef734);
    }
    FUN_00049094(1);
    if (self->f74 == 0) {
        for (int i = 0; i < 6; i++) {
            Core *c0 = self->core;
            FUN_00092c38(c0, SlotValue(i, Tag()));
        }
    }
    for (unsigned j = 0; j < self->v.count(); j++) {
        if (self->v.data[j] != 0) {
            FUN_00055e48(self->v.data[j], 1);
            self->v.data[j] = 0;
        }
    }
    int n = (int)self->v.size;
    self->v.size -= n;
    self->f75 = 0;
    self->f76 = 0;
    self->f77 = 0;
    self->f78 = 0;
    self->f78 = arg->f7c == 2;
    if (self->f74 == 0) {
        FUN_0019487c(self->core, arg, 0, 0, 1, 1);
        new (a) char[24]();
        a[0] = FUN_00194420(0);
        a[1] = FUN_00194420(1);
        a[2] = FUN_00194420(2);
        a[3] = FUN_00194420(3);
        a[4] = FUN_00194420(4);
        a[5] = FUN_00194420(5);
        FUN_00011090(self->tab, a, 24);
    } else {
        new (b) char[24]();
        FUN_0019487c(self->core, arg, 0, 0, 1, 1);
        Core *c = self->core;
        Elem *e0 = c->s0;
        Elem *e1 = c->s1;
        Elem *e2 = c->s2;
        Elem *e3 = c->s3;
        Elem *e4 = c->s4;
        Elem *e5 = c->s5;
        if (e0) b[0] = e0->f1b4;
        if (e1) b[1] = e1->f1b4;
        if (e2) b[2] = e2->f1b4;
        if (e3) b[3] = e3->f1b4;
        if (e4) b[4] = e4->f1b4;
        if (e5) b[5] = e5->f1b4;
        FUN_00011090(self->tab, b, 24);
    }
    if (self->tab[0] >= 0 && self->tab[0] < 15) {
        self->f6c = 0;
    } else {
        self->f6c = 1;
    }
    if (self->f6c != 0) {
        FUN_0020507c(self, 99);
    } else {
        FUN_0020507c(self, self->tab[0]);
    }
    FUN_002052b8(self, 1, self->f78);
    int flag = self->f78;
    Elem *e = ((Slots2 *)self->core)->f64;
    if (e != 0) {
        int k = 0;
        do {
            FUN_0005743c(e, k, self->v[k], flag);
            k++;
        } while (k < 6);
    }
    FUN_00094424(self->core);
    ((Part *)self->core)->m1();
    self->f70 = arg->f24;
    if (self->f4c != 3) {
        self->f50 = 3;
    } else {
        if (self->f50 != 0) self->f50 = 0;
    }
    self->f48 = 1;
}
}
