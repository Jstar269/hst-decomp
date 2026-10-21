/* HSTMATCH module=hstp_trans_main.prx start=0x002b56a8 end=0x002b59ec symbol=FUN_002b56a8 lang=c++ */
/* Clone of src/eboot/screen_setup_texts_002a5f18.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
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
extern char *DAT_003ea8e8;
extern int DAT_003a9ee4;
extern int DAT_003aa010;
extern char DAT_003aa0d4[];
void FUN_00111aa4(void *, int, int);
void FUN_002b6160(void *, int);
int FUN_002be968(char *);
char *FUN_0020d1e0(int, int, int);
void FUN_000143b0(char *, char *, ...);
void FUN_002be970(char *, int *, int *);
int FUN_002bea30(char *);
void FUN_000149a8(char *, char *);
float FUN_002bea40(char *);
float FUN_002bea6c(char *);
int FUN_002bea98(char *);
int FUN_002beaa0(char *);
char *FUN_002be918(char *);
float FUN_002be938(char *);
int FUN_002be928(char *);
int FUN_002be948(char *);
int FUN_002be950(char *);
int FUN_002be958(char *);
void FUN_002b497c(int, char *, char *);
void FUN_002b59ec(void *);
void FUN_002b55cc(void *, int);
void FUN_00113a50();

void FUN_002b56a8(char *self)
{
  char *base;
  int n;
  int a, b;
  int v;
  float f;
  int p, q, r, rem;
  Model *m;

  base = DAT_003ea8e8 + 0x87128;
  *(unsigned char *)(self + 0x1558) = 0;
  *(int *)(self + 0x884) = 9;
  FUN_00111aa4(*(void **)(self + 0x178), *(int *)(self + 0x884), 2);
  FUN_002b6160(self, *(int *)(self + 0x884));
  v = FUN_002be968(base);
  FUN_000143b0(self + 0x1fd, FUN_0020d1e0(0x13, 0xd, 3), v);
  a = 0;
  b = 0;
  FUN_002be970(base, &a, &b);
  FUN_000143b0(self + 0x27d, FUN_0020d1e0(0x13, 0xd, 2), a, b);
  FUN_000149a8(self + 0x2fd, FUN_0020d1e0(0xe, 1, FUN_002bea30(base)));
  v = (int)(100.0f * FUN_002bea40(base));
  FUN_000143b0(self + 0x37d, FUN_0020d1e0(0x13, 0xd, 0), v);
  v = (int)(100.0f * FUN_002bea6c(base));
  FUN_000143b0(self + 0x3fd, FUN_0020d1e0(0x13, 0xd, 0), v);
  p = FUN_002bea98(base);
  q = FUN_002beaa0(base);
  rem = FUN_002beaa0(base) % 10;
  FUN_000149a8(self + 0x47d, FUN_0020d1e0(0xc, 0, p));
  FUN_000149a8(self + 0x4fd, FUN_0020d1e0(0xd, 1, q));
  r = DAT_003a9ee4 + p;
  m = *(Model **)(self + 0xb8);
  m->f24 = r;
  m->f28 = r;
  if (q != 0 && q != 500) {
    *(int *)(self + 0x16fc) = rem;
  } else {
    *(int *)(self + 0x16fc) = -1;
  }
  FUN_000149a8(self + 0x57d, FUN_002be918(base));
  f = FUN_002be938(base);
  n = FUN_002be928(base);
  FUN_000143b0(self + 0x5fd, DAT_003aa0d4, (double)f);
  r = DAT_003aa010 + n;
  m = *(Model **)(self + 0x11c);
  m->f24 = r;
  m->f28 = r;
  v = FUN_002be948(base);
  FUN_000143b0(self + 0x67d, FUN_0020d1e0(0x13, 0xd, 1), v);
  v = FUN_002be950(base);
  FUN_000143b0(self + 0x6fd, FUN_0020d1e0(0x13, 0xd, 1), v);
  FUN_002b497c(FUN_002be958(base), self + 0x77d, self + 0x7fd);
  FUN_002b59ec(self);
  {
    int i = 0;
    char *s = self;
    char *t = self;
    do {
      Item *it = *(Item **)(s + 0x140);
      it->name = t + 0x17d;
      it->flag = 1;
      FUN_00113a50();
      i++;
      s += 4;
      t += 0x80;
    } while (i < 14);
  }
  FUN_002b55cc(self, 0);
}
}
