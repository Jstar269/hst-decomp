/* HSTMATCH module=EBOOT.BIN start=0x0016a234 end=0x0016a364 symbol=FUN_0016a234 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
} __attribute__((aligned(16)));
struct Mat { float m[16]; } __attribute__((aligned(16)));

extern Mat DAT_002bc410;
extern "C" {
void FUN_0004d278(Mat *, Mat *, float);
void FUN_0004d2cc(Mat *, Mat *, float);
void FUN_00022548(Vec4 *, Mat *, Vec4 *);
float FUN_000224d8(Vec4 *, Vec4 *);
float FUN_00022e44(float);
void FUN_00022418(Vec4 *, Vec4 *, Vec4 *);

/* Builds a vector from a length and two angles: tilts (0, radius, 0) by the pitch, takes the length of its
   horizontal part, swings a vector of that length by the yaw and adds the two. */
void FUN_0016a234(Vec4 *out, float *radius, float *yaw, float *pitch)
{
    Vec4 side;
    Vec4 up;
    Mat rot;
    Vec4 flat;
    Vec4 sum;
    up = Vec4(0.0f, *radius, 0.0f, 1.0f);
    FUN_0004d278(&rot, &DAT_002bc410, *pitch);
    FUN_00022548(&up, &rot, &up);
    flat.x = up.x;
    flat.y = 0.0f;
    flat.z = up.z;
    flat.w = 1.0f;
    float len = FUN_00022e44(FUN_000224d8(&flat, &flat));
    side.x = 0.0f;
    side.y = 0.0f;
    side.z = len;
    side.w = 1.0f;
    FUN_0004d2cc(&rot, &DAT_002bc410, *yaw);
    FUN_00022548(&side, &rot, &side);
    up = Vec4(0.0f, up.y, 0.0f, 1.0f);
    side = Vec4(side.x, 0.0f, side.z, 1.0f);
    FUN_00022418(&sum, &side, &up);
    Vec4 result = sum;
    result.w = 1.0f;
    *out = result;
}
}
