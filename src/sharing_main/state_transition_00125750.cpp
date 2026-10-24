/* HSTMATCH module=hstp_trans_main.prx start=0x00125750 end=0x001259ac symbol=FUN_00125750 lang=c++ */
/* Clone of src/eboot/state_transition_0011a57c.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; earlier declaration order int s1, s0 assigns s1=$17 and s0=$16; int off=f50*4, base=(int)DAT_003e19f0 gives addu v1, a0, v1; names and types await human review. */

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
extern Game *DAT_003e19f0;
extern GlobB *DAT_003e1e84;

extern int FUN_000e24b4(GlobB *, int);
extern int FUN_000e25dc(GlobB *, int);
extern int FUN_000e2708(GlobB *, int);
extern int FUN_000e2c0c(GlobB *, int);

void FUN_00125750(Obj *self);
}

void FUN_00125750(Obj *self) {
    self->f314 = 27;
    self->f318 = 27;

    int s1;
    int s0 = self->f2d0;
    int v1 = self->f2d4;
    s1 = !s0;

    if (v1 != s0) {
        if (FUN_000e2c0c(DAT_003e1e84, s0) && self->f2d8 < 310) {
            self->f2d4 = s0;
            self->f2d8 = 310;
            self->f314 = 11;
            self->f318 = 23;
            return;
        }
        if (FUN_000e2708(DAT_003e1e84, s0) && self->f2d8 < 210) {
            self->f2d4 = s0;
            self->f2d8 = 210;
            self->f314 = 17;
            self->f318 = 22;
            return;
        }
        if ((FUN_000e24b4(DAT_003e1e84, s0) || FUN_000e25dc(DAT_003e1e84, s0)) && self->f2d8 < 110) {
            self->f2d4 = s0;
            self->f2d8 = 110;
            self->f314 = 5;
            int off = DAT_003e1e84->f50 * 4;
            int base = (int)DAT_003e19f0;
            Player *p = *(Player **)(off + base + 0x70);
            self->f318 = (self->f2d0 == p->f144) ? 21 : 24;
            return;
        }
    }

    if (self->f2d4 != s1) {
        if (FUN_000e2c0c(DAT_003e1e84, s1) && self->f2d8 < 300) {
            self->f2d4 = s1;
            self->f2d8 = 300;
            self->f314 = 11;
            self->f318 = 25;
            return;
        }
        if (FUN_000e2708(DAT_003e1e84, s1) && self->f2d8 < 200) {
            self->f2d4 = s1;
            self->f2d8 = 200;
            self->f314 = 17;
            return;
        }
        if ((FUN_000e24b4(DAT_003e1e84, s1) || FUN_000e25dc(DAT_003e1e84, s1)) && self->f2d8 < 100) {
            self->f2d4 = s1;
            self->f2d8 = 100;
            self->f314 = 5;
            return;
        }
    }
}
