/* HSTMATCH module=EBOOT.BIN start=0x001ac970 end=0x001acb5c symbol=FUN_001ac970 lang=c99 */
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

extern void FUN_000ffb3c();
extern void FUN_00103628();
extern void FUN_0010b6d4();
extern undefined4 FUN_0019d474();
extern void FUN_001acb5c();
extern void FUN_001acc30();
extern void FUN_001acf64();
extern void FUN_001ad350();
extern void FUN_001ad604();
extern void FUN_001ad89c();

void FUN_001ac970(int *param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  
  FUN_0010b6d4(param_1[0x245],0,5);
  FUN_00103628(*param_1);
  iVar1 = FUN_0019d474();
  iVar2 = FUN_0019d474();
  uVar7 = 0;
  if (*(int *)(iVar1 + 0x370) != 0) {
    iVar8 = 0;
    piVar9 = param_1;
    do {
      iVar5 = uVar7 * 4;
      if (*(int *)(*(int *)(iVar2 + 0x360) + iVar5) == 6) {
        uVar3 = *(uint *)(iVar1 + 0x370);
      }
      else {
        piVar4 = (int *)((int)param_1 + iVar8 + 0x9c);
        if (*(int *)(*(int *)(iVar1 + 0x36c) + iVar5) == 0) {
          FUN_000ffb3c(*piVar4,0);
          *(int *)piVar9[9] = piVar9[0xd];
        }
        else {
          FUN_000ffb3c(*piVar4,1);
          *(undefined4 *)piVar9[9] = 0x80808080;
        }
        if (*(int *)(*(int *)(iVar2 + 0x360) + iVar5) == 5) {
          iVar6 = 7;
          piVar4 = param_1 + 0x15;
          do {
            if (*(int *)(iVar5 + *(int *)(iVar1 + 0x36c)) == 0) {
              (**(code **)(*(int *)piVar4[0x21c] + 0x18))((int *)piVar4[0x21c],param_1[0x247]);
            }
            else {
              (**(code **)(*(int *)piVar4[0x21c] + 0x18))((int *)piVar4[0x21c],param_1[0x246]);
            }
            iVar6 = iVar6 + 1;
            piVar4 = piVar4 + 3;
          } while (iVar6 < 0xd);
        }
        uVar3 = *(uint *)(iVar1 + 0x370);
      }
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + 0x14;
      piVar9 = piVar9 + 5;
    } while (uVar7 < uVar3);
  }
  FUN_001acb5c((int)param_1,1);
  FUN_001acc30((int)param_1,'\0');
  FUN_001acf64((int)param_1,'\0');
  FUN_001ad350((int)param_1,'\0');
  FUN_001ad604((int)param_1,'\0');
  FUN_001ad89c((int)param_1,'\0');
  return;
}
// near miss from lane fm9 (unreviewed)
