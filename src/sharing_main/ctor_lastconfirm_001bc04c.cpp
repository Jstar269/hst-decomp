/* HSTMATCH module=hstp_trans_main.prx start=0x001bc04c end=0x001bc3cc symbol=FUN_001bc04c lang=c++ */
/* Clone of src/eboot/ctor_lastconfirm_001ae974.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode ram-0x001bc04c.c as a guide): typed Widget virtuals (slots 5/6), float arguments, the dimmed colour as an inline per-byte Half(); exact match verified; names and types await human review. */
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
extern char DAT_003b7ebc[];
extern char DAT_00389a70[];
extern char DAT_00389948[];
extern char DAT_00389978[];
extern char DAT_00389a08[];
extern char DAT_00389a40[];
extern char *DAT_00389820[];
extern char *DAT_003898b4[];
extern char *DAT_00389924[];
extern char *DAT_00389944[];
extern char DAT_002d3490[], DAT_002d3aa0[], DAT_002d3b04[], DAT_002d3b28[];
extern char DAT_002d3b4c[], DAT_002d48b4[];
extern char DAT_002d4f28[], DAT_002d5cd4[], DAT_002d5e84[], DAT_002d5ea8[];
extern char DAT_002d5ecc[], DAT_002d5ef0[];
extern int DAT_003e1a08;
void FUN_0001c684(char *, int, char *);
void FUN_0001c73c(char *);
void FUN_00109a44(void *, char *, int);
void FUN_00108e6c(float, void *);
void FUN_001090f4(void *, int);
void FUN_00225e94(void *, void *, char **, int);
void FUN_00225f18(void *, void *, char *, int);
void FUN_00225fb4(void *, void *, char *, int);
void FUN_00226050(void *, void *, char *, int);
void FUN_0022618c(void *, void *, char *);
void *FUN_0008f170(int);

static inline unsigned Half(unsigned c)
{
  unsigned a = (c >> 24) & 0xff, r = (c >> 16) & 0xff, g = (c >> 8) & 0xff, b = c & 0xff;
  return (a << 24) | ((r >> 1) << 16) | ((g >> 1) << 8) | (b >> 1);
}

int FUN_001bc04c(int *param_1)
{
  unsigned int *puVar3;
  Widget *w;
  void *uVar1;
  FUN_0001c684(DAT_003b7ebc, 1, DAT_00389a70);
  puVar3 = *(unsigned int **)((char *)param_1 + 4);
  FUN_00109a44((void *)*puVar3, DAT_00389948, 0);
  FUN_00108e6c(4000.0f, (void *)*puVar3);
  FUN_001090f4((void *)*puVar3, -256);
  FUN_00225e94(puVar3 + 1, (void *)*puVar3, DAT_00389820, 7);
  FUN_00225f18(puVar3 + 8, puVar3 + 1, DAT_002d3490, 0x2f);
  FUN_00225fb4(puVar3 + 0xf3, puVar3 + 1, DAT_002d3aa0, 3);
  FUN_00226050(puVar3 + 0xfc, puVar3 + 1, DAT_002d3b04, 1);
  FUN_0022618c(puVar3 + 0xff, puVar3 + 1, DAT_002d3b28);
  w = (Widget *)puVar3[0xff];
  *(int *)((char *)w + 0xd8) = 0;
  *(char *)((char *)w + 0x114) = 1;
  ((Widget *)puVar3[0xff])->SetSize(4100.0f);
  ((Widget *)puVar3[0xff])->SetState(-236);

  puVar3 = *(unsigned int **)((char *)param_1 + 8);
  FUN_00109a44((void *)*puVar3, DAT_00389978, 0);
  FUN_00108e6c(4000.0f, (void *)*puVar3);
  FUN_001090f4((void *)*puVar3, -256);
  FUN_00225e94(puVar3 + 1, (void *)*puVar3, DAT_003898b4, 10);
  FUN_00225f18(puVar3 + 0xb, puVar3 + 1, DAT_002d3b4c, 0x68);
  FUN_00225fb4(puVar3 + 0x213, puVar3 + 1, DAT_002d48b4, 0x32);

  puVar3 = *(unsigned int **)((char *)param_1 + 0xc);
  FUN_00109a44((void *)*puVar3, DAT_00389a08, 0);
  FUN_00108e6c(4010.0f, (void *)*puVar3);
  FUN_001090f4((void *)*puVar3, -246);
  FUN_00225e94(puVar3 + 1, (void *)*puVar3, DAT_00389924, 8);
  FUN_00225f18(puVar3 + 9, puVar3 + 1, DAT_002d4f28, 0x6a);
  FUN_00225fb4(puVar3 + 0x21b, puVar3 + 1, DAT_002d5cd4, 0xd);
  FUN_00226050(puVar3 + 0x242, puVar3 + 1, DAT_002d5e84, 1);
  FUN_0022618c(puVar3 + 0x245, puVar3 + 1, DAT_002d5ea8);
  w = (Widget *)puVar3[0x245];
  *(int *)((char *)w + 0xd8) = 0;
  *(char *)((char *)w + 0x114) = 1;
  ((Widget *)puVar3[0x245])->SetSize(4200.0f);
  ((Widget *)puVar3[0x245])->SetState(-156);
  puVar3[0x246] = 0x80808080;
  puVar3[0x247] = Half(puVar3[0x246]);

  puVar3 = *(unsigned int **)((char *)param_1 + 0x10);
  FUN_00109a44((void *)*puVar3, DAT_00389a40, 0);
  FUN_00108e6c(0.0f, (void *)*puVar3);
  FUN_001090f4((void *)*puVar3, 0x10);
  FUN_00225e94(puVar3 + 1, (void *)*puVar3, DAT_00389944, 1);
  FUN_00225f18(puVar3 + 2, puVar3 + 1, DAT_002d5ecc, 1);
  FUN_00226050(puVar3 + 7, puVar3 + 1, DAT_002d5ef0, 1);
  FUN_0001c73c(DAT_003b7ebc);
  uVar1 = FUN_0008f170(DAT_003e1a08);
  *(void **)((char *)param_1 + 0x1c) = uVar1;
  FUN_00108e6c(2300.0f, uVar1);
  return 1;
}
}
