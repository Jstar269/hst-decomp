/* HSTMATCH module=hstp_trans_main.prx start=0x0017682c end=0x00176b00 symbol=FUN_0017682c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/camera_follow_height_0016a668.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct V4 {
    float x, y, z, w;
};

/* Camera view object: two positions and three floats. */
struct Obj {
    char pad0[0x40];
    V4 eye;                 /* 0x40 */
    char pad50[0x10];
    V4 target;              /* 0x60 */
    char pad70[0x10];
    float unk80;            /* 0x80 */
    float unk84;            /* 0x84 written from the blended scales */
    float unk88;            /* 0x88 written from the blended range */
};

/* Tuning block: pairs of values blended by a clamped 0..1 factor, and the two ranges that give the factors. */
struct Cfg {
    char pad0[0x50];
    float scale_a0, scale_a1;       /* 0x50 */
    float ref_lo, ref_hi;           /* 0x58 range of unk80 */
    float scale_b0, scale_b1;       /* 0x60 */
    float out_c0, out_c1;           /* 0x68 */
    float height_lo, height_hi;     /* 0x70 range of the eye height */
    float scale_a_alt;              /* 0x78 replaces scale_a0 and scale_a1 in mode 3 */
};

struct Game {
    char pad0[0x3c];
    int mode;               /* 0x3c */
};

#define GAME_MODE_ALT_SCALE 3

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

/* Keeps the eye above a limit (raising both positions by the shortfall when flag is set), then recomputes the
   two scale values of the view from the tuning block. */
extern "C" void FUN_0017682c(Obj *self, int flag)
{
    if (DAT_00387a08 != 0.0f) {
        V4 p1;
        p1.x = self->eye.x;
        p1.y = self->eye.y;
        p1.z = self->eye.z;
        p1.w = self->eye.w;
        V4 p2;
        p2.x = self->target.x;
        p2.y = self->target.y;
        p2.z = self->target.z;
        p2.w = self->target.w;
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
        float y0 = self->unk80;
        if (flag != 0 && fy > -DAT_00387a08) {
            float t = fy + DAT_00387a08;
            p1.y = p1.y - t;
            p2.y = p2.y - t;
            self->eye.x = p1.x;
            self->eye.y = p1.y;
            self->eye.z = p1.z;
            self->eye.w = p1.w;
            self->target.x = p2.x;
            self->target.y = p2.y;
            self->target.z = p2.z;
            self->target.w = p2.w;
            FUN_0006187c(self);
        }
        Cfg *c = DAT_003e95c4;
        float scale_a0 = c->scale_a0;
        float scale_a1 = c->scale_a1;
        float ref_lo = c->ref_lo;
        float ref_hi = c->ref_hi;
        float scale_b0 = c->scale_b0;
        float scale_b1 = c->scale_b1;
        float out_c0 = c->out_c0;
        float out_c1 = c->out_c1;
        float height_lo = c->height_lo;
        float height_hi = c->height_hi;
        if (DAT_003e19f0->mode == GAME_MODE_ALT_SCALE) {
            scale_a0 = c->scale_a_alt;
            scale_a1 = scale_a0;
        }
        float t_height = Clamp((-p1.y - height_lo) / (height_hi - height_lo), DAT_00387a1c, DAT_00387a20);
        float t_ref = Clamp((y0 - ref_lo) / (ref_hi - ref_lo), DAT_00387a24, DAT_00387a28);
        self->unk84 = (scale_a0 + t_height * (scale_a1 - scale_a0)) * (scale_b0 + t_ref * (scale_b1 - scale_b0));
        self->unk88 = out_c0 + t_height * (out_c1 - out_c0);
        DAT_00387a08 = 0.4f;
    }
}
