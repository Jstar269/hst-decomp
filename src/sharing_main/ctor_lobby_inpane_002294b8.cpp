/* HSTMATCH module=hstp_trans_main.prx start=0x002294b8 end=0x00229888 symbol=FUN_002294b8 lang=c++ data=0x00398324 */
/* Hand-written reconstruction (port of src/eboot/ctor_lobby_inpane_00219fa0.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00398324-0x00398354) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Lobby in-pane layout constructor (siblings: ctor_parts_lobby_0021d02c.c). Matching idioms: byte-offset induction variables per table loop (counter, table pointer, offset), the virtual call made on the stored element (w = (slot = lookup())->SetState(-3)), two local float[7] tables copied from consecutive globals with the pointer/counter initialisations placed around the copies (statement positions steer the $f0/$f1 allocation), selects written with != 0 so the likely branch lands as in retail. */
struct Widget {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void SetState(int);
};
struct Entry {
  int idx;
  char *name;
  int result;
};
struct Panel {
  char pad00[0x60];
  float f60;
  float f64;
};
struct Model {
  char pad[0x24];
  int f24, f28;
};

extern "C" {
extern char DAT_003b28b4[];
extern float DAT_00397f08;
extern char *DAT_00397f3c[];
extern Entry DAT_00398178[];
extern float DAT_003982ec, DAT_003982f0, DAT_003982f4, DAT_003982f8, DAT_003982fc, DAT_00398300, DAT_00398304;
extern float DAT_00398308, DAT_0039830c, DAT_00398310, DAT_00398314, DAT_00398318, DAT_0039831c, DAT_00398320;
extern int DAT_0039827c;
extern int DAT_00397f0c[];
void FUN_0010873c(void *);
void FUN_00109a44(void *, char *, int);
void FUN_00108e6c(float, void *);
Widget *FUN_00109304(void *, char *, int);
void *FUN_00108124(void *, char *);
void FUN_00105570(void *, int);
void FUN_00105470(void *, int);
int FUN_001d5580();
void FUN_00108558(void *);
void FUN_00111aa4(void *, int, int);
void FUN_000224c0(float, void *, void *);
void *FUN_00000bcc(int);
void *FUN_001196d8(void *);
int FUN_0020d1e0(int, int, int);
void FUN_0011988c(void *, int, int);
void FUN_001090f4(void *, int);

char *FUN_002294b8(char *self)
{
  float a[7];
  float b[7];

  FUN_0010873c(self);
  *(char **)self = DAT_003b28b4;
  *(int *)(self + 0xe0) = 0;
  FUN_00109a44(self, "data/menu/lobby/lobbyinpane/commandlayouter.lay", 1);
  FUN_00108e6c(DAT_00397f08, self);
  {
    int i = 0;
    char **names = DAT_00397f3c;
    int off = 0;
    do {
      (*(Widget **)(self + off + 0x58) = FUN_00109304(self, *names, 0))->SetState(-3);
      i++;
      names++;
      off += 4;
    } while (i < 3);
  }
  {
    int j = 0;
    Entry *e = DAT_00398178;
    int off = 0;
    do {
      void *h = FUN_00108124(*(void **)(self + e->idx * 4 + 0x58), e->name);
      *(void **)(self + off + 100) = h;
      FUN_00105570(h, -256);
      int r = *(int *)(*(char **)((unsigned int)self + off + 100) + 0x24);
      j++;
      off += 4;
      e->result = r;
      e++;
    } while (j < 31);
  }
  {
    int j = 7;
    int off = 0x1c;
    do {
      FUN_00105470(*(void **)(self + off + 100), 1);
      j++;
      off += 4;
    } while (j <= 13);
  }
  *(int *)(self + 0xe8) = 0;
  int i;
  float *pb;
  float *pa;
  int off;
  pa = a;
  pb = b;
  i = 0;
  a[0] = DAT_003982ec;
  a[1] = DAT_003982f0;
  a[2] = DAT_003982f4;
  a[3] = DAT_003982f8;
  a[4] = DAT_003982fc;
  a[5] = DAT_00398300;
  a[6] = DAT_00398304;
  off = 0;
  b[0] = DAT_00398308;
  b[1] = DAT_0039830c;
  b[2] = DAT_00398310;
  b[3] = DAT_00398314;
  b[4] = DAT_00398318;
  b[5] = DAT_0039831c;
  b[6] = DAT_00398320;
  do {
    int v;
    if (FUN_001d5580() != 0) {
      v = *(int *)pb;
    } else {
      v = *(int *)pa;
    }
    *(int *)(self + off + 0xec) = v;
    i++;
    pb++;
    pa++;
    off += 4;
  } while (i < 7);
  *(int *)(self + 0x108) = FUN_001d5580() != 0 ? 6 : 5;
  {
    int t = DAT_0039827c + (unsigned char)((FUN_001d5580() != 0) ^ 1);
    Model *m = *(Model **)(self + 0xb8);
    m->f24 = t;
    m->f28 = t;
  }
  (*(Panel **)(self + 0x58))->f60 = 8.0f;
  FUN_00108558(*(void **)(self + 0x58));
  (*(Panel **)(self + 0x60))->f60 = 8.0f;
  FUN_00108558(*(void **)(self + 0x60));
  {
    char *obj = *(char **)(*(char **)(self + 0xbc) + 0x20);
    *(char **)(self + 0xe4) = obj;
    *(int *)(obj + 0xd8) = 0;
    *(char *)(obj + 0x114) = 1;
    FUN_00111aa4(*(void **)(self + 0xe4), *(int *)(self + 0xe8), 2);
    FUN_000224c0(0.8f, *(char **)(self + 0xe4) + 0x30, *(char **)(self + 0xe4) + 0x30);
    FUN_000224c0(0.8f, *(char **)(self + 0xe4) + 0x40, *(char **)(self + 0xe4) + 0x40);
    (*(Panel **)(self + 0xe4))->f60 = 32.0f;
    (*(Panel **)(self + 0xe4))->f64 = 33.0f;
    (*(Widget **)(self + 0xe4))->SetState(-2);
    FUN_00108558(*(void **)(self + 0xe4));
  }
  {
    void *p = FUN_00000bcc(0x7c);
    if (p != 0) {
      p = FUN_001196d8(p);
    }
    *(void **)(self + 0xe0) = p;
    if (p != 0) {
      int r = FUN_0020d1e0(0x12, 0x21, DAT_00397f0c[*(int *)((*(int *)(self + 0xe8) << 2) + (int)self + 0xec)]);
      FUN_0011988c(*(void **)(self + 0xe0), r, 0);
      FUN_00108e6c(100000.0f, *(void **)(self + 0xe0));
      FUN_001090f4(*(void **)(self + 0xe0), -1);
      *(int *)(self + 0x10c) = 0;
    } else {
      *(int *)(self + 0x10c) = 0;
    }
  }
  *(int *)(self + 0x110) = 0;
  *(char *)(self + 0x54) = 0;
  return self;
}
}
