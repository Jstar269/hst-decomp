/* HSTMATCH module=EBOOT.BIN start=0x00232ec4 end=0x0023302c symbol=FUN_00232ec4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-decompiled: virtual member calls on subobject, &DAT_0034179c symbol reference, switch case ordering; exact match verified. */

extern "C" {
    extern char DAT_0034179c;
    int FUN_001b1c44(void *dat, int arg2);
    void FUN_00220238(int arg1, unsigned char arg2);
    int FUN_0022c194(void);
    int FUN_0022c1c4(void);
    int FUN_0022c1dc(void);
    unsigned char FUN_0022c928(int arg1);
    void FUN_002323e0(void *arg1);
    void FUN_00232558(void *arg1, int arg2);
    void FUN_0023302c(void *arg1, int arg2);
    unsigned char FUN_0026ef04(void);
}

struct SubObj {
    virtual void dummy0();
    virtual void method12();
    virtual void method16();
    char pad[0x1dc - 4];
    int field_1dc;
    int field_1e0;
};

struct MyObj {
    SubObj *sub;
    int field_4;
    char pad[0x10 - 8];
    unsigned char field_10;
};

extern "C" void FUN_00232ec4(MyObj *self)
{
    FUN_002323e0(self->sub);
    FUN_0023302c(self, 4);
    self->sub->method12();
    self->sub->method16();
    self->field_10 = FUN_0026ef04();
    int cVar2 = FUN_0022c928(7);
    int cVar3 = 0;
    int iVar4 = FUN_0022c194();
    if (iVar4 >= 0 && iVar4 < 10) {
        cVar3 = FUN_0022c928(iVar4);
    }
    if (FUN_0022c1dc()) {
        int val = FUN_0022c1c4();
        SubObj *sub = self->sub;
        if (sub->field_1e0 != val) {
            FUN_001b1c44(&DAT_0034179c, 1);
            sub->field_1e0 = val;
        } else {
            sub->field_1e0 = val;
        }
        switch (sub->field_1dc) {
        case 0:
            break;
        case 1:
            FUN_00232558(sub, sub->field_1e0);
            break;
        }
        FUN_0023302c(self, 0);
    } else {
        if (cVar2 != 0) {
            FUN_0023302c(self, 3);
        } else if (cVar3 != 0) {
            FUN_0023302c(self, 1);
        } else {
            FUN_00220238(self->field_4, self->field_10);
        }
    }
}
