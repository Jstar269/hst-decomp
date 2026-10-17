/* HSTMATCH module=EBOOT.BIN start=0x002a49d8 end=0x002a4a20 symbol=FUN_002a49d8 lang=c99 */
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

extern undefined DAT_00309ee0;
extern undefined4 DAT_0034b350;
extern undefined4 * FUN_0001f06c();
extern void FUN_002a4f18();

undefined4 * FUN_002a49d8(undefined4 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309ee0);
  DAT_0034b350 = (unsigned int)(param_1);
  FUN_002a4f18(param_1,0);
  return param_1;
}
