/* HSTMATCH module=EBOOT.BIN start=0x000f57a4 end=0x000f5ba8 symbol=FUN_000f57a4 lang=c99 */
typedef unsigned int u32; typedef unsigned short u16;
extern int FUN_001031e8(); extern int FUN_00051490(); extern int FUN_00051894(); extern int FUN_0005185c();
extern u32 DAT_003386b0; extern u32 DAT_00338b44;
void FUN_000f57a4(int a)
{
  int i, off;
  if (*(char *)(a + 0x54) != 0) return;
  FUN_001031e8();
  i = 0; off = 0;
  do {
    u32 *p = *(u32 **)(a + 0xe0);
    int n = *(int *)(DAT_003386b0 + off + 0x70);
    u32 v = *(u32 *)(n + 0x794);
    int panel = n + 0x788;
    int src = *(int *)(a + 0x58);
    int shade;
    *(u16 *)(p + 2) = (u16)(*(u16 *)(p + 1) + *(u32 *)(n + 0x790));
    *(u16 *)((int)p + 10) = (u16)(*(u16 *)((int)p + 6) + (u16)v);
    shade = (int)(*(float *)(src + 0x78) * 128.0f);
    *p = ((u32)shade << 0x18) | 0x808080;
    FUN_00051490(panel, 0, 0, 0x1e0, 0x110, 0, 0);
    FUN_00051894(0, 0, panel, ((u32)shade << 0x18) | 0x808080);
    FUN_0005185c(panel);
    if (*(char *)(DAT_00338b44 + 0x45) == 0) {
      u32 *q = *(u32 **)(a + 0xe8);
      int m = *(int *)(DAT_003386b0 + off + 0x78);
      u32 w = *(u32 *)(m + 0x794);
      int panel2 = m + 0x788;
      int s2;
      *(u16 *)(q + 2) = (u16)(*(u16 *)(q + 1) + *(u32 *)(m + 0x790));
      *(u16 *)((int)q + 10) = (u16)(*(u16 *)((int)q + 6) + (u16)w);
      s2 = (int)(*(float *)(src + 0x78) * 128.0f);
      *q = ((u32)s2 << 0x18) | 0x808080;
      FUN_00051490(panel2, 0, 0, 0x1e0, 0x110, 0, 0);
      FUN_00051894(0, 0, panel2, ((u32)s2 << 0x18) | 0x808080);
      FUN_0005185c(panel2);
    }
    i++; off += 4; a += 4;
  } while (i < 2);
}
// near miss from lane fm11 (unreviewed)
