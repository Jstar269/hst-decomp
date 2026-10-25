/* HSTMATCH module=EBOOT.BIN start=0x00052690 end=0x00052834 symbol=FUN_00052690 lang=c99 */
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
extern float DAT_002d0ebc, DAT_002d0ec0, DAT_002d0ec4, DAT_002d0ec8;
#define CH(v,m) ((((v) * 255.0f) < (m)) ? (u8)(int)((v) * 255.0f) : (u8)(int)(m))
#define FX(v) (((v) < 2147483648.0f) ? (u16)(int)(v) : (u16)((int)((v) - 2147483648.0f) | 0x8000))
void FUN_00052690(int g, float *p2, u32 *p3, float *p4, u32 *p5, float *c)
{
  u32 *p = *(u32 **)(g + 0x28);
  u32 col = (u32)CH(c[0], DAT_002d0ebc) | ((u32)CH(c[1], DAT_002d0ec0) << 8)
          | ((u32)CH(c[2], DAT_002d0ec4) << 16) | ((u32)CH(c[3], DAT_002d0ec8) << 24);
  float u0 = *(float *)(p3 + 2);
  float u1 = *(float *)(p5 + 2);
  p[0] = ((((u32)(p + 0xb) & 0xfffffff) >> 0x18) << 0x10) | 0x10000000;
  p[1] = ((u32)(p + 0xb) & 0xffffff) | 0x8000000;
  *(u16 *)(p + 2) = FX(p2[0]);
  *(u16 *)((int)p + 10) = FX(p2[1]);
  p[3] = col;
  p[4] = p3[0];
  p[5] = p3[1];
  p[6] = FX(u0);
  *(u16 *)(p + 7) = FX(p4[0]);
  *(u16 *)((int)p + 0x1e) = FX(p4[1]);
  p[8] = col;
  p[9] = p5[0];
  p[10] = p5[1];
  p[0xb] = FX(u1);
  p[0xc] = 0x1e000001;
  p[0xd] = 0x1280019e;
  p[0xe] = ((((u32)(p + 2) & 0xfffffff) >> 0x18) << 0x10) | 0x10000000;
  p[0xf] = ((u32)(p + 2) & 0xffffff) | 0x1000000;
  p[0x10] = 0x4060002;
  *(u32 **)(g + 0x28) = p + 0x11;
}
// near miss from lane fm11 (unreviewed)
