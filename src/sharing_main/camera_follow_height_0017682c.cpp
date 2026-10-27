/* HSTMATCH module=hstp_trans_main.prx start=0x0017682c end=0x00176b00 symbol=FUN_0017682c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/camera_follow_height_0016a668.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct V4 {
    float x, y, z, w;
};

struct Obj {
    char pad0[0x40];
    V4 a;
    char pad50[0x10];
    V4 b;
    char pad70[0x10];
    float f80;
    float f84;
    float f88;
};

struct Cfg {
    char pad0[0x50];
    float f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78;
};

struct Game {
    char pad0[0x3c];
    int f3c;
};

extern "C" {
extern float DAT_00387a08;
extern float DAT_00387a1c;
extern float DAT_00387a20;
extern float DAT_00387a24;
extern float DAT_00387a28;
extern Cfg *DAT_003e95c4;
extern Game *DAT_003e19f0;
void FUN_0002245c(V4 *, V4 *, V4 *);
void FUN_000224c0(float, V4 *, V4 *);
void FUN_00022440(V4 *, V4 *, V4 *);
void FUN_0006187c(Obj *);
}

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

extern "C" void FUN_0017682c(Obj *self, int flag)
{
    if (DAT_00387a08 != 0.0f) {
        V4 p1;
        p1.x = self->a.x;
        p1.y = self->a.y;
        p1.z = self->a.z;
        p1.w = self->a.w;
        V4 p2;
        p2.x = self->b.x;
        p2.y = self->b.y;
        p2.z = self->b.z;
        p2.w = self->b.w;
        V4 e;
        V4 d;
        V4 f;
        V4 t2;
        V4 t1;
        FUN_0002245c(&t1, &p2, &p1);
        d = t1;
        FUN_000224c0(0.2f, &t2, &d);
        e = t2;
        FUN_00022440(&f, &p1, &e);
        float fy = f.y;
        float y0 = self->f80;
        if (flag != 0 && fy > -DAT_00387a08) {
            float t = fy + DAT_00387a08;
            p1.y = p1.y - t;
            p2.y = p2.y - t;
            self->a.x = p1.x;
            self->a.y = p1.y;
            self->a.z = p1.z;
            self->a.w = p1.w;
            self->b.x = p2.x;
            self->b.y = p2.y;
            self->b.z = p2.z;
            self->b.w = p2.w;
            FUN_0006187c(self);
        }
        Cfg *c = DAT_003e95c4;
        float k50 = c->f50;
        float k54 = c->f54;
        float k58 = c->f58;
        float k5c = c->f5c;
        float k60 = c->f60;
        float k64 = c->f64;
        float k68 = c->f68;
        float k6c = c->f6c;
        float k70 = c->f70;
        float k74 = c->f74;
        if (DAT_003e19f0->f3c == 3) {
            k50 = c->f78;
            k54 = k50;
        }
        float t1v = Clamp((-p1.y - k70) / (k74 - k70), DAT_00387a1c, DAT_00387a20);
        float t2v = Clamp((y0 - k58) / (k5c - k58), DAT_00387a24, DAT_00387a28);
        self->f84 = (k50 + t1v * (k54 - k50)) * (k60 + t2v * (k64 - k60));
        self->f88 = k68 + t1v * (k6c - k68);
        DAT_00387a08 = 0.4f;
    }
}
