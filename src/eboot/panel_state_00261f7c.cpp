/* HSTMATCH module=EBOOT.BIN start=0x00261f7c end=0x002621ac symbol=FUN_00261f7c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Panel;

struct Sng {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5(int);
  virtual void m6(float);
  virtual void m7();
  virtual void m8();
  virtual void m9();
  virtual void m10();
  virtual void m11();
};

struct Ret {
  virtual void g0();
  virtual void g1();
  virtual void g2();
};

struct SubA {
  char pad0[0xdc];
  int fdc;
  char pad1[8];
  unsigned char fe8;
  unsigned char pad2;
  unsigned char fea;
};

struct SubB {
  char pad0[0x80];
  int f80;
  int f84;
  char pad1[0x711 - 0x88];
  unsigned char b711;
  char pad2[0x831 - 0x712];
  unsigned char b831;
};

struct Panel {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual int v8();
  char pad0[0x51];
  unsigned char f55;
  char pad1[2];
  SubA *f58;
  SubB *f5c;
  int f60;
  char pad2[4];
  int *f68[4];
  int *f78;
  int *f7c;
  int *f80;
  int f84;
  int f88;
};

extern "C" {
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
void FUN_00103128(void *);
void FUN_001b1c44(void *, int);
int FUN_0010ba20(void *, void *, int, int);
void FUN_000ffb3c(void *, int);
void FUN_0025336c(int, int);
void *FUN_0008d994(void *);
void FUN_00103628(void *, int);
extern void *DAT_003386c0;
extern void *DAT_003386c8;
extern char DAT_0034179c;
}

extern "C" void FUN_00261f7c(Panel *self)
{
  int sel;
  int i;
  int *p;

  if (self->v8() == 0) {
    return;
  }
  ((Sng *)DAT_003386c0)->m6(99980.0f);
  ((Sng *)DAT_003386c0)->m5(-256);
  ((Sng *)DAT_003386c0)->m11();
  FUN_00103540(99990.0f, self);
  FUN_001037c8(self, -1);
  FUN_00103128(self);
  sel = self->f58->fdc;
  if (self->f58->fea != 0) {
    FUN_001b1c44(&DAT_0034179c, 1);
  }
  if (self->f58->fe8 != 0) {
    FUN_001b1c44(&DAT_0034179c, 3);
    self->f55 = 1;
    self->f5c->f80 = sel;
    self->f5c->f84 = self->f88;
    self->f58->fe8 = 0;
  } else {
    if (sel == 3 && FUN_0010ba20(self->f58, &self->f88, 4, 0) != 0) {
      FUN_001b1c44(&DAT_0034179c, 1);
    }
  }
  for (i = 0; i < 4u; i++) {
    if (i == 0) {
      int sum = self->f84 + self->f88;
      p = (int *)self->f80;
      p[9] = sum;
      p[10] = sum;
    }
    FUN_000ffb3c(self->f68[i], i == sel);
  }
  FUN_000ffb3c(self->f78, self->f88 == 0);
  FUN_000ffb3c(self->f7c, self->f88 == 3);
  self->f5c->b711 = 0;
  self->f5c->b831 = 0;
  FUN_0025336c(10, 0);
  FUN_00103628(FUN_0008d994(DAT_003386c8), 0);
  ((Ret *)FUN_0008d994(DAT_003386c8))->g2();
  self->f60 = self->f60 + 1;
}
