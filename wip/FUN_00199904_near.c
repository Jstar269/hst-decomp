/* HSTMATCH module=EBOOT.BIN start=0x00199904 end=0x00199a0c symbol=FUN_00199904 lang=c99 */
extern int DAT_003091b0;
extern int DAT_0030ebf4;
extern int DAT_002e1944[6];
extern int DAT_002e195c;
extern int DAT_0034179c;
extern void FUN_0001f06c(void *self);
extern void FUN_0001cad0(void *a, int b, void *c);
extern void *FUN_00000bcc(int size);
extern int FUN_00050ff4(void *p, int a, int b);
extern void FUN_001b2bc8(void *p);
extern void FUN_00199754(void *p, int a);
extern void FUN_0001cb88(void *p);
int FUN_00199904(int this_)
{
  int *o = (int *)this_;
  int *s0;
  int *tab;
  int i;
  FUN_0001f06c(o);
  o[0] = (int)&DAT_003091b0;
  FUN_0001cad0(&DAT_0030ebf4, 1, &DAT_002e195c);
  o[15] = 0;
  if ((s0 = (int *)FUN_00000bcc(44)) != 0) {
    s0[6] = 0;
    s0[7] = 0;
    s0[8] = 0;
    *(char *)((char *)s0 + 36) = 0;
    s0[10] = -1;
    tab = DAT_002e1944;
    for (i = 0; i < 6; i++) {
      s0[i] = (int)FUN_00000bcc(72);
      if (s0[i]) s0[i] = FUN_00050ff4((void *)s0[i], *tab, 0);
      tab++;
    }
    FUN_001b2bc8(&DAT_0034179c);
    FUN_00199754(s0, 0);
  }
  FUN_0001cb88(&DAT_0030ebf4);
  o[15] = (int)s0;
  return this_;
}
// near miss from lane dsn3 (unreviewed)
