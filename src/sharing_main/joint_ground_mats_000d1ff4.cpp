/* HSTMATCH module=hstp_trans_main.prx start=0x000d1ff4 end=0x000d2258 symbol=FUN_000d1ff4 lang=c++ */
/* Clone of src/eboot/joint_ground_mats_000ce3f8.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
    Mat4(const Mat4 &o) : r0(o.r0), r1(o.r1), r2(o.r2), r3(o.r3) {}
};

struct Node;
struct Model {
    char pad[0x58];
    Node *root;
};
struct Player {
    char pad[0x5bc];
    Model *model;
};
struct Cam {
    char pad[0x44];
    int id;
};
struct Mgr {
    char pad[0x70];
    Player *players[8];
    Cam *cam;
};
struct Pair {
    int a;
    int b;
    char pad[0x1c];
};
struct Self {
    char pad[0xe0];
    Pair pairs[4];
};

extern Mgr *DAT_003e19f0;
extern const Mat4 DAT_002cc260;

extern "C" {
Mat4 FUN_00055d60(Node *n, int joint);
int FUN_000ce044();
void FUN_000d2350(int id, float a, float b, float c, Mat4 *m, int n, int f);
}

static inline void SetGroundPos(Mat4 &m, const Vec4 &p)
{
    m.r3.x = p.x;
    m.r3.y = 0.0f;
    m.r3.z = p.z;
    m.r3.w = p.w;
}

extern "C" void FUN_000d1ff4(Self *self, int idx)
{
    Model *model = DAT_003e19f0->players[idx]->model;
    if (model == 0)
        return;
    Node *root = model->root;
    if (root == 0)
        return;
    Mat4 m1 = DAT_002cc260;
    Mat4 m2 = DAT_002cc260;
    Mat4 j1 = FUN_00055d60(root, self->pairs[idx].a);
    SetGroundPos(m1, j1.r3);
    Mat4 j2 = FUN_00055d60(root, self->pairs[idx].b);
    SetGroundPos(m2, j2.r3);
    int n;
    if (FUN_000ce044() == 2)
        n = 4;
    else if (FUN_000ce044() == 0)
        n = 2;
    else
        n = 3;
    FUN_000d2350(DAT_003e19f0->cam->id, 3500.0f, 1.0f, 0.0f, &m1, n, 1);
    FUN_000d2350(DAT_003e19f0->cam->id, 3500.0f, 1.0f, 0.0f, &m2, n, 1);
}
