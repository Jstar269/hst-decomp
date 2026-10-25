/* HSTMATCH module=EBOOT.BIN start=0x00285f3c end=0x002861e0 symbol=FUN_00285f3c lang=c++ */
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

struct False {};

extern "C" {
extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern undefined * DAT_003386b0;
extern undefined * DAT_00338ac4;
extern undefined4 DAT_00338ac8;
extern undefined * DAT_003415ac;
extern undefined4 DAT_0034a138;
extern void FUN_00103628(...);
extern void FUN_00114168(...);
extern int FUN_001155c0(...);
extern void FUN_00116414(...);
extern undefined1 * FUN_0018c9f4(int);
extern undefined4 FUN_001eca14(...);
extern void FUN_00280404();
extern uint * FUN_000149a8(...);
}

extern "C" undefined4 FUN_00285f3c(int *param_1,False tag)
{
  unsigned char cVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = FUN_001155c0(DAT_003415ac);
  if (iVar2 != 0) {
    if (*(int *)(DAT_003415ac + 0x68) == 6) {
      FUN_00103628(DAT_003415ac,1);
      FUN_00116414(DAT_003415ac + 0x8c,*(undefined4 *)(DAT_003415ac + 0x90),0);
      if (*(char *)(DAT_00338ac4 + 0x178) != '\0') {
        if ((DAT_0034a138 != 0) && (iVar2 = FUN_001eca14(), iVar2 != 0)) {
          return 0;
        }
        if ((DAT_003386b0 != 0) && (*(char *)(DAT_003386b0 + 0x5b) != '\0')) {
          return 0;
        }
      }
      cVar1 = (unsigned char)param_1[1];
      if (cVar1 == '\0') {
        FUN_00280404();
      }
      return 0;
    }
  }
  cVar1 = (unsigned char)param_1[1];
  if ((cVar1 == '\0') &&
     ((((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) != 0 ||
       (*(int *)(DAT_003415ac + 0x68) != 6)) && (DAT_00338ac8 != 0)))) {
    if (DAT_00338ac8 == -0x7fbef4f1) {
      iVar2 = (int)(FUN_0018c9f4(0x11));
      if (*(int *)(iVar2 + 4) == 0) {
        puVar3 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar2 + 8) + 8) < 0x11) {
        puVar3 = &DAT_002c0e1c;
      }
      else if (*(int *)(*(int *)(iVar2 + 0xc) + 0xc4) < 5) {
        puVar3 = &DAT_002c0e18;
      }
      else {
        puVar3 = *(undefined **)(*(int *)(*(int *)(iVar2 + 0xc) + 0xc0) + 0x10);
      }
      *param_1 = (int)puVar3;
    }
    else if (DAT_00338ac8 == -0x7fbef4fd) {
      iVar2 = (int)(FUN_0018c9f4(0x11));
      if (*(int *)(iVar2 + 4) == 0) {
        puVar3 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar2 + 8) + 8) < 0x11) {
        puVar3 = &DAT_002c0e1c;
      }
      else if (*(int *)(*(int *)(iVar2 + 0xc) + 0xc4) < 4) {
        puVar3 = &DAT_002c0e18;
      }
      else {
        puVar3 = *(undefined **)(*(int *)(*(int *)(iVar2 + 0xc) + 0xc0) + 0xc);
      }
      *param_1 = (int)puVar3;
    }
    else {
      iVar2 = (int)(FUN_0018c9f4(0x11));
      if (*(int *)(iVar2 + 4) == 0) {
        puVar3 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar2 + 8) + 8) < 0x11) {
        puVar3 = &DAT_002c0e1c;
      }
      else if (*(int *)(*(int *)(iVar2 + 0xc) + 0xc4) < 0x11) {
        puVar3 = &DAT_002c0e18;
      }
      else {
        puVar3 = *(undefined **)(*(int *)(*(int *)(iVar2 + 0xc) + 0xc0) + 0x40);
      }
      *param_1 = (int)puVar3;
    }
    if (*param_1 != 0) {
      FUN_00114168(DAT_003415ac,6,*param_1,0,0);
    }
  }
  return 1;
}
// Near miss: 90 of 169 words differ, beginning at the early status-result branch and continuing through its state-six path.
// Ruled out byte versus word fields, C versus C++ mode, the empty by-value tag's frame effect, pointer-typed globals, and several zero-result branch forms.
// near miss from lane km5 (unreviewed)
