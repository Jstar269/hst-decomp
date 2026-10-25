/* HSTMATCH module=hstp_trans_main.prx start=0x000f523c end=0x000f54b4 symbol=FUN_000f523c lang=c++ */
/* Clone of src/eboot/anim_scale_rotate_000efb74.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
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
            Key **k = tracks[i].key;
            float t = k ? (*k)->t : 0.0f;
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

extern const Mat4 DAT_002cc260;
extern float DAT_0037e038;
extern signed char DAT_003e1f00;
extern Vec4 DAT_003e1f10;

extern "C" {
Vec4 *FUN_000224c0(Vec4 *out, const Vec4 *v, float s);
void FUN_0004d644(float a, Mat4 *out, const Mat4 *in);
void FUN_00055b64(Anim *a, Mat4 *m);
void FUN_00059e58(Anim *a);
void FUN_0005fec8(Anim *a);
void FUN_000f4c2c(Self *self, int state);
}

extern "C" void FUN_000f523c(Self *self)
{
    Mat4 m = DAT_002cc260;
    if (DAT_003e1f00 == 0) {
        DAT_003e1f10.x = 0.0f;
        DAT_003e1f10.y = -0.07f;
        DAT_003e1f10.z = 0.0f;
        DAT_003e1f10.w = 1.0f;
        DAT_003e1f00 = 1;
    }
    float s = DAT_0037e038;
    FUN_000224c0(&m.r0, &m.r0, s);
    FUN_000224c0(&m.r1, &m.r1, s);
    FUN_000224c0(&m.r2, &m.r2, s);
    FUN_000224c0(&m.r3, &m.r3, s);
    FUN_0004d644(0.017453292f * self->yaw, &m, &m);
    m.r3 = DAT_003e1f10;
    FUN_00055b64(self->anim, &m);
    Anim *a = self->anim;
    FUN_00059e58(a);
    FUN_0005fec8(a);
    if (self->anim->Done())
        FUN_000f4c2c(self, 3);
}
