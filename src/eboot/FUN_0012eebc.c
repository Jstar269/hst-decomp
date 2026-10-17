/* HSTMATCH module=EBOOT.BIN start=0x0012eebc end=0x0012eef8 symbol=FUN_0012eebc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_0033b578;
extern void FUN_0015f8f4();

void FUN_0012eebc(int param_1)
{
  if ((*(int *)(param_1 + 0xe0) != 0) && (DAT_0033b578 == 1)) {
    FUN_0015f8f4(*(int *)(param_1 + 0xe0));
  }
  return;
}
