/* HSTMATCH module=EBOOT.BIN start=0x002a761c end=0x002a796c symbol=FUN_002a761c lang=c++ */
extern "C" int FUN_002af274(int *);
extern "C" int *FUN_002af27c(int *, int);
extern "C" int FUN_001fea10(int, int, int);
extern "C" void FUN_00143b0(char *, int, ...);
extern "C" char *strcpy(char *, const char *);
extern "C" void FUN_000ffb3c(int *, int);
extern "C" int FUN_002af26c(int *, int *);
extern "C" int FUN_00020f5c(int, float);
extern "C" void FUN_002a51ec(int *, char *, char *);
extern "C" void FUN_0010d4a8(void *);
typedef int S;
extern "C" void FUN_002a761c(S *self)
{
  int *gbase = (int *)(*(int *)0x003415a8 + 0x87128);
  int count;
  int *p;
  if (FUN_002af274(gbase) <= 0) return;
  p = FUN_002af27c((int *)(*(int *)0x003415a8 + 0x87128), self[0x1668/4] + self[0x166c/4]);
  FUN_00143b0((char *)self + 0xf61, FUN_001fea10(19, 13, 2), p[34], p[35]);
  float fv = *(float *)((char *)p + 0x30);
  FUN_00143b0((char *)self + 0xfe1, FUN_001fea10(19, 13, 3), p[36]);
  FUN_00143b0((char *)self + 0x1061, FUN_001fea10(19, 13, 2), p[37], p[38]);
  strcpy((char *)self + 0x10e1, (const char *)FUN_001fea10(14, 1, p[39]));
  FUN_00143b0((char *)self + 0x1161, FUN_001fea10(19, 13, 0), (int)(100.0f * *(float *)(p + 40)));
  FUN_00143b0((char *)self + 0x11e1, FUN_001fea10(19, 13, 0), (int)(100.0f * *(float *)(p + 41)));
  int s4 = p[42], s5 = p[43], s3 = s5 % 10;
  strcpy((char *)self + 0x1261, (const char *)FUN_001fea10(12, 0, s4));
  strcpy((char *)self + 0x12e1, (const char *)FUN_001fea10(13, 1, s5));
  int *q = (int *)self[0x1f8/4];
  int v = *(int *)0x003019e0 + s4;
  q[9] = v; q[10] = v;
  q = (int *)self[0x1fc/4];
  if (s5 == 0) {
    FUN_000ffb3c(q, 1);
  } else if (s5 == 500) {
    FUN_000ffb3c(q, 1);
  } else {
    FUN_000ffb3c(q, 0);
    int w = *(int *)0x003019ec + 2 - s3;
    q[9] = w; q[10] = w;
  }
  strcpy((char *)self + 0x1361, (const char *)FUN_001fea10(13, 1, s5));
  int r = FUN_002af26c(p, p + 6);
  int t = FUN_00020f5c(r, fv);
  FUN_00143b0((char *)self + 0x13e1, FUN_001fea10(19, 13, 1), r, t);
  q = (int *)self[0x270/4];
  v = *(int *)0x00301b48 + t;
  q[9] = v; q[10] = v;
  FUN_00143b0((char *)self + 0x1461, FUN_001fea10(19, 13, 1), p[13]);
  FUN_00143b0((char *)self + 0x14e1, FUN_001fea10(19, 13, 1), p[14]);
  FUN_002a51ec(p + 15, (char *)self + 0x1561, (char *)self + 0x15e1);
  v = self[0x1668/4] + self[0x166c/4];
  FUN_000ffb3c((int *)self[0x1d0/4], v == 0);
  v = FUN_002af274(gbase) - 1;
  int w = self[0x1668/4] + self[0x166c/4];
  FUN_000ffb3c((int *)self[0x1d4/4], w == v);
  for (int i = 0; i < 38; i++) {
    q = (int *)self[164 + i];
    q[62] = (int)((char *)p + 0x361);
    q[78] = 1;
    FUN_0010d4a8(q);
    p += 32;
  }
}
// NEAR 226/212; prologue+frame match; first diff +0x28 (0x002a7644): retail hoists lui at,0x8 / ori at,0x87128 before 'move s2,a0', ours emits move first; body still 206 words off (log/arg ordering).
// near miss from lane dsn3 (unreviewed)
