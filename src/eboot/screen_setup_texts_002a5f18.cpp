/* HSTMATCH module=EBOOT.BIN start=0x002a5f18 end=0x002a625c symbol=FUN_002a5f18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Model {
  char pad[0x24];
  int f24, f28;
};
struct Item {
  char pad[0xf8];
  char *name;
  char pad_fc[0x3c];
  int flag;
};
struct Screen {
  char pad0[0x140];
  Item *items[14];
  char pad_178[0x4];
};

extern "C" {
extern char *DAT_003415a8;
extern int DAT_00300e48;
extern int DAT_00300f74;
extern char DAT_00301038[];
void FUN_0010b8cc(void *, int, int);
void FUN_002a69d0(void *, int);
int FUN_002af0e4(char *);
char *FUN_001fea10(int, int, int);
void FUN_000143b0(char *, char *, ...);
void FUN_002af0ec(char *, int *, int *);
int FUN_002af1ac(char *);
void FUN_000149a8(char *, char *);
float FUN_002af1bc(char *);
float FUN_002af1e8(char *);
int FUN_002af214(char *);
int FUN_002af21c(char *);
char *FUN_002af094(char *);
float FUN_002af0b4(char *);
int FUN_002af0a4(char *);
int FUN_002af0c4(char *);
int FUN_002af0cc(char *);
int FUN_002af0d4(char *);
void FUN_002a51ec(int, char *, char *);
void FUN_002a625c(void *);
void FUN_002a5e3c(void *, int);
void FUN_0010d4a8();

void FUN_002a5f18(char *self)
{
  char *base;
  int n;
  int a, b;
  int v;
  float f;
  int p, q, r, rem;
  Model *m;

  base = DAT_003415a8 + 0x87128;
  *(unsigned char *)(self + 0x1558) = 0;
  *(int *)(self + 0x884) = 9;
  FUN_0010b8cc(*(void **)(self + 0x178), *(int *)(self + 0x884), 2);
  FUN_002a69d0(self, *(int *)(self + 0x884));
  v = FUN_002af0e4(base);
  FUN_000143b0(self + 0x1fd, FUN_001fea10(0x13, 0xd, 3), v);
  a = 0;
  b = 0;
  FUN_002af0ec(base, &a, &b);
  FUN_000143b0(self + 0x27d, FUN_001fea10(0x13, 0xd, 2), a, b);
  FUN_000149a8(self + 0x2fd, FUN_001fea10(0xe, 1, FUN_002af1ac(base)));
  v = (int)(100.0f * FUN_002af1bc(base));
  FUN_000143b0(self + 0x37d, FUN_001fea10(0x13, 0xd, 0), v);
  v = (int)(100.0f * FUN_002af1e8(base));
  FUN_000143b0(self + 0x3fd, FUN_001fea10(0x13, 0xd, 0), v);
  p = FUN_002af214(base);
  q = FUN_002af21c(base);
  rem = FUN_002af21c(base) % 10;
  FUN_000149a8(self + 0x47d, FUN_001fea10(0xc, 0, p));
  FUN_000149a8(self + 0x4fd, FUN_001fea10(0xd, 1, q));
  r = DAT_00300e48 + p;
  m = *(Model **)(self + 0xb8);
  m->f24 = r;
  m->f28 = r;
  if (q != 0 && q != 500) {
    *(int *)(self + 0x16fc) = rem;
  } else {
    *(int *)(self + 0x16fc) = -1;
  }
  FUN_000149a8(self + 0x57d, FUN_002af094(base));
  f = FUN_002af0b4(base);
  n = FUN_002af0a4(base);
  FUN_000143b0(self + 0x5fd, DAT_00301038, (double)f);
  r = DAT_00300f74 + n;
  m = *(Model **)(self + 0x11c);
  m->f24 = r;
  m->f28 = r;
  v = FUN_002af0c4(base);
  FUN_000143b0(self + 0x67d, FUN_001fea10(0x13, 0xd, 1), v);
  v = FUN_002af0cc(base);
  FUN_000143b0(self + 0x6fd, FUN_001fea10(0x13, 0xd, 1), v);
  FUN_002a51ec(FUN_002af0d4(base), self + 0x77d, self + 0x7fd);
  FUN_002a625c(self);
  {
    int i = 0;
    char *s = self;
    char *t = self;
    do {
      Item *it = *(Item **)(s + 0x140);
      it->name = t + 0x17d;
      it->flag = 1;
      FUN_0010d4a8();
      i++;
      s += 4;
      t += 0x80;
    } while (i < 14);
  }
  FUN_002a5e3c(self, 0);
}
}
