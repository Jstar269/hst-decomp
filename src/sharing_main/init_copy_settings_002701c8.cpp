/* HSTMATCH module=hstp_trans_main.prx start=0x002701c8 end=0x002702d4 symbol=FUN_002701c8 lang=c++ */
/* Clone of src/eboot/init_copy_settings_0025f3a0.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ object with a slot-6 virtual call, bool flag built as (f64!=0)^1 then re-tested (as in 0x25f0c4), and the three float runs plus two bytes copied as ONE struct assignment of a nested struct (separate member assignments interleave the loads); exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_003eaaf6;
extern void FUN_00108e6c(float, void *);
extern void FUN_001090f4(void *, int);
extern void FUN_002637c0(void *, int);
extern void FUN_0026fac8(void *);
extern void FUN_0026f4c0(void *, int);
}

struct F4 { float a, b, c, d; };
struct F3 { float a, b, c; };
struct F2 { float a, b; };
struct U2 { unsigned char a, b; };

struct Set { F4 v0; F3 v1; F2 v2; U2 v3; };
struct Src {
  char pad[0x58];
  Set s;
};

struct Obj {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5();
  virtual void m6();
  char pad0[0x5c - 4];
  Src *f5c;
  char pad00[4];
  unsigned char f64;
  unsigned char f65;
  char pad1[0x1c4 - 0x66];
  char f1c4[0x34];
  unsigned char f1f8;
  char pad2[0x2c8 - 0x1f9];
  Set s;
};

extern "C" void FUN_002701c8(Obj *self, unsigned char flag)
{
  self->m6();
  FUN_00108e6c(99990.0f, self);
  FUN_001090f4(self, -2);
  self->f64 = 1;
  self->f65 = flag;
  self->f1f8 = DAT_003eaaf6 != 0;
  int b = (self->f64 != 0) ^ 1;
  if (b == 0) {
    b = self->f65 != 0;
  }
  FUN_002637c0(self->f1c4, b);
  Src *src = self->f5c;
  self->s = src->s;
  FUN_0026fac8(self);
  FUN_0026f4c0(self, 3);
}
