/* HSTMATCH module=EBOOT.BIN start=0x0025ccb4 end=0x0025ccfc symbol=FUN_0025ccb4 lang=c99 */
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

extern undefined4 DAT_003415ac;
extern void FUN_00103628();
extern void FUN_00281090();

void FUN_0025ccb4(int param_1)
{
  *(undefined1 *)(param_1 + 0x54) = 0;
  *(undefined1 *)(param_1 + 0x55) = 0;
  FUN_00103628(param_1,1);
  FUN_00103628(DAT_003415ac,1);
  FUN_00281090(*(undefined4 *)(param_1 + 0x5c));
  return;
}
