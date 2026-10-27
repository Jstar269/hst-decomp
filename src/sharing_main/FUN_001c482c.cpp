/* HSTMATCH module=hstp_trans_main.prx start=0x001c482c end=0x001c4a70 symbol=FUN_001c482c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/FUN_001b6b6c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct G_001c482c {
    char pad00[0x5d];
    unsigned char f5d;
    unsigned char f5e;
    unsigned char f5f;
    char pad60[0x84 - 0x60];
    unsigned char f84;
};
struct P_001c482c {
    char pad00[0x7b];
    unsigned char f7b;
    char pad7c[0x90 - 0x7c];
    unsigned char f90;
};
struct R_001c482c {
    char pad00[0x144];
    int f144;
};
extern "C" {
extern G_001c482c *DAT_003e1e84;
extern void *DAT_003e19f0;
extern char DAT_003eaad8[];
int FUN_00089f84(void *);
int FUN_000dfc24(G_001c482c *);
int FUN_000e23f4(G_001c482c *, int);
int FUN_000e2424(G_001c482c *, int);
int FUN_000e2454(G_001c482c *, int);
int FUN_000e2484(G_001c482c *, int);
void FUN_001c6834(P_001c482c *, int, int);
void FUN_001c66d8(float, P_001c482c *);
void FUN_001c657c(float, P_001c482c *);
void FUN_001bfc3c(int, int);
void FUN_001c5f20(P_001c482c *);
}
extern "C" void FUN_001c482c(P_001c482c *self)
{
    if (DAT_003e1e84->f84 != 0) {
        if (self->f7b == 0)
            FUN_001c6834(self, 0x91, 0);
        FUN_001c66d8(0.5f, self);
    }
    else if (DAT_003e1e84->f5f != 0) {
        FUN_001c6834(self, 0x93, 0);
        FUN_001c66d8(0.5f, self);
    }
    else if (DAT_003e1e84->f5e != 0) {
        FUN_001c6834(self, 0x92, 0);
    }
    else if (DAT_003e1e84->f5d != 0) {
        FUN_001c6834(self, 0x94, 0);
    }
    else if (FUN_000dfc24(DAT_003e1e84) != 0) {
        FUN_001c6834(self, 0x95, 0);
        FUN_001c66d8(0.5f, self);
    }
    else {
        if (FUN_000e23f4(DAT_003e1e84, -1) != 0 || FUN_000e2424(DAT_003e1e84, -1) != 0 ||
            FUN_000e2484(DAT_003e1e84, -1) != 0)
            FUN_001c657c(0.5f, self);
    }
    unsigned int s2 = ((R_001c482c *)FUN_00089f84(DAT_003e19f0))->f144;
    unsigned int s0 = s2 ^ 1;
    if (FUN_000e23f4(DAT_003e1e84, s2) != 0 || FUN_000e2424(DAT_003e1e84, s2) != 0 ||
        FUN_000e2454(DAT_003e1e84, s2) != 0) {
        FUN_001bfc3c((int)DAT_003eaad8, 0x43);
    }
    else {
        if (FUN_000e23f4(DAT_003e1e84, s0) != 0 || FUN_000e2424(DAT_003e1e84, s0) != 0 ||
            FUN_000e2454(DAT_003e1e84, s0) != 0) {
            if (self->f90 != 0)
                FUN_001bfc3c((int)DAT_003eaad8, 0x4b);
        }
    }
    FUN_001c5f20(self);
}
