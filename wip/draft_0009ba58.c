/* HSTMATCH module=EBOOT.BIN start=0x0009ba58 end=0x0009bbf0 symbol=FUN_0009ba58 lang=c99 */
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
extern void FUN_00093c7c();

void FUN_0009ba58(int param_1)
{
  int iVar1;
  int iVar2;
  float fVar3;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  undefined4 local_10;
  float local_14;
  undefined4 local_18;
  undefined4 local_1c;
  undefined4 local_20;
  
  local_14 = 1.0f;
  iVar2 = *(int *)(*(int *)(param_1 + 0x5bc) + 0x58);
  if (iVar2 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(iVar2 + 0xf0);
  }
  if ((0x43 < iVar1) && (iVar1 < 0x88)) {
    if (iVar2 == 0) {
      fVar3 = 0.0f;
    }
    else {
      fVar3 = *(float *)(iVar2 + 0x104);
    }
    if (fVar3 <= 5.0f) {
      local_14 = 0.0f;
      goto LAB_0009bb74;
    }
  }
  if ((0x87 < iVar1) && (iVar1 < 0x9e)) {
    local_14 = 0.0f;
    goto LAB_0009bb74;
  }
  if ((0x9d < iVar1) && (iVar1 < 0xf8)) {
    local_14 = 0.0f;
    goto LAB_0009bb74;
  }
  iVar2 = *(int *)(DAT_003386b0 + 0x3c);
  if (iVar2 == 4) {
    iVar2 = *(int *)(DAT_003386b0 + 0x88);
LAB_0009bb30:
    if ((*(int *)(iVar2 + 0x1d4) < 2) &&
       (*(float *)(param_1 + 0x588) - 5.0f <= *(float *)(param_1 + 0x5a8) * *(float *)(iVar2 + 0x18))
       ) goto LAB_0009bb74;
  }
  else if ((iVar2 == 7) || (iVar2 == 5)) {
    iVar2 = *(int *)(DAT_003386b0 + 0x88);
    goto LAB_0009bb30;
  }
  local_14 = -1.0f;
LAB_0009bb74:
  if (local_14 == 1.0f) {
    iVar2 = *(int *)(DAT_003386b0 + 0x88);
    local_10 = *(undefined4 *)(iVar2 + 0x10);
    local_c = *(undefined4 *)(iVar2 + 0x14);
    local_8 = *(undefined4 *)(iVar2 + 0x18);
    local_4 = *(undefined4 *)(iVar2 + 0x1c);
    FUN_00093c7c(*(undefined4 *)(param_1 + 0x5bc),&local_10);
  }
  else {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    FUN_00093c7c(*(undefined4 *)(param_1 + 0x5bc),&local_20);
  }
  return;
}
// near miss from lane fm9 (unreviewed)
