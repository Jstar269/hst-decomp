/* HSTMATCH module=EBOOT.BIN start=0x000c3a1c end=0x000c3f0c symbol=FUN_000c3a1c lang=c99 */
/* Pass 3: dump lines 2-290. Continues at the marker. */
extern unsigned char DAT_00338b44[];
extern float DAT_002c01c0, DAT_002c01c4, DAT_002c01c8, DAT_002c01cc;
extern float DAT_002c01d0, DAT_002c01d4, DAT_002c01d8, DAT_002c01dc;
extern float DAT_002c01e0, DAT_002c01e4, DAT_002c01e8, DAT_002c01ec;
extern long long DAT_002c01f0[10];
extern signed char DAT_002c0238, DAT_002c0239;
extern int DAT_002c023c, DAT_002c0240, DAT_002c0244;
extern float DAT_002c0250, DAT_002c0254, DAT_002c0258, DAT_002c025c;
extern float DAT_002c0260, DAT_002c0264, DAT_002c0268, DAT_002c026c;
extern float DAT_002c0270, DAT_002c0274, DAT_002c0278, DAT_002c027c;
extern long long DAT_002c0280[10];
extern signed char DAT_002c02c8, DAT_002c02c9;
extern int DAT_002c02cc, DAT_002c02d0, DAT_002c02d4;
extern float DAT_002c02e0, DAT_002c02e4, DAT_002c02e8, DAT_002c02ec;
extern float DAT_002c02f0, DAT_002c02f4, DAT_002c02f8, DAT_002c02fc;
extern float DAT_002c0300, DAT_002c0304, DAT_002c0308, DAT_002c030c;
extern long long DAT_002c0310[10];
extern signed char DAT_002c0358, DAT_002c0359;
extern int DAT_002c035c, DAT_002c0360, DAT_002c0364;
extern float DAT_002c0370, DAT_002c0374, DAT_002c0378, DAT_002c037c;
extern float DAT_002c0380, DAT_002c0384, DAT_002c0388, DAT_002c038c;
extern float DAT_002c0390, DAT_002c0394, DAT_002c0398, DAT_002c039c;
extern long long DAT_002c03a0[10];
extern signed char DAT_002c03e8, DAT_002c03e9;
extern int DAT_002c03ec, DAT_002c03f0, DAT_002c03f4;
extern void FUN_0004d7dc(void *, int, int);

struct Frame {
  float g[12];        /* 0x00 */
  long long q[9];     /* 0x30 */
  char b0, b1;        /* 0x78 */
  char pad0[2];
  int i0, i1, i2;     /* 0x7c */
  char pad1[8];
  float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11; /* 0x90 */
  long long q2[9];    /* 0xc0 */
  char b2, b3;        /* 0x108 */
  char pad2[2];
  int j0, j1, j2;     /* 0x10c */
};


int FUN_000c3a1c(int a0, int a1, int a2)
{
  struct Frame f;
  int i;
  int s4, s0;
  int p2;
  int q2;
  int idx;
  float t0, t1, t2, t3, tw;

  if (*(unsigned char *)(*(int *)DAT_00338b44 + 69) == 0) goto L2;
  p2 = a1;
  f.g[0] = DAT_002c01c0;
  f.g[1] = DAT_002c01c4;
  f.g[2] = DAT_002c01c8;
  f.g[3] = DAT_002c01cc;
  f.g[4] = DAT_002c01d0;
  f.g[5] = DAT_002c01d4;
  f.g[6] = DAT_002c01d8;
  f.g[7] = DAT_002c01dc;
  f.g[8] = DAT_002c01e0;
  f.g[9] = DAT_002c01e4;
  f.g[10] = DAT_002c01e8;
  f.g[11] = DAT_002c01ec;
  for (i = 0; i < 9; i++) f.q[i] = DAT_002c01f0[i];
  f.b0 = DAT_002c0238;
  f.b1 = DAT_002c0239;
  f.i0 = DAT_002c023c;
  f.i1 = DAT_002c0240;
  f.i2 = DAT_002c0244;
  f.f0 = DAT_002c0250;
  f.f1 = DAT_002c0254;
  f.f2 = DAT_002c0258;
  f.f3 = DAT_002c025c;
  f.f4 = DAT_002c0260;
  f.f5 = DAT_002c0264;
  f.f6 = DAT_002c0268;
  f.f7 = DAT_002c026c;
  f.f8 = DAT_002c0270;
  f.f9 = DAT_002c0274;
  f.f10 = DAT_002c0278;
  f.f11 = DAT_002c027c;
  for (i = 0; i < 9; i++) f.q2[i] = DAT_002c0280[i];
  f.b2 = DAT_002c02c8;
  f.b3 = DAT_002c02c9;
  f.j0 = DAT_002c02cc;
  f.j1 = DAT_002c02d0;
  f.j2 = DAT_002c02d4;
  goto L3;
L2:
  f.g[0] = DAT_002c02e0;
  f.g[1] = DAT_002c02e4;
  f.g[2] = DAT_002c02e8;
  f.g[3] = DAT_002c02ec;
  f.g[4] = DAT_002c02f0;
  f.g[5] = DAT_002c02f4;
  f.g[6] = DAT_002c02f8;
  f.g[7] = DAT_002c02fc;
  f.g[8] = DAT_002c0300;
  f.g[9] = DAT_002c0304;
  f.g[10] = DAT_002c0308;
  f.g[11] = DAT_002c030c;
  for (i = 0; i < 9; i++) f.q[i] = DAT_002c0310[i];
  f.b0 = DAT_002c0358;
  f.b1 = DAT_002c0359;
  f.i0 = DAT_002c035c;
  f.i1 = DAT_002c0360;
  f.i2 = DAT_002c0364;
  f.f0 = DAT_002c0370;
  f.f1 = DAT_002c0374;
  f.f2 = DAT_002c0378;
  f.f3 = DAT_002c037c;
  f.f4 = DAT_002c0380;
  f.f5 = DAT_002c0384;
  f.f6 = DAT_002c0388;
  f.f7 = DAT_002c038c;
  f.f8 = DAT_002c0390;
  f.f9 = DAT_002c0394;
  f.f10 = DAT_002c0398;
  f.f11 = DAT_002c039c;
  for (i = 0; i < 9; i++) f.q2[i] = DAT_002c03a0[i];
  f.b2 = DAT_002c03e8;
  f.b3 = DAT_002c03e9;
  f.j0 = DAT_002c03ec;
  f.j1 = DAT_002c03f0;
  f.j2 = DAT_002c03f4;
L3:
  q2 = a2;
  {
    char *bp = (char *)&f;
    for (idx = 0; idx < 2; idx++) {
      s4 = 0;
      do {
        FUN_0004d7dc(bp, p2, q2);
        t0 = *(float *)(bp + 16);
        t1 = *(float *)(bp + 20);
        t2 = *(float *)(bp + 24);
        t3 = *(float *)(bp + 28);
        tw = *(float *)(bp + 32);
        s4++;
        *(float *)(bp + 16) = tw;
        tw = *(float *)(bp + 36);
        *(float *)(bp + 20) = tw;
        tw = *(float *)(bp + 40);
        *(float *)(bp + 24) = tw;
        tw = *(float *)(bp + 44);
        *(float *)(bp + 28) = tw;
        *(float *)(bp + 32) = t0;
        *(float *)(bp + 36) = t1;
        *(float *)(bp + 40) = t2;
        *(float *)(bp + 44) = t3;
      } while (s4 < 2);
      bp += 144;
    }
  }
  {
    float e = *(float *)(p2 + 48);
    if (e == 3.402823466e+38f) {
      return 0;
    }
    *(int *)(p2 + 56) = 26;
  }
  return 1;
}

// near miss from lane dsn3 (unreviewed)
