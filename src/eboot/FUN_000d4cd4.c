/* HSTMATCH module=EBOOT.BIN start=0x000d4cd4 end=0x000d4d34 symbol=FUN_000d4cd4 lang=c99 */
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

extern undefined DAT_0030744c;
extern void FUN_000007f4();
extern undefined4 * FUN_0001f06c();
extern void FUN_000d4ddc();
extern void FUN_00056b98();
extern void FUN_00056cb0();

undefined4 * FUN_000d4cd4(undefined4 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_0030744c);
  FUN_000007f4(param_1 + 0x14,FUN_00056b98,FUN_00056cb0,0x1b0,4);
  *(undefined1 *)(param_1 + 0x1c4) = 0;
  FUN_000d4ddc(param_1);
  return param_1;
}
