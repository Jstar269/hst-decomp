/* HSTMATCH module=EBOOT.BIN start=0x00129224 end=0x001293b4 symbol=FUN_00129224 lang=c++ */
/* Hand-written reconstruction from the disassembly (tag a1 candidate used only for the pseudocode shape); the manager pointer tested first is FUN_0012d75c's argument (Ghidra dropped it, retail loads it into a0); the hit record is 144 bytes and the dead first store to *id is kept as retail has it; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Ray {
    Vec4 start;
    Vec4 dir;
};

struct Hit {
    char hdr[16];
    Vec4 pos;
    Vec4 normal;
    float dist;
    int a;
    int id;
    int b;
    int c;
    char tail[76];
};

struct Mgr {
    char pad[0xc];
    void *world;
};

extern Mgr *DAT_0033b574;

extern "C" {
Vec4 *FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_0012d75c(Mgr *);
unsigned char FUN_000558e4(void *, Hit *, Ray *, int, int, int, int);
}

extern "C" int FUN_00129224(float up, float down, Vec4 *pos, Vec4 *normal, int *id)
{
    Hit hit;
    Ray ray;
    Vec4 delta;
    Vec4 d;
    bool usable;
    int ok;

    hit.dist = 3.4028235e38f;
    hit.a = 0;
    hit.b = 0;
    hit.c = 0;
    delta.x = 0.0f;
    delta.y = up;
    delta.z = 0.0f;
    delta.w = 0.0f;
    FUN_00022418(&d, pos, &delta);
    ray.start.x = d.x;
    ray.start.y = d.y;
    ray.start.z = d.z;
    ray.start.w = 0.0f;
    ray.dir.x = 0.0f;
    ray.dir.y = -(up + down);
    ray.dir.z = 0.0f;
    ray.dir.w = 0.0f;
    ok = 0;
    usable = false;
    if (DAT_0033b574 != 0 && FUN_0012d75c(DAT_0033b574) != 0) {
        usable = true;
    }
    if (usable && FUN_000558e4(DAT_0033b574->world, &hit, &ray, 0, 0, 0, 1) != 0) {
        ok = 1;
    }
    if (ok != 0) {
        *id = hit.id;
        *id = 1;
        normal->x = hit.normal.x;
        normal->y = hit.normal.y;
        normal->z = hit.normal.z;
        normal->w = hit.normal.w;
        pos->x = hit.pos.x;
        pos->y = hit.pos.y;
        pos->z = hit.pos.z;
        pos->w = hit.pos.w;
    }
    return ok;
}
