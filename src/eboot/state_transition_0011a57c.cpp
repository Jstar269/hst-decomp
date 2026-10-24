/* HSTMATCH module=EBOOT.BIN start=0x0011a57c end=0x0011a7d8 symbol=FUN_0011a57c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; earlier declaration order int s1, s0 assigns s1=$17 and s0=$16; int off=f50*4, base=(int)DAT_003386b0 gives addu v1, a0, v1; names and types await human review. */

struct Player {
    char pad[0x144];
    int f144;
};

struct Game {
    char pad[0x70];
    Player *players[1];
};

struct GlobB {
    char pad[0x50];
    int f50;
};

struct Obj {
    char pad[0x2d0];
    int f2d0;
    int f2d4;
    int f2d8;
    char pad2[0x314 - 0x2dc];
    int f314;
    int f318;
};

extern "C" {
extern Game *DAT_003386b0;
extern GlobB *DAT_00338b44;

extern int FUN_000de2c8(GlobB *, int);
extern int FUN_000de3f0(GlobB *, int);
extern int FUN_000de51c(GlobB *, int);
extern int FUN_000dea20(GlobB *, int);

void FUN_0011a57c(Obj *self);
}

void FUN_0011a57c(Obj *self) {
    self->f314 = 27;
    self->f318 = 27;

    int s1;
    int s0 = self->f2d0;
    int v1 = self->f2d4;
    s1 = !s0;

    if (v1 != s0) {
        if (FUN_000dea20(DAT_00338b44, s0) && self->f2d8 < 310) {
            self->f2d4 = s0;
            self->f2d8 = 310;
            self->f314 = 11;
            self->f318 = 23;
            return;
        }
        if (FUN_000de51c(DAT_00338b44, s0) && self->f2d8 < 210) {
            self->f2d4 = s0;
            self->f2d8 = 210;
            self->f314 = 17;
            self->f318 = 22;
            return;
        }
        if ((FUN_000de2c8(DAT_00338b44, s0) || FUN_000de3f0(DAT_00338b44, s0)) && self->f2d8 < 110) {
            self->f2d4 = s0;
            self->f2d8 = 110;
            self->f314 = 5;
            int off = DAT_00338b44->f50 * 4;
            int base = (int)DAT_003386b0;
            Player *p = *(Player **)(off + base + 0x70);
            self->f318 = (self->f2d0 == p->f144) ? 21 : 24;
            return;
        }
    }

    if (self->f2d4 != s1) {
        if (FUN_000dea20(DAT_00338b44, s1) && self->f2d8 < 300) {
            self->f2d4 = s1;
            self->f2d8 = 300;
            self->f314 = 11;
            self->f318 = 25;
            return;
        }
        if (FUN_000de51c(DAT_00338b44, s1) && self->f2d8 < 200) {
            self->f2d4 = s1;
            self->f2d8 = 200;
            self->f314 = 17;
            return;
        }
        if ((FUN_000de2c8(DAT_00338b44, s1) || FUN_000de3f0(DAT_00338b44, s1)) && self->f2d8 < 100) {
            self->f2d4 = s1;
            self->f2d8 = 100;
            self->f314 = 5;
            return;
        }
    }
}
