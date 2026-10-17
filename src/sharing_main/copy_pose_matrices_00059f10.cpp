/* HSTMATCH module=hstp_trans_main.prx start=0x00059f10 end=0x0005a228 symbol=FUN_00059f10 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: Vec4 is aligned(16) (the 1/scale vector sits at sp+32, the 16-byte scale query result at sp+48, so the query out-parameter is a Vec4 although only x,y,z are read); `#pragma opt_strength_reduction off` keeps the per-pass i*144 / i*72 recomputation; the loop counters are declared and zeroed BEFORE the `if (count != 0)` guard so `move s4,zero` fills the guard's delay slot; Mat4 = four Vec4 members (row-batched lwc1/swc1 copies for the implicit assignment). */
#pragma opt_strength_reduction off
struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r0, r1, r2, r3; };
struct Bone { Mat4 m0; Mat4 m1; signed char parent; signed char idx; char pad[14]; };
struct Anim {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual Mat4 *GetMats();
  virtual int GetScale(Vec4 *out, int idx);
  char pad[0x2c];
  char sub30[0x54];
  float f84;
};
struct Ext { int pad8[2]; int f8; };
struct Self {
  char pad0[0x8c];
  Ext *ext;
  char pad90[0x160 - 0x90];
  Mat4 *mats;
  int extra;
  char pad168[0x174 - 0x168];
  Bone *bones;
  unsigned count;
  char pad17c[4];
  Anim *anim;
  char pad184[0x1a8 - 0x184];
  unsigned char flag;
};
extern "C" {
extern void FUN_00055b64(Self *, void *);
extern void FUN_00055c0c(Self *, float);
extern void FUN_00022478(Vec4 *, Vec4 *, Vec4 *);
extern void FUN_00022598(Mat4 *, Mat4 *, Mat4 *);
extern void FUN_00034acc(int, int, Mat4 *);
}
extern "C" void FUN_00059f10(Self *self)
{
  if (self->anim != 0) {
    FUN_00055b64(self, self->anim->sub30);
    FUN_00055c0c(self, self->anim->f84);
    unsigned i = 0;
    if (self->count != 0) {
      do {
        Bone *b = &self->bones[i];
        int p = b->parent;
        int k = b->idx;
        b->m0 = self->mats[p];
        Mat4 *am = self->anim->GetMats();
        Mat4 *km = am + k;
        if (self->flag == 0) {
          Vec4 sc;
          if (self->anim->GetScale(&sc, k) != 0) {
            Vec4 inv;
            inv.x = 1.0f / sc.x;
            inv.w = 1.0f;
            inv.y = 1.0f / sc.y;
            inv.z = 1.0f / sc.z;
            FUN_00022478(&self->mats[p].r0, &self->mats[p].r0, &inv);
            FUN_00022478(&self->mats[p].r1, &self->mats[p].r1, &inv);
            FUN_00022478(&self->mats[p].r2, &self->mats[p].r2, &inv);
          }
        }
        FUN_00022598(&self->mats[p], km, &self->mats[p]);
        if (p > 0)
          FUN_00022598(&self->mats[p], &self->bones[i].m1, &self->mats[p]);
        i++;
      } while (i < self->count);
    }
  }
  if (self->extra != 0)
    FUN_00034acc(self->ext->f8, self->extra, self->mats);
  if (self->anim != 0) {
    unsigned j = 0;
    if (self->count != 0) {
      do {
        Bone *b = &self->bones[j];
        j++;
        self->mats[b->parent] = b->m0;
      } while (j < self->count);
    }
  }
}
