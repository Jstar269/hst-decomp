/* HSTMATCH module=EBOOT.BIN start=0x000b3c68 end=0x000b3ca0 symbol=FUN_000b3c68 lang=c99 */
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

extern undefined4 DAT_00341508;

int FUN_000b3c68(int param_1)
{
  return *(int *)(DAT_00341508 + *(int *)(param_1 + 0x158) * 0x18) +
         *(int *)(param_1 + 0x15c) * 0x22c;
}
