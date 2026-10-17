/* HSTMATCH module=hstp_trans_main.prx start=0x00277564 end=0x002775dc symbol=FUN_00277564 lang=c++ */
/* Clone of src/eboot/FUN_0026665c.cpp (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern "C" void FUN_0002245c(Vec4 *out, void *param_1, void *param_2);
extern "C" void FUN_002779a0(void *param_1, Vec4 param_2, int param_3);
extern "C" void FUN_00277a98(void *param_1);

static inline Vec4 MakeVec4(void *param_1, void *param_2)
{
  Vec4 result;
  FUN_0002245c(&result, param_1, param_2);
  return result;
}

extern "C" void FUN_00277564(char *self)
{
  if (*(unsigned char *)(self + 0x160) != 0)
    FUN_002779a0(self, MakeVec4(self + 0x150, self + 0x130), 0);
  FUN_00277a98(self);
  *(float *)(self + 0x168) = *(float *)(self + 0x164);
}
