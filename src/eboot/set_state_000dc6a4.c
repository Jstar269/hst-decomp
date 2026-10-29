/* HSTMATCH module=EBOOT.BIN start=0x000dc6a4 end=0x000dc820 symbol=FUN_000dc6a4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
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

extern undefined * DAT_003386b0;
extern undefined DAT_0034189b;
extern undefined DAT_003419bb;
extern uint * FUN_000114c0();
extern void FUN_000db868();

void FUN_000dc6a4(int param_1,int param_2)
{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x3c) = param_2;
  switch (param_2) {
  case 0:
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(DAT_003386b0 + 0x88);
      FUN_000114c0(param_1 + 0xd8,0,0x30);
      *(uint *)(param_1 + 0xd0) = (uint)DAT_0034189b;
      *(undefined4 *)(param_1 + 0xc4) = 0;
      *(undefined4 *)(param_1 + 0xb8) = 0;
      *(uint *)(param_1 + 0xd4) = (uint)DAT_003419bb;
      *(undefined4 *)(param_1 + 200) = 0;
      *(undefined4 *)(param_1 + 0xbc) = 0;
      *(undefined4 *)(param_1 + 0x48) = 1;
      *(undefined4 *)(param_1 + 0x4c) = 1;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x58) = 1;
      *(undefined1 *)(param_1 + 0x108) = 0;
      FUN_000db868(param_1);
    break;
  case 1:
      *(undefined1 *)(param_1 + 0x44) = 1;
      if (*(uchar *)(param_1 + 0xb0) != 0) {
        ((uchar *)param_1)[0xb0] = 0;
        *(int *)(param_1 + 0x48) = -*(int *)(param_1 + 0x48);
      }
      uVar1 = *(undefined4 *)(param_1 + 0x54);
      *(undefined4 *)(param_1 + 0x50) = uVar1;
      if (*(int *)(param_1 + 0x9c) >= 0) {
        FUN_000db868(param_1);
      }
      else {
        *(undefined1 *)(param_1 + 0x5c) = 0;
        *(undefined4 *)(param_1 + 0x90) = 0;
        *(undefined4 *)(param_1 + 0x94) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x98) = 0xffffffff;
        *(undefined4 *)(param_1 + 0xac) = 0;
        *(undefined1 *)(param_1 + 100) = 0;
        *(undefined1 *)(param_1 + 0x65) = 0;
        *(undefined1 *)(param_1 + 0x66) = 0;
        *(undefined1 *)(param_1 + 0x67) = 0;
        *(undefined4 *)(param_1 + 0x68) = 3;
        *(undefined4 *)(param_1 + 0x6c) = 0xd;
        *(undefined1 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7c) = 0;
        *(undefined4 *)(param_1 + 0x80) = 0;
        *(undefined1 *)(param_1 + 0x60) = 0;
        *(undefined1 *)(param_1 + 0x61) = 0;
        *(undefined1 *)(param_1 + 0x62) = 0;
        *(undefined1 *)(param_1 + 99) = 0;
        *(undefined1 *)(param_1 + 0x71) = 0;
        *(undefined1 *)(param_1 + 0x72) = 0;
        *(undefined1 *)(param_1 + 0x73) = 0;
        *(undefined1 *)(param_1 + 0x74) = 0;
        *(undefined1 *)(param_1 + 0x75) = 0;
        *(undefined1 *)(param_1 + 0x5d) = 0;
        *(undefined1 *)(param_1 + 0x5e) = 0;
        *(undefined1 *)(param_1 + 0x84) = 0;
        *(undefined1 *)(param_1 + 0x85) = 0;
      }

    break;
  case 2:
  case 3:
  default:
    break;
  }
  return;
}
