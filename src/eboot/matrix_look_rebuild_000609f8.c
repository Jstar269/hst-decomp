/* HSTMATCH module=EBOOT.BIN start=0x000609f8 end=0x00060bb8 symbol=FUN_000609f8 lang=c99 */
/* Hand-written reconstruction from the disassembly (twin of src/sharing_main/matrix_look_rebuild_0006187c.c, supersedes the near miss wip/matrix_rebuild_000609f8.c); exact match verified (matching idiom: the translation row is copied onto itself field by field before being overwritten, as in matrix_basis_ctor_0006163c.c); names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { Vec4 r0, r1, r2, r3; } Mat4;
typedef struct {
  void *vptr;
  char pad4[0xc];
  Mat4 m;
  float f50;
  char pad54[0xc];
  Vec4 f60;
  float f70;
} Obj;

extern void FUN_00022434(Vec4 *, Vec4 *, Vec4 *);
extern float FUN_000224d8(Vec4 *, Vec4 *);
extern void FUN_000224f8(Vec4 *, Vec4 *, Vec4 *);
extern void FUN_00022518(Vec4 *, Vec4 *);
extern float FUN_00022e44(float);
extern Vec4 FUN_00060bb8(Vec4 *, float);

void FUN_000609f8(Obj *self)
{
  Mat4 m;
  Vec4 up;
  Vec4 dd;
  Vec4 d2;
  Vec4 d;

  FUN_00022434(&d, &self->f60, &self->m.r3);
  m.r2.x = d.x;
  m.r2.y = d.y;
  m.r2.z = d.z;
  m.r2.w = 0.0f;
  up = FUN_00060bb8(&m.r2, self->f70);
  m.r1.x = up.x;
  m.r1.y = up.y;
  m.r1.z = up.z;
  m.r1.w = 0.0f;
  FUN_00022518(&m.r2, &m.r2);
  m.r2.w = 0.0f;
  FUN_000224f8(&m.r0, &m.r1, &m.r2);
  FUN_00022518(&m.r0, &m.r0);
  m.r0.w = 0.0f;
  FUN_000224f8(&m.r1, &m.r2, &m.r0);
  m.r3.x = m.r3.x;
  m.r3.y = m.r3.y;
  m.r3.z = m.r3.z;
  m.r3.w = m.r3.w;
  m.r3.x = self->m.r3.x;
  m.r3.y = self->m.r3.y;
  m.r3.z = self->m.r3.z;
  m.r3.w = 1.0f;
  self->m.r0 = m.r0;
  self->m.r1 = m.r1;
  self->m.r2 = m.r2;
  self->m.r3 = m.r3;
  FUN_00022434(&d2, &self->f60, &self->m.r3);
  dd = d2;
  self->f50 = FUN_00022e44(FUN_000224d8(&dd, &dd));
}
