/* HSTMATCH module=EBOOT.BIN start=0x0012cbdc end=0x0012cbe4 symbol=FUN_0012cbdc lang=c99 */
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

extern void FUN_0012b6e8(float param_1,int param_2);

void FUN_0012cbdc(float param_1,int param_2)
{
  FUN_0012b6e8(param_1,param_2 + -0xe0);
  return;
}
