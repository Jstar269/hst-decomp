/* HSTMATCH module=hstp_trans_main.prx start=0x0020a6c0 end=0x0020a888 symbol=FUN_0020a6c0 lang=c++ */
/* Clone of src/eboot/ctor_tutorial_widgets_001fbfa8.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (structure taken from the sibling constructors ctor_two_tables_000f13e8.cpp and ctor_two_tables_000ee6d4.c); exact match verified (matching idioms: the re-read of the stored array element uses an (unsigned long) address cast so it is not CSE'd with the (unsigned int) store, the callee FUN_00051d38 declares its pointer parameter before the float, and the virtual call goes through the stored slot); names and types await human review. */
extern char DAT_003b281c[];
extern char DAT_00397014[];
extern char DAT_00397034[];
extern float DAT_00396df4;
extern char *DAT_00396f5c[];
struct Entry {
  int idx;
  int name;
  int out;
};
extern Entry DAT_00396fb4[];

extern "C" {
void FUN_0010873c(void *);
void FUN_00109a44(void *, char *, int);
void FUN_00108e6c(void *, float);
int FUN_000143b0(char *, const char *, ...);
void *FUN_00000bcc(unsigned);
void *FUN_000518d4(void *);
void FUN_00051ad8(void *, char *, int);
void FUN_00051d38(void *, float);
void FUN_00105470(void *, int);
void *FUN_00109304(void *, char *, int);
int *FUN_00108124(void *, int);
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

extern "C" Self *FUN_0020a6c0(Self *self)
{
  char buf[256];
  FUN_0010873c(self);
  self->vt = DAT_003b281c;
  FUN_00109a44(self, DAT_00397014, 0);
  FUN_00108e6c(self, DAT_00396df4);
  self->a80[0] = 0;
  self->a80[1] = 0;
  self->a80[2] = 0;
  int i = 0;
  int off = 0;
  do {
    FUN_000143b0(buf, DAT_00397034, i + 1);
    void *m = FUN_00000bcc(0x48);
    if (m != 0)
      m = FUN_000518d4(m);
    *(void **)((unsigned int)self + off + 0x80) = m;
    FUN_00051ad8(m, buf, 0);
    FUN_00051d38(*(void **)((unsigned long)self + off + 0x80), 100.0f + DAT_00396df4);
    i++;
    off += 4;
  } while (i < 3);
  int j = 0;
  char **src = DAT_00396f5c;
  int off2 = 0;
  do {
    Widget *w = (Widget *)FUN_00109304(self, *src, 0);
    *(Widget **)((unsigned int)self + off2 + 0x54) = w;
    (*(Widget **)((unsigned int)self + off2 + 0x54))->m5(-2);
    j++;
    src++;
    off2 += 4;
  } while (j < 3);
  int k = 0;
  Entry *e = DAT_00396fb4;
  int off3 = 0;
  do {
    int *h = FUN_00108124(self->a54[e->idx], e->name);
    *(int **)((unsigned int)self + off3 + 0x60) = h;
    if (h != 0)
      e->out = h[9];
    k++;
    e++;
    off3 += 4;
  } while (k < 8);
  FUN_00105470(self->a60[6], 1);
  FUN_00105470(self->a60[2], 1);
  FUN_00105470(self->a60[5], 1);
  self->f8c = 0;
  self->b90 = 1;
  return self;
}
