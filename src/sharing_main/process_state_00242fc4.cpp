/* HSTMATCH module=hstp_trans_main.prx start=0x00242fc4 end=0x0024312c symbol=FUN_00242fc4 lang=c++ */
/* Clone of src/eboot/process_state_00232ec4.cpp (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-decompiled: virtual member calls on subobject, &DAT_003eaad8 symbol reference, switch case ordering; exact match verified. */

extern "C" {
    extern char DAT_003eaad8;
    int FUN_001bfc3c(void *dat, int arg2);
    void FUN_0022f7ac(int arg1, unsigned char arg2);
    int FUN_0023bc48(void);
    int FUN_0023bc78(void);
    int FUN_0023bc90(void);
    unsigned char FUN_0023c4c8(int arg1);
    void FUN_002424e0(void *arg1);
    void FUN_00242658(void *arg1, int arg2);
    void FUN_0024312c(void *arg1, int arg2);
    unsigned char FUN_0027ff44(void);
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

extern "C" void FUN_00242fc4(MyObj *self)
{
    FUN_002424e0(self->sub);
    FUN_0024312c(self, 4);
    self->sub->method12();
    self->sub->method16();
    self->field_10 = FUN_0027ff44();
    int cVar2 = FUN_0023c4c8(7);
    int cVar3 = 0;
    int iVar4 = FUN_0023bc48();
    if (iVar4 >= 0 && iVar4 < 10) {
        cVar3 = FUN_0023c4c8(iVar4);
    }
    if (FUN_0023bc90()) {
        int val = FUN_0023bc78();
        SubObj *sub = self->sub;
        if (sub->field_1e0 != val) {
            FUN_001bfc3c(&DAT_003eaad8, 1);
            sub->field_1e0 = val;
        } else {
            sub->field_1e0 = val;
        }
        switch (sub->field_1dc) {
        case 0:
            break;
        case 1:
            FUN_00242658(sub, sub->field_1e0);
            break;
        }
        FUN_0024312c(self, 0);
    } else {
        if (cVar2 != 0) {
            FUN_0024312c(self, 3);
        } else if (cVar3 != 0) {
            FUN_0024312c(self, 1);
        } else {
            FUN_0022f7ac(self->field_4, self->field_10);
        }
    }
}
