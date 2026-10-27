/* HSTMATCH module=hstp_trans_main.prx start=0x0027302c end=0x00273138 symbol=FUN_0027302c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/init_manager_00262204.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */

extern "C" {
extern char DAT_003a69ec[];
extern char DAT_003a6a04[];
extern char DAT_003b2d20[];
extern char DAT_003b3e6c[];
extern char DAT_003b7ebc[];

extern void *FUN_00000bcc(unsigned int size);
extern void *FUN_00010184(int a, int b);
extern void FUN_000104e0(void *p);
extern void FUN_0001bb2c(void *a, void *b, int c);
extern void FUN_0001c684(void *a, int b, void *c);
extern void FUN_0001c73c(void *a);
extern void *FUN_0001c848(void);
extern int FUN_0001c8a0(void);
extern void *FUN_0001ec44(void *self);
extern void FUN_00264244(void);
extern void FUN_00268744(void *p);
extern void *FUN_00273138(void *p, void *name);
}

struct Obj_0027302c {
    void *vptr;           // +0
    char pad[56];         // +4 .. +59
    void *f3C;            // +60 (0x3c)
};

struct Target_0027302c {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

extern "C" void *FUN_0027302c(struct Obj_0027302c *self)
{
    void *iVar1;
    void *uVar3;
    void *p;
    int uVar4;

    FUN_0001ec44(self);
    self->vptr = &DAT_003b2d20;
    iVar1 = FUN_00010184(64, 0x300000);
    FUN_0001bb2c(&DAT_003b3e6c, iVar1, 0x300000);
    FUN_0001c684(&DAT_003b7ebc, 1, DAT_003a69ec);

    p = FUN_00000bcc(0x1870);
    if (p != 0) {
        p = FUN_00273138(p, DAT_003a6a04);
    }
    self->f3C = p;

    FUN_00264244();
    FUN_0001c73c(&DAT_003b7ebc);
    uVar3 = FUN_0001c848();
    uVar4 = FUN_0001c8a0();
    FUN_0001bb2c(&DAT_003b3e6c, uVar3, uVar4);

    if (iVar1 != 0) {
        FUN_000104e0(iVar1);
    }

    FUN_00268744(self->f3C);
    ((struct Target_0027302c *)self->f3C)->v6();

    return self;
}
