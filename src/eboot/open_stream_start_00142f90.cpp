/* HSTMATCH module=EBOOT.BIN start=0x00142f90 end=0x001430c4 symbol=FUN_00142f90 lang=c++ data=0x002dbb7c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ virtual call (slot 2) on the device with 6 arguments, flag ternary reversed (modeFlag != 0 ? 3 : 1), float first argument 0.0f (f12) to FUN_0005f030, float fields copied, typed structs; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dbb7c-0x002dbb8a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Dev {
  virtual void d0();
  virtual void d1();
  virtual unsigned char Open(const char *name, int a, int b, int c, int d, int flag);
  char pad[0xc0 - 4];
  unsigned char active;
  char pad1[3];
  float unkc4;
  char pad2[0xd0 - 0xc8];
  float unkd0;
};
struct Obj {
  char pad0[4];
  Dev *dev;
  unsigned char ok; /* set when the second step succeeds */
  char pad1[0xd1c - 9];
  unsigned char result; /* open result */
};

extern "C" {
extern void FUN_00014788(char *, char *);
extern void FUN_0005ec14(Dev *, int, char *, int, int, int, int, int);
extern int FUN_0005eff8(Dev *, int);
extern void FUN_0005f030(float, Dev *, int);
}

/* Open the stream named by name on the device, then load the "<name without extension>_motion01.tat" companion. */
extern "C" void FUN_00142f90(Obj *self, char *name, int arg, int unused, int modeFlag)
{
  int i;
  char *dst;
  int flag;
  char buf[512];

  if (modeFlag != 0) {
    flag = 3;
  }
  else {
    flag = 1;
  }
  self->result = self->dev->Open(name, arg, 0, 0, 0, flag);
  i = 0;
  if (*name != '.') {
    dst = buf;
    do {
      char *src = name + i;
      i = i + 1;
      *dst = *src;
      dst = dst + 1;
    } while (name[i] != '.');
  }
  buf[i] = '\0';
  FUN_00014788(buf, "_motion01.tat");
  FUN_0005ec14(self->dev, 0, buf, arg, 0, 0, 0, 0);
  if (FUN_0005eff8(self->dev, 0) == 0) {
    self->ok = 0;
  }
  else {
    self->ok = 1;
    FUN_0005f030(0.0f, self->dev, 0);
    self->dev->active = 1;
    self->dev->unkc4 = 1.0f;
    self->dev->unkd0 = self->dev->unkc4;
  }
}
