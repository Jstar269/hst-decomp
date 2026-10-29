/* HSTMATCH module=EBOOT.BIN start=0x000ceb1c end=0x000cec2c symbol=FUN_000ceb1c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float DAT_0033876C;
extern float DAT_00338760[];
extern void FUN_00058fc0(void *p, int a);
extern void FUN_0005f110(void *p, float v);
extern void FUN_00059084(void *p, int a);
extern void FUN_000550c8(void *p, float *v);
extern void FUN_00059174(void *p);
extern void FUN_0005f0d8(void *p);

void FUN_000ceb1c(char *self)
{
  float *v;
  float buf[4];
  char *ctl;
  int none = -1;

  if (DAT_0033876C > 0.0f) v = DAT_00338760;
  else v = 0;
  if (v != 0) {
    if (*(unsigned char *)(self + 0x3c) == 0) {
      ctl = self + 0x40;
      FUN_00058fc0(ctl, none);
      FUN_0005f110(ctl, 0.0f);
      *(int *)(self + 0x110) = 0;
      FUN_00059084(ctl, -1);
      *(float *)(self + 0x110) = *(float *)(self + 0x104);
    }
    buf[0] = v[0];
    buf[1] = v[1];
    buf[2] = v[2];
    buf[3] = v[3];
    buf[1] = v[1] - 0.099999994f;
    FUN_000550c8(self + 0x40, buf);
    *(unsigned char *)(self + 0x3c) = 1;
  } else {
    *(unsigned char *)(self + 0x3c) = 0;
  }
  if (*(unsigned char *)(self + 0x3c) != 0) {
    ctl = self + 0x40;
    FUN_00059174(ctl);
    FUN_0005f0d8(ctl);
    *(float *)(self + 0xc0) = *(float *)(self + 0x144);
  }
}
