/* HSTMATCH module=EBOOT.BIN start=0x0025b050 end=0x0025b090 symbol=FUN_0025b050 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
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

extern int * FUN_0025b090();
extern undefined4 FUN_0025b1c4();

undefined4 FUN_0025b050(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_0025b1c4(param_1);
  FUN_0025b090(param_1,param_3);
  return param_1;
}
