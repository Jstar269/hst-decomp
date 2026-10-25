/* HSTMATCH module=EBOOT.BIN start=0x00049774 end=0x0004992c symbol=FUN_00049774 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
extern float FUN_00049fbc();
extern float FUN_0004a080(int *p);
extern void FUN_00059174(int o);
extern void FUN_0006391c(int a, int b, int c);
extern void FUN_00063d08(int a, u32 f, int b, int c);
extern void FUN_00058f38(float f, int o, int c);
extern float DAT_002d0810;
extern int DAT_00331b84;
extern int DAT_00331b88;
void FUN_00049774(int *p)
{
  float a = FUN_00049fbc();
  if (*(float *)(*p + 0x104) == 0.0f) a = 1.0f;
  FUN_00059174(*p);
  {
    float b = FUN_00049fbc(p);
    int g = DAT_00331b84;
    if (b + DAT_002d0810 < 1.0f) {
      if (1.0f <= a + DAT_002d0810) FUN_0006391c(p[8], DAT_00331b84, -1);
      *(float *)(DAT_00331b84 + 0x10) = 1.0f - b;
    } else {
      *(u32 *)(DAT_00331b84 + 0xc) = 0;
      *(u8 *)(g + 0x52) = 0;
    }
  }
  a = FUN_0004a080(p);
  {
    int q = *p;
    float c = *(float *)(q + 0x104);
    float d = *(float *)(q + 0x100);
    int flag = 0;
    if (c == 0.0f) a = 0.0f;
    FUN_00058f38(c + d, q, -1);
    d = FUN_0004a080(p);
    FUN_00058f38(c, *p, -1);
    FUN_00059174(*p);
    if (0.0f < d - DAT_002d0810 && a - DAT_002d0810 <= 0.0f) {
      FUN_00063d08(p[8], 0xbf800000, DAT_00331b88, -1);
      flag = 1;
    }
    a = FUN_0004a080(p);
    if (0.0f < a - DAT_002d0810) *(float *)(DAT_00331b88 + 0x10) = a;
    else if (!flag) { *(u32 *)(DAT_00331b88 + 0xc) = 0; *(u8 *)(DAT_00331b88 + 0x52) = 0; }
  }
}
// near miss from lane fm11 (unreviewed)
