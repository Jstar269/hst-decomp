/* HSTMATCH module=EBOOT.BIN start=0x001cc190 end=0x001cc354 symbol=FUN_001cc190 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern undefined DAT_002ea308;
extern void FUN_0018a950(undefined4, undefined *);
extern undefined1 * FUN_0018c9f4(int);
extern void FUN_001cb5ec(int, void *, int, undefined4);
extern void FUN_001cd88c(int, int, int);
extern undefined * FUN_002294f4(int, undefined4, void *, int);
extern undefined4 FUN_002297d8(int, void *, int);
}

extern "C" void FUN_001cc190(int param_1,int param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  int iVar2;
  register int iVar3;
  undefined *puVar4;
  undefined1 auStack_100 [256];
  
  if (param_2 != 0) {
    FUN_001cb5ec(param_1,auStack_100,param_2,param_3);
    if (param_4 < 0) {
      iVar2 = *(int *)(param_1 + 0x15c);
      iVar1 = (int)(FUN_002294f4(iVar2 + 0x34,*(undefined4 *)(iVar2 + 0x24),auStack_100,0));
      if (iVar1 != 0) {
        *(undefined1 *)(iVar2 + 99) = 0;
        *(undefined1 *)(iVar2 + 100) = 0;
        *(int *)(iVar2 + 0x68) = iVar1;
        *(undefined4 *)(iVar2 + 0x6c) = 0;
        *(undefined4 *)(iVar2 + 0x70) = 0;
        FUN_0018a950(*(undefined4 *)(iVar2 + 0x20),&DAT_002ea308);
        FUN_001cd88c(iVar2,2,1);
      }
      *(undefined4 *)(iVar2 + 0x74) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x78) = 0xffffffff;
      FUN_002297d8(iVar2 + 0x34,auStack_100,0);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0x4c) + param_4 * 4);
      iVar2 = *(int *)(iVar3 + 0x34);
      iVar1 = (int)(FUN_0018c9f4(7));
      if (*(int *)(iVar1 + 4) == 0) {
        puVar4 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 1) {
        puVar4 = &DAT_002c0e1c;
      }
      else if ((iVar2 < 0) || ((*(int **)(iVar1 + 0xc))[1] <= iVar2)) {
        puVar4 = &DAT_002c0e18;
      } else {
        puVar4 = *(undefined **)(**(int **)(iVar1 + 0xc) + iVar2 * 4);
      }
      iVar2 = *(int *)(param_1 + 0x15c);
      iVar1 = (int)(FUN_002294f4(iVar2 + 0x34,*(undefined4 *)(iVar2 + 0x24),auStack_100,0));
      if (iVar1 != 0) {
        *(undefined1 *)(iVar2 + 99) = 0;
        *(undefined1 *)(iVar2 + 100) = 0;
        *(int *)(iVar2 + 0x68) = iVar1;
        *(undefined4 *)(iVar2 + 0x6c) = 0;
        *(undefined4 *)(iVar2 + 0x70) = 0;
        FUN_0018a950(*(undefined4 *)(iVar2 + 0x20),puVar4);
        FUN_001cd88c(iVar2,2,1);
      }
      *(undefined4 *)(iVar2 + 0x74) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x78) = 0xffffffff;
      FUN_002297d8(iVar2 + 0x34,auStack_100,0);
      *(int *)(*(int *)(param_1 + 0x15c) + 0x5c) = iVar3;
    }
  }
  return;
}

// Best result: 2 differing words out of 113; first mismatch at +0x110.
// Retail writes the comparison result to v0 and branches on v0; this source uses at for the same comparison.
// Ruled out explicit condition temporaries, nested and goto forms, C/C++ modes, register hints, and strength-reduction toggles.
// near miss from lane km4 (unreviewed)
