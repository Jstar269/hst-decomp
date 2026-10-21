/* HSTMATCH module=EBOOT.BIN start=0x00103aa0 end=0x00103d60 symbol=FUN_00103aa0 lang=c++ rodata=0x002c0fb0 */
/* Hand-written reconstruction from the disassembly; exact match verified. Object factory: a 10-way switch (jump table at rodata=0x002c0fb0) returning `new Ck(arg)` for each kind, every class an inline-ctor subclass of Obj (base ctor FUN_00103d80, vtable pointer stored from a DAT_ vtable image, then per-kind member inits); kind 6 uses the out-of-line ctor FUN_0010dc48 through an explicit alloc plus null test. Matching idioms: `return new Ck(arg)` per case (not p=alloc; if(p)..; break), FUN_0004700c declared with its float and integer parameters interleaved as (float, void*, float, int, float*4, int*5). Names and types await human review. */
extern char DAT_00307f60;
extern char DAT_00307ad4;
extern char DAT_00307ec0;
extern char DAT_00307e7c;
extern char DAT_00307a90;
extern char DAT_00307a4c;
extern char DAT_00307a08;
extern char DAT_003079c4;
extern char DAT_00307980;

extern "C" {
void FUN_00103d80(void *, int);
void FUN_00103d6c(void *);
void FUN_00103d60(void *);
void FUN_0010b308(void *);
void FUN_0004700c(float, void *, float, int, float, float, float, float, int, int, int, int, int);
void FUN_00047004(void *);
void FUN_00057344(void *);
void FUN_0010d3e4(void *);
void *FUN_0010dc48(void *, int);
void *FUN_00000bcc(int);
}

struct Obj {
  void *vt;
  int w[0x33];
  Obj(int a) { FUN_00103d80(this, a); }
};

struct C0 : Obj {
  int w2[0x48 - 0x34];
  int m[4];
  C0(int a) : Obj(a)
  {
    vt = &DAT_00307f60;
    FUN_00103d6c(m);
    FUN_0010b308(this);
  }
};

struct C1 : Obj {
  C1(int a) : Obj(a) { vt = &DAT_00307ad4; }
};

struct C2 : Obj {
  int w2[4];
  C2(int a) : Obj(a) { vt = &DAT_00307ec0; }
};

struct C3 : Obj {
  int a34[0x46 - 0x34];
  int a46[2];
  int a48[0x52 - 0x48];
  float f52;
  int w2[1];
  C3(int a) : Obj(a)
  {
    vt = &DAT_00307e7c;
    FUN_0004700c(0.0f, a34, 0.0f, 0, 1.0f, 1.0f, 0.0f, 0.0f, 0, 0, 0, -32, 16);
    FUN_00047004(a46);
    FUN_00057344(a48);
    f52 = 100000.5f;
    FUN_0010d3e4(this);
  }
};

struct C4 : Obj {
  int f34;
  int f35;
  int a36[2];
  C4(int a) : Obj(a)
  {
    vt = &DAT_00307a90;
    f34 = 1;
    f35 = 2;
    FUN_00103d60(a36);
  }
};

struct C5 : Obj {
  int a34[2];
  int w2[2];
  C5(int a) : Obj(a)
  {
    vt = &DAT_00307a4c;
    FUN_00103d60(a34);
  }
};

struct C7 : Obj {
  C7(int a) : Obj(a) { vt = &DAT_00307a08; }
};

struct C8 : Obj {
  C8(int a) : Obj(a) { vt = &DAT_003079c4; }
};

struct C9 : Obj {
  int w2[0x45 - 0x34];
  unsigned char b45;
  char pad[3];
  int f46;
  int w3[5];
  C9(int a) : Obj(a)
  {
    vt = &DAT_00307980;
    b45 = 1;
    f46 = 0;
  }
};

extern "C" void *FUN_00103aa0(int unused, int kind, int arg)
{
  switch (kind) {
  case 0:
    return new C0(arg);
  case 1:
    return new C1(arg);
  case 2:
    return new C2(arg);
  case 3:
    return new C3(arg);
  case 4:
    return new C4(arg);
  case 5:
    return new C5(arg);
  case 6: {
    void *q = FUN_00000bcc(0xf0);
    if (q) q = FUN_0010dc48(q, arg);
    return q;
  }
  case 7:
    return new C7(arg);
  case 8:
    return new C8(arg);
  case 9:
    return new C9(arg);
  }
  return 0;
}
