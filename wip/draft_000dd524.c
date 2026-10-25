/* HSTMATCH module=EBOOT.BIN start=0x000dd524 end=0x000dd994 symbol=FUN_000dd524 lang=c99 */
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

extern undefined * DAT_003386b0;
extern undefined4 DAT_00341284;
extern undefined4 DAT_00341288;
extern int FUN_0008882c();

void FUN_000dd524(int param_1,int param_2)
{
  uchar cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if (0 < *(int *)(param_1 + 0x90)) {
    iVar2 = FUN_0008882c(DAT_003386b0);
    if (param_2 == *(int *)(iVar2 + 0x148)) {
      if (0 < *(int *)(param_1 + 0x90)) {
        if (*(int *)(param_1 + 0x90) == 1) {
          if ((*(int *)(param_1 + 0x8c) == 1) && (*(uchar *)(param_1 + 100) != '\0')) {
            *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1e8) =
                 *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1e8) + 1;
          }
        }
        else {
          if ((*(uchar *)(param_1 + 100) != '\0') || (*(int *)(param_1 + 0xac) == 0)) {
            *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1e4) =
                 *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1e4) + 1;
          }
          if (DAT_00341284 < *(int *)(param_1 + 0x7c)) {
            cVar1 = *(uchar *)(param_1 + 0x84);
          }
          else {
            if (DAT_00341288 <= *(int *)(param_1 + 0x7c)) {
              *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x20c) =
                   *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x20c) + 1;
              iVar2 = (DAT_00341284 - *(int *)(param_1 + 0x7c)) * 4 +
                      *(int *)(DAT_003386b0 + 0xa0);
              *(int *)(iVar2 + 0x210) = *(int *)(iVar2 + 0x210) + 1;
            }
            cVar1 = *(uchar *)(param_1 + 0x84);
          }
          if (cVar1 == '\0') {
            cVar1 = *(uchar *)(param_1 + 0x84);
          }
          else {
            *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x200) =
                 *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x200) + 1;
            cVar1 = *(uchar *)(param_1 + 0x84);
          }
          if (((cVar1 == '\0') && (*(uchar *)(param_1 + 0x61) != '\0')) &&
             ((*(uint *)(param_1 + 0x94) ^ 1) == *(uint *)(param_1 + 0x9c))) {
            *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x204) =
                 *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x204) + 1;
          }
        }
      }
      iVar2 = *(int *)(param_1 + 0x78);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x78);
    }
    if (iVar2 == param_2) {
      iVar2 = *(int *)(param_1 + 0x90);
      uVar5 = *(uint *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1dc);
      if (uVar5 < (uint)(iVar2 / 2)) {
        uVar5 = iVar2 / 2;
      }
      *(uint *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1dc) = uVar5;
      iVar2 = *(int *)(param_1 + 0x90);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x90);
    }
    if (iVar2 == 1) {
      if (*(uchar *)(param_1 + 100) != '\0') {
        iVar2 = *(int *)(DAT_003386b0 + 0xa0) + 0x54 + param_2 * 0x5c;
        puVar4 = (undefined4 *)(iVar2 + 0x18);
        puVar3 = puVar4;
        if (*(float *)(iVar2 + 0x18) < *(float *)(param_1 + 0x80)) {
          puVar3 = (undefined4 *)(param_1 + 0x80);
        }
        *puVar4 = *puVar3;
      }
      cVar1 = *(uchar *)(param_1 + 0x65);
    }
    else {
      cVar1 = *(uchar *)(param_1 + 0x65);
    }
    if (cVar1 == '\0') {
      iVar2 = *(int *)(param_1 + 0x90);
    }
    else {
      iVar2 = param_2 * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
      *(int *)(iVar2 + 0x84) = *(int *)(iVar2 + 0x84) + 1;
      iVar2 = *(int *)(param_1 + 0x90);
    }
    if (iVar2 < 2) {
      cVar1 = *(uchar *)(param_1 + 0x66);
    }
    else {
      if (*(uchar *)(param_1 + 0x70) != '\0') {
        iVar2 = param_2 * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(iVar2 + 0x98) = *(int *)(iVar2 + 0x98) + 1;
      }
      cVar1 = *(uchar *)(param_1 + 0x66);
    }
    if (cVar1 == '\0') {
      iVar2 = *(int *)(param_1 + 0x6c);
    }
    else {
      iVar2 = param_2 * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
      *(int *)(iVar2 + 0x94) = *(int *)(iVar2 + 0x94) + 1;
      iVar2 = *(int *)(param_1 + 0x6c);
    }
    if (iVar2 == 1) {
      iVar2 = *(int *)(param_1 + 0x90);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x68);
      if (iVar2 == 2) {
        iVar2 = param_2 * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(iVar2 + 0xac) = *(int *)(iVar2 + 0xac) + 1;
      }
      else if (iVar2 == 1) {
        iVar2 = param_2 * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(iVar2 + 0xa8) = *(int *)(iVar2 + 0xa8) + 1;
      }
      else if (iVar2 == 0) {
        iVar2 = param_2 * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(iVar2 + 0xa4) = *(int *)(iVar2 + 0xa4) + 1;
      }
      iVar2 = *(int *)(param_1 + 0x90);
    }
    if (0 < iVar2) {
      param_2 = param_2 * 0x5c;
      iVar2 = param_2 + *(int *)(DAT_003386b0 + 0xa0);
      *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + 1;
      if (*(int *)(param_1 + 0x90) == 1) {
        iVar2 = param_2 + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(iVar2 + 0x8c) = *(int *)(iVar2 + 0x8c) + 1;
        iVar2 = *(int *)(param_1 + 0x90);
      }
      else {
        iVar2 = *(int *)(param_1 + 0x90);
      }
      if (iVar2 == 2) {
        param_2 = param_2 + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(param_2 + 0x90) = *(int *)(param_2 + 0x90) + 1;
      }
    }
  }
  return;
}
// near miss from lane fm11 (unreviewed)
