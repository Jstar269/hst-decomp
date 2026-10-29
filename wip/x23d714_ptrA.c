/* HSTMATCH module=EBOOT.BIN start=0x0023d714 end=0x0023dab8 symbol=FUN_0023d714 lang=c99 */
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

extern undefined4 DAT_0034a77c;
extern void FUN_000ffb3c();
extern int FUN_0016b21c();
extern undefined4 FUN_00238d58();
extern bool FUN_0023a80c();
extern int FUN_0024dd40(float param_1,int param_2);

void FUN_0023d714(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  
  uVar1 = FUN_00238d58();
  iVar2 = FUN_0023a80c(uVar1);
  iVar10 = 0;
  iVar8 = param_1;
  do {
    FUN_000ffb3c(*(undefined4 *)(iVar8 + 0x798),1);
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 0x14;
  } while (iVar10 < 10);
  iVar10 = 0;
  iVar8 = 0;
  int *pa = (int *)(param_1 + 0x6bc);
  int *pb = (int *)(param_1 + 0x84c);
  do {
    iVar3 = FUN_0016b21c(iVar10);
    iVar3 = FUN_0024dd40(*(undefined4 *)(iVar3 + 4),DAT_0034a77c);
    if (iVar3 <= iVar8) {
      iVar3 = iVar8;
    }
    iVar10 = iVar10 + 1;
    iVar8 = iVar3;
  } while (iVar10 < 0xf);
  if (iVar3 < 2) {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0x6bc),1);
  }
  else {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0x6bc),0);
  }
  if (iVar3 < 6) {
    iVar10 = 0;
    iVar8 = 0;
    do {
      iVar4 = (int)pa;
      piVar11 = pa;
      iVar5 = (int)pb;
      piVar9 = pb;
      if (iVar10 < iVar3) {
        FUN_000ffb3c(*piVar11,0);
        if ((((iVar10 == 7) || (iVar10 == 6)) || (iVar10 == 4)) || ((iVar10 == 2 || (iVar10 == 1))))
        {
          if (iVar2 == 0) {
            iVar6 = *piVar11;
            iVar4 = (int)pa + iVar10;
            *(int *)(iVar6 + 0x24) = iVar4;
            *(int *)(iVar6 + 0x28) = iVar4;
          }
          else {
            iVar6 = *piVar11;
            iVar4 = (int)pa + iVar10 + 0xc;
            *(int *)(iVar6 + 0x24) = iVar4;
            *(int *)(iVar6 + 0x28) = iVar4;
          }
        }
        else {
          iVar6 = *piVar11;
          iVar4 = (int)pa + iVar10;
          *(int *)(iVar6 + 0x24) = iVar4;
          *(int *)(iVar6 + 0x28) = iVar4;
        }
        FUN_000ffb3c(*piVar9,0);
      }
      else {
        FUN_000ffb3c(*piVar11,1);
        FUN_000ffb3c(*piVar9,1);
      }
      if (iVar10 == 9) {
        uVar1 = *(int *)((char *)pb + 4);
LAB_0023da60:
        iVar4 = *piVar9;
        *(undefined4 *)(iVar4 + 0x24) = uVar1;
        *(undefined4 *)(iVar4 + 0x28) = uVar1;
      }
      else {
        if (((iVar10 == 7) || (iVar10 == 5)) || ((iVar10 == 4 || ((iVar10 == 2 || (iVar10 == 0))))))
        {
          uVar1 = *(int *)((char *)pb + 4);
          goto LAB_0023da60;
        }
        iVar4 = *piVar9;
        iVar5 = *(int *)((char *)pb + 4) + 1;
        *(int *)(iVar4 + 0x24) = iVar5;
        *(int *)(iVar4 + 0x28) = iVar5;
      }
      iVar10 = iVar10 + 1;
      iVar8 = iVar8 + 0x14;
      pa = (int *)((char *)pa + 0x14);
      pb = (int *)((char *)pb + 0x14);
    } while (iVar10 < 10);
  }
  else {
    uVar12 = 0;
    iVar8 = 0;
    do {
      iVar10 = (int)pa;
      piVar11 = pa;
      iVar4 = (int)pb;
      piVar9 = pb;
      if ((int)uVar12 < iVar3) {
        FUN_000ffb3c(*piVar11,0);
        if ((((uVar12 == 7) || (uVar12 == 6)) || (uVar12 == 4)) || ((uVar12 == 2 || (uVar12 == 1))))
        {
          if (iVar2 == 0) {
            iVar5 = *piVar11;
            iVar10 = (int)pa + uVar12;
            *(int *)(iVar5 + 0x24) = iVar10;
            *(int *)(iVar5 + 0x28) = iVar10;
          }
          else {
            iVar5 = *piVar11;
            iVar10 = (int)pa + uVar12 + 0xc;
            *(int *)(iVar5 + 0x24) = iVar10;
            *(int *)(iVar5 + 0x28) = iVar10;
          }
        }
        else {
          iVar5 = *piVar11;
          iVar10 = (int)pa + uVar12;
          *(int *)(iVar5 + 0x24) = iVar10;
          *(int *)(iVar5 + 0x28) = iVar10;
        }
        FUN_000ffb3c(*piVar9,0);
        uVar7 = uVar12 & 1;
        if (((int)uVar12 < 0) && (uVar7 != 0)) {
          uVar7 = uVar7 - 2;
        }
        if (uVar7 == 0) {
          uVar1 = *(int *)((char *)pb + 4);
          iVar10 = *piVar9;
          *(undefined4 *)(iVar10 + 0x24) = uVar1;
          *(undefined4 *)(iVar10 + 0x28) = uVar1;
        }
        else {
          iVar10 = *piVar9;
          iVar4 = *(int *)((char *)pb + 4) + 1;
          *(int *)(iVar10 + 0x24) = iVar4;
          *(int *)(iVar10 + 0x28) = iVar4;
        }
      }
      else {
        FUN_000ffb3c(*piVar11,1);
        FUN_000ffb3c(*piVar9,1);
      }
      uVar12 = uVar12 + 1;
      iVar8 = iVar8 + 0x14;
    } while ((int)uVar12 < 10);
  }
  return;
}
// near miss from lane dsn3 (unreviewed)
