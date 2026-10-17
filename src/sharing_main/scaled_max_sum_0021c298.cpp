/* HSTMATCH module=hstp_trans_main.prx start=0x0021c298 end=0x0021c3c8 symbol=FUN_0021c298 lang=c++ */
/* Clone of src/eboot/scaled_max_sum_0020d6fc.cpp (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Self { char pad[0x8a5]; unsigned char flag; };
struct Cfg { char pad[0x45]; unsigned char f45; };
struct A { char pad[0x1c]; float f1c; char pad2[0x38]; float f58; float f5c; };
struct B { char pad[0x58]; float f58; float f5c; char pad2[0x1a4]; float f204; };

extern float DAT_00397ba8;
extern float DAT_00397bac;
extern float DAT_00397bb0;
extern Cfg *DAT_003e1e84;
extern "C" B *FUN_002248ac(Self *);
extern "C" A *FUN_0022492c(void);
extern "C" A *FUN_00224a48(void);

static inline float Max(const float &a, const float &b)
{
  return a > b ? a : b;
}

extern "C" float FUN_0021c298(Self *self)
{
  if (self->flag != 0) {
    return Max(DAT_00397ba8, FUN_0022492c()->f5c + FUN_002248ac(self)->f5c) * 0.01f;
  }
  if (DAT_003e1e84->f45 != 0) {
    return Max(DAT_00397bac, FUN_0022492c()->f58 + FUN_002248ac(self)->f58) * 0.01f;
  }
  return Max(DAT_00397bb0, FUN_00224a48()->f1c + FUN_002248ac(self)->f204) * 0.01f;
}
