/* HSTMATCH module=EBOOT.BIN start=0x0023c040 end=0x0023c2ac symbol=FUN_0023c040 lang=c++ */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode ram-0x0023c040.c as a guide).
// NEAR MISS: 155/155 words, 19 words differ, all in the final rect block (from +0x218).
// Everything up to the virtual calls matches byte for byte. Retail keeps the source rect in v1,
// the destination in v0 and the gfx pointer only transiently in a0; ours takes v0 for the gfx
// pointer and a3 for the destination. Tried: every declaration/usage order of the three pointer
// locals, float pair order (0x64/0x60 vs 0x60/0x64), the four short locals in pseudocode and in
// 8/4/10/6 order, floats read through a local vs a re-dereferenced expression, destination as
// int* vs byte offsets. All give 19-23 differing words with the same body. Remaining lever is
// the local-vs-temporary register class MWCC picks for the destination pointer. */

struct Item {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5(int);
  virtual void v6(float);
};

struct Gfx {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8(int, int, int, int, int);
};

extern "C" {
extern char DAT_0030ebf4[];
extern void *DAT_0034a6c0;
extern char DAT_002f548c[];
extern char DAT_002f54a0[];
extern char DAT_002f54c8[];
extern char *DAT_002f5468[];
extern char DAT_002c9f9c[];
extern char DAT_002ca16c[];
extern char DAT_002ca424[];
extern char DAT_002ca448[];
extern char DAT_002ca46c[];
extern int DAT_003386c8;
extern int DAT_0034a114;

void FUN_0001cad0(char *, int, char *);
void FUN_0001cb88(char *);
void FUN_002172f4(void *, char *, int);
void FUN_00104118(void *, char *, int);
void FUN_00103540(void *, float);
void FUN_001037c8(void *, int);
void *FUN_0008d994(int);
void *FUN_001cd804(int);
void FUN_00216e90(void *, void *, void *, int);
void FUN_00216f14(void *, void *, void *, int);
void FUN_00216fb0(void *, void *, void *, int);
void FUN_002170ec(void *, void *, void *, int);
void FUN_0021704c(void *, void *, void *, int);
void FUN_00217188(void *, void *, void *);
void FUN_00217294(void *, void *, void *);
void FUN_00103628(void *, int);

int FUN_0023c040(int param_1)
{
  FUN_0001cad0(DAT_0030ebf4, 1, DAT_002f548c);
  FUN_002172f4(&DAT_0034a6c0, DAT_002f54a0, 0xcb);
  FUN_00104118(*(void **)(param_1 + 4), DAT_002f54c8, 0);
  FUN_00103540(*(void **)(param_1 + 4), 2000.0f);
  FUN_001037c8(*(void **)(param_1 + 4), 0x10);
  FUN_0001cb88(DAT_0030ebf4);
  if (DAT_003386c8 != 0) {
    *(void **)(param_1 + 0x1750) = FUN_0008d994(DAT_003386c8);
  } else if (DAT_0034a114 != 0) {
    *(void **)(param_1 + 0x1750) = FUN_001cd804(DAT_0034a114);
  }
  if (*(void **)(param_1 + 0x1750) != 0) {
    FUN_00103540(*(void **)(param_1 + 0x1750), 2300.0f);
  }
  FUN_00216e90((void *)(param_1 + 8), *(void **)(param_1 + 4), DAT_002f5468, 9);
  FUN_00216f14((void *)(param_1 + 0x2c), (void *)(param_1 + 8), DAT_0034a6c0, 0xcb);
  FUN_00216fb0((void *)(param_1 + 0x1008), (void *)(param_1 + 8), DAT_002c9f9c, 0xe);
  FUN_002170ec((void *)(param_1 + 0x10b0), (void *)(param_1 + 8), DAT_002ca16c, 0x15);
  FUN_0021704c((void *)(param_1 + 0x11ac), (void *)(param_1 + 8), DAT_002ca424, 1);
  FUN_00217188((void *)(param_1 + 0x11b8), (void *)(param_1 + 8), DAT_002ca448);
  FUN_00217294((void *)(param_1 + 0x11bc), (void *)(param_1 + 8), DAT_002ca46c);

  Item *it = *(Item **)(param_1 + 0x11b8);
  *(int *)((char *)it + 0xd8) = 0;
  *(char *)((char *)it + 0x114) = 1;
  (*(Item **)(param_1 + 0x11b8))->v6(2300.0f);
  (*(Item **)(param_1 + 0x11b8))->v5(-256);

  short *r = *(short **)(param_1 + 0xe8c);
  (*(Gfx **)(param_1 + 0x20))->v8(0, r[2], r[3], r[4], r[5]);

  int *dst = *(int **)(param_1 + 0x14c0);
  float f60 = *(float *)(*(int *)(param_1 + 0x20) + 0x60);
  float f64 = *(float *)(*(int *)(param_1 + 0x20) + 0x64);
  short *rc = *(short **)(param_1 + 0xdc4);
  short h10 = rc[5];
  short h6 = rc[3];
  short h8 = rc[4];
  short h4 = rc[2];
  dst[3] = 0;
  dst[4] = 0;
  dst[5] = (int)f60;
  dst[6] = (int)f64;
  dst[1] = (short)(h8 - h4);
  dst[2] = (short)(h10 - h6);

  short *rb = *(short **)(param_1 + 0xa04);
  *(int *)(param_1 + 0x174c) = (short)(rb[4] - rb[2]);
  FUN_00103628(*(void **)(param_1 + 4), 0);
  return 1;
}
}
// near miss from lane fm4 (unreviewed)
