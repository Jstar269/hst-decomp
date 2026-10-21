/* HSTMATCH module=EBOOT.BIN start=0x00130d60 end=0x0013110c symbol=FUN_00130d60 lang=c++ rodata=0x002c151c */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: every missing case label 0..25 is listed (empty group) so MWCC emits the 26-entry jump table (rodata=0x2c151c), cases in retail body order (0x14 before 0xc/0x17, 0x16 before 0xe), the flag stays a bool passed to a bool parameter, FUN_000df000 takes the global pointer Ghidra dropped; names and types await human review. */
struct Sub {
    char pad0[0x78];
    unsigned char f78;
    char pad79;
    unsigned char f7a;
};

struct Obj {
    char pad0[0x3c];
    int f3c;
    int f40;
    int f44;
    char pad48[0x7c - 0x48];
    void *f7c;
    Sub *f80;
    void *f84;
    int f88;
    int f8c;
    int f90;
    char pad94[0xa0 - 0x94];
    int fa0, fa4, fa8, fac;
    int fb0, fb4;
    char padb8[0xc0 - 0xb8];
    int fc0, fc4, fc8, fcc;
    int fd0;
    char padd4[0xe0 - 0xd4];
    int fe0, fe4, fe8, fec;
    unsigned char ff0, ff1, ff2, ff3;
    int ff4, ff8, ffc, f100;
    char pad104[0x110 - 0x104];
    int f110, f114, f118, f11c;
    char pad120[0x128 - 0x120];
    int f128, f12c, f130;
    unsigned char f134;
};

extern "C" {
extern int DAT_0034a678;
struct Game { char pad[0x5d]; unsigned char f5d; };
extern Game *DAT_00338b44;
int FUN_0022c860(void);
void FUN_0001f1fc(void *o, int n);
void FUN_001b9b0c(void *o, bool n);
void FUN_001b9d10(void *o);
void FUN_00124238(Sub *o);
void FUN_00124268(Sub *o);
int FUN_00125218(Sub *o);
int FUN_000df000(Game *g);
void FUN_00123c94(Sub *o, int n);
void FUN_001240f4(Sub *o);
void FUN_0013096c(Obj *o, int n);
void FUN_001237e0(Sub *o);
void FUN_000b9edc(void *o);
void FUN_00131e00(void);
}

extern "C" int FUN_00130d60(Obj *self, int state)
{
    switch (state) {
    case 4: {
        bool b = DAT_0034a678 == 0x2a && FUN_0022c860() != 0;
        self->f8c = 4;
        FUN_0001f1fc(self->f7c, 0);
        FUN_0001f1fc(self->f84, 1);
        FUN_001b9b0c(self->f84, b);
        if (b) {
            FUN_0001f1fc(self->f80, 1);
            FUN_00124238(self->f80);
            self->f88 = FUN_00125218(self->f80);
        }
        break;
    }
    case 5: {
        bool b = DAT_0034a678 == 0x2a && FUN_0022c860() != 0;
        FUN_0001f1fc(self->f7c, 1);
        FUN_0001f1fc(self->f84, 0);
        FUN_001b9d10(self->f84);
        if (b) {
            FUN_0001f1fc(self->f80, 0);
            self->f80->f78 = 0;
        }
        self->f8c = 0;
        break;
    }
    case 6:
        FUN_0001f1fc(self->f80, 1);
        FUN_00124268(self->f80);
        self->f88 = FUN_00125218(self->f80);
        self->f8c = 3;
        break;
    case 7:
        FUN_0001f1fc(self->f80, 0);
        self->f80->f78 = 0;
        self->f88 = 0;
        self->f8c = 0;
        break;
    case 8:
        FUN_0001f1fc(self->f80, 0);
        self->f80->f78 = 0;
        self->f88 = 0;
        self->f8c = 0;
        self->ff0 = 1;
        self->fb0 = 0;
        self->fb4 = 0;
        self->fc0 = 0;
        self->fc4 = 0;
        self->fc8 = 0;
        self->fcc = 0x3f800000;
        self->f90 = 0;
        self->fa0 = 0;
        self->fa4 = 0;
        self->fa8 = 0;
        self->fac = 0x3f800000;
        self->fd0 = 0;
        self->f44 = 0;
        self->fe0 = 0;
        self->fe4 = 0;
        self->fe8 = 0;
        self->fec = 0x3f800000;
        self->f128 = 0;
        self->f12c = 1;
        self->f130 = 0;
        self->ff1 = 0;
        self->ff2 = 0;
        self->ff3 = 0;
        self->ff4 = 0;
        self->ff8 = 0;
        self->ffc = 0;
        self->f100 = 0;
        self->f110 = 0;
        self->f114 = 0;
        self->f118 = 0;
        self->f11c = 0x3f800000;
        break;
    case 0x14:
        if (self->ff0 != 0) {
            self->ff0 = 0;
            FUN_00131e00();
        }
        break;
    case 0x17:
    case 0xc:
        self->f3c = 0;
        self->f40 = -1;
        if (DAT_00338b44->f5d == 0 && FUN_000df000(DAT_00338b44) == 0) {
            FUN_0001f1fc(self->f80, 1);
            if (state >= 0x10) {
                FUN_001240f4(self->f80);
            } else {
                FUN_00123c94(self->f80, 0);
            }
            self->f88 = FUN_00125218(self->f80);
            self->f8c = 2;
        }
        break;
    case 0xd:
        FUN_0001f1fc(self->f80, 0);
        self->f80->f78 = 0;
        self->f88 = 0;
        self->f8c = 0;
        break;
    case 0x16:
        self->f3c = 0;
        self->f40 = -1;
        break;
    case 0xe:
        self->f3c = 0;
        self->f40 = -1;
        FUN_0013096c(self, 0);
        FUN_0001f1fc(self->f80, 1);
        FUN_001237e0(self->f80);
        if (self->f80->f78 == 0) {
            if (self->f80->f7a != 0) FUN_000b9edc(self->f7c);
        }
        self->f88 = FUN_00125218(self->f80);
        self->f8c = 1;
        self->f134 = 0;
        self->ff3 = 0;
        break;
    case 0xf:
        FUN_0013096c(self, 0);
        FUN_0001f1fc(self->f80, 0);
        self->f80->f78 = 0;
        self->f88 = 0;
        self->f8c = 0;
        break;
    case 0x19:
        self->f3c = 0;
        self->f40 = -1;
        FUN_0013096c(self, 0);
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 9:
    case 10:
    case 11:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x15:
    case 0x18:
        break;
    }
    return 0;
}
