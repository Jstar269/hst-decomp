/* HSTMATCH module=EBOOT.BIN start=0x0005e05c end=0x0005e2c0 symbol=FUN_0005e05c lang=c99 */
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

extern void FUN_000043b4();
extern int * FUN_0005e748();
extern void FUN_0005e954();

void FUN_0005e05c(int *param_1,int param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int local_4;
  int *local_8;
  int local_c;
  int local_10;
  int local_14;
  uint local_28 [5];
  uint local_2c;
  uint local_30;
  
  local_8 = param_1 + 2;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_4 = 0;
  local_28[0] = (param_1[1] + param_2) - param_1[2];
  uVar9 = param_1[2];
  if (0x15555555 - uVar9 < local_28[0]) {
    FUN_000043b4();
  }
  if (uVar9 < 0x71c71c7) {
    local_2c = ((uVar9 + 1) * 3) / 5;
    if (local_2c < local_28[0]) {
      puVar2 = local_28;
    }
    else {
      puVar2 = &local_2c;
    }
    iVar7 = uVar9 + *puVar2;
  }
  else if (uVar9 < 0xe38e38e) {
    local_30 = uVar9 + 1 >> 1;
    if (local_30 < local_28[0]) {
      puVar2 = local_28;
    }
    else {
      puVar2 = &local_30;
    }
    iVar7 = uVar9 + *puVar2;
  }
  else {
    iVar7 = 0x15555555;
  }
  FUN_0005e954(&local_14,iVar7,0);
  local_4 = param_1[1];
  puVar3 = (undefined4 *)(local_14 + local_4 * 0xc + local_10 * 0xc);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *param_3;
      puVar3[1] = param_3[1];
      puVar3[2] = param_3[2];
    }
    puVar3 = puVar3 + 3;
    local_10 = local_10 + 1;
  }
  puVar8 = (undefined4 *)*param_1;
  puVar3 = puVar8 + param_1[1] * 3;
  puVar1 = (undefined4 *)(local_14 + local_4 * 0xc);
  iVar7 = local_10;
  while (puVar8 < puVar3) {
    puVar6 = puVar1 + -3;
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = puVar3[-3];
      puVar1[-2] = puVar3[-2];
      puVar1[-1] = puVar3[-1];
    }
    local_4 = local_4 + -1;
    iVar7 = iVar7 + 1;
    puVar3 = puVar3 + -3;
    puVar1 = puVar6;
  }
  iVar4 = param_1[2];
  param_1[2] = local_c;
  iVar5 = *param_1;
  *param_1 = local_14;
  local_10 = param_1[1];
  param_1[1] = iVar7;
  local_14 = iVar5;
  local_c = iVar4;
  FUN_0005e748(&local_14,0xffffffff);
  return;
}
// near miss from lane fm11 (unreviewed)
