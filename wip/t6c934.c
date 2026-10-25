/* HSTMATCH module=EBOOT.BIN start=0x0006c934 end=0x0006cc08 symbol=FUN_0006c934 lang=c99 */
typedef unsigned int u32;
extern int FUN_0006cc54(); extern int FUN_0006cc30(); extern int FUN_0006cc28();
extern int FUN_0006cc20(); extern int FUN_00068a54(); extern int FUN_00000a00();
extern int FUN_0006b96c(); extern int FUN_0006cc10(); extern int FUN_0006cc08();
extern int FUN_0006cc00();
#define BLK(q) do { int *t; int iVar1; u32 uVar2; \
  t = (int *)*(u32 *)(q); \
  if (t == 0) { t = (int *)*(u32 *)((char *)(q) + 4); } \
  else { \
    if (*t == 0) iVar1 = t[1]; else { FUN_0006c934(p1, (u32 *)t); iVar1 = t[1]; } \
    if (iVar1 != 0) FUN_0006c934(p1, (u32 *)iVar1); \
    uVar2 = FUN_0006cc54(p1); FUN_0006cc30(uVar2, t + 3); \
    uVar2 = FUN_0006cc28(p1); FUN_0006cc20(uVar2, t, 1); \
    t = (int *)*(u32 *)((char *)(q) + 4); } \
  if (t != 0) { \
    if (*t == 0) iVar1 = t[1]; else { FUN_0006c934(p1, (u32 *)t); iVar1 = t[1]; } \
    if (iVar1 != 0) FUN_0006c934(p1, (u32 *)iVar1); \
    uVar2 = FUN_0006cc54(p1); FUN_0006cc30(uVar2, t + 3); \
    uVar2 = FUN_0006cc28(p1); FUN_0006cc20(uVar2, t, 1); } \
  FUN_0006cc54(p1); FUN_00068a54((u32 *)(q) + 3, -1); FUN_0006cc28(p1); FUN_00000a00(q); } while (0)
void FUN_0006c934(u32 p1, u32 *p2)
{
  u32 *v;
  v = (u32 *)*p2;
  if (v != 0) BLK(v);
  v = (u32 *)p2[1];
  if (v != 0) BLK(v);
  if (p2 != (u32 *)0xfffffff4 && p2 != (u32 *)0xfffffff0) {
    u32 *q = p2 + 9;
    int t;
    if (q != 0) FUN_0006b96c(q, 0);
    q = p2 + 6;
    t = FUN_0006cc10(q, p2[7]);
    if (q != 0 && p2[6] != 0) {
      u32 u;
      FUN_0006cc08(q);
      u = p2[6];
      FUN_0006cc00(q);
      FUN_00000a00((void *)u);
    }
  }
  FUN_00000a00(p2);
}
// near miss from lane fm11 (unreviewed)
