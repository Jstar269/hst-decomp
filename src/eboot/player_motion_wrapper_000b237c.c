/* HSTMATCH module=EBOOT.BIN start=0x000b237c end=0x000b270c symbol=FUN_000b237c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
enum {
    MOTION_NONE = 0x7fff,   /* motion id meaning "leave this slot alone" */
    MOTION_ROW_COUNT = 0x115 /* rows of the motion table */
};

typedef struct CVec CVec;
typedef struct Mat16 Mat16;
typedef struct Row Row;
typedef struct Track2 Track2;
typedef struct ModelEff ModelEff;
typedef struct Model Model;
typedef struct Slot Slot;
typedef struct World World;
typedef struct Eff Eff;
typedef struct Player Player;
struct CVec {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat16 { float f[16]; } __attribute__((aligned(16)));

struct Row {
    signed char c0;
    char pad1[11];
    short s12;
    char pad14[2];
};
struct Track2 {
    int m0;
    char pad4[4];
    unsigned char m8;
    char pad9[0x14 - 9];
    float time;
    char pad18[0x34 - 0x18];
};
struct ModelEff {
    char pad0[0xf0];
    Track2 tracks[3];
};
struct Model { char pad0[0x58]; ModelEff *m58; };
struct Slot { char pad0[0x50]; short s50; signed char c52; char pad53; float f54; int f58; };
struct World { char pad0[0x780]; int f780; };
struct Eff { char pad[8]; };
struct Player {
    char pad0[0x148];
    int m148;
    char pad14c[0x1b4 - 0x14c];
    unsigned char m1b4;
    char pad1b5[0x550 - 0x1b5];
    Mat16 mat;
    char pad590[0x5bc - 0x590];
    Model *model;
    char pad5c0[0x5d0 - 0x5c0];
    Eff effect;
};

extern unsigned char DAT_003386b8;
extern World *DAT_00338af0;
extern Row DAT_002beb78[];
extern char DAT_002d45ac[];
void FUN_00093524(float, Model *);
void FUN_000b270c(Player *, int, unsigned char, float, int, unsigned char, float, unsigned char, int, int, float);
Slot *FUN_000c4ba0(World *, int);
int FUN_00057838(Eff *, int);
void FUN_00057b58(Eff *, int, int, float);
void FUN_00058f38(float, Eff *, int);
void FUN_00059084(Eff *, int);
void FUN_000550ec(float, Eff *);
void FUN_0005548c(CVec *, ModelEff *, char *);
float FUN_000224d8(CVec *, CVec *);
float FUN_00022e44(float);
void FUN_00022498(CVec *, CVec *, float);
void FUN_00055044(Eff *, CVec *);

/* Start the motions through the player setter, then record the track state per slot and, for a table row
   with an effect index, restart the effect with a scaled copy of the player matrix. */
void FUN_000b237c(Player *pl, float speed1, int id1, unsigned char c1, int id2, unsigned char c2, float speed2,
                  unsigned char extra, int flag1, int flag2, float add)
{
    FUN_00093524(1.0f, pl->model);
    FUN_000b270c(pl, id1, c1, speed1, id2, c2, speed2, extra, flag1, flag2, add);
    int row = -1;
    int ch = 0;
    int ids[2] = { id1, id2 };
    int k = 0;
    int *ip = ids;
    int off1 = 0;
    int off2 = 0;
    do {
        int id = *ip;
        if (id >= 0 && id < MOTION_ROW_COUNT) {
            if (DAT_002beb78[id].s12 >= 0) {
                ch = DAT_002beb78[id].c0;
                row = DAT_002beb78[id].s12;
            }
        }
        if (id != MOTION_NONE) {
            int b = DAT_003386b8 != 0;
            if (b) {
                b = !pl->m1b4;
            }
            if (b && DAT_00338af0 != 0) {
                Slot *s = (Slot *)((char *)FUN_000c4ba0(DAT_00338af0, pl->m148) + off1);
                s->f58 = DAT_00338af0->f780;
                ModelEff *me = pl->model->m58;
                float f = me ? *(float *)((char *)me + off2 + 0x104) : 0.0f;
                unsigned char a = me ? *(unsigned char *)((char *)me + off2 + 0xf8) : 0;
                int v = me ? *(int *)((char *)me + off2 + 0xf0) : -1;
                s->s50 = v;
                s->c52 = a;
                s->f54 = f;
            }
        }
        k++;
        ip++;
        off1 += 12;
        off2 += 0x34;
    } while (k < 2);
    if (row >= 0) {
        int idx = row - 248;
        if (FUN_00057838(&pl->effect, idx) != 0) {
            FUN_00057b58(&pl->effect, 0, idx, 0.0f);
            ModelEff *me = pl->model->m58;
            float f = me ? me->tracks[ch].time : 0.0f;
            FUN_00058f38(f, &pl->effect, -1);
            FUN_00059084(&pl->effect, -1);
            FUN_000550ec(1.0f, &pl->effect);
            Mat16 m;
            m.f[0] = pl->mat.f[0];
            m.f[1] = pl->mat.f[1];
            m.f[2] = pl->mat.f[2];
            m.f[3] = pl->mat.f[3];
            m.f[4] = pl->mat.f[4];
            m.f[5] = pl->mat.f[5];
            m.f[6] = pl->mat.f[6];
            m.f[7] = pl->mat.f[7];
            m.f[8] = pl->mat.f[8];
            m.f[9] = pl->mat.f[9];
            m.f[10] = pl->mat.f[10];
            m.f[11] = pl->mat.f[11];
            m.f[12] = pl->mat.f[12];
            m.f[13] = pl->mat.f[13];
            m.f[14] = pl->mat.f[14];
            m.f[15] = pl->mat.f[15];
            Mat16 tmpm;
            FUN_0005548c((CVec *)&tmpm, pl->model->m58, DAT_002d45ac);
            float len = 100.0f * FUN_00022e44(FUN_000224d8((CVec *)&tmpm, (CVec *)&tmpm));
            FUN_00022498((CVec *)&m.f[0], (CVec *)&m.f[0], len);
            FUN_00022498((CVec *)&m.f[4], (CVec *)&m.f[4], len);
            FUN_00022498((CVec *)&m.f[8], (CVec *)&m.f[8], len);
            FUN_00055044(&pl->effect, (CVec *)&m.f[0]);
        }
    }
}
