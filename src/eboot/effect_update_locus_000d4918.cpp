/* HSTMATCH module=EBOOT.BIN start=0x000d4918 end=0x000d4b8c symbol=FUN_000d4918 lang=c++ */
/* Clone of src/sharing_main/effect_update_locus_000d8608.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: the entry array is indexed `[(unsigned)i]` so MWCC recomputes i*32 each pass instead of adding an induction register; exact match verified; names and types await human review. */
/* Effect.cpp (same file as FUN_000d4758, assert "p.locus"): for each of the four players with a record,
   records seven bone translation rows (FUN_00055240 bone matrices) into the player's locus ring
   (FUN_000ea62c), deleting the locus when FUN_000b3558 says the player no longer qualifies or when the
   player state is 6, and creating it through FUN_000d4758 otherwise. The record step is one static
   inline expanded twice (two sets of seven Mat4 locals, as retail); the release is the usual
   `if (p) { delete p; p = 0; }` (virtual deleting dtor, slot 0). */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Mat4 {
    Vec4 r0, r1, r2, r3;
};

struct Model;

struct Rec {
    char pad0[0x58];
    Model *model;
};

struct Player {
    char pad0[0x3c];
    int state;
    char pad40[0x5bc - 0x40];
    Rec *rec;
};

struct Game {
    char pad0[0x70];
    Player *players[4];
};

struct Locus {
    virtual ~Locus();
};

struct Ent {
    int bone[7];
    Locus *locus;
};

struct Effect {
    char pad0[0x48];
    Ent *ents;
};

extern Game *DAT_003386b0;

extern "C" {
void FUN_00055240(Mat4 *out, Model *m, int bone);
void FUN_000ea62c(Locus *t, Vec4 *a, Vec4 *b, Vec4 *c, Vec4 *d, Vec4 *e, Vec4 *f, Vec4 *g);
int FUN_000b3558(Player *p);
void FUN_000d4758(Effect *self, int i);
}

static inline void Record(Ent *e, Model *m)
{
    Mat4 m0, m1, m2, m3, m4, m5, m6;
    FUN_00055240(&m0, m, e->bone[0]);
    FUN_00055240(&m1, m, e->bone[1]);
    FUN_00055240(&m2, m, e->bone[2]);
    FUN_00055240(&m3, m, e->bone[3]);
    FUN_00055240(&m4, m, e->bone[4]);
    FUN_00055240(&m5, m, e->bone[5]);
    FUN_00055240(&m6, m, e->bone[6]);
    FUN_000ea62c(e->locus, &m0.r3, &m1.r3, &m2.r3, &m3.r3, &m4.r3, &m5.r3, &m6.r3);
}

extern "C" void FUN_000d4918(Effect *self)
{
    int i;
    Player *pl;
    Rec *rec;
    Ent *e;

    for (i = 0; i < 4; i++) {
        pl = DAT_003386b0->players[i];
        if (pl != 0) {
            rec = pl->rec;
            if (rec != 0) {
                e = &self->ents[(unsigned)i];
                if (e->locus != 0) {
                    Record(e, rec->model);
                    if (FUN_000b3558(pl) == 0) {
                        if (e->locus) {
                            delete e->locus;
                            e->locus = 0;
                        }
                    }
                } else {
                    if (FUN_000b3558(pl) != 0) {
                        FUN_000d4758(self, i);
                        if (e->locus != 0) {
                            Record(e, rec->model);
                        }
                    }
                }
                if (pl->state == 6 && e->locus != 0) {
                    if (e->locus) {
                        delete e->locus;
                        e->locus = 0;
                    }
                }
            }
        }
    }
}
