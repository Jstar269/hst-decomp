/* HSTMATCH module=EBOOT.BIN start=0x0022f9f4 end=0x0022fc38 symbol=FUN_0022f9f4 lang=c99 rodata=0x002c9bd8 */
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
extern undefined4 DAT_003415ac;
extern undefined4 DAT_003415d4;
extern undefined4 DAT_0034a818;
extern undefined * DAT_0034b350;
extern void FUN_00103128();
extern void FUN_00103628();
extern undefined1 FUN_001155c0();
extern bool FUN_00190724();
extern int FUN_001b1f7c();
extern int FUN_001b2bc0();
extern void FUN_001b40d8();
extern void FUN_001b4104();
extern void FUN_0022d49c();
extern void FUN_0022da30();
extern void FUN_0022fcdc();
extern void FUN_0023028c();
extern undefined1 FUN_002911c0();
extern undefined4 FUN_002911cc();
extern void FUN_002a4d40();

void FUN_0022f9f4(int param_1)
{
  int iVar1;
  int *piVar2;
  
  FUN_00103128();
  switch(*(undefined4 *)(param_1 + 0x414)) {
  case 0:
    FUN_0023028c(param_1);
    break;
  case 1:
    FUN_0022da30(param_1);
    break;
  case 2:
    FUN_0022d49c(param_1);
    break;
  case 3:
    FUN_0023028c(param_1);
    break;
  case 4:
    iVar1 = FUN_001b1f7c(0x34179c,*(undefined4 *)(param_1 + 0xb0));
    if ((iVar1 == 0) && (-1 < *(int *)(param_1 + 0xac))) {
      iVar1 = FUN_001b2bc0(0x34179c,param_1 + 0xac);
      *(int *)(param_1 + 0xb0) = iVar1;
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0xac) = 0xffffffff;
        FUN_0022fcdc(param_1,0);
      }
    }
    FUN_0023028c(param_1);
    break;
  case 5:
    iVar1 = FUN_002911c0(DAT_0034a818);
    if (((iVar1 == 0) || (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0)) ||
       (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1a) >> 0x1e == 0)) {
      FUN_002911cc(DAT_0034a818);
      FUN_0022fcdc(param_1,0);
    }
    break;
  case 6:
    iVar1 = FUN_00190724(DAT_003415d4);
    if (iVar1 != 0) {
      FUN_0022fcdc(param_1,0);
    }
    break;
  case 7:
    iVar1 = FUN_00190724(DAT_003415d4);
    if (iVar1 != 0) {
      FUN_0022fcdc(param_1,0);
    }
    break;
  case 8:
    if (*(char *)(param_1 + 0xb8) == '\0') {
      if ((DAT_0034b350 != 0) && (*(int *)(DAT_0034b350 + 0x5d0) == 0)) {
        FUN_001b4104(0x34179c);
        FUN_0022fcdc(param_1,0);
      }
    }
    else {
      iVar1 = FUN_001155c0(DAT_003415ac);
      if (iVar1 != 0) {
        FUN_00103628(DAT_003415ac,1);
        FUN_002a4d40(DAT_0034b350);
        *(undefined1 *)(param_1 + 0xb8) = 0;
        FUN_001b40d8(0x34179c);
      }
    }
    break;
  default:
    piVar2 = *(int **)(param_1 + 0x214);
    goto LAB_0022fc10;
  }
  piVar2 = *(int **)(param_1 + 0x214);
LAB_0022fc10:
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x10))();
  }
  return;
}
// near miss from lane fm9 (unreviewed)
