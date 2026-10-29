/* HSTMATCH module=EBOOT.BIN start=0x0016a364 end=0x0016a47c symbol=FUN_0016a364 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idioms: a Vec4 with a four-float constructor (arguments evaluated right to left, so side.x/side.z are re-stored from the transformed vector), a local float zero kept in a variable so MWCC does not fold x - 0.0f, and x/y/z of the result read into locals before the stores; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
} __attribute__((aligned(16)));

struct Mat4 {
    Vec4 r[4];
};

extern Mat4 DAT_002bc410;

extern "C" {
float FUN_0000c6dc(float, float);
float FUN_0016a47c(const Vec4 *, const Vec4 *);
void FUN_0004d2cc(float, Mat4 *, const Mat4 *);
Vec4 *FUN_00022548(Vec4 *, const Mat4 *, const Vec4 *);
Vec4 *FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
}

/* Swings pos around the vertical axis: a horizontal vector of the distance from FUN_0016a47c is rotated by the yaw
   of pos plus *yaw_add, then the height of pos is added back. */
extern "C" void FUN_0016a364(Vec4 *out, Vec4 *pos, float *yaw_add)
{
    Vec4 side;
    Vec4 up;
    Mat4 rot;
    Vec4 origin;
    Vec4 sum;

    float zero = 0.0f;
    float yaw = FUN_0000c6dc(pos->x - zero, pos->z - zero);
    origin = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
    side = Vec4(0.0f, 0.0f, FUN_0016a47c(pos, &origin), 1.0f);
    FUN_0004d2cc(yaw + yaw_add[0], &rot, &DAT_002bc410);
    FUN_00022548(&side, &rot, &side);
    up = Vec4(0.0f, pos->y, 0.0f, 1.0f);
    side = Vec4(side.x, 0.0f, side.z, 1.0f);
    FUN_00022418(&sum, &side, &up);
    float x = sum.x;
    float y = sum.y;
    float z = sum.z;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}
