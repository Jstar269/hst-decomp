/* HSTMATCH module=EBOOT.BIN start=0x002256b8 end=0x0022589c symbol=FUN_002256b8 lang=c99 */
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

extern undefined DAT_002eff8c;
extern undefined DAT_002eff8d;
extern undefined4 DAT_00310fc4;
extern undefined * DAT_0034a114;
extern undefined4 DAT_0034a678;
extern void FUN_00042ff4();
extern void FUN_000f6c48();
extern void FUN_001031e8();
extern undefined4 FUN_001cd2a8();
extern void FUN_0021ae88();
extern void FUN_0021b088();

void FUN_002256b8(int *param_1)
{
  int iVar1;
  int *piVar2;
  
  if (DAT_0034a678 == 0x20) {
    iVar1 = param_1[10];
  }
  else {
    if (DAT_0034a678 != 2) {
      return;
    }
    iVar1 = param_1[10];
  }
  if (*(int *)(iVar1 + 4) != 0xb) {
    FUN_0021ae88();
  }
  if (DAT_002eff8c == '\0') goto LAB_00225870;
  if (*(int *)(param_1[10] + 4) == 0xb) {
    (**(code **)(*(int *)*param_1 + 0x14))();
    (**(code **)(*(int *)param_1[8] + 0x14))();
    if (DAT_0034a114 != 0) {
      iVar1 = FUN_001cd2a8();
      if (iVar1 == 0) {
        (**(code **)(*(int *)param_1[1] + 0x14))();
      }
      goto LAB_002257f8;
    }
    piVar2 = (int *)param_1[2];
  }
  else {
    if (*(int *)(param_1[10] + 4) == 0) {
      FUN_0021b088(*param_1,*(int *)(DAT_0034a114 + 0xcc) + 1,*(int *)(DAT_0034a114 + 0xd0) + 1,1)
      ;
      piVar2 = (int *)*param_1;
      *(undefined1 *)(piVar2 + 0x17) = 1;
      (**(code **)(*piVar2 + 0x10))(piVar2);
      FUN_001031e8(piVar2);
      FUN_00042ff4(0x47c35000,DAT_00310fc4);
    }
LAB_002257f8:
    piVar2 = (int *)param_1[2];
  }
  (**(code **)(*piVar2 + 0x14))();
  (**(code **)(*(int *)param_1[3] + 0x14))();
  (**(code **)(*(int *)param_1[4] + 0x14))();
  (**(code **)(*(int *)param_1[6] + 0x14))();
  (**(code **)(*(int *)param_1[7] + 0x14))();
  (**(code **)(*(int *)param_1[9] + 0x14))();
LAB_00225870:
  if (DAT_002eff8d != '\0') {
    FUN_000f6c48(param_1[0xc]);
  }
  return;
}
// near miss from lane fm9 (unreviewed)
