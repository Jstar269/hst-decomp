/* HSTMATCH module=EBOOT.BIN start=0x00063088 end=0x00063554 symbol=FUN_00063088 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
extern int FUN_00063554(), FUN_00051490(), FUN_00051a10(), FUN_0005185c();
extern int FUN_00050534(), FUN_00051398(), FUN_00051894(), FUN_000503d0();
#define C8(v) ((v) < 2147483648.0f ? (u8)(int)(v) : (u8)(int)((v) - 2147483648.0f))
void FUN_00063088(u32 param_1, int p)
{
  float f[4];
  if ((*(char *)(p + 0x40) == 0) || (*(char *)(p + 0x41) != 0)) {
    u8 a, b, c, d, shade;
    float al;
    FUN_00063554(f, p);
    if (0.0f <= *(float *)(p + 0x10)) { shade = *(char *)(p + 0x40); al = *(float *)(p + 0x10); }
    else shade = *(char *)(p + 0x40);
    if (shade == 0) {
      u32 col;
      u32 cv = *(u32 *)(p + 4);
      a = C8(f[0] * 255.0f); b = C8(f[1] * 255.0f); c = C8(f[2] * 255.0f); d = C8(al * 128.0f);
      col = a | (b << 8) | (c << 16) | ((u32)d << 24);
      FUN_00051490(cv, 0, 0, 0x1e0, 0x110, 0, 0);
      FUN_00051a10(0, 0, 0x43f00000, 0x43880000, param_1, cv, col);
      FUN_0005185c(cv);
    } else {
      u32 col;
      int cv;
      float x = 0.0f;
      int i = 0;
      a = C8(f[0] * 128.0f); b = C8(f[1] * 128.0f); c = C8(f[2] * 128.0f); d = C8(al * 128.0f);
      col = a | (b << 8) | (c << 16) | ((u32)d << 24);
      cv = FUN_00050534(0x311170);
      FUN_00051398(*(u32 *)(*(int *)(p + 4) + 0x18), cv);
      if (cv != 0) {
        FUN_00051490(cv, 0, 0, 0x1e0, 0x110, 0, 0);
        do {
          FUN_00051894(x, 0, x, 0, x + 120.0f, 0x43880000, x + 120.0f, 0x43880000, cv, col);
          i++; x += 120.0f;
        } while (i < 4);
        FUN_0005185c(cv);
      }
    }
  } else {
    FUN_000503d0(*(u32 *)(p + 0x44), 0x311170);
    *(u8 *)(p + 0x41) = 1;
  }
}
// near miss from lane fm11 (unreviewed)
