/* HSTMATCH module=EBOOT.BIN start=0x0010ee50 end=0x0010ef0c symbol=FUN_0010ee50 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined DAT_002d9210;
extern undefined DAT_00307a08;
extern undefined DAT_00307df4;
extern undefined4 DAT_00310fc4;
extern void FUN_00042e04();
extern void FUN_00042ecc();
extern undefined4 * FUN_00103d80();

undefined4 * FUN_0010ee50(undefined4 *param_1)
{
  FUN_00103d80(param_1,&DAT_002d9210);
  *param_1 = (int)(&DAT_00307a08);
  *param_1 = (int)(&DAT_00307df4);
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  *(undefined2 *)(param_1 + 0x36) = 0;
  param_1[0x37] = 0x3f800000;
  param_1[0x38] = 0x3f800000;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  *(undefined1 *)(param_1 + 0x3b) = 0;
  *(undefined2 *)((int)param_1 + 0xee) = 0;
  *(undefined2 *)(param_1 + 0x3c) = 0;
  *(undefined2 *)((int)param_1 + 0xf2) = 0xffe0;
  *(undefined2 *)(param_1 + 0x3d) = 0x10;
  param_1[0x3e] = 0;
  *(undefined2 *)(param_1 + 0x23f) = 0;
  param_1[0x240] = 0;
  param_1[0x241] = 0;
  *(undefined2 *)(param_1 + 0x242) = 0xffff;
  *(undefined1 *)((int)param_1 + 0x90a) = 1;
  FUN_00042e04(DAT_00310fc4);
  FUN_00042ecc(DAT_00310fc4);
  return param_1;
}
