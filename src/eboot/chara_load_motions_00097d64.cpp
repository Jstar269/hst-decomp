/* HSTMATCH module=EBOOT.BIN start=0x00097d64 end=0x00098870 symbol=FUN_00097d64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

enum {
    MOTION_COUNT = 0x115,      /* entries in the motion table */
    FACE_MOTION_FIRST = 248,   /* first entry played on the face animation */
    COMMON_SET_COUNT = 2,      /* common motion sets (two variants) */
    SKIN_KEY_OFFSET = 0x2d     /* offset of the skin key string in the face record */
};

struct Motion { int data; int pad[3]; };

struct MotionEntry {        /* 16 bytes, table at DAT_002beb78 */
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

struct Slot {               /* 0x120 bytes, table at DAT_003417b8 */
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

extern Game *DAT_003386b0;
extern int DAT_00338770;
extern int DAT_00338b08;
extern Opts *DAT_00338b44;
extern Slot DAT_003417b8[];
extern Motion **DAT_00338774[COMMON_SET_COUNT];
extern unsigned char DAT_0033877c;
extern unsigned char DAT_003386b8;
extern char DAT_0030ebf4[];
extern MotionEntry DAT_002beb78[];
extern int DAT_0034a77c;

extern const char DAT_002d435c[];   /* "" */
extern const char DAT_002d4468[];   /* "ad_" */
extern const char DAT_002d4440[];   /* "game/400_pc/face/%scommon_motion_%d.xb" */
extern const char DAT_002d446c[];   /* "npc999" */
extern const char DAT_002d4474[];   /* "999/" */
extern const char DAT_002d447c[];   /* "099/" */
extern const char *DAT_002d4428[];  /* { "s", "d" } */
extern const char *DAT_002d4438[];  /* { "_m", "_f" } */
extern const char DAT_002d4484[];   /* "%s%s%s.i3m" */
extern const char DAT_002d4490[];   /* "data/chara/adhoc/motion/" */
extern const char DAT_002d44ac[];   /* "data/chara/motion/" */
extern const char DAT_002d44c0[];   /* "game/400_pc/face/%sface%03d_anim.xb" */
extern const char DAT_002d4420[];   /* "s" */
extern const char DAT_002d4424[];   /* "d" */
extern const char DAT_002d4430[];   /* "_m" */
extern const char DAT_002d4434[];   /* "_f" */
extern const char DAT_002d44e4[];   /* "yaji/00/" */
extern const char DAT_002d44f0[];   /* "%02d/" */
extern const char DAT_002d44f8[];   /* "%s%s%s.i3r" */
extern const char DAT_002d4504[];   /* "_00" */
extern const char DAT_002d4508[];   /* "_01" */
extern const char DAT_002d450c[];   /* "data/chara/motion/%02d/%s" */
extern const char DAT_002d4528[];   /* "data/chara/motion/%s%s" */
extern const char DAT_002d4540[];   /* ".tat" */
extern const char DAT_002d4548[];   /* "data/chara/model/face/%02d/" */

void *operator new(unsigned int);

extern "C" {
void FUN_00117128(int);
void FUN_00098870(Chara *);
PlayerData *FUN_000d8c24(int, int, int);
void *FUN_00000a90(unsigned int);
void *FUN_000114c0(void *, int, unsigned int);
void FUN_0001ca58(char *, const char *, const char *, int);
void FUN_0001cb88(char *);
int FUN_00014d64(const char *, const char *);
int FUN_000143b0(char *, const char *, ...);
char *FUN_00014788(char *, const char *);
Motion *FUN_00055dd0(void *);
void FUN_00055eac(Motion *, const char *, int);
void FUN_00055e48(Motion *, short);
Hands *FUN_000b3c68(Chara *);
void FUN_0005743c(Anim *, int, Motion *, int);
void FUN_00092e50(Model *, int, const char *, const char *, int, int);
void FUN_000b42b4(MotionVec *, Motion *const *, Tag);
unsigned char FUN_0024de88(int, int, int);
int FUN_001b63e0(char *, int);
void FUN_001b5588(int, int, char *, int);
}

/* Release build: assertions compile to nothing (the Sharing build keeps them, see the twin). */
#define HST_ASSERT(cond, text, line) ((void)0)

#define IsAdhoc() (DAT_0033877c != 0 || DAT_003386b8 != 0)

static inline void PushBack(MotionVec *v, Motion *const &x, Tag)
{
    if (v->size < v->cap) {
        v->size++;
        v->data[v->size - 1] = x;
    }
    else
        FUN_000b42b4(v, &x, Tag());
}

extern "C" void FUN_00097d64(Chara *self)
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

    FUN_00117128(DAT_003386b0->m9c);
    DAT_00338770++;
    FUN_00098870(self);
    DAT_00338770--;
    enabled = self->model->enabled;
    face = self->face->id;
    pd = FUN_000d8c24(DAT_00338b08, 0, face);

    busy = false;
    if (DAT_00338b44->two)
        n = 2;
    else
        n = 4;
    for (i = 0; i < n; i++) {
        if (FUN_000d8c24(DAT_00338b08, 0, DAT_003417b8[i].id)->kind != 0) {
            busy = true;
            break;
        }
    }

    if (DAT_00338774[0] == 0) {
        int j;
        int base;
        HST_ASSERT(DAT_00338770 == 0, "s_CommonMotionRefCount == 0", 1984);
        for (unsigned k = 0; k < COMMON_SET_COUNT; k++) {
            DAT_00338774[k] = (Motion **)FUN_00000a90(0x454);
            FUN_000114c0(DAT_00338774[k], 0, 0x454);
        }
        for (j = 0, base = 0; j < 4; base += MOTION_COUNT, j++) {
            int end;
            int idx;
            FUN_0001ca58(DAT_0030ebf4, DAT_002d4440, IsAdhoc() ? DAT_002d4468 : DAT_002d435c, j);
            end = (base + MOTION_COUNT) / 4;
            for (idx = base / 4; idx < end; idx++) {
                MotionEntry *m = &DAT_002beb78[idx];
                if ((idx < 174 || idx >= 198 || busy) && m->common) {
                    int cnt;
                    int k;
                    if (FUN_00014d64(m->name, DAT_002d446c) != 0)
                        FUN_000143b0(name, DAT_002d4474);
                    else
                        FUN_000143b0(name, DAT_002d447c);
                    cnt = 1;
                    if (m->side || m->gender)
                        cnt = 2;
                    for (k = 0; k < cnt; k++) {
                        Motion *mem;
                        Motion *mt;
                        if (m->side) {
                            HST_ASSERT(m->gender == 0, "g_AnimationList[i].sex == 0", 2065);
                            FUN_000143b0(motion, m->name, DAT_002d4428[k]);
                        } else if (m->gender)
                            FUN_000143b0(motion, m->name, DAT_002d4438[k]);
                        else
                            FUN_000143b0(motion, m->name);
                        FUN_000143b0(path, DAT_002d4484, IsAdhoc() ? DAT_002d4490 : DAT_002d44ac, name, motion);
                        mem = (Motion *)operator new(0x10);
                        if (mem)
                            mem = FUN_00055dd0(mem);
                        DAT_00338774[k][idx] = mem;
                        FUN_00055eac(DAT_00338774[k][idx], path, 0);
                        mt = DAT_00338774[k][idx];
                        if (mt->data == 0) {
                            HST_ASSERT(false, "false", 2086);
                            if (mt) {
                                FUN_00055e48(mt, 1);
                                DAT_00338774[k][idx] = 0;
                            }
                        }
                    }
                }
            }
            FUN_0001cb88(DAT_0030ebf4);
        }
    }

    DAT_00338770++;
    FUN_0001ca58(DAT_0030ebf4, DAT_002d44c0, IsAdhoc() ? DAT_002d4468 : DAT_002d435c, face);
    if (FUN_000b3c68(self)->right == 1)
        right = DAT_002d4420;
    else
        right = DAT_002d4424;
    if (FUN_000b3c68(self)->left == 1)
        left = DAT_002d4420;
    else
        left = DAT_002d4424;
    female = 0;
    if (face < 100)
        female = self->face->sex != 1;
    else if (face >= 100 && face < 200)
        female = 1;
    else if (face >= 200 && face < 300)
        female = 0;
    if (female == 0)
        sex = DAT_002d4430;
    else
        sex = DAT_002d4434;

    for (int j = 0; j < MOTION_COUNT; j++) {
        MotionEntry *e = &DAT_002beb78[j];
        Motion *mot = 0;
        if (e->kind != 0) {
            int want = pd->kind == 0 ? 1 : 2;
            if (want != e->kind) goto add;
        }
        {
            int load = e->loop <= 0;
            if (e->common) {
                int t;
                if (FUN_00014d64(e->name, DAT_002d446c) != 0)
                    FUN_000143b0(name, DAT_002d4474);
                else
                    FUN_000143b0(name, DAT_002d447c);
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
                        c = FUN_000b3c68(self)->right;
                    else
                        c = FUN_000b3c68(self)->left;
                    t = c - 1;
                }
                if (e->gender)
                    t = female;
                mot = DAT_00338774[t][j];
            } else {
                if (j >= FACE_MOTION_FIRST && j < FACE_MOTION_FIRST) {
                    FUN_000143b0(name, DAT_002d44e4);
                    FUN_000143b0(motion, e->name);
                } else {
                    FUN_000143b0(name, DAT_002d44f0, face);
                    if (e->side)
                        FUN_000143b0(motion, e->name, face, e->side == 1 ? right : left);
                    else if (e->gender)
                        FUN_000143b0(motion, e->name, face, sex);
                    else
                        FUN_000143b0(motion, e->name, face);
                }
                FUN_000143b0(path, DAT_002d4484, IsAdhoc() ? DAT_002d4490 : DAT_002d44ac, name, motion);
                if (pd && pd->kind == 0) {
                    Motion *mem = (Motion *)operator new(0x10);
                    if (mem)
                        mem = FUN_00055dd0(mem);
                    mot = mem;
                    FUN_00055eac(mot, path, 0);
                    if (mot->data == 0) {
                        if (j < FACE_MOTION_FIRST || j >= MOTION_COUNT)
                            HST_ASSERT(false, "false", 2218);
                        if (mot) {
                            FUN_00055e48(mot, 1);
                            mot = 0;
                        }
                    }
                }
            }
            if (j >= FACE_MOTION_FIRST && j < MOTION_COUNT) {
                if (mot) {
                    if (self->noface == 0) {
                        char path2[128];
                        FUN_000143b0(path2, DAT_002d44f8, IsAdhoc() ? DAT_002d4490 : DAT_002d44ac, name, motion);
                        self->anim.Load(path2, 0, 0, 0, 0, 0);
                    }
                    FUN_0005743c(&self->anim, j - FACE_MOTION_FIRST, mot, 0);
                }
                load = 0;
            }
            if (enabled && load) {
                int common = 0;
                if (e->variant >= 0)
                    FUN_00014788(motion, e->variant == 0 ? DAT_002d4504 : DAT_002d4508);
                if (e->per_face && pd->kind == 0) {
                    FUN_000143b0(path, DAT_002d450c, face, motion);
                } else {
                    FUN_000143b0(path, DAT_002d4528, name, motion);
                    common = 1;
                }
                FUN_00014788(path, DAT_002d4540);
                FUN_000143b0(model, DAT_002d4548, face);
                FUN_00092e50(self->model, j, path, model, 0, common);
            }
        }
    add:
        PushBack(&self->motions, mot, Tag());
    }
    FUN_0001cb88(DAT_0030ebf4);

    {
        char *key = (char *)self->face + SKIN_KEY_OFFSET;
        if (!self->locked && FUN_0024de88(DAT_0034a77c, 10, DAT_003417b8[self->slot].team) == 0 && !DAT_003386b8)
            self->skin = 0;
        else
            self->skin = FUN_001b63e0(key, DAT_003417b8[self->slot].skin);
        FUN_001b5588(DAT_003386b0->ma8, self->slot, key, self->skin);
    }
}
