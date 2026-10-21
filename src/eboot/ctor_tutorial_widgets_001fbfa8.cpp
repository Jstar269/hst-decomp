/* HSTMATCH module=EBOOT.BIN start=0x001fbfa8 end=0x001fc170 symbol=FUN_001fbfa8 lang=c++ */
/* Hand-written reconstruction from the disassembly (structure taken from the sibling constructors ctor_two_tables_000f13e8.cpp and ctor_two_tables_000ee6d4.c); exact match verified (matching idioms: the re-read of the stored array element uses an (unsigned long) address cast so it is not CSE'd with the (unsigned int) store, the callee FUN_00051398 declares its pointer parameter before the float, and the virtual call goes through the stored slot); names and types await human review. */
extern char DAT_00309550[];
extern char DAT_002eefd8[];
extern char DAT_002eeff8[];
extern float DAT_002eedb8;
extern char *DAT_002eef20[];
struct Entry {
  int idx;
  int name;
  int out;
};
extern Entry DAT_002eef78[];

extern "C" {
void FUN_00102e38(void *);
void FUN_00104118(void *, char *, int);
void FUN_00103540(void *, float);
int FUN_000143b0(char *, const char *, ...);
void *FUN_00000bcc(unsigned);
void *FUN_00050fc0(void *);
void FUN_000511c4(void *, char *, int);
void FUN_00051398(void *, float);
void FUN_000ffb3c(void *, int);
void *FUN_001039d8(void *, char *, int);
int *FUN_001026b8(void *, int);
}

class Widget {
public:
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5(int v);
};

struct Self {
  void *vt;
  char pad[0x50];
  Widget *a54[3];
  int *a60[8];
  void *a80[3];
  int f8c;
  unsigned char b90;
};

extern "C" Self *FUN_001fbfa8(Self *self)
{
  char buf[256];
  FUN_00102e38(self);
  self->vt = DAT_00309550;
  FUN_00104118(self, DAT_002eefd8, 0);
  FUN_00103540(self, DAT_002eedb8);
  self->a80[0] = 0;
  self->a80[1] = 0;
  self->a80[2] = 0;
  int i = 0;
  int off = 0;
  do {
    FUN_000143b0(buf, DAT_002eeff8, i + 1);
    void *m = FUN_00000bcc(0x48);
    if (m != 0)
      m = FUN_00050fc0(m);
    *(void **)((unsigned int)self + off + 0x80) = m;
    FUN_000511c4(m, buf, 0);
    FUN_00051398(*(void **)((unsigned long)self + off + 0x80), 100.0f + DAT_002eedb8);
    i++;
    off += 4;
  } while (i < 3);
  int j = 0;
  char **src = DAT_002eef20;
  int off2 = 0;
  do {
    Widget *w = (Widget *)FUN_001039d8(self, *src, 0);
    *(Widget **)((unsigned int)self + off2 + 0x54) = w;
    (*(Widget **)((unsigned int)self + off2 + 0x54))->m5(-2);
    j++;
    src++;
    off2 += 4;
  } while (j < 3);
  int k = 0;
  Entry *e = DAT_002eef78;
  int off3 = 0;
  do {
    int *h = FUN_001026b8(self->a54[e->idx], e->name);
    *(int **)((unsigned int)self + off3 + 0x60) = h;
    if (h != 0)
      e->out = h[9];
    k++;
    e++;
    off3 += 4;
  } while (k < 8);
  FUN_000ffb3c(self->a60[6], 1);
  FUN_000ffb3c(self->a60[2], 1);
  FUN_000ffb3c(self->a60[5], 1);
  self->f8c = 0;
  self->b90 = 1;
  return self;
}
