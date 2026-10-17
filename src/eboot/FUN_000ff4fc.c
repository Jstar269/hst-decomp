/* HSTMATCH module=EBOOT.BIN start=0x000ff4fc end=0x000ff548 symbol=FUN_000ff4fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
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

extern undefined DAT_00307974;
extern int FUN_00010184();

undefined4 * FUN_000ff4fc(undefined4 *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  *param_1 = (unsigned int)(&DAT_00307974);
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar1 = FUN_00010184(0x40);
  param_1[1] = uVar1;
  return param_1;
}
