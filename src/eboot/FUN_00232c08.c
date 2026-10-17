/* HSTMATCH module=EBOOT.BIN start=0x00232c08 end=0x00232c58 symbol=FUN_00232c08 lang=c99 */
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

extern undefined4 DAT_0034a664;
extern void FUN_00232cc4();
extern void FUN_0023302c();

undefined4 * FUN_00232c08(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  DAT_0034a664 = (unsigned int)(param_1);
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  FUN_00232cc4();
  FUN_0023302c(param_1,9);
  return param_1;
}
