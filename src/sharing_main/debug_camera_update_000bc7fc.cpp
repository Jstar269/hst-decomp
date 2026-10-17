/* HSTMATCH module=hstp_trans_main.prx start=0x000bc7fc end=0x000bd070 symbol=FUN_000bc7fc bss=0x003e1df8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug camera update: mode 0 off, 1 free-fly, 2 orbit (mode 1 also returns early after the camera object's
   update, so its switch cases only run if FUN_0013c750 changes the mode). Pad stick axes (+0x90/+0x94) go to
   one of four inputs by two 2-bit pad flags; the free-fly move vector is transformed by the camera matrix,
   the orbit offset by the yaw/pitch matrix. The previous preset-select value is a function-local static
   (bss=; its loads/stores are scheduled across pointer stores). Literal factors multiply with the constant
   first; retail's operand order (value first) and the kept `* 1.0f` come from non-const locals holding the
   factors (speed/down/rate). The fov clamp bounds are non-const globals (fov is reloaded after its store). */
struct Vec4 { float x, y, z, w; Vec4() {} Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {} };
struct Mat4 { Vec4 r[4]; };

struct Pad {                /* DAT_003751d4 */
    char pad0[0x8a];
    signed char a0 : 2;     /* 0x8a bits 0-1 */
    signed char a1 : 2;
    signed char a2 : 2;     /* 0x8a bits 4-5 */
    signed char a3 : 2;
    signed char b0 : 2;
    signed char b1 : 2;     /* 0x8b bits 2-3 */
    signed char b2 : 2;
    signed char b3 : 2;     /* 0x8b bits 6-7 */
    char pad8c[0x90 - 0x8c];
    float x;
    float y;
};

struct Camera {
    char pad0[0x110];
    Mat4 view;
    char pad150[0x1d0 - 0x150];
    Vec4 pos;
    Vec4 at;
    Vec4 up;
    float fov;
    char pad204[0x214 - 0x204];
    float tanHalf;
};

struct CamObj {
    virtual void d0();
    virtual void Apply(Camera *cam);
};

struct DebugCam {
    char pad0[0xc8];
    int mode;
    float pitch;
    float yaw;
    float dist;
    char padd8[0xe0 - 0xd8];
    Vec4 rot;
    float fov;
    int preset;
    CamObj *obj;
};

extern Pad *DAT_003751d4;
extern Camera *DAT_003da704;
extern void *DAT_003e95c4;
extern float DAT_0037b324;
extern float DAT_0037b328;
extern const Mat4 DAT_002cc260;

extern "C" {
void FUN_000bc170(DebugCam *self, Camera *cam);
void FUN_00062160(CamObj *obj, Camera *cam);
void FUN_0016ac90(CamObj *obj);
void FUN_0013c750(Vec4 *out, void *table, int idx, int flag);
float FUN_0000ce54(float x, float y);
float FUN_0000c018(float x);
Vec4 *FUN_000224c0(Vec4 *out, const Vec4 *v, float s);
Vec4 *FUN_00022570(Vec4 *out, const Mat4 *m, const Vec4 *v);
void FUN_0004d64c(Mat4 *out, const Mat4 *in, float a);
void FUN_0004d5f8(Mat4 *out, const Mat4 *in, float a);
}

extern "C" float fabsf(float);

template <class T> inline T Clamp(const T &v, const T &lo, const T &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

extern "C" void FUN_000bc7fc(DebugCam *self)
{
    static float s_prevSel;
    Vec4 saved;
    Vec4 move;
    Vec4 pos;
    Mat4 m;

    if (self->mode == 0)
        return;
    if (DAT_003751d4->b1 == 0 && DAT_003751d4->b3 == 1) {
        FUN_000bc170(self, DAT_003da704);
        FUN_00062160(self->obj, DAT_003da704);
    }
    if (self->mode == 1) {
        FUN_0016ac90(self->obj);
        self->obj->Apply(DAT_003da704);
        return;
    }
    FUN_0013c750(&saved, DAT_003e95c4, self->preset, -1);
    float rx = 0.0f;
    float ry = 0.0f;
    float sx = 0.0f;
    int sel = DAT_003751d4->a0;
    float sy = 0.0f;
    float mx = 0.0f;
    float my = 0.0f;
    float mz = 0.0f;
    if (sel == 1 && DAT_003751d4->b3 == 1) {
        mz = DAT_003751d4->y;
    } else if (sel == 1) {
        sx = DAT_003751d4->x;
        sy = DAT_003751d4->y;
    } else if (DAT_003751d4->b3 == -2) {
        rx = DAT_003751d4->x;
        ry = DAT_003751d4->y;
    } else {
        mx = DAT_003751d4->x;
        my = DAT_003751d4->y;
    }
    switch (self->mode) {
    case 1: {
        self->pitch += 0.06981317f * ry;
        if (self->pitch < -1.5707964f)
            self->pitch = -1.5707964f;
        if (self->pitch > 1.5707964f)
            self->pitch = 1.5707964f;
        self->yaw += 0.06981317f * rx;
        while (self->yaw < -3.1415927f)
            self->yaw += 6.2831855f;
        while (self->yaw > 3.1415927f)
            self->yaw -= 6.2831855f;
        move.x = 0.0f;
        move.y = 0.0f;
        move.z = 0.0f;
        move.w = 1.0f;
        float speed = 0.5f;
        float down = -1.0f;
        int sign;
        if (my < 0.0f)
            sign = -1;
        else
            sign = 1;
        float p = FUN_0000ce54(my, 6.0f);
        p *= sign;
        if (DAT_003751d4->a2 == 1)
            move.y = p * speed;
        else
            move.z = p * down;
        if (fabsf(mx) < 0.8f)
            mx *= 0.125f;
        move.x = mx * speed;
        if (fabsf(mz) < 0.8f)
            mz *= 0.125f;
        move.y = mz * speed;
        FUN_000224c0(&move, &move, speed);
        move.w = 1.0f;
        self->fov += 0.5f * sy;
        self->fov = Clamp(self->fov, DAT_0037b324, DAT_0037b328);
        Camera *cam = DAT_003da704;
        cam->fov = self->fov;
        cam->tanHalf = FUN_0000c018(0.008726646f * cam->fov);
        if (fabsf(s_prevSel) != 1.0f) {
            if (sx == 1.0f) {
                Vec4 q;
                self->preset = (self->preset + 17) % 16;
                FUN_0013c750(&q, DAT_003e95c4, self->preset, -1);
                self->rot = q;
            } else if (sx == -1.0f) {
                Vec4 q;
                self->preset = (self->preset + 15) % 16;
                FUN_0013c750(&q, DAT_003e95c4, self->preset, -1);
                self->rot = q;
            }
        }
        FUN_00022570(&pos, &DAT_003da704->view, &move);
        DAT_003da704->pos = pos;
        break;
    }
    case 2: {
        self->pitch += 0.06981317f * ry;
        if (self->pitch < -1.5707964f)
            self->pitch = -1.5707964f;
        if (self->pitch > 1.5707964f)
            self->pitch = 1.5707964f;
        self->yaw -= 0.06981317f * rx;
        while (self->yaw < -3.1415927f)
            self->yaw += 6.2831855f;
        while (self->yaw > 3.1415927f)
            self->yaw -= 6.2831855f;
        float rate = 1.0f;
        float dz = 12.0f * my / 30.0f * rate;
        if (dz != 0.0f) {
            if (fabsf(self->dist) > 10.0f)
                dz *= fabsf(self->dist) / 10.0f;
        }
        self->dist -= dz;
        if (self->dist > 0.0f)
            self->dist = 0.0f;
        break;
    }
    }
    m = DAT_002cc260;
    switch (self->mode) {
    case 1:
        FUN_0004d64c(&m, &m, self->yaw);
        FUN_0004d5f8(&m, &m, self->pitch);
        m.r[3] = DAT_003da704->pos;
        break;
    case 2: {
        FUN_0004d64c(&m, &m, self->yaw);
        FUN_0004d5f8(&m, &m, self->pitch);
        Vec4 off(0.0f, 0.0f, self->dist, 1.0f);
        FUN_00022570(&m.r[3], &m, &off);
        break;
    }
    }
    DAT_003da704->pos = m.r[3];
    DAT_003da704->at = m.r[2];
    DAT_003da704->up = m.r[1];
    s_prevSel = sx;
    self->rot = saved;
}
