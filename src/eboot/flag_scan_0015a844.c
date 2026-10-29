/* HSTMATCH module=EBOOT.BIN start=0x0015a844 end=0x0015aa1c symbol=FUN_0015a844 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: positive `if (bit && F(..) == 0)` else-if chain instead of the inverted nests, signed char flag byte, unsigned char global, int-returning F; exact match verified; names and types await human review. */
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

extern undefined * DAT_00340400;
extern unsigned char DAT_00340408;
extern void FUN_0015b6a4();
extern int FUN_0015d16c();

undefined4 FUN_0015a844(int param_1)
{
  signed char bVar1;
  undefined4 uVar2;

  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 8) = 0x5a;
  bVar1 = *(signed char *)(DAT_00340400 + 0xf0);
  if (DAT_00340408 != 0) {
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    FUN_0015b6a4(param_1,1,1,1);
    uVar2 = 0xd0;
  }
  else {
    if ((bVar1 & 1) && FUN_0015d16c(param_1,0xd0) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd0;
      FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else if ((bVar1 & 2) && FUN_0015d16c(param_1,0xd1) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd1;
      FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else if ((bVar1 & 4) && FUN_0015d16c(param_1,0xd2) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd2;
      FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else if ((bVar1 & 8) && FUN_0015d16c(param_1,0xd3) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd3;
      FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else if ((bVar1 & 0x10) && FUN_0015d16c(param_1,0xd4) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd4;
      FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  return uVar2;
}
