/* HSTMATCH module=EBOOT.BIN start=0x002310d0 end=0x00231114 symbol=FUN_002310d0 lang=c99 */
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

extern undefined4 DAT_0034a65c;
extern void FUN_00231168();
extern void FUN_00231248();

undefined4 * FUN_002310d0(undefined4 *param_1,undefined1 param_2)
{
  *param_1 = 0;
  DAT_0034a65c = (unsigned int)(param_1);
  *(undefined1 *)(param_1 + 2) = param_2;
  FUN_00231168();
  FUN_00231248(param_1,1);
  return param_1;
}
