/* HSTMATCH module=EBOOT.BIN start=0x0025f3a0 end=0x0025f4ac symbol=FUN_0025f3a0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ object with a slot-6 virtual call, bool flag built as (enabled != 0) ^ 1 then re-tested (as in the sibling initializer), and the three float runs plus two bytes copied as ONE struct assignment of a nested struct (separate member assignments interleave the loads); readability pass; exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_003417be;
extern void FUN_00103540(float, void *);
extern void FUN_001037c8(void *, int);
extern void FUN_0025346c(void *, int);
extern void FUN_0025eca0(void *);
extern void FUN_0025e698(void *, int);
}

struct F4 { float a, b, c, d; };
struct F3 { float a, b, c; };
struct F2 { float a, b; };
struct U2 { unsigned char a, b; };

/* Block of three float runs and two bytes, copied as one struct. */
struct Set { F4 v0; F3 v1; F2 v2; U2 v3; };
struct Src {
  char pad[0x58];
  Set s;  /* 0x58 */
};

struct Obj {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5();
  virtual void m6();
  char pad4[0x5c - 4];
  Src *src;  /* 0x5c */
  char pad60[4];
  unsigned char enabled;  /* 0x64 */
  unsigned char altFlag;  /* 0x65 */
  char pad1[0x1c4 - 0x66];
  char sub1c4[0x34];  /* 0x1c4 */
  unsigned char unk1f8;
  char pad2[0x2c8 - 0x1f9];
  Set s;
};

extern "C" void FUN_0025f3a0(Obj *self, unsigned char flag)
{
  self->m6();
  FUN_00103540(99990.0f, self);
  FUN_001037c8(self, -2);
  self->enabled = 1;
  self->altFlag = flag;
  self->unk1f8 = DAT_003417be != 0;
  int b = (self->enabled != 0) ^ 1;
  if (b == 0) {
    b = self->altFlag != 0;
  }
  FUN_0025346c(self->sub1c4, b);
  Src *from = self->src;
  self->s = from->s;
  FUN_0025eca0(self);
  FUN_0025e698(self, 3);
}
