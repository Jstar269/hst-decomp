/* HSTMATCH module=EBOOT.BIN start=0x00094fa4 end=0x00094fe0 symbol=FUN_00094fa4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_00307278;
extern undefined4 * FUN_00056b98();
extern void FUN_0009503c();

undefined4 * FUN_00094fa4(undefined4 *param_1)
{
  FUN_00056b98();
  *param_1 = (unsigned int)(&DAT_00307278);
  FUN_0009503c(param_1);
  return param_1;
}
