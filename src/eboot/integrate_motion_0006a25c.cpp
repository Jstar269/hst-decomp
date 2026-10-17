/* HSTMATCH module=EBOOT.BIN start=0x0006a25c end=0x0006a3f4 symbol=FUN_0006a25c lang=c++ */
/* Clone of src/sharing_main/integrate_motion_0006b7c0.cpp (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Motion step with the VFPU scale/add helpers (0x224c0 / 0x22440): counts the timer down, advances pos by vel*dt and acc*(dt*(dt+1)/2) (both scaled by f68) and vel by acc*dt, returns whether the timer ran out. Vec4 is a plain POD (a user constructor makes the copies out-of-line); the 16-byte copies in retail are the const-reference bindings of the Vec4 temporaries. Names provisional. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern "C" {
Vec4 *FUN_00022498(Vec4 *out, const Vec4 *v, float s);   /* VFPU scale */
Vec4 *FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b); /* VFPU add */
}

inline Vec4 operator*(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

inline Vec4 &operator+=(Vec4 &a, const Vec4 &b)
{
    FUN_00022418(&a, &a, &b);
    return a;
}

struct Obj {
    char pad0[0x30];
    Vec4 pos;
    Vec4 vel;
    Vec4 acc;
    float f60;
    float timer;
    float f68;
};

extern "C" bool FUN_0006a25c(float dt, Obj *self)
{
    self->timer -= dt;
    self->pos += self->vel * dt * self->f68;
    self->pos += self->acc * (dt * (dt + 1.0f) / 2.0f) * self->f68;
    self->vel += self->acc * dt;
    return self->timer <= 0.0f;
}
