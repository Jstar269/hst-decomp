/* HSTMATCH module=EBOOT.BIN start=0x0017e6c0 end=0x0017e8bc symbol=FUN_0017e6c0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec3 {
    float x, y, z;
};

struct Vec4 {
    float x, y, z, w;
};

struct LightParam {
    char pad0[4];
    float f4;
    char pad8[28];
    struct Vec3 dir0;     // 36 (0x24)
    struct Vec3 col0;     // 48 (0x30)
    struct Vec3 dir1;     // 60 (0x3c)
    struct Vec3 col1;     // 72 (0x48)
    struct Vec3 ambient;  // 84 (0x54)
};

struct LightTarget {
    char pad0[0x5a0];
    struct Vec4 pos;      // 0x5a0
};

extern void *DAT_003313c4;
extern void FUN_00022518(struct Vec4 *out, const struct Vec4 *in);
extern void FUN_0005c76c(void *mgr, float r, float g, float b, float a);
extern void FUN_0005c7a4(void *mgr, int idx, const struct Vec4 *dir);
extern void FUN_0005c810(void *mgr, int idx, const struct Vec4 *col);

void FUN_0017e6c0(struct LightTarget *target, const struct LightParam *param)
{
    struct Vec4 dir0_vec;
    struct Vec4 dir1_vec;
    struct Vec4 zero_vec0;
    struct Vec4 col0_vec;
    struct Vec4 zero_vec1;
    struct Vec4 col1_vec;
    struct Vec4 norm0;
    struct Vec4 norm1;

    float f4 = param->f4;
    target->pos.x = 0.0f;
    target->pos.y = f4;
    target->pos.z = 5.0f;
    target->pos.w = 0.0f;

    float d0_x = param->dir0.x;
    float d0_z = param->dir0.z;
    float d0_y = param->dir0.y;
    dir0_vec.x = d0_x;
    dir0_vec.y = d0_y;
    dir0_vec.z = d0_z;
    dir0_vec.w = 0.0f;

    float d1_z = param->dir1.z;
    float d1_y = param->dir1.y;
    float d1_x = param->dir1.x;
    dir1_vec.x = d1_x;
    dir1_vec.y = d1_y;
    dir1_vec.z = d1_z;
    dir1_vec.w = 0.0f;

    if (dir0_vec.x == 0.0f && dir0_vec.y == 0.0f && dir0_vec.z == 0.0f) {
        zero_vec0.x = 0.0f;
        zero_vec0.y = 0.0f;
        zero_vec0.z = 0.0f;
        zero_vec0.w = 0.0f;
        FUN_0005c810(DAT_003313c4, 0, &zero_vec0);
    } else {
        FUN_00022518(&norm0, &dir0_vec);
        norm0.w = 0.0f;
        FUN_0005c7a4(DAT_003313c4, 0, &dir0_vec);
        float c0_z = param->col0.z;
        float c0_y = param->col0.y;
        float c0_x = param->col0.x;
        col0_vec.x = c0_x;
        col0_vec.y = c0_y;
        col0_vec.z = c0_z;
        col0_vec.w = 0.0f;
        FUN_0005c810(DAT_003313c4, 0, &col0_vec);
    }

    if (dir1_vec.x == 0.0f && dir1_vec.y == 0.0f && dir1_vec.z == 0.0f) {
        zero_vec1.x = 0.0f;
        zero_vec1.y = 0.0f;
        zero_vec1.z = 0.0f;
        zero_vec1.w = 0.0f;
        FUN_0005c810(DAT_003313c4, 1, &zero_vec1);
    } else {
        FUN_00022518(&norm1, &dir1_vec);
        norm1.w = 0.0f;
        FUN_0005c7a4(DAT_003313c4, 1, &dir1_vec);
        float c1_z = param->col1.z;
        float c1_y = param->col1.y;
        float c1_x = param->col1.x;
        col1_vec.x = c1_x;
        col1_vec.y = c1_y;
        col1_vec.z = c1_z;
        col1_vec.w = 0.0f;
        FUN_0005c810(DAT_003313c4, 1, &col1_vec);
    }

    FUN_0005c76c(DAT_003313c4, param->ambient.x, param->ambient.y, param->ambient.z, 1.0f);
}
