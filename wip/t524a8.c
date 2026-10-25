/* HSTMATCH module=EBOOT.BIN start=0x000524a8 end=0x00052690 symbol=FUN_000524a8 lang=c99 */
typedef unsigned int u32; typedef unsigned short u16;
extern int DAT_002d0eb8;
#define FX(v) (((v) < 2147483648.0f) ? (u16)(int)(v) : (u16)((int)((v) - 2147483648.0f) | 0x8000))
void FUN_000524a8(float x0, float y0, u32 c0, u32 f0, float x1, float y1, u32 c1, u32 f1,
                  int g, u32 attr, float u0, float u1)
{
  u32 *p = *(u32 **)(g + 0x28);
  int n = (attr >> 0x18) << 1;
  u32 col;
  if (n > DAT_002d0eb8) n = DAT_002d0eb8;
  col = (attr & 0x00ffffff) | ((u32)n << 24);
  p[0] = ((((u32)(p + 0xb) & 0xfffffff) >> 0x18) << 0x10) | 0x10000000;
  p[1] = ((u32)(p + 0xb) & 0xffffff) | 0x8000000;
  *(u16 *)(p + 2) = FX(x0);
  *(u16 *)((int)p + 10) = FX(y0);
  p[3] = col;
  p[4] = c0;
  p[5] = f0;
  p[6] = FX(u0);
  *(u16 *)(p + 7) = FX(x1);
  *(u16 *)((int)p + 0x1e) = FX(y1);
  p[8] = col;
  p[9] = c1;
  p[10] = f1;
  p[0xb] = FX(u1);
  p[0xc] = 0x1e000001;
  p[0xd] = 0x1280019e;
  p[0xe] = ((((u32)(p + 2) & 0xfffffff) >> 0x18) << 0x10) | 0x10000000;
  p[0xf] = ((u32)(p + 2) & 0xffffff) | 0x1000000;
  p[0x10] = 0x4060002;
  *(u32 **)(g + 0x28) = p + 0x11;
}
// near miss from lane fm11 (unreviewed)
