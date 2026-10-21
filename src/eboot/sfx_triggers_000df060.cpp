/* HSTMATCH module=EBOOT.BIN start=0x000df060 end=0x000df444 symbol=FUN_000df060 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the other-player flag is `if (f61 != 0 && f98 >= 0 && f9c != players[f98]->f144) b = true; else b = false;` (one && chain with both arms assigned: retail's shared false label), kinds 8/9/10 and 11/12 are switch statements, the A arm is the else of `if (F(..) != 0)`, the 4-float copy is four field assignments; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
};
struct Player {
    char pad0[0x144];
    unsigned f144;
    char pad1[0x440 - 0x148];
    int f440;
    char pad2[0x494 - 0x444];
    float f494;
    char pad3[0x4cc - 0x498];
    unsigned char f4cc;
    unsigned char f4cd;
};
struct Rec {
    char pad[0x10];
    Vec4 v10;
};
struct Cell {
    char pad[0x26c];
    Rec *f26c;
    int f270;
};
struct Game {
    char pad0[0x70];
    Player *players[6];
    Cell *f88;
    char pad1[0xa8 - 0x8c];
    void *fa8;
};
struct Self {
    char pad0[0x61];
    unsigned char f61;
    unsigned char f62;
    char pad1[0x67 - 0x63];
    unsigned char f67;
    char pad2[0x6c - 0x68];
    int f6c;
    char pad3[0x71 - 0x70];
    unsigned char f71;
    unsigned char f72;
    unsigned char f73;
    unsigned char f74;
    char pad4[0x7c - 0x75];
    int f7c;
    char pad5[0x84 - 0x80];
    unsigned char f84;
    unsigned char f85;
    char pad6[0x90 - 0x86];
    int f90;
    unsigned f94;
    int f98;
    unsigned f9c;
};
extern Game *DAT_003386b0;
extern "C" {
Player *FUN_0008882c(Game *);
int FUN_00088880(Game *, int);
void FUN_001b5640(void *, int);
int FUN_000a8c18(Player *, Vec4 *);
}

extern "C" void FUN_000df060(Self *self)
{
    Player *pl = FUN_0008882c(DAT_003386b0);
    if (self->f9c == pl->f144) {
        if (FUN_00088880(DAT_003386b0, self->f98) != 0) {
            if (self->f71 != 0) {
                FUN_001b5640(DAT_003386b0->fa8, 199);
            }
        } else {
            if (self->f72 != 0) {
                FUN_001b5640(DAT_003386b0->fa8, 200);
            }
        }
        return;
    }
    if (FUN_00088880(DAT_003386b0, self->f98) != 0) {
        Cell *cell = DAT_003386b0->f88;
        Rec **pp = &cell->f26c;
        int off = 0;
        if (cell->f270 == 0) {
            off = cell->f270 - 1;
        }
        Rec *rec = *pp + off;
        Vec4 v;
        v.x = rec->v10.x;
        v.y = rec->v10.y;
        v.z = rec->v10.z;
        v.w = rec->v10.w;
        if (self->f85 != 0) {
            FUN_001b5640(DAT_003386b0->fa8, 202);
        }
        bool b;
        if (self->f61 != 0 && self->f98 >= 0 && self->f9c != DAT_003386b0->players[self->f98]->f144) {
            b = true;
        } else {
            b = false;
        }
        if (b) {
            switch (self->f6c) {
            case 8:
            case 9:
            case 10:
                FUN_001b5640(DAT_003386b0->fa8, 193);
                break;
            default:
                if (FUN_000a8c18(pl, &v) != 0) {
                    FUN_001b5640(DAT_003386b0->fa8, 192);
                }
            }
        } else {
            if (self->f84 != 0) {
                switch (self->f6c) {
                case 11:
                    FUN_001b5640(DAT_003386b0->fa8, 194);
                    break;
                case 12:
                    FUN_001b5640(DAT_003386b0->fa8, 195);
                    if (self->f7c > 0) {
                        FUN_001b5640(DAT_003386b0->fa8, 190);
                    } else if (self->f7c < 0) {
                        FUN_001b5640(DAT_003386b0->fa8, 191);
                    }
                    break;
                }
            }
        }
        if (self->f67 != 0) {
            FUN_001b5640(DAT_003386b0->fa8, 196);
        }
    } else {
        if (self->f94 == (pl->f144 ^ 1)) {
            if (self->f90 >= 3) {
                if (pl->f494 == 0.0f) {
                    FUN_001b5640(DAT_003386b0->fa8, 203);
                }
            }
            if (pl->f4cc != 0) {
                if (pl->f4cd == 0) {
                    FUN_001b5640(DAT_003386b0->fa8, 197);
                }
            }
            if (pl->f4cd != 0) {
                FUN_001b5640(DAT_003386b0->fa8, 198);
            }
            if (self->f73 != 0) {
                FUN_001b5640(DAT_003386b0->fa8, 205);
            }
            if (self->f74 != 0) {
                FUN_001b5640(DAT_003386b0->fa8, 206);
            }
        }
    }
    if (pl->f440 >= 2) {
        FUN_001b5640(DAT_003386b0->fa8, 204);
    }
    if (self->f62 != 0) {
        FUN_001b5640(DAT_003386b0->fa8, 207);
    }
}
