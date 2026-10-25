/* HSTMATCH module=EBOOT.BIN start=0x00205558 end=0x002059ec symbol=FUN_00205558 lang=c99 */
typedef unsigned int u32;
extern int FUN_002059ec(), FUN_00092078(), FUN_00057b58(), FUN_00058ddc(), FUN_00058ec4();
extern int FUN_00058f38(), FUN_0005f110(), FUN_00059084(), FUN_00093b00(), FUN_00205b4c();
extern u32 DAT_00310fc8; extern char DAT_002ef6a4[];
#define SETUP(v, arg, fl) do { FUN_00057b58(0, o, 0, arg); FUN_00058ddc(o, fl, -1); \
  FUN_00058ec4(0x3f800000, o, -1); *(u32 *)(o + 0xc4) = 0x3f800000; FUN_00058f38(v, o, -1); \
  FUN_0005f110(v, o); FUN_00059084(o, -1); *(u32 *)(o + 0xd0) = *(u32 *)(o + 0xc4); } while (0)
#define RND() (((float)(((DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3) & 0x7fffffffu) >> 0x10)) * 3.0517578e-05f * 5.0f)
void FUN_00205558(int *a)
{
  int i4; u32 k; int flg;
  if (a[0x12] != 0) {
    FUN_002059ec(DAT_002ef6a4, a[0x11]);
    a[0x11] = a[0x12];
    a[0x12] = 0;
    i4 = a[0x11];
    if (i4 != 3 && i4 != 2) {
      if (i4 != 1) goto lab99c;
      if ((char)a[0x1b] == 0) k = 0;
      else if (a[0x1c] == 0) k = 4;
      else k = 2;
      flg = k < (u32)a[4] && **(int **)(a[3] + k * 4) != 0;
      if (flg) {
        int o;
        float f1 = RND();
        FUN_00092078(f1, *a, k, 1, 0);
        {
          int o2;
          float f2 = RND();
          o2 = *(int *)(*a + 100);
          if (o2 != 0) { o = o2; SETUP(f2, k, 1); }
        }
        (*(void (**)(int))(*(int *)*a + 0xc))(*a);
      }
      goto lab998;
    }
    /* i == 3 or 2 */
    if ((char)a[0x1b] == 0) k = (i4 == 3) ? 1 : 2;
    else if (a[0x1c] == 0) k = (i4 == 3) ? 5 : 2;
    else k = (i4 == 3) ? 3 : 2;
    if (i4 == 3) { if ((char)a[0x1b] == 0) k = 1; else if (a[0x1c] == 0) k = 5; else k = 3; }
    flg = k < (u32)a[4] && **(int **)(a[3] + k * 4) != 0;
    if (flg) {
      int o;
      if (i4 == 2) {
        FUN_00092078(0xbf800000, *a, 0, 0, 0);
        o = *(int *)(*a + 100);
        if (o != 0) { FUN_00057b58(0, o, 0, 0); FUN_00058ddc(o, 0, -1); FUN_00058ec4(0x3f800000, o, -1);
          *(u32 *)(o + 0xc4) = 0x3f800000; FUN_00058f38(0xbf800000, o, -1); FUN_0005f110(0xbf800000, o);
          FUN_00059084(o, -1); *(u32 *)(o + 0xd0) = *(u32 *)(o + 0xc4); }
      }
      FUN_00092078(0xbf800000, *a, k, 0, 0);
      o = *(int *)(*a + 100);
      if (o != 0) { SETUP(0xbf800000, k, 0); }
      (*(void (**)(int))(*(int *)*a + 0xc))(*a);
    }
  }
lab998:
lab99c:
  i4 = a[0x11];
  if (i4 == 3 && FUN_00093b00(*a, -1) != 0) FUN_00205b4c(a, 1);
}
// near miss from lane fm11 (unreviewed)
