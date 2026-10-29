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

/* Casts a ray straight down from up above pos to down below it; on a hit writes the hit position and normal back and returns 1. */
extern "C" int FUN_00129224(float up, float down, Vec4 *pos, Vec4 *normal, int *id)
{
    Hit hit;
    Ray ray;
    Vec4 up_offset;
    Vec4 start;
    bool world_ready;
    int found;

    hit.dist = 3.4028235e38f;
    hit.a = 0;
    hit.b = 0;
    hit.c = 0;
    up_offset.x = 0.0f;
    up_offset.y = up;
    up_offset.z = 0.0f;
    up_offset.w = 0.0f;
    FUN_00022418(&start, pos, &up_offset);
    ray.start.x = start.x;
    ray.start.y = start.y;
    ray.start.z = start.z;
    ray.start.w = 0.0f;
    ray.dir.x = 0.0f;
    ray.dir.y = -(up + down);
    ray.dir.z = 0.0f;
    ray.dir.w = 0.0f;
    found = 0;
    world_ready = false;
    if (DAT_0033b574 != 0 && FUN_0012d75c(DAT_0033b574) != 0) {
        world_ready = true;
    }
    if (world_ready && FUN_000558e4(DAT_0033b574->world, &hit, &ray, 0, 0, 0, 1) != 0) {
        found = 1;
    }
    if (found != 0) {
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
    return found;
}
