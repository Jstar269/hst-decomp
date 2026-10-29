/* HSTMATCH module=hstp_trans_main.prx start=0x002294b8 end=0x00229888 symbol=FUN_002294b8 lang=c++ data=0x00398324 */
/* Hand-written reconstruction (port of src/eboot/ctor_lobby_inpane_00219fa0.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00398324-0x00398354) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Lobby in-pane layout constructor (siblings: ctor_parts_lobby_0021d02c.c). Matching idioms: byte-offset induction variables per table loop (counter, table pointer, offset), the virtual call made on the stored element (w = (slot = lookup())->SetState(-3)), two local float[7] tables copied from consecutive globals with the pointer/counter initialisations placed around the copies (statement positions steer the $f0/$f1 allocation), selects written with != 0 so the likely branch lands as in retail. */
/* Layout element object (a polymorphic widget; only the used fields are named). */
struct Widget {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void SetState(int);
  char pad04[0x30 - 4];
  float vecA[4];            /* 0x30 */
  float vecB[4];            /* 0x40 */
  char pad50[0x10];
  float x;                  /* 0x60 */
  float y;                  /* 0x64 */
  char pad68[0xd8 - 0x68];
  int unkd8;                /* 0xd8 */
  char padDC[0x114 - 0xdc];
  char unk114;              /* 0x114 */
};
/* Named layout element: lookup handle into the layout file. */
struct Elem {
  char pad00[0x20];
  Widget *widget;           /* 0x20 */
  int unk24;                /* 0x24 */
  int unk28;                /* 0x28 */
};
/* One row of the element table: which pane to search, the element name, and the value read back. */
struct ElemSpec {
  int pane;
  char *name;
  int result;
};
enum {
  ELEM_COUNT = 31,
  PANE_COUNT = 3,
  OPTION_COUNT = 7,
  /* Byte offsets of the tables the loops walk with byte-offset induction variables (see LobbyInPane). */
  PANES_OFF = 0x58,
  ELEMS_OFF = 0x64,
  OPTIONS_OFF = 0xec
};
struct LobbyInPane {
  char *vtable;             /* 0x00 */
  char pad04[0x50];
  char unk54;               /* 0x54 */
  Widget *panes[3];         /* 0x58 */
  Elem *elems[31];          /* 0x64 */
  void *unke0;              /* 0xe0 */
  Widget *cursor;           /* 0xe4 */
  int selected;             /* 0xe8 index into options */
  int options[7];           /* 0xec */
  int unk108;               /* 0x108 */
  int unk10c;               /* 0x10c */
  int unk110;               /* 0x110 */
};

extern "C" {
extern char DAT_003b28b4[];
extern float DAT_00397f08;
extern char *DAT_00397f3c[];
extern ElemSpec DAT_00398178[];
extern float DAT_003982ec, DAT_003982f0, DAT_003982f4, DAT_003982f8, DAT_003982fc, DAT_00398300, DAT_00398304;
extern float DAT_00398308, DAT_0039830c, DAT_00398310, DAT_00398314, DAT_00398318, DAT_0039831c, DAT_00398320;
extern int DAT_0039827c;
extern int DAT_00397f0c[];
void FUN_0010873c(void *);
void FUN_00109a44(void *, char *, int);
void FUN_00108e6c(float, void *);
Widget *FUN_00109304(void *, char *, int);
Elem *FUN_00108124(void *, char *);
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

/* self is a char pointer so the table loops keep their byte-offset arithmetic; `pane` is the typed view. */
char *FUN_002294b8(char *self)
{
  LobbyInPane *pane = (LobbyInPane *)self;
  float a[7];
  float b[7];

  FUN_0010873c(self);
  pane->vtable = DAT_003b28b4;
  pane->unke0 = 0;
  FUN_00109a44(self, "data/menu/lobby/lobbyinpane/commandlayouter.lay", 1);
  FUN_00108e6c(DAT_00397f08, self);
  /* Create the three panes from the layout file. */
  {
    int i = 0;
    char **names = DAT_00397f3c;
    int off = 0;
    do {
      (*(Widget **)(self + off + PANES_OFF) = FUN_00109304(self, *names, 0))->SetState(-3);
      i++;
      names++;
      off += 4;
    } while (i < PANE_COUNT);
  }
  /* Look up every named element and remember the value each one reports. */
  {
    int j = 0;
    ElemSpec *e = DAT_00398178;
    int off = 0;
    do {
      Elem *h = FUN_00108124(pane->panes[e->pane], e->name);
      *(Elem **)(self + off + ELEMS_OFF) = h;
      FUN_00105570(h, -256);
      int r = (*(Elem **)((unsigned int)self + off + ELEMS_OFF))->unk24;
      j++;
      off += 4;
      e->result = r;
      e++;
    } while (j < ELEM_COUNT);
  }
  {
    int j = 7;
    int off = 0x1c;
    do {
      FUN_00105470(*(Elem **)(self + off + ELEMS_OFF), 1);
      j++;
      off += 4;
    } while (j <= 13);
  }
  pane->selected = 0;
  /* Pick one of two 7-entry option tables (copied through float registers). */
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
    *(int *)(self + off + OPTIONS_OFF) = v;
    i++;
    pb++;
    pa++;
    off += 4;
  } while (i < OPTION_COUNT);
  pane->unk108 = FUN_001d5580() != 0 ? 6 : 5;
  {
    int t = DAT_0039827c + (unsigned char)((FUN_001d5580() != 0) ^ 1);
    Elem *m = pane->elems[21];
    m->unk24 = t;
    m->unk28 = t;
  }
  pane->panes[0]->x = 8.0f;
  FUN_00108558(pane->panes[0]);
  pane->panes[2]->x = 8.0f;
  FUN_00108558(pane->panes[2]);
  {
    Widget *w = pane->elems[22]->widget;
    pane->cursor = w;
    w->unkd8 = 0;
    w->unk114 = 1;
    FUN_00111aa4(pane->cursor, pane->selected, 2);
    FUN_000224c0(0.8f, pane->cursor->vecA, pane->cursor->vecA);
    FUN_000224c0(0.8f, pane->cursor->vecB, pane->cursor->vecB);
    pane->cursor->x = 32.0f;
    pane->cursor->y = 33.0f;
    pane->cursor->SetState(-2);
    FUN_00108558(pane->cursor);
  }
  {
    void *p = FUN_00000bcc(0x7c);
    if (p != 0) {
      p = FUN_001196d8(p);
    }
    pane->unke0 = p;
    if (p != 0) {
      int r = FUN_0020d1e0(0x12, 0x21, DAT_00397f0c[pane->options[pane->selected]]);
      FUN_0011988c(pane->unke0, r, 0);
      FUN_00108e6c(100000.0f, pane->unke0);
      FUN_001090f4(pane->unke0, -1);
      pane->unk10c = 0;
    } else {
      pane->unk10c = 0;
    }
  }
  pane->unk110 = 0;
  pane->unk54 = 0;
  return self;
}
}
