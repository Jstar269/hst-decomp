/* HSTMATCH module=hstp_trans_main.prx start=0x00099ed0 end=0x0009aa88 symbol=FUN_00099ed0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Motion { int data; int pad[3]; };

struct MotionEntry {        /* 16 bytes, table at DAT_002ceb64 */
    signed char loop;       /* 0 */
    signed char common;     /* 1 */
    signed char side;       /* 2 */
    signed char variant;    /* 3 */
    signed char kind;       /* 4 */
    signed char gender;     /* 5 */
    signed char per_face;   /* 6 */
    char pad7;
    const char *name;       /* 8 */
    int pad12;
};

struct PlayerData { char pad0[0x62]; signed char kind : 4; };

struct Slot {               /* 0x120 bytes, table at DAT_003eaaf0 */
    char pad0[0x18];
    short id;
    char pad1a[0x7f - 0x1a];
    unsigned char team;
    char pad80[0x11c - 0x80];
    int skin;
};

struct Hands { char pad0[0x12]; signed char right; signed char left; };

struct FaceInfo { short id; char pad2[0x24 - 2]; unsigned char sex; };

struct Anim {
    virtual void d0();
    virtual void d1();
    virtual void Load(const char *path, int a, int b, int c, int d, int e);
};

struct Tag {};

struct MotionVec { Motion **data; unsigned size; unsigned cap; };

struct Model { char pad0[0x50]; int enabled; };

struct Chara {
    char pad0[0x148];
    int slot;
    char pad14c[0x154 - 0x14c];
    FaceInfo *face;
    int locked;
    char pad15c[0x164 - 0x15c];
    int skin;
    char pad168[0x5bc - 0x168];
    Model *model;
    MotionVec motions;
    char pad5cc[0x5d0 - 0x5cc];
    Anim anim;
    char pad5d4[0x65c - 0x5d4];
    int noface;
};

struct Game { char pad0[0x9c]; int m9c; char pada0[0xa8 - 0xa0]; int ma8; };
struct Opts { char pad0[0x45]; unsigned char two; };

extern Game *DAT_003e19f0;
extern int DAT_003e1ab0;
extern int DAT_003e1e48;
extern Opts *DAT_003e1e84;
extern Slot DAT_003eaaf0[];
extern Motion **DAT_003e1ab4[2];
extern unsigned char DAT_003e1abc;
extern unsigned char DAT_003e19f8;
extern char DAT_003b7ebc[];
extern MotionEntry DAT_002ceb64[];
extern int DAT_003f3aac;

extern const char DAT_0037a6c0[];   /* "" */
extern const char DAT_0037a844[];   /* "ad_" */
extern const char DAT_0037a81c[];   /* "game/400_pc/face/%scommon_motion_%d.xb" */
extern const char DAT_0037a848[];   /* "npc999" */
extern const char DAT_0037a850[];   /* "999/" */
extern const char DAT_0037a858[];   /* "099/" */
extern const char *DAT_0037a7e8[];  /* { "s", "d" } */
extern const char *DAT_0037a7f8[];  /* { "_m", "_f" } */
extern const char DAT_0037a87c[];   /* "%s%s%s.i3m" */
extern const char DAT_0037a888[];   /* "data/chara/adhoc/motion/" */
extern const char DAT_0037a8a4[];   /* "data/chara/motion/" */
extern const char DAT_0037a8c0[];   /* "game/400_pc/face/%sface%03d_anim.xb" */
extern const char DAT_0037a7e0[];   /* "s" */
extern const char DAT_0037a7e4[];   /* "d" */
extern const char DAT_0037a7f0[];   /* "_m" */
extern const char DAT_0037a7f4[];   /* "_f" */
extern const char DAT_0037a8e4[];   /* "yaji/00/" */
extern const char DAT_0037a8f0[];   /* "%02d/" */
extern const char DAT_0037a8f8[];   /* "%s%s%s.i3r" */
extern const char DAT_0037a904[];   /* "_00" */
extern const char DAT_0037a908[];   /* "_01" */
extern const char DAT_0037a90c[];   /* "data/chara/motion/%02d/%s" */
extern const char DAT_0037a928[];   /* "data/chara/motion/%s%s" */
extern const char DAT_0037a940[];   /* ".tat" */
extern const char DAT_0037a948[];   /* "data/chara/model/face/%02d/" */

void *operator new(unsigned int);

extern "C" {
void FUN_001220cc(int);
void FUN_0009aa88(Chara *);
PlayerData *FUN_000dca74(int, int, int);
void *FUN_00000a90(unsigned int);
void *FUN_000114c0(void *, int, unsigned int);
void FUN_0001c5f4(char *, const char *, const char *, int);
void FUN_0001c73c(char *);
int FUN_00014d64(const char *, const char *);
int FUN_000143b0(char *, const char *, ...);
char *FUN_00014788(char *, const char *);
Motion *FUN_0005697c(void *);
void FUN_00056a58(Motion *, const char *, int);
void FUN_000569f4(Motion *, short);
Hands *FUN_000b6e80(Chara *);
void FUN_00058090(Anim *, int, Motion *, int);
void FUN_00094ce4(Model *, int, const char *, const char *, int, int);
void FUN_000b75a4(MotionVec *, Motion *const *, Tag);
unsigned char FUN_0025e0c0(int, int, int);
int FUN_001c40a0(char *, int);
void FUN_001c319c(int, int, char *, int);
}

/* Debug build: assertions print through the (empty) variadic debug printf and hang. */
extern const char DAT_0037a6cc[];   /* "assertion \"%s\" failed: file \"%s\", line %d
" */
extern const char DAT_0037a704[];   /* "Player.cpp" */
extern const char DAT_0037a800[];   /* "s_CommonMotionRefCount == 0" */
extern const char DAT_0037a860[];   /* "g_AnimationList[i].sex == 0" */
extern const char DAT_0037a8b8[];   /* "false" */
extern "C" void FUN_00097e3c(...);
#define HST_ASSERT(cond, text, line)     do { if (!(cond)) { FUN_00097e3c(DAT_0037a6cc, text, DAT_0037a704, line); for (;;) {} } } while (0)

#define IsAdhoc() (DAT_003e1abc != 0 || DAT_003e19f8 != 0)

static inline void PushBack(MotionVec *v, Motion *const &x, Tag)
{
    if (v->size < v->cap) {
        v->size++;
        v->data[v->size - 1] = x;
    }
    else
        FUN_000b75a4(v, &x, Tag());
}

extern "C" void FUN_00099ed0(Chara *self)
{
    char name[128];
    char motion[64];
    char path[128];
    char model[128];
    int enabled;
    int face;
    PlayerData *pd;
    bool busy;
    int n;
    int i;
    const char *right;
    const char *left;
    const char *sex;
    int female;

    FUN_001220cc(DAT_003e19f0->m9c);
    DAT_003e1ab0++;
    FUN_0009aa88(self);
    DAT_003e1ab0--;
    enabled = self->model->enabled;
    face = self->face->id;
    pd = FUN_000dca74(DAT_003e1e48, 0, face);

    busy = false;
    if (DAT_003e1e84->two)
        n = 2;
    else
        n = 4;
    for (i = 0; i < n; i++) {
        if (FUN_000dca74(DAT_003e1e48, 0, DAT_003eaaf0[i].id)->kind != 0) {
            busy = true;
            break;
        }
    }

    if (DAT_003e1ab4[0] == 0) {
        int j;
        int base;
        HST_ASSERT(DAT_003e1ab0 == 0, DAT_0037a800, 1984);
        for (unsigned k = 0; k < 2; k++) {
            DAT_003e1ab4[k] = (Motion **)FUN_00000a90(0x454);
            FUN_000114c0(DAT_003e1ab4[k], 0, 0x454);
        }
        for (j = 0, base = 0; j < 4; base += 0x115, j++) {
            int end;
            int idx;
            FUN_0001c5f4(DAT_003b7ebc, DAT_0037a81c, IsAdhoc() ? DAT_0037a844 : DAT_0037a6c0, j);
            end = (base + 0x115) / 4;
            for (idx = base / 4; idx < end; idx++) {
                MotionEntry *m = &DAT_002ceb64[idx];
                if ((idx < 174 || idx >= 198 || busy) && m->common) {
                    int cnt;
                    int k;
                    if (FUN_00014d64(m->name, DAT_0037a848) != 0)
                        FUN_000143b0(name, DAT_0037a850);
                    else
                        FUN_000143b0(name, DAT_0037a858);
                    cnt = 1;
                    if (m->side || m->gender)
                        cnt = 2;
                    for (k = 0; k < cnt; k++) {
                        Motion *mem;
                        Motion *mt;
                        if (m->side) {
                            HST_ASSERT(m->gender == 0, DAT_0037a860, 2065);
                            FUN_000143b0(motion, m->name, DAT_0037a7e8[k]);
                        } else if (m->gender)
                            FUN_000143b0(motion, m->name, DAT_0037a7f8[k]);
                        else
                            FUN_000143b0(motion, m->name);
                        FUN_000143b0(path, DAT_0037a87c, IsAdhoc() ? DAT_0037a888 : DAT_0037a8a4, name, motion);
                        mem = (Motion *)operator new(0x10);
                        if (mem)
                            mem = FUN_0005697c(mem);
                        DAT_003e1ab4[k][idx] = mem;
                        FUN_00056a58(DAT_003e1ab4[k][idx], path, 0);
                        mt = DAT_003e1ab4[k][idx];
                        if (mt->data == 0) {
                            HST_ASSERT(false, DAT_0037a8b8, 2086);
                            if (mt) {
                                FUN_000569f4(mt, 1);
                                DAT_003e1ab4[k][idx] = 0;
                            }
                        }
                    }
                }
            }
            FUN_0001c73c(DAT_003b7ebc);
        }
    }

    DAT_003e1ab0++;
    FUN_0001c5f4(DAT_003b7ebc, DAT_0037a8c0, IsAdhoc() ? DAT_0037a844 : DAT_0037a6c0, face);
    if (FUN_000b6e80(self)->right == 1)
        right = DAT_0037a7e0;
    else
        right = DAT_0037a7e4;
    if (FUN_000b6e80(self)->left == 1)
        left = DAT_0037a7e0;
    else
        left = DAT_0037a7e4;
    female = 0;
    if (face < 100)
        female = self->face->sex != 1;
    else if (face >= 100 && face < 200)
        female = 1;
    else if (face >= 200 && face < 300)
        female = 0;
    if (female == 0)
        sex = DAT_0037a7f0;
    else
        sex = DAT_0037a7f4;

    for (int j = 0; j < 0x115; j++) {
        MotionEntry *e = &DAT_002ceb64[j];
        Motion *mot = 0;
        if (e->kind != 0) {
            int want = pd->kind == 0 ? 1 : 2;
            if (want != e->kind) goto add;
        }
        {
            int load = e->loop <= 0;
            if (e->common) {
                int t;
                if (FUN_00014d64(e->name, DAT_0037a848) != 0)
                    FUN_000143b0(name, DAT_0037a850);
                else
                    FUN_000143b0(name, DAT_0037a858);
                if (e->side)
                    FUN_000143b0(motion, e->name, e->side == 1 ? right : left);
                else if (e->gender)
                    FUN_000143b0(motion, e->name, sex);
                else
                    FUN_000143b0(motion, e->name);
                t = 0;
                if (e->side) {
                    signed char c;
                    if (e->side == 1)
                        c = FUN_000b6e80(self)->right;
                    else
                        c = FUN_000b6e80(self)->left;
                    t = c - 1;
                }
                if (e->gender)
                    t = female;
                mot = DAT_003e1ab4[t][j];
            } else {
                if (j >= 248 && j < 248) {
                    FUN_000143b0(name, DAT_0037a8e4);
                    FUN_000143b0(motion, e->name);
                } else {
                    FUN_000143b0(name, DAT_0037a8f0, face);
                    if (e->side)
                        FUN_000143b0(motion, e->name, face, e->side == 1 ? right : left);
                    else if (e->gender)
                        FUN_000143b0(motion, e->name, face, sex);
                    else
                        FUN_000143b0(motion, e->name, face);
                }
                FUN_000143b0(path, DAT_0037a87c, IsAdhoc() ? DAT_0037a888 : DAT_0037a8a4, name, motion);
                if (pd && pd->kind == 0) {
                    Motion *mem = (Motion *)operator new(0x10);
                    if (mem)
                        mem = FUN_0005697c(mem);
                    mot = mem;
                    FUN_00056a58(mot, path, 0);
                    if (mot->data == 0) {
                        if (j < 248 || j >= 0x115)
                            HST_ASSERT(false, DAT_0037a8b8, 2218);
                        if (mot) {
                            FUN_000569f4(mot, 1);
                            mot = 0;
                        }
                    }
                }
            }
            if (j >= 248 && j < 0x115) {
                if (mot) {
                    if (self->noface == 0) {
                        char path2[128];
                        FUN_000143b0(path2, DAT_0037a8f8, IsAdhoc() ? DAT_0037a888 : DAT_0037a8a4, name, motion);
                        self->anim.Load(path2, 0, 0, 0, 0, 0);
                    }
                    FUN_00058090(&self->anim, j - 248, mot, 0);
                }
                load = 0;
            }
            if (enabled && load) {
                int common = 0;
                if (e->variant >= 0)
                    FUN_00014788(motion, e->variant == 0 ? DAT_0037a904 : DAT_0037a908);
                if (e->per_face && pd->kind == 0) {
                    FUN_000143b0(path, DAT_0037a90c, face, motion);
                } else {
                    FUN_000143b0(path, DAT_0037a928, name, motion);
                    common = 1;
                }
                FUN_00014788(path, DAT_0037a940);
                FUN_000143b0(model, DAT_0037a948, face);
                FUN_00094ce4(self->model, j, path, model, 0, common);
            }
        }
    add:
        PushBack(&self->motions, mot, Tag());
    }
    FUN_0001c73c(DAT_003b7ebc);

    {
        char *key = (char *)self->face + 0x2d;
        if (!self->locked && FUN_0025e0c0(DAT_003f3aac, 10, DAT_003eaaf0[self->slot].team) == 0 && !DAT_003e19f8)
            self->skin = 0;
        else
            self->skin = FUN_001c40a0(key, DAT_003eaaf0[self->slot].skin);
        FUN_001c319c(DAT_003e19f0->ma8, self->slot, key, self->skin);
    }
}
