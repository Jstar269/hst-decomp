/* HSTMATCH module=hstp_trans_main.prx start=0x00168204 end=0x0016841c symbol=FUN_00168204 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0c) corrected by hand: C++ struct layout, virtual deleting destructors, and null-checked allocations; exact match verified; names and types await human review. */
struct Obj_0010873c {
    virtual ~Obj_0010873c();
};

struct Obj_00051ad8 {
    virtual ~Obj_00051ad8();
};

struct Item_00108124 {
    char pad[0x24];
    int f24;
    int f28;
};

struct Self_00168204 {
    char pad00[0x28];
    Obj_0010873c *obj28;
    char pad2c[0x34 - 0x2c];
    Obj_00051ad8 *obj34;
    char pad38[0x40 - 0x38];
    float f40;
    float f44;
    float f48;
    float f4c;
    char pad50[0x70 - 0x50];
    char sub70[0x300];
    char buf370[1];
};

extern "C" {
extern char DAT_0038560c[];
extern char DAT_00385630[];
extern char DAT_003858b4[];
extern char DAT_003858dc[];
extern char DAT_003858fc[];
extern char DAT_00385900[];
extern char DAT_003b7ebc[];
extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, ...);
extern int FUN_00014934(char *, char *);
extern void FUN_000149a8(char *, char *);
extern void FUN_0001c684(char *, int, char *);
extern void FUN_0001c73c(char *);
extern Obj_00051ad8 *FUN_000518d4(void *);
extern void FUN_00051ad8(Obj_00051ad8 *, char *, int);
extern void FUN_00051d38(float, Obj_00051ad8 *);
extern void FUN_00105470(Item_00108124 *, int);
extern Item_00108124 *FUN_00108124(void *, char *);
extern Obj_0010873c *FUN_0010873c(void *);
extern void FUN_00108f54(Obj_0010873c *, int);
extern void *FUN_00109304(Obj_0010873c *, char *, int);
extern void FUN_00109a44(Obj_0010873c *, char *, int);
}

extern "C" void FUN_00168204(Self_00168204 *self, int name)
{
    FUN_000143b0(self->buf370, DAT_0038560c, name);
    FUN_0001c684(DAT_003b7ebc, 1, self->buf370);
    FUN_000143b0(self->buf370, DAT_00385630, name);
    if (self->obj34 == 0 || FUN_00014934(self->sub70, self->buf370) != 0) {
        if (self->obj34 != 0) {
            delete self->obj34;
            self->obj34 = 0;
        }
        Obj_00051ad8 *p = (Obj_00051ad8 *)FUN_00000bcc(0x48);
        if (p != 0) {
            p = FUN_000518d4(p);
        }
        self->obj34 = p;
        FUN_00051ad8(p, self->buf370, 0);
        FUN_00051d38(3000.0f, self->obj34);
        FUN_000149a8(self->sub70, self->buf370);
        self->f40 = 0.0f;
        self->f44 = 0.0f;
        self->f48 = 0.0f;
        self->f4c = 1.0f;
    }
    FUN_0001c73c(DAT_003b7ebc);
    FUN_000143b0(self->buf370, DAT_003858b4);
    FUN_0001c684(DAT_003b7ebc, 1, self->buf370);
    if (self->obj28 != 0) {
        if (self->obj28 != 0) {
            delete self->obj28;
            self->obj28 = 0;
        }
    }
    Obj_0010873c *q = (Obj_0010873c *)FUN_00000bcc(0x54);
    if (q != 0) {
        q = FUN_0010873c(q);
    }
    Obj_0010873c *o28 = q;
    self->obj28 = o28;
    FUN_00109a44(o28, DAT_003858dc, 0);
    FUN_00108f54(self->obj28, 0);
    void *grp = FUN_00109304(self->obj28, DAT_003858fc, 0);
    if (grp != 0) {
        Item_00108124 *item = FUN_00108124(grp, DAT_00385900);
        if (item != 0) {
            FUN_00105470(item, 0);
            int v = name + item->f24 - 1;
            item->f24 = v;
            item->f28 = v;
        }
    }
    FUN_0001c73c(DAT_003b7ebc);
}
