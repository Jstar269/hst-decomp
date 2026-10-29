/* HSTMATCH module=EBOOT.BIN start=0x000ce3f8 end=0x000ce65c symbol=FUN_000ce3f8 lang=c++ */
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
/* Two joint indices per player. */
struct Pair {
    int a; /* first joint */
    int b; /* second joint */
    char pad[0x1c];
};
#define PLAYER_PAIRS 4
#define FX_RANGE 3500.0f

struct Self {
    char pad[0xe0];
    Pair pairs[PLAYER_PAIRS]; /* 0xe0 */
};

extern Mgr *DAT_003386b0;
extern const Mat4 DAT_002bc410;

extern "C" {
Mat4 FUN_00055240(Node *n, int joint);
int FUN_000ca4a4();
void FUN_000ce754(int id, float a, float b, float c, Mat4 *m, int n, int f);
}

/* Copies the joint position onto the matrix translation with y flattened to the ground (0). */
static inline void SetGroundPos(Mat4 &m, const Vec4 &p)
{
    m.r3.x = p.x;
    m.r3.y = 0.0f;
    m.r3.z = p.z;
    m.r3.w = p.w;
}

/* For one player: takes the two joint positions from the model, flattens them onto the ground plane and submits an effect for each. */
extern "C" void FUN_000ce3f8(Self *self, int idx)
{
    Model *model = DAT_003386b0->players[idx]->model;
    if (model == 0)
        return;
    Node *root = model->root;
    if (root == 0)
        return;
    Mat4 m1 = DAT_002bc410;
    Mat4 m2 = DAT_002bc410;
    Mat4 j1 = FUN_00055240(root, self->pairs[idx].a);
    SetGroundPos(m1, j1.r3);
    Mat4 j2 = FUN_00055240(root, self->pairs[idx].b);
    SetGroundPos(m2, j2.r3);
    int n;
    if (FUN_000ca4a4() == 2)
        n = 4;
    else if (FUN_000ca4a4() == 0)
        n = 2;
    else
        n = 3;
    FUN_000ce754(DAT_003386b0->cam->id, FX_RANGE, 1.0f, 0.0f, &m1, n, 1);
    FUN_000ce754(DAT_003386b0->cam->id, FX_RANGE, 1.0f, 0.0f, &m2, n, 1);
}
