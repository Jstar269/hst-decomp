/* HSTMATCH module=EBOOT.BIN start=0x001ae974 end=0x001aecf4 symbol=FUN_001ae974 lang=c++ */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode ram-0x001ae974.c as a guide): typed Widget virtuals (slots 5/6), float arguments, the dimmed colour as an inline per-byte Half(); exact match verified; names and types await human review. */
/* Matching idiom: the dimmed colour must be computed from the value READ BACK from the object (Half(puVar3[0x246]) after the 0x80808080 store): the store-forwarded register value is not a compile-time constant, so MWCC keeps retail's ext/srl/sll/or byte chain instead of folding it to 0x80404040. */
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

int FUN_001ae974(int *param_1)
{
  unsigned int *puVar3;
  Widget *w;
  void *uVar1;
  FUN_0001cad0(DAT_0030ebf4, 1, DAT_002e2140);
  puVar3 = *(unsigned int **)((char *)param_1 + 4);
  FUN_00104118((void *)*puVar3, DAT_002e2078, 0);
  FUN_00103540(4000.0f, (void *)*puVar3);
  FUN_001037c8((void *)*puVar3, -256);
  FUN_00216e90(puVar3 + 1, (void *)*puVar3, DAT_002e1f50, 7);
  FUN_00216f14(puVar3 + 8, puVar3 + 1, DAT_002c2f80, 0x2f);
  FUN_00216fb0(puVar3 + 0xf3, puVar3 + 1, DAT_002c3590, 3);
  FUN_0021704c(puVar3 + 0xfc, puVar3 + 1, DAT_002c35f4, 1);
  FUN_00217188(puVar3 + 0xff, puVar3 + 1, DAT_002c3618);
  w = (Widget *)puVar3[0xff];
  *(int *)((char *)w + 0xd8) = 0;
  *(char *)((char *)w + 0x114) = 1;
  ((Widget *)puVar3[0xff])->SetSize(4100.0f);
  ((Widget *)puVar3[0xff])->SetState(-236);

  puVar3 = *(unsigned int **)((char *)param_1 + 8);
  FUN_00104118((void *)*puVar3, DAT_002e20a8, 0);
  FUN_00103540(4000.0f, (void *)*puVar3);
  FUN_001037c8((void *)*puVar3, -256);
  FUN_00216e90(puVar3 + 1, (void *)*puVar3, DAT_002e1fe4, 10);
  FUN_00216f14(puVar3 + 0xb, puVar3 + 1, DAT_002c363c, 0x68);
  FUN_00216fb0(puVar3 + 0x213, puVar3 + 1, DAT_002c43a4, 0x32);

  puVar3 = *(unsigned int **)((char *)param_1 + 0xc);
  FUN_00104118((void *)*puVar3, DAT_002e20d8, 0);
  FUN_00103540(4010.0f, (void *)*puVar3);
  FUN_001037c8((void *)*puVar3, -246);
  FUN_00216e90(puVar3 + 1, (void *)*puVar3, DAT_002e2054, 8);
  FUN_00216f14(puVar3 + 9, puVar3 + 1, DAT_002c4a18, 0x6a);
  FUN_00216fb0(puVar3 + 0x21b, puVar3 + 1, DAT_002c57c4, 0xd);
  FUN_0021704c(puVar3 + 0x242, puVar3 + 1, DAT_002c5974, 1);
  FUN_00217188(puVar3 + 0x245, puVar3 + 1, DAT_002c5998);
  w = (Widget *)puVar3[0x245];
  *(int *)((char *)w + 0xd8) = 0;
  *(char *)((char *)w + 0x114) = 1;
  ((Widget *)puVar3[0x245])->SetSize(4200.0f);
  ((Widget *)puVar3[0x245])->SetState(-156);
  puVar3[0x246] = 0x80808080;
  puVar3[0x247] = Half(puVar3[0x246]);

  puVar3 = *(unsigned int **)((char *)param_1 + 0x10);
  FUN_00104118((void *)*puVar3, DAT_002e2110, 0);
  FUN_00103540(0.0f, (void *)*puVar3);
  FUN_001037c8((void *)*puVar3, 0x10);
  FUN_00216e90(puVar3 + 1, (void *)*puVar3, DAT_002e2074, 1);
  FUN_00216f14(puVar3 + 2, puVar3 + 1, DAT_002c59bc, 1);
  FUN_0021704c(puVar3 + 7, puVar3 + 1, DAT_002c59e0, 1);
  FUN_0001cb88(DAT_0030ebf4);
  uVar1 = FUN_0008d994(DAT_003386c8);
  *(void **)((char *)param_1 + 0x1c) = uVar1;
  FUN_00103540(2300.0f, uVar1);
  return 1;
}
}
