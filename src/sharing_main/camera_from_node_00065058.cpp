/* HSTMATCH module=hstp_trans_main.prx start=0x00065058 end=0x000651e8 symbol=FUN_00065058 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vec4 has a user default and memberwise copy constructor: the node matrix copy `Mat4 local = src->node->m;` is then
   emitted as 16 interleaved lwc1/swc1 $f0 pairs like retail (a POD Mat4 is a word-copy loop, a Mat4-only copy
   constructor batches each row). FUN_0000c018 is newlib tanf: the angle is converted to degrees, then tan(angle/2). */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));
struct Mat4 { Vec4 r0, r1, r2, r3; };
struct Node { char pad[0x30]; Mat4 m; };
struct Src { Node *node; };
struct Obj {
  char pad[0x1d0];
  Vec4 pos;
  Vec4 f1e0;
  Vec4 f1f0;
  float fov;
  float f204;
  float f208;
  char pad20c[0x214 - 0x20c];
  float tan_half_fov;
};
extern "C" {
extern Obj *DAT_003da704;
extern void FUN_00049820(Mat4 *out, Src *src);
extern void FUN_00022598(Mat4 *out, Mat4 *a, Mat4 *b);
extern float FUN_00049cb4(Src *src);
extern float FUN_0000c018(float x);
extern float FUN_00049da8(Src *src);
extern float FUN_00049e34(Src *src);
extern void FUN_0005c8e0(Obj *self);
}
extern "C" void FUN_00065058(Obj *self, Src *src)
{
  if (self == 0)
    self = DAT_003da704;
  Mat4 m;
  FUN_00049820(&m, src);
  Mat4 local = src->node->m;
  FUN_00022598(&m, &local, &m);
  self->pos = m.r3;
  self->f1e0 = m.r2;
  self->f1f0 = m.r1;
  self->fov = FUN_00049cb4(src) * 57.29578f;
  self->tan_half_fov = FUN_0000c018(self->fov * 0.008726646f);
  self->f204 = FUN_00049da8(src);
  self->f208 = FUN_00049e34(src);
  FUN_0005c8e0(self);
}
