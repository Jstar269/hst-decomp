/* HSTMATCH module=EBOOT.BIN start=0x001c8ccc end=0x001c8dc8 symbol=FUN_001c8ccc lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined * DAT_0033b574;
extern int FUN_0014c344();
extern int FUN_001930c4();
extern undefined4 FUN_0019319c();
extern int FUN_0022ada4();

undefined4 FUN_001c8ccc(void)
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = 0;
  bVar1 = false;
  if ((DAT_0033b574 != 0) &&
     (piVar2 = (int *)FUN_0014c344(*(undefined4 *)(DAT_0033b574 + 0x1324),0xbe), *piVar2 >= 2)) {
    bVar1 = true;
  }
  if (bVar1) {
    bVar1 = false;
    if ((DAT_0033b574 != 0) &&
       (piVar2 = (int *)FUN_0014c344(*(undefined4 *)(DAT_0033b574 + 0x1324),0xbf), *piVar2 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar4 = 1;
      iVar5 = 0;
      iVar3 = FUN_0019319c();
      if (0 < iVar3) {
        do {
          iVar3 = FUN_001930c4(iVar5);
          if (((iVar3 != 0) && (*(char *)(iVar3 + 0x2f) != '\0')) &&
             (iVar3 = FUN_0022ada4((int)*(short *)(iVar3 + 0x36),(int)*(short *)(iVar3 + 0x38)),
             iVar3 == 0)) {
            return 0;
          }
          iVar5 = iVar5 + 1;
          iVar3 = FUN_0019319c();
        } while (iVar5 < iVar3);
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}
// Near miss: six words remain at the three result/flag joins; the int helper result and direct less-than-two threshold match. Direct-return restructuring changed the shared return layout.
// near miss from lane u5cr3-0 (unreviewed)
