/* HSTMATCH module=hstp_trans_main.prx start=0x0006f6ec end=0x0006f75c symbol=FUN_0006f6ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined * DAT_003daf6c;
extern void FUN_00000a00();
extern void FUN_000700fc();

int FUN_0006f6ec(int param_1,short param_2)
{
  if (param_1 != 0) {
    if ((DAT_003daf6c != 0) && (*(int *)(param_1 + 4) != 0)) {
      FUN_000700fc(DAT_003daf6c + 0xc,*(int *)((int)param_1 + 4));
      *(undefined4 *)(param_1 + 4) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
