/* HSTMATCH module=EBOOT.BIN start=0x0008d640 end=0x0008d650 symbol=FUN_0008d640 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
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


void FUN_0008d640(int param_1,int param_2,undefined2 param_3)
{
  *(undefined2 *)(param_1 + param_2 * 2) = param_3;
  return;
}
