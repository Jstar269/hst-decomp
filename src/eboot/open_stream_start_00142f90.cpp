/* HSTMATCH module=EBOOT.BIN start=0x00142f90 end=0x001430c4 symbol=FUN_00142f90 lang=c++ data=0x002dbb7c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ virtual call (slot 2) on the device with 6 arguments, flag ternary reversed (param_5 != 0 ? 3 : 1), float first argument 0.0f (f12) to FUN_0005f030, float fields copied, typed structs; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dbb7c-0x002dbb8a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Dev {
  virtual void d0();
  virtual void d1();
  virtual unsigned char Open(const char *name, int a, int b, int c, int d, int flag);
  char pad[0xc0 - 4];
  unsigned char on;
  char pad1[3];
  float f_c4;
  char pad2[0xd0 - 0xc8];
  float f_d0;
};
struct Obj {
  char pad0[4];
  Dev *dev;
  unsigned char ok;
  char pad1[0xd1c - 9];
  unsigned char r;
};

extern "C" {
extern void FUN_00014788(char *, char *);
extern void FUN_0005ec14(Dev *, int, char *, int, int, int, int, int);
extern int FUN_0005eff8(Dev *, int);
extern void FUN_0005f030(float, Dev *, int);
}

extern "C" void FUN_00142f90(Obj *param_1, char *param_2, int param_3, int param_4, int param_5)
{
  int i;
  char *d;
  int flag;
  char buf[512];

  if (param_5 != 0) {
    flag = 3;
  }
  else {
    flag = 1;
  }
  param_1->r = param_1->dev->Open(param_2, param_3, 0, 0, 0, flag);
  i = 0;
  if (*param_2 != '.') {
    d = buf;
    do {
      char *s = param_2 + i;
      i = i + 1;
      *d = *s;
      d = d + 1;
    } while (param_2[i] != '.');
  }
  buf[i] = '\0';
  FUN_00014788(buf, "_motion01.tat");
  FUN_0005ec14(param_1->dev, 0, buf, param_3, 0, 0, 0, 0);
  if (FUN_0005eff8(param_1->dev, 0) == 0) {
    param_1->ok = 0;
  }
  else {
    param_1->ok = 1;
    FUN_0005f030(0.0f, param_1->dev, 0);
    param_1->dev->on = 1;
    param_1->dev->f_c4 = 1.0f;
    param_1->dev->f_d0 = param_1->dev->f_c4;
  }
}
