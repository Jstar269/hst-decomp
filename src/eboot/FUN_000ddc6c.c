/* HSTMATCH module=EBOOT.BIN start=0x000ddc6c end=0x000ddca8 symbol=FUN_000ddc6c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_003386b0;

void FUN_000ddc6c(int param_1)
{
  *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x54) =
       *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x54) + *(int *)(param_1 + 0xc4);
  *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x58) =
       *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x58) + *(int *)(param_1 + 200);
  return;
}
