/* HSTMATCH module=EBOOT.BIN start=0x001b66bc end=0x001b6868 symbol=FUN_001b66bc lang=c99 */
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

extern undefined DAT_003386b8;
extern undefined * DAT_00338b44;
extern undefined DAT_0034179c;
extern void FUN_000622d4();
extern int FUN_001b2af0(int *, int);
extern void FUN_001b3e2c();
extern void FUN_001b41c8();
extern void FUN_001b4530();

void FUN_001b66bc(int param_1)
{
  int iVar1;
  undefined2 *puVar2;
  
  if (*(unsigned char *)(param_1 + 0x90) != 0) {
    if (*(unsigned char *)(param_1 + 0x93) != 0) {
      iVar1 = FUN_001b2af0((int *)&DAT_0034179c,6);
    }
    else if (*(volatile unsigned char *)(param_1 + 0x94) != 0) {
      iVar1 = FUN_001b2af0((int *)&DAT_0034179c,5);
    }
    else if (*(volatile unsigned char *)(param_1 + 0x94) != 0) {
      iVar1 = FUN_001b2af0((int *)&DAT_0034179c,4);
    }
    else {
      iVar1 = FUN_001b2af0((int *)&DAT_0034179c,7);
    }
    *(int *)(param_1 + 0x4c) = iVar1;
  }
  else {
    iVar1 = FUN_001b2af0((int *)&DAT_0034179c,4);
    *(int *)(param_1 + 0x4c) = iVar1;
  }
  FUN_001b3e2c((int *)&DAT_0034179c);
  FUN_001b41c8((int *)&DAT_0034179c);
  FUN_000622d4(3,0x80,0x80,0);
  *(undefined1 *)(param_1 + 0x78) = 1;
  *(undefined1 *)(param_1 + 0x79) = 1;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (DAT_003386b8 == 0) {
    FUN_001b4530((int *)&DAT_0034179c);
  }
  else {
    unsigned char flag = *(unsigned char *)(DAT_00338b44 + 0x45);
    if (flag != 0) {
      FUN_001b4530((int *)&DAT_0034179c);
    }
  }
  iVar1 = 0;
  do {
    puVar2 = *(undefined2 **)(param_1 + 0xa0);
    iVar1 = iVar1 + 6;
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xa4);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xa8);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xac);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xb0);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2 = *(undefined2 **)(param_1 + 0xb4);
    *puVar2 = 0;
    puVar2[1] = 2;
    puVar2[2] = 0;
    param_1 = param_1 + 0x18;
  } while (iVar1 < 0x12);
  return;
}
// near miss from lane km4 (unreviewed)
