/* HSTMATCH module=EBOOT.BIN start=0x0026b850 end=0x0026bc68 symbol=FUN_0026b850 lang=c99 */
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

extern undefined * DAT_002cfc8c;
extern undefined4 DAT_003386c8;
extern undefined * DAT_003415ac;
extern undefined4 DAT_0034a120;
extern int * DAT_0034b328;
extern int FUN_00000bcc();
extern void FUN_0001f21c();
extern undefined4 FUN_0008d994();
extern void FUN_00103128();
extern void FUN_00103628();
extern void FUN_0010b6d4();
extern void FUN_0010b8cc();
extern undefined1 FUN_001155c0();
extern undefined4 FUN_001b1c44();
extern void FUN_001b3ce8();
extern void FUN_001b3ea4();
extern undefined4 * FUN_0029a8bc();
extern void FUN_0029dfdc();
extern bool FUN_0029e0e0();
extern undefined4 FUN_0029e0fc();

void FUN_0026b850(int *param_1)
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = (**(code **)(*param_1 + 0x28))();
  if (iVar1 != 0) {
    iVar1 = param_1[0x17];
    if (iVar1 == 0) {
      if (((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) == 0) &&
         (iVar1 = FUN_001155c0(), iVar1 != 0)) {
        FUN_00103628(DAT_003415ac,1);
      }
      FUN_00103128(param_1);
      iVar1 = *(int *)(param_1[0x16] + 0xdc);
      if (*(char *)(param_1[0x16] + 0xea) == '\0') {
        iVar4 = param_1[0x16];
      }
      else {
        FUN_001b1c44(0x34179c,1);
        iVar4 = param_1[0x16];
      }
      if (*(char *)(iVar4 + 0xe8) == '\0') {
        if ((*(char *)(iVar4 + 0xea) == '\0') &&
           (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1a) >> 0x1e == 0)) {
          FUN_001b1c44(0x34179c,4);
          if (param_1[0x1a] == 0) {
            *(undefined1 *)(param_1 + 0x15) = 0;
          }
          else if (param_1[0x1a] == 1) {
            (**(code **)(*(int *)param_1[0x18] + 0xc))((int *)param_1[0x18],0);
            (**(code **)(*(int *)param_1[0x19] + 0xc))((int *)param_1[0x19],1);
            (**(code **)(*(int *)param_1[0x16] + 0xc))((int *)param_1[0x16],0);
            (**(code **)(*(int *)param_1[0x16] + 0x30))();
            FUN_0010b6d4(param_1[0x16],0,1);
            (**(code **)(*(int *)param_1[0x16] + 0x20))(0x453b9000);
            param_1[0x1a] = 0;
            FUN_0010b8cc(param_1[0x16],1,0);
          }
        }
      }
      else {
        if (iVar1 == 0) {
          FUN_001b1c44(0x34179c,3);
          param_1[0x17] = 1;
          (**(code **)(*(int *)param_1[0x16] + 0xc))();
          FUN_001b3ea4(0x3f000000,0x34179c);
          param_1[0x1b] = 0;
        }
        else if (param_1[0x1a] == 0) {
          FUN_001b1c44(0x34179c,3);
          (**(code **)(*(int *)param_1[0x18] + 0xc))((int *)param_1[0x18],1);
          (**(code **)(*(int *)param_1[0x19] + 0xc))((int *)param_1[0x19],0);
          (**(code **)(*(int *)param_1[0x16] + 0xc))((int *)param_1[0x16],1);
          param_1[0x1a] = 1;
        }
        else {
          FUN_001b1c44(0x34179c,4);
          *(undefined1 *)(param_1 + 0x15) = 0;
        }
        *(undefined1 *)(param_1[0x16] + 0xe8) = 0;
      }
    }
    else if (iVar1 == 1) {
      if (0x27 < param_1[0x1b]) {
        param_1[0x17] = 2;
        iVar1 = FUN_00000bcc(0x40);
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (unsigned int)(FUN_0029a8bc(iVar1));
        }
        FUN_0001f21c(DAT_0034a120,uVar2);
        FUN_0029dfdc(DAT_0034b328);
      }
    }
    else if (((iVar1 == 2) && (DAT_0034b328 != (int *)0x0)) && (iVar1 = FUN_0029e0e0(), iVar1 == 0)
            ) {
      iVar1 = FUN_0029e0fc(DAT_0034b328);
      if (iVar1 == 1) {
        *(undefined1 *)((int)param_1 + 0x55) = 1;
      }
      else {
        param_1[0x17] = 0;
        *(undefined1 *)((int)param_1 + 0x55) = 0;
        (**(code **)(*(int *)param_1[0x18] + 0xc))((int *)param_1[0x18],0);
        (**(code **)(*(int *)param_1[0x19] + 0xc))((int *)param_1[0x19],1);
        (**(code **)(*(int *)param_1[0x16] + 0xc))((int *)param_1[0x16],0);
        (**(code **)(*(int *)param_1[0x16] + 0x30))();
        FUN_0010b6d4(param_1[0x16],0,1);
        (**(code **)(*(int *)param_1[0x16] + 0x20))(0x453b9000);
        param_1[0x1a] = 0;
      }
      if (DAT_0034b328 != (int *)0x0) {
        if (DAT_0034b328 != (int *)0x0) {
          (**(code **)(*DAT_0034b328 + 8))(DAT_0034b328,1);
        }
        DAT_0034b328 = (int *)0x0;
      }
      FUN_001b3ce8(0x34179c,1);
    }
    piVar3 = (int *)FUN_0008d994(DAT_003386c8);
    (**(code **)(*piVar3 + 0x10))(piVar3);
    param_1[0x1b] = param_1[0x1b] + 1;
  }
  return;
}
// near miss from lane fm11 (unreviewed)
