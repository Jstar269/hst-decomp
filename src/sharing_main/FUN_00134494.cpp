/* HSTMATCH module=hstp_trans_main.prx start=0x00134494 end=0x00134624 symbol=FUN_00134494 lang=c++ */
/* Clone of src/eboot/FUN_00129224.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (tag a1 candidate used only for the pseudocode shape); the manager pointer tested first is FUN_00138c5c's argument (Ghidra dropped it, retail loads it into a0); the hit record is 144 bytes and the dead first store to *id is kept as retail has it; exact match verified; names and types await human review. */
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

extern Mgr *DAT_003e48b4;

extern "C" {
Vec4 *FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_00138c5c(Mgr *);
unsigned char FUN_00056490(void *, Hit *, Ray *, int, int, int, int);
}

extern "C" int FUN_00134494(float up, float down, Vec4 *pos, Vec4 *normal, int *id)
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
    FUN_00022440(&d, pos, &delta);
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
    if (DAT_003e48b4 != 0 && FUN_00138c5c(DAT_003e48b4) != 0) {
        usable = true;
    }
    if (usable && FUN_00056490(DAT_003e48b4->world, &hit, &ray, 0, 0, 0, 1) != 0) {
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
