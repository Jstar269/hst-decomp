/* HSTMATCH module=EBOOT.BIN start=0x001cc354 end=0x001cc510 symbol=FUN_001cc354 lang=c99 */
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

extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern float DAT_0034a10c;
extern char DAT_002eab78[];
extern void FUN_000143b0();
extern void FUN_0018a950();
extern undefined1 * FUN_0018c9f4();
extern void FUN_001cd88c();
extern undefined4 FUN_00229470();
extern undefined * FUN_002294f4();
extern undefined4 FUN_002297d8();

void FUN_001cc354(int param_1,undefined4 param_2)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  undefined1 auStack_100 [256];
  
  iVar2 = (int)(FUN_0018c9f4(0xc));
  iVar3 = *(int *)(param_1 + 0xc0);
  if (*(int *)(iVar2 + 4) == 0) {
    puVar4 = &DAT_002c0e20;
  }
  else if (*(int *)(*(int *)(iVar2 + 8) + 8) < 1) {
    puVar4 = &DAT_002c0e1c;
  }
  else if ((iVar3 < 0) || ((*(int **)(iVar2 + 0xc))[1] <= iVar3)) {
    puVar4 = &DAT_002c0e18;
  }
  else {
    puVar4 = *(undefined **)(**(int **)(iVar2 + 0xc) + iVar3 * 4);
  }
  FUN_000143b0(auStack_100,DAT_002eab78,param_2);
  FUN_00229470(*(int *)(param_1 + 0x15c) + 0x34,*(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x24),
               auStack_100);
  DAT_0034a10c = DAT_0034a10c * 0x343fd + 0x269ec3;
  iVar3 = *(int *)(param_1 + 0x15c);
  iVar2 = (int)(FUN_002294f4(iVar3 + 0x34,*(undefined4 *)(iVar3 + 0x24),auStack_100,0));
  if (iVar2 != 0) {
    *(undefined1 *)(iVar3 + 99) = 0;
    *(undefined1 *)(iVar3 + 100) = 0;
    *(int *)(iVar3 + 0x68) = iVar2;
    *(undefined4 *)(iVar3 + 0x6c) = 0;
    *(undefined4 *)(iVar3 + 0x70) = 0;
    FUN_0018a950(*(undefined4 *)(iVar3 + 0x20),puVar4);
    FUN_001cd88c(iVar3,2,1);
  }
  *(undefined4 *)(iVar3 + 0x74) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x78) = 0xffffffff;
  FUN_002297d8(iVar3 + 0x34,auStack_100,0);
  piVar5 = *(int **)(param_1 + 0x98);
  if (piVar5 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar5 + 0x34))(piVar5);
    bVar1 = iVar2 == 2;
    if (!bVar1) {
      iVar2 = (**(code **)(*piVar5 + 0x34))(piVar5);
      bVar1 = iVar2 == 3;
    }
    if (bVar1) {
      *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x5c) = *(undefined4 *)(param_1 + 0x98);
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)
