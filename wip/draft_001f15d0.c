/* HSTMATCH module=EBOOT.BIN start=0x001f15d0 end=0x001f1968 symbol=FUN_001f15d0 lang=c99 */
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
extern undefined4 FUN_001b1c44();
extern void FUN_001e74d4();
extern void FUN_001e750c();
extern void FUN_001e7700();
extern void FUN_001e7714();
extern void FUN_001e7730();
extern void FUN_001f3770();
extern void FUN_001f474c();
extern void FUN_001f47a4();
extern void FUN_001f4bfc();
extern void FUN_001fb928();

void FUN_001f15d0(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    if (*(char *)(param_1 + 0x521) == '\0') {
      *(undefined4 *)(param_1 + 0x8178) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x8178) = 2;
    }
    FUN_001f474c(param_1,0);
    FUN_001e74d4(*(undefined4 *)(param_1 + 0x510));
    FUN_001e7714(*(undefined4 *)(param_1 + 0x510));
    FUN_001e7700(*(undefined4 *)(param_1 + 0x510),1);
    *(undefined4 *)(param_1 + 0x8170) = 0;
    *(undefined4 *)(param_1 + 0x8174) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x8170);
  if (iVar1 == 3) {
    iVar1 = *(int *)(param_1 + 0x8174) + 1;
    *(int *)(param_1 + 0x8174) = iVar1;
    if (0x1e < iVar1) {
      FUN_001f3770(param_1);
    }
  }
  else if (iVar1 == 2) {
    iVar1 = *(int *)(param_1 + 0x8174) + 1;
    *(int *)(param_1 + 0x8174) = iVar1;
    if (0x1e < iVar1) {
      FUN_001fb928(param_1 + 0x3c,0x13,1);
    }
  }
  else if (iVar1 == 1) {
    if (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1a) >> 0x1e == 0) {
      FUN_001b1c44(0x34179c,4);
      *(undefined4 *)(param_1 + 0x8178) = 2;
      *(undefined4 *)(param_1 + 0x817c) = 1;
      FUN_001e7700(*(undefined4 *)(param_1 + 0x510));
      FUN_001f3770(param_1);
    }
    else if (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0) {
      FUN_001b1c44(0x34179c);
      *(undefined4 *)(param_1 + 0x817c) = 1;
      iVar1 = *(int *)(param_1 + 0x8178);
      if (iVar1 == 2) {
        *(undefined4 *)(param_1 + 0x8170) = 3;
        *(undefined4 *)(param_1 + 0x8174) = 0;
        FUN_001e7700(*(undefined4 *)(param_1 + 0x510));
        FUN_001e7730(*(undefined4 *)(param_1 + 0x510));
      }
      else if (iVar1 == 1) {
        *(undefined4 *)(param_1 + 0x8170) = 3;
        *(undefined4 *)(param_1 + 0x8174) = 0;
        FUN_001e7700(*(undefined4 *)(param_1 + 0x510));
        FUN_001e7730(*(undefined4 *)(param_1 + 0x510));
      }
      else if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x8170) = 2;
        *(undefined4 *)(param_1 + 0x8174) = 0;
        FUN_001e7700(*(undefined4 *)(param_1 + 0x510));
        FUN_001e7730(*(undefined4 *)(param_1 + 0x510));
      }
    }
    else if (((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1e) >> 0x1e == 0) {
      FUN_001b1c44(0x34179c,1);
      iVar1 = *(int *)(param_1 + 0x8178) + -1;
      *(int *)(param_1 + 0x8178) = iVar1;
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x8178) = 2;
      }
      FUN_001e750c(*(undefined4 *)(param_1 + 0x510));
    }
    else if (((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1a) >> 0x1e == 0) {
      FUN_001b1c44(0x34179c,1);
      iVar1 = *(int *)(param_1 + 0x8178) + 1;
      *(int *)(param_1 + 0x8178) = iVar1;
      if (iVar1 < 3) {
        uVar2 = *(undefined4 *)(param_1 + 0x510);
      }
      else {
        *(undefined4 *)(param_1 + 0x8178) = 0;
        uVar2 = *(undefined4 *)(param_1 + 0x510);
      }
      FUN_001e750c(uVar2);
    }
  }
  else if ((iVar1 == 0) &&
          (iVar1 = *(int *)(param_1 + 0x8174) + 1, *(int *)(param_1 + 0x8174) = iVar1, 0x14 < iVar1)
          ) {
    *(undefined4 *)(param_1 + 0x8174) = 0;
    *(undefined4 *)(param_1 + 0x8170) = 1;
    FUN_001e7700(*(undefined4 *)(param_1 + 0x510),0);
  }
  FUN_001f4bfc(param_1);
  FUN_001f47a4(param_1);
  return;
}
// near miss from lane fm11 (unreviewed)
