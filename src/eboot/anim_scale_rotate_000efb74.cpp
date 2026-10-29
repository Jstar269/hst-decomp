/* HSTMATCH module=EBOOT.BIN start=0x000efb74 end=0x000efdec symbol=FUN_000efb74 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
    Mat4(const Mat4 &o) : r0(o.r0), r1(o.r1), r2(o.r2), r3(o.r3) {}
};

struct Key {
    char pad[8];
    float t;
};
struct Track {
    Key **key;
    char pad[0xc];
    float end;
    char pad14[0x20];
};
struct Anim {
    char pad[0xf4];
    Track tracks[1];
    char pad128[0x30];
    int first;
    int last;

    int Last() const { return last; }

    bool Done()
    {
        for (int i = first; i <= Last(); i++) {
            Key **key = tracks[i].key;
            float t = key ? (*key)->t : 0.0f;
            if (tracks[i].end < t)
                return false;
        }
        return true;
    }
};

struct Self {
    char pad[0x90];
    Anim *anim;
    char pad94[0xc];
    float yaw;
};

extern const Mat4 DAT_002bc410;
extern float DAT_002d7260;
extern signed char DAT_00338bc0;
extern Vec4 DAT_00338bd0;

extern "C" {
Vec4 *FUN_00022498(Vec4 *out, const Vec4 *v, float s);
void FUN_0004d2cc(float a, Mat4 *out, const Mat4 *in);
void FUN_00055044(Anim *a, Mat4 *m);
void FUN_00059174(Anim *a);
void FUN_0005f0d8(Anim *a);
void FUN_000ef564(Self *self, int state);
}

extern "C" void FUN_000efb74(Self *self)
{
    /* Scale the base matrix, rotate it by the yaw (degrees to radians), set its translation, push it to the animation. */
    Mat4 m = DAT_002bc410;
    if (DAT_00338bc0 == 0) {
        DAT_00338bd0.x = 0.0f;
        DAT_00338bd0.y = -0.07f;
        DAT_00338bd0.z = 0.0f;
        DAT_00338bd0.w = 1.0f;
        DAT_00338bc0 = 1;
    }
    float scale = DAT_002d7260;
    FUN_00022498(&m.r0, &m.r0, scale);
    FUN_00022498(&m.r1, &m.r1, scale);
    FUN_00022498(&m.r2, &m.r2, scale);
    FUN_00022498(&m.r3, &m.r3, scale);
    FUN_0004d2cc(0.017453292f * self->yaw, &m, &m);
    m.r3 = DAT_00338bd0;
    FUN_00055044(self->anim, &m);
    Anim *a = self->anim;
    FUN_00059174(a);
    FUN_0005f0d8(a);
    if (self->anim->Done())
        FUN_000ef564(self, 3);
}
