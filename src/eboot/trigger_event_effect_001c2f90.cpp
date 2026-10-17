/* HSTMATCH module=EBOOT.BIN start=0x001c2f90 end=0x001c30b8 symbol=FUN_001c2f90 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: vector member offset correction (w at 0xdc) and scalar field initialization avoiding .data section; exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
};

extern "C" void *DAT_0034a2e0;
extern "C" void *DAT_0033b574;
extern "C" void *DAT_002ea2f0;

extern "C" void FUN_00225c40(void *, int, int, const void *);
extern "C" bool FUN_00225de4(void *);
extern "C" bool FUN_001c39f8(int);
extern "C" void FUN_002879e0(void *, int, void *, int, float, int);
extern "C" void FUN_001cd88c(void *, int, int);

struct Obj {
  char pad_0[8];
  int field_8;
  char pad_c[0xa5];
  unsigned char field_b1;
  char pad_b2[2];
  int field_b4;
  int field_b8;
  int field_bc;
  int field_c0;
  char pad_c4[0xc];
  Vec4 field_d0;
};

extern "C" void FUN_001c2f90(Obj *self)
{
  if (self->field_8 >= self->field_c0) {
    bool bVar1 = true;
    if (self->field_b1 == 0) {
      int b8 = self->field_b8;
      if (b8 >= 0) {
        if (self->field_d0.w == 0.0f) {
          Vec4 v;
          v.y = -10.0f;
          v.x = 0.0f;
          v.z = 0.0f;
          v.w = 0.0f;
          FUN_00225c40(DAT_0034a2e0, b8, self->field_bc, &v);
        } else {
          FUN_00225c40(DAT_0034a2e0, b8, self->field_bc, &self->field_d0);
        }
        bVar1 = false;
      }
      self->field_b1 = 1;
      self->field_c0 = -1;
    }
    if (self->field_b1 != 0) {
      if (bVar1) {
        if (FUN_00225de4(DAT_0034a2e0)) {
          if (FUN_001c39f8(self->field_b8)) {
            FUN_002879e0((char *)DAT_0033b574 + 0x1320, 0, DAT_002ea2f0, 0, -1.0f, 0);
          }
          FUN_001cd88c(self, self->field_b4, 1);
        }
      }
    }
  }
}
