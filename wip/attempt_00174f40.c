/* HSTMATCH module=EBOOT.BIN start=0x00174f40 end=0x0017523c symbol=FUN_00174f40 lang=c99 */
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

extern void * DAT_00338b08;
extern int FUN_000d8c24();
extern undefined2 FUN_0017951c();

bool FUN_00174f40(undefined4 param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4, int param_5,int param_6)
{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  bVar2 = false;
  uVar3 = FUN_0017951c(param_1,0);
  iVar4 = FUN_0017951c(param_1,2);
  iVar5 = FUN_0017951c(param_1,3);
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  if (param_5 == 3) {
    iVar5 = FUN_000d8c24(DAT_00338b08,1,uVar3);
    iVar6 = FUN_000d8c24(DAT_00338b08,3,iVar4);
    iVar7 = FUN_000d8c24(DAT_00338b08,4,param_6);
    iVar8 = ((int)*(char *)(iVar7 + 99) << 0x1a) >> 0x1a;
    if (0 < iVar8) {
      bVar2 = iVar8 == ((int)*(char *)(iVar5 + 99) << 0x1a) >> 0x1a;
      if (bVar2) {
        *param_2 = 1;
        cVar1 = *(char *)(iVar7 + 99);
      }
      else {
        cVar1 = *(char *)(iVar7 + 99);
      }
      if (((int)cVar1 << 0x1a) >> 0x1a == ((int)*(char *)(iVar6 + 99) << 0x1a) >> 0x1a) {
        *param_3 = 1;
        bVar2 = true;
      }
    }
    if ((param_6 != 0) && (param_6 == iVar4)) {
      *param_3 = 1;
      bVar2 = true;
    }
  }
  else if (param_5 == 2) {
    iVar4 = FUN_000d8c24(DAT_00338b08,1,uVar3);
    iVar6 = FUN_000d8c24(DAT_00338b08,3,param_6);
    iVar7 = FUN_000d8c24(DAT_00338b08,4,iVar5);
    iVar8 = ((int)*(char *)(iVar6 + 99) << 0x1a) >> 0x1a;
    if (0 < iVar8) {
      bVar2 = iVar8 == ((int)*(char *)(iVar4 + 99) << 0x1a) >> 0x1a;
      if (bVar2) {
        *param_2 = 1;
        cVar1 = *(char *)(iVar6 + 99);
      }
      else {
        cVar1 = *(char *)(iVar6 + 99);
      }
      if (((int)cVar1 << 0x1a) >> 0x1a == ((int)*(char *)(iVar7 + 99) << 0x1a) >> 0x1a) {
        *param_4 = 1;
        bVar2 = true;
      }
    }
    if ((param_6 != 0) && (param_6 == iVar5)) {
      *param_4 = 1;
      bVar2 = true;
    }
  }
  else if (param_5 == 0) {
    iVar6 = FUN_000d8c24(DAT_00338b08,1,param_6);
    iVar4 = FUN_000d8c24(DAT_00338b08,3,iVar4);
    iVar5 = FUN_000d8c24(DAT_00338b08,4,iVar5);
    iVar7 = ((int)*(char *)(iVar6 + 99) << 0x1a) >> 0x1a;
    if (0 < iVar7) {
      bVar2 = iVar7 == ((int)*(char *)(iVar4 + 99) << 0x1a) >> 0x1a;
      if (bVar2) {
        *param_3 = 1;
        cVar1 = *(char *)(iVar6 + 99);
      }
      else {
        cVar1 = *(char *)(iVar6 + 99);
      }
      if (((int)cVar1 << 0x1a) >> 0x1a == ((int)*(char *)(iVar5 + 99) << 0x1a) >> 0x1a) {
        *param_4 = 1;
        bVar2 = true;
      }
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}
// near miss from lane km4 (unreviewed)
