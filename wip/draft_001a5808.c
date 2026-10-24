/* HSTMATCH module=EBOOT.BIN start=0x001a5808 end=0x001a5a1c symbol=FUN_001a5808 lang=c99 */
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


void FUN_001a5808(int *param_1,int *param_2,int param_3,int param_4,int param_5,int *param_6, int param_7)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  bVar1 = false;
  if (param_3 < 0) {
    iVar3 = 1;
    if (1 < param_4) {
      iVar2 = *param_2;
      do {
        iVar2 = iVar2 - iVar3;
        if (iVar2 < 0) {
          if (param_5 == 0) {
            bVar1 = true;
          }
          else {
            iVar2 = iVar2 + param_4;
          }
        }
        if (!bVar1) {
          piVar6 = (int *)(*param_6 + iVar2 * 0xc);
          if (piVar6[1] < 1) {
            iVar4 = *piVar6;
          }
          else {
            iVar4 = piVar6[1] + -1;
            if (iVar4 < *param_1) {
              if (-1 < iVar4) {
                iVar5 = *param_6;
                while( true ) {
                  if (param_7 < *(int *)(*(int *)(iVar5 + iVar2 * 0xc) + iVar4 * 4)) {
                    *param_2 = iVar2;
                    *param_1 = iVar4;
                    bVar1 = true;
                  }
                  if ((bVar1) || (iVar4 = iVar4 + -1, iVar4 < 0)) break;
                  iVar5 = *param_6;
                }
              }
              goto LAB_001a58f4;
            }
            iVar4 = *piVar6;
          }
          if (param_7 < *(int *)(iVar4 + *param_1 * 4)) {
            *param_2 = iVar2;
            bVar1 = true;
          }
        }
LAB_001a58f4:
        if (bVar1) {
          return;
        }
        iVar3 = iVar3 + 1;
        if (param_4 <= iVar3) {
          return;
        }
        iVar2 = *param_2;
      } while( true );
    }
  }
  else {
    iVar3 = 1;
    if (1 < param_4) {
      iVar2 = *param_2;
      do {
        iVar2 = iVar2 + iVar3;
        if (param_4 <= iVar2) {
          if (param_5 == 0) {
            bVar1 = true;
          }
          else {
            iVar2 = iVar2 - param_4;
          }
        }
        if (!bVar1) {
          piVar6 = (int *)(*param_6 + iVar2 * 0xc);
          if (piVar6[1] < 1) {
            iVar4 = *piVar6;
          }
          else {
            iVar4 = piVar6[1] + -1;
            if (iVar4 < *param_1) {
              if (-1 < iVar4) {
                iVar5 = *param_6;
                while( true ) {
                  if (param_7 < *(int *)(*(int *)(iVar5 + iVar2 * 0xc) + iVar4 * 4)) {
                    *param_2 = iVar2;
                    *param_1 = iVar4;
                    bVar1 = true;
                  }
                  if ((bVar1) || (iVar4 = iVar4 + -1, iVar4 < 0)) break;
                  iVar5 = *param_6;
                }
              }
              goto LAB_001a59fc;
            }
            iVar4 = *piVar6;
          }
          if (param_7 < *(int *)(iVar4 + *param_1 * 4)) {
            *param_2 = iVar2;
            bVar1 = true;
          }
        }
LAB_001a59fc:
        if (bVar1) {
          return;
        }
        iVar3 = iVar3 + 1;
        if (param_4 <= iVar3) {
          return;
        }
        iVar2 = *param_2;
      } while( true );
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)
