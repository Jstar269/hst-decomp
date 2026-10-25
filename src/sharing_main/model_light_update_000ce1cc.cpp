/* HSTMATCH module=hstp_trans_main.prx start=0x000ce1cc end=0x000ce568 symbol=FUN_000ce1cc lang=c++ */
/* Clone of src/eboot/model_light_update_000ca62c.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the effect element is reached through an inline Get(unsigned) so the i*0x1b0 product is not strength-reduced; the duplicated effects/enabled null tests are kept as retail has them); names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Cam {
    char pad0[0x20];
    Vec4 vel;
    char pad1[0x2f0 - 0x30];
    Vec4 pos;
    Vec4 GetPos() const { return pos; }
};

struct Player {
    char pad0[0x4da];
    unsigned char hidden;
};

struct Game {
    char pad0[0x3c];
    int mode;
    char pad1[0x70 - 0x40];
    Player *players[4];
    char pad2[0x88 - 0x80];
    Cam *cam;
};

struct Node {
    char pad0[0x40];
    Vec4 pos;
    void SetPos(const Vec4 &p) { pos = p; }
};

struct Key {
    char pad0[0x30];
    float weight;
};

extern "C" void FUN_0005ffd8(void *, void *);

struct Anim {
    char pad00[0xdc];
    Key keys[2];
    char pad0[0x158 - 0x144];
    int first;
    int last;
    bool Active() const
    {
        for (int i = first; i <= last; i++) {
            if (keys[i].weight != 0.0f)
                return true;
        }
        return false;
    }
};

inline void Apply(Anim *a, void *model)
{
    if (a->Active())
        FUN_0005ffd8(a, model);
}

struct Effect {
    char data[0x1b0];
};

struct Self {
    char pad0[0x5c];
    void *model;
    char pad1[0x70 - 0x60];
    void *sound;
    Node *node0;
    Node *node1;
    unsigned char restart;
    char pad2[0x18c - 0x7d];
    Anim *anims[10];
    char pad3[0x1c0 - 0x1b4];
    void *extra;
    unsigned char hasExtra;
    char pad4[0x1d0 - 0x1c5];
    Effect *effects;
    unsigned char *enabled;
    bool Valid() const { return effects != 0 && enabled != 0; }
    bool IsOn(int i) const { return Valid() && enabled[i] != 0; }
    Effect *Get(unsigned i) { return &effects[i]; }
};

extern "C" {
extern Game *DAT_003e19f0;
extern void *DAT_003da704;
extern unsigned int DAT_0037c440;
void FUN_000cc190(Self *);
void FUN_0005c700(void *, void *);
void FUN_0005d3f4(void *, float, float, float, float);
void FUN_0005d580(void *, int, Vec4 *, Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
void FUN_0005ffd8(void *, void *);
void FUN_00064d80(void *, float, float);
}

extern "C" void FUN_000ce1cc(Self *self)
{
    FUN_000cc190(self);
    FUN_0005c700(self->model, DAT_003da704);
    FUN_0005d3f4(self->model, 0.5f, 0.5f, 0.5f, 1.0f);
    Vec4 dir0;
    Vec4 col0;
    Vec4 dir1;
    Vec4 col1;
    col0.x = 0.5f;
    col0.y = 0.5f;
    col0.z = 0.5f;
    col0.w = 0.0f;
    dir0.x = -1.0f;
    dir0.y = 1.0f;
    dir0.z = -1.0f;
    dir0.w = 0.0f;
    FUN_0005d580(self->model, 0, &dir0, &col0);
    col1.x = 0.0f;
    col1.y = 0.0f;
    col1.z = 0.0f;
    col1.w = 0.0f;
    dir1.x = 1.0f;
    dir1.y = -1.0f;
    dir1.z = 1.0f;
    dir1.w = 0.0f;
    FUN_0005d580(self->model, 1, &dir1, &col1);
    Cam *cam = DAT_003e19f0->cam;
    if (self->node0 != 0)
        self->node0->SetPos(cam->GetPos());
    if (self->node1 != 0)
        self->node1->SetPos(cam->GetPos());
    for (int i = 0; i < 10; i++) {
        if (i == 7 || i == 3)
            continue;
        Vec4 v;
        Cam *c = DAT_003e19f0->cam;
        v.x = c->vel.x;
        v.y = c->vel.y;
        v.z = c->vel.z;
        v.w = c->vel.w;
        if (FUN_00022500(&v, &v) > 400.0f && DAT_003e19f0->mode == 7 && (DAT_0037c440 & 0x1000) != 0) {
            Apply(self->anims[i], self->model);
        }
    }
    if (self->sound != 0) {
        if (self->restart != 0) {
            self->restart = 0;
            FUN_00064d80(self->sound, 65279.0f, 0.0f);
        } else {
            FUN_00064d80(self->sound, 65279.0f, 0.8f);
        }
    }
    if (self->hasExtra != 0)
        FUN_0005ffd8(self->extra, 0);
    for (int i = 0; i < 4; i++) {
        Player *p = DAT_003e19f0->players[i];
        if (p != 0 && p->hidden == 0 && self->effects != 0 && self->enabled != 0 && self->effects != 0 &&
            self->enabled != 0 && self->enabled[i] != 0)
            FUN_0005ffd8(self->Get(i), 0);
    }
}
