/* HSTMATCH module=EBOOT.BIN start=0x00219fa0 end=0x0021a370 symbol=FUN_00219fa0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
extern char DAT_003095e8[];
extern char DAT_002eff58[];
extern float DAT_002efb3c;
extern char *DAT_002efb70[];
extern Entry DAT_002efdac[];
extern float DAT_002eff20, DAT_002eff24, DAT_002eff28, DAT_002eff2c, DAT_002eff30, DAT_002eff34, DAT_002eff38;
extern float DAT_002eff3c, DAT_002eff40, DAT_002eff44, DAT_002eff48, DAT_002eff4c, DAT_002eff50, DAT_002eff54;
extern int DAT_002efeb0;
extern int DAT_002efb40[];
void FUN_00102e38(void *);
void FUN_00104118(void *, char *, int);
void FUN_00103540(float, void *);
Widget *FUN_001039d8(void *, char *, int);
void *FUN_001026b8(void *, char *);
void FUN_000ffc3c(void *, int);
void FUN_000ffb3c(void *, int);
int FUN_001c7158();
void FUN_00102c54(void *);
void FUN_0010b8cc(void *, int, int);
void FUN_00022498(float, void *, void *);
void *FUN_00000bcc(int);
void *FUN_001108fc(void *);
int FUN_001fea10(int, int, int);
void FUN_00110a78(void *, int, int);
void FUN_001037c8(void *, int);

char *FUN_00219fa0(char *self)
{
  float a[7];
  float b[7];

  FUN_00102e38(self);
  *(char **)self = DAT_003095e8;
  *(int *)(self + 0xe0) = 0;
  FUN_00104118(self, DAT_002eff58, 1);
  FUN_00103540(DAT_002efb3c, self);
  {
    int i = 0;
    char **names = DAT_002efb70;
    int off = 0;
    do {
      (*(Widget **)(self + off + 0x58) = FUN_001039d8(self, *names, 0))->SetState(-3);
      i++;
      names++;
      off += 4;
    } while (i < 3);
  }
  {
    int j = 0;
    Entry *e = DAT_002efdac;
    int off = 0;
    do {
      void *h = FUN_001026b8(*(void **)(self + e->idx * 4 + 0x58), e->name);
      *(void **)(self + off + 100) = h;
      FUN_000ffc3c(h, -256);
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
      FUN_000ffb3c(*(void **)(self + off + 100), 1);
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
  a[0] = DAT_002eff20;
  a[1] = DAT_002eff24;
  a[2] = DAT_002eff28;
  a[3] = DAT_002eff2c;
  a[4] = DAT_002eff30;
  a[5] = DAT_002eff34;
  a[6] = DAT_002eff38;
  off = 0;
  b[0] = DAT_002eff3c;
  b[1] = DAT_002eff40;
  b[2] = DAT_002eff44;
  b[3] = DAT_002eff48;
  b[4] = DAT_002eff4c;
  b[5] = DAT_002eff50;
  b[6] = DAT_002eff54;
  do {
    int v;
    if (FUN_001c7158() != 0) {
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
  *(int *)(self + 0x108) = FUN_001c7158() != 0 ? 6 : 5;
  {
    int t = DAT_002efeb0 + (unsigned char)((FUN_001c7158() != 0) ^ 1);
    Model *m = *(Model **)(self + 0xb8);
    m->f24 = t;
    m->f28 = t;
  }
  (*(Panel **)(self + 0x58))->f60 = 8.0f;
  FUN_00102c54(*(void **)(self + 0x58));
  (*(Panel **)(self + 0x60))->f60 = 8.0f;
  FUN_00102c54(*(void **)(self + 0x60));
  {
    char *obj = *(char **)(*(char **)(self + 0xbc) + 0x20);
    *(char **)(self + 0xe4) = obj;
    *(int *)(obj + 0xd8) = 0;
    *(char *)(obj + 0x114) = 1;
    FUN_0010b8cc(*(void **)(self + 0xe4), *(int *)(self + 0xe8), 2);
    FUN_00022498(0.8f, *(char **)(self + 0xe4) + 0x30, *(char **)(self + 0xe4) + 0x30);
    FUN_00022498(0.8f, *(char **)(self + 0xe4) + 0x40, *(char **)(self + 0xe4) + 0x40);
    (*(Panel **)(self + 0xe4))->f60 = 32.0f;
    (*(Panel **)(self + 0xe4))->f64 = 33.0f;
    (*(Widget **)(self + 0xe4))->SetState(-2);
    FUN_00102c54(*(void **)(self + 0xe4));
  }
  {
    void *p = FUN_00000bcc(0x7c);
    if (p != 0) {
      p = FUN_001108fc(p);
    }
    *(void **)(self + 0xe0) = p;
    if (p != 0) {
      int r = FUN_001fea10(0x12, 0x21, DAT_002efb40[*(int *)((*(int *)(self + 0xe8) << 2) + (int)self + 0xec)]);
      FUN_00110a78(*(void **)(self + 0xe0), r, 0);
      FUN_00103540(100000.0f, *(void **)(self + 0xe0));
      FUN_001037c8(*(void **)(self + 0xe0), -1);
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
