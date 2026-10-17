/* HSTMATCH module=hstp_trans_main.prx start=0x001d131c end=0x001d1444 symbol=FUN_001d131c lang=c++ */
/* Clone of src/eboot/trigger_event_effect_001c2f90.cpp (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: vector member offset correction (w at 0xdc) and scalar field initialization avoiding .data section; exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
};

extern "C" void *DAT_003f3610;
extern "C" void *DAT_003e48b4;
extern "C" void *DAT_00391f48;

extern "C" void FUN_002351b4(void *, int, int, const void *);
extern "C" bool FUN_00235358(void *);
extern "C" bool FUN_001d1d84(int);
extern "C" void FUN_00299114(void *, int, void *, int, float, int);
extern "C" void FUN_001dbf68(void *, int, int);

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

extern "C" void FUN_001d131c(Obj *self)
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
          FUN_002351b4(DAT_003f3610, b8, self->field_bc, &v);
        } else {
          FUN_002351b4(DAT_003f3610, b8, self->field_bc, &self->field_d0);
        }
        bVar1 = false;
      }
      self->field_b1 = 1;
      self->field_c0 = -1;
    }
    if (self->field_b1 != 0) {
      if (bVar1) {
        if (FUN_00235358(DAT_003f3610)) {
          if (FUN_001d1d84(self->field_b8)) {
            FUN_00299114((char *)DAT_003e48b4 + 0x1320, 0, DAT_00391f48, 0, -1.0f, 0);
          }
          FUN_001dbf68(self, self->field_b4, 1);
        }
      }
    }
  }
}
