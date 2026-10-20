/* HSTMATCH module=EBOOT.BIN start=0x000ce188 end=0x000ce3f8 symbol=FUN_000ce188 lang=c++ */
#pragma opt_common off

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
    Mat4(const Mat4 &o) : r0(o.r0), r1(o.r1), r2(o.r2), r3(o.r3) {}
};

extern Mat4 DAT_002bc410;
extern char *DAT_003313c4;

struct SubInner {
    char pad[0x58];
    void *bone_base;
};

struct SubOuter {
    char pad[0x5bc];
    SubInner *inner;
};

struct HandleObj {
    char pad[0x44];
    int handle;
};

struct GlobalSystem {
    char pad[0x70];
    SubOuter *outer[1];
    char pad2[0x90 - 0x74];
    HandleObj *handle_obj;
};

extern GlobalSystem *DAT_003386b0;

struct BoneItem {
    int bone_id;
    char pad[32];
};

struct Obj {
    char pad[0xd8];
    BoneItem bones[1];
    char pad2[0x154 - (0xd8 + sizeof(BoneItem))];
    int flags[1];
};

extern "C" {
void FUN_00055240(Mat4 *out, void *bone_base, int bone_id);
void FUN_00022434(Vec4 *out, const Vec4 *target, const Vec4 *pos);
void FUN_00022518(Vec4 *out, const Vec4 *in);
void FUN_00022498(Vec4 *out, const Vec4 *in, float scale);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_000ce754(int handle, const Mat4 *m, int a2, int a3, float f1, float f2, float f3);
}

extern "C" void FUN_000ce188(Obj *self, int idx)
{
    Mat4 m;
    Vec4 scaled_copy;
    Vec4 dir_copy;
    Vec4 diff_copy;
    Mat4 m2;
    Mat4 m1;
    Vec4 pos;
    Vec4 diff;
    Vec4 dir;
    Vec4 scaled;

    SubOuter *outer = DAT_003386b0->outer[idx];
    if (outer == 0)
        return;
    SubInner *inner = outer->inner;
    if (inner == 0)
        return;
    void *bone_base = inner->bone_base;
    if (bone_base == 0)
        return;

    int *p_bone = &self->bones[idx].bone_id;
    FUN_00055240(&m1, bone_base, *p_bone);
    FUN_00055240(&m2, bone_base, *p_bone);

    const Vec4 *m1_r3 = &m1.r3;

    FUN_00022434(&diff, (const Vec4 *)(DAT_003313c4 + 0x1d0), &m2.r3);
    diff_copy = diff;

    FUN_00022518(&dir, &diff_copy);
    dir.w = 0.0f;
    dir_copy = dir;
    dir_copy.w = 0.0f;

    FUN_00022498(&scaled, &dir_copy, 0.29999998f);
    scaled_copy = scaled;

    FUN_00022418(&pos, &scaled_copy, m1_r3);

    self->flags[idx] = 0;

    m = DAT_002bc410;
    m.r3 = pos;

    int handle = DAT_003386b0->handle_obj->handle;
    FUN_000ce754(handle, &m, 5, 1, 3500.0f, 1.0f, 0.0f);
}
// near miss from lane s10171846g1r1-0 (unreviewed)
