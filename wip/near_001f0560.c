/* HSTMATCH module=EBOOT.BIN start=0x001f0560 end=0x001f0850 symbol=FUN_001f0560 lang=c99 rodata=0x002c8f8c */
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
extern undefined DAT_0034179c;
extern void FUN_001b1c44(void *, int);
extern void FUN_001e09dc();
extern void FUN_001e28e0();
extern void FUN_001e2990();
extern void FUN_001e5ac4();
extern void FUN_001e5b64();
extern void FUN_001e5da0();
extern void FUN_001e5df0();
extern void FUN_001e5e3c();
extern void FUN_001f3770();
extern void FUN_001f474c();
extern void FUN_001f47a4();
extern void FUN_001f4bfc();

void FUN_001f0560(int param_1)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined4 *)(param_1 + 0x1084) = 0;
    *(undefined4 *)(param_1 + 0x1088) = 0;
    FUN_001f474c(param_1,0);
    FUN_001e09dc(*(undefined4 *)(param_1 + 0x510),2);
    FUN_001e2990(*(undefined4 *)(param_1 + 0x510));
    FUN_001e5ac4(*(undefined4 *)(param_1 + 0x510));
    FUN_001e5da0(*(undefined4 *)(param_1 + 0x510));
  }
  switch(*(undefined4 *)(param_1 + 0x1084)) {
  case 0:
    iVar2 = *(int *)(param_1 + 0x1088) + 1;
    *(int *)(param_1 + 0x1088) = iVar2;
    if (10 < iVar2) {
      *(undefined4 *)(param_1 + 0x1084) = 1;
      *(undefined4 *)(param_1 + 0x1088) = 0;
      FUN_001e5b64(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(param_1 + 0x1084));
      FUN_001e5e3c(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(param_1 + 0x1084));
      FUN_001b1c44(&DAT_0034179c,8);
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
    iVar2 = *(int *)(param_1 + 0x1088) + 1;
    *(int *)(param_1 + 0x1088) = iVar2;
    if (iVar2 >= 6) {
      if (*(int *)(param_1 + 0x1084) != 4) {
        FUN_001b1c44(&DAT_0034179c,8);
      }
      iVar2 = *(int *)(param_1 + 0x1084);
      *(int *)(param_1 + 0x1084) = iVar2 + 1;
      *(undefined4 *)(param_1 + 0x1088) = 0;
      FUN_001e5b64(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(param_1 + 0x1084));
      FUN_001e5e3c(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(param_1 + 0x1084));
    
    }
    else {
      if (*(unsigned char *)(param_1 + 0x58c) == '\0') {
        bVar1 = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_001b1c44(&DAT_0034179c,3);
        *(undefined4 *)(param_1 + 0x10a4) = *(undefined4 *)(param_1 + 0x10a0);
        *(undefined4 *)(param_1 + 0x1084) = 6;
        *(undefined4 *)(param_1 + 0x1088) = 0;
        FUN_001e5df0(*(undefined4 *)(param_1 + 0x510));
        FUN_001e5b64(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(param_1 + 0x1084));
        FUN_001e28e0(*(undefined4 *)(param_1 + 0x510));
      }
    
    }
    break;
  case 5:
    iVar4 = *(int *)(param_1 + 0x10a4);
    iVar2 = iVar4 + 0x14;
    *(int *)(param_1 + 0x10a4) = iVar2;
    if (iVar2 >= *(int *)(param_1 + 0x10a0)) {
      *(int *)(param_1 + 0x10a4) = *(int *)(param_1 + 0x10a0);
      *(undefined4 *)(param_1 + 0x1084) = 6;
      *(undefined4 *)(param_1 + 0x1088) = 0;
      FUN_001e28e0(*(undefined4 *)(param_1 + 0x510));
      iVar2 = *(int *)(param_1 + 0x10a4);
    
      }
      else {
      if (*(unsigned char *)(param_1 + 0x58c) == '\0') {
        bVar1 = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_001b1c44(&DAT_0034179c,3);
        *(undefined4 *)(param_1 + 0x10a4) = *(undefined4 *)(param_1 + 0x10a0);
        *(undefined4 *)(param_1 + 0x1084) = 6;
        *(undefined4 *)(param_1 + 0x1088) = 0;
        FUN_001e28e0(*(undefined4 *)(param_1 + 0x510));
        FUN_001e5df0(*(undefined4 *)(param_1 + 0x510));
      }
      iVar2 = *(int *)(param_1 + 0x10a4);
    
      }
    if (iVar4 != iVar2) {
      FUN_001b1c44(&DAT_0034179c,0x1a);
    }
    uVar3 = *(undefined4 *)(param_1 + 0x510);
    FUN_001e5b64(uVar3,*(undefined4 *)(param_1 + 0x1084));
    break;
  case 6:
    if (*(unsigned char *)(param_1 + 0x58c) == '\0') {
      bVar1 = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_001b1c44(&DAT_0034179c,3);
      FUN_001f3770(param_1);
    }
  }
  FUN_001f4bfc(param_1);
  FUN_001f47a4(param_1);
  return;
}
// Best near miss: 91 differing words remain, concentrated in the state jump-table case layout.
// The retail range check is branch-likely; case 0 and cases 1-4 still schedule counter updates and
// branch targets differently. Tried unsigned byte flags, a byte-pointer parameter, local state
// and counter aliases, reordered declarations, explicit range guards/defaults, and branch inversions.
// Replaced the raw 0x34179c argument with the existing DAT_0034179c symbol.
// near miss from lane km4 (unreviewed)
