/* HSTMATCH module=EBOOT.BIN start=0x00123470 end=0x001237e0 symbol=FUN_00123470 lang=c99 */
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

extern Match *DAT_00338b44;
extern int DAT_0033b494;
extern int DAT_0033b498;
extern int DAT_002da1a0;
extern int DAT_002da1a4;
extern int DAT_002da1a8;
extern unsigned int DAT_00310fc8;
extern int DAT_0034a820;

extern int FUN_000de208(Match *, int);
extern int FUN_000de268(Match *, int);
extern int FUN_000de298(Match *, int);
extern int FUN_000de238(Match *, int);
extern unsigned int FUN_002b79e8(void);
extern int FUN_00125230(Pl *);
extern void FUN_00124274(Pl *);
extern void FUN_00132124(int, int *);
extern int FUN_001252fc(Pl *, int);
extern int FUN_00125514(Pl *, int, int, int);
extern void FUN_002932b8(float, int, int);

void FUN_00123470(Pl *self, int arg)
{
    int mode = 0;
    int out;
    int r;
    float f;
    if (DAT_00338b44->f9c == 0) {
        if (FUN_000de208(DAT_00338b44, -1) != 0) {
            mode = 2;
        } else if (FUN_000de268(DAT_00338b44, -1) != 0) {
            mode = 1;
        } else if (FUN_000de298(DAT_00338b44, -1) != 0) {
            mode = 3;
        } else if (FUN_000de238(DAT_00338b44, -1) != 0) {
            mode = 16;
        } else if (DAT_00338b44->fa4 == 0) {
            mode = 16;
        }
    } else if (DAT_00338b44->fa4 == 1) {
        mode = 16;
    }
    if (mode == 0 && ((unsigned char)FUN_002b79e8() & 0x10) != 0) {
        mode = 16;
    }
    self->f80 = -1;
    if (FUN_00125230(self) != 0 && self->f7b != 0 && mode != 0) {
        self->f8c = 1;
        r = FUN_00125230(self);
        if (r != 0) {
            self->f94 = 1;
            self->f95 = 1;
        } else {
            self->f94 = 0;
            self->f95 = 0;
        }
        if (mode == 16 && FUN_00125230(self) != 0 &&
            (DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3, (int)((DAT_00310fc8 >> 16) & 0x7fff) % 100 < 80)) {
            FUN_00132124(60, &out);
            f = (float)FUN_001252fc(self, out);
        } else {
            f = (float)FUN_00125514(self, mode, 0, arg);
        }
        if (f < 0.0f) {
            DAT_002da1a4 = DAT_002da1a0;
        } else {
            DAT_002da1a4 = DAT_002da1a0;
            DAT_002da1a8 = DAT_002da1a0;
            self->f80 = (int)f;
        }
        int *p = &DAT_0033b494;
        f = (float)FUN_00125514(self, mode, 1, arg);
        if (f < 0.0f) {
            DAT_0033b498 = DAT_0033b494;
        } else {
            int v = (int)f;
            *p = v;
            DAT_0033b498 = v;
            DAT_002da1a8 = v;
            self->f80 = v;
        }
        if (arg != 0 && DAT_0034a820 != 0) {
            FUN_002932b8(65535.0f, DAT_0034a820, 4);
        }
    } else {
        if (arg != 0) {
            if (self->f7b != 0 && mode != 0) {
                self->f79 = 1;
                FUN_00124274(self);
                if (self->f79 != 0) {
                    DAT_002da1a0 = self->f58;
                } else {
                    DAT_0033b494 = self->f58;
                }
            }
            DAT_0033b498 = DAT_0033b494;
            DAT_002da1a4 = DAT_002da1a0;
            if (self->f7b != 0 && mode != 0) {
                self->f8c = 1;
            }
        }
    }
}
