/* HSTMATCH module=EBOOT.BIN start=0x000938b8 end=0x000939a4 symbol=FUN_000938b8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Returns a 4x4 matrix by value (hidden result pointer in a0): the model's matrix for index idx (0x55240)
   when the object at +0x58 is set, else a copy of the global identity matrix at 0x2bc410. The unscheduled
   lwc1/swc1 pairs with one lui per field come from a user-declared memberwise copy constructor. Names
   provisional. */
struct Mat4_000938b8 {
    float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
    Mat4_000938b8() {}
    Mat4_000938b8(const Mat4_000938b8 &o)
        : m00(o.m00), m01(o.m01), m02(o.m02), m03(o.m03), m10(o.m10), m11(o.m11), m12(o.m12), m13(o.m13),
          m20(o.m20), m21(o.m21), m22(o.m22), m23(o.m23), m30(o.m30), m31(o.m31), m32(o.m32), m33(o.m33) {}
};
struct Model_000938b8;
extern "C" Mat4_000938b8 FUN_00055240(Model_000938b8 *m, int idx);
extern "C" const Mat4_000938b8 DAT_002bc410; /* identity */
struct Obj_000938b8 {
    char pad[0x58];
    Model_000938b8 *model;
};
extern "C" Mat4_000938b8 FUN_000938b8(Obj_000938b8 *o, int idx)
{
    if (o->model)
        return FUN_00055240(o->model, idx);
    return DAT_002bc410;
}
