/* HSTMATCH module=EBOOT.BIN start=0x0006d2b0 end=0x0006d624 symbol=FUN_0006d2b0 lang=c99 */
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
extern int * FUN_0006d798();
extern void FUN_0006d828();

void FUN_0006d2b0(int *param_1,int param_2,undefined2 *param_3)
{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  uint *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
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
  uVar11 = param_1[2];
  if (0x6666666 - uVar11 < local_28[0]) {
    FUN_000043b4();
  }
  if (uVar11 < 0x2222222) {
    local_2c = ((uVar11 + 1) * 3) / 5;
    if (local_2c < local_28[0]) {
      puVar4 = local_28;
    }
    else {
      puVar4 = &local_2c;
    }
    iVar10 = uVar11 + *puVar4;
  }
  else if (uVar11 < 0x4444444) {
    local_30 = uVar11 + 1 >> 1;
    if (local_30 < local_28[0]) {
      puVar4 = local_28;
    }
    else {
      puVar4 = &local_30;
    }
    iVar10 = uVar11 + *puVar4;
  }
  else {
    iVar10 = 0x6666666;
  }
  FUN_0006d828(&local_14,iVar10,0);
  local_4 = param_1[1];
  puVar5 = (undefined2 *)(local_14 + local_4 * 0x28 + local_10 * 0x28);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (puVar5 != (undefined2 *)0x0) {
      *puVar5 = *param_3;
      puVar5[1] = param_3[1];
      puVar5[2] = param_3[2];
      puVar5[3] = param_3[3];
      puVar5[4] = param_3[4];
      uVar1 = param_3[6];
      puVar5[5] = param_3[5];
      puVar5[6] = uVar1;
      uVar1 = param_3[8];
      puVar5[7] = param_3[7];
      puVar5[8] = uVar1;
      uVar1 = param_3[10];
      uVar2 = param_3[0xb];
      puVar5[9] = param_3[9];
      puVar5[10] = uVar1;
      puVar5[0xb] = uVar2;
      uVar1 = param_3[0xd];
      uVar2 = param_3[0xe];
      puVar5[0xc] = param_3[0xc];
      puVar5[0xd] = uVar1;
      puVar5[0xe] = uVar2;
      uVar1 = param_3[0x10];
      puVar5[0xf] = param_3[0xf];
      puVar5[0x10] = uVar1;
      puVar5[0x11] = param_3[0x11];
      puVar5[0x12] = param_3[0x12];
      puVar5[0x13] = param_3[0x13];
    }
    puVar5 = puVar5 + 0x14;
    local_10 = local_10 + 1;
  }
  puVar6 = (undefined2 *)*param_1;
  puVar5 = puVar6 + param_1[1] * 0x14;
  puVar3 = (undefined2 *)(local_14 + local_4 * 0x28);
  iVar10 = local_10;
  while (puVar6 < puVar5) {
    puVar7 = puVar3 + -0x14;
    if (puVar7 != (undefined2 *)0x0) {
      *puVar7 = puVar5[-0x14];
      puVar3[-0x13] = puVar5[-0x13];
      puVar3[-0x12] = puVar5[-0x12];
      puVar3[-0x11] = puVar5[-0x11];
      puVar3[-0x10] = puVar5[-0x10];
      uVar1 = puVar5[-0xe];
      puVar3[-0xf] = puVar5[-0xf];
      puVar3[-0xe] = uVar1;
      uVar1 = puVar5[-0xc];
      puVar3[-0xd] = puVar5[-0xd];
      puVar3[-0xc] = uVar1;
      uVar1 = puVar5[-10];
      uVar2 = puVar5[-9];
      puVar3[-0xb] = puVar5[-0xb];
      puVar3[-10] = uVar1;
      puVar3[-9] = uVar2;
      uVar1 = puVar5[-7];
      uVar2 = puVar5[-6];
      puVar3[-8] = puVar5[-8];
      puVar3[-7] = uVar1;
      puVar3[-6] = uVar2;
      uVar1 = puVar5[-4];
      puVar3[-5] = puVar5[-5];
      puVar3[-4] = uVar1;
      puVar3[-3] = puVar5[-3];
      puVar3[-2] = puVar5[-2];
      puVar3[-1] = puVar5[-1];
    }
    local_4 = local_4 + -1;
    iVar10 = iVar10 + 1;
    puVar5 = puVar5 + -0x14;
    puVar3 = puVar7;
  }
  iVar8 = param_1[2];
  param_1[2] = local_c;
  iVar9 = *param_1;
  *param_1 = local_14;
  local_10 = param_1[1];
  param_1[1] = iVar10;
  local_14 = iVar9;
  local_c = iVar8;
  FUN_0006d798(&local_14,0xffffffff);
  return;
}
// near miss from lane fm11 (unreviewed)
