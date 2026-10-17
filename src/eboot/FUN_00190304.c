/* HSTMATCH module=EBOOT.BIN start=0x00190304 end=0x00190348 symbol=FUN_00190304 lang=c99 */
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

extern undefined DAT_00309194;
extern undefined4 * FUN_0001f06c();
extern void FUN_00198df0();
extern void FUN_00198eb4();

undefined4 * FUN_00190304(undefined4 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309194);
  FUN_00198df0(param_1 + 0xf);
  FUN_00198eb4(param_1);
  return param_1;
}
