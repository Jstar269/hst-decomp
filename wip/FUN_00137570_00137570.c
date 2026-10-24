/* HSTMATCH module=EBOOT.BIN start=0x00137570 end=0x00137840 symbol=FUN_00137570 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned int uint;

extern int FUN_00000bcc();
extern int FUN_0023ed34();
extern void FUN_0023fe08(int, int, int, int, float, float, int, int);
extern void FUN_0013ca84();
extern void FUN_0001f21c();
extern int FUN_0024b5a0();
extern void FUN_0024ba68();
extern void FUN_0013cb30();

void FUN_00137570(int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_40[8];
  int local_8;
  int local_4;

  uVar3 = 0;
  if (*(int *)(param_1 + 0x13d0) != 0) {
    do {
      iVar1 = FUN_00000bcc(0x330);
      if (iVar1 == 0) {
        local_4 = 0;
      }
      else {
        local_4 = FUN_0023ed34(iVar1, *(undefined4 *)(*(int *)(param_1 + 0x13cc) + uVar3 * 0x24));
      }
      iVar1 = *(int *)(param_1 + 0x13cc) + uVar3 * 0x24;
      FUN_0023fe08(local_4, *(undefined4 *)(iVar1 + 4), *(undefined4 *)(iVar1 + 8),
                   *(undefined4 *)(iVar1 + 0xc), *(float *)(iVar1 + 0x10),
                   *(float *)(iVar1 + 0x14), *(undefined4 *)(iVar1 + 0x18),
                   *(undefined4 *)(iVar1 + 0x1c));
      if (*(int *)(*(int *)(param_1 + 0x13cc) + uVar3 * 0x24 + 0x20) == 0) {
        uVar2 = *(uint *)(param_1 + 0x139c);
      }
      else {
        *(undefined1 *)(local_4 + 0x3c) = 1;
        *(undefined1 *)(local_4 + 0x3d) = 1;
        *(undefined1 *)(local_4 + 0x301) = 1;
        uVar2 = *(uint *)(param_1 + 0x139c);
      }
      if (uVar2 < *(uint *)(param_1 + 0x13a0)) {
        *(uint *)(param_1 + 0x139c) = uVar2 + 1;
        *(int *)(*(int *)(param_1 + 0x1398) + (uVar2 + 1) * 4 + -4) = local_4;
      }
      else {
        FUN_0013ca84(param_1 + 0x1398, &local_4, 0);
      }
      FUN_0001f21c(param_1, local_4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x13d0));
  }
  iVar1 = FUN_00000bcc(0x280);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0024b5a0(iVar1, 0xb);
  }
  local_40[0] = 0xc1400000;
  local_40[1] = 0xc111eb85;
  local_40[2] = 0xc111eb85;
  local_40[3] = 0x3f800000;
  local_40[4] = 0x41400000;
  local_40[5] = 0;
  local_40[6] = 0xc111eb85;
  local_40[7] = 0x3f800000;
  FUN_0024ba68(local_8, &local_40[4], &local_40[0]);
  uVar4 = *(undefined4 *)(param_1 + 0x1354);
  *(undefined4 *)(local_8 + 0x24c) = *(undefined4 *)(param_1 + 0x1350);
  *(undefined4 *)(local_8 + 0x250) = uVar4;
  uVar3 = *(uint *)(param_1 + 0x13a8);
  if (uVar3 < *(uint *)(param_1 + 0x13ac)) {
    *(uint *)(param_1 + 0x13a8) = uVar3 + 1;
    *(int *)(*(int *)(param_1 + 0x13a4) + uVar3 * 4) = local_8;
  }
  else {
    FUN_0013cb30(param_1 + 0x13a4, &local_8, 0);
  }
  FUN_0001f21c(param_1, local_8);
  iVar1 = FUN_00000bcc(0x280);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_0024b5a0(iVar1, 0xc);
  }
  local_40[0] = 0xc1400000;
  local_40[1] = 0xc111eb85;
  local_40[2] = 0xc111eb85;
  local_40[3] = 0x3f800000;
  local_40[4] = 0x41400000;
  local_40[5] = 0xc0400000;
  local_40[6] = 0xc111eb85;
  local_40[7] = 0x3f800000;
  FUN_0024ba68(local_8, &local_40[4], &local_40[0]);
  uVar4 = *(undefined4 *)(param_1 + 0x1354);
  *(undefined4 *)(local_8 + 0x24c) = *(undefined4 *)(param_1 + 0x1350);
  *(undefined4 *)(local_8 + 0x250) = uVar4;
  uVar3 = *(uint *)(param_1 + 0x13a8);
  if (uVar3 < *(uint *)(param_1 + 0x13ac)) {
    *(uint *)(param_1 + 0x13a8) = uVar3 + 1;
    *(int *)(*(int *)(param_1 + 0x13a4) + uVar3 * 4) = local_8;
  }
  else {
    FUN_0013cb30(param_1 + 0x13a4, &local_8, 0);
  }
  FUN_0001f21c(param_1, local_8);
  return;
}
// near miss from lane fm10 (unreviewed)
