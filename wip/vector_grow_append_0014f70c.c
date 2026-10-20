/* HSTMATCH module=EBOOT.BIN start=0x0014f70c end=0x0014f948 symbol=FUN_0014f70c lang=c99 */
// NOT MATCHED (119/143 words, 141 differ, first at +0x0): the generated source has the right IDEA
// (need = p[1] + count - p[2]; overflow guard calling FUN_000043b4; 1.5x candidate `((cap+1)*3)/5`
// selected against `need` through a conditional pointer; grow via FUN_0014fabc(&tmp, newcap, 0); copy
// two words per element; then the two move-construct helpers and the final FUN_0014fa2c(&tmp,-1)).
// Retail's frame is 96 bytes with the temp vector at sp+76 (three words, zero-initialised in the order
// 76/80/84), the saved p[1] at sp+92, `base = p + 2` at sp+88, `need` at sp+56 and the 1.5x candidate at
// sp+52; the third argument of FUN_0014fabc is a `signed char` (retail emits `move v0,zero; andi 0xff;
// seb a2,v0`). Reproducing the full 143 words needs the whole slot order rebuilt from scratch.
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
extern undefined4 * FUN_00011090();
extern uint * FUN_000114c0();
extern int * FUN_0014fa2c();
extern void FUN_0014fabc(int *a, int b, signed char c);

void FUN_0014f70c(int *param_1,int param_2,undefined4 *param_3)
{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
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
  uVar5 = param_1[2];
  if (0x1fffffff - uVar5 < local_28[0]) {
    FUN_000043b4();
  }
  if (uVar5 < 0xaaaaaaa) {
    local_2c = ((uVar5 + 1) * 3) / 5;
    if (local_2c < local_28[0]) {
      puVar1 = local_28;
    }
    else {
      puVar1 = &local_2c;
    }
    iVar4 = uVar5 + *puVar1;
  }
  else if (uVar5 < 0x15555554) {
    local_30 = uVar5 + 1 >> 1;
    if (local_30 < local_28[0]) {
      puVar1 = local_28;
    }
    else {
      puVar1 = &local_30;
    }
    iVar4 = uVar5 + *puVar1;
  }
  else {
    iVar4 = 0x1fffffff;
  }
  FUN_0014fabc(&local_14,iVar4,0);
  local_4 = param_1[1];
  puVar2 = (undefined4 *)(local_14 + local_4 * 8 + local_10 * 8);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = *param_3;
      puVar2[1] = param_3[1];
    }
    puVar2 = puVar2 + 2;
    local_10 = local_10 + 1;
  }
  iVar6 = *param_1;
  iVar4 = param_1[1] * 8;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 7;
  }
  iVar4 = iVar4 >> 3;
  local_4 = local_4 - iVar4;
  FUN_00011090(local_14 + local_4 * 8,iVar6,iVar4 << 3);
  FUN_000114c0(iVar6,0,iVar4 << 3);
  iVar4 = local_10 + iVar4;
  param_1[1] = 0;
  iVar6 = param_1[2];
  param_1[2] = local_c;
  iVar3 = *param_1;
  *param_1 = local_14;
  local_10 = param_1[1];
  param_1[1] = iVar4;
  local_14 = iVar3;
  local_c = iVar6;
  FUN_0014fa2c(&local_14,0xffffffff);
  return;
}
// near miss from lane ds1 (unreviewed)
