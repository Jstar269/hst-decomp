/* HSTMATCH module=hstp_trans_main.prx start=0x00255d0c end=0x00255e78 symbol=FUN_00255d0c lang=c99 */
/* Clone of src/eboot/FUN_00245b04.c (hstclone.py tag s10172123g5r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: C99 4-float struct copies, LCG random seed update; exact match verified; names and types await human review. */

extern void *DAT_003e95e0;
extern void FUN_00055b64(void *sub, void *mat);

struct Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    struct Vec4 r0, r1, r2, r3;
};

struct GlobalSeedHolder {
    char pad[0x1360];
    int seed;
};

struct Obj {
    char pad[60];
    unsigned char f3c;     // 60 (0x3c)
    unsigned char f3d;     // 61 (0x3d)
    char pad62[2];
    int f40;               // 64 (0x40)
    char pad68[4];
    unsigned char f48;     // 72 (0x48)
    char pad73[23];
    char sub_60[448];      // 96 (0x60)
    struct Mat4 mat_544;   // 544 (0x220)
    char pad608[32];
    struct Vec4 pos_640;   // 640 (0x280)
    struct Vec4 pos_656;   // 656 (0x290)
    char pad672[97];
    unsigned char f301;    // 769 (0x301)
    char pad770[34];
    int f324;              // 804 (0x324)
    char pad808[1];
    unsigned char f329;    // 809 (0x329)
};

void FUN_00255d0c(struct Obj *self)
{
    self->pos_640.x = self->pos_656.x;
    self->pos_640.y = self->pos_656.y;
    self->pos_640.z = self->pos_656.z;
    self->pos_640.w = self->pos_656.w;

    if (self->f40 != 0) {
        self->f40 = 0;
        self->f48 = 1;
    }

    struct Mat4 local_mat;
    local_mat.r0 = self->mat_544.r0;
    local_mat.r1 = self->mat_544.r1;
    local_mat.r2 = self->mat_544.r2;
    local_mat.r3 = self->mat_544.r3;

    local_mat.r3.x = self->pos_640.x;
    local_mat.r3.y = self->pos_640.y;
    local_mat.r3.z = self->pos_640.z;
    local_mat.r3.w = self->pos_640.w;

    FUN_00055b64(self->sub_60, &local_mat);

    int flag = 1;
    if (self->f301 == 0) {
        int seed = ((struct GlobalSeedHolder *)DAT_003e95e0)->seed * 0x343fd + 0x269ec3;
        ((struct GlobalSeedHolder *)DAT_003e95e0)->seed = seed;
        if (((seed >> 16) & 0x7fff) % 100 < 50) {
            goto label;
        }
        flag = 0;
    }
label:
    self->f3c = flag;

    self->f3d = self->f3c;
    self->f324 = 0;
    self->f329 = 0;
}
