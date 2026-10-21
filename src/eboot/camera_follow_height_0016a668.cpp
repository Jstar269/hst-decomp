/* HSTMATCH module=EBOOT.BIN start=0x0016a668 end=0x0016a93c symbol=FUN_0016a668 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the three Vec4 sret helpers return into plain temporaries that are copied (`d = t1; e = t2;`, t2 declared before t1 so the 32(sp) slot is the sub temp), `fy = f.y` is read before `y0 = self->f80` so the f.y load fills the beqz slot, the clamp is `v < lo ? lo : (v > hi ? hi : v)` (c.ngt) on plain globals (double global load), every config float is read into a local in offset order before the `== 3` test (k50 = c->f78; k54 = k50 in that order); names and types await human review. */
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

extern "C" void FUN_0016a668(Obj *self, int flag)
{
    if (DAT_002e044c != 0.0f) {
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
        FUN_00022434(&t1, &p2, &p1);
        d = t1;
        FUN_00022498(0.2f, &t2, &d);
        e = t2;
        FUN_00022418(&f, &p1, &e);
        float fy = f.y;
        float y0 = self->f80;
        if (flag != 0 && fy > -DAT_002e044c) {
            float t = fy + DAT_002e044c;
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
            FUN_000609f8(self);
        }
        Cfg *c = DAT_00340284;
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
        if (DAT_003386b0->f3c == 3) {
            k50 = c->f78;
            k54 = k50;
        }
        float t1v = Clamp((-p1.y - k70) / (k74 - k70), DAT_002e0460, DAT_002e0464);
        float t2v = Clamp((y0 - k58) / (k5c - k58), DAT_002e0468, DAT_002e046c);
        self->f84 = (k50 + t1v * (k54 - k50)) * (k60 + t2v * (k64 - k60));
        self->f88 = k68 + t1v * (k6c - k68);
        DAT_002e044c = 0.4f;
    }
}
