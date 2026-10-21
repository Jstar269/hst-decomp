/* HSTMATCH module=hstp_trans_main.prx start=0x001093cc end=0x0010968c symbol=FUN_001093cc lang=c++ rodata=0x002d1260 */
/* Clone of src/eboot/create_object_by_kind_00103aa0.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified. Object factory: a 10-way switch (jump table at rodata=0x2d1260) returning `new Ck(arg)` for each kind, every class an inline-ctor subclass of Obj (base ctor FUN_001096ac, vtable pointer stored from a DAT_ vtable image, then per-kind member inits); kind 6 uses the out-of-line ctor FUN_001141f0 through an explicit alloc plus null test. Matching idioms: `return new Ck(arg)` per case (not p=alloc; if(p)..; break), FUN_00047364 declared with its float and integer parameters interleaved as (float, void*, float, int, float*4, int*5). Names and types await human review. */
extern char DAT_003b122c;
extern char DAT_003b0da0;
extern char DAT_003b118c;
extern char DAT_003b1148;
extern char DAT_003b0d5c;
extern char DAT_003b0d18;
extern char DAT_003b0cd4;
extern char DAT_003b0c90;
extern char DAT_003b0c4c;

extern "C" {
void FUN_001096ac(void *, int);
void FUN_00109698(void *);
void FUN_0010968c(void *);
void FUN_00111414(void *);
void FUN_00047364(float, void *, float, int, float, float, float, float, int, int, int, int, int);
void FUN_0004735c(void *);
void FUN_00057f98(void *);
void FUN_0011398c(void *);
void *FUN_001141f0(void *, int);
void *FUN_00000bcc(int);
}

struct Obj {
  void *vt;
  int w[0x33];
  Obj(int a) { FUN_001096ac(this, a); }
};

struct C0 : Obj {
  int w2[0x48 - 0x34];
  int m[4];
  C0(int a) : Obj(a)
  {
    vt = &DAT_003b122c;
    FUN_00109698(m);
    FUN_00111414(this);
  }
};

struct C1 : Obj {
  C1(int a) : Obj(a) { vt = &DAT_003b0da0; }
};

struct C2 : Obj {
  int w2[4];
  C2(int a) : Obj(a) { vt = &DAT_003b118c; }
};

struct C3 : Obj {
  int a34[0x46 - 0x34];
  int a46[2];
  int a48[0x52 - 0x48];
  float f52;
  int w2[1];
  C3(int a) : Obj(a)
  {
    vt = &DAT_003b1148;
    FUN_00047364(0.0f, a34, 0.0f, 0, 1.0f, 1.0f, 0.0f, 0.0f, 0, 0, 0, -32, 16);
    FUN_0004735c(a46);
    FUN_00057f98(a48);
    f52 = 100000.5f;
    FUN_0011398c(this);
  }
};

struct C4 : Obj {
  int f34;
  int f35;
  int a36[2];
  C4(int a) : Obj(a)
  {
    vt = &DAT_003b0d5c;
    f34 = 1;
    f35 = 2;
    FUN_0010968c(a36);
  }
};

struct C5 : Obj {
  int a34[2];
  int w2[2];
  C5(int a) : Obj(a)
  {
    vt = &DAT_003b0d18;
    FUN_0010968c(a34);
  }
};

struct C7 : Obj {
  C7(int a) : Obj(a) { vt = &DAT_003b0cd4; }
};

struct C8 : Obj {
  C8(int a) : Obj(a) { vt = &DAT_003b0c90; }
};

struct C9 : Obj {
  int w2[0x45 - 0x34];
  unsigned char b45;
  char pad[3];
  int f46;
  int w3[5];
  C9(int a) : Obj(a)
  {
    vt = &DAT_003b0c4c;
    b45 = 1;
    f46 = 0;
  }
};

extern "C" void *FUN_001093cc(int unused, int kind, int arg)
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
    if (q) q = FUN_001141f0(q, arg);
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
