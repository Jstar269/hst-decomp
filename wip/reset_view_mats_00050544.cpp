/* HSTMATCH module=EBOOT.BIN start=0x00050544 end=0x000507b0 symbol=FUN_00050544 lang=c++ */
struct Vec4 {
    float x, y, z, w;
    Vec4 &operator=(const Vec4 &o) { float a = o.x, b = o.y, c = o.z, d = o.w; x = a; y = b; z = c; w = d; return *this; }
};
struct Mat {
    Vec4 r[4];
    Mat &operator=(const Mat &o) { Vec4 *d = r; d[0] = o.r[0]; d[1] = o.r[1]; d[2] = o.r[2]; d[3] = o.r[3]; return *this; }
};
struct Obj {
    char pad[0x1a010];
    int c0;
    int c1;
    int c2;
    int c3;
    Mat m0;
    Mat m1;
};

extern "C" {
extern char DAT_00311170;
extern char DAT_002d0a6c;
extern char DAT_002d0d40;
extern Mat DAT_002bc410;
int FUN_00039fc4(Obj *);
void FUN_0004f010(char *a, int b, char *c, int d, char *e);
void FUN_000507b0(float, Obj *);
}

extern "C" void FUN_00050544(Obj *self)
{
    int v = FUN_00039fc4(self);
    if (v != 0) {
        FUN_0004f010(&DAT_00311170, v, &DAT_002d0a6c, 0x74d, &DAT_002d0d40);
    }
    self->c0 = 0;
    self->c1 = 0;
    self->c2 = 0;
    self->c3 = 0;
    self->m0 = DAT_002bc410;
    self->m1 = DAT_002bc410;
    FUN_000507b0(0.0f, self);
}
// NEAR 113 words: retail materialises each destination row address (lui at,1 / ori / addu reg,s0,at) and stores 0..12 off it, while reloading the identity source with a fresh lui per float, loading x,y,z,w in order.
// Ours keeps one row base for the whole matrix and loads x last. Placement new (&r[i]) Vec4(o.r[i]) gets the per-row base but adds a null check; plain inlines fold into lui 2/negative displacements.
// near miss from lane ol3 (unreviewed)
