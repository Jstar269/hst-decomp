/* HSTMATCH module=hstp_trans_main.prx start=0x000b53d0 end=0x000b5760 symbol=FUN_000b53d0 lang=c99 */
/* Clone of src/eboot/player_motion_wrapper_000b237c.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern unsigned char DAT_003e19f8;
extern World *DAT_003e1e30;
extern Row DAT_002ceb64[];
extern char DAT_0037aa74[];
void FUN_00095448(float, Model *);
void FUN_000b5760(Player *, int, unsigned char, float, int, unsigned char, float, unsigned char, int, int, float);
Slot *FUN_000c8538(World *, int);
int FUN_0005848c(Eff *, int);
void FUN_000587ac(Eff *, int, int, float);
void FUN_00059c1c(float, Eff *, int);
void FUN_00059d68(Eff *, int);
void FUN_00055c0c(float, Eff *);
void FUN_00056008(CVec *, ModelEff *, char *);
float FUN_00022500(CVec *, CVec *);
float FUN_00022e6c(float);
void FUN_000224c0(CVec *, CVec *, float);
void FUN_00055b64(Eff *, CVec *);

void FUN_000b53d0(Player *pl, float speed1, int id1, unsigned char c1, int id2, unsigned char c2, float speed2,
                  unsigned char extra, int flag1, int flag2, float add)
{
    FUN_00095448(1.0f, pl->model);
    FUN_000b5760(pl, id1, c1, speed1, id2, c2, speed2, extra, flag1, flag2, add);
    int row = -1;
    int ch = 0;
    int ids[2] = { id1, id2 };
    int k = 0;
    int *ip = ids;
    int off1 = 0;
    int off2 = 0;
    do {
        int id = *ip;
        if (id >= 0 && id < 0x115) {
            if (DAT_002ceb64[id].s12 >= 0) {
                ch = DAT_002ceb64[id].c0;
                row = DAT_002ceb64[id].s12;
            }
        }
        if (id != 0x7fff) {
            int b = DAT_003e19f8 != 0;
            if (b) {
                b = !pl->m1b4;
            }
            if (b && DAT_003e1e30 != 0) {
                Slot *s = (Slot *)((char *)FUN_000c8538(DAT_003e1e30, pl->m148) + off1);
                s->f58 = DAT_003e1e30->f780;
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
        if (FUN_0005848c(&pl->effect, idx) != 0) {
            FUN_000587ac(&pl->effect, 0, idx, 0.0f);
            ModelEff *me = pl->model->m58;
            float f = me ? me->tracks[ch].time : 0.0f;
            FUN_00059c1c(f, &pl->effect, -1);
            FUN_00059d68(&pl->effect, -1);
            FUN_00055c0c(1.0f, &pl->effect);
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
            FUN_00056008((CVec *)&tmpm, pl->model->m58, DAT_0037aa74);
            float len = 100.0f * FUN_00022e6c(FUN_00022500((CVec *)&tmpm, (CVec *)&tmpm));
            FUN_000224c0((CVec *)&m.f[0], (CVec *)&m.f[0], len);
            FUN_000224c0((CVec *)&m.f[4], (CVec *)&m.f[4], len);
            FUN_000224c0((CVec *)&m.f[8], (CVec *)&m.f[8], len);
            FUN_00055b64(&pl->effect, (CVec *)&m.f[0]);
        }
    }
}
