/* HSTMATCH module=EBOOT.BIN start=0x00250f68 end=0x0025112c symbol=FUN_00250f68 lang=c99 */
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

extern undefined DAT_002fc4e0;
extern undefined4 DAT_002fc518;
extern undefined8 FUN_0000c07c();
extern undefined4 FUN_00022178();
extern uint FUN_00022254();
extern void FUN_000ffb3c();

void FUN_00250f68(int param_1,int param_2,int param_3)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined8 uVar7;
  
  if (param_3 == 0) {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0xbc),1);
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0xac),1);
    iVar4 = 0;
    do {
      FUN_000ffb3c(*(undefined4 *)(param_1 + 0xb0),1);
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 4;
    } while (iVar4 < 3);
  }
  else if (param_2 < 0) {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0xbc),0);
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0xac),1);
    uVar2 = DAT_002fc518;
    iVar6 = 0;
    iVar4 = *(int *)(param_1 + 0xac);
    puVar5 = (unsigned int *)(&DAT_002fc4e0);
    *(undefined4 *)(iVar4 + 0x24) = DAT_002fc518;
    *(undefined4 *)(iVar4 + 0x28) = uVar2;
    do {
      FUN_000ffb3c(*(undefined4 *)(param_1 + 0xb0),0);
      iVar3 = puVar5[0x11];
      iVar4 = *(int *)(param_1 + 0xb0);
      iVar6 = iVar6 + 1;
      *(int *)(iVar4 + 0x24) = iVar3 + 10;
      *(int *)(iVar4 + 0x28) = iVar3 + 10;
      param_1 = param_1 + 4;
      puVar5 = puVar5 + 3;
    } while (iVar6 < 3);
  }
  else {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0xbc),0);
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0xac),1);
    uVar2 = DAT_002fc518;
    iVar6 = 0;
    iVar4 = *(int *)(param_1 + 0xac);
    puVar5 = (unsigned int *)(&DAT_002fc4e0);
    *(undefined4 *)(iVar4 + 0x24) = DAT_002fc518;
    *(undefined4 *)(iVar4 + 0x28) = uVar2;
    do {
      uVar7 = FUN_00022178(2 - iVar6);
      uVar7 = FUN_0000c07c(0,0x40240000,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      iVar4 = FUN_00022254((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      if (param_2 < iVar4) {
        uVar2 = *(undefined4 *)(param_1 + 0xb0);
      }
      else {
        uVar2 = *(undefined4 *)(param_1 + 0xb0);
      }
      FUN_000ffb3c(uVar2,param_2 < iVar4 && iVar6 != 2);
      piVar1 = (int *)(puVar5 + 0x11);
      iVar3 = *(int *)(param_1 + 0xb0);
      iVar6 = iVar6 + 1;
      param_1 = param_1 + 4;
      puVar5 = puVar5 + 3;
      iVar4 = *piVar1 + (param_2 / iVar4) % 10;
      *(int *)(iVar3 + 0x24) = iVar4;
      *(int *)(iVar3 + 0x28) = iVar4;
    } while (iVar6 < 3);
  }
  return;
}
// near miss from lane fm9 (unreviewed)
