/* HSTMATCH module=EBOOT.BIN start=0x000d83b8 end=0x000d8408 symbol=FUN_000d83b8 lang=c99 */
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

extern undefined DAT_003075e0;
extern void FUN_000007f4();
extern void FUN_000d8408();
extern void FUN_000d8460();

undefined4 * FUN_000d83b8(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003075e0);
  FUN_000007f4((int)(param_1 + 1),FUN_000d8460,FUN_000d8408,0xc,6);
  return param_1;
}
