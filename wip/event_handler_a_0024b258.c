/* HSTMATCH module=EBOOT.BIN start=0x0024b258 end=0x0024b5a0 symbol=FUN_0024b258 lang=c99 */
// NOT MATCHED (214/210 words, 207 differ, measured from the generated baseline): 840-byte dispatch function; the head is a plain `li v0,K; beq a1,v0` chain over K = 0x18/0x0e/0x16/0x08/0x13/0x04 with beql/beqzl delay slots carrying the first statement of each case (`lbu a0,1127(s0)`, `sb zero,1257(s0)`, `sw zero,1264(s0)`, ...). Rebuilding it needs the whole case table transcribed from the disassembly.
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
extern void FUN_00055044();
extern void FUN_00058fc0();
extern void FUN_0005f110();
extern void FUN_0024747c();

undefined4 FUN_0024b258(int param_1,int param_2)
{
  char cVar1;
  int iVar2;
  
  if (param_2 == 0x18) {
    FUN_0024747c();
    *(undefined1 *)(param_1 + 0x467) = 0;
    *(undefined4 *)(param_1 + 0x45c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x4b8) = 0;
    return 0;
  }
  if (param_2 == 0xe) {
    cVar1 = *(char *)(param_1 + 0x467);
  }
  else {
    if (param_2 != 0x16) {
      if (param_2 != 8) {
        return 0;
      }
      *(undefined1 *)(param_1 + 0x4e9) = 0;
      *(undefined4 *)(param_1 + 0x4f0) = 0;
      if (*(int *)(param_1 + 0x45c) < 0) {
        iVar2 = *(int *)(param_1 + 0x4e0);
LAB_0024b39c:
        if (iVar2 != 1) {
          *(undefined1 *)(param_1 + 0x4bd) = 0;
          goto LAB_0024b3b4;
        }
        *(undefined4 *)(param_1 + 0x45c) = 0xffffffff;
      }
      else {
        if ((*(int *)(param_1 + 0x4e0) == 1) && (*(int *)(param_1 + 0x4b8) != 2)) {
          iVar2 = *(int *)(param_1 + 0x4e0);
          goto LAB_0024b39c;
        }
        if (*(int *)(param_1 + 0x4e0) == 0) {
          *(undefined4 *)(param_1 + 0x45c) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x4e0) = 1;
        }
        else {
          iVar2 = *(int *)(param_1 + 0x454);
          if (((iVar2 == 0x66) || (iVar2 == 0x6e)) || (iVar2 == 0x77)) {
            if (iVar2 == 0x6e) {
              *(undefined4 *)(param_1 + 0x45c) = 0xffffffff;
              *(undefined4 *)(param_1 + 0x4e0) = 0;
            }
            else {
              *(undefined4 *)(param_1 + 0x45c) = 0xffffffff;
            }
          }
          else {
            *(undefined4 *)(param_1 + 0x44) = 0x41200000;
            *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0x40);
            *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0x44);
            *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0x48);
            *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0x4c);
            FUN_00055044(param_1 + 0xe0,param_1 + 0xa0);
            FUN_00055044(*(undefined4 *)(param_1 + 0x444),param_1 + 0xa0);
            *(undefined1 *)(param_1 + 0x465) = 0;
            *(undefined1 *)(param_1 + 0x467) = 1;
          }
        }
      }
      *(undefined1 *)(param_1 + 0x4bd) = 0;
LAB_0024b3b4:
      *(undefined1 *)(param_1 + 0x4b0) = 0;
      *(undefined1 *)(param_1 + 0x484) = 1;
      return 0;
    }
    cVar1 = *(char *)(param_1 + 0x467);
  }
  if (cVar1 != '\0') {
    *(undefined1 *)(param_1 + 0x4b0) = 0;
    goto LAB_0024b568;
  }
  if (-1 < *(int *)(param_1 + 0x45c)) {
    if (*(int *)(*(int *)(DAT_003386b0 + 0x9c) + 0x58) < *(int *)(param_1 + 0x45c)) {
      iVar2 = *(int *)(param_1 + 0x4e0);
      if (*(int *)(param_1 + 0x4e0) <= *(int *)(param_1 + 0x4b8)) {
        iVar2 = *(int *)(param_1 + 0x4b8);
      }
      *(int *)(param_1 + 0x4b8) = iVar2;
      FUN_0024747c(param_1);
      if (*(int *)(param_1 + 0x4b8) == 2) {
        *(undefined4 *)(param_1 + 0x4e0) = 1;
        *(undefined1 *)(param_1 + 0x4bc) = 1;
        goto LAB_0024b518;
      }
      iVar2 = *(int *)(param_1 + 0x454);
    }
    else {
      if (((*(int *)(param_1 + 0x4e0) != 1) || (*(int *)(param_1 + 0x4b8) == 2)) ||
         ((iVar2 = *(int *)(param_1 + 0x454), iVar2 != 0x72 && ((iVar2 != 0x71 && (iVar2 != 0x66))))
         )) {
        if ((*(int *)(param_1 + 0x4b8) == 1) &&
           (((iVar2 = *(int *)(param_1 + 0x454), iVar2 == 0x72 || (iVar2 == 0x71)) ||
            (iVar2 == 0x66)))) {
          FUN_0024747c(param_1);
          *(undefined4 *)(param_1 + 0x4e0) = 1;
        }
        else {
          *(undefined4 *)(param_1 + 0x44) = 0x41200000;
          *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0x40);
          *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0x44);
          *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0x48);
          *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0x4c);
          FUN_00055044(param_1 + 0xe0,param_1 + 0xa0);
          FUN_00055044(*(undefined4 *)(param_1 + 0x444),param_1 + 0xa0);
          *(undefined1 *)(param_1 + 0x465) = 0;
        }
      }
LAB_0024b518:
      iVar2 = *(int *)(param_1 + 0x454);
    }
    if (iVar2 == 0x73) {
      *(undefined4 *)(param_1 + 0x4e0) = 0;
      FUN_00058fc0(param_1 + 0xe0,0xffffffff);
      FUN_0005f110(0,param_1 + 0xe0);
      *(undefined4 *)(param_1 + 0x1b0) = 0;
    }
    FUN_00058fc0(param_1 + 0x290,0xffffffff);
    FUN_0005f110(0,param_1 + 0x290);
    *(undefined4 *)(param_1 + 0x360) = 0;
  }
  *(undefined1 *)(param_1 + 0x4b0) = 0;
LAB_0024b568:
  *(undefined1 *)(param_1 + 0x484) = 1;
  return 0;
}
// near miss from lane ds1 (unreviewed)
