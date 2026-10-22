/* HSTMATCH module=EBOOT.BIN start=0x00063554 end=0x0006367c symbol=FUN_00063554 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Blends two vectors of the object: out = f20 + (f30 - f20) * s with s = 1 - num/den, where den is
   max(DAT_002d11bc, f8) and num is max(f0c, DAT_002d11b8); the three out-of-line vector helpers
   (0x22434 subtract, 0x22498 scale, 0x22418 add) write into plain stack temporaries that are copied
   field by field. Matching idiom: Max() returns a const reference, which gives retail's address
   select between the object member and the global. */
struct V4 {
    float x, y, z, w;
};

struct Obj {
    char pad[8];
    float f8;
    float fc;
    char pad2[0x20 - 0x10];
    V4 f20;
    V4 f30;
};

extern "C" {
extern float DAT_002d11b8;
extern float DAT_002d11bc;
void FUN_00022434(V4 *, V4 *, V4 *);
void FUN_00022498(float, V4 *, V4 *);
void FUN_00022418(V4 *, V4 *, V4 *);
}

static inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }

extern "C" void FUN_00063554(V4 *out, Obj *p)
{
    const float &den = Max(DAT_002d11bc, p->f8);
    const float &num = Max(p->fc, DAT_002d11b8);
    float scale = 1.0f - num / den;
    V4 e;
    V4 d;
    V4 t1;
    V4 t2;
    V4 f;
    FUN_00022434(&t1, &p->f30, &p->f20);
    d = t1;
    FUN_00022498(scale, &t2, &d);
    e = t2;
    FUN_00022418(&f, &p->f20, &e);
    out->x = f.x;
    out->y = f.y;
    out->z = f.z;
    out->w = f.w;
}
