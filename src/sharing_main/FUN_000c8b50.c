/* HSTMATCH module=hstp_trans_main.prx start=0x000c8b50 end=0x000c8b84 symbol=FUN_000c8b50 lang=c99 */
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

extern undefined4 DAT_003e1e04;
extern undefined4 FUN_000be1f4();
extern void FUN_00297918();

void FUN_000c8b50(int param_1)
{
  FUN_00297918(*(undefined4 *)(param_1 + 0x784));
  if (DAT_003e1e04 != 0) {
    FUN_000be1f4(DAT_003e1e04);
  }
  return;
}
