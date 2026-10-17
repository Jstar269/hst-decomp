/* HSTMATCH module=EBOOT.BIN start=0x00115b78 end=0x00115bac symbol=FUN_00115b78 lang=c99 */
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

extern void FUN_00101f48();

void FUN_00115b78(int param_1,undefined2 param_2)
{
  FUN_00101f48();
  *(undefined2 *)(param_1 + 0x908) = param_2;
  return;
}
