/* HSTMATCH module=hstp_trans_main.prx start=0x00272da4 end=0x00272fd4 symbol=FUN_00272da4 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/panel_state_00261f7c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
void FUN_00108e6c(float, void *);
void FUN_001090f4(void *, int);
void FUN_00108a2c(void *);
void FUN_001bfc3c(void *, int);
int FUN_00111bf8(void *, void *, int, int);
void FUN_00105470(void *, int);
void FUN_002636c0(int, int);
void *FUN_0008f170(void *);
void FUN_00108f54(void *, int);
extern void *DAT_003e1a00;
extern void *DAT_003e1a08;
extern char DAT_003eaad8;
}

extern "C" void FUN_00272da4(Panel *self)
{
  int sel;
  int i;
  int *p;

  if (self->v8() == 0) {
    return;
  }
  ((Sng *)DAT_003e1a00)->m6(99980.0f);
  ((Sng *)DAT_003e1a00)->m5(-256);
  ((Sng *)DAT_003e1a00)->m11();
  FUN_00108e6c(99990.0f, self);
  FUN_001090f4(self, -1);
  FUN_00108a2c(self);
  sel = self->f58->fdc;
  if (self->f58->fea != 0) {
    FUN_001bfc3c(&DAT_003eaad8, 1);
  }
  if (self->f58->fe8 != 0) {
    FUN_001bfc3c(&DAT_003eaad8, 3);
    self->f55 = 1;
    self->f5c->f80 = sel;
    self->f5c->f84 = self->f88;
    self->f58->fe8 = 0;
  } else {
    if (sel == 3 && FUN_00111bf8(self->f58, &self->f88, 4, 0) != 0) {
      FUN_001bfc3c(&DAT_003eaad8, 1);
    }
  }
  for (i = 0; i < 4u; i++) {
    if (i == 0) {
      int sum = self->f84 + self->f88;
      p = (int *)self->f80;
      p[9] = sum;
      p[10] = sum;
    }
    FUN_00105470(self->f68[i], i == sel);
  }
  FUN_00105470(self->f78, self->f88 == 0);
  FUN_00105470(self->f7c, self->f88 == 3);
  self->f5c->b711 = 0;
  self->f5c->b831 = 0;
  FUN_002636c0(10, 0);
  FUN_00108f54(FUN_0008f170(DAT_003e1a08), 0);
  ((Ret *)FUN_0008f170(DAT_003e1a08))->g2();
  self->f60 = self->f60 + 1;
}
