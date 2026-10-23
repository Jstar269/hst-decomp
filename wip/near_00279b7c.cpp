/* HSTMATCH module=EBOOT.BIN start=0x00279b7c end=0x00279f64 symbol=FUN_00279b7c lang=c++ */
#pragma opt_strength_reduction on
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
extern undefined4 DAT_00338b08;
extern undefined * DAT_003415a8;
extern undefined * DAT_00341ccc;
int FUN_000d8bfc(int, int);
int FUN_000d8c24(int, int, uint);
void FUN_000143b0(void *, void *, int);
void FUN_000ffb3c(int, int);
void FUN_001bf884(void *, uint, int);
void FUN_001bf948(void *, uint, int);
void FUN_001bf980(void *, uint, int);
void FUN_001bf9b8(void *, uint, int);
int FUN_00293a34(int);
int FUN_00293ae0(int, int);
void FUN_00293c6c(int);
}

extern "C" void FUN_00279b7c(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar6;
  register byte *pbVar3;
  uint uVar4;
  undefined1 auStack_60 [96];
  
  uVar4 = 0;
  iVar1 = FUN_000d8bfc(DAT_00338b08,5);
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      iVar2 = FUN_000d8c24(DAT_00338b08,5,uVar4);
      if (iVar2 != 0) {
        if ((int)uVar4 < 0) {
          pbVar3 = (byte *)0x0;
        }
        else if ((int)uVar4 < 0x280) {
          pbVar3 = (byte *)(DAT_00341ccc + iVar1 + 0x34c);
        }
        else {
          pbVar3 = (byte *)0x0;
        }
        iVar6 = *(char *)(iVar2 + 0x60);
        if ((1 < iVar6) && (iVar6 == param_1) && ((uint)*pbVar3 < 2)
           ) {
          if (param_1 == 2) {
            FUN_001bf884(DAT_003415a8 + 0x80,uVar4,6);
          }
          else {
            FUN_001bf884(DAT_003415a8 + 0x80,uVar4,2);
          }
        }
      }
      iVar1 = iVar1 + 2;
      uVar4 = uVar4 + 1;
      iVar2 = FUN_000d8bfc(DAT_00338b08,5);
    } while ((int)uVar4 < iVar2);
  }
  uVar4 = 0;
  iVar1 = FUN_000d8bfc(DAT_00338b08,1);
  if (0 < iVar1) {
    do {
      iVar1 = FUN_000d8c24(DAT_00338b08,1,uVar4);
      if (iVar1 != 0) {
        if ((int)uVar4 < 0) {
          pbVar3 = (byte *)0x0;
        }
        else if ((int)uVar4 < 0x280) {
          pbVar3 = (byte *)(DAT_00341ccc + uVar4 + 0x84c);
        }
        else {
          pbVar3 = (byte *)0x0;
        }
        iVar6 = *(char *)(iVar1 + 0x60);
        if ((1 < iVar6) && (iVar6 == param_1) && ((uint)*pbVar3 < 2)
           ) {
          if (param_1 == 2) {
            FUN_001bf948(DAT_003415a8 + 0x80,uVar4,6);
          }
          else {
            FUN_001bf948(DAT_003415a8 + 0x80,uVar4,2);
          }
        }
      }
      uVar4 = uVar4 + 1;
      iVar1 = FUN_000d8bfc(DAT_00338b08,1);
    } while ((int)uVar4 < iVar1);
  }
  uVar4 = 0;
  iVar1 = FUN_000d8bfc(DAT_00338b08,2);
  if (0 < iVar1) {
    do {
      iVar1 = FUN_000d8c24(DAT_00338b08,2,uVar4);
      if (iVar1 != 0) {
        if ((int)uVar4 < 0) {
          pbVar3 = (byte *)0x0;
        }
        else if ((int)uVar4 < 0x280) {
          pbVar3 = (byte *)(DAT_00341ccc + uVar4 + 0xacc);
        }
        else {
          pbVar3 = (byte *)0x0;
        }
        iVar6 = *(char *)(iVar1 + 0x60);
        if ((1 < iVar6) && (iVar6 == param_1) && ((uint)*pbVar3 < 2)
           ) {
          if (param_1 == 2) {
            FUN_001bf980(DAT_003415a8 + 0x80,uVar4,6);
          }
          else {
            FUN_001bf980(DAT_003415a8 + 0x80,uVar4,2);
          }
        }
      }
      uVar4 = uVar4 + 1;
      iVar1 = FUN_000d8bfc(DAT_00338b08,2);
    } while ((int)uVar4 < iVar1);
  }
  uVar4 = 0;
  iVar1 = FUN_000d8bfc(DAT_00338b08,3);
  if (0 < iVar1) {
    do {
      iVar1 = FUN_000d8c24(DAT_00338b08,3,uVar4);
      if (iVar1 != 0) {
        if ((int)uVar4 < 0) {
          pbVar3 = (byte *)0x0;
        }
        else if ((int)uVar4 < 0x280) {
          pbVar3 = (byte *)(DAT_00341ccc + uVar4 + 0xd4c);
        }
        else {
          pbVar3 = (byte *)0x0;
        }
        iVar6 = *(char *)(iVar1 + 0x60);
        if ((1 < iVar6) && (iVar6 == param_1) && ((uint)*pbVar3 < 2)
           ) {
          if (param_1 == 2) {
            FUN_001bf9b8(DAT_003415a8 + 0x80,uVar4,6);
          }
          else {
            FUN_001bf9b8(DAT_003415a8 + 0x80,uVar4,2);
          }
        }
      }
      uVar4 = uVar4 + 1;
      iVar1 = FUN_000d8bfc(DAT_00338b08,3);
    } while ((int)uVar4 < iVar1);
  }
  FUN_00293a34((int)auStack_60);
  FUN_00293c6c((int)auStack_60);
  FUN_00293ae0((int)auStack_60,-1);
  return;
}

// Best result: 61 differing words out of 250; first mismatch at +0x54.
// Remaining differences repeat in the four index-bound/pointer-selection blocks and status-register assignment.
// Ruled out signed and unsigned indices, byte promotion variants, pointer volatility, register hints, C/C++ modes, prototypes, and strength-reduction toggles.
// near miss from lane km4 (unreviewed)
