/* HSTMATCH module=EBOOT.BIN start=0x002ab8fc end=0x002abb70 symbol=FUN_002ab8fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern int DAT_00300af4[];
extern char *DAT_003415a8;
extern int DAT_0034b354;
extern void FUN_0010b8cc(int, int, int);
extern void FUN_00110a78(int, int, int);
extern int FUN_001fea10(int, int, int);
extern void FUN_002a5680(int, int);
extern int FUN_002af274(char *);
}

struct VC {
    virtual void d0();
    virtual void m(int);
};

struct Obj {
    char pad_00[0x3c];
    int f3c;
    int f40;
    int f44;
    int f48;
    int pad_4c;
    int f50;
    char pad_54[6];
    unsigned char f5a;
};

extern "C" void FUN_002ab8fc(Obj *self, unsigned char val) {
    self->f5a = val;
    bool b = !self->f5a;
    int s0 = self->f3c;
    ((VC *)(*(int **)(s0 + 0xd4)))->m(b);
    *(bool *)(s0 + 0xe0) = !b;
    if (!b) {
        ((VC *)(*(int **)(s0 + 0x60)))->m(0);
        ((VC *)(*(int **)(s0 + 0x64)))->m(1);
        ((VC *)(*(int **)(s0 + 0x68)))->m(1);
        ((VC *)(*(int **)(s0 + 0x6c)))->m(1);
    } else {
        ((VC *)(*(int **)(s0 + 0x60)))->m(1);
    }
    FUN_002a5680(self->f3c, self->f50);

    b = (self->f5a != 0) || (self->f50 != 0);
    s0 = self->f40;
    ((VC *)(*(int **)(s0 + 0x178)))->m(b);
    *(bool *)(s0 + 0x17c) = !b;
    if (!b) {
        int a0 = *(int *)(s0 + 0x178);
        int v = *(int *)(a0 + 0xdc);
        FUN_0010b8cc(a0, v, 0);
        if (DAT_0034b354 != 0) {
            int u = FUN_001fea10(18, 49, DAT_00300af4[v]);
            FUN_00110a78(DAT_0034b354, u, 0);
        }
    }

    b = (self->f5a != 0) || (self->f50 != 1);
    s0 = self->f44;
    int s2 = 1;
    if (!b) {
        bool ok = 0 < FUN_002af274(DAT_003415a8 + 0x87128);
        bool not_ok = !ok;
        if (not_ok) {
        } else {
            s2 = 0;
        }
    }
    ((VC *)(*(int **)(s0 + 0x358)))->m(s2);
    *(bool *)(s0 + 0x360) = !b;

    int s0_val = 1;
    if (self->f5a == 0) {
        int a0 = 0;
        if (self->f50 != 2 && self->f50 != 3) {
            a0 = s0_val;
        }
        if (!a0) {
            s0_val = 0;
        }
    }
    int s1 = self->f48;
    ((VC *)(*(int **)(s1 + 0x1034)))->m(s0_val);
    *(bool *)(s1 + 0x103c) = !s0_val;
    if (!s0_val) {
        FUN_0010b8cc(*(int *)(s1 + 0x1034), *(int *)(s1 + 0x30c8), 0);
    }
}
