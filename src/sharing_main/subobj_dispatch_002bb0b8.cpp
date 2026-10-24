/* HSTMATCH module=hstp_trans_main.prx start=0x002bb0b8 end=0x002bb32c symbol=FUN_002bb0b8 lang=c++ */
/* Clone of src/eboot/subobj_dispatch_002ab8fc.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern int DAT_003a9b90[];
extern char *DAT_003ea8e8;
extern int DAT_003f46a0;
extern void FUN_00111aa4(int, int, int);
extern void FUN_0011988c(int, int, int);
extern int FUN_0020d1e0(int, int, int);
extern void FUN_002b4e10(int, int);
extern int FUN_002beb30(char *);
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

extern "C" void FUN_002bb0b8(Obj *self, unsigned char val) {
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
    FUN_002b4e10(self->f3c, self->f50);

    b = (self->f5a != 0) || (self->f50 != 0);
    s0 = self->f40;
    ((VC *)(*(int **)(s0 + 0x178)))->m(b);
    *(bool *)(s0 + 0x17c) = !b;
    if (!b) {
        int a0 = *(int *)(s0 + 0x178);
        int v = *(int *)(a0 + 0xdc);
        FUN_00111aa4(a0, v, 0);
        if (DAT_003f46a0 != 0) {
            int u = FUN_0020d1e0(18, 49, DAT_003a9b90[v]);
            FUN_0011988c(DAT_003f46a0, u, 0);
        }
    }

    b = (self->f5a != 0) || (self->f50 != 1);
    s0 = self->f44;
    int s2 = 1;
    if (!b) {
        bool ok = 0 < FUN_002beb30(DAT_003ea8e8 + 0x87128);
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
        FUN_00111aa4(*(int *)(s1 + 0x1034), *(int *)(s1 + 0x30c8), 0);
    }
}
