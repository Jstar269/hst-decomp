/* HSTMATCH module=EBOOT.BIN start=0x00258294 end=0x002584d0 symbol=FUN_00258294 lang=c99 */
typedef unsigned char u8;

extern u8 DAT_003417b8[];
extern void FUN_0025418c(void *, int);
extern int FUN_00258608(void *, int, int);
extern void FUN_002584d0(int, short *, short *, short *, short *);
extern void FUN_0005bbd4(int, float, float, float, float, float, float);
extern void FUN_0005bc58(int, float, float, float, float, float, float);

void FUN_00258294(int param_1)
{
  u8 *pu;
  int i;
  int n;
  int base;
  int idx;
  short y2;
  short x2;
  short y1;
  short x1;
  float fx;
  float fy;
  float fw;
  float fh;

  i = 0;
  pu = DAT_003417b8;
  base = param_1;
  while (i < (*(u8 *)(param_1 + 0x644) == 0 ? 4 : 2)) {
    pu[0xe0] = 0;
    pu[0xe3] = 0;
    pu[0xe1] = 0;
    pu[0x105] = 0;
    pu[0x106] = 0;
    pu[0x107] = 0;
    pu[0x108] = 0;
    *(int *)(pu + 0x10c) = -1;
    *(int *)(pu + 0x110) = -1;
    *(float *)(pu + 0x114) = 5.0f;
    pu[0x118] = 10;
    pu[0x119] = 0;
    *(int *)(pu + 0x11c) = 0;
    pu[0xe4] = 0xe3;
    pu[0xe5] = 0x81;
    pu[0xe6] = 0xbf;
    pu[0xe7] = 0xe3;
    pu[0xe8] = 0x82;
    pu[0xe9] = 0x93;
    pu[0xea] = 0xe3;
    pu[0xeb] = 0x83;
    pu[0xec] = 0x86;
    pu[0xed] = 0xe3;
    pu[0xee] = 0x83;
    pu[0xef] = 0x8b;
    pu[0xf0] = 0x50;
    ((u8 *)base)[0x7f8] = 0;
    ((u8 *)base)[0x7fb] = 0;
    ((u8 *)base)[0x7f9] = 0;
    ((u8 *)base)[0x81d] = 0;
    ((u8 *)base)[0x81e] = 0;
    ((u8 *)base)[0x81f] = 0;
    ((u8 *)base)[0x820] = 0;
    *(int *)((u8 *)base + 0x824) = -1;
    *(int *)((u8 *)base + 0x828) = -1;
    *(float *)((u8 *)base + 0x82c) = 5.0f;
    ((u8 *)base)[0x830] = 10;
    ((u8 *)base)[0x831] = 0;
    *(int *)((u8 *)base + 0x834) = 0;
    ((u8 *)base)[0x7fc] = 0xe3;
    ((u8 *)base)[0x7fd] = 0x81;
    ((u8 *)base)[0x7fe] = 0xbf;
    ((u8 *)base)[0x7ff] = 0xe3;
    ((u8 *)base)[0x800] = 0x82;
    ((u8 *)base)[0x801] = 0x93;
    ((u8 *)base)[0x802] = 0xe3;
    ((u8 *)base)[0x803] = 0x83;
    ((u8 *)base)[0x804] = 0x86;
    ((u8 *)base)[0x805] = 0xe3;
    ((u8 *)base)[0x806] = 0x83;
    ((u8 *)base)[0x807] = 0x8b;
    ((u8 *)base)[0x808] = 0x50;
    pu = pu + 0x120;
    base = base + 0x458;
    i = i + 1;
  }
  FUN_0025418c((void *)(param_1 + 0x60),
               *(u8 *)(param_1 + 0x644) == 0 ? 4 : 2);
  i = 0;
  idx = param_1;
  while (i < (*(u8 *)(param_1 + 0x644) == 0 ? 4 : 2)) {
    n = FUN_00258608((void *)(param_1 + 0x270), i, 9);
    FUN_002584d0(n, &x1, &y1, &x2, &y2);
    fx = (float)x1;
    fy = (float)y1;
    fw = (float)x2 - fx;
    fh = (float)y2 - fy;
    FUN_0005bbd4(*(int *)(idx + 0xc0), fx, fy, fw, fh, fx + fw / 2.0f,
                 fy + fh / 2.0f);
    FUN_0005bc58(*(int *)(idx + 0xc0), fx, fy, fw, fh, fx + fw / 2.0f,
                 fy + fh / 2.0f);
    idx = idx + 4;
    i = i + 1;
  }
}

// NEAR MISS (first attempt): 170/143 words. The structure is understood (two while loops, the first
// clearing/initialising two parallel sprite blocks - a global at DAT_003417b8 with stride 0x120 and a
// per-instance block at param_1 + i*0x458 with the same field layout at +0x7f8 - the second filling
// rect floats f12..f17 from four shorts and calling FUN_0005bbd4/FUN_0005bc58), but this spelling
// costs 27 extra words: the four shorts and the six float temps are not yet allocated like retail
// (retail keeps the four shorts at sp+24..30 and computes the half-extents in f14/f15/f16/f17).
// near miss from lane fm4 (unreviewed)
