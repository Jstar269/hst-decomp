/* HSTMATCH module=EBOOT.BIN start=0x0012cbec end=0x0012cbf4 symbol=FUN_0012cbec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern void FUN_0012b678(int param_1,undefined4 *param_2,uint param_3,undefined1 param_4);

void FUN_0012cbec(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)
{
  FUN_0012b678((int)(param_1 + -0xe0),(undefined4 *)(param_2),(uint)(param_3),(undefined1)(param_4));
  return;
}
