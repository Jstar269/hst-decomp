/* HSTMATCH module=EBOOT.BIN start=0x002a57ec end=0x002a594c symbol=FUN_002a57ec lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: C++ virtual method calls on sub-objects, mode switch dispatching sub-object updates and child notifications; exact match verified; names and types await human review. */

extern "C" {
extern int DAT_00300a70;
extern void FUN_000ffb3c(int, bool);

struct SubObj {
    virtual void func0();
    virtual void vfunc_c(int);
};

struct Target {
    char pad0[36];
    int f_24;
    int f_28;
};

struct Obj {
    char pad0[100];
    SubObj *obj_64;
    SubObj *obj_68;
    SubObj *obj_6c;
    char pad70[60];
    int f_ac;
    int f_b0;
    int f_b4;
    int f_b8;
    int f_bc;
    int f_c0;
    char padc4[4];
    Target *f_c8;
    char padcc[20];
    unsigned char flag_e0;
    char pade1[3];
    int mode;
    int param_3;
};

void FUN_002a57ec(Obj *param_1, int param_2, int p3)
{
    param_1->mode = param_2;
    param_1->param_3 = p3;

    param_1->obj_64->vfunc_c(1);
    param_1->obj_68->vfunc_c(1);
    param_1->obj_6c->vfunc_c(1);

    if (param_1->flag_e0 != 0) {
        return;
    }

    switch (param_1->mode) {
    case 0:
        param_1->obj_64->vfunc_c(0);
        break;
    case 1:
        param_1->obj_68->vfunc_c(0);
        FUN_000ffb3c(param_1->f_ac, p3 != 0);
        FUN_000ffb3c(param_1->f_b0, p3 != 0);
        FUN_000ffb3c(param_1->f_b4, p3 != 0);
        FUN_000ffb3c(param_1->f_b8, p3 != 0);
        FUN_000ffb3c(param_1->f_bc, p3 != 1);
        FUN_000ffb3c(param_1->f_c0, p3 != 1);
        break;
    case 2:
    case 3: {
        param_1->obj_6c->vfunc_c(0);
        int val = DAT_00300a70 + p3;
        Target *t = param_1->f_c8;
        t->f_24 = val;
        t->f_28 = val;
        break;
    }
    }
}
}
