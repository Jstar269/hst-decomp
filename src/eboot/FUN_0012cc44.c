/* HSTMATCH module=EBOOT.BIN start=0x0012cc44 end=0x0012cc4c symbol=FUN_0012cc44 lang=c99 */
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

extern undefined4 * FUN_00126c2c(undefined4 *param_1,short param_2);

void FUN_0012cc44(int param_1,short param_2)
{
  FUN_00126c2c((undefined4 *)((undefined4 *)(param_1 + -0xe0)),(short)(param_2));
  return;
}
