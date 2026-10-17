/* HSTMATCH module=hstp_trans_main.prx start=0x0006163c end=0x000617c0 symbol=FUN_0006163c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed Mat4/Vec4 structs, the 64-byte copy from the global matrix as four Vec4 member assignments (row-batched lwc1/swc1), float member stores of 0.0f/-1.0f/1.0f, the last row copied onto itself field by field (as in copy_float_state_00062160.c); exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef struct { float x, y, z, w; } Vec4;
typedef struct { Vec4 r0, r1, r2, r3; } Mat4;
typedef struct {
  void *vptr;
  char pad4[0xc];
  Vec4 f10;
  Vec4 f20;
  Vec4 f30;
  Vec4 f40;
  float f50;
  char pad54[0xc];
  Vec4 f60;
  float f70;
} Obj;

extern Mat4 DAT_002cc260;
extern char DAT_003b0358;
extern void FUN_00022520(Vec4 *, Vec4 *, Vec4 *);
extern void FUN_00022540(Vec4 *, Vec4 *);

Obj *FUN_0006163c(Obj *param_1)
{
  param_1->vptr = &DAT_003b0358;
  param_1->f10 = DAT_002cc260.r0;
  param_1->f20 = DAT_002cc260.r1;
  param_1->f30 = DAT_002cc260.r2;
  param_1->f40 = DAT_002cc260.r3;
  param_1->f30.x = 0.0f;
  param_1->f30.y = 0.0f;
  param_1->f30.z = -1.0f;
  param_1->f30.w = 0.0f;
  FUN_00022540(&param_1->f30, &param_1->f30);
  param_1->f30.w = 0.0f;
  FUN_00022520(&param_1->f10, &param_1->f20, &param_1->f30);
  FUN_00022540(&param_1->f10, &param_1->f10);
  param_1->f10.w = 0.0f;
  FUN_00022520(&param_1->f20, &param_1->f30, &param_1->f10);
  param_1->f40.x = param_1->f40.x;
  param_1->f40.y = param_1->f40.y;
  param_1->f40.z = param_1->f40.z;
  param_1->f40.w = param_1->f40.w;
  param_1->f50 = 1.0f;
  param_1->f60.x = 0.0f;
  param_1->f60.y = 0.0f;
  param_1->f60.z = -1.0f;
  param_1->f60.w = 0.0f;
  param_1->f70 = 0.0f;
  return param_1;
}
