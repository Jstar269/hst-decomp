/* HSTMATCH module=EBOOT.BIN start=0x001f7b6c end=0x001f7f68 symbol=FUN_001f7b6c lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
extern int FUN_001931b8(), FUN_001fb524(), FUN_0022cd60(), FUN_0024e2dc(), FUN_0024e064();
extern int FUN_0024e174(), FUN_0024e158(), FUN_0024e1c0();
extern int DAT_0034a678; extern char DAT_00341d88, DAT_00341d89; extern int DAT_00341d8c;
extern char DAT_00341834[]; extern char DAT_00341c54;
void FUN_001f7b6c(int p, int m)
{
  *(u8 *)(p + 0x81ac) = 0; *(u8 *)(p + 0x81ad) = 0; *(u8 *)(p + 0x81ae) = 0;
  *(u8 *)(p + 0x81af) = 0; *(u8 *)(p + 0x81b0) = 0;
  *(u32 *)(p + 0x81b4) = 0; *(u32 *)(p + 0x81b8) = 0; *(u32 *)(p + 0x81bc) = 0; *(u32 *)(p + 0x81c0) = 0;
  *(u8 *)(p + 0x81c4) = 0; *(u8 *)(p + 0x81c5) = 0;
  if (m == 0) {
    if (DAT_0034a678 == 0x2a) {
      int l4 = 0, l8 = 0, iVar2, iVar3, cVar1;
      FUN_001931b8(&l4, &l8, &DAT_00341c54);
      cVar1 = DAT_00341d88;
      iVar2 = FUN_001fb524(p);
      iVar3 = FUN_0022cd60();
      if (iVar3 != 0 && *(int *)(FUN_0022cd60() + 0x138) == 0) *(u8 *)(p + 0x81c4) = 1;
      *(u8 *)(p + 0x81c5) = DAT_00341d89;
      iVar3 = 0;
      if (cVar1 == 0) iVar3 = DAT_00341d8c;
      *(u8 *)(p + 0x81ac) = 1;
      *(u8 *)(p + 0x81ae) = 1;
      *(char *)(p + 0x81af) = cVar1;
      if (*(char *)(p + 0x81af) == 0) {
        if (*(char *)(p + 0x81c4) == 0 && *(char *)(p + 0x81c5) != 0) *(u8 *)(p + 0x81ad) = 1;
        else if ((*(char *)(p + 0x81c4) == 0 || *(char *)(p + 0x81c5) != 0) && iVar3 < iVar2) *(u8 *)(p + 0x81ad) = 1;
      } else *(u8 *)(p + 0x81ad) = 1;
      *(int *)(p + 0x81bc) = iVar2;
      *(int *)(p + 0x81c0) = iVar3;
    } else {
      int iVar2 = FUN_0024e2dc();
      u32 u8v = (u8)DAT_00341834[*(int *)(p + 0x3d4) * 0x120];
      int iVar3 = FUN_0024e174(FUN_0024e064());
      int iVar5 = FUN_001fb524(p);
      int iVar6 = FUN_0024e158(FUN_0024e064());
      int iVar7 = FUN_0024e1c0(FUN_0024e064());
      *(u8 *)(p + 0x81af) = iVar7 == 0;
      if (iVar2 == 3) {
        *(u8 *)(p + 0x81ae) = 1;
        if (iVar6 < 0) *(u8 *)(p + 0x81af) = 1;
        if (*(char *)(p + 0x81af) != 0 || iVar6 < iVar5) *(u8 *)(p + 0x81ad) = 1;
        *(int *)(p + 0x81bc) = iVar5;
        *(int *)(p + 0x81c0) = iVar6;
      } else {
        *(u8 *)(p + 0x81ae) = 0;
        if (*(char *)(p + 0x81af) != 0 || iVar3 < (int)u8v) *(u8 *)(p + 0x81ad) = 1;
        *(u32 *)(p + 0x81b4) = u8v;
        *(int *)(p + 0x81b8) = iVar3;
        if (*(char *)(p + 0x81ad) != 0 && u8v == 0xe) *(u8 *)(p + 0x81b0) = 1;
      }
    }
  } else {
    *(u8 *)(p + 0x81ad) = 1; *(u8 *)(p + 0x81af) = 1; *(u8 *)(p + 0x81b0) = 1;
    *(u32 *)(p + 0x81b4) = 0xe; *(u32 *)(p + 0x81b8) = 0;
  }
}
// near miss from lane fm11 (unreviewed)
