/* HSTMATCH module=EBOOT.BIN start=0x00118ad4 end=0x00118adc symbol=FUN_00118ad4 lang=c99 */
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

extern void FUN_0011d314();

void FUN_00118ad4(undefined4 param_1,int param_2)
{
  FUN_0011d314(param_1,param_2,*(undefined4 *)(param_2 + 0x14));
  return;
}
