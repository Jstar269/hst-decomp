/* HSTMATCH module=EBOOT.BIN start=0x002a7b44 end=0x002a7f78 symbol=FUN_002a7b44 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8; typedef unsigned short u16;
extern int FUN_00049094(), FUN_00022668(), FUN_0002260c(), FUN_000225b0();
extern int FUN_00093484(), FUN_00093434(), FUN_00093750(), FUN_00093778();
extern int FUN_000937a0(), FUN_00093be0(), FUN_00057b58(), FUN_00058ddc();
extern int FUN_00058ec4(), FUN_00058f38(), FUN_0005f110(), FUN_00059084();
extern float DAT_002bc410[]; extern char DAT_0034b470, DAT_0034b490;
extern float DAT_0034b4a0, DAT_0034b4a4, DAT_0034b4a8, DAT_0034b4ac;
extern float DAT_0034b4b0, DAT_0034b4b4, DAT_0034b4b8, DAT_0034b4bc;
extern float DAT_0034b480, DAT_0034b484, DAT_0034b488, DAT_0034b48c;
extern int DAT_00301c9c, DAT_00301c94, DAT_00301c98; extern float DAT_00301ca0;
extern float DAT_0034b4c0, DAT_0034b4c4; extern float DAT_0034b458[], DAT_0034b460[];
void FUN_002a7b44(int *a)
{
  float m[16];
  int i;
  if (*(char *)((int)a + 0x19) != 0) {
    if (FUN_00049094(0) != 0) {
      for (i = 0; i < 16; i++) m[i] = DAT_002bc410[i];
      if (DAT_0034b470 == 0) DAT_0034b470 = 1;
      if (DAT_0034b490 == 0) {
        DAT_0034b4a0 = 0.0f; DAT_0034b4a4 = 0x3ecccccd; DAT_0034b4a8 = 0x400ccccd; DAT_0034b4ac = 1.0f;
        DAT_0034b4b0 = 0.0f; DAT_0034b4b4 = 0x3f333333; DAT_0034b4b8 = 0x400ccccd; DAT_0034b4bc = 1.0f;
        DAT_0034b490 = 1;
      }
      {
        u16 *src = (u16 *)(DAT_002bc410 + 4);
        u16 *dst = (u16 *)(m + 12);
        i = 8;
        do {
          u8 hi = *(u8 *)((int)src + 1);
          i--;
          *(u8 *)dst = *(u8 *)src;
          *(u8 *)((int)dst + 1) = hi;
          src = (u16 *)((int)src + 2);
          dst = (u16 *)((int)dst + 2);
        } while (0 < i);
      }
      if ((char)a[6] == 0) {
        DAT_00301c9c = DAT_00301c94;
        DAT_0034b484 = DAT_0034b4a4; DAT_0034b488 = DAT_0034b4a8; DAT_0034b48c = DAT_0034b4ac;
        DAT_0034b480 = DAT_0034b458[a[5]];
      } else {
        DAT_00301c9c = DAT_00301c98;
        DAT_0034b484 = DAT_0034b4b4; DAT_0034b488 = DAT_0034b4b8; DAT_0034b48c = DAT_0034b4bc;
        DAT_0034b480 = DAT_0034b460[a[5]];
      }
      FUN_00022668(DAT_0034b4c0 * 0.017453292f, m, m);
      FUN_0002260c(DAT_00301ca0 * 0.017453292f, m, m);
      FUN_000225b0(DAT_0034b4c4 * 0.017453292f, m, m);
      m[12] = DAT_0034b480; m[13] = DAT_0034b484; m[14] = DAT_0034b488; m[15] = DAT_0034b48c;
      FUN_00093484(DAT_00301c9c, *a);
      FUN_00093434(*a, m);
      FUN_00093750(0, *a, 0, a[7]);
      FUN_00093778(*a, 1, -1);
      FUN_000937a0(0x3f800000, *a, -1);
      FUN_00093be0(*a, -1);
      {
        int o = *(int *)(*a + 100);
        if (o == 0) *(u8 *)((int)a + 0x19) = 0;
        else {
          FUN_00057b58(0, o, 0, a[7]);
          FUN_00058ddc(o, 1, -1);
          FUN_00058ec4(0x3f800000, o, -1);
          *(u32 *)(o + 0xc4) = 0x3f800000;
          FUN_00058f38(0xbf800000, o, -1);
          FUN_0005f110(0xbf800000, o);
          FUN_00059084(o, -1);
          *(u32 *)(o + 0xd0) = *(u32 *)(o + 0xc4);
          *(u8 *)((int)a + 0x19) = 0;
        }
      }
      *(u8 *)((int)a + 0x1a) = 1;
    }
  }
  if (*(char *)((int)a + 0x19) == 0 && *(char *)((int)a + 0x1a) != 0) {
    (*(void (**)(int *))(*(int *)*a + 0xc))((int *)*a);
  }
}
// near miss from lane fm11 (unreviewed)
