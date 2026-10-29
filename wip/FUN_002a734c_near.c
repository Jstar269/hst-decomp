/* HSTMATCH module=EBOOT.BIN start=0x002a734c end=0x002a761c symbol=FUN_002a734c lang=c99 */
extern char DAT_003415a8[];
extern char DAT_00301038[];
extern char DAT_00300a90[];
extern char DAT_00301510[];
extern int FUN_002af274(void *);
extern int FUN_002af27c(void *, int);
extern void FUN_000ffb3c(int, int);
extern int FUN_002af26c(void *);
extern int FUN_00020f5c(float);
extern int FUN_00143b0(void *, char *, ...);
extern char *strcpy(char *, const char *);
/* PARKED NEAR: first compile 182/180 words, 148 differ. Structure as decoded, but ours keeps g in s8:
   retail uses exactly s0..s7 (self s5, g s7, table s1, ptr s0/s2, i s4, elem s6, idx s3) and we add a ninth,
   so every prologue/epilogue word shifts. Open questions: the FUN_00143b0 4-arg call gets a3 = v1 which only the
   <10 band assigns (stale in the other two bands, so the source 4th argument is not simply n); the second
   argument of the strcpy call in the found path; and whether the i++ belongs inside each band (retail duplicates
   it into both branch tails). Compare condition fixed to `idx < FUN_002af274(g)` (the call returns the count). */
extern void FUN_0010f5d4(int, int);
#define VT3(p, f) (*(void (**)(int, int))(*(int *)(p) + 12))((p), (f))
void FUN_002a734c(char *self)
{
  char *g = (char *)*(int *)DAT_003415a8 + 0x87128;
  char *s1 = DAT_00301510;
  char *s0 = self;
  char *s2 = self;
  int i = 0;
  do {
    int idx;
    int v0;
    idx = *(int *)(self + 0x166c) + i;
    if (idx < FUN_002af274(g)) {
      char *s6 = (char *)FUN_002af27c(g, idx);
      int n;
      int v1;
      FUN_000ffb3c(*(int *)(s2 + 0x184), 0);
      n = *(int *)(self + 0x166c) + i + 1;
      if (n >= 100) {
        FUN_000ffb3c(*(int *)(s2 + 0x94), 1);
        FUN_000ffb3c(*(int *)(s2 + 0xc4), 1);
        VT3(*(int *)(s2 + 0x328), 1);
        FUN_000ffb3c(*(int *)(s2 + 0x64), 0);
      } else if (n < 10) {
        FUN_000ffb3c(*(int *)(s2 + 0xc4), 1);
        VT3(*(int *)(s2 + 0x328), 1);
        FUN_000ffb3c(*(int *)(s2 + 0x64), 1);
        FUN_000ffb3c(*(int *)(s2 + 0x94), 0);
        v1 = *(int *)(s1 + 0xa4) + n;
        v0 = *(int *)(s2 + 0x94);
        *(int *)(v0 + 0x24) = v1;
        *(int *)(v0 + 0x28) = v1;
      } else {
        FUN_000ffb3c(*(int *)(s2 + 0x94), 1);
        FUN_000ffb3c(*(int *)(s2 + 0x64), 1);
        FUN_000ffb3c(*(int *)(s2 + 0xc4), 0);
        VT3(*(int *)(s2 + 0x328), 0);
        FUN_0010f5d4(*(int *)(s2 + 0x328), n);
      }
      {
        float f20 = *(float *)(s6 + 0x30);
        int s3 = FUN_002af26c(s6);
        int a2 = FUN_00020f5c(f20);
        FUN_00143b0(self + (((i + 12) << 7) + 0x361), DAT_00301038, a2, v1);
        FUN_000ffb3c(*(int *)(s2 + 0x124), 0);
        v1 = *(int *)(s1 + 0x254) + s3;
        v0 = *(int *)(s2 + 0x124);
        *(int *)(v0 + 0x24) = v1;
        *(int *)(v0 + 0x28) = v1;
        strcpy(s0 + 0x361, s6 + 0x18);
      }
    } else {
      FUN_000ffb3c(*(int *)(s2 + 0x184), 1);
      FUN_000ffb3c(*(int *)(s2 + 0x94), 1);
      FUN_000ffb3c(*(int *)(s2 + 0xc4), 1);
      VT3(*(int *)(s2 + 0x328), 1);
      FUN_000ffb3c(*(int *)(s2 + 0x64), 1);
      FUN_00143b0(self + (((i + 12) << 7) + 0x361), DAT_00300a90);
      FUN_000ffb3c(*(int *)(s2 + 0x124), 1);
      strcpy(s0 + 0x361, DAT_00300a90);
    }
    i++;
    s2 += 4;
    s1 += 12;
    s0 += 128;
  } while (i < 12);
  VT3(*(int *)(self + 0x35c), FUN_002af274(g) < 13);
}
// near miss from lane dsn3 (unreviewed)
