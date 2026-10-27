/* HSTMATCH module=hstp_trans_main.prx start=0x002778c8 end=0x002779a0 symbol=FUN_002778c8 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/step_state_vector_0026694c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Copies the 4-float vector at +0x130 to +0x140, then for state (+0x1f0) == 1 runs 0x12c530 on the sub-object at +0x80, passes (+0x130 - +0x140)
   by value to 0x266a24, stores the byte result of 0x12c5ac at +0x120 and, when it is set, moves the state to +0x1f4 and clears it; otherwise 0x266a9c.
   Matching idiom: `switch (state) { case 1: ...; default: ... }` (the if/else form lays out a bne). Names provisional. */
struct Vec4 {
  float f[4];
  Vec4() {}
  Vec4(const Vec4& other) {
    f[0] = other.f[0];
    f[1] = other.f[1];
    f[2] = other.f[2];
    f[3] = other.f[3];
  }
} __attribute__((aligned(16)));

struct Sub { char pad[0x120 - 0x80]; };
struct Self {
  char pad[0x80];
  Sub sub80;
  unsigned char b120;
  char pad2[0x130 - 0x121];
  Vec4 v130;
  Vec4 v140;
  char pad3[0x1f0 - 0x150];
  int state;
  int saved;
};

extern "C" void FUN_0002245c(Vec4 *out, void *param_1, void *param_2);
extern "C" void FUN_0013799c(void *, void *);
extern "C" unsigned char FUN_00137a18(void *);
extern "C" void FUN_002779a0(void *param_1, Vec4 param_2, int param_3);
extern "C" void FUN_00277a18(void *);

static inline Vec4 MakeVec4(void *param_1, void *param_2)
{
  Vec4 result;
  FUN_0002245c(&result, param_1, param_2);
  return result;
}

extern "C" void FUN_002778c8(Self *self)
{
  self->v140.f[0] = self->v130.f[0];
  self->v140.f[1] = self->v130.f[1];
  self->v140.f[2] = self->v130.f[2];
  self->v140.f[3] = self->v130.f[3];
  switch (self->state) {
  case 1:
    FUN_0013799c(&self->sub80, &self->v130);
    FUN_002779a0(self, MakeVec4(&self->v130, &self->v140), 0);
    self->b120 = FUN_00137a18(&self->sub80);
    if (self->b120 != 0 && self->state != 0) {
      self->saved = self->state;
      self->state = 0;
    }
    break;
  default:
    FUN_00277a18(self);
    break;
  }
}
