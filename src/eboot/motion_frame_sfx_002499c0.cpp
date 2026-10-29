/* HSTMATCH module=EBOOT.BIN start=0x002499c0 end=0x0024a504 symbol=FUN_002499c0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Mat4 { Vec4 r0, r1, r2, r3; };

struct Model { char pad[0x30]; };

struct Hud { char pad0[0x44]; int id; };
struct Game { char pad0[0x90]; Hud *hud; };

struct Obj {
    char pad0[0x290];
    Model model;          /* 0x290 */
    Mat4 mtx;             /* 0x2c0 */
    char pad300[0x394 - 0x300];
    float frame;          /* 0x394 */
    char pad398[0x454 - 0x398];
    int motion;           /* 0x454 */
    char pad458[0x465 - 0x458];
    unsigned char active; /* 0x465 */
    char pad466[0x4cc - 0x466];
    int joint[5];         /* 0x4cc */
};

extern Game *DAT_003386b0;
extern Mat4 DAT_002bc410; /* identity matrix */

extern "C" {
Mat4 FUN_00055240(Model *, int);
void FUN_000ce754(int, Mat4 *, int, float, float, int, float);
}

static inline const Mat4 &Identity() { return DAT_002bc410; }

/* For the current motion id, plays an effect at the matching animation frame (position from one or more joints). */
extern "C" void FUN_002499c0(Obj *self)
{
    if (self->active) {
        Mat4 m = Identity();
        int frame = (int)self->frame;
        int id = DAT_003386b0->hud->id;

        if (self->motion == 0x6b) {
            m = self->mtx;
            m.r3 = FUN_00055240(&self->model, self->joint[0]).r3;
            if (frame == 1)
                FUN_000ce754(id, &m, 0x1ff, 3000.0f, 1.0f, 1, 0.0f);
        } else if (self->motion == 0x71) {
            m = self->mtx;
            m.r3 = FUN_00055240(&self->model, self->joint[0]).r3;
            if (frame == 20)
                FUN_000ce754(id, &m, 0x20a, 3000.0f, 1.0f, 1, 0.0f);
            m.r3 = FUN_00055240(&self->model, self->joint[1]).r3;
            if (frame == 20)
                FUN_000ce754(id, &m, 0x20a, 3000.0f, 1.0f, 1, 0.0f);
        } else if (self->motion == 0x73) {
            m = self->mtx;
            if (frame == 23)
                FUN_000ce754(id, &m, 0x1ff, 3000.0f, 1.0f, 1, 0.0f);
        } else if (self->motion == 0x65) {
            m = Identity();
            m.r3 = FUN_00055240(&self->model, self->joint[0]).r3;
            if (frame == 30)
                FUN_000ce754(id, &m, 0x20b, 3000.0f, 1.0f, 1, 0.0f);
        } else if (self->motion == 0x72) {
            m = Identity();
            m.r3 = FUN_00055240(&self->model, self->joint[0]).r3;
            if (frame == 18)
                FUN_000ce754(id, &m, 0x230, 3000.0f, 1.0f, 1, 0.0f);
        } else if (self->motion == 0x74) {
            m = Identity();
            m.r3 = FUN_00055240(&self->model, self->joint[0]).r3;
            if (frame == 27)
                FUN_000ce754(id, &m, 0x22d, 3000.0f, 1.0f, 1, 0.0f);
        } else if (self->motion == 0x75) {
            m = Identity();
            m.r3 = FUN_00055240(&self->model, self->joint[0]).r3;
            if (frame == 0)
                FUN_000ce754(id, &m, 0x219, 3000.0f, 1.0f, 1, 0.0f);
        } else if (self->motion == 0x76) {
            m = Identity();
            if (frame == 1)
                m.r3 = FUN_00055240(&self->model, self->joint[0]).r3;
            else if (frame == 8)
                m.r3 = FUN_00055240(&self->model, self->joint[1]).r3;
            else if (frame == 12)
                m.r3 = FUN_00055240(&self->model, self->joint[2]).r3;
            else if (frame == 18)
                m.r3 = FUN_00055240(&self->model, self->joint[3]).r3;
            else
                m.r3 = FUN_00055240(&self->model, self->joint[4]).r3;
            if (frame == 1 || frame == 8 || frame == 12 || frame == 18 || frame == 23)
                FUN_000ce754(id, &m, 0x229, 3000.0f, 1.0f, 1, 0.0f);
        }
    }
}
