/* HSTMATCH module=EBOOT.BIN start=0x00285d04 end=0x00285e40 symbol=FUN_00285d04 lang=c99 */
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

extern int DAT_00338ac4;
extern int FUN_000bbba4();

undefined4 FUN_00285d04(int param_1)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (DAT_00338ac4 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_000bbba4(DAT_00338ac4,DAT_00338ac4 + 0x3e);
    if (*(uchar *)(DAT_00338ac4 + iVar2 * 7 + 0x5e) == '\0') {
      uVar3 = 0;
    }
    else {
      iVar5 = iVar2 * 0x458 + param_1;
      if (*(uchar *)(iVar5 + 0xa6d) == '\0') {
        uVar3 = 0;
      }
      else {
        iVar9 = 0;
        iVar4 = DAT_00338ac4;
        do {
          if ((((*(uchar *)(iVar4 + 0x5e) != '\0') && (*(uchar *)(param_1 + 0xa6d) != '\0')) &&
              (iVar9 != iVar2)) && (*(uchar *)(param_1 + 0xa48) == '\0')) {
            iVar8 = 0;
            piVar6 = (int *)(iVar5 + 0x958);
            iVar7 = param_1;
            do {
              if (*piVar6 != *(int *)(iVar7 + 0x958)) {
                bVar1 = false;
                goto LAB_00285e08;
              }
              iVar8 = iVar8 + 1;
              iVar7 = iVar7 + 4;
              piVar6 = piVar6 + 1;
            } while (iVar8 < 7);
            if (*(int *)(iVar5 + 0x974) == *(int *)(param_1 + 0x974)) {
              if (*(int *)(iVar5 + 0x978) == *(int *)(param_1 + 0x978)) {
                bVar1 = true;
              }
              else {
                bVar1 = false;
              }
            }
            else {
              bVar1 = false;
            }
LAB_00285e08:
            if (!bVar1) {
              return 0;
            }
          }
          iVar9 = iVar9 + 1;
          iVar4 = iVar4 + 7;
          param_1 = param_1 + 0x458;
        } while (iVar9 < 4);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}
// near miss from lane dsn3 (unreviewed)
