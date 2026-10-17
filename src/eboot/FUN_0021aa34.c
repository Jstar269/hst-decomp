/* HSTMATCH module=EBOOT.BIN start=0x0021aa34 end=0x0021aa6c symbol=FUN_0021aa34 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern void FUN_0021aabc();
extern void FUN_0021abe0();

undefined4 * FUN_0021aa34(undefined4 *param_1)
{
  *param_1 = 0;
  FUN_0021aabc();
  FUN_0021abe0(param_1,0xb);
  return param_1;
}
