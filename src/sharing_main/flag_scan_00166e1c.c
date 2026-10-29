/* HSTMATCH module=hstp_trans_main.prx start=0x00166e1c end=0x00166ff4 symbol=FUN_00166e1c lang=c99 */
/* Clone of src/eboot/flag_scan_0015a844.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined * DAT_003e9740;
extern unsigned char DAT_003e9748;
extern void FUN_00167c4c();
extern int FUN_00169714();

undefined4 FUN_00166e1c(int param_1)
{
  signed char bVar1;
  undefined4 uVar2;

  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 8) = 0x5a;
  bVar1 = *(signed char *)(DAT_003e9740 + 0xf0);
  if (DAT_003e9748 != 0) {
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    FUN_00167c4c(param_1,1,1,1);
    uVar2 = 0xd0;
  }
  else {
    if ((bVar1 & 1) && FUN_00169714(param_1,0xd0) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd0;
      FUN_00167c4c(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else if ((bVar1 & 2) && FUN_00169714(param_1,0xd1) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd1;
      FUN_00167c4c(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else if ((bVar1 & 4) && FUN_00169714(param_1,0xd2) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd2;
      FUN_00167c4c(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else if ((bVar1 & 8) && FUN_00169714(param_1,0xd3) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd3;
      FUN_00167c4c(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else if ((bVar1 & 0x10) && FUN_00169714(param_1,0xd4) == 0) {
      *(undefined4 *)(param_1 + 4) = 0xd4;
      FUN_00167c4c(param_1,*(undefined4 *)(param_1 + 4),0,1);
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  return uVar2;
}
