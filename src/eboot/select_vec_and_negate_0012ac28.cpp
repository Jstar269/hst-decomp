/* HSTMATCH module=EBOOT.BIN start=0x0012ac28 end=0x0012ad54 symbol=FUN_0012ac28 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: the goto web is one || chain with the else arm first (c1 || c2 || c3 || !F(G)), the hidden global argument of 0xd75c restored, Vec4 members with a 4-float ctor and an inline operator- (args evaluated right to left, the loads batch like retail), field-by-field float copies; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
inline Vec4 operator-(const Vec4 &v) { return Vec4(-v.x, -v.y, -v.z, -v.w); }
struct Mat4 { Vec4 r0, r1, r2, r3; };
struct Obj {
    char pad0[0x58];
    void *f58;
    char pad1[0x1b0 - 0x5c];
    Vec4 v1b0;
    char pad2[0x224 - 0x1c0];
    float f224;
    char pad3[0x230 - 0x228];
    Vec4 v230;
    Vec4 v240;
    char pad4[0x350 - 0x250];
    int f350;
};
extern int DAT_0033b574;
extern float DAT_002da3cc;
extern float DAT_002da3d0;
extern "C" {
int FUN_0012d75c(int);
void FUN_00055240(Mat4 *, void *, int);
void FUN_00091d90(Obj *, Vec4 *);
void FUN_00091db4(Obj *, Vec4 *);
int FUN_00129224(float, float, Vec4 *, Vec4 *, float *);
}

extern "C" void FUN_0012ac28(Obj *o)
{
    if (o->f350 < 0 || o->f58 == 0 || DAT_0033b574 == 0 || !FUN_0012d75c(DAT_0033b574)) {
        o->v230.x = o->v1b0.x;
        o->v230.y = o->v1b0.y;
        o->v230.z = o->v1b0.z;
        o->v230.w = o->v1b0.w;
    } else {
        Mat4 m;
        FUN_00055240(&m, o->f58, o->f350);
        o->v230.x = m.r3.x;
        o->v230.y = m.r3.y;
        o->v230.z = m.r3.z;
        o->v230.w = m.r3.w;
    }
    if (DAT_0033b574 != 0 && FUN_0012d75c(DAT_0033b574) != 0) {
        FUN_00129224(DAT_002da3cc, DAT_002da3d0, &o->v230, &o->v240, &o->f224);
    }
    FUN_00091d90(o, &o->v230);
    Vec4 n = -o->v240;
    FUN_00091db4(o, &n);
}
