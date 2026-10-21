/* HSTMATCH module=hstp_trans_main.prx start=0x0012e644 end=0x0012e9b4 symbol=FUN_0012e644 lang=c99 */
/* Clone of src/eboot/match_input_00123470.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Match {
    char pad0[0x9c];
    int f9c;
    int pad_a0;
    int fa4;
} Match;
typedef struct Pl {
    char pad0[0x58];
    int f58;
    char pad5c[0x79 - 0x5c];
    unsigned char f79;
    char pad7a;
    unsigned char f7b;
    char pad7c[0x80 - 0x7c];
    int f80;
    char pad84[0x8c - 0x84];
    unsigned char f8c;
    char pad8d[0x94 - 0x8d];
    unsigned char f94;
    unsigned char f95;
} Pl;

extern Match *DAT_003e1e84;
extern int DAT_003e47d4;
extern int DAT_003e47d8;
extern int DAT_00381180;
extern int DAT_00381184;
extern int DAT_00381188;
extern unsigned int DAT_003ba2c8;
extern int DAT_003f3b50;

extern int FUN_000e23f4(Match *, int);
extern int FUN_000e2454(Match *, int);
extern int FUN_000e2484(Match *, int);
extern int FUN_000e2424(Match *, int);
extern unsigned int FUN_002c7788(void);
extern int FUN_00130404(Pl *);
extern void FUN_0012f448(Pl *);
extern void FUN_0013d6dc(int, int *);
extern int FUN_001304d0(Pl *, int);
extern int FUN_001306e8(Pl *, int, int, int);
extern void FUN_002a48c4(float, int, int);

void FUN_0012e644(Pl *self, int arg)
{
    int mode = 0;
    int out;
    int r;
    float f;
    if (DAT_003e1e84->f9c == 0) {
        if (FUN_000e23f4(DAT_003e1e84, -1) != 0) {
            mode = 2;
        } else if (FUN_000e2454(DAT_003e1e84, -1) != 0) {
            mode = 1;
        } else if (FUN_000e2484(DAT_003e1e84, -1) != 0) {
            mode = 3;
        } else if (FUN_000e2424(DAT_003e1e84, -1) != 0) {
            mode = 16;
        } else if (DAT_003e1e84->fa4 == 0) {
            mode = 16;
        }
    } else if (DAT_003e1e84->fa4 == 1) {
        mode = 16;
    }
    if (mode == 0 && ((unsigned char)FUN_002c7788() & 0x10) != 0) {
        mode = 16;
    }
    self->f80 = -1;
    if (FUN_00130404(self) != 0 && self->f7b != 0 && mode != 0) {
        self->f8c = 1;
        r = FUN_00130404(self);
        if (r != 0) {
            self->f94 = 1;
            self->f95 = 1;
        } else {
            self->f94 = 0;
            self->f95 = 0;
        }
        if (mode == 16 && FUN_00130404(self) != 0 &&
            (DAT_003ba2c8 = DAT_003ba2c8 * 0x343fd + 0x269ec3, (int)((DAT_003ba2c8 >> 16) & 0x7fff) % 100 < 80)) {
            FUN_0013d6dc(60, &out);
            f = (float)FUN_001304d0(self, out);
        } else {
            f = (float)FUN_001306e8(self, mode, 0, arg);
        }
        if (f < 0.0f) {
            DAT_00381184 = DAT_00381180;
        } else {
            DAT_00381184 = DAT_00381180;
            DAT_00381188 = DAT_00381180;
            self->f80 = (int)f;
        }
        int *p = &DAT_003e47d4;
        f = (float)FUN_001306e8(self, mode, 1, arg);
        if (f < 0.0f) {
            DAT_003e47d8 = DAT_003e47d4;
        } else {
            int v = (int)f;
            *p = v;
            DAT_003e47d8 = v;
            DAT_00381188 = v;
            self->f80 = v;
        }
        if (arg != 0 && DAT_003f3b50 != 0) {
            FUN_002a48c4(65535.0f, DAT_003f3b50, 4);
        }
    } else {
        if (arg != 0) {
            if (self->f7b != 0 && mode != 0) {
                self->f79 = 1;
                FUN_0012f448(self);
                if (self->f79 != 0) {
                    DAT_00381180 = self->f58;
                } else {
                    DAT_003e47d4 = self->f58;
                }
            }
            DAT_003e47d8 = DAT_003e47d4;
            DAT_00381184 = DAT_00381180;
            if (self->f7b != 0 && mode != 0) {
                self->f8c = 1;
            }
        }
    }
}
