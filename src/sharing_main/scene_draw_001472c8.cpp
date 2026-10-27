/* HSTMATCH module=hstp_trans_main.prx start=0x001472c8 end=0x00147d14 symbol=FUN_001472c8 lang=c++ */
/* Clone of src/eboot/scene_draw_0013bc7c.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the display-flag test of the second category loop goes through the inline IsOn(int) (an open-coded `1 << tab[i]` there swaps a0/a1), the player loop binds `&p->model` / `&p->anim` to locals passed to the inline Select/Draw helpers (retail keeps both addresses in s3/s4 across the calls), the object/player lists are indexed through inline accessors taking an unsigned index (no strength reduction, per-pass sll), the draw tests keep `!(h > top)` / `!(h < bottom)` (c.ngt.s/c.lt.s); names and types await human review. */
/* Per-frame scene draw: each object category is gated by a bit of the display-flag word DAT_0037c440 (table DAT_002d1a54 maps the six model lists to flag bits); the sphere/object/player groups are culled against the camera (DAT_003da704) height band top/bottom or, in the other camera mode, by bounding-sphere distance. Names provisional. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Model {
    char pad0[0x68];
    float height;
    char pad6c[0x90 - 0x6c];
};

struct ModelList {
    Model **data;
    unsigned size;
    unsigned cap;
};

struct Sphere {
    Vec4 pos;
    float radius;
    char pad14[0x20 - 0x14];
};

struct SphereList {
    Sphere *data;
    unsigned size;
    unsigned cap;
};

struct Obj {
    char pad0[0x20];
    Model model;
    char pad1[0x420 - 0x20 - sizeof(Model)];
    Vec4 pos;
    float radius;
    char pad434[0x444 - 0x434];
    unsigned char mode;
};

struct ObjList {
    Obj **data;
    unsigned size;
    unsigned cap;
};

struct Pl {
    char pad0[0x20];
    Model model;
    char pad1[0x1d0 - 0x20 - sizeof(Model)];
    Model anim;
    char pad2[0x3d0 - 0x1d0 - sizeof(Model)];
    int kind;
    int pad3d4;
    unsigned char f3d8;
    char pad3d9[3];
    unsigned f3dc;
};

struct PlList {
    Pl **data;
    unsigned size;
    unsigned cap;
};

struct Game {
    char pad0[0x44];
    Model *m44;
    char pad48[4];
    Model *m4c;
    char pad50[0x68 - 0x50];
    ModelList extras;
    char pad74[0x80 - 0x74];
    ModelList lists[6];
    char padc8[0x104 - 0xc8];
    SphereList spheres;
    ModelList lists2[6];
    char pad158[0x164 - 0x158];
    ObjList objs;
    char pad170[0x17c - 0x170];
    ObjList objs2;
    PlList players;
    char pad194[0xd5c - 0x194];
    unsigned char fd5c;
    unsigned char fd5d;
    char padd5e[0x1350 - 0xd5e];
    float top;
    float bottom;
    char pad1358[0x1388 - 0x1358];
    void *cam;
    char pad138c[0x1414 - 0x138c];
    unsigned char f1414;
    char pad1415[0x141e - 0x1415];
    unsigned char f141e;
};

struct Camera {
    char pad0[0x1d0];
    Vec4 pos;
};

struct Ctx {
    char pad0[0x8c];
    int f8c;
};

extern "C" {
extern unsigned int DAT_0037c440;
extern const int DAT_002d1a54[6];
extern Camera *DAT_003da704;
extern Ctx *DAT_003e95c4;
void FUN_0002245c(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_00022500(const Vec4 *a, const Vec4 *b);
int FUN_0013d2b0(Ctx *);
void FUN_0005ffd8(Model *, void *);
void FUN_00056344(Model *, void *);
void FUN_000562d0(Vec4 *, Model *);
float FUN_00056314(Model *);
void FUN_00212154(void *);
void FUN_00212410(void *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_0002245c(&r, &a, &b);
    return r;
}

static inline bool IsOn(int t)
{
    return (DAT_0037c440 & (1 << t)) != 0;
}

static inline Obj *ObjAt(ObjList *l, unsigned i)
{
    return l->data[i];
}

static inline Pl *PlAt(PlList *l, unsigned i)
{
    return l->data[i];
}

static inline Model *Select(Pl *p, Model *body, Model *anim)
{
    Model *m = 0;
    if (p->f3d8 != 0)
        m = anim;
    else if (p->kind == 10)
        m = body;
    else if (p->f3dc < 2)
        m = body;
    else if ((unsigned)(p->kind - 4) < 2 && p->f3dc == 2)
        m = body;
    return m;
}

static inline void Draw(Pl *p, Model *body, Model *anim)
{
    if (p->f3d8 != 0)
        FUN_0005ffd8(anim, 0);
    else if (p->kind == 10)
        FUN_0005ffd8(body, 0);
    else if (p->f3dc < 2)
        FUN_0005ffd8(body, 0);
    else if ((unsigned)(p->kind - 4) < 2 && p->f3dc == 2)
        FUN_0005ffd8(body, 0);
}

extern "C" void FUN_001472c8(Game *g)
{
    if (g->fd5c != 0 && (DAT_0037c440 & 0x10) != 0)
        FUN_0005ffd8(g->m44, 0);
    if (g->fd5d != 0 && (DAT_0037c440 & 0x20) != 0)
        FUN_0005ffd8(g->m4c, 0);

    for (unsigned i = 0; i < 6; i++) {
        if (IsOn(DAT_002d1a54[i]) && DAT_002d1a54[i] != 8) {
            for (unsigned j = 0; j < g->lists[i].size; j++)
                FUN_00056344(g->lists[i].data[j], 0);
        }
    }
    if ((DAT_0037c440 & 4) != 0 && g->f1414 != 0) {
        for (unsigned j = 0; j < g->extras.size; j++)
            FUN_0005ffd8(g->extras.data[j], 0);
    }
    if ((DAT_0037c440 & 0x40) != 0) {
        for (unsigned i = 0; i < 6; i++) {
            if (IsOn(DAT_002d1a54[i])) {
                for (unsigned j = 0; j < g->lists2[i].size; j++)
                    FUN_00056344(g->lists2[i].data[j], 0);
            }
        }
    }
    if ((DAT_0037c440 & 0x100) != 0) {
        for (unsigned i = 0; i < g->lists[5].size; i++) {
            Vec4 pos = g->spheres.data[i].pos;
            Vec4 cam = DAT_003da704->pos;
            Vec4 d = Sub(cam, pos);
            float r = g->spheres.data[i].radius;
            float d2 = FUN_00022500(&d, &d);
            if (DAT_003e95c4->f8c == 0 || FUN_0013d2b0(DAT_003e95c4) != 0) {
                if (cam.z > g->top) {
                    if (!(g->lists[5].data[i]->height > g->top))
                        FUN_00056344(g->lists[5].data[i], 0);
                } else if (cam.z < g->bottom) {
                    if (!(g->lists[5].data[i]->height < g->bottom))
                        FUN_00056344(g->lists[5].data[i], 0);
                } else {
                    FUN_00056344(g->lists[5].data[i], 0);
                }
            } else if (r * r < d2) {
                FUN_00056344(g->lists[5].data[i], 0);
            }
        }
    }
    if ((DAT_0037c440 & 0x80) != 0) {
        for (int i = 0; i < g->objs.size; i++) {
            Vec4 pos = ObjAt(&g->objs, i)->pos;
            Vec4 cam = DAT_003da704->pos;
            Vec4 d = Sub(cam, pos);
            float r = ObjAt(&g->objs, i)->radius;
            float d2 = FUN_00022500(&d, &d);
            if (ObjAt(&g->objs, i)->mode == 1) {
                FUN_0005ffd8(&ObjAt(&g->objs, i)->model, 0);
            } else if (DAT_003e95c4->f8c == 0 || FUN_0013d2b0(DAT_003e95c4) != 0) {
                if (cam.z > g->top) {
                    if (!(ObjAt(&g->objs, i)->model.height > g->top))
                        FUN_0005ffd8(&ObjAt(&g->objs, i)->model, 0);
                } else if (cam.z < g->bottom) {
                    if (!(ObjAt(&g->objs, i)->model.height < g->bottom))
                        FUN_0005ffd8(&ObjAt(&g->objs, i)->model, 0);
                } else {
                    FUN_0005ffd8(&ObjAt(&g->objs, i)->model, 0);
                }
            } else if (r * r < d2) {
                FUN_0005ffd8(&ObjAt(&g->objs, i)->model, 0);
            }
        }
    }
    if ((DAT_0037c440 & 1) != 0) {
        for (int i = 0; i < g->objs2.size; i++)
            FUN_0005ffd8(&ObjAt(&g->objs2, i)->model, 0);
    }
    if ((DAT_0037c440 & 8) != 0) {
        for (int i = 0; i < g->players.size; i++) {
            Pl *p = PlAt(&g->players, i);
            Model *body = &p->model;
            Model *anim = &p->anim;
            Model *m = Select(p, body, anim);
            if (m != 0) {
                Vec4 pos;
                FUN_000562d0(&pos, m);
                Vec4 cam = DAT_003da704->pos;
                Vec4 d = Sub(cam, pos);
                float r = FUN_00056314(m);
                float d2 = FUN_00022500(&d, &d);
                if (DAT_003e95c4->f8c == 0 || FUN_0013d2b0(DAT_003e95c4) != 0) {
                    if (cam.z > g->top) {
                        if (!(m->height > g->top) || p->kind == 9)
                            Draw(p, body, anim);
                    } else if (cam.z < g->bottom) {
                        if (!(m->height < g->bottom) || p->kind == 9)
                            Draw(p, body, anim);
                    } else {
                        Draw(p, body, anim);
                    }
                } else if (r * r < d2 || p->kind == 9) {
                    Draw(p, body, anim);
                }
            }
        }
    }
    if (g->f141e == 0) {
        FUN_00212154(g->cam);
        FUN_00212410(g->cam);
    }
}
