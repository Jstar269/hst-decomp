/* HSTMATCH module=hstp_trans_main.prx start=0x00136094 end=0x001361c0 symbol=FUN_00136094 lang=c++ */
/* Clone of src/eboot/select_vec_and_negate_0012ac28.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_003e48b4;
extern float DAT_0038144c;
extern float DAT_00381450;
extern "C" {
int FUN_00138c5c(int);
void FUN_00055d60(Mat4 *, void *, int);
void FUN_00093a28(Obj *, Vec4 *);
void FUN_00093a4c(Obj *, Vec4 *);
int FUN_00134494(float, float, Vec4 *, Vec4 *, float *);
}

extern "C" void FUN_00136094(Obj *o)
{
    if (o->f350 < 0 || o->f58 == 0 || DAT_003e48b4 == 0 || !FUN_00138c5c(DAT_003e48b4)) {
        o->v230.x = o->v1b0.x;
        o->v230.y = o->v1b0.y;
        o->v230.z = o->v1b0.z;
        o->v230.w = o->v1b0.w;
    } else {
        Mat4 m;
        FUN_00055d60(&m, o->f58, o->f350);
        o->v230.x = m.r3.x;
        o->v230.y = m.r3.y;
        o->v230.z = m.r3.z;
        o->v230.w = m.r3.w;
    }
    if (DAT_003e48b4 != 0 && FUN_00138c5c(DAT_003e48b4) != 0) {
        FUN_00134494(DAT_0038144c, DAT_00381450, &o->v230, &o->v240, &o->f224);
    }
    FUN_00093a28(o, &o->v230);
    Vec4 n = -o->v240;
    FUN_00093a4c(o, &n);
}
