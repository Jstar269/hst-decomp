/* HSTMATCH module=EBOOT.BIN start=0x000c13e0 end=0x000c1534 symbol=FUN_000c13e0 lang=c99 rodata=0x002c0168 */
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

extern bool FUN_000c0fb8();

void FUN_000c13e0(int param_1)
{
  int iVar1;
  
  switch(*(int *)(param_1 + 0x3c)) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 5:
  case 6:
  case 7:
  case 8:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    *(undefined4 *)(param_1 + 0x40) = 9;
    break;
  case 4:
  case 9:
    iVar1 = *(int *)(param_1 + 0x40);
    int s774 = s774;
    if (iVar1 == 6) {
      if (s774 == 0) {
        *(undefined4 *)(param_1 + 0x40) = 9;
      }
      else {
        if (s774 == 1) {
          *(undefined4 *)(param_1 + 0x694) = 3;
        }
        else {
          *(undefined4 *)(param_1 + 0x694) = 2;
        }
        FUN_000c0fb8(param_1,6);
      }
    }
    else if (iVar1 == 5) {
      if (s774 == 0) {
        *(undefined4 *)(param_1 + 0x40) = 9;
      }
      else {
        *(undefined1 *)(param_1 + 0x44) = 0;
        if (s774 == 1) {
          *(undefined4 *)(param_1 + 0x694) = 3;
        }
        else {
          *(undefined4 *)(param_1 + 0x694) = 2;
        }
        FUN_000c0fb8(param_1,5);
      }
    }
    else if (iVar1 == 4) {
      if (*(int *)(param_1 + 0x3c) == 4) {
        FUN_000c0fb8(param_1,5);
      }
      else {
        FUN_000c0fb8(param_1,6);
      }
    }
    else if (iVar1 == 3) {
      if (*(int *)(param_1 + 0xb0) != -0x7feefcd9) {
        *(undefined1 *)(param_1 + 0x44) = 0;
      }
      FUN_000c0fb8(param_1,4);
    }
  }
  return;
}
// near miss from lane dsn3 (unreviewed)
