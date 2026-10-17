/* HSTMATCH module=EBOOT.BIN start=0x0008d298 end=0x0008d2ec symbol=FUN_0008d298 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern uint * FUN_000114c0();

undefined1 * FUN_0008d298(undefined1 *param_1)
{
  FUN_000114c0(param_1,0,0x14);
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 2;
  param_1[3] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0x10] = 0;
  return param_1;
}
