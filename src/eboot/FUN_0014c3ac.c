/* HSTMATCH module=EBOOT.BIN start=0x0014c3ac end=0x0014c3d8 symbol=FUN_0014c3ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern int FUN_0022a970();

void FUN_0014c3ac(undefined4 param_1,int param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0022a970(param_2 + 0xf0);
  *puVar1 = param_3;
  return;
}
