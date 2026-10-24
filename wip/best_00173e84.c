/* HSTMATCH module=EBOOT.BIN start=0x00173e84 end=0x00174040 symbol=FUN_00173e84 lang=c99 */

typedef struct { float x, y, z, w; } V4;
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

extern undefined DAT_002c1f38;
extern undefined4 DAT_002e05fc;
extern undefined4 DAT_002e0600;
extern void FUN_0017d59c();
extern void FUN_00184040();

void FUN_00173e84(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{  V4 slot0;

  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_4;
  undefined4 local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x1d4) + 4);
  if (iVar1 < 4) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + -4;
  }
  if (param_2 >= 0) {
    param_2 = *(int *)(param_1 + 0x560) + param_2;
    if (param_2 < 4) {
      *(int *)(param_1 + 0x560) = param_2;
    }
    else {
      *(undefined4 *)(param_1 + 0x560) = 3;
      iVar3 = *(int *)(param_1 + 0x564) + -3;
      *(int *)(param_1 + 0x568) = iVar3;
      if (iVar3 < DAT_002e0600) {
        *(int *)(param_1 + 0x568) = DAT_002e0600;
      }
      else {
        if (iVar3 <= iVar1) {
          iVar1 = iVar3;
        }
        *(int *)(param_1 + 0x568) = iVar1;
      }
    }
  
  }
  else {
    param_2 = *(int *)(param_1 + 0x560) + param_2;
    if (param_2 < 0) {
      *(undefined4 *)(param_1 + 0x560) = 0;
      iVar3 = *(int *)(param_1 + 0x564);
      *(int *)(param_1 + 0x568) = iVar3;
      if (iVar3 < DAT_002e05fc) {
        *(int *)(param_1 + 0x568) = DAT_002e05fc;
      }
      else {
        if (iVar3 <= iVar1) {
          iVar1 = iVar3;
        }
        *(int *)(param_1 + 0x568) = iVar1;
      }
      pcVar2 = *(code **)(param_1 + 0x548);
      goto LAB_00173f8c;
    }
    *(int *)(param_1 + 0x560) = param_2;
  
  }
  pcVar2 = *(code **)(param_1 + 0x548);
LAB_00173f8c:
  local_4 = (*pcVar2)(param_3);
  slot0.x = 0x7fffffff;
  slot0.y = 0x7fffffff;
  slot0.z = 0x7fffffff;
  slot0.w = 0x7fffffff;
  local_8 = 0x7fffffff;
  iVar3 = 0;
  iVar1 = 0;
  do {
    FUN_0017d59c(*(int *)(param_1 + 0x178),&slot0,0,1,
                 *(undefined4 *)
                  (&DAT_002c1f38 + iVar1 + *(int *)(*(int *)(param_1 + 0x178) + 4) * 0x10),1);
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 4;
  } while (iVar3 < 4);
  FUN_00184040(*(undefined4 *)(param_1 + 0x174),param_3,0,1,param_4,param_5);
  return;
}
// near miss from lane km4 (unreviewed)
/* STATUS CORRECTION 2026-10-24 (slot refactor): measured 109/111 words, 85 differ; first at +0x0 -- four contiguous address-taken locals declared as one V4 object. */
// improved by lane fm10 (unreviewed): 87 -> 85 differing words
