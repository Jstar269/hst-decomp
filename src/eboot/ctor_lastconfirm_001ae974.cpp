/* HSTMATCH module=EBOOT.BIN start=0x001ae974 end=0x001aecf4 symbol=FUN_001ae974 lang=c++ */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode ram-0x001ae974.c as a guide): typed Widget virtuals (slots 5/6), float arguments, the dimmed colour as an inline per-byte Half(); exact match verified; names and types await human review. */
/* Matching idiom: the dimmed colour must be computed from the value READ BACK from the object (Half(page[0x246]) after the 0x80808080 store): the store-forwarded register value is not a compile-time constant, so MWCC keeps retail's ext/srl/sll/or byte chain instead of folding it to 0x80404040. */
struct Widget {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void SetState(int);
  virtual void SetSize(float);
};

extern "C" {
extern char DAT_0030ebf4[];
extern char DAT_002e2140[];
extern char DAT_002e2078[];
extern char DAT_002e20a8[];
extern char DAT_002e20d8[];
extern char DAT_002e2110[];
extern char *DAT_002e1f50[];
extern char *DAT_002e1fe4[];
extern char *DAT_002e2054[];
extern char *DAT_002e2074[];
extern char DAT_002c2f80[], DAT_002c3590[], DAT_002c35f4[], DAT_002c3618[];
extern char DAT_002c363c[], DAT_002c43a4[];
extern char DAT_002c4a18[], DAT_002c57c4[], DAT_002c5974[], DAT_002c5998[];
extern char DAT_002c59bc[], DAT_002c59e0[];
extern int DAT_003386c8;
void FUN_0001cad0(char *, int, char *);
void FUN_0001cb88(char *);
void FUN_00104118(void *, char *, int);
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
void FUN_00216e90(void *, void *, char **, int);
void FUN_00216f14(void *, void *, char *, int);
void FUN_00216fb0(void *, void *, char *, int);
void FUN_0021704c(void *, void *, char *, int);
void FUN_00217188(void *, void *, char *);
void *FUN_0008d994(int);

static inline unsigned Half(unsigned c)
{
  unsigned a = (c >> 24) & 0xff, r = (c >> 16) & 0xff, g = (c >> 8) & 0xff, b = c & 0xff;
  return (a << 24) | ((r >> 1) << 16) | ((g >> 1) << 8) | (b >> 1);
}

#define LASTCONFIRM_COLOR 0x80808080   /* colour word stored in the third page */

/* Object holding the four page objects the constructor fills in. */
struct LastConfirm {
  int unk0;
  unsigned int *page[4];   /* 0x04 */
  int unk14;
  int unk18;
  void *overlay;           /* 0x1c */
};

/* Set up the four pages (layouts, panes, widgets, colours) and the overlay object; returns 1. */
int FUN_001ae974(LastConfirm *self)
{
  unsigned int *page;
  Widget *widget;
  void *overlay;
  FUN_0001cad0(DAT_0030ebf4, 1, DAT_002e2140);
  page = self->page[0];
  FUN_00104118((void *)*page, DAT_002e2078, 0);
  FUN_00103540(4000.0f, (void *)*page);
  FUN_001037c8((void *)*page, -256);
  FUN_00216e90(page + 1, (void *)*page, DAT_002e1f50, 7);
  FUN_00216f14(page + 8, page + 1, DAT_002c2f80, 0x2f);
  FUN_00216fb0(page + 0xf3, page + 1, DAT_002c3590, 3);
  FUN_0021704c(page + 0xfc, page + 1, DAT_002c35f4, 1);
  FUN_00217188(page + 0xff, page + 1, DAT_002c3618);
  widget = (Widget *)page[0xff];
  *(int *)((char *)widget + 0xd8) = 0;
  *(char *)((char *)widget + 0x114) = 1;
  ((Widget *)page[0xff])->SetSize(4100.0f);
  ((Widget *)page[0xff])->SetState(-236);

  page = self->page[1];
  FUN_00104118((void *)*page, DAT_002e20a8, 0);
  FUN_00103540(4000.0f, (void *)*page);
  FUN_001037c8((void *)*page, -256);
  FUN_00216e90(page + 1, (void *)*page, DAT_002e1fe4, 10);
  FUN_00216f14(page + 0xb, page + 1, DAT_002c363c, 0x68);
  FUN_00216fb0(page + 0x213, page + 1, DAT_002c43a4, 0x32);

  page = self->page[2];
  FUN_00104118((void *)*page, DAT_002e20d8, 0);
  FUN_00103540(4010.0f, (void *)*page);
  FUN_001037c8((void *)*page, -246);
  FUN_00216e90(page + 1, (void *)*page, DAT_002e2054, 8);
  FUN_00216f14(page + 9, page + 1, DAT_002c4a18, 0x6a);
  FUN_00216fb0(page + 0x21b, page + 1, DAT_002c57c4, 0xd);
  FUN_0021704c(page + 0x242, page + 1, DAT_002c5974, 1);
  FUN_00217188(page + 0x245, page + 1, DAT_002c5998);
  widget = (Widget *)page[0x245];
  *(int *)((char *)widget + 0xd8) = 0;
  *(char *)((char *)widget + 0x114) = 1;
  ((Widget *)page[0x245])->SetSize(4200.0f);
  ((Widget *)page[0x245])->SetState(-156);
  page[0x246] = LASTCONFIRM_COLOR;
  page[0x247] = Half(page[0x246]);

  page = self->page[3];
  FUN_00104118((void *)*page, DAT_002e2110, 0);
  FUN_00103540(0.0f, (void *)*page);
  FUN_001037c8((void *)*page, 0x10);
  FUN_00216e90(page + 1, (void *)*page, DAT_002e2074, 1);
  FUN_00216f14(page + 2, page + 1, DAT_002c59bc, 1);
  FUN_0021704c(page + 7, page + 1, DAT_002c59e0, 1);
  FUN_0001cb88(DAT_0030ebf4);
  overlay = FUN_0008d994(DAT_003386c8);
  self->overlay = overlay;
  FUN_00103540(2300.0f, overlay);
  return 1;
}
}
