/* HSTMATCH module=EBOOT.BIN start=0x00219fa0 end=0x0021a370 symbol=FUN_00219fa0 lang=c++ data=0x002eff58 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002eff58-0x002eff88) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern char DAT_003095e8[];
extern float DAT_002efb3c;
extern char *DAT_002efb70[];
extern ElemSpec DAT_002efdac[];
extern float DAT_002eff20, DAT_002eff24, DAT_002eff28, DAT_002eff2c, DAT_002eff30, DAT_002eff34, DAT_002eff38;
extern float DAT_002eff3c, DAT_002eff40, DAT_002eff44, DAT_002eff48, DAT_002eff4c, DAT_002eff50, DAT_002eff54;
extern int DAT_002efeb0;
extern int DAT_002efb40[];
void FUN_00102e38(void *);
void FUN_00104118(void *, char *, int);
void FUN_00103540(float, void *);
Widget *FUN_001039d8(void *, char *, int);
Elem *FUN_001026b8(void *, char *);
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

/* self is a char pointer so the table loops keep their byte-offset arithmetic; `pane` is the typed view. */
char *FUN_00219fa0(char *self)
{
  LobbyInPane *pane = (LobbyInPane *)self;
  float a[7];
  float b[7];

  FUN_00102e38(self);
  pane->vtable = DAT_003095e8;
  pane->unke0 = 0;
  FUN_00104118(self, "data/menu/lobby/lobbyinpane/commandlayouter.lay", 1);
  FUN_00103540(DAT_002efb3c, self);
  /* Create the three panes from the layout file. */
  {
    int i = 0;
    char **names = DAT_002efb70;
    int off = 0;
    do {
      (*(Widget **)(self + off + PANES_OFF) = FUN_001039d8(self, *names, 0))->SetState(-3);
      i++;
      names++;
      off += 4;
    } while (i < PANE_COUNT);
  }
  /* Look up every named element and remember the value each one reports. */
  {
    int j = 0;
    ElemSpec *e = DAT_002efdac;
    int off = 0;
    do {
      Elem *h = FUN_001026b8(pane->panes[e->pane], e->name);
      *(Elem **)(self + off + ELEMS_OFF) = h;
      FUN_000ffc3c(h, -256);
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
      FUN_000ffb3c(*(Elem **)(self + off + ELEMS_OFF), 1);
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
    *(int *)(self + off + OPTIONS_OFF) = v;
    i++;
    pb++;
    pa++;
    off += 4;
  } while (i < OPTION_COUNT);
  pane->unk108 = FUN_001c7158() != 0 ? 6 : 5;
  {
    int t = DAT_002efeb0 + (unsigned char)((FUN_001c7158() != 0) ^ 1);
    Elem *m = pane->elems[21];
    m->unk24 = t;
    m->unk28 = t;
  }
  pane->panes[0]->x = 8.0f;
  FUN_00102c54(pane->panes[0]);
  pane->panes[2]->x = 8.0f;
  FUN_00102c54(pane->panes[2]);
  {
    Widget *w = pane->elems[22]->widget;
    pane->cursor = w;
    w->unkd8 = 0;
    w->unk114 = 1;
    FUN_0010b8cc(pane->cursor, pane->selected, 2);
    FUN_00022498(0.8f, pane->cursor->vecA, pane->cursor->vecA);
    FUN_00022498(0.8f, pane->cursor->vecB, pane->cursor->vecB);
    pane->cursor->x = 32.0f;
    pane->cursor->y = 33.0f;
    pane->cursor->SetState(-2);
    FUN_00102c54(pane->cursor);
  }
  {
    void *p = FUN_00000bcc(0x7c);
    if (p != 0) {
      p = FUN_001108fc(p);
    }
    pane->unke0 = p;
    if (p != 0) {
      int r = FUN_001fea10(0x12, 0x21, DAT_002efb40[pane->options[pane->selected]]);
      FUN_00110a78(pane->unke0, r, 0);
      FUN_00103540(100000.0f, pane->unke0);
      FUN_001037c8(pane->unke0, -1);
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
