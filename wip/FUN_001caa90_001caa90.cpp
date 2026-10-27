/* HSTMATCH module=EBOOT.BIN start=0x001caa90 end=0x001cad08 symbol=FUN_001caa90 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined * DAT_0033b574;
extern void FUN_000149a8(void *, undefined4);
extern uint * FUN_0014c354(void *, int);
extern uint * FUN_0014c384(void *, int);
extern void FUN_0014c3ac(void *, int, int);
extern undefined4 FUN_0014c3d8(void *, int);
extern char * FUN_0022a930();
extern void FUN_0022aae8(int,int,int,int,int);
extern int FUN_0022ab44(undefined4, undefined4, int);
extern int FUN_0022acf0(undefined4, undefined4, undefined1);
extern int FUN_0022ad48(undefined4, undefined4, undefined1);
extern int FUN_0022c84c();

void FUN_001caa90(char *param_1)
{
  undefined1 uVar1;
  char *ctx;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar11;
  undefined4 uVar10;
  int iVar9;
  bool uVar8;
  void *uVar7;
  bool small;
  int iVar12;
  undefined4 uVar13;
  int local_4;
  int local_8;
  int local_c;
  int local_10;
  
  uVar8 = 0;
  ctx = FUN_0022a930();
  small = *(int *)(ctx + 0xab44) < 3;
  if (small) {
    uVar8 = 0;
  }
  else {
    ctx = FUN_0022a930();
    uVar8 = (bool)(*(int *)(ctx + 0xab44) < 6);
  }
  *(undefined1 *)(param_1 + 0xf3) = 1;
  ctx = FUN_0022a930();
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(ctx + 0xab2c);
  uVar3 = FUN_0022c84c();
  FUN_000149a8(param_1 + 0x124,uVar3);
  FUN_0022a930();
  ctx = FUN_0022a930();
  uVar11 = *(undefined4 *)(ctx + 0xab30);
  ctx = FUN_0022a930();
  uVar10 = *(undefined4 *)(ctx + 0xab34);
  ctx = FUN_0022a930();
  iVar9 = *(int *)(ctx + 0xab38);
  ctx = FUN_0022a930();
  uVar13 = *(undefined4 *)(ctx + 0xab3c);
  uVar7 = *(void **)(DAT_0033b574 + 0x1324);
  puVar4 = (uint *)FUN_0014c354(uVar7,0);
  *puVar4 = uVar8;
  uVar3 = FUN_0014c3d8(uVar7,0xf);
  puVar5 = (undefined4 *)FUN_0014c384(uVar7,8);
  *puVar5 = uVar3;
  FUN_0014c3ac(uVar7,0xf,0);
  ctx = FUN_0022a930();
  iVar12 = *(int *)(ctx + 0xab44);
  ctx = FUN_0022a930();
  local_4 = *(int *)(ctx + 0xab48);
  ctx = FUN_0022a930();
  uVar1 = *(undefined1 *)(ctx + 0xab4e);
  iVar2 = FUN_0022ab44(uVar11,uVar10,0);
  if (uVar8 == 0) {
    *(undefined1 *)(param_1 + 0xf5) = 0;
  }
  else {
    *(bool *)(param_1 + 0xf5) = iVar2 + -1 < 3 || 5 < iVar2 + -1;
  }
  local_c = iVar12 + 1;
  local_8 = FUN_0022acf0(uVar11,uVar10,uVar1);
  if (local_8 < local_c) {
    piVar6 = &local_c;
  }
  else {
    piVar6 = &local_8;
  }
  iVar2 = *piVar6;
  local_10 = FUN_0022ad48(uVar11,uVar10,uVar1);
  if (local_10 < local_4) {
    piVar6 = &local_4;
  }
  else {
    piVar6 = &local_10;
  }
  local_4 = *piVar6;
  FUN_0022aae8(uVar11,iVar2,local_4,uVar10,uVar1);
  if (-1 < iVar9) {
    FUN_0022aae8(iVar9,iVar2,local_4,uVar13,uVar1);
  }
  return;
}
// Near miss: 125 of 158 words differ, chiefly in accessor-call scheduling and the first range-test block.
// Ruled out pointer/struct field access, bool/int flag widths, if/switch/goto forms, and duplicated flag stores.
// near miss from lane km5 (unreviewed)

}  /* extern "C" */
// improved by lane dsm1 (unreviewed): no comparable result -> 125 differing words
