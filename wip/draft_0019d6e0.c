/* HSTMATCH module=EBOOT.BIN start=0x0019d6e0 end=0x0019da6c symbol=FUN_0019d6e0 lang=c99 */
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

extern undefined * DAT_00338ac4;
extern undefined4 DAT_0034a678;
extern void FUN_00234158();
extern void FUN_002345f8();
extern void FUN_0023466c();

void FUN_0019d6e0(int param_1,int param_2,int param_3)
{
  char cVar1;
  
  if (param_1 == 4) {
    if (DAT_0034a678 == 0x30) {
      if (*(char *)(DAT_00338ac4 + 0x178) == '\0') {
        FUN_00234158(&DAT_0034a678,0x1e);
      }
      else {
        FUN_00234158(&DAT_0034a678,0x2b);
      }
    }
    else if (DAT_0034a678 == 0x29) {
      if (*(char *)(DAT_00338ac4 + 0x178) == '\0') {
        FUN_00234158(&DAT_0034a678,0x1e);
      }
      else {
        FUN_00234158(&DAT_0034a678,0x20);
      }
    }
    else {
      FUN_00234158(&DAT_0034a678,0x1e);
    }
  }
  else if (param_1 == 3) {
    if (DAT_0034a678 == 0x29) {
      cVar1 = *(char *)(param_2 + 0x28);
      if (((cVar1 == '\x04') || (cVar1 == '\x03')) || (cVar1 == '\0')) {
        FUN_00234158(&DAT_0034a678,0x25);
      }
      else {
        FUN_00234158(&DAT_0034a678,0x26);
      }
    }
    else if (DAT_0034a678 == 0x30) {
      cVar1 = *(char *)(param_2 + 0x28);
      if (((cVar1 == '\x04') || (cVar1 == '\x03')) || (cVar1 == '\0')) {
        FUN_00234158(&DAT_0034a678,0x2c);
      }
      else {
        FUN_00234158(&DAT_0034a678,0x2d);
      }
    }
    else {
      FUN_0023466c(&DAT_0034a678);
    }
  }
  else if (param_1 == 2) {
    if (DAT_0034a678 == 0x56) {
      FUN_00234158(&DAT_0034a678,0x55);
    }
    else if (DAT_0034a678 == 0x43) {
      FUN_00234158(&DAT_0034a678,0x3f);
    }
    else if (DAT_0034a678 == 0x34) {
      FUN_00234158(&DAT_0034a678,0x33);
    }
    else if (DAT_0034a678 == 0x30) {
      if (param_3 == 0) {
        cVar1 = *(char *)(param_2 + 0x28);
        if (((cVar1 == '\x04') || (cVar1 == '\x03')) || (cVar1 == '\0')) {
          FUN_00234158(&DAT_0034a678,0x2e);
        }
        else {
          FUN_00234158(&DAT_0034a678,0x2f);
        }
      }
      else if (*(char *)(DAT_00338ac4 + 0x178) == '\0') {
        FUN_00234158(&DAT_0034a678,0x3a);
      }
      else {
        FUN_00234158(&DAT_0034a678,0x2e);
      }
    }
    else if (DAT_0034a678 == 0x29) {
      if (param_3 == 0) {
        cVar1 = *(char *)(param_2 + 0x28);
        if (((cVar1 == '\x04') || (cVar1 == '\x03')) || (cVar1 == '\0')) {
          FUN_00234158(&DAT_0034a678,0x27);
        }
        else {
          FUN_00234158(&DAT_0034a678,0x28);
        }
      }
      else if (*(char *)(DAT_00338ac4 + 0x178) == '\0') {
        FUN_00234158(&DAT_0034a678,0x38);
      }
      else {
        FUN_00234158(&DAT_0034a678,0x27);
      }
    }
    else {
      FUN_0023466c(&DAT_0034a678);
    }
  }
  else if (param_1 == 1) {
    FUN_002345f8(&DAT_0034a678);
  }
  return;
}
// near miss from lane fm11 (unreviewed)
