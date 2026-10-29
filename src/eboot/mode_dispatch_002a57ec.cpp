/* HSTMATCH module=EBOOT.BIN start=0x002a57ec end=0x002a594c symbol=FUN_002a57ec lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: C++ virtual method calls on sub-objects, mode switch dispatching sub-object updates and child notifications; readability pass; exact match verified; names and types await human review. */

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
    SubObj *panel_a;
    SubObj *panel_b;
    SubObj *panel_c;
    char pad70[60];
    int item_ac;
    int item_b0;
    int item_b4;
    int item_b8;
    int item_bc;
    int item_c0;
    char padc4[4];
    Target *target;
    char padcc[20];
    unsigned char flag_e0;
    char pade1[3];
    int mode;
    int sub_mode;
};

void FUN_002a57ec(Obj *self, int new_mode, int sub_mode)
{
    self->mode = new_mode;
    self->sub_mode = sub_mode;

    /* Hide all three panels, then show the one for the new mode. */
    self->panel_a->vfunc_c(1);
    self->panel_b->vfunc_c(1);
    self->panel_c->vfunc_c(1);

    if (self->flag_e0 != 0) {
        return;
    }

    switch (self->mode) {
    case 0:
        self->panel_a->vfunc_c(0);
        break;
    case 1:
        self->panel_b->vfunc_c(0);
        FUN_000ffb3c(self->item_ac, sub_mode != 0);
        FUN_000ffb3c(self->item_b0, sub_mode != 0);
        FUN_000ffb3c(self->item_b4, sub_mode != 0);
        FUN_000ffb3c(self->item_b8, sub_mode != 0);
        FUN_000ffb3c(self->item_bc, sub_mode != 1);
        FUN_000ffb3c(self->item_c0, sub_mode != 1);
        break;
    case 2:
    case 3: {
        self->panel_c->vfunc_c(0);
        int value = DAT_00300a70 + sub_mode;
        Target *t = self->target;
        t->f_24 = value;
        t->f_28 = value;
        break;
    }
    }
}
}
