/* HSTMATCH module=EBOOT.BIN start=0x001b6b6c end=0x001b6db0 symbol=FUN_001b6b6c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a7/v21) corrected by hand: rewrote the inverted if/else chain into the natural if/else-if order and used unsigned temps so the pointer parameter colours into s1; exact match verified; names and types await human review. */
struct G_001b6b6c {
    char pad00[0x5d];
    unsigned char f5d;
    unsigned char f5e;
    unsigned char f5f;
    char pad60[0x84 - 0x60];
    unsigned char f84;
};
struct P_001b6b6c {
    char pad00[0x7b];
    unsigned char f7b;
    char pad7c[0x90 - 0x7c];
    unsigned char f90;
};
struct R_001b6b6c {
    char pad00[0x144];
    int f144;
};
extern "C" {
extern G_001b6b6c *DAT_00338b44;
extern void *DAT_003386b0;
extern char DAT_0034179c[];
int FUN_0008882c(void *);
int FUN_000dbc04(G_001b6b6c *);
int FUN_000de208(G_001b6b6c *, int);
int FUN_000de238(G_001b6b6c *, int);
int FUN_000de268(G_001b6b6c *, int);
int FUN_000de298(G_001b6b6c *, int);
void FUN_001b8b48(P_001b6b6c *, int, int);
void FUN_001b89ec(float, P_001b6b6c *);
void FUN_001b8890(float, P_001b6b6c *);
void FUN_001b1c44(int, int);
void FUN_001b8260(P_001b6b6c *);
}
extern "C" void FUN_001b6b6c(P_001b6b6c *self)
{
    if (DAT_00338b44->f84 != 0) {
        if (self->f7b == 0)
            FUN_001b8b48(self, 0x91, 0);
        FUN_001b89ec(0.5f, self);
    }
    else if (DAT_00338b44->f5f != 0) {
        FUN_001b8b48(self, 0x93, 0);
        FUN_001b89ec(0.5f, self);
    }
    else if (DAT_00338b44->f5e != 0) {
        FUN_001b8b48(self, 0x92, 0);
    }
    else if (DAT_00338b44->f5d != 0) {
        FUN_001b8b48(self, 0x94, 0);
    }
    else if (FUN_000dbc04(DAT_00338b44) != 0) {
        FUN_001b8b48(self, 0x95, 0);
        FUN_001b89ec(0.5f, self);
    }
    else {
        if (FUN_000de208(DAT_00338b44, -1) != 0 || FUN_000de238(DAT_00338b44, -1) != 0 ||
            FUN_000de298(DAT_00338b44, -1) != 0)
            FUN_001b8890(0.5f, self);
    }
    unsigned int s2 = ((R_001b6b6c *)FUN_0008882c(DAT_003386b0))->f144;
    unsigned int s0 = s2 ^ 1;
    if (FUN_000de208(DAT_00338b44, s2) != 0 || FUN_000de238(DAT_00338b44, s2) != 0 ||
        FUN_000de268(DAT_00338b44, s2) != 0) {
        FUN_001b1c44((int)DAT_0034179c, 0x43);
    }
    else {
        if (FUN_000de208(DAT_00338b44, s0) != 0 || FUN_000de238(DAT_00338b44, s0) != 0 ||
            FUN_000de268(DAT_00338b44, s0) != 0) {
            if (self->f90 != 0)
                FUN_001b1c44((int)DAT_0034179c, 0x4b);
        }
    }
    FUN_001b8260(self);
}
