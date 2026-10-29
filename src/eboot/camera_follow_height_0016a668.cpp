/* HSTMATCH module=EBOOT.BIN start=0x0016a668 end=0x0016a93c symbol=FUN_0016a668 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the three Vec4 sret helpers return into plain temporaries that are copied (`d = t1; e = t2;`, t2 declared before t1 so the 32(sp) slot is the sub temp), `fy = f.y` is read before `y0 = self->unk80` so the f.y load fills the beqz slot, the clamp is `v < lo ? lo : (v > hi ? hi : v)` (c.ngt) on plain globals (double global load), every config float is read into a local in offset order before the `== 3` test (scale_a0 = c->scale_a_alt; scale_a1 = scale_a0 in that order); names and types await human review. */
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
extern float DAT_002e044c;
extern float DAT_002e0460;
extern float DAT_002e0464;
extern float DAT_002e0468;
extern float DAT_002e046c;
extern Cfg *DAT_00340284;
extern Game *DAT_003386b0;
void FUN_00022434(V4 *, V4 *, V4 *);
void FUN_00022498(float, V4 *, V4 *);
void FUN_00022418(V4 *, V4 *, V4 *);
void FUN_000609f8(Obj *);
}

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

/* Keeps the eye above a limit (raising both positions by the shortfall when flag is set), then recomputes the
   two scale values of the view from the tuning block. */
extern "C" void FUN_0016a668(Obj *self, int flag)
{
    if (DAT_002e044c != 0.0f) {
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
        FUN_00022434(&t1, &p2, &p1);
        d = t1;
        FUN_00022498(0.2f, &t2, &d);
        e = t2;
        FUN_00022418(&f, &p1, &e);
        float fy = f.y;
        float y0 = self->unk80;
        if (flag != 0 && fy > -DAT_002e044c) {
            float t = fy + DAT_002e044c;
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
            FUN_000609f8(self);
        }
        Cfg *c = DAT_00340284;
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
        if (DAT_003386b0->mode == GAME_MODE_ALT_SCALE) {
            scale_a0 = c->scale_a_alt;
            scale_a1 = scale_a0;
        }
        float t_height = Clamp((-p1.y - height_lo) / (height_hi - height_lo), DAT_002e0460, DAT_002e0464);
        float t_ref = Clamp((y0 - ref_lo) / (ref_hi - ref_lo), DAT_002e0468, DAT_002e046c);
        self->unk84 = (scale_a0 + t_height * (scale_a1 - scale_a0)) * (scale_b0 + t_ref * (scale_b1 - scale_b0));
        self->unk88 = out_c0 + t_height * (out_c1 - out_c0);
        DAT_002e044c = 0.4f;
    }
}
