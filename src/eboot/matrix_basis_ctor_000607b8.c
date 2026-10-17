/* HSTMATCH module=EBOOT.BIN start=0x000607b8 end=0x0006093c symbol=FUN_000607b8 lang=c99 */
/* Clone of src/sharing_main/matrix_basis_ctor_0006163c.c (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern Mat4 DAT_002bc410;
extern char DAT_0030708c;
extern void FUN_000224f8(Vec4 *, Vec4 *, Vec4 *);
extern void FUN_00022518(Vec4 *, Vec4 *);

Obj *FUN_000607b8(Obj *param_1)
{
  param_1->vptr = &DAT_0030708c;
  param_1->f10 = DAT_002bc410.r0;
  param_1->f20 = DAT_002bc410.r1;
  param_1->f30 = DAT_002bc410.r2;
  param_1->f40 = DAT_002bc410.r3;
  param_1->f30.x = 0.0f;
  param_1->f30.y = 0.0f;
  param_1->f30.z = -1.0f;
  param_1->f30.w = 0.0f;
  FUN_00022518(&param_1->f30, &param_1->f30);
  param_1->f30.w = 0.0f;
  FUN_000224f8(&param_1->f10, &param_1->f20, &param_1->f30);
  FUN_00022518(&param_1->f10, &param_1->f10);
  param_1->f10.w = 0.0f;
  FUN_000224f8(&param_1->f20, &param_1->f30, &param_1->f10);
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
