/* HSTMATCH module=hstp_trans_main.prx start=0x000bc7fc end=0x000bd070 symbol=FUN_000bc7fc bss=0x003e1df8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug camera update: mode 0 off, 1 free-fly, 2 orbit (mode 1 also returns early after the camera object's
   update, so its switch cases only run if FUN_0013c750 changes the mode). Pad stick axes (+0x90/+0x94) go to
   one of four inputs by two 2-bit pad flags; the free-fly move vector is transformed by the camera matrix,
   the orbit offset by the yaw/pitch matrix. The previous preset-select value is a function-local static
   (bss=; its loads/stores are scheduled across pointer stores). Literal factors multiply with the constant
   first; retail's operand order (value first) and the kept `* 1.0f` come from non-const locals holding the
   factors (speed/down/rate). The fov clamp bounds are non-const globals (fov is reloaded after its store). */
#include "hst/pad_state.h"

struct Vec4 { float x, y, z, w; Vec4() {} Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {} };
struct Mat4 { Vec4 r[4]; };

enum { CAM_OFF = 0, CAM_FREE = 1, CAM_ORBIT = 2, PRESET_COUNT = 16 };

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

extern PadState *DAT_003751d4;
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
    static float s_prevStep;
    Vec4 saved;
    Vec4 move;
    Vec4 pos;
    Mat4 m;

    if (self->mode == CAM_OFF)
        return;
    if (DAT_003751d4->byte8b.st1 == 0 && DAT_003751d4->byte8b.st3 == 1) {
        FUN_000bc170(self, DAT_003da704);
        FUN_00062160(self->obj, DAT_003da704);
    }
    if (self->mode == CAM_FREE) {
        FUN_0016ac90(self->obj);
        self->obj->Apply(DAT_003da704);
        return;
    }
    FUN_0013c750(&saved, DAT_003e95c4, self->preset, -1);
    float lookX = 0.0f;
    float lookY = 0.0f;
    float stepX = 0.0f;
    int padSel = DAT_003751d4->byte8a.st0;
    float fovStep = 0.0f;
    float moveX = 0.0f;
    float moveY = 0.0f;
    float moveZ = 0.0f;
    if (padSel == 1 && DAT_003751d4->byte8b.st3 == 1) {
        moveZ = DAT_003751d4->stickY;
    } else if (padSel == 1) {
        stepX = DAT_003751d4->stickX;
        fovStep = DAT_003751d4->stickY;
    } else if (DAT_003751d4->byte8b.st3 == -2) {
        lookX = DAT_003751d4->stickX;
        lookY = DAT_003751d4->stickY;
    } else {
        moveX = DAT_003751d4->stickX;
        moveY = DAT_003751d4->stickY;
    }
    switch (self->mode) {
    case CAM_FREE: {
        self->pitch += 0.06981317f * lookY;
        if (self->pitch < -1.5707964f)
            self->pitch = -1.5707964f;
        if (self->pitch > 1.5707964f)
            self->pitch = 1.5707964f;
        self->yaw += 0.06981317f * lookX;
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
        if (moveY < 0.0f)
            sign = -1;
        else
            sign = 1;
        float p = FUN_0000ce54(moveY, 6.0f);
        p *= sign;
        if (DAT_003751d4->byte8a.st2 == 1)
            move.y = p * speed;
        else
            move.z = p * down;
        if (fabsf(moveX) < 0.8f)
            moveX *= 0.125f;
        move.x = moveX * speed;
        if (fabsf(moveZ) < 0.8f)
            moveZ *= 0.125f;
        move.y = moveZ * speed;
        FUN_000224c0(&move, &move, speed);
        move.w = 1.0f;
        self->fov += 0.5f * fovStep;
        self->fov = Clamp(self->fov, DAT_0037b324, DAT_0037b328);
        Camera *cam = DAT_003da704;
        cam->fov = self->fov;
        cam->tanHalf = FUN_0000c018(0.008726646f * cam->fov);
        if (fabsf(s_prevStep) != 1.0f) {
            if (stepX == 1.0f) {
                Vec4 q;
                self->preset = (self->preset + PRESET_COUNT + 1) % PRESET_COUNT;
                FUN_0013c750(&q, DAT_003e95c4, self->preset, -1);
                self->rot = q;
            } else if (stepX == -1.0f) {
                Vec4 q;
                self->preset = (self->preset + PRESET_COUNT - 1) % PRESET_COUNT;
                FUN_0013c750(&q, DAT_003e95c4, self->preset, -1);
                self->rot = q;
            }
        }
        FUN_00022570(&pos, &DAT_003da704->view, &move);
        DAT_003da704->pos = pos;
        break;
    }
    case CAM_ORBIT: {
        self->pitch += 0.06981317f * lookY;
        if (self->pitch < -1.5707964f)
            self->pitch = -1.5707964f;
        if (self->pitch > 1.5707964f)
            self->pitch = 1.5707964f;
        self->yaw -= 0.06981317f * lookX;
        while (self->yaw < -3.1415927f)
            self->yaw += 6.2831855f;
        while (self->yaw > 3.1415927f)
            self->yaw -= 6.2831855f;
        float rate = 1.0f;
        float dz = 12.0f * moveY / 30.0f * rate;
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
    case CAM_FREE:
        FUN_0004d64c(&m, &m, self->yaw);
        FUN_0004d5f8(&m, &m, self->pitch);
        m.r[3] = DAT_003da704->pos;
        break;
    case CAM_ORBIT: {
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
    s_prevStep = stepX;
    self->rot = saved;
}
